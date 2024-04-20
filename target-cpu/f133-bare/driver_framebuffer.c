// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>

#include "ioregs.h"
#include "sys.h"

void dump_reg(uintptr_t addr)
{
	//printf("REGISTER at 0x%x: 0x%x\r\n", addr, io_read32(addr));
}

void fb_probe(void)
{
/*
#define CCU_pll_video0_ctrl (CCU + 0x40) // PLL_VIDEO0 Control Register ()
#define CCU_pll_video0_ctrl_OFFSET 0x40
#define CCU_pll_video0_ctrl_pll_en (0x1 << 31)
#define CCU_pll_video0_ctrl_pll_en_SHIFT 31
#define CCU_pll_video0_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_video0_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_video0_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_video0_ctrl_lock_enable_SHIFT 29
#define CCU_pll_video0_ctrl_lock (0x1 << 28)
#define CCU_pll_video0_ctrl_lock_SHIFT 28
#define CCU_pll_video0_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_video0_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_video0_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_video0_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_video0_ctrl_pll_n (0xff << 8)
#define CCU_pll_video0_ctrl_pll_n_SHIFT 8
#define CCU_pll_video0_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_video0_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_video0_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_video0_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_video0_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_video0_ctrl_pll_input_div2_SHIFT 1
#define CCU_pll_video0_ctrl_pll_output_div2 0x1
#define CCU_pll_video0_ctrl_pll_output_div2_SHIFT 0

    // Enable PLL_VIDEO0. Fin=24M N=27 M=2 Fout(4X)=324M
    // Aiming to exceed the 297MHz requirement for DE while being
    // a multiply of 9MHz to generate 9M pixel clock.
    // Though maybe DE needs to be exactly 297, or less than 297...
    ccu.pll_video0_ctrl.write(|w| unsafe {
        w.pll_output_div2().clear_bit()
         .pll_input_div2().set_bit()
         .pll_n().bits(27 - 1)
         .pll_output_gate().clear_bit()
         .lock_enable().clear_bit()
         .pll_ldo_en().set_bit()
         .pll_en().set_bit()
    });
*/
	io_write32(CCU_pll_video0_ctrl, 0
		| (0 << CCU_pll_video0_ctrl_pll_output_div2_SHIFT)
		| (1 << CCU_pll_video0_ctrl_pll_input_div2_SHIFT)
		| ((27-1) << CCU_pll_video0_ctrl_pll_n_SHIFT)
		| (0 << CCU_pll_video0_ctrl_pll_output_gate_SHIFT)
		| (0 << CCU_pll_video0_ctrl_lock_enable_SHIFT)
		| (1 << CCU_pll_video0_ctrl_pll_ldo_en_SHIFT)
		| (1 << CCU_pll_video0_ctrl_pll_en_SHIFT)
	);
	dump_reg(CCU_pll_video0_ctrl); //0xC0001A02
/*
    ccu.pll_video0_ctrl.modify(|_, w| w.lock_enable().set_bit());
    while ccu.pll_video0_ctrl.read().lock().is_unlocked() {}
    unsafe { riscv::asm::delay(20_000) };
*/
	io_write32(CCU_pll_video0_ctrl, io_read32(CCU_pll_video0_ctrl) | CCU_pll_video0_ctrl_lock_enable);
	dump_reg(CCU_pll_video0_ctrl);
	while(!(io_read32(CCU_pll_video0_ctrl) & CCU_pll_video0_ctrl_lock));
	delay_us(20);
	dump_reg(CCU_pll_video0_ctrl);
/*
    ccu.pll_video0_ctrl.modify(|_, w| w.pll_output_gate().set_bit());
*/
	io_write32(CCU_pll_video0_ctrl, io_read32(CCU_pll_video0_ctrl) | CCU_pll_video0_ctrl_pll_output_gate);
	dump_reg(CCU_pll_video0_ctrl); //OK: REGISTER at 0x02001040: 0xF8001A02

/*
#define CCU_tconlcd_clk (CCU + 0xb60) // TCONLCD Clock Register ()
#define CCU_tconlcd_clk_OFFSET 0xb60
#define CCU_tconlcd_clk_clk_gating (0x1 << 31)
#define CCU_tconlcd_clk_clk_gating_SHIFT 31
#define CCU_tconlcd_clk_clk_src_sel (0x7 << 24)
#define CCU_tconlcd_clk_clk_src_sel_SHIFT 24
#define CCU_tconlcd_clk_factor_n (0x3 << 8)
#define CCU_tconlcd_clk_factor_n_SHIFT 8
#define CCU_tconlcd_clk_factor_m 0xf
#define CCU_tconlcd_clk_factor_m_SHIFT 0

    // Set TCON_LCD to PLL_VIDEO0(4X) and enable.
    ccu.tconlcd_clk.write(|w| unsafe {
        w.clk_gating().on()
         .clk_src_sel().pll_video0_4x()
         .factor_n().n1()
         .factor_m().bits(0)
    });

	"clk-mux@0x02001b60": {
		"parent": [
			{ "name": "pll-video0", "value": 0 },
			{ "name": "pll-video0-4x", "value": 1 },
			{ "name": "pll-video1", "value": 2 },
			{ "name": "pll-video1-4x", "value": 3 },
			{ "name": "pll-periph0-2x", "value": 4 },
			{ "name": "pll-audio1-div2", "value": 5 }
		],
		"name": "mux-tconlcd", "shift": 24, "width": 3,
		"default": { "parent": "pll-video0-4x" }
	},

*/
    const int CCU_tconlcd_clk_select_pll_video0_4x = 1;
	io_write32(CCU_tconlcd_clk, 0
		| CCU_tconlcd_clk_clk_gating
		| (CCU_tconlcd_clk_select_pll_video0_4x << CCU_tconlcd_clk_clk_src_sel_SHIFT)
		| ((1-1) << CCU_tconlcd_clk_factor_n_SHIFT)
		| (0 << CCU_tconlcd_clk_factor_m_SHIFT)
	);
	dump_reg(CCU_tconlcd_clk); //REGISTER at 0x02001B60: 0x81000000

/*
#define CCU_tconlcd_bgr (CCU + 0xb7c) // TCONLCD Bus Gating Reset Register ()
#define CCU_tconlcd_bgr_OFFSET 0xb7c
#define CCU_tconlcd_bgr_rst (0x1 << 16)
#define CCU_tconlcd_bgr_rst_SHIFT 16
#define CCU_tconlcd_bgr_gating 0x1
#define CCU_tconlcd_bgr_gating_SHIFT 0

    ccu.tconlcd_bgr.write(|w| w.rst().deassert().gating().pass());
*/
	io_write32(CCU_tconlcd_bgr, CCU_tconlcd_bgr_rst | CCU_tconlcd_bgr_gating);
	dump_reg(CCU_tconlcd_bgr);
/*
#define CCU_de_clk (CCU + 0x600) // DE Clock Register ()
#define CCU_de_clk_OFFSET 0x600
#define CCU_de_clk_clk_gating (0x1 << 31)
#define CCU_de_clk_clk_gating_SHIFT 31
#define CCU_de_clk_clk_src_sel (0x7 << 24)
#define CCU_de_clk_clk_src_sel_SHIFT 24
#define CCU_de_clk_factor_m 0x1f
#define CCU_de_clk_factor_m_SHIFT 0

    // Enable Display Engine clock with VIDEO0(4X)=324MHz and bring out of reset.
    // FACTOR_M=0 for M=1 for DE_CLK=CLK_SRC/1.
    ccu.de_clk.write(|w| w.clk_gating().on().clk_src_sel().pll_video0_4x());

	"clk-mux@0x02001600": {
		"parent": [
			{ "name": "pll-periph0-2x", "value": 0 },
			{ "name": "pll-video0-4x", "value": 1 },
			{ "name": "pll-video1-4x", "value": 2 },
			{ "name": "pll-audio1-div2", "value": 3 }
		],

*/
    const int CCU_de_clk_select_pll_video0_4x = 1;
	io_write32(CCU_de_clk, CCU_de_clk_clk_gating | (CCU_de_clk_select_pll_video0_4x << CCU_de_clk_clk_src_sel_SHIFT));
	dump_reg(CCU_de_clk);
/*
#define CCU_de_bgr (CCU + 0x60c) // DE Bus Gating Reset Register ()
#define CCU_de_bgr_OFFSET 0x60c
#define CCU_de_bgr_rst (0x1 << 16)
#define CCU_de_bgr_rst_SHIFT 16
#define CCU_de_bgr_gating 0x1
#define CCU_de_bgr_gating_SHIFT 0

    ccu.de_bgr.write(|w| w.rst().deassert().gating().pass());
*/
	io_write32(CCU_de_bgr, CCU_de_bgr_rst | CCU_de_bgr_gating);
	dump_reg(CCU_de_bgr);

/*
#define GPIO_pd_cfg0 (GPIO + 0x90) // PD Configure Register 0 ()
#define GPIO_pd_cfg0_OFFSET 0x90
#define GPIO_pd_cfg0_pd7_select (0xf << 28)
#define GPIO_pd_cfg0_pd7_select_SHIFT 28
#define GPIO_pd_cfg0_pd6_select (0xf << 24)
#define GPIO_pd_cfg0_pd6_select_SHIFT 24
#define GPIO_pd_cfg0_pd5_select (0xf << 20)
#define GPIO_pd_cfg0_pd5_select_SHIFT 20
#define GPIO_pd_cfg0_pd4_select (0xf << 16)
#define GPIO_pd_cfg0_pd4_select_SHIFT 16
#define GPIO_pd_cfg0_pd3_select (0xf << 12)
#define GPIO_pd_cfg0_pd3_select_SHIFT 12
#define GPIO_pd_cfg0_pd2_select (0xf << 8)
#define GPIO_pd_cfg0_pd2_select_SHIFT 8
#define GPIO_pd_cfg0_pd1_select (0xf << 4)
#define GPIO_pd_cfg0_pd1_select_SHIFT 4
#define GPIO_pd_cfg0_pd0_select 0xf
#define GPIO_pd_cfg0_pd0_select_SHIFT 0

    // Set PD0-21 to LCD functions, and PD22 (LCD backlight PWM) to output.
    gpio.pd_cfg0.write(|w|
        w.pd0_select().lcd0_d2()
         .pd1_select().lcd0_d3()
         .pd2_select().lcd0_d4()
         .pd3_select().lcd0_d5()
         .pd4_select().lcd0_d6()
         .pd5_select().lcd0_d7()
         .pd6_select().lcd0_d10()
         .pd7_select().lcd0_d11());
    gpio.pd_cfg1.write(|w|
        w.pd8_select().lcd0_d12()
         .pd9_select().lcd0_d13()
         .pd10_select().lcd0_d14()
         .pd11_select().lcd0_d15()
         .pd12_select().lcd0_d18()
         .pd13_select().lcd0_d19()
         .pd14_select().lcd0_d20()
         .pd15_select().lcd0_d21());
    gpio.pd_cfg2.write(|w|
        w.pd16_select().lcd0_d22()
         .pd17_select().lcd0_d23()
         .pd18_select().lcd0_clk()
         .pd19_select().lcd0_de()
         .pd20_select().lcd0_hsync()
         .pd21_select().lcd0_vsync()
         .pd22_select().output());

*/
	io_write32(GPIO_pd_cfg0, 0
		| (2 << GPIO_pd_cfg0_pd0_select_SHIFT) //d2
		| (2 << GPIO_pd_cfg0_pd1_select_SHIFT) //d3
		| (2 << GPIO_pd_cfg0_pd2_select_SHIFT) //d4
		| (2 << GPIO_pd_cfg0_pd3_select_SHIFT) //d5
		| (2 << GPIO_pd_cfg0_pd4_select_SHIFT) //d6
		| (2 << GPIO_pd_cfg0_pd5_select_SHIFT) //d7
		| (2 << GPIO_pd_cfg0_pd6_select_SHIFT) //d10
		| (2 << GPIO_pd_cfg0_pd7_select_SHIFT) //d11
	);
	dump_reg(GPIO_pd_cfg0);
	io_write32(GPIO_pd_cfg1, 0
		| (2 << GPIO_pd_cfg1_pd8_select_SHIFT) //d12
		| (2 << GPIO_pd_cfg1_pd9_select_SHIFT) //d13
		| (2 << GPIO_pd_cfg1_pd10_select_SHIFT) //d14
		| (2 << GPIO_pd_cfg1_pd11_select_SHIFT) //d15
		| (2 << GPIO_pd_cfg1_pd12_select_SHIFT) //d18
		| (2 << GPIO_pd_cfg1_pd13_select_SHIFT) //d19
		| (2 << GPIO_pd_cfg1_pd14_select_SHIFT) //d20
		| (2 << GPIO_pd_cfg1_pd15_select_SHIFT) //d21
	);
	dump_reg(GPIO_pd_cfg1);
	io_write32(GPIO_pd_cfg2, 0
		| (2 << GPIO_pd_cfg2_pd16_select_SHIFT) //d22
		| (2 << GPIO_pd_cfg2_pd17_select_SHIFT) //d23
		| (2 << GPIO_pd_cfg2_pd18_select_SHIFT) //clk
		| (2 << GPIO_pd_cfg2_pd19_select_SHIFT) //de
		| (2 << GPIO_pd_cfg2_pd20_select_SHIFT) //hsync
		| (2 << GPIO_pd_cfg2_pd21_select_SHIFT) //vsync
		| (1 << GPIO_pd_cfg2_pd22_select_SHIFT) //OUTPUT (PWM / led)
	);
	dump_reg(GPIO_pd_cfg2);
/*
    // Turn on LCD backlight (PWM can come later).
    gpio.pd_dat.write(|w| unsafe { w.bits(1<<22) });
    dump_reg(&gpio.pd_dat);
*/
	io_write32(GPIO_pd_dat, 1<<22);
	dump_reg(GPIO_pd_dat);

/*
#define TCON_LCD0 0x05461000
#define TCON_LCD0_lcd_gctl (TCON_LCD0 + 0x0) // LCD Global Control Register ()
#define TCON_LCD0_lcd_gctl_OFFSET 0x0
#define TCON_LCD0_lcd_gctl_lcd_en (0x1 << 31)
#define TCON_LCD0_lcd_gctl_lcd_en_SHIFT 31
#define TCON_LCD0_lcd_gctl_lcd_gamma_en (0x1 << 30)
#define TCON_LCD0_lcd_gctl_lcd_gamma_en_SHIFT 30

    // Configure TCON for RGB operation:
    // TCON_EN / LCD_EN
    lcd0.lcd_gctl_reg.write(|w| unsafe { w.bits(1 << 31) });
*/
	io_write32(TCON_LCD0_lcd_gctl, TCON_LCD0_lcd_gctl_lcd_en);
	dump_reg(TCON_LCD0_lcd_gctl);
/*
#define TCON_LCD0_lcd_ctl (TCON_LCD0 + 0x40) // LCD Control Register ()
#define TCON_LCD0_lcd_ctl_OFFSET 0x40
#define TCON_LCD0_lcd_ctl_lcd_en (0x1 << 31)
#define TCON_LCD0_lcd_ctl_lcd_en_SHIFT 31
#define TCON_LCD0_lcd_ctl_lcd_if (0x3 << 24)
#define TCON_LCD0_lcd_ctl_lcd_if_SHIFT 24
#define TCON_LCD0_lcd_ctl_lcd_rb_swap (0x1 << 23)
#define TCON_LCD0_lcd_ctl_lcd_rb_swap_SHIFT 23
#define TCON_LCD0_lcd_ctl_lcd_fifo1_rst (0x1 << 21)
#define TCON_LCD0_lcd_ctl_lcd_fifo1_rst_SHIFT 21
#define TCON_LCD0_lcd_ctl_lcd_interlace_en (0x1 << 20)
#define TCON_LCD0_lcd_ctl_lcd_interlace_en_SHIFT 20
#define TCON_LCD0_lcd_ctl_lcd_start_dly (0x1f << 4)
#define TCON_LCD0_lcd_ctl_lcd_start_dly_SHIFT 4
#define TCON_LCD0_lcd_ctl_lcd_src_sel 0x7
#define TCON_LCD0_lcd_ctl_lcd_src_sel_SHIFT 0

    // Configure TCON_LCD in RGB666 mode for our 480x272 LCD.
    lcd0.lcd_ctl_reg.write(|w| unsafe { w.bits(
        // LCD_CTL_REG.LCD_EN=0 to disable
        (0 << 31)
        // LCD_CTL_REG.LCD_IF=0 for HV(Sync+DE)
        | (0 << 24)
        // Delay is VT-VD=292-272=20 (max 30)
        | (22 << 4) //VFP+VBP+sync (((33+10+2)/2)0x1f)
        // LCD_CTL_REG.LCD_SRC_SEL=000 for Display Engine source.
        // Try 0b001 for color check or 0b111 for grid check.
        | (0b000 << 0)
    )});
*/
	io_write32(TCON_LCD0_lcd_ctl, 0
		| (0 << TCON_LCD0_lcd_ctl_lcd_en_SHIFT)
		| (0 << TCON_LCD0_lcd_ctl_lcd_if_SHIFT)
		| (22 << TCON_LCD0_lcd_ctl_lcd_start_dly_SHIFT)
		| 0b000 //0b111
	);
	dump_reg(TCON_LCD0_lcd_ctl);
/*
#define TCON_LCD0_lcd_hv_if (TCON_LCD0 + 0x58) // LCD HV Panel Interface Register ()
#define TCON_LCD0_lcd_hv_if_OFFSET 0x58
#define TCON_LCD0_lcd_hv_if_hv_mode (0xf << 28)
#define TCON_LCD0_lcd_hv_if_hv_mode_SHIFT 28
#define TCON_LCD0_lcd_hv_if_rgb888_odd_order (0x3 << 26)
#define TCON_LCD0_lcd_hv_if_rgb888_odd_order_SHIFT 26
#define TCON_LCD0_lcd_hv_if_rgb888_even_order (0x3 << 24)
#define TCON_LCD0_lcd_hv_if_rgb888_even_order_SHIFT 24
#define TCON_LCD0_lcd_hv_if_yuv_sm (0x3 << 22)
#define TCON_LCD0_lcd_hv_if_yuv_sm_SHIFT 22
#define TCON_LCD0_lcd_hv_if_yuv_eav_sav_f_line_dly (0x3 << 20)
#define TCON_LCD0_lcd_hv_if_yuv_eav_sav_f_line_dly_SHIFT 20
#define TCON_LCD0_lcd_hv_if_ccir_csc_dis (0x1 << 19)
#define TCON_LCD0_lcd_hv_if_ccir_csc_dis_SHIFT 19

    lcd0.lcd_hv_if_reg.write(|w| unsafe { w.bits(
        // LCD_HV_IF_REG.HV_MODE=0 for 24bit/cycle parallel mode.
        0 << 28
    )});
*/
	io_write32(TCON_LCD0_lcd_hv_if, 0 << TCON_LCD0_lcd_hv_if_hv_mode_SHIFT);
	dump_reg(TCON_LCD0_lcd_hv_if);
/*
#define TCON_LCD0_lcd_dclk (TCON_LCD0 + 0x44) // LCD Data Clock Register ()
#define TCON_LCD0_lcd_dclk_OFFSET 0x44
#define TCON_LCD0_lcd_dclk_lcd_dclk_en (0xf << 28)
#define TCON_LCD0_lcd_dclk_lcd_dclk_en_SHIFT 28
#define TCON_LCD0_lcd_dclk_lcd_dclk_div 0x7f
#define TCON_LCD0_lcd_dclk_lcd_dclk_div_SHIFT 0

    lcd0.lcd_dclk_reg.write(|w| unsafe { w.bits(
        // LCD_DCLK_REG.LCD_DCLK_EN=0001 for dclk_en=1, others=0
        (0b0001 << 28)
        // Linux just sets bit 31, i.e. 0b1000, which is "reserved" in D1 docs.
        //(1 << 31)
        // LCD_DCLK_REG.LCD_DCLK_DIV=36 for /36 to obtain 9MHz DCLK from 324MHz.
        | (13 << 0) //324MHz/13 = ~25MHz
    )});
*/
	io_write32(TCON_LCD0_lcd_dclk, 0
		| (0b0001 << TCON_LCD0_lcd_dclk_lcd_dclk_en_SHIFT)
		| (13 << TCON_LCD0_lcd_dclk_lcd_dclk_div_SHIFT)
	);
	dump_reg(TCON_LCD0_lcd_dclk);
/*
#define TCON_LCD0_lcd_basic0 (TCON_LCD0 + 0x48) // LCD Basic Timing Register0 ()
#define TCON_LCD0_lcd_basic0_OFFSET 0x48
#define TCON_LCD0_lcd_basic0_width_x (0xfff << 16)
#define TCON_LCD0_lcd_basic0_width_x_SHIFT 16
#define TCON_LCD0_lcd_basic0_height_y 0xfff
#define TCON_LCD0_lcd_basic0_height_y_SHIFT 0
    lcd0.lcd_basic0_reg.write(|w| unsafe { w.bits(
        // LCD_BASIC0_REG.WIDTH_X=479 for 480px wide panel
        ((640-1) << 16)
        // LCD_BASIC0_REG.HEIGHT_Y=271 for 272px tall panel
        | ((480-1) << 0)
    )});
*/
	io_write32(TCON_LCD0_lcd_basic0, 0
		| ((640-1) << TCON_LCD0_lcd_basic0_width_x_SHIFT)
		| ((480-1) << TCON_LCD0_lcd_basic0_height_y_SHIFT)
	);
	dump_reg(TCON_LCD0_lcd_basic0);
/*
#define TCON_LCD0_lcd_basic1 (TCON_LCD0 + 0x4c) // LCD Basic Timing Register1 ()
#define TCON_LCD0_lcd_basic1_OFFSET 0x4c
#define TCON_LCD0_lcd_basic1_ht (0x1fff << 16)
#define TCON_LCD0_lcd_basic1_ht_SHIFT 16
#define TCON_LCD0_lcd_basic1_hbp 0xfff
#define TCON_LCD0_lcd_basic1_hbp_SHIFT 0

    lcd0.lcd_basic1_reg.write(|w| unsafe { w.bits(
        // LCD_BASIC1_REG.HT=530 for 531 horizontal clocks total
        ((800-1) << 16)
        // LCD_BASIC1_REG.HBP=42 for 43 Thbp (sync+bp)
        | ((96+48-1) << 0)
    )});
*/
	io_write32(TCON_LCD0_lcd_basic1, 0
		| ((800-1) << TCON_LCD0_lcd_basic1_ht_SHIFT)
		| ((96+48-1) << TCON_LCD0_lcd_basic1_hbp_SHIFT
	));
	dump_reg(TCON_LCD0_lcd_basic1);
/*
#define TCON_LCD0_lcd_basic2 (TCON_LCD0 + 0x50) // LCD Basic Timing Register2 ()
#define TCON_LCD0_lcd_basic2_OFFSET 0x50
#define TCON_LCD0_lcd_basic2_vt (0x1fff << 16)
#define TCON_LCD0_lcd_basic2_vt_SHIFT 16
#define TCON_LCD0_lcd_basic2_vbp 0xfff
#define TCON_LCD0_lcd_basic2_vbp_SHIFT 0

    lcd0.lcd_basic2_reg.write(|w| unsafe { w.bits(
        // LCD_BASIC2_REG.VT=584 for 292 vertical rows total
        ((525*2) << 16)
        // LCD_BASIC2_REG.VBP=11 for 12 Tvbp (sync+bp)
        | ((2+33-1) << 0)
    )});
*/
	io_write32(TCON_LCD0_lcd_basic2, 0
		| ((525*2) << TCON_LCD0_lcd_basic2_vt_SHIFT)
        | ((2+33-1) << TCON_LCD0_lcd_basic2_vbp_SHIFT)
	);
	dump_reg(TCON_LCD0_lcd_basic2);
/*
#define TCON_LCD0_lcd_basic3 (TCON_LCD0 + 0x54) // LCD Basic Timing Register3 ()
#define TCON_LCD0_lcd_basic3_OFFSET 0x54
#define TCON_LCD0_lcd_basic3_hspw (0x3ff << 16)
#define TCON_LCD0_lcd_basic3_hspw_SHIFT 16
#define TCON_LCD0_lcd_basic3_vspw 0x3ff
#define TCON_LCD0_lcd_basic3_vspw_SHIFT 0

    lcd0.lcd_basic3_reg.write(|w| unsafe { w.bits(
        // LCD_BASIC3_REG.HSPW=3 for 4 DCLK wide HSYNC pulse
        (96 << 16)
        // LCD_BASIC3_REG.VSPW=3 for 4 row long VSYNC pulse
        | (2 << 0)
    )});
*/
	io_write32(TCON_LCD0_lcd_basic3, 0
		| (96 << TCON_LCD0_lcd_basic3_hspw_SHIFT)
        | (2 << TCON_LCD0_lcd_basic3_vspw_SHIFT)
	);
	dump_reg(TCON_LCD0_lcd_basic3);
/*
#define TCON_LCD0_lcd_io_tri (TCON_LCD0 + 0x8c) // LCD IO Control Register ()
#define TCON_LCD0_lcd_io_tri_OFFSET 0x8c
#define TCON_LCD0_lcd_io_tri_RESET 0x0FFFFFFF
#define TCON_LCD0_lcd_io_tri_rgb_endian (0x1 << 28)
#define TCON_LCD0_lcd_io_tri_rgb_endian_SHIFT 28
#define TCON_LCD0_lcd_io_tri_io0_output_tri_en (0x1 << 24)
#define TCON_LCD0_lcd_io_tri_io0_output_tri_en_SHIFT 24
#define TCON_LCD0_lcd_io_tri_data_output_tri_en 0xffffff
#define TCON_LCD0_lcd_io_tri_data_output_tri_en_SHIFT 0
    lcd0.lcd_io_tri_reg.write(|w| unsafe { w.bits(
        // Enable IO0-3, D2..7, D10..15, D18..23 inclusive.
        0x0003_0303
    )});
*/
	io_write32(TCON_LCD0_lcd_io_tri, 0x00030303);
	dump_reg(TCON_LCD0_lcd_io_tri);
/*
#define TCON_LCD0_lcd_io_pol (TCON_LCD0 + 0x88) // LCD IO Polarity Register ()
#define TCON_LCD0_lcd_io_pol_OFFSET 0x88
#define TCON_LCD0_lcd_io_pol_io_output_sel (0x1 << 31)
#define TCON_LCD0_lcd_io_pol_io_output_sel_SHIFT 31
#define TCON_LCD0_lcd_io_pol_dclk_sel (0x7 << 28)
#define TCON_LCD0_lcd_io_pol_dclk_sel_SHIFT 28
#define TCON_LCD0_lcd_io_pol_io0_inv (0x1 << 24)
#define TCON_LCD0_lcd_io_pol_io0_inv_SHIFT 24
#define TCON_LCD0_lcd_io_pol_data_inv 0xffffff
#define TCON_LCD0_lcd_io_pol_data_inv_SHIFT 0

    lcd0.lcd_io_pol_reg.write(|w| unsafe { w.bits(
        0b0011 << 24 //DE, CLK, H, V polarity
    )});
*/
	io_write32(TCON_LCD0_lcd_io_pol, 0b0011 << TCON_LCD0_lcd_io_pol_io0_inv_SHIFT);
	dump_reg(TCON_LCD0_lcd_io_pol);
/*
    // LCD_EN
    lcd0.lcd_ctl_reg.modify(|r, w| unsafe { w.bits(r.bits() | (1 << 31)) });

*/
	io_write32(TCON_LCD0_lcd_ctl, io_read32(TCON_LCD0_lcd_ctl) | TCON_LCD0_lcd_ctl_lcd_en);
	dump_reg(TCON_LCD0_lcd_ctl);
/*
    unsafe { de::init(&FB.0) };
*/
	void init_de(void);
	init_de();
}

