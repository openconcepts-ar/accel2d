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


module accel_rectangle_fill32 (
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
        output wire   [27:0] mmap_m_cmd_addr,
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
    wire          flush;
    reg           cmd_valid = 1'd0;
    wire          cmd_ready;
    wire          cmd_last;
    wire          cmd_payload_we;
    wire   [27:0] cmd_payload_addr;
    reg           wdata_valid = 1'd0;
    wire          wdata_ready;
    wire  [127:0] wdata_payload_data;
    wire   [15:0] wdata_payload_we;
    wire          rdata_valid;
    wire          rdata_ready;
    wire  [127:0] rdata_payload_data;
    reg    [29:0] litedram_wb_adr = 30'd0;
    reg   [127:0] litedram_wb_dat_w = 128'd0;
    reg   [127:0] litedram_wb_dat_r = 128'd0;
    reg    [15:0] litedram_wb_sel = 16'd0;
    wire          litedram_wb_cyc;
    wire          litedram_wb_stb;
    reg           litedram_wb_ack = 1'd0;
    wire          litedram_wb_we;
    wire    [2:0] litedram_wb_cti;
    wire    [1:0] litedram_wb_bte;
    reg           litedram_wb_err = 1'd0;
    reg           aborted = 1'd0;
    reg           is_ongoing = 1'd0;
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
    reg     [1:0] accelgluesoc_litedramwishbone2native_state = 2'd0;
    reg     [1:0] accelgluesoc_litedramwishbone2native_next_state = 2'd0;
    reg           aborted_next_value = 1'd0;
    reg           aborted_next_value_ce = 1'd0;
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
    assign litedram_wb_cyc = extcore_dma_bus_cyc;
    assign litedram_wb_stb = extcore_dma_bus_stb;
    assign extcore_dma_bus_ack = litedram_wb_ack;
    assign litedram_wb_we = extcore_dma_bus_we;
    assign litedram_wb_cti = extcore_dma_bus_cti;
    assign litedram_wb_bte = extcore_dma_bus_bte;
    assign extcore_dma_bus_err = litedram_wb_err;
    always @(*) begin
        litedram_wb_adr <= 30'd0;
        litedram_wb_dat_w <= 128'd0;
        extcore_dma_bus_dat_r <= 32'd0;
        litedram_wb_sel <= 16'd0;
        case (extcore_dma_bus_adr[1:0])
            1'd0: begin
                litedram_wb_adr <= extcore_dma_bus_adr[29:2];
                litedram_wb_sel[3:0] <= extcore_dma_bus_sel;
                litedram_wb_dat_w[31:0] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= litedram_wb_dat_r[31:0];
            end
            1'd1: begin
                litedram_wb_adr <= extcore_dma_bus_adr[29:2];
                litedram_wb_sel[7:4] <= extcore_dma_bus_sel;
                litedram_wb_dat_w[63:32] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= litedram_wb_dat_r[63:32];
            end
            2'd2: begin
                litedram_wb_adr <= extcore_dma_bus_adr[29:2];
                litedram_wb_sel[11:8] <= extcore_dma_bus_sel;
                litedram_wb_dat_w[95:64] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= litedram_wb_dat_r[95:64];
            end
            2'd3: begin
                litedram_wb_adr <= extcore_dma_bus_adr[29:2];
                litedram_wb_sel[15:12] <= extcore_dma_bus_sel;
                litedram_wb_dat_w[127:96] <= extcore_dma_bus_dat_w;
                extcore_dma_bus_dat_r <= litedram_wb_dat_r[127:96];
            end
        endcase
    end
    assign cmd_payload_addr = (litedram_wb_adr - 1'd0);
    assign cmd_payload_we = litedram_wb_we;
    assign cmd_last = (~litedram_wb_we);
    assign flush = (~litedram_wb_cyc);
    always @(*) begin
        wdata_valid <= 1'd0;
        wdata_valid <= (litedram_wb_stb & litedram_wb_we);
        if (1'd1) begin
            if ((~is_ongoing)) begin
                wdata_valid <= 1'd0;
            end
        end
    end
    assign wdata_payload_data = litedram_wb_dat_w;
    assign wdata_payload_we = litedram_wb_sel;
    assign rdata_ready = 1'd1;
    always @(*) begin
        aborted_next_value <= 1'd0;
        is_ongoing <= 1'd0;
        aborted_next_value_ce <= 1'd0;
        litedram_wb_ack <= 1'd0;
        cmd_valid <= 1'd0;
        accelgluesoc_litedramwishbone2native_next_state <= 2'd0;
        litedram_wb_dat_r <= 128'd0;
        accelgluesoc_litedramwishbone2native_next_state <= accelgluesoc_litedramwishbone2native_state;
        case (accelgluesoc_litedramwishbone2native_state)
            1'd1: begin
                is_ongoing <= 1'd1;
                aborted_next_value <= ((~litedram_wb_cyc) | aborted);
                aborted_next_value_ce <= 1'd1;
                if ((wdata_valid & wdata_ready)) begin
                    litedram_wb_ack <= (litedram_wb_cyc & (~aborted));
                    accelgluesoc_litedramwishbone2native_next_state <= 1'd0;
                end
            end
            2'd2: begin
                aborted_next_value <= ((~litedram_wb_cyc) | aborted);
                aborted_next_value_ce <= 1'd1;
                if (rdata_valid) begin
                    litedram_wb_ack <= (litedram_wb_cyc & (~aborted));
                    litedram_wb_dat_r <= rdata_payload_data;
                    accelgluesoc_litedramwishbone2native_next_state <= 1'd0;
                end
            end
            default: begin
                cmd_valid <= (litedram_wb_cyc & litedram_wb_stb);
                if (((cmd_valid & cmd_ready) & litedram_wb_we)) begin
                    accelgluesoc_litedramwishbone2native_next_state <= 1'd1;
                end
                if (((cmd_valid & cmd_ready) & (~litedram_wb_we))) begin
                    accelgluesoc_litedramwishbone2native_next_state <= 2'd2;
                end
                aborted_next_value <= 1'd0;
                aborted_next_value_ce <= 1'd1;
            end
        endcase
    end
    always @(*) begin
        accelgluesoc_wishbone_dat_r <= 32'd0;
        accelgluesoc_adr <= 14'd0;
        accelgluesoc_wishbone2csr_next_state <= 1'd0;
        accelgluesoc_we <= 1'd0;
        accelgluesoc_dat_w <= 32'd0;
        accelgluesoc_wishbone_ack <= 1'd0;
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
        x00_we <= 1'd0;
        x00_re <= 1'd0;
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
        rgba0_re <= 1'd0;
        rgba0_we <= 1'd0;
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
        accelgluesoc_litedramwishbone2native_state <= accelgluesoc_litedramwishbone2native_next_state;
        if (aborted_next_value_ce) begin
            aborted <= aborted_next_value;
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
            aborted <= 1'd0;
            accelgluesoc_litedramwishbone2native_state <= 2'd0;
            accelgluesoc_wishbone2csr_state <= 1'd0;
        end
    end



    M_accel_rectangle_fill32 M_accel_rectangle_fill32(
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

