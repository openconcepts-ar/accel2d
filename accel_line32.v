/*
Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
SPDX-License-Identifier: AGPL-3.0-only

This program is free software: you can redistribute it and/or modify it under the terms of the
GNU Affero General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.
If not, see <https://www.gnu.org/licenses/>.

This file uses portions from LiteX and MiSoC projects under BSD 2-Clause license
Unless otherwise noted, LiteX is copyright (C) 2012-2022 Enjoy-Digital & LiteX developers.
Unless otherwise noted, MiSoC is copyright (C) 2012-2015 Enjoy-Digital.
Unless otherwise noted, MiSoC is copyright (C) 2007-2015 M-Labs Ltd.

See LITEX-CONTRIBUTORS file for additional authors that may have written code used in this file

*/

`timescale 1ns / 1ps


module accel_line32 (
        input  wire          clk,
        input  wire          rst,
        input  wire   [29:0] mmap_s_adr,
        input  wire   [31:0] mmap_s_dat_w,
        output wire   [31:0] mmap_s_dat_r,
        input  wire    [3:0] mmap_s_sel,
        input  wire          mmap_s_cyc,
        input  wire          mmap_s_stb,
        output wire          mmap_s_ack,
        input  wire          mmap_s_we,
        input  wire    [2:0] mmap_s_cti,
        input  wire    [1:0] mmap_s_bte,
        output wire          mmap_s_err,
        output wire          mmap_m_cmd_valid,
        input  wire          mmap_m_cmd_ready,
        output wire          mmap_m_cmd_we,
        output wire   [29:0] mmap_m_cmd_addr,
        output wire          mmap_m_wdata_valid,
        input  wire          mmap_m_wdata_ready,
        output wire   [15:0] mmap_m_wdata_we,
        output wire  [127:0] mmap_m_wdata_data,
        input  wire          mmap_m_rdata_valid,
        output wire          mmap_m_rdata_ready,
        input  wire  [127:0] mmap_m_rdata_data
    );



    wire          sys_clk;
    wire          sys_rst;
    wire          por_clk;
    reg           soc_int_rst = 1'd1;
    wire   [29:0] soc_adr;
    wire   [31:0] soc_dat_w;
    wire   [31:0] soc_dat_r;
    wire    [3:0] soc_sel;
    wire          soc_cyc;
    wire          soc_stb;
    wire          soc_ack;
    wire          soc_we;
    wire    [2:0] soc_cti;
    wire    [1:0] soc_bte;
    wire          soc_err;
    wire          extcore_args_valid;
    wire          extcore_args_ready;
    wire   [15:0] extcore_args_payload_x0;
    wire   [15:0] extcore_args_payload_y0;
    wire   [15:0] extcore_args_payload_x1;
    wire   [15:0] extcore_args_payload_y1;
    wire   [31:0] extcore_args_payload_rgba;
    wire   [31:0] extcore_args_payload_base;
    wire   [15:0] extcore_args_payload_xstride;
    wire   [15:0] extcore_args_payload_ystride;
    reg           extcore_run_storage = 1'd0;
    reg           extcore_run_re = 1'd0;
    wire          extcore_done_status;
    wire          extcore_done_we;
    reg           extcore_done_re = 1'd0;
    reg    [15:0] extcore_csrstorage0_storage = 16'd0;
    reg           extcore_csrstorage0_re = 1'd0;
    reg    [15:0] extcore_csrstorage1_storage = 16'd0;
    reg           extcore_csrstorage1_re = 1'd0;
    reg    [15:0] extcore_csrstorage2_storage = 16'd0;
    reg           extcore_csrstorage2_re = 1'd0;
    reg    [15:0] extcore_csrstorage3_storage = 16'd0;
    reg           extcore_csrstorage3_re = 1'd0;
    reg    [31:0] extcore_csrstorage4_storage = 32'd0;
    reg           extcore_csrstorage4_re = 1'd0;
    reg    [31:0] extcore_csrstorage5_storage = 32'd0;
    reg           extcore_csrstorage5_re = 1'd0;
    reg    [15:0] extcore_csrstorage6_storage = 16'd0;
    reg           extcore_csrstorage6_re = 1'd0;
    reg    [15:0] extcore_csrstorage7_storage = 16'd0;
    reg           extcore_csrstorage7_re = 1'd0;
    wire   [29:0] extcore_dma_bus_adr;
    wire   [31:0] extcore_dma_bus_dat_w;
    reg    [31:0] extcore_dma_bus_dat_r = 32'd0;
    wire    [3:0] extcore_dma_bus_sel;
    wire          extcore_dma_bus_cyc;
    wire          extcore_dma_bus_stb;
    wire          extcore_dma_bus_ack;
    wire          extcore_dma_bus_we;
    reg     [2:0] extcore_dma_bus_cti = 3'd0;
    reg     [1:0] extcore_dma_bus_bte = 2'd0;
    wire          extcore_dma_bus_err;
    wire   [31:0] extcore_adr;
    wire          cmd_valid;
    wire          cmd_ready;
    wire          cmd_payload_we;
    wire   [29:0] cmd_payload_addr;
    wire          wdata_valid;
    wire          wdata_ready;
    wire  [127:0] wdata_payload_data;
    wire   [15:0] wdata_payload_we;
    wire          rdata_valid;
    reg           rdata_ready = 1'd0;
    wire  [127:0] rdata_payload_data;
    wire   [29:0] bus_adr;
    wire  [127:0] bus_dat_w;
    wire  [127:0] bus_dat_r;
    wire   [15:0] bus_sel;
    wire          bus_cyc;
    wire          bus_stb;
    wire          bus_ack;
    wire          bus_we;
    wire    [2:0] bus_cti;
    wire    [1:0] bus_bte;
    reg           bus_err = 1'd0;
    reg    [29:0] busx_adr = 30'd0;
    reg   [127:0] busx_dat_w = 128'd0;
    wire  [127:0] busx_dat_r;
    reg    [15:0] busx_sel = 16'd0;
    wire          busx_cyc;
    wire          busx_stb;
    reg           busx_ack = 1'd0;
    wire          busx_we;
    wire    [2:0] busx_cti;
    wire    [1:0] busx_bte;
    reg           busx_err = 1'd0;
    wire   [29:0] slave_tmp_adr;
    wire  [127:0] slave_tmp_dat_w;
    wire  [127:0] slave_tmp_dat_r;
    wire   [15:0] slave_tmp_sel;
    reg           slave_tmp_cyc = 1'd0;
    reg           slave_tmp_stb = 1'd0;
    wire          slave_tmp_ack;
    reg           slave_tmp_we = 1'd0;
    reg     [2:0] slave_tmp_cti = 3'd0;
    reg     [1:0] slave_tmp_bte = 2'd0;
    wire          slave_tmp_err;
    reg     [2:0] data_port_adr = 3'd0;
    wire  [127:0] data_port_dat_r;
    reg    [15:0] data_port_we = 16'd0;
    reg   [127:0] data_port_dat_w = 128'd0;
    reg     [2:0] sel_port_adr = 3'd0;
    wire   [15:0] sel_port_dat_r;
    reg           sel_port_we = 1'd0;
    reg    [15:0] sel_port_dat_w = 16'd0;
    reg           write_from_slave = 1'd0;
    reg     [2:0] tag_port_adr = 3'd0;
    wire   [27:0] tag_port_dat_r;
    reg           tag_port_we = 1'd0;
    wire   [27:0] tag_port_dat_w;
    wire   [26:0] tag_do_tag;
    wire          tag_do_dirty;
    reg    [26:0] tag_di_tag = 27'd0;
    reg           tag_di_dirty = 1'd0;
    reg           word_clr = 1'd0;
    reg           word_inc = 1'd0;
    reg     [2:0] autoevict_counter = 3'd0;
    reg           auto_evict = 1'd0;
    wire          sink_sink_valid;
    wire          sink_sink_ready;
    wire   [29:0] sink_sink_payload_address;
    wire  [127:0] sink_sink_payload_data;
    wire   [15:0] sink_sink_payload_sel;
    wire          fifo_sink_valid;
    wire          fifo_sink_ready;
    reg           fifo_sink_first = 1'd0;
    reg           fifo_sink_last = 1'd0;
    wire  [127:0] fifo_sink_payload_data;
    wire   [15:0] fifo_sink_payload_sel;
    wire          fifo_source_valid;
    wire          fifo_source_ready;
    wire          fifo_source_first;
    wire          fifo_source_last;
    wire  [127:0] fifo_source_payload_data;
    wire   [15:0] fifo_source_payload_sel;
    wire          fifo_re;
    reg           fifo_readable = 1'd0;
    wire          fifo_syncfifo_we;
    wire          fifo_syncfifo_writable;
    wire          fifo_syncfifo_re;
    wire          fifo_syncfifo_readable;
    wire  [145:0] fifo_syncfifo_din;
    wire  [145:0] fifo_syncfifo_dout;
    reg     [4:0] fifo_level0 = 5'd0;
    reg           fifo_replace = 1'd0;
    reg     [3:0] fifo_produce = 4'd0;
    reg     [3:0] fifo_consume = 4'd0;
    reg     [3:0] fifo_wrport_adr = 4'd0;
    wire  [145:0] fifo_wrport_dat_r;
    wire          fifo_wrport_we;
    wire  [145:0] fifo_wrport_dat_w;
    wire          fifo_do_read;
    wire    [3:0] fifo_rdport_adr;
    wire  [145:0] fifo_rdport_dat_r;
    wire          fifo_rdport_re;
    wire    [4:0] fifo_level1;
    wire  [127:0] fifo_fifo_in_payload_data;
    wire   [15:0] fifo_fifo_in_payload_sel;
    wire          fifo_fifo_in_first;
    wire          fifo_fifo_in_last;
    wire  [127:0] fifo_fifo_out_payload_data;
    wire   [15:0] fifo_fifo_out_payload_sel;
    wire          fifo_fifo_out_first;
    wire          fifo_fifo_out_last;
    reg    [13:0] accelgluesoc_adr = 14'd0;
    reg           accelgluesoc_we = 1'd0;
    reg    [31:0] accelgluesoc_dat_w = 32'd0;
    wire   [31:0] accelgluesoc_dat_r;
    wire   [29:0] accelgluesoc_wishbone_adr;
    wire   [31:0] accelgluesoc_wishbone_dat_w;
    reg    [31:0] accelgluesoc_wishbone_dat_r = 32'd0;
    wire    [3:0] accelgluesoc_wishbone_sel;
    wire          accelgluesoc_wishbone_cyc;
    wire          accelgluesoc_wishbone_stb;
    reg           accelgluesoc_wishbone_ack = 1'd0;
    wire          accelgluesoc_wishbone_we;
    wire    [2:0] accelgluesoc_wishbone_cti;
    wire    [1:0] accelgluesoc_wishbone_bte;
    reg           accelgluesoc_wishbone_err = 1'd0;
    wire   [13:0] bank_bus_adr;
    wire          bank_bus_we;
    wire   [31:0] bank_bus_dat_w;
    reg    [31:0] bank_bus_dat_r = 32'd0;
    reg           run0_re = 1'd0;
    wire          run0_r;
    reg           run0_we = 1'd0;
    wire          run0_w;
    reg           done_re = 1'd0;
    wire          done_r;
    reg           done_we = 1'd0;
    wire          done_w;
    reg           x00_re = 1'd0;
    wire   [15:0] x00_r;
    reg           x00_we = 1'd0;
    wire   [15:0] x00_w;
    reg           y00_re = 1'd0;
    wire   [15:0] y00_r;
    reg           y00_we = 1'd0;
    wire   [15:0] y00_w;
    reg           x10_re = 1'd0;
    wire   [15:0] x10_r;
    reg           x10_we = 1'd0;
    wire   [15:0] x10_w;
    reg           y10_re = 1'd0;
    wire   [15:0] y10_r;
    reg           y10_we = 1'd0;
    wire   [15:0] y10_w;
    reg           rgba0_re = 1'd0;
    wire   [31:0] rgba0_r;
    reg           rgba0_we = 1'd0;
    wire   [31:0] rgba0_w;
    reg           base0_re = 1'd0;
    wire   [31:0] base0_r;
    reg           base0_we = 1'd0;
    wire   [31:0] base0_w;
    reg           xstride0_re = 1'd0;
    wire   [15:0] xstride0_r;
    reg           xstride0_we = 1'd0;
    wire   [15:0] xstride0_w;
    reg           ystride0_re = 1'd0;
    wire   [15:0] ystride0_r;
    reg           ystride0_we = 1'd0;
    wire   [15:0] ystride0_w;
    wire          sel;
    wire   [13:0] csr_interconnect_adr;
    wire          csr_interconnect_we;
    wire   [31:0] csr_interconnect_dat_w;
    wire   [31:0] csr_interconnect_dat_r;
    reg     [2:0] accelgluesoc_wpubase_state = 3'd1;
    reg     [2:0] accelgluesoc_wpubase_next_state = 3'd0;
    reg     [2:0] autoevict_counter_next_value = 3'd0;
    reg           autoevict_counter_next_value_ce = 1'd0;
    reg           accelgluesoc_wishbone2csr_state = 1'd0;
    reg           accelgluesoc_wishbone2csr_next_state = 1'd0;


    assign soc_adr = mmap_s_adr;
    assign soc_dat_w = mmap_s_dat_w;
    assign mmap_s_dat_r = soc_dat_r;
    assign soc_sel = mmap_s_sel;
    assign soc_cyc = mmap_s_cyc;
    assign soc_stb = mmap_s_stb;
    assign mmap_s_ack = soc_ack;
    assign soc_we = mmap_s_we;
    assign soc_cti = mmap_s_cti;
    assign soc_bte = mmap_s_bte;
    assign mmap_s_err = soc_err;
    assign mmap_m_cmd_valid = cmd_valid;
    assign cmd_ready = mmap_m_cmd_ready;
    assign mmap_m_cmd_we = cmd_payload_we;
    assign mmap_m_cmd_addr = cmd_payload_addr;
    assign mmap_m_wdata_valid = wdata_valid;
    assign wdata_ready = mmap_m_wdata_ready;
    assign mmap_m_wdata_we = wdata_payload_we;
    assign mmap_m_wdata_data = wdata_payload_data;
    assign rdata_valid = mmap_m_rdata_valid;
    assign mmap_m_rdata_ready = rdata_ready;
    assign rdata_payload_data = mmap_m_rdata_data;
    assign sys_clk = clk;
    assign por_clk = clk;
    assign sys_rst = soc_int_rst;
    assign accelgluesoc_wishbone_adr = soc_adr;
    assign accelgluesoc_wishbone_dat_w = soc_dat_w;
    assign soc_dat_r = accelgluesoc_wishbone_dat_r;
    assign accelgluesoc_wishbone_sel = soc_sel;
    assign accelgluesoc_wishbone_cyc = soc_cyc;
    assign accelgluesoc_wishbone_stb = soc_stb;
    assign soc_ack = accelgluesoc_wishbone_ack;
    assign accelgluesoc_wishbone_we = soc_we;
    assign accelgluesoc_wishbone_cti = soc_cti;
    assign accelgluesoc_wishbone_bte = soc_bte;
    assign soc_err = accelgluesoc_wishbone_err;
    assign extcore_args_valid = extcore_run_storage;
    assign extcore_done_status = extcore_args_ready;
    assign extcore_args_payload_x0 = extcore_csrstorage0_storage;
    assign extcore_args_payload_y0 = extcore_csrstorage1_storage;
    assign extcore_args_payload_x1 = extcore_csrstorage2_storage;
    assign extcore_args_payload_y1 = extcore_csrstorage3_storage;
    assign extcore_args_payload_rgba = extcore_csrstorage4_storage;
    assign extcore_args_payload_base = extcore_csrstorage5_storage;
    assign extcore_args_payload_xstride = extcore_csrstorage6_storage;
    assign extcore_args_payload_ystride = extcore_csrstorage7_storage;
    assign extcore_dma_bus_adr = extcore_adr[31:2];
    assign sink_sink_payload_data = bus_dat_w;
    assign sink_sink_payload_sel = bus_sel;
    assign sink_sink_valid = ((bus_cyc & bus_stb) & bus_we);
    assign sink_sink_payload_address = bus_adr;
    assign bus_ack = (sink_sink_ready & sink_sink_valid);
    assign bus_dat_r = bus_dat_w;
    assign busx_cyc = extcore_dma_bus_cyc;
    assign busx_stb = extcore_dma_bus_stb;
    assign extcore_dma_bus_ack = busx_ack;
    assign busx_we = extcore_dma_bus_we;
    assign busx_cti = extcore_dma_bus_cti;
    assign busx_bte = extcore_dma_bus_bte;
    assign extcore_dma_bus_err = busx_err;
    assign bus_adr = slave_tmp_adr;
    assign bus_dat_w = slave_tmp_dat_w;
    assign slave_tmp_dat_r = bus_dat_r;
    assign bus_sel = slave_tmp_sel;
    assign bus_cyc = slave_tmp_cyc;
    assign bus_stb = slave_tmp_stb;
    assign slave_tmp_ack = bus_ack;
    assign bus_we = slave_tmp_we;
    assign bus_cti = slave_tmp_cti;
    assign bus_bte = slave_tmp_bte;
    assign slave_tmp_err = bus_err;
    assign {tag_do_dirty, tag_do_tag} = tag_port_dat_r;
    assign tag_port_dat_w = {tag_di_dirty, tag_di_tag};
    always @(*) begin
        data_port_dat_w <= 128'd0;
        data_port_we <= 16'd0;
        if (write_from_slave) begin
            data_port_dat_w <= slave_tmp_dat_r;
            data_port_we <= {16{1'd1}};
        end else begin
            data_port_dat_w <= {1{busx_dat_w}};
            if ((((busx_cyc & busx_stb) & busx_we) & busx_ack)) begin
                data_port_we <= busx_sel;
            end
        end
    end
    assign slave_tmp_dat_w = data_port_dat_r;
    assign busx_dat_r = data_port_dat_r;
    assign slave_tmp_adr = {tag_do_tag, busx_adr[2:0]};
    assign slave_tmp_sel = sel_port_dat_r;
    always @(*) begin
        tag_di_tag <= 27'd0;
        tag_di_dirty <= 1'd0;
        extcore_dma_bus_dat_r <= 32'd0;
        word_clr <= 1'd0;
        word_inc <= 1'd0;
        slave_tmp_cyc <= 1'd0;
        slave_tmp_stb <= 1'd0;
        slave_tmp_we <= 1'd0;
        busx_adr <= 30'd0;
        accelgluesoc_wpubase_next_state <= 3'd0;
        busx_dat_w <= 128'd0;
        data_port_adr <= 3'd0;
        busx_sel <= 16'd0;
        autoevict_counter_next_value <= 3'd0;
        autoevict_counter_next_value_ce <= 1'd0;
        busx_ack <= 1'd0;
        sel_port_adr <= 3'd0;
        sel_port_we <= 1'd0;
        auto_evict <= 1'd0;
        sel_port_dat_w <= 16'd0;
        write_from_slave <= 1'd0;
        tag_port_adr <= 3'd0;
        tag_port_we <= 1'd0;
        case (extcore_dma_bus_adr[1:0])
            1'd0: begin
                busx_adr <= extcore_dma_bus_adr[29:2];
                busx_sel[3:0] <= extcore_dma_bus_sel;
                busx_dat_w[31:0] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= busx_dat_r[31:0];
            end
            1'd1: begin
                busx_adr <= extcore_dma_bus_adr[29:2];
                busx_sel[7:4] <= extcore_dma_bus_sel;
                busx_dat_w[63:32] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= busx_dat_r[63:32];
            end
            2'd2: begin
                busx_adr <= extcore_dma_bus_adr[29:2];
                busx_sel[11:8] <= extcore_dma_bus_sel;
                busx_dat_w[95:64] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= busx_dat_r[95:64];
            end
            2'd3: begin
                busx_adr <= extcore_dma_bus_adr[29:2];
                busx_sel[15:12] <= extcore_dma_bus_sel;
                busx_dat_w[127:96] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= busx_dat_r[127:96];
            end
        endcase
        tag_port_adr <= busx_adr[2:0];
        tag_di_tag <= busx_adr[29:3];
        data_port_adr <= busx_adr[2:0];
        sel_port_adr <= busx_adr[2:0];
        sel_port_we <= 1'd0;
        accelgluesoc_wpubase_next_state <= accelgluesoc_wpubase_state;
        case (accelgluesoc_wpubase_state)
            1'd0: begin
                if (busx_cyc) begin
                    accelgluesoc_wpubase_next_state <= 1'd1;
                end else begin
                    busx_adr[2:0] <= autoevict_counter;
                    tag_port_adr <= busx_adr[2:0];
                    data_port_adr <= busx_adr[2:0];
                    sel_port_adr <= busx_adr[2:0];
                    accelgluesoc_wpubase_next_state <= 2'd3;
                end
            end
            2'd2: begin
                slave_tmp_stb <= 1'd1;
                slave_tmp_cyc <= 1'd1;
                slave_tmp_we <= 1'd1;
                if (slave_tmp_ack) begin
                    word_inc <= 1'd1;
                    if (1'd1) begin
                        tag_port_we <= 1'd1;
                        sel_port_we <= 1'd1;
                        sel_port_dat_w <= 1'd0;
                        word_clr <= 1'd1;
                        accelgluesoc_wpubase_next_state <= 1'd1;
                    end
                end
            end
            2'd3: begin
                busx_adr[2:0] <= autoevict_counter;
                tag_port_adr <= busx_adr[2:0];
                data_port_adr <= busx_adr[2:0];
                sel_port_adr <= busx_adr[2:0];
                auto_evict <= tag_do_dirty;
                if (auto_evict) begin
                    slave_tmp_cyc <= 1'd1;
                    slave_tmp_stb <= 1'd1;
                    slave_tmp_we <= 1'd1;
                    if (slave_tmp_ack) begin
                        tag_di_tag <= tag_do_tag;
                        tag_di_dirty <= 1'd0;
                        tag_port_we <= 1'd1;
                        sel_port_we <= 1'd1;
                        sel_port_dat_w <= 1'd0;
                        autoevict_counter_next_value <= (autoevict_counter + 1'd1);
                        autoevict_counter_next_value_ce <= 1'd1;
                        accelgluesoc_wpubase_next_state <= 1'd0;
                    end
                end else begin
                    accelgluesoc_wpubase_next_state <= 1'd0;
                end
            end
            3'd4: begin
                slave_tmp_stb <= 1'd1;
                slave_tmp_cyc <= 1'd1;
                slave_tmp_we <= 1'd0;
                if (slave_tmp_ack) begin
                    write_from_slave <= 1'd1;
                    word_inc <= 1'd1;
                    if (1'd1) begin
                        accelgluesoc_wpubase_next_state <= 1'd1;
                    end else begin
                        accelgluesoc_wpubase_next_state <= 1'd1;
                    end
                end
            end
            default: begin
                if ((busx_cyc & busx_stb)) begin
                    word_clr <= 1'd1;
                    autoevict_counter_next_value <= (busx_adr[29:3] ^ 3'd4);
                    autoevict_counter_next_value_ce <= 1'd1;
                    if ((tag_do_tag == busx_adr[29:3])) begin
                        busx_ack <= 1'd1;
                        if (busx_we) begin
                            tag_di_dirty <= 1'd1;
                            tag_port_we <= 1'd1;
                            sel_port_we <= 1'd1;
                            sel_port_dat_w <= (busx_sel | sel_port_dat_r);
                        end
                    end else begin
                        if (tag_do_dirty) begin
                            accelgluesoc_wpubase_next_state <= 2'd2;
                        end else begin
                            tag_port_we <= 1'd1;
                            sel_port_we <= 1'd1;
                            if (busx_we) begin
                                sel_port_dat_w <= busx_sel;
                            end else begin
                                sel_port_dat_w <= 1'd0;
                            end
                            word_clr <= 1'd1;
                            accelgluesoc_wpubase_next_state <= 1'd1;
                        end
                    end
                end else begin
                    if ((~busx_cyc)) begin
                        accelgluesoc_wpubase_next_state <= 1'd0;
                    end
                end
            end
        endcase
    end
    assign cmd_payload_we = 1'd1;
    assign cmd_payload_addr = sink_sink_payload_address;
    assign cmd_valid = (fifo_sink_ready & sink_sink_valid);
    assign sink_sink_ready = (fifo_sink_ready & cmd_ready);
    assign fifo_sink_valid = (sink_sink_valid & cmd_ready);
    assign fifo_sink_payload_data = sink_sink_payload_data;
    assign fifo_sink_payload_sel = sink_sink_payload_sel;
    assign wdata_payload_we = fifo_source_payload_sel;
    assign wdata_valid = fifo_source_valid;
    assign fifo_source_ready = wdata_ready;
    assign wdata_payload_data = fifo_source_payload_data;
    assign fifo_syncfifo_din = {fifo_fifo_in_last, fifo_fifo_in_first, fifo_fifo_in_payload_sel, fifo_fifo_in_payload_data};
    assign {fifo_fifo_out_last, fifo_fifo_out_first, fifo_fifo_out_payload_sel, fifo_fifo_out_payload_data} = fifo_syncfifo_dout;
    assign fifo_sink_ready = fifo_syncfifo_writable;
    assign fifo_syncfifo_we = fifo_sink_valid;
    assign fifo_fifo_in_first = fifo_sink_first;
    assign fifo_fifo_in_last = fifo_sink_last;
    assign fifo_fifo_in_payload_data = fifo_sink_payload_data;
    assign fifo_fifo_in_payload_sel = fifo_sink_payload_sel;
    assign fifo_source_valid = fifo_readable;
    assign fifo_source_first = fifo_fifo_out_first;
    assign fifo_source_last = fifo_fifo_out_last;
    assign fifo_source_payload_data = fifo_fifo_out_payload_data;
    assign fifo_source_payload_sel = fifo_fifo_out_payload_sel;
    assign fifo_re = fifo_source_ready;
    assign fifo_syncfifo_re = (fifo_syncfifo_readable & ((~fifo_readable) | fifo_re));
    assign fifo_level1 = (fifo_level0 + fifo_readable);
    always @(*) begin
        fifo_wrport_adr <= 4'd0;
        if (fifo_replace) begin
            fifo_wrport_adr <= (fifo_produce - 1'd1);
        end else begin
            fifo_wrport_adr <= fifo_produce;
        end
    end
    assign fifo_wrport_dat_w = fifo_syncfifo_din;
    assign fifo_wrport_we = (fifo_syncfifo_we & (fifo_syncfifo_writable | fifo_replace));
    assign fifo_do_read = (fifo_syncfifo_readable & fifo_syncfifo_re);
    assign fifo_rdport_adr = fifo_consume;
    assign fifo_syncfifo_dout = fifo_rdport_dat_r;
    assign fifo_rdport_re = fifo_do_read;
    assign fifo_syncfifo_writable = (fifo_level0 != 5'd16);
    assign fifo_syncfifo_readable = (fifo_level0 != 1'd0);
    always @(*) begin
        accelgluesoc_we <= 1'd0;
        accelgluesoc_wishbone_ack <= 1'd0;
        accelgluesoc_dat_w <= 32'd0;
        accelgluesoc_wishbone2csr_next_state <= 1'd0;
        accelgluesoc_wishbone_dat_r <= 32'd0;
        accelgluesoc_adr <= 14'd0;
        accelgluesoc_wishbone2csr_next_state <= accelgluesoc_wishbone2csr_state;
        case (accelgluesoc_wishbone2csr_state)
            1'd1: begin
                accelgluesoc_wishbone_ack <= 1'd1;
                accelgluesoc_wishbone_dat_r <= accelgluesoc_dat_r;
                accelgluesoc_wishbone2csr_next_state <= 1'd0;
            end
            default: begin
                accelgluesoc_dat_w <= accelgluesoc_wishbone_dat_w;
                if ((accelgluesoc_wishbone_cyc & accelgluesoc_wishbone_stb)) begin
                    accelgluesoc_adr <= accelgluesoc_wishbone_adr;
                    accelgluesoc_we <= (accelgluesoc_wishbone_we & (accelgluesoc_wishbone_sel != 1'd0));
                    accelgluesoc_wishbone2csr_next_state <= 1'd1;
                end
            end
        endcase
    end
    assign sel = (bank_bus_adr[13:9] == 1'd0);
    assign run0_r = bank_bus_dat_w[0];
    always @(*) begin
        run0_re <= 1'd0;
        run0_we <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 1'd0))) begin
            run0_re <= bank_bus_we;
            run0_we <= (~bank_bus_we);
        end
    end
    assign done_r = bank_bus_dat_w[0];
    always @(*) begin
        done_we <= 1'd0;
        done_re <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 1'd1))) begin
            done_re <= bank_bus_we;
            done_we <= (~bank_bus_we);
        end
    end
    assign x00_r = bank_bus_dat_w[15:0];
    always @(*) begin
        x00_re <= 1'd0;
        x00_we <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 2'd2))) begin
            x00_re <= bank_bus_we;
            x00_we <= (~bank_bus_we);
        end
    end
    assign y00_r = bank_bus_dat_w[15:0];
    always @(*) begin
        y00_re <= 1'd0;
        y00_we <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 2'd3))) begin
            y00_re <= bank_bus_we;
            y00_we <= (~bank_bus_we);
        end
    end
    assign x10_r = bank_bus_dat_w[15:0];
    always @(*) begin
        x10_we <= 1'd0;
        x10_re <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 3'd4))) begin
            x10_re <= bank_bus_we;
            x10_we <= (~bank_bus_we);
        end
    end
    assign y10_r = bank_bus_dat_w[15:0];
    always @(*) begin
        y10_re <= 1'd0;
        y10_we <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 3'd5))) begin
            y10_re <= bank_bus_we;
            y10_we <= (~bank_bus_we);
        end
    end
    assign rgba0_r = bank_bus_dat_w[31:0];
    always @(*) begin
        rgba0_we <= 1'd0;
        rgba0_re <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 3'd6))) begin
            rgba0_re <= bank_bus_we;
            rgba0_we <= (~bank_bus_we);
        end
    end
    assign base0_r = bank_bus_dat_w[31:0];
    always @(*) begin
        base0_we <= 1'd0;
        base0_re <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 3'd7))) begin
            base0_re <= bank_bus_we;
            base0_we <= (~bank_bus_we);
        end
    end
    assign xstride0_r = bank_bus_dat_w[15:0];
    always @(*) begin
        xstride0_re <= 1'd0;
        xstride0_we <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 4'd8))) begin
            xstride0_re <= bank_bus_we;
            xstride0_we <= (~bank_bus_we);
        end
    end
    assign ystride0_r = bank_bus_dat_w[15:0];
    always @(*) begin
        ystride0_we <= 1'd0;
        ystride0_re <= 1'd0;
        if ((sel & (bank_bus_adr[8:0] == 4'd9))) begin
            ystride0_re <= bank_bus_we;
            ystride0_we <= (~bank_bus_we);
        end
    end
    assign run0_w = extcore_run_storage;
    assign done_w = extcore_done_status;
    assign extcore_done_we = done_we;
    assign x00_w = extcore_csrstorage0_storage[15:0];
    assign y00_w = extcore_csrstorage1_storage[15:0];
    assign x10_w = extcore_csrstorage2_storage[15:0];
    assign y10_w = extcore_csrstorage3_storage[15:0];
    assign rgba0_w = extcore_csrstorage4_storage[31:0];
    assign base0_w = extcore_csrstorage5_storage[31:0];
    assign xstride0_w = extcore_csrstorage6_storage[15:0];
    assign ystride0_w = extcore_csrstorage7_storage[15:0];
    assign csr_interconnect_adr = accelgluesoc_adr;
    assign csr_interconnect_we = accelgluesoc_we;
    assign csr_interconnect_dat_w = accelgluesoc_dat_w;
    assign accelgluesoc_dat_r = csr_interconnect_dat_r;
    assign bank_bus_adr = csr_interconnect_adr;
    assign bank_bus_we = csr_interconnect_we;
    assign bank_bus_dat_w = csr_interconnect_dat_w;
    assign csr_interconnect_dat_r = bank_bus_dat_r;



    always @(posedge por_clk) begin
        soc_int_rst <= rst;
    end

    always @(posedge sys_clk) begin
        accelgluesoc_wpubase_state <= accelgluesoc_wpubase_next_state;
        if (autoevict_counter_next_value_ce) begin
            autoevict_counter <= autoevict_counter_next_value;
        end
        if (fifo_syncfifo_re) begin
            fifo_readable <= 1'd1;
        end else begin
            if (fifo_re) begin
                fifo_readable <= 1'd0;
            end
        end
        if (((fifo_syncfifo_we & fifo_syncfifo_writable) & (~fifo_replace))) begin
            fifo_produce <= (fifo_produce + 1'd1);
        end
        if (fifo_do_read) begin
            fifo_consume <= (fifo_consume + 1'd1);
        end
        if (((fifo_syncfifo_we & fifo_syncfifo_writable) & (~fifo_replace))) begin
            if ((~fifo_do_read)) begin
                fifo_level0 <= (fifo_level0 + 1'd1);
            end
        end else begin
            if (fifo_do_read) begin
                fifo_level0 <= (fifo_level0 - 1'd1);
            end
        end
        accelgluesoc_wishbone2csr_state <= accelgluesoc_wishbone2csr_next_state;
        bank_bus_dat_r <= 1'd0;
        if (sel) begin
            case (bank_bus_adr[8:0])
                1'd0: begin
                    bank_bus_dat_r <= run0_w;
                end
                1'd1: begin
                    bank_bus_dat_r <= done_w;
                end
                2'd2: begin
                    bank_bus_dat_r <= x00_w;
                end
                2'd3: begin
                    bank_bus_dat_r <= y00_w;
                end
                3'd4: begin
                    bank_bus_dat_r <= x10_w;
                end
                3'd5: begin
                    bank_bus_dat_r <= y10_w;
                end
                3'd6: begin
                    bank_bus_dat_r <= rgba0_w;
                end
                3'd7: begin
                    bank_bus_dat_r <= base0_w;
                end
                4'd8: begin
                    bank_bus_dat_r <= xstride0_w;
                end
                4'd9: begin
                    bank_bus_dat_r <= ystride0_w;
                end
            endcase
        end
        if (run0_re) begin
            extcore_run_storage <= run0_r;
        end
        extcore_run_re <= run0_re;
        extcore_done_re <= done_re;
        if (x00_re) begin
            extcore_csrstorage0_storage[15:0] <= x00_r;
        end
        extcore_csrstorage0_re <= x00_re;
        if (y00_re) begin
            extcore_csrstorage1_storage[15:0] <= y00_r;
        end
        extcore_csrstorage1_re <= y00_re;
        if (x10_re) begin
            extcore_csrstorage2_storage[15:0] <= x10_r;
        end
        extcore_csrstorage2_re <= x10_re;
        if (y10_re) begin
            extcore_csrstorage3_storage[15:0] <= y10_r;
        end
        extcore_csrstorage3_re <= y10_re;
        if (rgba0_re) begin
            extcore_csrstorage4_storage[31:0] <= rgba0_r;
        end
        extcore_csrstorage4_re <= rgba0_re;
        if (base0_re) begin
            extcore_csrstorage5_storage[31:0] <= base0_r;
        end
        extcore_csrstorage5_re <= base0_re;
        if (xstride0_re) begin
            extcore_csrstorage6_storage[15:0] <= xstride0_r;
        end
        extcore_csrstorage6_re <= xstride0_re;
        if (ystride0_re) begin
            extcore_csrstorage7_storage[15:0] <= ystride0_r;
        end
        extcore_csrstorage7_re <= ystride0_re;
        if (sys_rst) begin
            extcore_run_storage <= 1'd0;
            extcore_run_re <= 1'd0;
            extcore_done_re <= 1'd0;
            extcore_csrstorage0_storage <= 16'd0;
            extcore_csrstorage0_re <= 1'd0;
            extcore_csrstorage1_storage <= 16'd0;
            extcore_csrstorage1_re <= 1'd0;
            extcore_csrstorage2_storage <= 16'd0;
            extcore_csrstorage2_re <= 1'd0;
            extcore_csrstorage3_storage <= 16'd0;
            extcore_csrstorage3_re <= 1'd0;
            extcore_csrstorage4_storage <= 32'd0;
            extcore_csrstorage4_re <= 1'd0;
            extcore_csrstorage5_storage <= 32'd0;
            extcore_csrstorage5_re <= 1'd0;
            extcore_csrstorage6_storage <= 16'd0;
            extcore_csrstorage6_re <= 1'd0;
            extcore_csrstorage7_storage <= 16'd0;
            extcore_csrstorage7_re <= 1'd0;
            autoevict_counter <= 3'd0;
            fifo_readable <= 1'd0;
            fifo_level0 <= 5'd0;
            fifo_produce <= 4'd0;
            fifo_consume <= 4'd0;
            accelgluesoc_wpubase_state <= 3'd1;
            accelgluesoc_wishbone2csr_state <= 1'd0;
        end
    end



    reg [127:0] data_mem[0:7];
    reg [2:0] data_mem_adr0;
    always @(posedge sys_clk) begin
        if (data_port_we[0])
            data_mem[data_port_adr][7:0] <= data_port_dat_w[7:0];
        if (data_port_we[1])
            data_mem[data_port_adr][15:8] <= data_port_dat_w[15:8];
        if (data_port_we[2])
            data_mem[data_port_adr][23:16] <= data_port_dat_w[23:16];
        if (data_port_we[3])
            data_mem[data_port_adr][31:24] <= data_port_dat_w[31:24];
        if (data_port_we[4])
            data_mem[data_port_adr][39:32] <= data_port_dat_w[39:32];
        if (data_port_we[5])
            data_mem[data_port_adr][47:40] <= data_port_dat_w[47:40];
        if (data_port_we[6])
            data_mem[data_port_adr][55:48] <= data_port_dat_w[55:48];
        if (data_port_we[7])
            data_mem[data_port_adr][63:56] <= data_port_dat_w[63:56];
        if (data_port_we[8])
            data_mem[data_port_adr][71:64] <= data_port_dat_w[71:64];
        if (data_port_we[9])
            data_mem[data_port_adr][79:72] <= data_port_dat_w[79:72];
        if (data_port_we[10])
            data_mem[data_port_adr][87:80] <= data_port_dat_w[87:80];
        if (data_port_we[11])
            data_mem[data_port_adr][95:88] <= data_port_dat_w[95:88];
        if (data_port_we[12])
            data_mem[data_port_adr][103:96] <= data_port_dat_w[103:96];
        if (data_port_we[13])
            data_mem[data_port_adr][111:104] <= data_port_dat_w[111:104];
        if (data_port_we[14])
            data_mem[data_port_adr][119:112] <= data_port_dat_w[119:112];
        if (data_port_we[15])
            data_mem[data_port_adr][127:120] <= data_port_dat_w[127:120];
        data_mem_adr0 <= data_port_adr;
    end
    assign data_port_dat_r = data_mem[data_mem_adr0];


    reg [15:0] sel_mem[0:7];
    reg [2:0] sel_mem_adr0;
    always @(posedge sys_clk) begin
        if (sel_port_we)
            sel_mem[sel_port_adr] <= sel_port_dat_w;
        sel_mem_adr0 <= sel_port_adr;
    end
    assign sel_port_dat_r = sel_mem[sel_mem_adr0];


    reg [27:0] tag_mem[0:7];
    reg [2:0] tag_mem_adr0;
    always @(posedge sys_clk) begin
        if (tag_port_we)
            tag_mem[tag_port_adr] <= tag_port_dat_w;
        tag_mem_adr0 <= tag_port_adr;
    end
    assign tag_port_dat_r = tag_mem[tag_mem_adr0];


    reg [145:0] storage[0:15];
    reg [145:0] storage_dat0;
    reg [145:0] storage_dat1;
    always @(posedge sys_clk) begin
        if (fifo_wrport_we)
            storage[fifo_wrport_adr] <= fifo_wrport_dat_w;
        storage_dat0 <= storage[fifo_wrport_adr];
    end
    always @(posedge sys_clk) begin
        if (fifo_rdport_re)
            storage_dat1 <= storage[fifo_rdport_adr];
    end
    assign fifo_wrport_dat_r = storage_dat0;
    assign fifo_rdport_dat_r = storage_dat1;


    M_accel_line32 M_accel_line32(
                       .clock(sys_clk),
                       .in_base(extcore_args_payload_base),
                       .in_bus_ack(extcore_dma_bus_ack),
                       .in_bus_dat_r(extcore_dma_bus_dat_r),
                       .in_rgba(extcore_args_payload_rgba),
                       .in_run(extcore_args_valid),
                       .in_x0(extcore_args_payload_x0),
                       .in_x1(extcore_args_payload_x1),
                       .in_xstride(extcore_args_payload_xstride),
                       .in_y0(extcore_args_payload_y0),
                       .in_y1(extcore_args_payload_y1),
                       .in_ystride(extcore_args_payload_ystride),
                       .reset(sys_rst),
                       .out_bus_adr(extcore_adr),
                       .out_bus_cyc(extcore_dma_bus_cyc),
                       .out_bus_dat_w(extcore_dma_bus_dat_w),
                       .out_bus_sel(extcore_dma_bus_sel),
                       .out_bus_stb(extcore_dma_bus_stb),
                       .out_bus_we(extcore_dma_bus_we),
                       .out_done(extcore_args_ready)
                   );

endmodule