/*
Working values for 640x480 (test grid):
REGISTER at 0x2001040: 0xc0001a02
REGISTER at 0x2001040: 0xe0001a02
REGISTER at 0x2001040: 0xf0001a02
REGISTER at 0x2001040: 0xf8001a02
REGISTER at 0x2001b60: 0x81000000
REGISTER at 0x2001b7c: 0x10001
REGISTER at 0x2001600: 0x81000000
REGISTER at 0x200160c: 0x10001
REGISTER at 0x2000090: 0x22222222
REGISTER at 0x2000094: 0x22222222
REGISTER at 0x2000098: 0x1222222
REGISTER at 0x20000a0: 0x400000
REGISTER at 0x5461000: 0x80000000
REGISTER at 0x5461040: 0x167
REGISTER at 0x5461058: 0x0
REGISTER at 0x5461044: 0x1000000d
REGISTER at 0x5461048: 0x27f01df
REGISTER at 0x546104c: 0x31f008f
REGISTER at 0x5461050: 0x41a0022
REGISTER at 0x5461054: 0x600002
REGISTER at 0x546108c: 0x30303
REGISTER at 0x5461088: 0x3
REGISTER at 0x5461040: 0x80000167
*/

#define DE_BASE	 0x05000000
#define DE_SCLK_GATE	 (DE_BASE + 0x000)
#define DE_HCLK_GATE	 (DE_BASE + 0x004)
#define DE_AHB_RESET	 (DE_BASE + 0x008)
#define DE_SCLK_DIV	 (DE_BASE + 0x00C)

#define DE_MIXER0	 (DE_BASE + 0x00100000)
#define DE_M0_GLB	 (DE_MIXER0 + 0x00000)
#define DE_M0_BLD	 (DE_MIXER0 + 0x01000)
#define DE_M0_OVL_V	 (DE_MIXER0 + 0x02000)
#define DE_M0_OVL_UI1	 (DE_MIXER0 + 0x03000)
#define DE_M0_VIDEO_SCALAR	 (DE_MIXER0 + 0x20000)
#define DE_M0_UI_SCALAR1	 (DE_MIXER0 + 0x40000)
#define DE_M0_POST_PROC1	 (DE_MIXER0 + 0xA0000)
#define DE_M0_POST_PROC2	 (DE_MIXER0 + 0xB0000)
#define DE_M0_DMA	 (DE_MIXER0 + 0xC0000)

#define DE_M0_GLB_CTL	 (DE_M0_GLB + 0x000)
#define DE_M0_GLB_STS	 (DE_M0_GLB + 0x004)
#define DE_M0_GLB_DBUFFER	 (DE_M0_GLB + 0x008)
#define DE_M0_GLB_SIZE	 (DE_M0_GLB + 0x00C)
#define DE_M0_OVL_V_ATTCTL	 (DE_M0_OVL_V + 0x000)
#define DE_M0_OVL_V_MBSIZE	 (DE_M0_OVL_V + 0x004)
#define DE_M0_OVL_V_COOR	 (DE_M0_OVL_V + 0x008)
#define DE_M0_OVL_V_PITCH0	 (DE_M0_OVL_V + 0x00C)
#define DE_M0_OVL_V_PITCH1	 (DE_M0_OVL_V + 0x010)
#define DE_M0_OVL_V_PITCH2	 (DE_M0_OVL_V + 0x014)
#define DE_M0_OVL_V_TOP_LADD0	 (DE_M0_OVL_V + 0x018)
#define DE_M0_OVL_V_TOP_LADD1	 (DE_M0_OVL_V + 0x01C)
#define DE_M0_OVL_V_TOP_LADD2	 (DE_M0_OVL_V + 0x020)
#define DE_M0_OVL_V_BOT_LADD0	 (DE_M0_OVL_V + 0x024)
#define DE_M0_OVL_V_BOT_LADD1	 (DE_M0_OVL_V + 0x028)
#define DE_M0_OVL_V_BOT_LADD2	 (DE_M0_OVL_V + 0x02C)
#define DE_M0_OVL_V_FILL_COLOR	 (DE_M0_OVL_V + 0x0C0)
#define DE_M0_OVL_V_TOP_HADD0	 (DE_M0_OVL_V + 0x0D0)
#define DE_M0_OVL_V_TOP_HADD1	 (DE_M0_OVL_V + 0x0D4)
#define DE_M0_OVL_V_TOP_HADD2	 (DE_M0_OVL_V + 0x0D8)
#define DE_M0_OVL_V_BOT_HADD0	 (DE_M0_OVL_V + 0x0DC)
#define DE_M0_OVL_V_BOT_HADD1	 (DE_M0_OVL_V + 0x0E0)
#define DE_M0_OVL_V_BOT_HADD2	 (DE_M0_OVL_V + 0x0E4)
#define DE_M0_OVL_V_SIZE	 (DE_M0_OVL_V + 0x0E8)
#define DE_M0_OVL_V_HDS_CTL0	 (DE_M0_OVL_V + 0x0F0)
#define DE_M0_OVL_V_HDS_CTL1	 (DE_M0_OVL_V + 0x0F4)
#define DE_M0_OVL_V_VDS_CTL0	 (DE_M0_OVL_V + 0x0F8)
#define DE_M0_OVL_V_VDS_CTL1	 (DE_M0_OVL_V + 0x0FC)
#define DE_M0_UI1_ATTCTL_L0	 (DE_M0_OVL_UI1 + 0x000)
#define DE_M0_UI1_MBSIZE_L0	 (DE_M0_OVL_UI1 + 0x004)
#define DE_M0_UI1_COOR_L0	 (DE_M0_OVL_UI1 + 0x008)
#define DE_M0_UI1_PITCH_L0	 (DE_M0_OVL_UI1 + 0x00C)
#define DE_M0_UI1_TOP_LADD_L0	 (DE_M0_OVL_UI1 + 0x010)
#define DE_M0_UI1_BOT_LADD_L0	 (DE_M0_OVL_UI1 + 0x014)
#define DE_M0_UI1_FILL_COLOR_L0	 (DE_M0_OVL_UI1 + 0x018)
#define DE_M0_UI1_TOP_HADD	 (DE_M0_OVL_UI1 + 0x080)
#define DE_M0_UI1_BOT_HADD	 (DE_M0_OVL_UI1 + 0x084)
#define DE_M0_UI1_SIZE	 (DE_M0_OVL_UI1 + 0x088)
#define DE_M0_BLD_FILL_COLOR_CTL	 (DE_M0_BLD + 0x000)
#define DE_M0_BLD_FILL_COLOR_P0	 (DE_M0_BLD + 0x004 + 0 * 0x14)
#define DE_M0_BLD_CH_ISIZE_P0	 (DE_M0_BLD + 0x008 + 0 * 0x14)
#define DE_M0_BLD_CH_OFFSET_P0	 (DE_M0_BLD + 0x008 + 0 * 0x14)
#define DE_M0_BLD_CH_RTCTL	 (DE_M0_BLD + 0x080)
#define DE_M0_BLD_PREMUL_CTL	 (DE_M0_BLD + 0x084)
#define DE_M0_BLD_BK_COLOR	 (DE_M0_BLD + 0x088)
#define DE_M0_BLD_SIZE	 (DE_M0_BLD + 0x08C)
#define DE_M0_BLD_CTL	 (DE_M0_BLD + 0x090)
#define DE_M0_BLD_KEY_CTL	 (DE_M0_BLD + 0x0B0)
#define DE_M0_BLD_KEY_CON	 (DE_M0_BLD + 0x0B4)
#define DE_M0_BLD_KEY_MAX	 (DE_M0_BLD + 0x0C0)
#define DE_M0_BLD_KEY_MIN	 (DE_M0_BLD + 0x0E0)
#define DE_M0_BLD_OUT_COLOR	 (DE_M0_BLD + 0x0FC)


#warning this should be parameters
uintptr_t framebuffer_address;
unsigned framebuffer_pitch;

//see https://linux-sunxi.org/images/7/7b/Allwinner_DE2.0_Spec_V1.0.pdf section 5.10
void init_de(void)
{
    framebuffer_pitch = 640*sizeof(uint32_t);
	
    // Enable ROT_SCLK_GATE, RT_WB_SCLK_GATE, CORE1_SCLK_GATE, CORE0_SCLK_GATE
    // (at least, as they exist in the H8).
    // write_volatile(DE_SCLK_GATE as *mut u32, 0xF);
    io_write32(DE_SCLK_GATE, 0b1111);
    dump_reg(DE_SCLK_GATE);

    // Enable ROT_HCLK_GATE, RT_WB_HCLK_GATE, CORE1_HCLK_GATE, CORE_HCLK_GATE0
    // (at least, as they exist in the H8).
    // write_volatile(DE_HCLK_GATE as *mut u32, 0xF);
    io_write32(DE_HCLK_GATE, 0b1111);
    dump_reg(DE_HCLK_GATE);

    // Bring ROT, RT_WB, CORE1, CORE0 out of reset.
    // write_volatile(DE_AHB_RESET as *mut u32, 0xF);
    io_write32(DE_AHB_RESET, 0b1111);
    dump_reg(DE_AHB_RESET);

    // Hopefully default div is OK.
    /* write_volatile(DE_SCLK_DIV as *mut u32,
          (0 << 12)     // ROT_SCLK_DIV
        | (0 <<  8)     // RT_WB_SCLK_DIV
        | (0 <<  4)     // CORE1_SCLK_DIV
        | (0 <<  0)     // CORE0_SCLK_DIV
    );*/
    io_write32(DE_SCLK_DIV, 0
    	| (0 << 12)     // ROT_SCLK_DIV
        | (0 <<  8)     // RT_WB_SCLK_DIV
        | (0 <<  4)     // CORE1_SCLK_DIV
        | (0 <<  0)     // CORE0_SCLK_DIV
	);    	
    dump_reg(DE_SCLK_DIV);

    // Hopefully DE2TCON_MUX either doesn't exist or default is fine.
    // Hopefully CMD_CTL either doesn't exist or default is fine.
    // Hopefully DI_CTL either doesn't exist or default is fine.

    // Enable RT
    // write_volatile(DE_M0_GLB_CTL as *mut u32, 1);
    io_write32(DE_M0_GLB_CTL, 1);
    dump_reg(DE_M0_GLB_CTL);

    // Set height=272 and width=480
    // write_volatile(DE_M0_GLB_SIZE as *mut u32, ((480-1) << 16) | ((640-1) << 0));
    io_write32(DE_M0_GLB_SIZE, ((480-1) << 16) | ((640-1) << 0));
    dump_reg(DE_M0_GLB_SIZE);

    // Set OVL_UI1_L0 to alpha=FF, top-addr-only, no-premult, BGR888, no fill, global alpha, enable
    // NB not sure why BGR is required, since data is in RGB...??
    // write_volatile(DE_M0_UI1_ATTCTL_L0 as *mut u32, (0xFF << 24) | (0 << 23) | (0 << 16) | (0x09 << 8) | (0 << 4) | (1 << 1) | (1 << 0));
    //See DE manual, Section 5.10.8
    //Note: the layer priority is layer3>layer2>layer1>layer0
    enum LAY_FBFMT
    {
	ARGB_8888 = 0,
	ABGR_8888,
	RGBA_8888,
	BGRA_8888,
	XRGB_8888,
	XBGR_8888,
	RGBX_8888,
	BGRX_8888,
	RGB_888,
	BGR_888,
	RGB_565,
	BGR_565,
	ARGB_4444,
	ABGR_4444,
	RGBA_4444,
	BGRA_4444,
	ARGB_1555,
	ABGR_1555,
	RGBA_5551,
	BGRA_5551
    };
    io_write32(DE_M0_UI1_ATTCTL_L0, 0
    	| (0xFF << 24) //LAY_GBLALPHA
    	| (0 << 23) //TOP_BOTTOM_ADDR_EN
    	| (0 << 16) //LAY_PREMUL_CTL
    	| (XBGR_8888 << 8) //LAY_FBFMT
    	| (0 << 4) //LAY_FILLCOLOR_EN
    	| (1 << 1) //LAY_ALPHA_MODE
    	| (1 << 0) //LAY_EN
    );
    dump_reg(DE_M0_UI1_ATTCTL_L0);

    // Set OVL_UI1_L0 to height=272 width=480
    // write_volatile(DE_M0_UI1_MBSIZE_L0 as *mut u32, ((480-1) << 16) | ((640-1) << 0));
    io_write32(DE_M0_UI1_MBSIZE_L0, ((480-1) << 16) | ((640-1) << 0));
    dump_reg(DE_M0_UI1_MBSIZE_L0);

    // Set OVL_UI1_L0 coordinate to 0, 0
    // write_volatile(DE_M0_UI1_COOR_L0 as *mut u32, (0 << 16) | (0 << 0));
    io_write32(DE_M0_UI1_COOR_L0, (0 << 16) | (0 << 0));
    dump_reg(DE_M0_UI1_COOR_L0);

    // Set OVL_UI1_L0 pitch to 480*3 bytes/line.
    // write_volatile(DE_M0_UI1_PITCH_L0 as *mut u32, 640*3);
    io_write32(DE_M0_UI1_PITCH_L0, framebuffer_pitch);
    dump_reg(DE_M0_UI1_PITCH_L0);

    // Set memory start address
    // write_volatile(DE_M0_UI1_TOP_LADD_L0 as *mut u32, fb.as_ptr() as u32);
    // write_volatile(DE_M0_UI1_TOP_HADD as *mut u32, 0);
    io_write32(DE_M0_UI1_TOP_LADD_L0, framebuffer_address);
    dump_reg(DE_M0_UI1_TOP_LADD_L0);
    io_write32(DE_M0_UI1_TOP_HADD, 0);
    dump_reg(DE_M0_UI1_TOP_HADD);

    // Set overlay to 272x480
    // write_volatile(DE_M0_UI1_SIZE as *mut u32, ((480-1) << 16) | ((640-1) << 0));
    io_write32(DE_M0_UI1_SIZE, ((480-1) << 16) | ((640-1) << 0));
    dump_reg(DE_M0_UI1_SIZE);

    // Enable Pipe0, no fill
    // write_volatile(DE_M0_BLD_FILL_COLOR_CTL as *mut u32, 1<<8);
    io_write32(DE_M0_BLD_FILL_COLOR_CTL, 1<<8);
    dump_reg(DE_M0_BLD_FILL_COLOR_CTL);

    // Pipe0 Input size 272x480
    // write_volatile(DE_M0_BLD_CH_ISIZE_P0 as *mut u32, ((480-1)<<16) | ((640-1) << 0));
    io_write32(DE_M0_BLD_CH_ISIZE_P0, ((480-1)<<16) | ((640-1) << 0));
    dump_reg(DE_M0_BLD_CH_ISIZE_P0);

    // Pipe 0 offset apparently needs to be 271,479? Not sure why.
    // write_volatile(DE_M0_BLD_CH_OFFSET_P0 as *mut u32, ((480-1) << 16) | ((640-1) << 0));
    io_write32(DE_M0_BLD_CH_OFFSET_P0, ((480-1) << 16) | ((640-1) << 0));
    dump_reg(DE_M0_BLD_CH_OFFSET_P0);

    // Pipe 0 select from channel 1, pipe 1 from 0, pipe 2 from 2, pipe 3 from 3
    // write_volatile(DE_M0_BLD_CH_RTCTL as *mut u32, (3<<12) | (2<<8) | (0<<4) | (1<<0));
    io_write32(DE_M0_BLD_CH_RTCTL, (3<<12) | (2<<8) | (0<<4) | (1<<0));
    dump_reg(DE_M0_BLD_CH_RTCTL);

    // Output size 272x480
    // write_volatile(DE_M0_BLD_SIZE as *mut u32, ((480-1) << 16) | ((640-1) << 0));
    io_write32(DE_M0_BLD_SIZE, ((480-1) << 16) | ((640-1) << 0));
    dump_reg(DE_M0_BLD_SIZE);
}

/*
DE values for 640x480, 32-bpp:
EGISTER at 0x5000000: 0xf
REGISTER at 0x5000004: 0xf
REGISTER at 0x5000008: 0xf
REGISTER at 0x500000c: 0x0
REGISTER at 0x5100000: 0x1
REGISTER at 0x510000c: 0x1df027f
REGISTER at 0x5103000: 0xff000503
REGISTER at 0x5103004: 0x1df027f
REGISTER at 0x5103008: 0x0
REGISTER at 0x510300c: 0xa00
REGISTER at 0x5103010: 0x40000b50
REGISTER at 0x5103080: 0x0
REGISTER at 0x5103088: 0x1df027f
REGISTER at 0x5101000: 0x100
REGISTER at 0x5101008: 0x1df027f
REGISTER at 0x5101008: 0x1df027f
REGISTER at 0x5101080: 0x3201
REGISTER at 0x510108c: 0x1df027f
*/
