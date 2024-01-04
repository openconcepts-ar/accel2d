/****************************************************************
 * D1H v1.0 SVD peripherals & registers
 * generated @ 2024-01-01 14:17:13
 * 
 * DO NOT EDIT! This file was auto-generated with:
 * http://github.com/postspectacular/cmsis-svd-srcgen
 ****************************************************************/

#ifndef _CMSIS_SVD_H
#define _CMSIS_SVD_H

/****************************************************************
 * Clock Controller Unit
 ****************************************************************/
#define CCU 0x02001000
#define CCU_pll_cpu_ctrl (CCU + 0x0) // PLL_CPU Control Register ()
#define CCU_pll_cpu_ctrl_OFFSET 0x0
#define CCU_pll_cpu_ctrl_pll_en (0x1 << 31)
#define CCU_pll_cpu_ctrl_pll_en_SHIFT 31
#define CCU_pll_cpu_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_cpu_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_cpu_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_cpu_ctrl_lock_enable_SHIFT 29
#define CCU_pll_cpu_ctrl_lock (0x1 << 28)
#define CCU_pll_cpu_ctrl_lock_SHIFT 28
#define CCU_pll_cpu_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_cpu_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_cpu_ctrl_pll_lock_time (0x7 << 24)
#define CCU_pll_cpu_ctrl_pll_lock_time_SHIFT 24
#define CCU_pll_cpu_ctrl_pll_n (0xff << 8)
#define CCU_pll_cpu_ctrl_pll_n_SHIFT 8
#define CCU_pll_cpu_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_cpu_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_cpu_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_cpu_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_cpu_ctrl_pll_m 0x3
#define CCU_pll_cpu_ctrl_pll_m_SHIFT 0
#define CCU_pll_ddr_ctrl (CCU + 0x10) // PLL_DDR Control Register ()
#define CCU_pll_ddr_ctrl_OFFSET 0x10
#define CCU_pll_ddr_ctrl_pll_en (0x1 << 31)
#define CCU_pll_ddr_ctrl_pll_en_SHIFT 31
#define CCU_pll_ddr_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_ddr_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_ddr_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_ddr_ctrl_lock_enable_SHIFT 29
#define CCU_pll_ddr_ctrl_lock (0x1 << 28)
#define CCU_pll_ddr_ctrl_lock_SHIFT 28
#define CCU_pll_ddr_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_ddr_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_ddr_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_ddr_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_ddr_ctrl_pll_n (0xff << 8)
#define CCU_pll_ddr_ctrl_pll_n_SHIFT 8
#define CCU_pll_ddr_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_ddr_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_ddr_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_ddr_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_ddr_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_ddr_ctrl_pll_input_div2_SHIFT 1
#define CCU_pll_ddr_ctrl_pll_output_div2 0x1
#define CCU_pll_ddr_ctrl_pll_output_div2_SHIFT 0
#define CCU_pll_peri_ctrl (CCU + 0x20) // PLL_PERI Control Register ()
#define CCU_pll_peri_ctrl_OFFSET 0x20
#define CCU_pll_peri_ctrl_pll_en (0x1 << 31)
#define CCU_pll_peri_ctrl_pll_en_SHIFT 31
#define CCU_pll_peri_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_peri_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_peri_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_peri_ctrl_lock_enable_SHIFT 29
#define CCU_pll_peri_ctrl_lock (0x1 << 28)
#define CCU_pll_peri_ctrl_lock_SHIFT 28
#define CCU_pll_peri_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_peri_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_peri_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_peri_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_peri_ctrl_pll_p1 (0x7 << 20)
#define CCU_pll_peri_ctrl_pll_p1_SHIFT 20
#define CCU_pll_peri_ctrl_pll_p0 (0x7 << 16)
#define CCU_pll_peri_ctrl_pll_p0_SHIFT 16
#define CCU_pll_peri_ctrl_pll_n (0xff << 8)
#define CCU_pll_peri_ctrl_pll_n_SHIFT 8
#define CCU_pll_peri_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_peri_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_peri_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_peri_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_peri_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_peri_ctrl_pll_input_div2_SHIFT 1
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
#define CCU_pll_video1_ctrl (CCU + 0x48) // PLL_VIDEO1 Control Register ()
#define CCU_pll_video1_ctrl_OFFSET 0x48
#define CCU_pll_video1_ctrl_pll_en (0x1 << 31)
#define CCU_pll_video1_ctrl_pll_en_SHIFT 31
#define CCU_pll_video1_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_video1_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_video1_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_video1_ctrl_lock_enable_SHIFT 29
#define CCU_pll_video1_ctrl_lock (0x1 << 28)
#define CCU_pll_video1_ctrl_lock_SHIFT 28
#define CCU_pll_video1_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_video1_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_video1_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_video1_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_video1_ctrl_pll_n (0xff << 8)
#define CCU_pll_video1_ctrl_pll_n_SHIFT 8
#define CCU_pll_video1_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_video1_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_video1_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_video1_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_video1_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_video1_ctrl_pll_input_div2_SHIFT 1
#define CCU_pll_video1_ctrl_pll_output_div2 0x1
#define CCU_pll_video1_ctrl_pll_output_div2_SHIFT 0
#define CCU_pll_ve_ctrl (CCU + 0x58) // PLL_VE Control Register ()
#define CCU_pll_ve_ctrl_OFFSET 0x58
#define CCU_pll_ve_ctrl_pll_en (0x1 << 31)
#define CCU_pll_ve_ctrl_pll_en_SHIFT 31
#define CCU_pll_ve_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_ve_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_ve_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_ve_ctrl_lock_enable_SHIFT 29
#define CCU_pll_ve_ctrl_lock (0x1 << 28)
#define CCU_pll_ve_ctrl_lock_SHIFT 28
#define CCU_pll_ve_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_ve_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_ve_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_ve_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_ve_ctrl_pll_n (0xff << 8)
#define CCU_pll_ve_ctrl_pll_n_SHIFT 8
#define CCU_pll_ve_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_ve_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_ve_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_ve_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_ve_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_ve_ctrl_pll_input_div2_SHIFT 1
#define CCU_pll_ve_ctrl_pll_output_div2 0x1
#define CCU_pll_ve_ctrl_pll_output_div2_SHIFT 0
#define CCU_pll_audio0_ctrl (CCU + 0x78) // PLL_AUDIO0 Control Register ()
#define CCU_pll_audio0_ctrl_OFFSET 0x78
#define CCU_pll_audio0_ctrl_pll_en (0x1 << 31)
#define CCU_pll_audio0_ctrl_pll_en_SHIFT 31
#define CCU_pll_audio0_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_audio0_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_audio0_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_audio0_ctrl_lock_enable_SHIFT 29
#define CCU_pll_audio0_ctrl_lock (0x1 << 28)
#define CCU_pll_audio0_ctrl_lock_SHIFT 28
#define CCU_pll_audio0_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_audio0_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_audio0_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_audio0_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_audio0_ctrl_pll_p (0x3f << 16)
#define CCU_pll_audio0_ctrl_pll_p_SHIFT 16
#define CCU_pll_audio0_ctrl_pll_n (0xff << 8)
#define CCU_pll_audio0_ctrl_pll_n_SHIFT 8
#define CCU_pll_audio0_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_audio0_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_audio0_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_audio0_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_audio0_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_audio0_ctrl_pll_input_div2_SHIFT 1
#define CCU_pll_audio0_ctrl_pll_output_div2 0x1
#define CCU_pll_audio0_ctrl_pll_output_div2_SHIFT 0
#define CCU_pll_audio1_ctrl (CCU + 0x80) // PLL_AUDIO1 Control Register ()
#define CCU_pll_audio1_ctrl_OFFSET 0x80
#define CCU_pll_audio1_ctrl_pll_en (0x1 << 31)
#define CCU_pll_audio1_ctrl_pll_en_SHIFT 31
#define CCU_pll_audio1_ctrl_pll_ldo_en (0x1 << 30)
#define CCU_pll_audio1_ctrl_pll_ldo_en_SHIFT 30
#define CCU_pll_audio1_ctrl_lock_enable (0x1 << 29)
#define CCU_pll_audio1_ctrl_lock_enable_SHIFT 29
#define CCU_pll_audio1_ctrl_lock (0x1 << 28)
#define CCU_pll_audio1_ctrl_lock_SHIFT 28
#define CCU_pll_audio1_ctrl_pll_output_gate (0x1 << 27)
#define CCU_pll_audio1_ctrl_pll_output_gate_SHIFT 27
#define CCU_pll_audio1_ctrl_pll_sdm_en (0x1 << 24)
#define CCU_pll_audio1_ctrl_pll_sdm_en_SHIFT 24
#define CCU_pll_audio1_ctrl_pll_p1 (0x7 << 20)
#define CCU_pll_audio1_ctrl_pll_p1_SHIFT 20
#define CCU_pll_audio1_ctrl_pll_p0 (0x7 << 16)
#define CCU_pll_audio1_ctrl_pll_p0_SHIFT 16
#define CCU_pll_audio1_ctrl_pll_n (0xff << 8)
#define CCU_pll_audio1_ctrl_pll_n_SHIFT 8
#define CCU_pll_audio1_ctrl_pll_unlock_mdsel (0x3 << 6)
#define CCU_pll_audio1_ctrl_pll_unlock_mdsel_SHIFT 6
#define CCU_pll_audio1_ctrl_pll_lock_mdsel (0x1 << 5)
#define CCU_pll_audio1_ctrl_pll_lock_mdsel_SHIFT 5
#define CCU_pll_audio1_ctrl_pll_input_div2 (0x1 << 1)
#define CCU_pll_audio1_ctrl_pll_input_div2_SHIFT 1
#define CCU_pll_ddr_pat0_ctrl (CCU + 0x110) // PLL_DDR Pattern0 Control Register ()
#define CCU_pll_ddr_pat0_ctrl_OFFSET 0x110
#define CCU_pll_ddr_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_ddr_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_ddr_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_ddr_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_ddr_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_ddr_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_ddr_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_ddr_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_ddr_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_ddr_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_ddr_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_ddr_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_ddr_pat1_ctrl (CCU + 0x114) // PLL_DDR Pattern1 Control Register ()
#define CCU_pll_ddr_pat1_ctrl_OFFSET 0x114
#define CCU_pll_ddr_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_ddr_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_ddr_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_ddr_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_ddr_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_ddr_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_peri_pat0_ctrl (CCU + 0x120) // PLL_PERI Pattern0 Control Register ()
#define CCU_pll_peri_pat0_ctrl_OFFSET 0x120
#define CCU_pll_peri_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_peri_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_peri_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_peri_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_peri_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_peri_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_peri_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_peri_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_peri_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_peri_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_peri_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_peri_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_peri_pat1_ctrl (CCU + 0x124) // PLL_PERI Pattern1 Control Register ()
#define CCU_pll_peri_pat1_ctrl_OFFSET 0x124
#define CCU_pll_peri_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_peri_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_peri_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_peri_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_peri_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_peri_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_video0_pat0_ctrl (CCU + 0x140) // PLL_VIDEO0 Pattern0 Control Register ()
#define CCU_pll_video0_pat0_ctrl_OFFSET 0x140
#define CCU_pll_video0_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_video0_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_video0_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_video0_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_video0_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_video0_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_video0_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_video0_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_video0_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_video0_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_video0_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_video0_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_video0_pat1_ctrl (CCU + 0x144) // PLL_VIDEO0 Pattern1 Control Register ()
#define CCU_pll_video0_pat1_ctrl_OFFSET 0x144
#define CCU_pll_video0_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_video0_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_video0_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_video0_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_video0_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_video0_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_video1_pat0_ctrl (CCU + 0x148) // PLL_VIDEO1 Pattern0 Control Register ()
#define CCU_pll_video1_pat0_ctrl_OFFSET 0x148
#define CCU_pll_video1_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_video1_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_video1_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_video1_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_video1_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_video1_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_video1_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_video1_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_video1_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_video1_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_video1_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_video1_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_video1_pat1_ctrl (CCU + 0x14c) // PLL_VIDEO1 Pattern1 Control Register ()
#define CCU_pll_video1_pat1_ctrl_OFFSET 0x14c
#define CCU_pll_video1_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_video1_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_video1_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_video1_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_video1_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_video1_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_ve_pat0_ctrl (CCU + 0x158) // PLL_VE Pattern0 Control Register ()
#define CCU_pll_ve_pat0_ctrl_OFFSET 0x158
#define CCU_pll_ve_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_ve_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_ve_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_ve_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_ve_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_ve_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_ve_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_ve_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_ve_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_ve_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_ve_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_ve_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_ve_pat1_ctrl (CCU + 0x15c) // PLL_VE Pattern1 Control Register ()
#define CCU_pll_ve_pat1_ctrl_OFFSET 0x15c
#define CCU_pll_ve_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_ve_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_ve_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_ve_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_ve_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_ve_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_audio0_pat0_ctrl (CCU + 0x178) // PLL_AUDIO0 Pattern0 Control Register ()
#define CCU_pll_audio0_pat0_ctrl_OFFSET 0x178
#define CCU_pll_audio0_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_audio0_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_audio0_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_audio0_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_audio0_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_audio0_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_audio0_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_audio0_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_audio0_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_audio0_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_audio0_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_audio0_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_audio0_pat1_ctrl (CCU + 0x17c) // PLL_AUDIO0 Pattern1 Control Register ()
#define CCU_pll_audio0_pat1_ctrl_OFFSET 0x17c
#define CCU_pll_audio0_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_audio0_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_audio0_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_audio0_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_audio0_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_audio0_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_audio1_pat0_ctrl (CCU + 0x180) // PLL_AUDIO1 Pattern0 Control Register ()
#define CCU_pll_audio1_pat0_ctrl_OFFSET 0x180
#define CCU_pll_audio1_pat0_ctrl_sig_delt_pat_en (0x1 << 31)
#define CCU_pll_audio1_pat0_ctrl_sig_delt_pat_en_SHIFT 31
#define CCU_pll_audio1_pat0_ctrl_spr_freq_mode (0x3 << 29)
#define CCU_pll_audio1_pat0_ctrl_spr_freq_mode_SHIFT 29
#define CCU_pll_audio1_pat0_ctrl_wave_step (0x1ff << 20)
#define CCU_pll_audio1_pat0_ctrl_wave_step_SHIFT 20
#define CCU_pll_audio1_pat0_ctrl_sdm_clk_sel (0x1 << 19)
#define CCU_pll_audio1_pat0_ctrl_sdm_clk_sel_SHIFT 19
#define CCU_pll_audio1_pat0_ctrl_freq (0x3 << 17)
#define CCU_pll_audio1_pat0_ctrl_freq_SHIFT 17
#define CCU_pll_audio1_pat0_ctrl_wave_bot 0x1ffff
#define CCU_pll_audio1_pat0_ctrl_wave_bot_SHIFT 0
#define CCU_pll_audio1_pat1_ctrl (CCU + 0x184) // PLL_AUDIO1 Pattern1 Control Register ()
#define CCU_pll_audio1_pat1_ctrl_OFFSET 0x184
#define CCU_pll_audio1_pat1_ctrl_dither_en (0x1 << 24)
#define CCU_pll_audio1_pat1_ctrl_dither_en_SHIFT 24
#define CCU_pll_audio1_pat1_ctrl_frac_en (0x1 << 20)
#define CCU_pll_audio1_pat1_ctrl_frac_en_SHIFT 20
#define CCU_pll_audio1_pat1_ctrl_frac_in 0x1ffff
#define CCU_pll_audio1_pat1_ctrl_frac_in_SHIFT 0
#define CCU_pll_cpu_bias (CCU + 0x300) // PLL_CPU Bias Register ()
#define CCU_pll_cpu_bias_OFFSET 0x300
#define CCU_pll_cpu_bias_pll_vco_rst_in (0x1 << 31)
#define CCU_pll_cpu_bias_pll_vco_rst_in_SHIFT 31
#define CCU_pll_cpu_bias_pll_cp (0x1f << 16)
#define CCU_pll_cpu_bias_pll_cp_SHIFT 16
#define CCU_pll_ddr_bias (CCU + 0x310) // PLL_DDR Bias Register ()
#define CCU_pll_ddr_bias_OFFSET 0x310
#define CCU_pll_ddr_bias_pll_cp (0x1f << 16)
#define CCU_pll_ddr_bias_pll_cp_SHIFT 16
#define CCU_pll_peri_bias (CCU + 0x320) // PLL_PERI Bias Register ()
#define CCU_pll_peri_bias_OFFSET 0x320
#define CCU_pll_peri_bias_pll_cp (0x1f << 16)
#define CCU_pll_peri_bias_pll_cp_SHIFT 16
#define CCU_pll_video0_bias (CCU + 0x340) // PLL_VIDEO0 Bias Register ()
#define CCU_pll_video0_bias_OFFSET 0x340
#define CCU_pll_video0_bias_pll_cp (0x1f << 16)
#define CCU_pll_video0_bias_pll_cp_SHIFT 16
#define CCU_pll_video1_bias (CCU + 0x348) // PLL_VIDEO1 Bias Register ()
#define CCU_pll_video1_bias_OFFSET 0x348
#define CCU_pll_video1_bias_pll_cp (0x1f << 16)
#define CCU_pll_video1_bias_pll_cp_SHIFT 16
#define CCU_pll_ve_bias (CCU + 0x358) // PLL_VE Bias Register ()
#define CCU_pll_ve_bias_OFFSET 0x358
#define CCU_pll_ve_bias_pll_cp (0x1f << 16)
#define CCU_pll_ve_bias_pll_cp_SHIFT 16
#define CCU_pll_audio0_bias (CCU + 0x378) // PLL_AUDIO0 Bias Register ()
#define CCU_pll_audio0_bias_OFFSET 0x378
#define CCU_pll_audio0_bias_pll_cp (0x1f << 16)
#define CCU_pll_audio0_bias_pll_cp_SHIFT 16
#define CCU_pll_audio1_bias (CCU + 0x380) // PLL_AUDIO1 Bias Register ()
#define CCU_pll_audio1_bias_OFFSET 0x380
#define CCU_pll_audio1_bias_pll_cp (0x1f << 16)
#define CCU_pll_audio1_bias_pll_cp_SHIFT 16
#define CCU_pll_cpu_tun (CCU + 0x400) // PLL_CPU Tuning Register ()
#define CCU_pll_cpu_tun_OFFSET 0x400
#define CCU_pll_cpu_tun_pll_vco (0x7 << 28)
#define CCU_pll_cpu_tun_pll_vco_SHIFT 28
#define CCU_pll_cpu_tun_pll_vco_gain (0x7 << 24)
#define CCU_pll_cpu_tun_pll_vco_gain_SHIFT 24
#define CCU_pll_cpu_tun_pll_cnt_int (0x7f << 16)
#define CCU_pll_cpu_tun_pll_cnt_int_SHIFT 16
#define CCU_pll_cpu_tun_pll_reg_od (0x1 << 15)
#define CCU_pll_cpu_tun_pll_reg_od_SHIFT 15
#define CCU_pll_cpu_tun_pll_b_in (0x7f << 8)
#define CCU_pll_cpu_tun_pll_b_in_SHIFT 8
#define CCU_pll_cpu_tun_pll_reg_od1 (0x1 << 7)
#define CCU_pll_cpu_tun_pll_reg_od1_SHIFT 7
#define CCU_pll_cpu_tun_pll_b_out 0x7f
#define CCU_pll_cpu_tun_pll_b_out_SHIFT 0
#define CCU_cpu_axi_cfg (CCU + 0x500) // CPU_AXI Configuration Register ()
#define CCU_cpu_axi_cfg_OFFSET 0x500
#define CCU_cpu_axi_cfg_cpu_clk_sel (0x7 << 24)
#define CCU_cpu_axi_cfg_cpu_clk_sel_SHIFT 24
#define CCU_cpu_axi_cfg_pll_cpu_out_ext_divp (0x3 << 16)
#define CCU_cpu_axi_cfg_pll_cpu_out_ext_divp_SHIFT 16
#define CCU_cpu_axi_cfg_cpu_div2 (0x3 << 8)
#define CCU_cpu_axi_cfg_cpu_div2_SHIFT 8
#define CCU_cpu_axi_cfg_cpu_div1 0x3
#define CCU_cpu_axi_cfg_cpu_div1_SHIFT 0
#define CCU_cpu_gating (CCU + 0x504) // CPU_GATING Configuration Register ()
#define CCU_cpu_gating_OFFSET 0x504
#define CCU_cpu_gating_cpu_gating (0x1 << 31)
#define CCU_cpu_gating_cpu_gating_SHIFT 31
#define CCU_cpu_gating_cpu_gating_field 0xffff
#define CCU_cpu_gating_cpu_gating_field_SHIFT 0
#define CCU_psi_clk (CCU + 0x510) // PSI Clock Register ()
#define CCU_psi_clk_OFFSET 0x510
#define CCU_psi_clk_clk_src_sel (0x3 << 24)
#define CCU_psi_clk_clk_src_sel_SHIFT 24
#define CCU_psi_clk_factor_n (0x3 << 8)
#define CCU_psi_clk_factor_n_SHIFT 8
#define CCU_psi_clk_factor_m 0x3
#define CCU_psi_clk_factor_m_SHIFT 0
#define CCU_apb0_clk (CCU + 0x520) // APB Clock Register ()
#define CCU_apb0_clk_OFFSET 0x520
#define CCU_apb0_clk_clk_src_sel (0x3 << 24)
#define CCU_apb0_clk_clk_src_sel_SHIFT 24
#define CCU_apb0_clk_factor_n (0x3 << 8)
#define CCU_apb0_clk_factor_n_SHIFT 8
#define CCU_apb0_clk_factor_m 0x1f
#define CCU_apb0_clk_factor_m_SHIFT 0
#define CCU_mbus_clk (CCU + 0x540) // MBUS Clock Register ()
#define CCU_mbus_clk_OFFSET 0x540
#define CCU_mbus_clk_mbus_rst (0x1 << 30)
#define CCU_mbus_clk_mbus_rst_SHIFT 30
#define CCU_de_clk (CCU + 0x600) // DE Clock Register ()
#define CCU_de_clk_OFFSET 0x600
#define CCU_de_clk_clk_gating (0x1 << 31)
#define CCU_de_clk_clk_gating_SHIFT 31
#define CCU_de_clk_clk_src_sel (0x7 << 24)
#define CCU_de_clk_clk_src_sel_SHIFT 24
#define CCU_de_clk_factor_m 0x1f
#define CCU_de_clk_factor_m_SHIFT 0
#define CCU_de_bgr (CCU + 0x60c) // DE Bus Gating Reset Register ()
#define CCU_de_bgr_OFFSET 0x60c
#define CCU_de_bgr_rst (0x1 << 16)
#define CCU_de_bgr_rst_SHIFT 16
#define CCU_de_bgr_gating 0x1
#define CCU_de_bgr_gating_SHIFT 0
#define CCU_di_clk (CCU + 0x620) // DI Clock Register ()
#define CCU_di_clk_OFFSET 0x620
#define CCU_di_clk_clk_gating (0x1 << 31)
#define CCU_di_clk_clk_gating_SHIFT 31
#define CCU_di_clk_clk_src_sel (0x7 << 24)
#define CCU_di_clk_clk_src_sel_SHIFT 24
#define CCU_di_clk_factor_m 0x1f
#define CCU_di_clk_factor_m_SHIFT 0
#define CCU_di_bgr (CCU + 0x62c) // DI Bus Gating Reset Register ()
#define CCU_di_bgr_OFFSET 0x62c
#define CCU_di_bgr_rst (0x1 << 16)
#define CCU_di_bgr_rst_SHIFT 16
#define CCU_di_bgr_gating 0x1
#define CCU_di_bgr_gating_SHIFT 0
#define CCU_g2d_clk (CCU + 0x630) // G2D Clock Register ()
#define CCU_g2d_clk_OFFSET 0x630
#define CCU_g2d_clk_clk_gating (0x1 << 31)
#define CCU_g2d_clk_clk_gating_SHIFT 31
#define CCU_g2d_clk_clk_src_sel (0x7 << 24)
#define CCU_g2d_clk_clk_src_sel_SHIFT 24
#define CCU_g2d_clk_factor_m 0x1f
#define CCU_g2d_clk_factor_m_SHIFT 0
#define CCU_g2d_bgr (CCU + 0x63c) // G2D Bus Gating Reset Register ()
#define CCU_g2d_bgr_OFFSET 0x63c
#define CCU_g2d_bgr_rst (0x1 << 16)
#define CCU_g2d_bgr_rst_SHIFT 16
#define CCU_g2d_bgr_gating 0x1
#define CCU_g2d_bgr_gating_SHIFT 0
#define CCU_ce_clk (CCU + 0x680) // CE Clock Register ()
#define CCU_ce_clk_OFFSET 0x680
#define CCU_ce_clk_clk_gating (0x1 << 31)
#define CCU_ce_clk_clk_gating_SHIFT 31
#define CCU_ce_clk_clk_src_sel (0x7 << 24)
#define CCU_ce_clk_clk_src_sel_SHIFT 24
#define CCU_ce_clk_factor_n (0x3 << 8)
#define CCU_ce_clk_factor_n_SHIFT 8
#define CCU_ce_clk_factor_m 0xf
#define CCU_ce_clk_factor_m_SHIFT 0
#define CCU_ce_bgr (CCU + 0x68c) // CE Bus Gating Reset Register ()
#define CCU_ce_bgr_OFFSET 0x68c
#define CCU_ce_bgr_rst (0x1 << 16)
#define CCU_ce_bgr_rst_SHIFT 16
#define CCU_ce_bgr_gating 0x1
#define CCU_ce_bgr_gating_SHIFT 0
#define CCU_ve_clk (CCU + 0x690) // VE Clock Register ()
#define CCU_ve_clk_OFFSET 0x690
#define CCU_ve_clk_clk_gating (0x1 << 31)
#define CCU_ve_clk_clk_gating_SHIFT 31
#define CCU_ve_clk_clk_src_sel (0x1 << 24)
#define CCU_ve_clk_clk_src_sel_SHIFT 24
#define CCU_ve_clk_factor_m 0x1f
#define CCU_ve_clk_factor_m_SHIFT 0
#define CCU_ve_bgr (CCU + 0x69c) // VE Bus Gating Reset Register ()
#define CCU_ve_bgr_OFFSET 0x69c
#define CCU_ve_bgr_rst (0x1 << 16)
#define CCU_ve_bgr_rst_SHIFT 16
#define CCU_ve_bgr_gating 0x1
#define CCU_ve_bgr_gating_SHIFT 0
#define CCU_dma_bgr (CCU + 0x70c) // DMA Bus Gating Reset Register ()
#define CCU_dma_bgr_OFFSET 0x70c
#define CCU_dma_bgr_rst (0x1 << 16)
#define CCU_dma_bgr_rst_SHIFT 16
#define CCU_dma_bgr_gating 0x1
#define CCU_dma_bgr_gating_SHIFT 0
#define CCU_msgbox_bgr (CCU + 0x71c) // MSGBOX Bus Gating Reset Register ()
#define CCU_msgbox_bgr_OFFSET 0x71c
#define CCU_msgbox_bgr_msgbox0_rst (0x1 << 16)
#define CCU_msgbox_bgr_msgbox0_rst_SHIFT 16
#define CCU_msgbox_bgr_msgbox0_gating 0x1
#define CCU_msgbox_bgr_msgbox0_gating_SHIFT 0
#define CCU_spinlock_bgr (CCU + 0x72c) // SPINLOCK Bus Gating Reset Register ()
#define CCU_spinlock_bgr_OFFSET 0x72c
#define CCU_spinlock_bgr_rst (0x1 << 16)
#define CCU_spinlock_bgr_rst_SHIFT 16
#define CCU_spinlock_bgr_gating 0x1
#define CCU_spinlock_bgr_gating_SHIFT 0
#define CCU_hstimer_bgr (CCU + 0x73c) // HSTIMER Bus Gating Reset Register ()
#define CCU_hstimer_bgr_OFFSET 0x73c
#define CCU_hstimer_bgr_rst (0x1 << 16)
#define CCU_hstimer_bgr_rst_SHIFT 16
#define CCU_hstimer_bgr_gating 0x1
#define CCU_hstimer_bgr_gating_SHIFT 0
#define CCU_avs_clk (CCU + 0x740) // AVS Clock Register ()
#define CCU_avs_clk_OFFSET 0x740
#define CCU_avs_clk_clk_gating (0x1 << 31)
#define CCU_avs_clk_clk_gating_SHIFT 31
#define CCU_dbgsys_bgr (CCU + 0x78c) // DBGSYS Bus Gating Reset Register ()
#define CCU_dbgsys_bgr_OFFSET 0x78c
#define CCU_dbgsys_bgr_rst (0x1 << 16)
#define CCU_dbgsys_bgr_rst_SHIFT 16
#define CCU_dbgsys_bgr_gating 0x1
#define CCU_dbgsys_bgr_gating_SHIFT 0
#define CCU_pwm_bgr (CCU + 0x7ac) // PWM Bus Gating Reset Register ()
#define CCU_pwm_bgr_OFFSET 0x7ac
#define CCU_pwm_bgr_rst (0x1 << 16)
#define CCU_pwm_bgr_rst_SHIFT 16
#define CCU_pwm_bgr_gating 0x1
#define CCU_pwm_bgr_gating_SHIFT 0
#define CCU_iommu_bgr (CCU + 0x7bc) // IOMMU Bus Gating Reset Register ()
#define CCU_iommu_bgr_OFFSET 0x7bc
#define CCU_iommu_bgr_gating 0x1
#define CCU_iommu_bgr_gating_SHIFT 0
#define CCU_dram_clk (CCU + 0x800) // DRAM Clock Register ()
#define CCU_dram_clk_OFFSET 0x800
#define CCU_dram_clk_clk_gating (0x1 << 31)
#define CCU_dram_clk_clk_gating_SHIFT 31
#define CCU_dram_clk_sdrclk_upd (0x1 << 27)
#define CCU_dram_clk_sdrclk_upd_SHIFT 27
#define CCU_dram_clk_clk_src_sel (0x7 << 24)
#define CCU_dram_clk_clk_src_sel_SHIFT 24
#define CCU_dram_clk_dram_div2 (0x3 << 8)
#define CCU_dram_clk_dram_div2_SHIFT 8
#define CCU_dram_clk_dram_div1 0x3
#define CCU_dram_clk_dram_div1_SHIFT 0
#define CCU_mbus_mat_clk_gating (CCU + 0x804) // MBUS Master Clock Gating Register ()
#define CCU_mbus_mat_clk_gating_OFFSET 0x804
#define CCU_mbus_mat_clk_gating_riscv_mclk_en (0x1 << 11)
#define CCU_mbus_mat_clk_gating_riscv_mclk_en_SHIFT 11
#define CCU_mbus_mat_clk_gating_g2d_mclk_en (0x1 << 10)
#define CCU_mbus_mat_clk_gating_g2d_mclk_en_SHIFT 10
#define CCU_mbus_mat_clk_gating_csi_mclk_en (0x1 << 8)
#define CCU_mbus_mat_clk_gating_csi_mclk_en_SHIFT 8
#define CCU_mbus_mat_clk_gating_tvin_mclk_en (0x1 << 7)
#define CCU_mbus_mat_clk_gating_tvin_mclk_en_SHIFT 7
#define CCU_mbus_mat_clk_gating_ce_mclk_en (0x1 << 2)
#define CCU_mbus_mat_clk_gating_ce_mclk_en_SHIFT 2
#define CCU_mbus_mat_clk_gating_ve_mclk_en (0x1 << 1)
#define CCU_mbus_mat_clk_gating_ve_mclk_en_SHIFT 1
#define CCU_mbus_mat_clk_gating_dma_mclk_en 0x1
#define CCU_mbus_mat_clk_gating_dma_mclk_en_SHIFT 0
#define CCU_dram_bgr (CCU + 0x80c) // DRAM Bus Gating Reset Register ()
#define CCU_dram_bgr_OFFSET 0x80c
#define CCU_dram_bgr_rst (0x1 << 16)
#define CCU_dram_bgr_rst_SHIFT 16
#define CCU_dram_bgr_gating 0x1
#define CCU_dram_bgr_gating_SHIFT 0
#define CCU_smhc0_clk (CCU + 0x830) // SMHC0 Clock Register ()
#define CCU_smhc0_clk_OFFSET 0x830
#define CCU_smhc0_clk_clk_gating (0x1 << 31)
#define CCU_smhc0_clk_clk_gating_SHIFT 31
#define CCU_smhc0_clk_clk_src_sel (0x7 << 24)
#define CCU_smhc0_clk_clk_src_sel_SHIFT 24
#define CCU_smhc0_clk_factor_n (0x3 << 8)
#define CCU_smhc0_clk_factor_n_SHIFT 8
#define CCU_smhc0_clk_factor_m 0xf
#define CCU_smhc0_clk_factor_m_SHIFT 0
#define CCU_smhc1_clk (CCU + 0x834) // SMHC1 Clock Register ()
#define CCU_smhc1_clk_OFFSET 0x834
#define CCU_smhc1_clk_clk_gating (0x1 << 31)
#define CCU_smhc1_clk_clk_gating_SHIFT 31
#define CCU_smhc1_clk_clk_src_sel (0x7 << 24)
#define CCU_smhc1_clk_clk_src_sel_SHIFT 24
#define CCU_smhc1_clk_factor_n (0x3 << 8)
#define CCU_smhc1_clk_factor_n_SHIFT 8
#define CCU_smhc1_clk_factor_m 0xf
#define CCU_smhc1_clk_factor_m_SHIFT 0
#define CCU_smhc2_clk (CCU + 0x838) // SMHC2 Clock Register ()
#define CCU_smhc2_clk_OFFSET 0x838
#define CCU_smhc2_clk_clk_gating (0x1 << 31)
#define CCU_smhc2_clk_clk_gating_SHIFT 31
#define CCU_smhc2_clk_clk_src_sel (0x7 << 24)
#define CCU_smhc2_clk_clk_src_sel_SHIFT 24
#define CCU_smhc2_clk_factor_n (0x3 << 8)
#define CCU_smhc2_clk_factor_n_SHIFT 8
#define CCU_smhc2_clk_factor_m 0xf
#define CCU_smhc2_clk_factor_m_SHIFT 0
#define CCU_smhc_bgr (CCU + 0x84c) // SMHC Bus Gating Reset Register ()
#define CCU_smhc_bgr_OFFSET 0x84c
#define CCU_smhc_bgr_smhc0_rst (0x1 << 16)
#define CCU_smhc_bgr_smhc0_rst_SHIFT 16
#define CCU_smhc_bgr_smhc0_gating 0x1
#define CCU_smhc_bgr_smhc0_gating_SHIFT 0
#define CCU_uart_bgr (CCU + 0x90c) // UART Bus Gating Reset Register ()
#define CCU_uart_bgr_OFFSET 0x90c
#define CCU_uart_bgr_uart0_rst (0x1 << 16)
#define CCU_uart_bgr_uart0_rst_SHIFT 16
#define CCU_uart_bgr_uart0_gating 0x1
#define CCU_uart_bgr_uart0_gating_SHIFT 0
#define CCU_twi_bgr (CCU + 0x91c) // TWI Bus Gating Reset Register ()
#define CCU_twi_bgr_OFFSET 0x91c
#define CCU_twi_bgr_twi0_rst (0x1 << 16)
#define CCU_twi_bgr_twi0_rst_SHIFT 16
#define CCU_twi_bgr_twi0_gating 0x1
#define CCU_twi_bgr_twi0_gating_SHIFT 0
#define CCU_spi0_clk (CCU + 0x940) // SPI0 Clock Register ()
#define CCU_spi0_clk_OFFSET 0x940
#define CCU_spi0_clk_clk_gating (0x1 << 31)
#define CCU_spi0_clk_clk_gating_SHIFT 31
#define CCU_spi0_clk_clk_src_sel (0x7 << 24)
#define CCU_spi0_clk_clk_src_sel_SHIFT 24
#define CCU_spi0_clk_factor_n (0x3 << 8)
#define CCU_spi0_clk_factor_n_SHIFT 8
#define CCU_spi0_clk_factor_m 0xf
#define CCU_spi0_clk_factor_m_SHIFT 0
#define CCU_spi1_clk (CCU + 0x944) // SPI1 Clock Register ()
#define CCU_spi1_clk_OFFSET 0x944
#define CCU_spi1_clk_clk_gating (0x1 << 31)
#define CCU_spi1_clk_clk_gating_SHIFT 31
#define CCU_spi1_clk_clk_src_sel (0x7 << 24)
#define CCU_spi1_clk_clk_src_sel_SHIFT 24
#define CCU_spi1_clk_factor_n (0x3 << 8)
#define CCU_spi1_clk_factor_n_SHIFT 8
#define CCU_spi1_clk_factor_m 0xf
#define CCU_spi1_clk_factor_m_SHIFT 0
#define CCU_spi_bgr (CCU + 0x96c) // SPI Bus Gating Reset Register ()
#define CCU_spi_bgr_OFFSET 0x96c
#define CCU_spi_bgr_spi0_rst (0x1 << 16)
#define CCU_spi_bgr_spi0_rst_SHIFT 16
#define CCU_spi_bgr_spi0_gating 0x1
#define CCU_spi_bgr_spi0_gating_SHIFT 0
#define CCU_emac_25m_clk (CCU + 0x970) // EMAC_25M Clock Register ()
#define CCU_emac_25m_clk_OFFSET 0x970
#define CCU_emac_25m_clk_clk_gating (0x1 << 31)
#define CCU_emac_25m_clk_clk_gating_SHIFT 31
#define CCU_emac_25m_clk_clk_src_gating (0x1 << 31)
#define CCU_emac_25m_clk_clk_src_gating_SHIFT 31
#define CCU_emac_bgr (CCU + 0x97c) // EMAC Bus Gating Reset Register ()
#define CCU_emac_bgr_OFFSET 0x97c
#define CCU_emac_bgr_rst (0x1 << 16)
#define CCU_emac_bgr_rst_SHIFT 16
#define CCU_emac_bgr_gating 0x1
#define CCU_emac_bgr_gating_SHIFT 0
#define CCU_irtx_clk (CCU + 0x9c0) // IRTX Clock Register ()
#define CCU_irtx_clk_OFFSET 0x9c0
#define CCU_irtx_clk_clk_gating (0x1 << 31)
#define CCU_irtx_clk_clk_gating_SHIFT 31
#define CCU_irtx_clk_clk_src_sel (0x7 << 24)
#define CCU_irtx_clk_clk_src_sel_SHIFT 24
#define CCU_irtx_clk_factor_n (0x3 << 8)
#define CCU_irtx_clk_factor_n_SHIFT 8
#define CCU_irtx_clk_factor_m 0xf
#define CCU_irtx_clk_factor_m_SHIFT 0
#define CCU_irtx_bgr (CCU + 0x9cc) // IRTX Bus Gating Reset Register ()
#define CCU_irtx_bgr_OFFSET 0x9cc
#define CCU_irtx_bgr_rst (0x1 << 16)
#define CCU_irtx_bgr_rst_SHIFT 16
#define CCU_irtx_bgr_gating 0x1
#define CCU_irtx_bgr_gating_SHIFT 0
#define CCU_gpadc_bgr (CCU + 0x9ec) // GPADC Bus Gating Reset Register ()
#define CCU_gpadc_bgr_OFFSET 0x9ec
#define CCU_gpadc_bgr_rst (0x1 << 16)
#define CCU_gpadc_bgr_rst_SHIFT 16
#define CCU_gpadc_bgr_gating 0x1
#define CCU_gpadc_bgr_gating_SHIFT 0
#define CCU_ths_bgr (CCU + 0x9fc) // THS Bus Gating Reset Register ()
#define CCU_ths_bgr_OFFSET 0x9fc
#define CCU_ths_bgr_rst (0x1 << 16)
#define CCU_ths_bgr_rst_SHIFT 16
#define CCU_ths_bgr_gating 0x1
#define CCU_ths_bgr_gating_SHIFT 0
#define CCU_i2s0_clk (CCU + 0xa10) // I2S Clock Register ()
#define CCU_i2s0_clk_OFFSET 0xa10
#define CCU_i2s0_clk_clk_gating (0x1 << 31)
#define CCU_i2s0_clk_clk_gating_SHIFT 31
#define CCU_i2s0_clk_clk_src_sel (0x7 << 24)
#define CCU_i2s0_clk_clk_src_sel_SHIFT 24
#define CCU_i2s0_clk_factor_n (0x3 << 8)
#define CCU_i2s0_clk_factor_n_SHIFT 8
#define CCU_i2s0_clk_factor_m 0x1f
#define CCU_i2s0_clk_factor_m_SHIFT 0
#define CCU_i2s2_asrc_clk (CCU + 0xa1c) // I2S2_ASRC Clock Register ()
#define CCU_i2s2_asrc_clk_OFFSET 0xa1c
#define CCU_i2s2_asrc_clk_clk_gating (0x1 << 31)
#define CCU_i2s2_asrc_clk_clk_gating_SHIFT 31
#define CCU_i2s2_asrc_clk_clk_src_sel (0x7 << 24)
#define CCU_i2s2_asrc_clk_clk_src_sel_SHIFT 24
#define CCU_i2s2_asrc_clk_factor_n (0x3 << 8)
#define CCU_i2s2_asrc_clk_factor_n_SHIFT 8
#define CCU_i2s2_asrc_clk_factor_m 0x1f
#define CCU_i2s2_asrc_clk_factor_m_SHIFT 0
#define CCU_i2s_bgr (CCU + 0xa20) // I2S Bus Gating Reset Register ()
#define CCU_i2s_bgr_OFFSET 0xa20
#define CCU_i2s_bgr_i2s0_rst (0x1 << 16)
#define CCU_i2s_bgr_i2s0_rst_SHIFT 16
#define CCU_i2s_bgr_i2s0_gating 0x1
#define CCU_i2s_bgr_i2s0_gating_SHIFT 0
#define CCU_owa_tx_clk (CCU + 0xa24) // OWA_TX Clock Register ()
#define CCU_owa_tx_clk_OFFSET 0xa24
#define CCU_owa_tx_clk_clk_gating (0x1 << 31)
#define CCU_owa_tx_clk_clk_gating_SHIFT 31
#define CCU_owa_tx_clk_clk_src_sel (0x7 << 24)
#define CCU_owa_tx_clk_clk_src_sel_SHIFT 24
#define CCU_owa_tx_clk_factor_n (0x3 << 8)
#define CCU_owa_tx_clk_factor_n_SHIFT 8
#define CCU_owa_tx_clk_factor_m 0x1f
#define CCU_owa_tx_clk_factor_m_SHIFT 0
#define CCU_owa_rx_clk (CCU + 0xa28) // OWA_RX Clock Register ()
#define CCU_owa_rx_clk_OFFSET 0xa28
#define CCU_owa_rx_clk_clk_gating (0x1 << 31)
#define CCU_owa_rx_clk_clk_gating_SHIFT 31
#define CCU_owa_rx_clk_clk_src_sel (0x7 << 24)
#define CCU_owa_rx_clk_clk_src_sel_SHIFT 24
#define CCU_owa_rx_clk_factor_n (0x3 << 8)
#define CCU_owa_rx_clk_factor_n_SHIFT 8
#define CCU_owa_rx_clk_factor_m 0x1f
#define CCU_owa_rx_clk_factor_m_SHIFT 0
#define CCU_owa_bgr (CCU + 0xa2c) // OWA Bus Gating Reset Register ()
#define CCU_owa_bgr_OFFSET 0xa2c
#define CCU_owa_bgr_rst (0x1 << 16)
#define CCU_owa_bgr_rst_SHIFT 16
#define CCU_owa_bgr_gating 0x1
#define CCU_owa_bgr_gating_SHIFT 0
#define CCU_dmic_clk (CCU + 0xa40) // DMIC Clock Register ()
#define CCU_dmic_clk_OFFSET 0xa40
#define CCU_dmic_clk_clk_gating (0x1 << 31)
#define CCU_dmic_clk_clk_gating_SHIFT 31
#define CCU_dmic_clk_clk_src_sel (0x7 << 24)
#define CCU_dmic_clk_clk_src_sel_SHIFT 24
#define CCU_dmic_clk_factor_n (0x3 << 8)
#define CCU_dmic_clk_factor_n_SHIFT 8
#define CCU_dmic_clk_factor_m 0x1f
#define CCU_dmic_clk_factor_m_SHIFT 0
#define CCU_dmic_bgr (CCU + 0xa4c) // DMIC Bus Gating Reset Register ()
#define CCU_dmic_bgr_OFFSET 0xa4c
#define CCU_dmic_bgr_rst (0x1 << 16)
#define CCU_dmic_bgr_rst_SHIFT 16
#define CCU_dmic_bgr_gating 0x1
#define CCU_dmic_bgr_gating_SHIFT 0
#define CCU_audio_codec_dac_clk (CCU + 0xa50) // AUDIO_CODEC_DAC Clock Register ()
#define CCU_audio_codec_dac_clk_OFFSET 0xa50
#define CCU_audio_codec_dac_clk_clk_gating (0x1 << 31)
#define CCU_audio_codec_dac_clk_clk_gating_SHIFT 31
#define CCU_audio_codec_dac_clk_clk_src_sel (0x7 << 24)
#define CCU_audio_codec_dac_clk_clk_src_sel_SHIFT 24
#define CCU_audio_codec_dac_clk_factor_n (0x3 << 8)
#define CCU_audio_codec_dac_clk_factor_n_SHIFT 8
#define CCU_audio_codec_dac_clk_factor_m 0x1f
#define CCU_audio_codec_dac_clk_factor_m_SHIFT 0
#define CCU_audio_codec_adc_clk (CCU + 0xa54) // AUDIO_CODEC_ADC Clock Register ()
#define CCU_audio_codec_adc_clk_OFFSET 0xa54
#define CCU_audio_codec_adc_clk_clk_gating (0x1 << 31)
#define CCU_audio_codec_adc_clk_clk_gating_SHIFT 31
#define CCU_audio_codec_adc_clk_clk_src_sel (0x7 << 24)
#define CCU_audio_codec_adc_clk_clk_src_sel_SHIFT 24
#define CCU_audio_codec_adc_clk_factor_n (0x3 << 8)
#define CCU_audio_codec_adc_clk_factor_n_SHIFT 8
#define CCU_audio_codec_adc_clk_factor_m 0x1f
#define CCU_audio_codec_adc_clk_factor_m_SHIFT 0
#define CCU_audio_codec_bgr (CCU + 0xa5c) // AUDIO_CODEC Bus Gating Reset Register ()
#define CCU_audio_codec_bgr_OFFSET 0xa5c
#define CCU_audio_codec_bgr_rst (0x1 << 16)
#define CCU_audio_codec_bgr_rst_SHIFT 16
#define CCU_audio_codec_bgr_gating 0x1
#define CCU_audio_codec_bgr_gating_SHIFT 0
#define CCU_usb0_clk (CCU + 0xa70) // USB0 Clock Register ()
#define CCU_usb0_clk_OFFSET 0xa70
#define CCU_usb0_clk_clken (0x1 << 31)
#define CCU_usb0_clk_clken_SHIFT 31
#define CCU_usb0_clk_rstn (0x1 << 30)
#define CCU_usb0_clk_rstn_SHIFT 30
#define CCU_usb0_clk_clk12m_sel (0x3 << 24)
#define CCU_usb0_clk_clk12m_sel_SHIFT 24
#define CCU_usb1_clk (CCU + 0xa74) // USB1 Clock Register ()
#define CCU_usb1_clk_OFFSET 0xa74
#define CCU_usb1_clk_clken (0x1 << 31)
#define CCU_usb1_clk_clken_SHIFT 31
#define CCU_usb1_clk_rstn (0x1 << 30)
#define CCU_usb1_clk_rstn_SHIFT 30
#define CCU_usb1_clk_clk12m_sel (0x3 << 24)
#define CCU_usb1_clk_clk12m_sel_SHIFT 24
#define CCU_usb_bgr (CCU + 0xa8c) // USB Bus Gating Reset Register ()
#define CCU_usb_bgr_OFFSET 0xa8c
#define CCU_usb_bgr_usbotg0_rst (0x1 << 24)
#define CCU_usb_bgr_usbotg0_rst_SHIFT 24
#define CCU_usb_bgr_usbehci0_rst (0x1 << 20)
#define CCU_usb_bgr_usbehci0_rst_SHIFT 20
#define CCU_usb_bgr_usbohci0_rst (0x1 << 16)
#define CCU_usb_bgr_usbohci0_rst_SHIFT 16
#define CCU_usb_bgr_usbotg0_gating (0x1 << 8)
#define CCU_usb_bgr_usbotg0_gating_SHIFT 8
#define CCU_usb_bgr_usbehci0_gating (0x1 << 4)
#define CCU_usb_bgr_usbehci0_gating_SHIFT 4
#define CCU_usb_bgr_usbohci0_gating 0x1
#define CCU_usb_bgr_usbohci0_gating_SHIFT 0
#define CCU_lradc_bgr (CCU + 0xa9c) // LRADC Bus Gating Reset Register ()
#define CCU_lradc_bgr_OFFSET 0xa9c
#define CCU_lradc_bgr_rst (0x1 << 16)
#define CCU_lradc_bgr_rst_SHIFT 16
#define CCU_lradc_bgr_gating 0x1
#define CCU_lradc_bgr_gating_SHIFT 0
#define CCU_dpss_top_bgr (CCU + 0xabc) // DPSS_TOP Bus Gating Reset Register ()
#define CCU_dpss_top_bgr_OFFSET 0xabc
#define CCU_dpss_top_bgr_rst (0x1 << 16)
#define CCU_dpss_top_bgr_rst_SHIFT 16
#define CCU_dpss_top_bgr_gating 0x1
#define CCU_dpss_top_bgr_gating_SHIFT 0
#define CCU_dsi_clk (CCU + 0xb24) // DSI Clock Register ()
#define CCU_dsi_clk_OFFSET 0xb24
#define CCU_dsi_clk_clk_gating (0x1 << 31)
#define CCU_dsi_clk_clk_gating_SHIFT 31
#define CCU_dsi_clk_clk_src_sel (0x7 << 24)
#define CCU_dsi_clk_clk_src_sel_SHIFT 24
#define CCU_dsi_clk_factor_m 0xf
#define CCU_dsi_clk_factor_m_SHIFT 0
#define CCU_dsi_bgr (CCU + 0xb4c) // DSI Bus Gating Reset Register ()
#define CCU_dsi_bgr_OFFSET 0xb4c
#define CCU_dsi_bgr_rst (0x1 << 16)
#define CCU_dsi_bgr_rst_SHIFT 16
#define CCU_dsi_bgr_gating 0x1
#define CCU_dsi_bgr_gating_SHIFT 0
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
#define CCU_tconlcd_bgr (CCU + 0xb7c) // TCONLCD Bus Gating Reset Register ()
#define CCU_tconlcd_bgr_OFFSET 0xb7c
#define CCU_tconlcd_bgr_rst (0x1 << 16)
#define CCU_tconlcd_bgr_rst_SHIFT 16
#define CCU_tconlcd_bgr_gating 0x1
#define CCU_tconlcd_bgr_gating_SHIFT 0
#define CCU_tcontv_clk (CCU + 0xb80) // TCONTV Clock Register ()
#define CCU_tcontv_clk_OFFSET 0xb80
#define CCU_tcontv_clk_clk_gating (0x1 << 31)
#define CCU_tcontv_clk_clk_gating_SHIFT 31
#define CCU_tcontv_clk_clk_src_sel (0x7 << 24)
#define CCU_tcontv_clk_clk_src_sel_SHIFT 24
#define CCU_tcontv_clk_factor_n (0x3 << 8)
#define CCU_tcontv_clk_factor_n_SHIFT 8
#define CCU_tcontv_clk_factor_m 0xf
#define CCU_tcontv_clk_factor_m_SHIFT 0
#define CCU_tcontv_bgr (CCU + 0xb9c) // TCONTV Bus Gating Reset Register ()
#define CCU_tcontv_bgr_OFFSET 0xb9c
#define CCU_tcontv_bgr_rst (0x1 << 16)
#define CCU_tcontv_bgr_rst_SHIFT 16
#define CCU_tcontv_bgr_gating 0x1
#define CCU_tcontv_bgr_gating_SHIFT 0
#define CCU_lvds_bgr (CCU + 0xbac) // LVDS Bus Gating Reset Register ()
#define CCU_lvds_bgr_OFFSET 0xbac
#define CCU_lvds_bgr_rst (0x1 << 16)
#define CCU_lvds_bgr_rst_SHIFT 16
#define CCU_tve_clk (CCU + 0xbb0) // TVE Clock Register ()
#define CCU_tve_clk_OFFSET 0xbb0
#define CCU_tve_clk_clk_gating (0x1 << 31)
#define CCU_tve_clk_clk_gating_SHIFT 31
#define CCU_tve_clk_clk_src_sel (0x7 << 24)
#define CCU_tve_clk_clk_src_sel_SHIFT 24
#define CCU_tve_clk_factor_n (0x3 << 8)
#define CCU_tve_clk_factor_n_SHIFT 8
#define CCU_tve_clk_factor_m 0xf
#define CCU_tve_clk_factor_m_SHIFT 0
#define CCU_tve_bgr (CCU + 0xbbc) // TVE Bus Gating Reset Register ()
#define CCU_tve_bgr_OFFSET 0xbbc
#define CCU_tve_bgr_rst (0x1 << 17)
#define CCU_tve_bgr_rst_SHIFT 17
#define CCU_tve_bgr_top_rst (0x1 << 16)
#define CCU_tve_bgr_top_rst_SHIFT 16
#define CCU_tve_bgr_gating (0x1 << 1)
#define CCU_tve_bgr_gating_SHIFT 1
#define CCU_tve_bgr_top_gating 0x1
#define CCU_tve_bgr_top_gating_SHIFT 0
#define CCU_tvd_clk (CCU + 0xbc0) // TVD Clock Register ()
#define CCU_tvd_clk_OFFSET 0xbc0
#define CCU_tvd_clk_clk_gating (0x1 << 31)
#define CCU_tvd_clk_clk_gating_SHIFT 31
#define CCU_tvd_clk_clk_src_sel (0x7 << 24)
#define CCU_tvd_clk_clk_src_sel_SHIFT 24
#define CCU_tvd_clk_factor_m 0x1f
#define CCU_tvd_clk_factor_m_SHIFT 0
#define CCU_tvd_bgr (CCU + 0xbdc) // TVD Bus Gating Reset Register ()
#define CCU_tvd_bgr_OFFSET 0xbdc
#define CCU_tvd_bgr_rst (0x1 << 17)
#define CCU_tvd_bgr_rst_SHIFT 17
#define CCU_tvd_bgr_top_rst (0x1 << 16)
#define CCU_tvd_bgr_top_rst_SHIFT 16
#define CCU_tvd_bgr_gating (0x1 << 1)
#define CCU_tvd_bgr_gating_SHIFT 1
#define CCU_tvd_bgr_top_gating 0x1
#define CCU_tvd_bgr_top_gating_SHIFT 0
#define CCU_ledc_clk (CCU + 0xbf0) // LEDC Clock Register ()
#define CCU_ledc_clk_OFFSET 0xbf0
#define CCU_ledc_clk_clk_gating (0x1 << 31)
#define CCU_ledc_clk_clk_gating_SHIFT 31
#define CCU_ledc_clk_clk_src_sel (0x7 << 24)
#define CCU_ledc_clk_clk_src_sel_SHIFT 24
#define CCU_ledc_clk_factor_n (0x3 << 8)
#define CCU_ledc_clk_factor_n_SHIFT 8
#define CCU_ledc_clk_factor_m 0xf
#define CCU_ledc_clk_factor_m_SHIFT 0
#define CCU_ledc_bgr (CCU + 0xbfc) // LEDC Bus Gating Reset Register ()
#define CCU_ledc_bgr_OFFSET 0xbfc
#define CCU_ledc_bgr_rst (0x1 << 16)
#define CCU_ledc_bgr_rst_SHIFT 16
#define CCU_ledc_bgr_gating 0x1
#define CCU_ledc_bgr_gating_SHIFT 0
#define CCU_csi_clk (CCU + 0xc04) // CSI Clock Register ()
#define CCU_csi_clk_OFFSET 0xc04
#define CCU_csi_clk_clk_gating (0x1 << 31)
#define CCU_csi_clk_clk_gating_SHIFT 31
#define CCU_csi_clk_clk_src_sel (0x7 << 24)
#define CCU_csi_clk_clk_src_sel_SHIFT 24
#define CCU_csi_clk_factor_m 0xf
#define CCU_csi_clk_factor_m_SHIFT 0
#define CCU_csi_master_clk (CCU + 0xc08) // CSI Master Clock Register ()
#define CCU_csi_master_clk_OFFSET 0xc08
#define CCU_csi_master_clk_clk_gating (0x1 << 31)
#define CCU_csi_master_clk_clk_gating_SHIFT 31
#define CCU_csi_master_clk_clk_src_sel (0x7 << 24)
#define CCU_csi_master_clk_clk_src_sel_SHIFT 24
#define CCU_csi_master_clk_factor_m 0x1f
#define CCU_csi_master_clk_factor_m_SHIFT 0
#define CCU_csi_bgr (CCU + 0xc1c) // CSI Bus Gating Reset Register ()
#define CCU_csi_bgr_OFFSET 0xc1c
#define CCU_csi_bgr_rst (0x1 << 16)
#define CCU_csi_bgr_rst_SHIFT 16
#define CCU_csi_bgr_gating 0x1
#define CCU_csi_bgr_gating_SHIFT 0
#define CCU_tpadc_clk (CCU + 0xc50) // TPADC Clock Register ()
#define CCU_tpadc_clk_OFFSET 0xc50
#define CCU_tpadc_clk_clk_gating (0x1 << 31)
#define CCU_tpadc_clk_clk_gating_SHIFT 31
#define CCU_tpadc_clk_clk_src_sel (0x7 << 24)
#define CCU_tpadc_clk_clk_src_sel_SHIFT 24
#define CCU_tpadc_bgr (CCU + 0xc5c) // TPADC Bus Gating Reset Register ()
#define CCU_tpadc_bgr_OFFSET 0xc5c
#define CCU_tpadc_bgr_rst (0x1 << 16)
#define CCU_tpadc_bgr_rst_SHIFT 16
#define CCU_tpadc_bgr_gating 0x1
#define CCU_tpadc_bgr_gating_SHIFT 0
#define CCU_dsp_clk (CCU + 0xc70) // DSP Clock Register ()
#define CCU_dsp_clk_OFFSET 0xc70
#define CCU_dsp_clk_clk_gating (0x1 << 31)
#define CCU_dsp_clk_clk_gating_SHIFT 31
#define CCU_dsp_clk_clk_src_sel (0x7 << 24)
#define CCU_dsp_clk_clk_src_sel_SHIFT 24
#define CCU_dsp_clk_factor_m 0x1f
#define CCU_dsp_clk_factor_m_SHIFT 0
#define CCU_dsp_bgr (CCU + 0xc7c) // DSP Bus Gating Reset Register ()
#define CCU_dsp_bgr_OFFSET 0xc7c
#define CCU_dsp_bgr_dbg_rst (0x1 << 18)
#define CCU_dsp_bgr_dbg_rst_SHIFT 18
#define CCU_dsp_bgr_cfg_rst (0x1 << 17)
#define CCU_dsp_bgr_cfg_rst_SHIFT 17
#define CCU_dsp_bgr_rst (0x1 << 16)
#define CCU_dsp_bgr_rst_SHIFT 16
#define CCU_dsp_bgr_cfg_gating (0x1 << 1)
#define CCU_dsp_bgr_cfg_gating_SHIFT 1
#define CCU_riscv_clk (CCU + 0xd00) // RISC-V Clock Register ()
#define CCU_riscv_clk_OFFSET 0xd00
#define CCU_riscv_clk_clk_src_sel (0x7 << 24)
#define CCU_riscv_clk_clk_src_sel_SHIFT 24
#define CCU_riscv_clk_axi_div_cfg (0x3 << 8)
#define CCU_riscv_clk_axi_div_cfg_SHIFT 8
#define CCU_riscv_clk_div_cfg 0x1f
#define CCU_riscv_clk_div_cfg_SHIFT 0
#define CCU_riscv_gating (CCU + 0xd04) // RISC-V GATING Configuration Register ()
#define CCU_riscv_gating_OFFSET 0xd04
#define CCU_riscv_gating_gating (0x1 << 31)
#define CCU_riscv_gating_gating_SHIFT 31
#define CCU_riscv_gating_gating_field 0xffff
#define CCU_riscv_gating_gating_field_SHIFT 0
#define CCU_riscv_cfg_bgr (CCU + 0xd0c) // RISC-V_CFG Bus Gating Reset Register ()
#define CCU_riscv_cfg_bgr_OFFSET 0xd0c
#define CCU_riscv_cfg_bgr_rst (0x1 << 16)
#define CCU_riscv_cfg_bgr_rst_SHIFT 16
#define CCU_riscv_cfg_bgr_gating 0x1
#define CCU_riscv_cfg_bgr_gating_SHIFT 0
#define CCU_pll_lock_dbg_ctrl (CCU + 0xf04) // PLL Lock Debug Control Register ()
#define CCU_pll_lock_dbg_ctrl_OFFSET 0xf04
#define CCU_pll_lock_dbg_ctrl_pll_lock_flag_en (0x1 << 31)
#define CCU_pll_lock_dbg_ctrl_pll_lock_flag_en_SHIFT 31
#define CCU_pll_lock_dbg_ctrl_clk_src_sel (0x7 << 20)
#define CCU_pll_lock_dbg_ctrl_clk_src_sel_SHIFT 20
#define CCU_fre_det_ctrl (CCU + 0xf08) // Frequency Detect Control Register ()
#define CCU_fre_det_ctrl_OFFSET 0xf08
#define CCU_fre_det_ctrl_error_flag (0x1 << 31)
#define CCU_fre_det_ctrl_error_flag_SHIFT 31
#define CCU_fre_det_ctrl_det_time (0x1f << 4)
#define CCU_fre_det_ctrl_det_time_SHIFT 4
#define CCU_fre_det_ctrl_fre_det_irq_en (0x1 << 1)
#define CCU_fre_det_ctrl_fre_det_irq_en_SHIFT 1
#define CCU_fre_det_ctrl_fre_det_fun_en 0x1
#define CCU_fre_det_ctrl_fre_det_fun_en_SHIFT 0
#define CCU_fre_up_lim (CCU + 0xf0c) // Frequency Up Limit Register ()
#define CCU_fre_up_lim_OFFSET 0xf0c
#define CCU_fre_down_lim (CCU + 0xf10) // Frequency Down Limit Register ()
#define CCU_fre_down_lim_OFFSET 0xf10
#define CCU_ccu_fan_gate (CCU + 0xf30) // CCU FANOUT CLOCK GATE Register ()
#define CCU_ccu_fan_gate_OFFSET 0xf30
#define CCU_ccu_fan_gate_clk32k_en (0x1 << 4)
#define CCU_ccu_fan_gate_clk32k_en_SHIFT 4
#define CCU_ccu_fan_gate_clk25m_en (0x1 << 3)
#define CCU_ccu_fan_gate_clk25m_en_SHIFT 3
#define CCU_ccu_fan_gate_clk16m_en (0x1 << 2)
#define CCU_ccu_fan_gate_clk16m_en_SHIFT 2
#define CCU_ccu_fan_gate_clk12m_en (0x1 << 1)
#define CCU_ccu_fan_gate_clk12m_en_SHIFT 1
#define CCU_ccu_fan_gate_clk24m_en 0x1
#define CCU_ccu_fan_gate_clk24m_en_SHIFT 0
#define CCU_clk27m_fan (CCU + 0xf34) // CLK27M FANOUT Register ()
#define CCU_clk27m_fan_OFFSET 0xf34
#define CCU_clk27m_fan_gating (0x1 << 31)
#define CCU_clk27m_fan_gating_SHIFT 31
#define CCU_clk27m_fan_clk_src_sel (0x3 << 24)
#define CCU_clk27m_fan_clk_src_sel_SHIFT 24
#define CCU_clk27m_fan_div1 (0x3 << 8)
#define CCU_clk27m_fan_div1_SHIFT 8
#define CCU_clk27m_fan_div0 0x1f
#define CCU_clk27m_fan_div0_SHIFT 0
#define CCU_pclk_fan (CCU + 0xf38) // PCLK FANOUT Register ()
#define CCU_pclk_fan_OFFSET 0xf38
#define CCU_pclk_fan_gating (0x1 << 31)
#define CCU_pclk_fan_gating_SHIFT 31
#define CCU_pclk_fan_div 0x1f
#define CCU_pclk_fan_div_SHIFT 0
#define CCU_ccu_fan (CCU + 0xf3c) // CCU FANOUT Register ()
#define CCU_ccu_fan_OFFSET 0xf3c
#define CCU_ccu_fan_clk_fanout0_en (0x1 << 21)
#define CCU_ccu_fan_clk_fanout0_en_SHIFT 21
#define CCU_ccu_fan_clk_fanout0_sel 0x7
#define CCU_ccu_fan_clk_fanout0_sel_SHIFT 0

/****************************************************************
 * System Configuration
 ****************************************************************/
#define SYS_CFG 0x03000000
#define SYS_CFG_dsp_boot_rammap (SYS_CFG + 0x8) // DSP Boot SRAM Remap Control Register ()
#define SYS_CFG_dsp_boot_rammap_OFFSET 0x8
#define SYS_CFG_dsp_boot_rammap_dsp_boot_sram_remap_enable 0x1
#define SYS_CFG_dsp_boot_rammap_dsp_boot_sram_remap_enable_SHIFT 0
#define SYS_CFG_ver (SYS_CFG + 0x24) // Version Register (R only)
#define SYS_CFG_ver_OFFSET 0x24
#define SYS_CFG_ver_boot_sel_pad_sta (0x3 << 11)
#define SYS_CFG_ver_boot_sel_pad_sta_SHIFT 11
#define SYS_CFG_ver_fel_sel_pad_sta (0x1 << 8)
#define SYS_CFG_ver_fel_sel_pad_sta_SHIFT 8
#define SYS_CFG_emac_ephy_clk0 (SYS_CFG + 0x30) // EMAC-EPHY Clock Register 0 ()
#define SYS_CFG_emac_ephy_clk0_OFFSET 0x30
#define SYS_CFG_emac_ephy_clk0_bps_efuse (0xf << 28)
#define SYS_CFG_emac_ephy_clk0_bps_efuse_SHIFT 28
#define SYS_CFG_emac_ephy_clk0_xmii_sel (0x1 << 27)
#define SYS_CFG_emac_ephy_clk0_xmii_sel_SHIFT 27
#define SYS_CFG_emac_ephy_clk0_ephy_mode (0x3 << 25)
#define SYS_CFG_emac_ephy_clk0_ephy_mode_SHIFT 25
#define SYS_CFG_emac_ephy_clk0_phy_addr (0x1f << 20)
#define SYS_CFG_emac_ephy_clk0_phy_addr_SHIFT 20
#define SYS_CFG_emac_ephy_clk0_clk_sel (0x1 << 18)
#define SYS_CFG_emac_ephy_clk0_clk_sel_SHIFT 18
#define SYS_CFG_emac_ephy_clk0_led_pol (0x1 << 17)
#define SYS_CFG_emac_ephy_clk0_led_pol_SHIFT 17
#define SYS_CFG_emac_ephy_clk0_shutdown (0x1 << 16)
#define SYS_CFG_emac_ephy_clk0_shutdown_SHIFT 16
#define SYS_CFG_emac_ephy_clk0_phy_select (0x1 << 15)
#define SYS_CFG_emac_ephy_clk0_phy_select_SHIFT 15
#define SYS_CFG_emac_ephy_clk0_rmii_en (0x1 << 13)
#define SYS_CFG_emac_ephy_clk0_rmii_en_SHIFT 13
#define SYS_CFG_emac_ephy_clk0_etxdc (0x7 << 10)
#define SYS_CFG_emac_ephy_clk0_etxdc_SHIFT 10
#define SYS_CFG_emac_ephy_clk0_erxdc (0x1f << 5)
#define SYS_CFG_emac_ephy_clk0_erxdc_SHIFT 5
#define SYS_CFG_emac_ephy_clk0_erxie (0x1 << 4)
#define SYS_CFG_emac_ephy_clk0_erxie_SHIFT 4
#define SYS_CFG_emac_ephy_clk0_etxie (0x1 << 3)
#define SYS_CFG_emac_ephy_clk0_etxie_SHIFT 3
#define SYS_CFG_emac_ephy_clk0_epit (0x1 << 2)
#define SYS_CFG_emac_ephy_clk0_epit_SHIFT 2
#define SYS_CFG_emac_ephy_clk0_etcs 0x3
#define SYS_CFG_emac_ephy_clk0_etcs_SHIFT 0
#define SYS_CFG_sys_ldo_ctrl (SYS_CFG + 0x150) // System LDO Control Register ()
#define SYS_CFG_sys_ldo_ctrl_OFFSET 0x150
#define SYS_CFG_sys_ldo_ctrl_spare (0xff << 24)
#define SYS_CFG_sys_ldo_ctrl_spare_SHIFT 24
#define SYS_CFG_sys_ldo_ctrl_ldob_trim (0xff << 8)
#define SYS_CFG_sys_ldo_ctrl_ldob_trim_SHIFT 8
#define SYS_CFG_sys_ldo_ctrl_ldoa_trim 0xff
#define SYS_CFG_sys_ldo_ctrl_ldoa_trim_SHIFT 0
#define SYS_CFG_rescal_ctrl (SYS_CFG + 0x160) // Resistor Calibration Control Register ()
#define SYS_CFG_rescal_ctrl_OFFSET 0x160
#define SYS_CFG_rescal_ctrl_ddr_res240_trimming_sel (0x1 << 8)
#define SYS_CFG_rescal_ctrl_ddr_res240_trimming_sel_SHIFT 8
#define SYS_CFG_rescal_ctrl_rescal_mode (0x1 << 2)
#define SYS_CFG_rescal_ctrl_rescal_mode_SHIFT 2
#define SYS_CFG_rescal_ctrl_cal_ana_en (0x1 << 1)
#define SYS_CFG_rescal_ctrl_cal_ana_en_SHIFT 1
#define SYS_CFG_rescal_ctrl_cal_en 0x1
#define SYS_CFG_rescal_ctrl_cal_en_SHIFT 0
#define SYS_CFG_res240_ctrl (SYS_CFG + 0x168) // 240ohms Resistor Manual Control Register ()
#define SYS_CFG_res240_ctrl_OFFSET 0x168
#define SYS_CFG_res240_ctrl_ddr_res240_trim 0x3f
#define SYS_CFG_res240_ctrl_ddr_res240_trim_SHIFT 0
#define SYS_CFG_rescal_status (SYS_CFG + 0x16c) // Resistor Calibration Status Register (R only)
#define SYS_CFG_rescal_status_OFFSET 0x16c
#define SYS_CFG_rescal_status_cout (0x1 << 8)
#define SYS_CFG_rescal_status_cout_SHIFT 8
#define SYS_CFG_rescal_status_res_cal_do 0x3f
#define SYS_CFG_rescal_status_res_cal_do_SHIFT 0

/****************************************************************
 * RISC-V System Configuration
 ****************************************************************/
#define RISCV_CFG 0x06010000
#define RISCV_CFG_riscv_sta_add0 (RISCV_CFG + 0x4) // RISCV Start Address0 Register ()
#define RISCV_CFG_riscv_sta_add0_OFFSET 0x4
#define RISCV_CFG_riscv_sta_add1 (RISCV_CFG + 0x8) // RISCV Start Address1 Register ()
#define RISCV_CFG_riscv_sta_add1_OFFSET 0x8
#define RISCV_CFG_riscv_sta_add1_sta_add_h 0xff
#define RISCV_CFG_riscv_sta_add1_sta_add_h_SHIFT 0
#define RISCV_CFG_rf1p_cfg (RISCV_CFG + 0x10) // RF1P Configuration Register ()
#define RISCV_CFG_rf1p_cfg_OFFSET 0x10
#define RISCV_CFG_rf1p_cfg_rf1p_cfg 0xff
#define RISCV_CFG_rf1p_cfg_rf1p_cfg_SHIFT 0
#define RISCV_CFG_rom_cfg (RISCV_CFG + 0x1c) // ROM Configuration Register ()
#define RISCV_CFG_rom_cfg_OFFSET 0x1c
#define RISCV_CFG_rom_cfg_rom_cfg 0xff
#define RISCV_CFG_rom_cfg_rom_cfg_SHIFT 0
#define RISCV_CFG_wakeup_en (RISCV_CFG + 0x20) // Wakeup Enable Register ()
#define RISCV_CFG_wakeup_en_OFFSET 0x20
#define RISCV_CFG_wakeup_en_wp_en 0x1
#define RISCV_CFG_wakeup_en_wp_en_SHIFT 0
#define RISCV_CFG_wakeup_mask0 (RISCV_CFG + 0x24) // Wakeup Mask Register ()
#define RISCV_CFG_wakeup_mask0_OFFSET 0x24
#define RISCV_CFG_ts_tmode_sel (RISCV_CFG + 0x40) // Timestamp Test Mode Select Register ()
#define RISCV_CFG_ts_tmode_sel_OFFSET 0x40
#define RISCV_CFG_ts_tmode_sel_ts_test_mode_en 0x1
#define RISCV_CFG_ts_tmode_sel_ts_test_mode_en_SHIFT 0
#define RISCV_CFG_sram_addr_twist (RISCV_CFG + 0x44) // SRAM Address Twist Register ()
#define RISCV_CFG_sram_addr_twist_OFFSET 0x44
#define RISCV_CFG_sram_addr_twist_sram_ts_kf (0xffff << 16)
#define RISCV_CFG_sram_addr_twist_sram_ts_kf_SHIFT 16
#define RISCV_CFG_sram_addr_twist_sram_addr_ts_fg 0x1
#define RISCV_CFG_sram_addr_twist_sram_addr_ts_fg_SHIFT 0
#define RISCV_CFG_work_mode (RISCV_CFG + 0x48) // Work Mode Register (R only)
#define RISCV_CFG_work_mode_OFFSET 0x48
#define RISCV_CFG_work_mode_wm_sta 0x3
#define RISCV_CFG_work_mode_wm_sta_SHIFT 0
#define RISCV_CFG_retite_pc0 (RISCV_CFG + 0x50) // Retire PC0 Register (R only)
#define RISCV_CFG_retite_pc0_OFFSET 0x50
#define RISCV_CFG_retite_pc1 (RISCV_CFG + 0x54) // Retire PC1 Register (R only)
#define RISCV_CFG_retite_pc1_OFFSET 0x54
#define RISCV_CFG_retite_pc1_rt_sig (0x1 << 31)
#define RISCV_CFG_retite_pc1_rt_sig_SHIFT 31
#define RISCV_CFG_retite_pc1_rt_pc_h 0xff
#define RISCV_CFG_retite_pc1_rt_pc_h_SHIFT 0
#define RISCV_CFG_irq_mode0 (RISCV_CFG + 0x60) // IRQ Mode Register ()
#define RISCV_CFG_irq_mode0_OFFSET 0x60
#define RISCV_CFG_riscv_axi_pmu_ctrl (RISCV_CFG + 0x104) // RISCV AXI PMU Control Register ()
#define RISCV_CFG_riscv_axi_pmu_ctrl_OFFSET 0x104
#define RISCV_CFG_riscv_axi_pmu_ctrl_pmu_clr (0x1 << 1)
#define RISCV_CFG_riscv_axi_pmu_ctrl_pmu_clr_SHIFT 1
#define RISCV_CFG_riscv_axi_pmu_ctrl_pmu_en 0x1
#define RISCV_CFG_riscv_axi_pmu_ctrl_pmu_en_SHIFT 0
#define RISCV_CFG_riscv_axi_pmu_prd (RISCV_CFG + 0x108) // RISCV AXI PMU Period Register ()
#define RISCV_CFG_riscv_axi_pmu_prd_OFFSET 0x108
#define RISCV_CFG_riscv_axi_pmu_lat_rd (RISCV_CFG + 0x10c) // RISCV AXI PMU Read Latency Register (R only)
#define RISCV_CFG_riscv_axi_pmu_lat_rd_OFFSET 0x10c
#define RISCV_CFG_riscv_axi_pmu_lat_wr (RISCV_CFG + 0x110) // RISCV AXI PMU Write Latency Register (R only)
#define RISCV_CFG_riscv_axi_pmu_lat_wr_OFFSET 0x110
#define RISCV_CFG_riscv_axi_pmu_req_rd (RISCV_CFG + 0x114) // RISCV AXI PMU Read Request Register (R only)
#define RISCV_CFG_riscv_axi_pmu_req_rd_OFFSET 0x114
#define RISCV_CFG_riscv_axi_pmu_req_wr (RISCV_CFG + 0x118) // RISCV AXI PMU Write Request Register (R only)
#define RISCV_CFG_riscv_axi_pmu_req_wr_OFFSET 0x118
#define RISCV_CFG_riscv_axi_pmu_bw_rd (RISCV_CFG + 0x11c) // RISCV AXI PMU Read Bandwidth Register (R only)
#define RISCV_CFG_riscv_axi_pmu_bw_rd_OFFSET 0x11c
#define RISCV_CFG_riscv_axi_pmu_bw_wr (RISCV_CFG + 0x120) // RISCV AXI PMU Write Bandwidth Register (R only)
#define RISCV_CFG_riscv_axi_pmu_bw_wr_OFFSET 0x120

/****************************************************************
 * Core-Local Interruptor
 ****************************************************************/
#define CLINT 0x14000000
#define CLINT_msip (CLINT + 0x0) // MSIP Register for hart 0 ()
#define CLINT_msip_OFFSET 0x0
#define CLINT_mtimecmpl (CLINT + 0x4000) // MTIMECMPL Register for hart 0 ()
#define CLINT_mtimecmpl_OFFSET 0x4000
#define CLINT_mtimecmph (CLINT + 0x4004) // MTIMECMPH Register for hart 0 ()
#define CLINT_mtimecmph_OFFSET 0x4004
#define CLINT_mtime (CLINT + 0xbff8) // MTIME\n\nREF: opensbi (R only)
#define CLINT_mtime_OFFSET 0xbff8
#define CLINT_ssip (CLINT + 0xc000) // SSIP Register for hart 0 ()
#define CLINT_ssip_OFFSET 0xc000
#define CLINT_stimecmpl (CLINT + 0xd000) // STIMECMPL Register for hart 0 ()
#define CLINT_stimecmpl_OFFSET 0xd000
#define CLINT_stimecmph (CLINT + 0xd004) // STIMECMPH Register for hart 0 ()
#define CLINT_stimecmph_OFFSET 0xd004

/****************************************************************
 * Timer Module, includes timer0, timer1, watchdog and audio video synchronization
 ****************************************************************/
#define TIMER 0x02050000
#define TIMER_tmr_irq_en (TIMER + 0x0) // Timer IRQ Enable Register ()
#define TIMER_tmr_irq_en_OFFSET 0x0
#define TIMER_tmr_irq_en_tmr1_irq_en (0x1 << 1)
#define TIMER_tmr_irq_en_tmr1_irq_en_SHIFT 1
#define TIMER_tmr_irq_en_tmr0_irq_en 0x1
#define TIMER_tmr_irq_en_tmr0_irq_en_SHIFT 0
#define TIMER_tmr_irq_sta (TIMER + 0x4) // Timer Status Register ()
#define TIMER_tmr_irq_sta_OFFSET 0x4
#define TIMER_tmr_irq_sta_tmr1_irq_pend (0x1 << 1)
#define TIMER_tmr_irq_sta_tmr1_irq_pend_SHIFT 1
#define TIMER_tmr_irq_sta_tmr0_irq_pend 0x1
#define TIMER_tmr_irq_sta_tmr0_irq_pend_SHIFT 0
#define TIMER_tmr0_ctrl (TIMER + 0x10) // Timer IRQ Enable Register ()
#define TIMER_tmr0_ctrl_OFFSET 0x10
#define TIMER_tmr0_ctrl_tmr_mode (0x1 << 7)
#define TIMER_tmr0_ctrl_tmr_mode_SHIFT 7
#define TIMER_tmr0_ctrl_tmr_clk_pres (0x7 << 4)
#define TIMER_tmr0_ctrl_tmr_clk_pres_SHIFT 4
#define TIMER_tmr0_ctrl_tmr_clk_src (0x3 << 2)
#define TIMER_tmr0_ctrl_tmr_clk_src_SHIFT 2
#define TIMER_tmr0_ctrl_tmr_reload (0x1 << 1)
#define TIMER_tmr0_ctrl_tmr_reload_SHIFT 1
#define TIMER_tmr0_ctrl_tmr_en 0x1
#define TIMER_tmr0_ctrl_tmr_en_SHIFT 0
#define TIMER_tmr0_intv_value (TIMER + 0x14) // Timer Interval Value Register ()
#define TIMER_tmr0_intv_value_OFFSET 0x14
#define TIMER_tmr0_cur_value (TIMER + 0x18) // Timer Current Value Register ()
#define TIMER_tmr0_cur_value_OFFSET 0x18
#define TIMER_wdog_irq_en (TIMER + 0xa0) // Watchdog IRQ Enable Register ()
#define TIMER_wdog_irq_en_OFFSET 0xa0
#define TIMER_wdog_irq_en_wdog_irq_en 0x1
#define TIMER_wdog_irq_en_wdog_irq_en_SHIFT 0
#define TIMER_wdog_irq_sta (TIMER + 0xa4) // Watchdog Status Register ()
#define TIMER_wdog_irq_sta_OFFSET 0xa4
#define TIMER_wdog_irq_sta_wdog_irq_pend 0x1
#define TIMER_wdog_irq_sta_wdog_irq_pend_SHIFT 0
#define TIMER_wdog_soft_rst (TIMER + 0xa8) // Watchdog Software Reset Register ()
#define TIMER_wdog_soft_rst_OFFSET 0xa8
#define TIMER_wdog_soft_rst_key_field (0xffff << 16)
#define TIMER_wdog_soft_rst_key_field_SHIFT 16
#define TIMER_wdog_soft_rst_soft_rst_en 0x1
#define TIMER_wdog_soft_rst_soft_rst_en_SHIFT 0
#define TIMER_wdog_ctrl (TIMER + 0xb0) // Watchdog Control Register ()
#define TIMER_wdog_ctrl_OFFSET 0xb0
#define TIMER_wdog_ctrl_wdog_key_field (0xfff << 1)
#define TIMER_wdog_ctrl_wdog_key_field_SHIFT 1
#define TIMER_wdog_ctrl_wdog_restart 0x1
#define TIMER_wdog_ctrl_wdog_restart_SHIFT 0
#define TIMER_wdog_cfg (TIMER + 0xb4) // Watchdog Configuration Register ()
#define TIMER_wdog_cfg_OFFSET 0xb4
#define TIMER_wdog_cfg_key_field (0xffff << 16)
#define TIMER_wdog_cfg_key_field_SHIFT 16
#define TIMER_wdog_cfg_wdog_clk_src (0x1 << 8)
#define TIMER_wdog_cfg_wdog_clk_src_SHIFT 8
#define TIMER_wdog_cfg_wdog_mode 0x3
#define TIMER_wdog_cfg_wdog_mode_SHIFT 0
#define TIMER_wdog_mode (TIMER + 0xb8) // Watchdog Mode Register ()
#define TIMER_wdog_mode_OFFSET 0xb8
#define TIMER_wdog_mode_key_field (0xffff << 16)
#define TIMER_wdog_mode_key_field_SHIFT 16
#define TIMER_wdog_mode_wdog_intv_value (0xf << 4)
#define TIMER_wdog_mode_wdog_intv_value_SHIFT 4
#define TIMER_wdog_mode_wdog_en 0x1
#define TIMER_wdog_mode_wdog_en_SHIFT 0
#define TIMER_wdog_output_cfg (TIMER + 0xbc) // Watchdog Output Configuration Register ()
#define TIMER_wdog_output_cfg_OFFSET 0xbc
#define TIMER_wdog_output_cfg_wdog_output_config 0xfff
#define TIMER_wdog_output_cfg_wdog_output_config_SHIFT 0
#define TIMER_avs_cnt_ctl (TIMER + 0xc0) // AVS Counter Control Register ()
#define TIMER_avs_cnt_ctl_OFFSET 0xc0
#define TIMER_avs_cnt_ctl_avs_cnt0_ps (0x1 << 8)
#define TIMER_avs_cnt_ctl_avs_cnt0_ps_SHIFT 8
#define TIMER_avs_cnt_ctl_avs_cnt0_en 0x1
#define TIMER_avs_cnt_ctl_avs_cnt0_en_SHIFT 0
#define TIMER_avs_cnt0 (TIMER + 0xc4) // AVS Counter 0 Register ()
#define TIMER_avs_cnt0_OFFSET 0xc4
#define TIMER_avs_cnt1 (TIMER + 0xc8) // AVS Counter 1 Register ()
#define TIMER_avs_cnt1_OFFSET 0xc8
#define TIMER_avs_cnt_div (TIMER + 0xcc) // AVS Counter Divisor Register ()
#define TIMER_avs_cnt_div_OFFSET 0xcc
#define TIMER_avs_cnt_div_avs_cnt0_d 0xfff
#define TIMER_avs_cnt_div_avs_cnt0_d_SHIFT 0

/****************************************************************
 * High Speed Timer
 ****************************************************************/
#define HS_TIMER 0x03008000
#define HS_TIMER_hs_tmr_irq_en (HS_TIMER + 0x0) // HS Timer IRQ Enable Register ()
#define HS_TIMER_hs_tmr_irq_en_OFFSET 0x0
#define HS_TIMER_hs_tmr_irq_en_hs_tmr0_int_en 0x1
#define HS_TIMER_hs_tmr_irq_en_hs_tmr0_int_en_SHIFT 0
#define HS_TIMER_hs_tmr_irq_stas (HS_TIMER + 0x4) // HS Timer Status Register ()
#define HS_TIMER_hs_tmr_irq_stas_OFFSET 0x4
#define HS_TIMER_hs_tmr_irq_stas_hs_tmr0_irq_pend 0x1
#define HS_TIMER_hs_tmr_irq_stas_hs_tmr0_irq_pend_SHIFT 0
#define HS_TIMER_hs_tmr0_ctrl (HS_TIMER + 0x20) // HS Timer Control Register ()
#define HS_TIMER_hs_tmr0_ctrl_OFFSET 0x20
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_test (0x1 << 31)
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_test_SHIFT 31
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_mode (0x1 << 7)
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_mode_SHIFT 7
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_clk (0x7 << 4)
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_clk_SHIFT 4
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_reload (0x1 << 1)
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_reload_SHIFT 1
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_en 0x1
#define HS_TIMER_hs_tmr0_ctrl_hs_tmr_en_SHIFT 0
#define HS_TIMER_hs_tmr0_intv_lo (HS_TIMER + 0x24) // HS Timer Interval Value Low Register ()
#define HS_TIMER_hs_tmr0_intv_lo_OFFSET 0x24
#define HS_TIMER_hs_tmr0_intv_hi (HS_TIMER + 0x28) // HS Timer Interval Value High Register ()
#define HS_TIMER_hs_tmr0_intv_hi_OFFSET 0x28
#define HS_TIMER_hs_tmr0_intv_hi_hs_tmr_intv_value_hi 0xffffff
#define HS_TIMER_hs_tmr0_intv_hi_hs_tmr_intv_value_hi_SHIFT 0
#define HS_TIMER_hs_tmr0_curnt_lo (HS_TIMER + 0x2c) // HS Timer Current Value Low Register ()
#define HS_TIMER_hs_tmr0_curnt_lo_OFFSET 0x2c
#define HS_TIMER_hs_tmr0_curnt_hi (HS_TIMER + 0x30) // HS Timer Current Value High Register ()
#define HS_TIMER_hs_tmr0_curnt_hi_OFFSET 0x30
#define HS_TIMER_hs_tmr0_curnt_hi_hs_tmr_cur_value_hi 0xffffff
#define HS_TIMER_hs_tmr0_curnt_hi_hs_tmr_cur_value_hi_SHIFT 0

/****************************************************************
 * Platform Level Interrupt Control
 ****************************************************************/
#define PLIC 0x10000000
#define PLIC_prio0 (PLIC + 0x0) // Interrupt Priority Register ()
#define PLIC_prio0_OFFSET 0x0
#define PLIC_prio0_priority 0x1f
#define PLIC_prio0_priority_SHIFT 0
#define PLIC_ip0 (PLIC + 0x1000) // Interrupt Pending Register ()
#define PLIC_ip0_OFFSET 0x1000
#define PLIC_mie0 (PLIC + 0x2000) // Machine Mode Interrupt Enable Register ()
#define PLIC_mie0_OFFSET 0x2000
#define PLIC_sie0 (PLIC + 0x2080) // Supervisor Mode Interrupt Enable Register ()
#define PLIC_sie0_OFFSET 0x2080
#define PLIC_ctrl (PLIC + 0x1ffffc) // Control Register ()
#define PLIC_ctrl_OFFSET 0x1ffffc
#define PLIC_ctrl_ctrl 0x1
#define PLIC_ctrl_ctrl_SHIFT 0
#define PLIC_mth (PLIC + 0x200000) // Machine Mode Priority Threshold Register ()
#define PLIC_mth_OFFSET 0x200000
#define PLIC_mth_priority 0x1f
#define PLIC_mth_priority_SHIFT 0
#define PLIC_mclaim (PLIC + 0x200004) // Machine Mode Claim/Complete Register ()
#define PLIC_mclaim_OFFSET 0x200004
#define PLIC_mclaim_mclaim 0x3ff
#define PLIC_mclaim_mclaim_SHIFT 0
#define PLIC_sth (PLIC + 0x201000) // Supervisor Mode Priority Threshold Register ()
#define PLIC_sth_OFFSET 0x201000
#define PLIC_sth_priority 0x1f
#define PLIC_sth_priority_SHIFT 0
#define PLIC_sclaim (PLIC + 0x201004) // Supervisor Mode Claim/Complete Register ()
#define PLIC_sclaim_OFFSET 0x201004
#define PLIC_sclaim_sclaim 0x3ff
#define PLIC_sclaim_sclaim_SHIFT 0

/****************************************************************
 * Direct Memory Access Controller
 ****************************************************************/
#define DMAC 0x03002000
#define DMAC_dmac_irq_en0 (DMAC + 0x0) // DMAC IRQ Enable Register 0 ()
#define DMAC_dmac_irq_en0_OFFSET 0x0
#define DMAC_dmac_irq_en0_dma0_hlaf_irq_en 0x1
#define DMAC_dmac_irq_en0_dma0_hlaf_irq_en_SHIFT 0
#define DMAC_dmac_irq_en0_dma0_pkg_irq_en (0x1 << 1)
#define DMAC_dmac_irq_en0_dma0_pkg_irq_en_SHIFT 1
#define DMAC_dmac_irq_en0_dma0_queue_irq_en (0x1 << 2)
#define DMAC_dmac_irq_en0_dma0_queue_irq_en_SHIFT 2
#define DMAC_dmac_irq_en1 (DMAC + 0x4) // DMAC IRQ Enable Register 1 ()
#define DMAC_dmac_irq_en1_OFFSET 0x4
#define DMAC_dmac_irq_en1_dma0_hlaf_irq_en 0x1
#define DMAC_dmac_irq_en1_dma0_hlaf_irq_en_SHIFT 0
#define DMAC_dmac_irq_en1_dma0_pkg_irq_en (0x1 << 1)
#define DMAC_dmac_irq_en1_dma0_pkg_irq_en_SHIFT 1
#define DMAC_dmac_irq_en1_dma0_queue_irq_en (0x1 << 2)
#define DMAC_dmac_irq_en1_dma0_queue_irq_en_SHIFT 2
#define DMAC_dmac_irq_pend0 (DMAC + 0x10) // DMAC IRQ Pending Register 0 ()
#define DMAC_dmac_irq_pend0_OFFSET 0x10
#define DMAC_dmac_irq_pend0_dma0_hlaf_irq_pend 0x1
#define DMAC_dmac_irq_pend0_dma0_hlaf_irq_pend_SHIFT 0
#define DMAC_dmac_irq_pend0_dma0_pkg_irq_pend (0x1 << 1)
#define DMAC_dmac_irq_pend0_dma0_pkg_irq_pend_SHIFT 1
#define DMAC_dmac_irq_pend0_dma0_queue_irq_pend (0x1 << 2)
#define DMAC_dmac_irq_pend0_dma0_queue_irq_pend_SHIFT 2
#define DMAC_dmac_irq_pend1 (DMAC + 0x14) // DMAC IRQ Pending Register 1 ()
#define DMAC_dmac_irq_pend1_OFFSET 0x14
#define DMAC_dmac_irq_pend1_dma0_hlaf_irq_pend 0x1
#define DMAC_dmac_irq_pend1_dma0_hlaf_irq_pend_SHIFT 0
#define DMAC_dmac_irq_pend1_dma0_pkg_irq_pend (0x1 << 1)
#define DMAC_dmac_irq_pend1_dma0_pkg_irq_pend_SHIFT 1
#define DMAC_dmac_irq_pend1_dma0_queue_irq_pend (0x1 << 2)
#define DMAC_dmac_irq_pend1_dma0_queue_irq_pend_SHIFT 2
#define DMAC_dmac_auto_gate (DMAC + 0x28) // DMAC Auto Gating Register ()
#define DMAC_dmac_auto_gate_OFFSET 0x28
#define DMAC_dmac_auto_gate_dma_mclk_circuit (0x1 << 2)
#define DMAC_dmac_auto_gate_dma_mclk_circuit_SHIFT 2
#define DMAC_dmac_auto_gate_dma_common_circuit (0x1 << 1)
#define DMAC_dmac_auto_gate_dma_common_circuit_SHIFT 1
#define DMAC_dmac_auto_gate_dma_chan_circuit 0x1
#define DMAC_dmac_auto_gate_dma_chan_circuit_SHIFT 0
#define DMAC_dmac_sta (DMAC + 0x30) // DMAC Status Register (R only)
#define DMAC_dmac_sta_OFFSET 0x30
#define DMAC_dmac_sta_mbus_fifo_status (0x1 << 31)
#define DMAC_dmac_sta_mbus_fifo_status_SHIFT 31
#define DMAC_dmac_sta_dma_status0 0x1
#define DMAC_dmac_sta_dma_status0_SHIFT 0
#define DMAC_dmac_en0 (DMAC + 0x100) // DMAC Channel Enable Register ()
#define DMAC_dmac_en0_OFFSET 0x100
#define DMAC_dmac_en0_dma_en 0x1
#define DMAC_dmac_en0_dma_en_SHIFT 0
#define DMAC_dmac_pau0 (DMAC + 0x104) // DMAC Channel Pause Register ()
#define DMAC_dmac_pau0_OFFSET 0x104
#define DMAC_dmac_pau0_dma_pause 0x1
#define DMAC_dmac_pau0_dma_pause_SHIFT 0
#define DMAC_dmac_desc_addr0 (DMAC + 0x108) // DMAC Channel Start Address Register ()
#define DMAC_dmac_desc_addr0_OFFSET 0x108
#define DMAC_dmac_desc_addr0_dma_desc_addr (0x3fffffff << 2)
#define DMAC_dmac_desc_addr0_dma_desc_addr_SHIFT 2
#define DMAC_dmac_desc_addr0_dma_desc_high_addr 0x3
#define DMAC_dmac_desc_addr0_dma_desc_high_addr_SHIFT 0
#define DMAC_dmac_cfg0 (DMAC + 0x10c) // DMAC Channel Configuration Register (R only)
#define DMAC_dmac_cfg0_OFFSET 0x10c
#define DMAC_dmac_cfg0_bmode_sel (0x1 << 30)
#define DMAC_dmac_cfg0_bmode_sel_SHIFT 30
#define DMAC_dmac_cfg0_dma_dest_data_width (0x3 << 25)
#define DMAC_dmac_cfg0_dma_dest_data_width_SHIFT 25
#define DMAC_dmac_cfg0_dma_addr_mode (0x1 << 24)
#define DMAC_dmac_cfg0_dma_addr_mode_SHIFT 24
#define DMAC_dmac_cfg0_dma_dest_block_size (0x3 << 22)
#define DMAC_dmac_cfg0_dma_dest_block_size_SHIFT 22
#define DMAC_dmac_cfg0_dma_dest_drq_type (0x3f << 16)
#define DMAC_dmac_cfg0_dma_dest_drq_type_SHIFT 16
#define DMAC_dmac_cfg0_dma_src_data_width (0x3 << 9)
#define DMAC_dmac_cfg0_dma_src_data_width_SHIFT 9
#define DMAC_dmac_cfg0_dma_src_addr_mode (0x1 << 8)
#define DMAC_dmac_cfg0_dma_src_addr_mode_SHIFT 8
#define DMAC_dmac_cfg0_dma_src_block_size (0x3 << 6)
#define DMAC_dmac_cfg0_dma_src_block_size_SHIFT 6
#define DMAC_dmac_cfg0_dma_src_drq_type 0x3f
#define DMAC_dmac_cfg0_dma_src_drq_type_SHIFT 0
#define DMAC_dmac_cur_src0 (DMAC + 0x110) // DMAC Channel Current Source Register (R only)
#define DMAC_dmac_cur_src0_OFFSET 0x110
#define DMAC_dmac_cur_dest0 (DMAC + 0x114) // DMAC Channel Current Destination Register (R only)
#define DMAC_dmac_cur_dest0_OFFSET 0x114
#define DMAC_dmac_bcnt_left0 (DMAC + 0x118) // DMAC Channel Byte Counter Left Register (R only)
#define DMAC_dmac_bcnt_left0_OFFSET 0x118
#define DMAC_dmac_bcnt_left0_dma_bcnt_left 0x1ffffff
#define DMAC_dmac_bcnt_left0_dma_bcnt_left_SHIFT 0
#define DMAC_dmac_para0 (DMAC + 0x11c) // DMAC Channel Parameter Register (R only)
#define DMAC_dmac_para0_OFFSET 0x11c
#define DMAC_dmac_para0_wait_cyc 0xff
#define DMAC_dmac_para0_wait_cyc_SHIFT 0
#define DMAC_dmac_mode0 (DMAC + 0x128) // DMAC Mode Register ()
#define DMAC_dmac_mode0_OFFSET 0x128
#define DMAC_dmac_mode0_dma_dst_mode (0x1 << 3)
#define DMAC_dmac_mode0_dma_dst_mode_SHIFT 3
#define DMAC_dmac_mode0_dma_src_mode (0x1 << 2)
#define DMAC_dmac_mode0_dma_src_mode_SHIFT 2
#define DMAC_dmac_fdesc_addr0 (DMAC + 0x12c) // DMAC Former Descriptor Address Register (R only)
#define DMAC_dmac_fdesc_addr0_OFFSET 0x12c
#define DMAC_dmac_pkg_num0 (DMAC + 0x130) // DMAC Package Number Register (R only)
#define DMAC_dmac_pkg_num0_OFFSET 0x130

/****************************************************************
 * Thermal Sensor Controller
 ****************************************************************/
#define THS 0x02009400
#define THS_ths_ctrl (THS + 0x0) // THS Control Register ()
#define THS_ths_ctrl_OFFSET 0x0
#define THS_ths_ctrl_RESET 0x01DF002F
#define THS_ths_ctrl_tacq (0xffff << 16)
#define THS_ths_ctrl_tacq_SHIFT 16
#define THS_ths_en (THS + 0x4) // THS Enable Register ()
#define THS_ths_en_OFFSET 0x4
#define THS_ths_en_RESET 0x00000000
#define THS_ths_en_ths_en 0x1
#define THS_ths_en_ths_en_SHIFT 0
#define THS_ths_per (THS + 0x8) // THS Period Control Register ()
#define THS_ths_per_OFFSET 0x8
#define THS_ths_per_RESET 0x0003A000
#define THS_ths_per_thermal_per (0xfffff << 12)
#define THS_ths_per_thermal_per_SHIFT 12
#define THS_ths_data_intc (THS + 0x10) // THS Data Interrupt Control Register ()
#define THS_ths_data_intc_OFFSET 0x10
#define THS_ths_data_intc_RESET 0x00000000
#define THS_ths_data_intc_ths_data_irq_en 0x1
#define THS_ths_data_intc_ths_data_irq_en_SHIFT 0
#define THS_ths_shut_intc (THS + 0x14) // THS Shut Interrupt Control Register ()
#define THS_ths_shut_intc_OFFSET 0x14
#define THS_ths_shut_intc_RESET 0x00000000
#define THS_ths_shut_intc_shut_int_en 0x1
#define THS_ths_shut_intc_shut_int_en_SHIFT 0
#define THS_ths_alarm_intc (THS + 0x18) // THS Alarm Interrupt Control Register ()
#define THS_ths_alarm_intc_OFFSET 0x18
#define THS_ths_alarm_intc_RESET 0x00000000
#define THS_ths_alarm_intc_alarm_int_en 0x1
#define THS_ths_alarm_intc_alarm_int_en_SHIFT 0
#define THS_ths_data_ints (THS + 0x20) // THS Data Interrupt Status Register ()
#define THS_ths_data_ints_OFFSET 0x20
#define THS_ths_data_ints_RESET 0x00000000
#define THS_ths_data_ints_ths_data_irq_sts 0x1
#define THS_ths_data_ints_ths_data_irq_sts_SHIFT 0
#define THS_ths_shut_ints (THS + 0x24) // THS Shut Interrupt Status Register ()
#define THS_ths_shut_ints_OFFSET 0x24
#define THS_ths_shut_ints_RESET 0x00000000
#define THS_ths_shut_ints_shut_int_sts 0x1
#define THS_ths_shut_ints_shut_int_sts_SHIFT 0
#define THS_ths_alarmo_ints (THS + 0x28) // THS_ALARM0_INTS ()
#define THS_ths_alarmo_ints_OFFSET 0x28
#define THS_ths_alarmo_ints_RESET 0x00000000
#define THS_ths_alarmo_ints_alarm_off_sts 0x1
#define THS_ths_alarmo_ints_alarm_off_sts_SHIFT 0
#define THS_ths_alarm_ints (THS + 0x2c) // THS Alarm Interrupt Status Register ()
#define THS_ths_alarm_ints_OFFSET 0x2c
#define THS_ths_alarm_ints_RESET 0x00000000
#define THS_ths_alarm_ints_alarm_int_sts 0x1
#define THS_ths_alarm_ints_alarm_int_sts_SHIFT 0
#define THS_ths_filter (THS + 0x30) // THS Median Filter Control Register ()
#define THS_ths_filter_OFFSET 0x30
#define THS_ths_filter_RESET 0x00000001
#define THS_ths_filter_filter_en (0x1 << 2)
#define THS_ths_filter_filter_en_SHIFT 2
#define THS_ths_filter_filter_type 0x3
#define THS_ths_filter_filter_type_SHIFT 0
#define THS_ths_alarm_ctrl (THS + 0x40) // THS Alarm Threshold Control Register ()
#define THS_ths_alarm_ctrl_OFFSET 0x40
#define THS_ths_alarm_ctrl_RESET 0x05A00684
#define THS_ths_alarm_ctrl_alarm_t_hot (0xfff << 16)
#define THS_ths_alarm_ctrl_alarm_t_hot_SHIFT 16
#define THS_ths_alarm_ctrl_alarm_t_hyst 0xfff
#define THS_ths_alarm_ctrl_alarm_t_hyst_SHIFT 0
#define THS_ths_shutdown_ctrl (THS + 0x80) // THS Shutdown Threshold Control Register ()
#define THS_ths_shutdown_ctrl_OFFSET 0x80
#define THS_ths_shutdown_ctrl_RESET 0x000004E9
#define THS_ths_shutdown_ctrl_shut_t_hot 0xfff
#define THS_ths_shutdown_ctrl_shut_t_hot_SHIFT 0
#define THS_ths_cdata (THS + 0xa0) // THS Calibration Data ()
#define THS_ths_cdata_OFFSET 0xa0
#define THS_ths_cdata_RESET 0x00000800
#define THS_ths_cdata_ths_cdata 0xfff
#define THS_ths_cdata_ths_cdata_SHIFT 0
#define THS_ths_data (THS + 0xc0) // THS Data Register (R only)
#define THS_ths_data_OFFSET 0xc0
#define THS_ths_data_RESET 0x00000000
#define THS_ths_data_ths_data 0xfff
#define THS_ths_data_ths_data_SHIFT 0

/****************************************************************
 * I/O Memory Management Unit
 ****************************************************************/
#define IOMMU 0x02010000
#define IOMMU_iommu_reset (IOMMU + 0x10) // IOMMU Reset Register ()
#define IOMMU_iommu_reset_OFFSET 0x10
#define IOMMU_iommu_reset_RESET 0x8003007F
#define IOMMU_iommu_reset_iommu_reset (0x1 << 31)
#define IOMMU_iommu_reset_iommu_reset_SHIFT 31
#define IOMMU_iommu_reset_pc_rst (0x1 << 17)
#define IOMMU_iommu_reset_pc_rst_SHIFT 17
#define IOMMU_iommu_reset_mtlb_rst (0x1 << 16)
#define IOMMU_iommu_reset_mtlb_rst_SHIFT 16
#define IOMMU_iommu_reset_m0_rst 0x1
#define IOMMU_iommu_reset_m0_rst_SHIFT 0
#define IOMMU_iommu_enable (IOMMU + 0x20) // IOMMU Enable Register ()
#define IOMMU_iommu_enable_OFFSET 0x20
#define IOMMU_iommu_enable_enable 0x1
#define IOMMU_iommu_enable_enable_SHIFT 0
#define IOMMU_iommu_bypass (IOMMU + 0x30) // IOMMU Bypass Register ()
#define IOMMU_iommu_bypass_OFFSET 0x30
#define IOMMU_iommu_bypass_RESET 0x0000007F
#define IOMMU_iommu_bypass_m0_bp 0x1
#define IOMMU_iommu_bypass_m0_bp_SHIFT 0
#define IOMMU_iommu_auto_gating (IOMMU + 0x40) // IOMMU Auto Gating Register ()
#define IOMMU_iommu_auto_gating_OFFSET 0x40
#define IOMMU_iommu_auto_gating_RESET 0x00000001
#define IOMMU_iommu_auto_gating_iommu_auto_gating 0x1
#define IOMMU_iommu_auto_gating_iommu_auto_gating_SHIFT 0
#define IOMMU_iommu_wbuf_ctrl (IOMMU + 0x44) // IOMMU Write Buffer Control Register ()
#define IOMMU_iommu_wbuf_ctrl_OFFSET 0x44
#define IOMMU_iommu_wbuf_ctrl_RESET 0x0000007F
#define IOMMU_iommu_ooo_ctrl (IOMMU + 0x48) // IOMMU Out of Order Control Register ()
#define IOMMU_iommu_ooo_ctrl_OFFSET 0x48
#define IOMMU_iommu_ooo_ctrl_RESET 0x0000007F
#define IOMMU_iommu_ooo_ctrl_m0_ooo_ctrl 0x1
#define IOMMU_iommu_ooo_ctrl_m0_ooo_ctrl_SHIFT 0
#define IOMMU_iommu_4kb_bdy_prt_ctrl (IOMMU + 0x4c) // IOMMU 4KB Boundary Protect Control Register ()
#define IOMMU_iommu_4kb_bdy_prt_ctrl_OFFSET 0x4c
#define IOMMU_iommu_4kb_bdy_prt_ctrl_RESET 0x0000007F
#define IOMMU_iommu_4kb_bdy_prt_ctrl_m0_4kb_bdy_prt_ctrl 0x1
#define IOMMU_iommu_4kb_bdy_prt_ctrl_m0_4kb_bdy_prt_ctrl_SHIFT 0
#define IOMMU_iommu_ttb (IOMMU + 0x50) // IOMMU Translation Table Base Register ()
#define IOMMU_iommu_ttb_OFFSET 0x50
#define IOMMU_iommu_ttb_ttb (0x3ffff << 14)
#define IOMMU_iommu_ttb_ttb_SHIFT 14
#define IOMMU_iommu_tlb_enable (IOMMU + 0x60) // IOMMU TLB Enable Register ()
#define IOMMU_iommu_tlb_enable_OFFSET 0x60
#define IOMMU_iommu_tlb_enable_RESET 0x0003007F
#define IOMMU_iommu_tlb_enable_ptw_cache_enable (0x1 << 17)
#define IOMMU_iommu_tlb_enable_ptw_cache_enable_SHIFT 17
#define IOMMU_iommu_tlb_enable_macro_tlb_enable (0x1 << 16)
#define IOMMU_iommu_tlb_enable_macro_tlb_enable_SHIFT 16
#define IOMMU_iommu_tlb_enable_micro_tlb0_enable 0x1
#define IOMMU_iommu_tlb_enable_micro_tlb0_enable_SHIFT 0
#define IOMMU_iommu_tlb_prefetch (IOMMU + 0x70) // IOMMU TLB Prefetch Register ()
#define IOMMU_iommu_tlb_prefetch_OFFSET 0x70
#define IOMMU_iommu_tlb_prefetch_RESET 0x00030000
#define IOMMU_iommu_tlb_prefetch_pf_vl_pt_to_pc (0x1 << 17)
#define IOMMU_iommu_tlb_prefetch_pf_vl_pt_to_pc_SHIFT 17
#define IOMMU_iommu_tlb_prefetch_pf_vl_pt_to_mt (0x1 << 16)
#define IOMMU_iommu_tlb_prefetch_pf_vl_pt_to_mt_SHIFT 16
#define IOMMU_iommu_tlb_prefetch_mi_tlb0_pf 0x1
#define IOMMU_iommu_tlb_prefetch_mi_tlb0_pf_SHIFT 0
#define IOMMU_iommu_tlb_flush_enable (IOMMU + 0x80) // IOMMU TLB Flush Enable Register ()
#define IOMMU_iommu_tlb_flush_enable_OFFSET 0x80
#define IOMMU_iommu_tlb_flush_enable_pc_fs (0x1 << 17)
#define IOMMU_iommu_tlb_flush_enable_pc_fs_SHIFT 17
#define IOMMU_iommu_tlb_flush_enable_ma_tlb_fs (0x1 << 16)
#define IOMMU_iommu_tlb_flush_enable_ma_tlb_fs_SHIFT 16
#define IOMMU_iommu_tlb_flush_enable_mi_tlb0_fs 0x1
#define IOMMU_iommu_tlb_flush_enable_mi_tlb0_fs_SHIFT 0
#define IOMMU_iommu_tlb_ivld_mode_sel (IOMMU + 0x84) // IOMMU TLB Invalidation Mode Select Register ()
#define IOMMU_iommu_tlb_ivld_mode_sel_OFFSET 0x84
#define IOMMU_iommu_tlb_ivld_mode_sel_tlb_ivld_mode_sel 0x1
#define IOMMU_iommu_tlb_ivld_mode_sel_tlb_ivld_mode_sel_SHIFT 0
#define IOMMU_iommu_tlb_ivld_sta_addr (IOMMU + 0x88) // IOMMU TLB Invalidation Start Address Register ()
#define IOMMU_iommu_tlb_ivld_sta_addr_OFFSET 0x88
#define IOMMU_iommu_tlb_ivld_sta_addr_tlb_ivld_sta_addr (0xfffff << 12)
#define IOMMU_iommu_tlb_ivld_sta_addr_tlb_ivld_sta_addr_SHIFT 12
#define IOMMU_iommu_tlb_ivld_end_addr (IOMMU + 0x8c) // IOMMU TLB Invalidation End Address Register ()
#define IOMMU_iommu_tlb_ivld_end_addr_OFFSET 0x8c
#define IOMMU_iommu_tlb_ivld_end_addr_tlb_ivld_end_addr (0xfffff << 12)
#define IOMMU_iommu_tlb_ivld_end_addr_tlb_ivld_end_addr_SHIFT 12
#define IOMMU_iommu_tlb_ivld_addr (IOMMU + 0x90) // IOMMU TLB Invalidation Address Register ()
#define IOMMU_iommu_tlb_ivld_addr_OFFSET 0x90
#define IOMMU_iommu_tlb_ivld_addr_tlb_ivld_addr (0xfffff << 12)
#define IOMMU_iommu_tlb_ivld_addr_tlb_ivld_addr_SHIFT 12
#define IOMMU_iommu_tlb_ivld_addr_mask (IOMMU + 0x94) // IOMMU TLB Invalidation Address Mask Register ()
#define IOMMU_iommu_tlb_ivld_addr_mask_OFFSET 0x94
#define IOMMU_iommu_tlb_ivld_addr_mask_tlb_ivld_addr_mask (0xfffff << 12)
#define IOMMU_iommu_tlb_ivld_addr_mask_tlb_ivld_addr_mask_SHIFT 12
#define IOMMU_iommu_tlb_ivld_enable (IOMMU + 0x98) // IOMMU TLB Invalidation Enable Register ()
#define IOMMU_iommu_tlb_ivld_enable_OFFSET 0x98
#define IOMMU_iommu_tlb_ivld_enable_tlb_ivld_enable 0x1
#define IOMMU_iommu_tlb_ivld_enable_tlb_ivld_enable_SHIFT 0
#define IOMMU_iommu_pc_ivld_mode_sel (IOMMU + 0x9c) // IOMMU PC Invalidation Mode Select Register ()
#define IOMMU_iommu_pc_ivld_mode_sel_OFFSET 0x9c
#define IOMMU_iommu_pc_ivld_mode_sel_pc_ivld_mode_sel 0x1
#define IOMMU_iommu_pc_ivld_mode_sel_pc_ivld_mode_sel_SHIFT 0
#define IOMMU_iommu_pc_ivld_addr (IOMMU + 0xa0) // IOMMU PC Invalidation Address Register ()
#define IOMMU_iommu_pc_ivld_addr_OFFSET 0xa0
#define IOMMU_iommu_pc_ivld_addr_pc_ivld_addr (0xfff << 20)
#define IOMMU_iommu_pc_ivld_addr_pc_ivld_addr_SHIFT 20
#define IOMMU_iommu_pc_ivld_sta_addr (IOMMU + 0xa4) // IOMMU PC Invalidation Start Address Register ()
#define IOMMU_iommu_pc_ivld_sta_addr_OFFSET 0xa4
#define IOMMU_iommu_pc_ivld_sta_addr_pc_ivld_sa (0xfff << 20)
#define IOMMU_iommu_pc_ivld_sta_addr_pc_ivld_sa_SHIFT 20
#define IOMMU_iommu_pc_ivld_enable (IOMMU + 0xa8) // IOMMU PC Invalidation Enable Register ()
#define IOMMU_iommu_pc_ivld_enable_OFFSET 0xa8
#define IOMMU_iommu_pc_ivld_enable_pc_ivld_enable 0x1
#define IOMMU_iommu_pc_ivld_enable_pc_ivld_enable_SHIFT 0
#define IOMMU_iommu_pc_ivld_end_addr (IOMMU + 0xac) // IOMMU PC Invalidation End Address Register ()
#define IOMMU_iommu_pc_ivld_end_addr_OFFSET 0xac
#define IOMMU_iommu_pc_ivld_end_addr_pc_ivld_ea (0xfff << 20)
#define IOMMU_iommu_pc_ivld_end_addr_pc_ivld_ea_SHIFT 20
#define IOMMU_iommu_dm_aut_ctrl0 (IOMMU + 0xb0) // IOMMU Domain Authority Control i Register\n\nSoftware can set 15 different permission control types in IOMMU_DM_AUT_CTRL0-7. A default access control type is DOMAIN0. The read/write operation of DOMAIN1-15 is unlimited by default.\n\nSoftware needs to set the index of the permission control domain corresponding to the page table item in the bit7:4 of the Level2 page table, the default value is 0 (use domain 0), that is, the read/write operation is not controlled.\n\nSetting REG_ARD_OVWT can mask the Domain control defined by IOMMU_DM_AUT_CTRL0-7. All Level2 page table type are covered by the type of REG_ARD_OVWT. The read/write operation is permitted by default. ()
#define IOMMU_iommu_dm_aut_ctrl0_OFFSET 0xb0
#define IOMMU_iommu_dm_aut_ctrl0_dm1_m0_wt_aut_ctrl (0x1 << 17)
#define IOMMU_iommu_dm_aut_ctrl0_dm1_m0_wt_aut_ctrl_SHIFT 17
#define IOMMU_iommu_dm_aut_ctrl0_dm1_m0_rd_aut_ctrl (0x1 << 17)
#define IOMMU_iommu_dm_aut_ctrl0_dm1_m0_rd_aut_ctrl_SHIFT 17
#define IOMMU_iommu_dm_aut_ctrl0_dm0_m0_wt_aut_ctrl (0x1 << 17)
#define IOMMU_iommu_dm_aut_ctrl0_dm0_m0_wt_aut_ctrl_SHIFT 17
#define IOMMU_iommu_dm_aut_ctrl0_dm0_m0_rd_aut_ctrl (0x1 << 17)
#define IOMMU_iommu_dm_aut_ctrl0_dm0_m0_rd_aut_ctrl_SHIFT 17
#define IOMMU_iommu_dm_aut_ovwt (IOMMU + 0xd0) // IOMMU Domain Authority Overwrite Register ()
#define IOMMU_iommu_dm_aut_ovwt_OFFSET 0xd0
#define IOMMU_iommu_dm_aut_ovwt_dm_aut_ovwt_enable (0x1 << 31)
#define IOMMU_iommu_dm_aut_ovwt_dm_aut_ovwt_enable_SHIFT 31
#define IOMMU_iommu_dm_aut_ovwt_m0_wt_aut_ovwt_ctrl (0x1 << 1)
#define IOMMU_iommu_dm_aut_ovwt_m0_wt_aut_ovwt_ctrl_SHIFT 1
#define IOMMU_iommu_dm_aut_ovwt_m0_rd_aut_ovwt_ctrl 0x1
#define IOMMU_iommu_dm_aut_ovwt_m0_rd_aut_ovwt_ctrl_SHIFT 0
#define IOMMU_iommu_int_enable (IOMMU + 0x100) // IOMMU Interrupt Enable Register ()
#define IOMMU_iommu_int_enable_OFFSET 0x100
#define IOMMU_iommu_int_enable_dbg_pf_l2_iv_pt_en (0x1 << 20)
#define IOMMU_iommu_int_enable_dbg_pf_l2_iv_pt_en_SHIFT 20
#define IOMMU_iommu_int_enable_dbg_pf_pc_iv_l1_pt_en (0x1 << 19)
#define IOMMU_iommu_int_enable_dbg_pf_pc_iv_l1_pt_en_SHIFT 19
#define IOMMU_iommu_int_enable_dbg_pf_dram_iv_l1_pt_en (0x1 << 18)
#define IOMMU_iommu_int_enable_dbg_pf_dram_iv_l1_pt_en_SHIFT 18
#define IOMMU_iommu_int_enable_l0_page_table_invalid_en (0x1 << 16)
#define IOMMU_iommu_int_enable_l0_page_table_invalid_en_SHIFT 16
#define IOMMU_iommu_int_enable_micro_tlb0_invalid_en 0x1
#define IOMMU_iommu_int_enable_micro_tlb0_invalid_en_SHIFT 0
#define IOMMU_iommu_int_clr (IOMMU + 0x104) // IOMMU Interrupt Clear Register ()
#define IOMMU_iommu_int_clr_OFFSET 0x104
#define IOMMU_iommu_int_clr_l0_page_table_invalid_clr (0x1 << 16)
#define IOMMU_iommu_int_clr_l0_page_table_invalid_clr_SHIFT 16
#define IOMMU_iommu_int_clr_micro_tlb0_invalid_clr 0x1
#define IOMMU_iommu_int_clr_micro_tlb0_invalid_clr_SHIFT 0
#define IOMMU_iommu_int_sta (IOMMU + 0x108) // IOMMU Interrupt Status Register ()
#define IOMMU_iommu_int_sta_OFFSET 0x108
#define IOMMU_iommu_int_sta_l0_page_table_invalid_sta (0x1 << 16)
#define IOMMU_iommu_int_sta_l0_page_table_invalid_sta_SHIFT 16
#define IOMMU_iommu_int_sta_micro_tlb0_invalid_sta 0x1
#define IOMMU_iommu_int_sta_micro_tlb0_invalid_sta_SHIFT 0
#define IOMMU_iommu_int_err_addr_tlb0 (IOMMU + 0x110) // IOMMU Interrupt Error Address i (R only)
#define IOMMU_iommu_int_err_addr_tlb0_OFFSET 0x110
#define IOMMU_iommu_int_err_addr_tlb0_int_err_addr 0xffffffff
#define IOMMU_iommu_int_err_addr_tlb0_int_err_addr_SHIFT 0
#define IOMMU_iommu_int_err_addr_l0 (IOMMU + 0x130) // IOMMU Interrupt Error Address Li (R only)
#define IOMMU_iommu_int_err_addr_l0_OFFSET 0x130
#define IOMMU_iommu_int_err_addr_l0_int_err_addr 0xffffffff
#define IOMMU_iommu_int_err_addr_l0_int_err_addr_SHIFT 0
#define IOMMU_iommu_int_err_data_tlb0 (IOMMU + 0x150) // IOMMU Interrupt Error Data i Register (R only)
#define IOMMU_iommu_int_err_data_tlb0_OFFSET 0x150
#define IOMMU_iommu_int_err_data_tlb0_int_err_data 0xffffffff
#define IOMMU_iommu_int_err_data_tlb0_int_err_data_SHIFT 0
#define IOMMU_iommu_int_err_data_l0 (IOMMU + 0x170) // IOMMU Interrupt Error Data Li Register (R only)
#define IOMMU_iommu_int_err_data_l0_OFFSET 0x170
#define IOMMU_iommu_int_err_data_l0_int_err_data 0xffffffff
#define IOMMU_iommu_int_err_data_l0_int_err_data_SHIFT 0
#define IOMMU_iommu_l0pg_int (IOMMU + 0x180) // IOMMU Li Page Table Interrupt Register (R only)
#define IOMMU_iommu_l0pg_int_OFFSET 0x180
#define IOMMU_iommu_l0pg_int_dbg_mode_int (0x1 << 31)
#define IOMMU_iommu_l0pg_int_dbg_mode_int_SHIFT 31
#define IOMMU_iommu_l0pg_int_master0_int 0x1
#define IOMMU_iommu_l0pg_int_master0_int_SHIFT 0
#define IOMMU_iommu_va (IOMMU + 0x190) // IOMMU Virtual Address Register ()
#define IOMMU_iommu_va_OFFSET 0x190
#define IOMMU_iommu_va_va 0xffffffff
#define IOMMU_iommu_va_va_SHIFT 0
#define IOMMU_iommu_va_data (IOMMU + 0x194) // IOMMU Virtual Address Data Register ()
#define IOMMU_iommu_va_data_OFFSET 0x194
#define IOMMU_iommu_va_data_va_data 0xffffffff
#define IOMMU_iommu_va_data_va_data_SHIFT 0
#define IOMMU_iommu_va_config (IOMMU + 0x198) // IOMMU Virtual Address Configuration Register ()
#define IOMMU_iommu_va_config_OFFSET 0x198
#define IOMMU_iommu_va_config_mode_sel (0x1 << 31)
#define IOMMU_iommu_va_config_mode_sel_SHIFT 31
#define IOMMU_iommu_va_config_va_config (0x1 << 8)
#define IOMMU_iommu_va_config_va_config_SHIFT 8
#define IOMMU_iommu_va_config_va_config_start 0x1
#define IOMMU_iommu_va_config_va_config_start_SHIFT 0
#define IOMMU_iommu_pmu_enable (IOMMU + 0x200) // IOMMU PMU Enable Register ()
#define IOMMU_iommu_pmu_enable_OFFSET 0x200
#define IOMMU_iommu_pmu_enable_pmu_enable 0x1
#define IOMMU_iommu_pmu_enable_pmu_enable_SHIFT 0
#define IOMMU_iommu_pmu_clr (IOMMU + 0x210) // IOMMU PMU Clear Register ()
#define IOMMU_iommu_pmu_clr_OFFSET 0x210
#define IOMMU_iommu_pmu_clr_pmu_clr 0x1
#define IOMMU_iommu_pmu_clr_pmu_clr_SHIFT 0
#define IOMMU_iommu_pmu_access_low0 (IOMMU + 0x230) // IOMMU PMU Access Low i Register ()
#define IOMMU_iommu_pmu_access_low0_OFFSET 0x230
#define IOMMU_iommu_pmu_access_high0 (IOMMU + 0x234) // IOMMU PMU Access High i Register ()
#define IOMMU_iommu_pmu_access_high0_OFFSET 0x234
#define IOMMU_iommu_pmu_hit_low0 (IOMMU + 0x238) // IOMMU PMU Hit Low i Register ()
#define IOMMU_iommu_pmu_hit_low0_OFFSET 0x238
#define IOMMU_iommu_pmu_hit_high0 (IOMMU + 0x23c) // IOMMU PMU Hit High i Register ()
#define IOMMU_iommu_pmu_hit_high0_OFFSET 0x23c
#define IOMMU_iommu_pmu_tl_low0 (IOMMU + 0x300) // IOMMU Total Latency Low i Register ()
#define IOMMU_iommu_pmu_tl_low0_OFFSET 0x300
#define IOMMU_iommu_pmu_tl_high0 (IOMMU + 0x304) // IOMMU Total Latency High i Register ()
#define IOMMU_iommu_pmu_tl_high0_OFFSET 0x304
#define IOMMU_iommu_pmu_ml0 (IOMMU + 0x308) // IOMMU Max Latency i Register ()
#define IOMMU_iommu_pmu_ml0_OFFSET 0x308

/****************************************************************
 * DSP Message Box
 ****************************************************************/
#define DSP_MSGBOX 0x01701000

/****************************************************************
 * DSP Message Box (derived from DSP_MSGBOX)
 ****************************************************************/
#define RV_MSGBOX 0x0601f000

/****************************************************************
 * Spinlock
 ****************************************************************/
#define SPINLOCK 0x03005000
#define SPINLOCK_spinlock_systatus (SPINLOCK + 0x0) // Spinlock System Status Register (R only)
#define SPINLOCK_spinlock_systatus_OFFSET 0x0
#define SPINLOCK_spinlock_systatus_locks_num (0x3 << 28)
#define SPINLOCK_spinlock_systatus_locks_num_SHIFT 28
#define SPINLOCK_spinlock_systatus_iu0 (0x1 << 8)
#define SPINLOCK_spinlock_systatus_iu0_SHIFT 8
#define SPINLOCK_spinlock_status (SPINLOCK + 0x10) // Spinlock Status Register (R only)
#define SPINLOCK_spinlock_status_OFFSET 0x10
#define SPINLOCK_spinlock_status_lock0_status 0x1
#define SPINLOCK_spinlock_status_lock0_status_SHIFT 0
#define SPINLOCK_spinlock_irq_en (SPINLOCK + 0x20) // Spinlock Interrupt Enable Register ()
#define SPINLOCK_spinlock_irq_en_OFFSET 0x20
#define SPINLOCK_spinlock_irq_en_lock0_irq_en 0x1
#define SPINLOCK_spinlock_irq_en_lock0_irq_en_SHIFT 0
#define SPINLOCK_spinlock_irq_sta (SPINLOCK + 0x40) // Spinlock Interrupt Status Register ()
#define SPINLOCK_spinlock_irq_sta_OFFSET 0x40
#define SPINLOCK_spinlock_irq_sta_lock0_irq_status 0x1
#define SPINLOCK_spinlock_irq_sta_lock0_irq_status_SHIFT 0
#define SPINLOCK_spinlock_lockid0 (SPINLOCK + 0x80) // Spinlock Lockid Register (R only)
#define SPINLOCK_spinlock_lockid0_OFFSET 0x80
#define SPINLOCK_spinlock_lock0 (SPINLOCK + 0x100) // Spinlock Register ()
#define SPINLOCK_spinlock_lock0_OFFSET 0x100
#define SPINLOCK_spinlock_lock0_taken 0x1
#define SPINLOCK_spinlock_lock0_taken_SHIFT 0

/****************************************************************
 * Real Time CLock
 ****************************************************************/
#define RTC 0x07090000
#define RTC_losc_ctrl (RTC + 0x0) // Low Oscillator Control Register ()
#define RTC_losc_ctrl_OFFSET 0x0
#define RTC_losc_ctrl_RESET 0x00004010
#define RTC_losc_ctrl_key_field (0xffff << 16)
#define RTC_losc_ctrl_key_field_SHIFT 16
#define RTC_losc_ctrl_losc_auto_swt_function (0x1 << 15)
#define RTC_losc_ctrl_losc_auto_swt_function_SHIFT 15
#define RTC_losc_ctrl_losc_auto_swt_32k_sel_en (0x1 << 14)
#define RTC_losc_ctrl_losc_auto_swt_32k_sel_en_SHIFT 14
#define RTC_losc_ctrl_rtc_hhmmss_acce (0x1 << 8)
#define RTC_losc_ctrl_rtc_hhmmss_acce_SHIFT 8
#define RTC_losc_ctrl_rtc_day_acce (0x1 << 7)
#define RTC_losc_ctrl_rtc_day_acce_SHIFT 7
#define RTC_losc_ctrl_ext_losc_en (0x1 << 4)
#define RTC_losc_ctrl_ext_losc_en_SHIFT 4
#define RTC_losc_ctrl_ext_losc_gsm (0x3 << 2)
#define RTC_losc_ctrl_ext_losc_gsm_SHIFT 2
#define RTC_losc_ctrl_rtc_src_sel (0x1 << 1)
#define RTC_losc_ctrl_rtc_src_sel_SHIFT 1
#define RTC_losc_ctrl_losc_src_sel 0x1
#define RTC_losc_ctrl_losc_src_sel_SHIFT 0
#define RTC_losc_auto_swt_sta (RTC + 0x4) // LOSC Auto Switch Status Register ()
#define RTC_losc_auto_swt_sta_OFFSET 0x4
#define RTC_losc_auto_swt_sta_ext_losc_sta (0x1 << 2)
#define RTC_losc_auto_swt_sta_ext_losc_sta_SHIFT 2
#define RTC_losc_auto_swt_sta_losc_auto_swt_pend (0x1 << 1)
#define RTC_losc_auto_swt_sta_losc_auto_swt_pend_SHIFT 1
#define RTC_losc_auto_swt_sta_losc_src_sel_sta 0x1
#define RTC_losc_auto_swt_sta_losc_src_sel_sta_SHIFT 0
#define RTC_intosc_clk_prescal (RTC + 0x8) // Internal OSC Clock Pre-scalar Register ()
#define RTC_intosc_clk_prescal_OFFSET 0x8
#define RTC_intosc_clk_prescal_RESET 0x0000000F
#define RTC_intosc_clk_prescal_intosc_32k_clk_prescal 0x1f
#define RTC_intosc_clk_prescal_intosc_32k_clk_prescal_SHIFT 0
#define RTC_rtc_day (RTC + 0x10) // RTC Year-Month-Day Register ()
#define RTC_rtc_day_OFFSET 0x10
#define RTC_rtc_day_day 0xffff
#define RTC_rtc_day_day_SHIFT 0
#define RTC_rtc_hh_mm_ss (RTC + 0x14) // RTC Hour-Minute-Second Register ()
#define RTC_rtc_hh_mm_ss_OFFSET 0x14
#define RTC_rtc_hh_mm_ss_hour (0x1f << 16)
#define RTC_rtc_hh_mm_ss_hour_SHIFT 16
#define RTC_rtc_hh_mm_ss_minute (0x3f << 8)
#define RTC_rtc_hh_mm_ss_minute_SHIFT 8
#define RTC_rtc_hh_mm_ss_second 0x3f
#define RTC_rtc_hh_mm_ss_second_SHIFT 0
#define RTC_alarm0_day_set (RTC + 0x20) // Alarm 0 Day Setting Register ()
#define RTC_alarm0_day_set_OFFSET 0x20
#define RTC_alarm0_day_set_alarm0_counter 0xffff
#define RTC_alarm0_day_set_alarm0_counter_SHIFT 0
#define RTC_alarm0_cur_vlu (RTC + 0x24) // Alarm 0 Counter Current Value Register ()
#define RTC_alarm0_cur_vlu_OFFSET 0x24
#define RTC_alarm0_cur_vlu_hour (0x1f << 16)
#define RTC_alarm0_cur_vlu_hour_SHIFT 16
#define RTC_alarm0_cur_vlu_minute (0x3f << 8)
#define RTC_alarm0_cur_vlu_minute_SHIFT 8
#define RTC_alarm0_cur_vlu_second 0x3f
#define RTC_alarm0_cur_vlu_second_SHIFT 0
#define RTC_alarm0_enable (RTC + 0x28) // Alarm 0 Enable Register ()
#define RTC_alarm0_enable_OFFSET 0x28
#define RTC_alarm0_enable_alm_0_en 0x1
#define RTC_alarm0_enable_alm_0_en_SHIFT 0
#define RTC_alarm0_irq_en (RTC + 0x2c) // Alarm 0 IRQ Enable Register ()
#define RTC_alarm0_irq_en_OFFSET 0x2c
#define RTC_alarm0_irq_en_alarm0_irq_en 0x1
#define RTC_alarm0_irq_en_alarm0_irq_en_SHIFT 0
#define RTC_alarm0_irq_sta (RTC + 0x30) // Alarm 0 IRQ Status Register ()
#define RTC_alarm0_irq_sta_OFFSET 0x30
#define RTC_alarm0_irq_sta_alarm0_irq_pend 0x1
#define RTC_alarm0_irq_sta_alarm0_irq_pend_SHIFT 0
#define RTC_alarm_config (RTC + 0x50) // Alarm Configuration Register ()
#define RTC_alarm_config_OFFSET 0x50
#define RTC_alarm_config_alarm_wakeup 0x1
#define RTC_alarm_config_alarm_wakeup_SHIFT 0
#define RTC_fout_32k_ctrl_gating (RTC + 0x60) // 32K Fanout Control Gating Register ()
#define RTC_fout_32k_ctrl_gating_OFFSET 0x60
#define RTC_fout_32k_ctrl_gating_hosc_to_32k_divider_enable (0x1 << 16)
#define RTC_fout_32k_ctrl_gating_hosc_to_32k_divider_enable_SHIFT 16
#define RTC_fout_32k_ctrl_gating_losc_out_src_sel (0x3 << 1)
#define RTC_fout_32k_ctrl_gating_losc_out_src_sel_SHIFT 1
#define RTC_fout_32k_ctrl_gating_fanout_32k_gating 0x1
#define RTC_fout_32k_ctrl_gating_fanout_32k_gating_SHIFT 0
#define RTC_gp_data0 (RTC + 0x100) // General Purpose Register ()
#define RTC_gp_data0_OFFSET 0x100
#define RTC_gp_data0_gp_data 0xffffffff
#define RTC_gp_data0_gp_data_SHIFT 0
#define RTC_fboot_info0 (RTC + 0x120) // Fast Boot Information Register 01 ()
#define RTC_fboot_info0_OFFSET 0x120
#define RTC_fboot_info0_fboot_info 0xffffffff
#define RTC_fboot_info0_fboot_info_SHIFT 0
#define RTC_dcxo_ctrl (RTC + 0x160) // DCXO Control Register ()
#define RTC_dcxo_ctrl_OFFSET 0x160
#define RTC_dcxo_ctrl_RESET 0x883F10F7
#define RTC_dcxo_ctrl_clk_req_enb (0x1 << 31)
#define RTC_dcxo_ctrl_clk_req_enb_SHIFT 31
#define RTC_dcxo_ctrl_dcxo_ictrl (0xf << 24)
#define RTC_dcxo_ctrl_dcxo_ictrl_SHIFT 24
#define RTC_dcxo_ctrl_dcxo_trim (0x7f << 16)
#define RTC_dcxo_ctrl_dcxo_trim_SHIFT 16
#define RTC_dcxo_ctrl_dcxo_bg (0x1f << 8)
#define RTC_dcxo_ctrl_dcxo_bg_SHIFT 8
#define RTC_dcxo_ctrl_dcxo_ldo_inrushb (0x1 << 7)
#define RTC_dcxo_ctrl_dcxo_ldo_inrushb_SHIFT 7
#define RTC_dcxo_ctrl_xtal_mode (0x1 << 6)
#define RTC_dcxo_ctrl_xtal_mode_SHIFT 6
#define RTC_dcxo_ctrl_dcxo_rfclk_enhance (0x3 << 4)
#define RTC_dcxo_ctrl_dcxo_rfclk_enhance_SHIFT 4
#define RTC_dcxo_ctrl_rsto_dly_sel (0x1 << 2)
#define RTC_dcxo_ctrl_rsto_dly_sel_SHIFT 2
#define RTC_dcxo_ctrl_dcxo_en (0x1 << 1)
#define RTC_dcxo_ctrl_dcxo_en_SHIFT 1
#define RTC_dcxo_ctrl_clk16m_rc_en 0x1
#define RTC_dcxo_ctrl_clk16m_rc_en_SHIFT 0
#define RTC_rtc_vio (RTC + 0x190) // RTC_VIO Regulation Register ()
#define RTC_rtc_vio_OFFSET 0x190
#define RTC_rtc_vio_RESET 0x00000004
#define RTC_rtc_vio_v_sel (0x1 << 4)
#define RTC_rtc_vio_v_sel_SHIFT 4
#define RTC_rtc_vio_rtc_viou 0x7
#define RTC_rtc_vio_rtc_viou_SHIFT 0
#define RTC_ic_chara (RTC + 0x1f0) // IC Characteristic Register ()
#define RTC_ic_chara_OFFSET 0x1f0
#define RTC_ic_chara_key_field (0xffff << 16)
#define RTC_ic_chara_key_field_SHIFT 16
#define RTC_ic_chara_id_data 0xffff
#define RTC_ic_chara_id_data_SHIFT 0
#define RTC_vdd_off_gating_ctrl (RTC + 0x1f4) // VDD Off Gating Control Register ()
#define RTC_vdd_off_gating_ctrl_OFFSET 0x1f4
#define RTC_vdd_off_gating_ctrl_RESET 0x00000021
#define RTC_vdd_off_gating_ctrl_key_field (0xffff << 16)
#define RTC_vdd_off_gating_ctrl_key_field_SHIFT 16
#define RTC_vdd_off_gating_ctrl_pwroff_gat_rtc_cfg (0x1 << 15)
#define RTC_vdd_off_gating_ctrl_pwroff_gat_rtc_cfg_SHIFT 15
#define RTC_vdd_off_gating_ctrl_vccio_det_spare (0xff << 4)
#define RTC_vdd_off_gating_ctrl_vccio_det_spare_SHIFT 4
#define RTC_vdd_off_gating_ctrl_vccio_det_bypass_en 0x1
#define RTC_vdd_off_gating_ctrl_vccio_det_bypass_en_SHIFT 0
#define RTC_efuse_hv_pwrswt_ctrl (RTC + 0x204) // Efuse High Voltage Power Switch Control Register ()
#define RTC_efuse_hv_pwrswt_ctrl_OFFSET 0x204
#define RTC_efuse_hv_pwrswt_ctrl_efuse_1_8v_power_switch_control 0x1
#define RTC_efuse_hv_pwrswt_ctrl_efuse_1_8v_power_switch_control_SHIFT 0
#define RTC_rtc_spi_clk_ctrl (RTC + 0x310) // RTC SPI Clock Control Register ()
#define RTC_rtc_spi_clk_ctrl_OFFSET 0x310
#define RTC_rtc_spi_clk_ctrl_RESET 0x00000009
#define RTC_rtc_spi_clk_ctrl_rtc_spi_clk_gating (0x1 << 31)
#define RTC_rtc_spi_clk_ctrl_rtc_spi_clk_gating_SHIFT 31
#define RTC_rtc_spi_clk_ctrl_rtc_spi_clk_div 0x1f
#define RTC_rtc_spi_clk_ctrl_rtc_spi_clk_div_SHIFT 0

/****************************************************************
 * Timing COntroller LCD
 ****************************************************************/
#define TCON_LCD0 0x05461000
#define TCON_LCD0_lcd_gctl (TCON_LCD0 + 0x0) // LCD Global Control Register ()
#define TCON_LCD0_lcd_gctl_OFFSET 0x0
#define TCON_LCD0_lcd_gctl_lcd_en (0x1 << 31)
#define TCON_LCD0_lcd_gctl_lcd_en_SHIFT 31
#define TCON_LCD0_lcd_gctl_lcd_gamma_en (0x1 << 30)
#define TCON_LCD0_lcd_gctl_lcd_gamma_en_SHIFT 30
#define TCON_LCD0_lcd_gint0 (TCON_LCD0 + 0x4) // LCD Global Interrupt Register0 ()
#define TCON_LCD0_lcd_gint0_OFFSET 0x4
#define TCON_LCD0_lcd_gint0_lcd_vb_int_en (0x1 << 31)
#define TCON_LCD0_lcd_gint0_lcd_vb_int_en_SHIFT 31
#define TCON_LCD0_lcd_gint0_lcd_line_int_en (0x1 << 29)
#define TCON_LCD0_lcd_gint0_lcd_line_int_en_SHIFT 29
#define TCON_LCD0_lcd_gint0_lcd_tri_finish_int_en (0x1 << 27)
#define TCON_LCD0_lcd_gint0_lcd_tri_finish_int_en_SHIFT 27
#define TCON_LCD0_lcd_gint0_lcd_tri_counter_int_en (0x1 << 26)
#define TCON_LCD0_lcd_gint0_lcd_tri_counter_int_en_SHIFT 26
#define TCON_LCD0_lcd_gint0_lcd_vb_int_flag (0x1 << 15)
#define TCON_LCD0_lcd_gint0_lcd_vb_int_flag_SHIFT 15
#define TCON_LCD0_lcd_gint0_lcd_line_int_flag (0x1 << 13)
#define TCON_LCD0_lcd_gint0_lcd_line_int_flag_SHIFT 13
#define TCON_LCD0_lcd_gint0_lcd_tri_finish_int_flag (0x1 << 11)
#define TCON_LCD0_lcd_gint0_lcd_tri_finish_int_flag_SHIFT 11
#define TCON_LCD0_lcd_gint0_lcd_tri_counter_int_flag (0x1 << 10)
#define TCON_LCD0_lcd_gint0_lcd_tri_counter_int_flag_SHIFT 10
#define TCON_LCD0_lcd_gint0_lcd_tri_underflow_flag (0x1 << 9)
#define TCON_LCD0_lcd_gint0_lcd_tri_underflow_flag_SHIFT 9
#define TCON_LCD0_lcd_gint0_fsync_int_inv (0x1 << 2)
#define TCON_LCD0_lcd_gint0_fsync_int_inv_SHIFT 2
#define TCON_LCD0_lcd_gint0_de_int_flag (0x1 << 1)
#define TCON_LCD0_lcd_gint0_de_int_flag_SHIFT 1
#define TCON_LCD0_lcd_gint0_fsync_int_flag 0x1
#define TCON_LCD0_lcd_gint0_fsync_int_flag_SHIFT 0
#define TCON_LCD0_lcd_gint1 (TCON_LCD0 + 0x8) // LCD Global Interrupt Register1 ()
#define TCON_LCD0_lcd_gint1_OFFSET 0x8
#define TCON_LCD0_lcd_gint1_lcd_line_int_num (0xfff << 16)
#define TCON_LCD0_lcd_gint1_lcd_line_int_num_SHIFT 16
#define TCON_LCD0_lcd_frm_ctl (TCON_LCD0 + 0x10) // LCD FRM Control Register ()
#define TCON_LCD0_lcd_frm_ctl_OFFSET 0x10
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_en (0x1 << 31)
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_en_SHIFT 31
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_mode_r (0x1 << 6)
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_mode_r_SHIFT 6
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_mode_g (0x1 << 5)
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_mode_g_SHIFT 5
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_mode_b (0x1 << 4)
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_mode_b_SHIFT 4
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_test 0x3
#define TCON_LCD0_lcd_frm_ctl_lcd_frm_test_SHIFT 0
#define TCON_LCD0_lcd_frm_seed0 (TCON_LCD0 + 0x14) // LCD FRM Seed Register ()
#define TCON_LCD0_lcd_frm_seed0_OFFSET 0x14
#define TCON_LCD0_lcd_frm_seed0_seed_value 0x1ffffff
#define TCON_LCD0_lcd_frm_seed0_seed_value_SHIFT 0
#define TCON_LCD0_lcd_frm_tab0 (TCON_LCD0 + 0x2c) // LCD FRM Table Register ()
#define TCON_LCD0_lcd_frm_tab0_OFFSET 0x2c
#define TCON_LCD0_lcd_frm_tab0_frm_table_value 0xffffffff
#define TCON_LCD0_lcd_frm_tab0_frm_table_value_SHIFT 0
#define TCON_LCD0_lcd_3d_fifo (TCON_LCD0 + 0x3c) // LCD 3D FIFO Register ()
#define TCON_LCD0_lcd_3d_fifo_OFFSET 0x3c
#define TCON_LCD0_lcd_3d_fifo_bist_en (0x1 << 31)
#define TCON_LCD0_lcd_3d_fifo_bist_en_SHIFT 31
#define TCON_LCD0_lcd_3d_fifo_half_line_size (0x3ff << 4)
#define TCON_LCD0_lcd_3d_fifo_half_line_size_SHIFT 4
#define TCON_LCD0_lcd_3d_fifo_setting 0x3
#define TCON_LCD0_lcd_3d_fifo_setting_SHIFT 0
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
#define TCON_LCD0_lcd_dclk (TCON_LCD0 + 0x44) // LCD Data Clock Register ()
#define TCON_LCD0_lcd_dclk_OFFSET 0x44
#define TCON_LCD0_lcd_dclk_lcd_dclk_en (0xf << 28)
#define TCON_LCD0_lcd_dclk_lcd_dclk_en_SHIFT 28
#define TCON_LCD0_lcd_dclk_lcd_dclk_div 0x7f
#define TCON_LCD0_lcd_dclk_lcd_dclk_div_SHIFT 0
#define TCON_LCD0_lcd_basic0 (TCON_LCD0 + 0x48) // LCD Basic Timing Register0 ()
#define TCON_LCD0_lcd_basic0_OFFSET 0x48
#define TCON_LCD0_lcd_basic0_width_x (0xfff << 16)
#define TCON_LCD0_lcd_basic0_width_x_SHIFT 16
#define TCON_LCD0_lcd_basic0_height_y 0xfff
#define TCON_LCD0_lcd_basic0_height_y_SHIFT 0
#define TCON_LCD0_lcd_basic1 (TCON_LCD0 + 0x4c) // LCD Basic Timing Register1 ()
#define TCON_LCD0_lcd_basic1_OFFSET 0x4c
#define TCON_LCD0_lcd_basic1_ht (0x1fff << 16)
#define TCON_LCD0_lcd_basic1_ht_SHIFT 16
#define TCON_LCD0_lcd_basic1_hbp 0xfff
#define TCON_LCD0_lcd_basic1_hbp_SHIFT 0
#define TCON_LCD0_lcd_basic2 (TCON_LCD0 + 0x50) // LCD Basic Timing Register2 ()
#define TCON_LCD0_lcd_basic2_OFFSET 0x50
#define TCON_LCD0_lcd_basic2_vt (0x1fff << 16)
#define TCON_LCD0_lcd_basic2_vt_SHIFT 16
#define TCON_LCD0_lcd_basic2_vbp 0xfff
#define TCON_LCD0_lcd_basic2_vbp_SHIFT 0
#define TCON_LCD0_lcd_basic3 (TCON_LCD0 + 0x54) // LCD Basic Timing Register3 ()
#define TCON_LCD0_lcd_basic3_OFFSET 0x54
#define TCON_LCD0_lcd_basic3_hspw (0x3ff << 16)
#define TCON_LCD0_lcd_basic3_hspw_SHIFT 16
#define TCON_LCD0_lcd_basic3_vspw 0x3ff
#define TCON_LCD0_lcd_basic3_vspw_SHIFT 0
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
#define TCON_LCD0_lcd_cpu_if (TCON_LCD0 + 0x60) // LCD CPU Panel Interface Register ()
#define TCON_LCD0_lcd_cpu_if_OFFSET 0x60
#define TCON_LCD0_lcd_cpu_if_cpu_mode (0xf << 28)
#define TCON_LCD0_lcd_cpu_if_cpu_mode_SHIFT 28
#define TCON_LCD0_lcd_cpu_if_da (0x1 << 26)
#define TCON_LCD0_lcd_cpu_if_da_SHIFT 26
#define TCON_LCD0_lcd_cpu_if_ca (0x1 << 25)
#define TCON_LCD0_lcd_cpu_if_ca_SHIFT 25
#define TCON_LCD0_lcd_cpu_if_wr_flag (0x1 << 23)
#define TCON_LCD0_lcd_cpu_if_wr_flag_SHIFT 23
#define TCON_LCD0_lcd_cpu_if_rd_flag (0x1 << 22)
#define TCON_LCD0_lcd_cpu_if_rd_flag_SHIFT 22
#define TCON_LCD0_lcd_cpu_if_auto (0x1 << 17)
#define TCON_LCD0_lcd_cpu_if_auto_SHIFT 17
#define TCON_LCD0_lcd_cpu_if_flush (0x1 << 16)
#define TCON_LCD0_lcd_cpu_if_flush_SHIFT 16
#define TCON_LCD0_lcd_cpu_if_tri_fifo_bist_en (0x1 << 3)
#define TCON_LCD0_lcd_cpu_if_tri_fifo_bist_en_SHIFT 3
#define TCON_LCD0_lcd_cpu_if_tri_fifo_en (0x1 << 2)
#define TCON_LCD0_lcd_cpu_if_tri_fifo_en_SHIFT 2
#define TCON_LCD0_lcd_cpu_if_tri_start (0x1 << 1)
#define TCON_LCD0_lcd_cpu_if_tri_start_SHIFT 1
#define TCON_LCD0_lcd_cpu_if_tri_en 0x1
#define TCON_LCD0_lcd_cpu_if_tri_en_SHIFT 0
#define TCON_LCD0_lcd_cpu_wr (TCON_LCD0 + 0x64) // LCD CPU Panel Write Data Register ()
#define TCON_LCD0_lcd_cpu_wr_OFFSET 0x64
#define TCON_LCD0_lcd_cpu_wr_data_wr 0xffffff
#define TCON_LCD0_lcd_cpu_wr_data_wr_SHIFT 0
#define TCON_LCD0_lcd_cpu_rd0 (TCON_LCD0 + 0x68) // LCD CPU Panel Read Data Registeri ()
#define TCON_LCD0_lcd_cpu_rd0_OFFSET 0x68
#define TCON_LCD0_lcd_cpu_rd0_data_rd0 0xffffff
#define TCON_LCD0_lcd_cpu_rd0_data_rd0_SHIFT 0
#define TCON_LCD0_lcd_lvds_if (TCON_LCD0 + 0x84) // LCD LVDS Configure Register ()
#define TCON_LCD0_lcd_lvds_if_OFFSET 0x84
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_en (0x1 << 31)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_en_SHIFT 31
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_link (0x1 << 30)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_link_SHIFT 30
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_even_odd_dir (0x1 << 29)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_even_odd_dir_SHIFT 29
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_dir (0x1 << 28)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_dir_SHIFT 28
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_mode (0x1 << 27)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_mode_SHIFT 27
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_bitwidth (0x1 << 26)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_bitwidth_SHIFT 26
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_debug_en (0x1 << 25)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_debug_en_SHIFT 25
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_debug_mode (0x1 << 24)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_debug_mode_SHIFT 24
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_correct_mode (0x1 << 23)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_correct_mode_SHIFT 23
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_clk_sel (0x1 << 20)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_clk_sel_SHIFT 20
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_clk_pol (0x1 << 4)
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_clk_pol_SHIFT 4
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_data_pol 0xf
#define TCON_LCD0_lcd_lvds_if_lcd_lvds_data_pol_SHIFT 0
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
#define TCON_LCD0_lcd_io_tri (TCON_LCD0 + 0x8c) // LCD IO Control Register ()
#define TCON_LCD0_lcd_io_tri_OFFSET 0x8c
#define TCON_LCD0_lcd_io_tri_RESET 0x0FFFFFFF
#define TCON_LCD0_lcd_io_tri_rgb_endian (0x1 << 28)
#define TCON_LCD0_lcd_io_tri_rgb_endian_SHIFT 28
#define TCON_LCD0_lcd_io_tri_io0_output_tri_en (0x1 << 24)
#define TCON_LCD0_lcd_io_tri_io0_output_tri_en_SHIFT 24
#define TCON_LCD0_lcd_io_tri_data_output_tri_en 0xffffff
#define TCON_LCD0_lcd_io_tri_data_output_tri_en_SHIFT 0
#define TCON_LCD0_lcd_debug (TCON_LCD0 + 0xfc) // LCD Debug Register ()
#define TCON_LCD0_lcd_debug_OFFSET 0xfc
#define TCON_LCD0_lcd_debug_lcd_fifo_underflow (0x1 << 31)
#define TCON_LCD0_lcd_debug_lcd_fifo_underflow_SHIFT 31
#define TCON_LCD0_lcd_debug_lcd_field_pol (0x1 << 29)
#define TCON_LCD0_lcd_debug_lcd_field_pol_SHIFT 29
#define TCON_LCD0_lcd_debug_lcd_current_line (0xfff << 16)
#define TCON_LCD0_lcd_debug_lcd_current_line_SHIFT 16
#define TCON_LCD0_lcd_ceu_ctl (TCON_LCD0 + 0x100) // LCD CEU Control Register ()
#define TCON_LCD0_lcd_ceu_ctl_OFFSET 0x100
#define TCON_LCD0_lcd_ceu_ctl_ceu_en (0x1 << 31)
#define TCON_LCD0_lcd_ceu_ctl_ceu_en_SHIFT 31
#define TCON_LCD0_lcd_ceu_ctl_bt656_f_mask (0x1 << 30)
#define TCON_LCD0_lcd_ceu_ctl_bt656_f_mask_SHIFT 30
#define TCON_LCD0_lcd_ceu_ctl_bt656_f_mask_value (0x1 << 29)
#define TCON_LCD0_lcd_ceu_ctl_bt656_f_mask_value_SHIFT 29
#define TCON_LCD0_lcd_ceu_coef_mul0 (TCON_LCD0 + 0x110) // LCD CEU Coefficient Register0 ()
#define TCON_LCD0_lcd_ceu_coef_mul0_OFFSET 0x110
#define TCON_LCD0_lcd_ceu_coef_mul0_ceu_coef_mul_value 0x1fff
#define TCON_LCD0_lcd_ceu_coef_mul0_ceu_coef_mul_value_SHIFT 0
#define TCON_LCD0_lcd_ceu_coef_add0 (TCON_LCD0 + 0x11c) // LCD CEU Coefficient Register1 ()
#define TCON_LCD0_lcd_ceu_coef_add0_OFFSET 0x11c
#define TCON_LCD0_lcd_ceu_coef_add0_ceu_coef_add_value 0x7ffff
#define TCON_LCD0_lcd_ceu_coef_add0_ceu_coef_add_value_SHIFT 0
#define TCON_LCD0_lcd_ceu_coef_rang0 (TCON_LCD0 + 0x140) // LCD CEU Coefficient Register2 ()
#define TCON_LCD0_lcd_ceu_coef_rang0_OFFSET 0x140
#define TCON_LCD0_lcd_ceu_coef_rang0_ceu_coef_range_min (0xff << 16)
#define TCON_LCD0_lcd_ceu_coef_rang0_ceu_coef_range_min_SHIFT 16
#define TCON_LCD0_lcd_ceu_coef_rang0_ceu_coef_range_max 0xff
#define TCON_LCD0_lcd_ceu_coef_rang0_ceu_coef_range_max_SHIFT 0
#define TCON_LCD0_lcd_cpu_tri0 (TCON_LCD0 + 0x160) // LCD CPU Panel Trigger Register0 ()
#define TCON_LCD0_lcd_cpu_tri0_OFFSET 0x160
#define TCON_LCD0_lcd_cpu_tri0_block_space (0xfff << 16)
#define TCON_LCD0_lcd_cpu_tri0_block_space_SHIFT 16
#define TCON_LCD0_lcd_cpu_tri0_block_size 0xfff
#define TCON_LCD0_lcd_cpu_tri0_block_size_SHIFT 0
#define TCON_LCD0_lcd_cpu_tri1 (TCON_LCD0 + 0x164) // LCD CPU Panel Trigger Register1 ()
#define TCON_LCD0_lcd_cpu_tri1_OFFSET 0x164
#define TCON_LCD0_lcd_cpu_tri1_block_current_num (0xffff << 16)
#define TCON_LCD0_lcd_cpu_tri1_block_current_num_SHIFT 16
#define TCON_LCD0_lcd_cpu_tri1_block_num 0xffff
#define TCON_LCD0_lcd_cpu_tri1_block_num_SHIFT 0
#define TCON_LCD0_lcd_cpu_tri2 (TCON_LCD0 + 0x168) // LCD CPU Panel Trigger Register2 ()
#define TCON_LCD0_lcd_cpu_tri2_OFFSET 0x168
#define TCON_LCD0_lcd_cpu_tri2_start_dly (0xffff << 16)
#define TCON_LCD0_lcd_cpu_tri2_start_dly_SHIFT 16
#define TCON_LCD0_lcd_cpu_tri2_trans_start_mode (0x1 << 15)
#define TCON_LCD0_lcd_cpu_tri2_trans_start_mode_SHIFT 15
#define TCON_LCD0_lcd_cpu_tri2_sync_mode (0x3 << 13)
#define TCON_LCD0_lcd_cpu_tri2_sync_mode_SHIFT 13
#define TCON_LCD0_lcd_cpu_tri2_trans_start_set 0x1fff
#define TCON_LCD0_lcd_cpu_tri2_trans_start_set_SHIFT 0
#define TCON_LCD0_lcd_cpu_tri3 (TCON_LCD0 + 0x16c) // LCD CPU Panel Trigger Register3 ()
#define TCON_LCD0_lcd_cpu_tri3_OFFSET 0x16c
#define TCON_LCD0_lcd_cpu_tri3_tri_int_mode (0x3 << 28)
#define TCON_LCD0_lcd_cpu_tri3_tri_int_mode_SHIFT 28
#define TCON_LCD0_lcd_cpu_tri3_counter_n (0xffff << 8)
#define TCON_LCD0_lcd_cpu_tri3_counter_n_SHIFT 8
#define TCON_LCD0_lcd_cpu_tri3_counter_m 0xff
#define TCON_LCD0_lcd_cpu_tri3_counter_m_SHIFT 0
#define TCON_LCD0_lcd_cpu_tri4 (TCON_LCD0 + 0x170) // LCD CPU Panel Trigger Register4 ()
#define TCON_LCD0_lcd_cpu_tri4_OFFSET 0x170
#define TCON_LCD0_lcd_cpu_tri4_plug_mode_en (0x1 << 28)
#define TCON_LCD0_lcd_cpu_tri4_plug_mode_en_SHIFT 28
#define TCON_LCD0_lcd_cpu_tri4_a1_first_valid (0x1 << 24)
#define TCON_LCD0_lcd_cpu_tri4_a1_first_valid_SHIFT 24
#define TCON_LCD0_lcd_cpu_tri4_d23_to_d0_first_valid 0xffffff
#define TCON_LCD0_lcd_cpu_tri4_d23_to_d0_first_valid_SHIFT 0
#define TCON_LCD0_lcd_cpu_tri5 (TCON_LCD0 + 0x174) // LCD CPU Panel Trigger Register5 ()
#define TCON_LCD0_lcd_cpu_tri5_OFFSET 0x174
#define TCON_LCD0_lcd_cpu_tri5_a1_non_first_valid (0x1 << 24)
#define TCON_LCD0_lcd_cpu_tri5_a1_non_first_valid_SHIFT 24
#define TCON_LCD0_lcd_cpu_tri5_d23_to_d0_non_first_valid 0xffffff
#define TCON_LCD0_lcd_cpu_tri5_d23_to_d0_non_first_valid_SHIFT 0
#define TCON_LCD0_lcd_cmap_ctl (TCON_LCD0 + 0x180) // LCD Color Map Control Register ()
#define TCON_LCD0_lcd_cmap_ctl_OFFSET 0x180
#define TCON_LCD0_lcd_cmap_ctl_color_map_en (0x1 << 31)
#define TCON_LCD0_lcd_cmap_ctl_color_map_en_SHIFT 31
#define TCON_LCD0_lcd_cmap_ctl_out_format 0x1
#define TCON_LCD0_lcd_cmap_ctl_out_format_SHIFT 0
#define TCON_LCD0_lcd_cmap_odd0 (TCON_LCD0 + 0x190) // LCD Color Map Odd Line Registeri ()
#define TCON_LCD0_lcd_cmap_odd0_OFFSET 0x190
#define TCON_LCD0_lcd_cmap_odd0_out_odd0 0xffff
#define TCON_LCD0_lcd_cmap_odd0_out_odd0_SHIFT 0
#define TCON_LCD0_lcd_cmap_even0 (TCON_LCD0 + 0x198) // LCD Color Map Even Line Registeri ()
#define TCON_LCD0_lcd_cmap_even0_OFFSET 0x198
#define TCON_LCD0_lcd_cmap_even0_out_even0 0xffff
#define TCON_LCD0_lcd_cmap_even0_out_even0_SHIFT 0
#define TCON_LCD0_lcd_safe_period (TCON_LCD0 + 0x1f0) // LCD Safe Period Register ()
#define TCON_LCD0_lcd_safe_period_OFFSET 0x1f0
#define TCON_LCD0_lcd_safe_period_safe_period_fifo_num (0x1fff << 16)
#define TCON_LCD0_lcd_safe_period_safe_period_fifo_num_SHIFT 16
#define TCON_LCD0_lcd_safe_period_safe_period_line (0xfff << 4)
#define TCON_LCD0_lcd_safe_period_safe_period_line_SHIFT 4
#define TCON_LCD0_lcd_safe_period_safe_period_mode 0x7
#define TCON_LCD0_lcd_safe_period_safe_period_mode_SHIFT 0
#define TCON_LCD0_lcd_lvds_ana0 (TCON_LCD0 + 0x220) // LCD LVDS Analog Register i ()
#define TCON_LCD0_lcd_lvds_ana0_OFFSET 0x220
#define TCON_LCD0_lcd_lvds_ana0_lvds_en_mb (0x1 << 31)
#define TCON_LCD0_lcd_lvds_ana0_lvds_en_mb_SHIFT 31
#define TCON_LCD0_lcd_lvds_ana0_en_lvds (0x1 << 29)
#define TCON_LCD0_lcd_lvds_ana0_en_lvds_SHIFT 29
#define TCON_LCD0_lcd_lvds_ana0_en_24m (0x1 << 28)
#define TCON_LCD0_lcd_lvds_ana0_en_24m_SHIFT 28
#define TCON_LCD0_lcd_lvds_ana0_lvds_hpren_drvc (0x1 << 24)
#define TCON_LCD0_lcd_lvds_ana0_lvds_hpren_drvc_SHIFT 24
#define TCON_LCD0_lcd_lvds_ana0_lvds_hpren_drv (0xf << 20)
#define TCON_LCD0_lcd_lvds_ana0_lvds_hpren_drv_SHIFT 20
#define TCON_LCD0_lcd_lvds_ana0_lvds_c (0x7 << 17)
#define TCON_LCD0_lcd_lvds_ana0_lvds_c_SHIFT 17
#define TCON_LCD0_lcd_lvds_ana0_lvds_denc (0x1 << 16)
#define TCON_LCD0_lcd_lvds_ana0_lvds_denc_SHIFT 16
#define TCON_LCD0_lcd_lvds_ana0_lvds_den (0xf << 12)
#define TCON_LCD0_lcd_lvds_ana0_lvds_den_SHIFT 12
#define TCON_LCD0_lcd_lvds_ana0_lvds_r (0x7 << 8)
#define TCON_LCD0_lcd_lvds_ana0_lvds_r_SHIFT 8
#define TCON_LCD0_lcd_lvds_ana0_lvds_plrc (0x1 << 4)
#define TCON_LCD0_lcd_lvds_ana0_lvds_plrc_SHIFT 4
#define TCON_LCD0_lcd_lvds_ana0_lvds_plr 0xf
#define TCON_LCD0_lcd_lvds_ana0_lvds_plr_SHIFT 0
#define TCON_LCD0_fsync_gen_ctrl (TCON_LCD0 + 0x228) // FSYNC_GEN_CTRL ()
#define TCON_LCD0_fsync_gen_ctrl_OFFSET 0x228
#define TCON_LCD0_fsync_gen_ctrl_sensor_dis_time (0x7ff << 8)
#define TCON_LCD0_fsync_gen_ctrl_sensor_dis_time_SHIFT 8
#define TCON_LCD0_fsync_gen_ctrl_sensor_act1_value (0x1 << 6)
#define TCON_LCD0_fsync_gen_ctrl_sensor_act1_value_SHIFT 6
#define TCON_LCD0_fsync_gen_ctrl_sensor_act0_value (0x1 << 5)
#define TCON_LCD0_fsync_gen_ctrl_sensor_act0_value_SHIFT 5
#define TCON_LCD0_fsync_gen_ctrl_sensor_dis_value (0x1 << 4)
#define TCON_LCD0_fsync_gen_ctrl_sensor_dis_value_SHIFT 4
#define TCON_LCD0_fsync_gen_ctrl_hsync_pol_sel (0x1 << 2)
#define TCON_LCD0_fsync_gen_ctrl_hsync_pol_sel_SHIFT 2
#define TCON_LCD0_fsync_gen_ctrl_sel_vsync_en (0x1 << 1)
#define TCON_LCD0_fsync_gen_ctrl_sel_vsync_en_SHIFT 1
#define TCON_LCD0_fsync_gen_ctrl_fsync_gen_en 0x1
#define TCON_LCD0_fsync_gen_ctrl_fsync_gen_en_SHIFT 0
#define TCON_LCD0_fsync_gen_dly (TCON_LCD0 + 0x22c) // FSYNC_GEN_DLY ()
#define TCON_LCD0_fsync_gen_dly_OFFSET 0x22c
#define TCON_LCD0_fsync_gen_dly_RESET 0x00000000
#define TCON_LCD0_fsync_gen_dly_sensor_act0_time (0xfff << 16)
#define TCON_LCD0_fsync_gen_dly_sensor_act0_time_SHIFT 16
#define TCON_LCD0_fsync_gen_dly_sensor_act1_time 0xfff
#define TCON_LCD0_fsync_gen_dly_sensor_act1_time_SHIFT 0
#define TCON_LCD0_lcd_sync_ctl (TCON_LCD0 + 0x230) // LCD Sync Control Register ()
#define TCON_LCD0_lcd_sync_ctl_OFFSET 0x230
#define TCON_LCD0_lcd_sync_ctl_lcd_ctrl_work_mode (0x1 << 8)
#define TCON_LCD0_lcd_sync_ctl_lcd_ctrl_work_mode_SHIFT 8
#define TCON_LCD0_lcd_sync_ctl_lcd_cyrl_sync_master_slave (0x1 << 4)
#define TCON_LCD0_lcd_sync_ctl_lcd_cyrl_sync_master_slave_SHIFT 4
#define TCON_LCD0_lcd_sync_ctl_lcd_ctrl_sync_mode 0x1
#define TCON_LCD0_lcd_sync_ctl_lcd_ctrl_sync_mode_SHIFT 0
#define TCON_LCD0_lcd_sync_pos (TCON_LCD0 + 0x234) // LCD Sync Position Register ()
#define TCON_LCD0_lcd_sync_pos_OFFSET 0x234
#define TCON_LCD0_lcd_sync_pos_lcd_sync_pixel_num (0xfff << 16)
#define TCON_LCD0_lcd_sync_pos_lcd_sync_pixel_num_SHIFT 16
#define TCON_LCD0_lcd_sync_pos_lcd_sync_line_num 0xfff
#define TCON_LCD0_lcd_sync_pos_lcd_sync_line_num_SHIFT 0
#define TCON_LCD0_lcd_slave_stop_pos (TCON_LCD0 + 0x238) // LCD Slave Stop Position Register ()
#define TCON_LCD0_lcd_slave_stop_pos_OFFSET 0x238
#define TCON_LCD0_lcd_slave_stop_pos_stop_val 0xff
#define TCON_LCD0_lcd_slave_stop_pos_stop_val_SHIFT 0
#define TCON_LCD0_lcd_gamma_table0 (TCON_LCD0 + 0x400) // LCD Gamma Table Register ()
#define TCON_LCD0_lcd_gamma_table0_OFFSET 0x400
#define TCON_LCD0_lcd_gamma_table0_red_comp (0xff << 16)
#define TCON_LCD0_lcd_gamma_table0_red_comp_SHIFT 16
#define TCON_LCD0_lcd_gamma_table0_green_comp (0xff << 8)
#define TCON_LCD0_lcd_gamma_table0_green_comp_SHIFT 8
#define TCON_LCD0_lcd_gamma_table0_blue_comp 0xff
#define TCON_LCD0_lcd_gamma_table0_blue_comp_SHIFT 0

/****************************************************************
 * Timing COntroller TV
 ****************************************************************/
#define TCON_TV0 0x05470000
#define TCON_TV0_tv_gctl (TCON_TV0 + 0x0) // TV Global Control Register ()
#define TCON_TV0_tv_gctl_OFFSET 0x0
#define TCON_TV0_tv_gctl_tv_en (0x1 << 31)
#define TCON_TV0_tv_gctl_tv_en_SHIFT 31
#define TCON_TV0_tv_gctl_cec_ddc_pad_sel (0x1 << 1)
#define TCON_TV0_tv_gctl_cec_ddc_pad_sel_SHIFT 1
#define TCON_TV0_tv_gint0 (TCON_TV0 + 0x4) // TV Global Interrupt Register0 ()
#define TCON_TV0_tv_gint0_OFFSET 0x4
#define TCON_TV0_tv_gint0_tv_vb_int_en (0x1 << 30)
#define TCON_TV0_tv_gint0_tv_vb_int_en_SHIFT 30
#define TCON_TV0_tv_gint0_tv_line_int_en (0x1 << 28)
#define TCON_TV0_tv_gint0_tv_line_int_en_SHIFT 28
#define TCON_TV0_tv_gint0_tv_vb_int_flag (0x1 << 14)
#define TCON_TV0_tv_gint0_tv_vb_int_flag_SHIFT 14
#define TCON_TV0_tv_gint0_tv_line_int_flag (0x1 << 12)
#define TCON_TV0_tv_gint0_tv_line_int_flag_SHIFT 12
#define TCON_TV0_tv_gint1 (TCON_TV0 + 0x8) // TV Global Interrupt Register1 ()
#define TCON_TV0_tv_gint1_OFFSET 0x8
#define TCON_TV0_tv_gint1_tv_line_int_num 0xfff
#define TCON_TV0_tv_gint1_tv_line_int_num_SHIFT 0
#define TCON_TV0_tv_src_ctl (TCON_TV0 + 0x40) // TV Source Control Register ()
#define TCON_TV0_tv_src_ctl_OFFSET 0x40
#define TCON_TV0_tv_src_ctl_tv_src_sel 0x7
#define TCON_TV0_tv_src_ctl_tv_src_sel_SHIFT 0
#define TCON_TV0_tv_ctl (TCON_TV0 + 0x90) // TV Control Register ()
#define TCON_TV0_tv_ctl_OFFSET 0x90
#define TCON_TV0_tv_ctl_tv_en (0x1 << 31)
#define TCON_TV0_tv_ctl_tv_en_SHIFT 31
#define TCON_TV0_tv_ctl_start_delay (0x1f << 4)
#define TCON_TV0_tv_ctl_start_delay_SHIFT 4
#define TCON_TV0_tv_ctl_tv_src_sel (0x1 << 1)
#define TCON_TV0_tv_ctl_tv_src_sel_SHIFT 1
#define TCON_TV0_tv_basic0 (TCON_TV0 + 0x94) // TV Basic Timing Register0 ()
#define TCON_TV0_tv_basic0_OFFSET 0x94
#define TCON_TV0_tv_basic0_width_xi (0xfff << 16)
#define TCON_TV0_tv_basic0_width_xi_SHIFT 16
#define TCON_TV0_tv_basic0_height_yi 0xfff
#define TCON_TV0_tv_basic0_height_yi_SHIFT 0
#define TCON_TV0_tv_basic1 (TCON_TV0 + 0x98) // TV Basic Timing Register1 ()
#define TCON_TV0_tv_basic1_OFFSET 0x98
#define TCON_TV0_tv_basic1_ls_xo (0xfff << 16)
#define TCON_TV0_tv_basic1_ls_xo_SHIFT 16
#define TCON_TV0_tv_basic1_ls_yo 0xfff
#define TCON_TV0_tv_basic1_ls_yo_SHIFT 0
#define TCON_TV0_tv_basic2 (TCON_TV0 + 0x9c) // TV Basic Timing Register2 ()
#define TCON_TV0_tv_basic2_OFFSET 0x9c
#define TCON_TV0_tv_basic2_tv_xo (0xfff << 16)
#define TCON_TV0_tv_basic2_tv_xo_SHIFT 16
#define TCON_TV0_tv_basic2_tv_yo 0xfff
#define TCON_TV0_tv_basic2_tv_yo_SHIFT 0
#define TCON_TV0_tv_basic3 (TCON_TV0 + 0xa0) // TV Basic Timing Register3 ()
#define TCON_TV0_tv_basic3_OFFSET 0xa0
#define TCON_TV0_tv_basic3_h_t (0x1fff << 16)
#define TCON_TV0_tv_basic3_h_t_SHIFT 16
#define TCON_TV0_tv_basic3_h_bp 0xfff
#define TCON_TV0_tv_basic3_h_bp_SHIFT 0
#define TCON_TV0_tv_basic4 (TCON_TV0 + 0xa4) // TV Basic Timing Register4 ()
#define TCON_TV0_tv_basic4_OFFSET 0xa4
#define TCON_TV0_tv_basic4_v_t (0x1fff << 16)
#define TCON_TV0_tv_basic4_v_t_SHIFT 16
#define TCON_TV0_tv_basic4_v_bp 0xfff
#define TCON_TV0_tv_basic4_v_bp_SHIFT 0
#define TCON_TV0_tv_basic5 (TCON_TV0 + 0xa8) // TV Basic Timing Register5 ()
#define TCON_TV0_tv_basic5_OFFSET 0xa8
#define TCON_TV0_tv_basic5_h_spw (0x3ff << 16)
#define TCON_TV0_tv_basic5_h_spw_SHIFT 16
#define TCON_TV0_tv_basic5_v_spw 0x3ff
#define TCON_TV0_tv_basic5_v_spw_SHIFT 0
#define TCON_TV0_tv_io_pol (TCON_TV0 + 0x88) // TV SYNC Signal Polarity Register ()
#define TCON_TV0_tv_io_pol_OFFSET 0x88
#define TCON_TV0_tv_io_pol_io0_inv (0x1 << 24)
#define TCON_TV0_tv_io_pol_io0_inv_SHIFT 24
#define TCON_TV0_tv_io_tri (TCON_TV0 + 0x8c) // TV SYNC Signal IO Control Register ()
#define TCON_TV0_tv_io_tri_OFFSET 0x8c
#define TCON_TV0_tv_io_tri_io0_output_tri_en (0x1 << 24)
#define TCON_TV0_tv_io_tri_io0_output_tri_en_SHIFT 24
#define TCON_TV0_tv_debug (TCON_TV0 + 0xfc) // TV Debug Register ()
#define TCON_TV0_tv_debug_OFFSET 0xfc
#define TCON_TV0_tv_debug_tv_fifo_u (0x1 << 30)
#define TCON_TV0_tv_debug_tv_fifo_u_SHIFT 30
#define TCON_TV0_tv_debug_tv_field_pol (0x1 << 28)
#define TCON_TV0_tv_debug_tv_field_pol_SHIFT 28
#define TCON_TV0_tv_debug_line_buf_bypass (0x1 << 13)
#define TCON_TV0_tv_debug_line_buf_bypass_SHIFT 13
#define TCON_TV0_tv_debug_tv_current_line 0xfff
#define TCON_TV0_tv_debug_tv_current_line_SHIFT 0
#define TCON_TV0_tv_ceu_ctl (TCON_TV0 + 0x100) // TV CEU Control Register ()
#define TCON_TV0_tv_ceu_ctl_OFFSET 0x100
#define TCON_TV0_tv_ceu_ctl_ceu_en (0x1 << 31)
#define TCON_TV0_tv_ceu_ctl_ceu_en_SHIFT 31
#define TCON_TV0_tv_ceu_coef_mul0 (TCON_TV0 + 0x110) // TV CEU Coefficient Register0 ()
#define TCON_TV0_tv_ceu_coef_mul0_OFFSET 0x110
#define TCON_TV0_tv_ceu_coef_mul0_ceu_coef_mul_value (0x1 << 8)
#define TCON_TV0_tv_ceu_coef_mul0_ceu_coef_mul_value_SHIFT 8
#define TCON_TV0_tv_ceu_coef_rang0 (TCON_TV0 + 0x140) // TV CEU Coefficient Register2 ()
#define TCON_TV0_tv_ceu_coef_rang0_OFFSET 0x140
#define TCON_TV0_tv_ceu_coef_rang0_ceu_coef_range_min (0x3ff << 16)
#define TCON_TV0_tv_ceu_coef_rang0_ceu_coef_range_min_SHIFT 16
#define TCON_TV0_tv_ceu_coef_rang0_ceu_coef_range_max 0x3ff
#define TCON_TV0_tv_ceu_coef_rang0_ceu_coef_range_max_SHIFT 0
#define TCON_TV0_tv_safe_period (TCON_TV0 + 0x1f0) // TV Safe Period Register ()
#define TCON_TV0_tv_safe_period_OFFSET 0x1f0
#define TCON_TV0_tv_safe_period_safe_period_fifo_num (0x1fff << 16)
#define TCON_TV0_tv_safe_period_safe_period_fifo_num_SHIFT 16
#define TCON_TV0_tv_safe_period_safe_period_line (0xfff << 4)
#define TCON_TV0_tv_safe_period_safe_period_line_SHIFT 4
#define TCON_TV0_tv_safe_period_safe_period_mode 0x7
#define TCON_TV0_tv_safe_period_safe_period_mode_SHIFT 0
#define TCON_TV0_tv_fill_ctl (TCON_TV0 + 0x300) // TV Fill Data Control Register ()
#define TCON_TV0_tv_fill_ctl_OFFSET 0x300
#define TCON_TV0_tv_fill_ctl_tv_fill_en (0x1 << 31)
#define TCON_TV0_tv_fill_ctl_tv_fill_en_SHIFT 31
#define TCON_TV0_tv_fill_begin0 (TCON_TV0 + 0x304) // TV Fill Data Begin Register ()
#define TCON_TV0_tv_fill_begin0_OFFSET 0x304
#define TCON_TV0_tv_fill_begin0_fill_begin 0xffffff
#define TCON_TV0_tv_fill_begin0_fill_begin_SHIFT 0
#define TCON_TV0_tv_fill_end0 (TCON_TV0 + 0x308) // TV Fill Data End Register ()
#define TCON_TV0_tv_fill_end0_OFFSET 0x308
#define TCON_TV0_tv_fill_end0_fill_end 0xffffff
#define TCON_TV0_tv_fill_end0_fill_end_SHIFT 0
#define TCON_TV0_tv_fill_data0 (TCON_TV0 + 0x30c) // TV Fill Data Value Register ()
#define TCON_TV0_tv_fill_data0_OFFSET 0x30c
#define TCON_TV0_tv_fill_data0_fill_value 0x3fffffff
#define TCON_TV0_tv_fill_data0_fill_value_SHIFT 0
#define TCON_TV0_tv_data_io_pol0 (TCON_TV0 + 0x330) // TCON Data IO Polarity Control0 ()
#define TCON_TV0_tv_data_io_pol0_OFFSET 0x330
#define TCON_TV0_tv_data_io_pol0_r_cb_ch_data_inv (0x3ff << 16)
#define TCON_TV0_tv_data_io_pol0_r_cb_ch_data_inv_SHIFT 16
#define TCON_TV0_tv_data_io_pol0_g_y_ch_data_inv 0x3ff
#define TCON_TV0_tv_data_io_pol0_g_y_ch_data_inv_SHIFT 0
#define TCON_TV0_tv_data_io_pol1 (TCON_TV0 + 0x334) // TCON Data IO Polarity Control1 ()
#define TCON_TV0_tv_data_io_pol1_OFFSET 0x334
#define TCON_TV0_tv_data_io_pol1_b_cr_ch_data_inv (0x3ff << 16)
#define TCON_TV0_tv_data_io_pol1_b_cr_ch_data_inv_SHIFT 16
#define TCON_TV0_tv_data_io_tri0 (TCON_TV0 + 0x338) // TCON Data IO Enable Control0 ()
#define TCON_TV0_tv_data_io_tri0_OFFSET 0x338
#define TCON_TV0_tv_data_io_tri0_r_cb_ch_data_out_tri_en (0x3ff << 16)
#define TCON_TV0_tv_data_io_tri0_r_cb_ch_data_out_tri_en_SHIFT 16
#define TCON_TV0_tv_data_io_tri0_g_y_ch_data_out_tri_en 0x3ff
#define TCON_TV0_tv_data_io_tri0_g_y_ch_data_out_tri_en_SHIFT 0
#define TCON_TV0_tv_data_io_tri1 (TCON_TV0 + 0x33c) // TCON Data IO Enable Control1 ()
#define TCON_TV0_tv_data_io_tri1_OFFSET 0x33c
#define TCON_TV0_tv_data_io_tri1_b_cr_ch_data_out_tri_en (0x3ff << 16)
#define TCON_TV0_tv_data_io_tri1_b_cr_ch_data_out_tri_en_SHIFT 16
#define TCON_TV0_tv_pixeldepth_mode (TCON_TV0 + 0x340) // TV Pixeldepth Mode Control Register ()
#define TCON_TV0_tv_pixeldepth_mode_OFFSET 0x340
#define TCON_TV0_tv_pixeldepth_mode_colorbar_pd_mode 0x1
#define TCON_TV0_tv_pixeldepth_mode_colorbar_pd_mode_SHIFT 0

/****************************************************************
 * TV Encoder TOP
 ****************************************************************/
#define TVE_TOP 0x05600000
#define TVE_TOP_tve_dac_map (TVE_TOP + 0x20) // TV Encoder DAC MAP Register ()
#define TVE_TOP_tve_dac_map_OFFSET 0x20
#define TVE_TOP_tve_dac_map_dac_map (0x7 << 4)
#define TVE_TOP_tve_dac_map_dac_map_SHIFT 4
#define TVE_TOP_tve_dac_map_dac_sel 0x3
#define TVE_TOP_tve_dac_map_dac_sel_SHIFT 0
#define TVE_TOP_tve_dac_status (TVE_TOP + 0x24) // TV Encoder DAC STAUTS Register ()
#define TVE_TOP_tve_dac_status_OFFSET 0x24
#define TVE_TOP_tve_dac_status_dac_status 0x3
#define TVE_TOP_tve_dac_status_dac_status_SHIFT 0
#define TVE_TOP_tve_dac_cfg0 (TVE_TOP + 0x28) // TV Encoder DAC CFG0 Register ()
#define TVE_TOP_tve_dac_cfg0_OFFSET 0x28
#define TVE_TOP_tve_dac_cfg0_RESET 0x80004200
#define TVE_TOP_tve_dac_cfg0_dac_clock_invert (0x1 << 31)
#define TVE_TOP_tve_dac_cfg0_dac_clock_invert_SHIFT 31
#define TVE_TOP_tve_dac_cfg0_cali_in (0x3ff << 16)
#define TVE_TOP_tve_dac_cfg0_cali_in_SHIFT 16
#define TVE_TOP_tve_dac_cfg0_low_bias (0xf << 12)
#define TVE_TOP_tve_dac_cfg0_low_bias_SHIFT 12
#define TVE_TOP_tve_dac_cfg0_bias_ext_sel (0x1 << 9)
#define TVE_TOP_tve_dac_cfg0_bias_ext_sel_SHIFT 9
#define TVE_TOP_tve_dac_cfg0_bias_int_sel (0x1 << 8)
#define TVE_TOP_tve_dac_cfg0_bias_int_sel_SHIFT 8
#define TVE_TOP_tve_dac_cfg0_bias_ref_int_en (0x1 << 4)
#define TVE_TOP_tve_dac_cfg0_bias_ref_int_en_SHIFT 4
#define TVE_TOP_tve_dac_cfg0_dac_en 0x1
#define TVE_TOP_tve_dac_cfg0_dac_en_SHIFT 0
#define TVE_TOP_tve_dac_cfg1 (TVE_TOP + 0x2c) // TV Encoder DAC CFG1 Register ()
#define TVE_TOP_tve_dac_cfg1_OFFSET 0x2c
#define TVE_TOP_tve_dac_cfg1_RESET 0x0000023A
#define TVE_TOP_tve_dac_cfg1_ref_ext_sel (0x1 << 9)
#define TVE_TOP_tve_dac_cfg1_ref_ext_sel_SHIFT 9
#define TVE_TOP_tve_dac_cfg1_ref_int_sel (0x1 << 8)
#define TVE_TOP_tve_dac_cfg1_ref_int_sel_SHIFT 8
#define TVE_TOP_tve_dac_cfg1_ref2_sel (0x3 << 4)
#define TVE_TOP_tve_dac_cfg1_ref2_sel_SHIFT 4
#define TVE_TOP_tve_dac_cfg1_ref1_sel 0xf
#define TVE_TOP_tve_dac_cfg1_ref1_sel_SHIFT 0
#define TVE_TOP_tve_dac_cfg2 (TVE_TOP + 0x30) // TV Encoder DAC CFG2 Register ()
#define TVE_TOP_tve_dac_cfg2_OFFSET 0x30
#define TVE_TOP_tve_dac_cfg2_ab (0x1f << 8)
#define TVE_TOP_tve_dac_cfg2_ab_SHIFT 8
#define TVE_TOP_tve_dac_cfg2_s2s1 (0x3 << 6)
#define TVE_TOP_tve_dac_cfg2_s2s1_SHIFT 6
#define TVE_TOP_tve_dac_cfg2_r_set 0x3f
#define TVE_TOP_tve_dac_cfg2_r_set_SHIFT 0
#define TVE_TOP_tve_dac_cfg3 (TVE_TOP + 0x34) // TV Encoder DAC CFG2 Register ()
#define TVE_TOP_tve_dac_cfg3_OFFSET 0x34
#define TVE_TOP_tve_dac_cfg3_force_data_set (0x3ff << 16)
#define TVE_TOP_tve_dac_cfg3_force_data_set_SHIFT 16
#define TVE_TOP_tve_dac_cfg3_force_data_en 0x1
#define TVE_TOP_tve_dac_cfg3_force_data_en_SHIFT 0
#define TVE_TOP_tve_dac_test (TVE_TOP + 0xf0) // TV Encoder DAC TEST Register ()
#define TVE_TOP_tve_dac_test_OFFSET 0xf0
#define TVE_TOP_tve_dac_test_dac_test_length (0x3ff << 16)
#define TVE_TOP_tve_dac_test_dac_test_length_SHIFT 16
#define TVE_TOP_tve_dac_test_dac_test_sel (0x3 << 4)
#define TVE_TOP_tve_dac_test_dac_test_sel_SHIFT 4
#define TVE_TOP_tve_dac_test_dac_test_enable 0x1
#define TVE_TOP_tve_dac_test_dac_test_enable_SHIFT 0

/****************************************************************
 * TV Encoder
 ****************************************************************/
#define TVE 0x05604000
#define TVE_tve_clock_gating (TVE + 0x0) // TV Encoder Clock Gating Register ()
#define TVE_tve_clock_gating_OFFSET 0x0
#define TVE_tve_clock_gating_clock_gate_dis (0x1 << 31)
#define TVE_tve_clock_gating_clock_gate_dis_SHIFT 31
#define TVE_tve_clock_gating_bist_en (0x1 << 28)
#define TVE_tve_clock_gating_bist_en_SHIFT 28
#define TVE_tve_clock_gating_upsample_for_ypbpr (0x1 << 22)
#define TVE_tve_clock_gating_upsample_for_ypbpr_SHIFT 22
#define TVE_tve_clock_gating_upsample_for_cvbs (0x3 << 20)
#define TVE_tve_clock_gating_upsample_for_cvbs_SHIFT 20
#define TVE_tve_clock_gating_tve_en 0x1
#define TVE_tve_clock_gating_tve_en_SHIFT 0
#define TVE_tve_configuration (TVE + 0x4) // TV Encoder Configuration Register ()
#define TVE_tve_configuration_OFFSET 0x4
#define TVE_tve_configuration_RESET 0x00010000
#define TVE_tve_configuration_bypass_tv (0x1 << 29)
#define TVE_tve_configuration_bypass_tv_SHIFT 29
#define TVE_tve_configuration_dac_src_sel (0x3 << 27)
#define TVE_tve_configuration_dac_src_sel_SHIFT 27
#define TVE_tve_configuration_dac_control_logic_clock_sel (0x1 << 26)
#define TVE_tve_configuration_dac_control_logic_clock_sel_SHIFT 26
#define TVE_tve_configuration_core_datapath_logic_clock_sel (0x1 << 25)
#define TVE_tve_configuration_core_datapath_logic_clock_sel_SHIFT 25
#define TVE_tve_configuration_core_control_logic_clock_sel (0x1 << 24)
#define TVE_tve_configuration_core_control_logic_clock_sel_SHIFT 24
#define TVE_tve_configuration_cb_cr_seq_for_422_mode (0x1 << 20)
#define TVE_tve_configuration_cb_cr_seq_for_422_mode_SHIFT 20
#define TVE_tve_configuration_input_chroma_data_sampling_rate_sel (0x1 << 19)
#define TVE_tve_configuration_input_chroma_data_sampling_rate_sel_SHIFT 19
#define TVE_tve_configuration_yuv_rgb_output_en (0x1 << 18)
#define TVE_tve_configuration_yuv_rgb_output_en_SHIFT 18
#define TVE_tve_configuration_yc_en (0x1 << 17)
#define TVE_tve_configuration_yc_en_SHIFT 17
#define TVE_tve_configuration_cvbs_en (0x1 << 16)
#define TVE_tve_configuration_cvbs_en_SHIFT 16
#define TVE_tve_configuration_color_bar_type (0x1 << 9)
#define TVE_tve_configuration_color_bar_type_SHIFT 9
#define TVE_tve_configuration_color_bar_mode (0x1 << 8)
#define TVE_tve_configuration_color_bar_mode_SHIFT 8
#define TVE_tve_configuration_mode_1080i_1250line_sel (0x1 << 4)
#define TVE_tve_configuration_mode_1080i_1250line_sel_SHIFT 4
#define TVE_tve_configuration_tvmode_select 0xf
#define TVE_tve_configuration_tvmode_select_SHIFT 0
#define TVE_tve_dac1 (TVE + 0x8) // TV Encoder DAC Register1 ()
#define TVE_tve_dac1_OFFSET 0x8
#define TVE_tve_dac1_dac0_src_sel (0x7 << 4)
#define TVE_tve_dac1_dac0_src_sel_SHIFT 4
#define TVE_tve_notch_dac_delay (TVE + 0xc) // TV Encoder Notch and DAC Delay Register ()
#define TVE_tve_notch_dac_delay_OFFSET 0xc
#define TVE_tve_notch_dac_delay_RESET 0x02014924
#define TVE_tve_notch_dac_delay_chroma_filter_active_valid (0x1 << 31)
#define TVE_tve_notch_dac_delay_chroma_filter_active_valid_SHIFT 31
#define TVE_tve_notch_dac_delay_luma_filter_lti_enable (0x1 << 30)
#define TVE_tve_notch_dac_delay_luma_filter_lti_enable_SHIFT 30
#define TVE_tve_notch_dac_delay_y_delay_before_dither (0x7 << 25)
#define TVE_tve_notch_dac_delay_y_delay_before_dither_SHIFT 25
#define TVE_tve_notch_dac_delay_hd_mode_cb_filter_bypass (0x1 << 24)
#define TVE_tve_notch_dac_delay_hd_mode_cb_filter_bypass_SHIFT 24
#define TVE_tve_notch_dac_delay_hd_mode_cr_filter_bypass (0x1 << 23)
#define TVE_tve_notch_dac_delay_hd_mode_cr_filter_bypass_SHIFT 23
#define TVE_tve_notch_dac_delay_chroma_filter_1_444_en (0x1 << 22)
#define TVE_tve_notch_dac_delay_chroma_filter_1_444_en_SHIFT 22
#define TVE_tve_notch_dac_delay_chroma_hd_mode_filter_en (0x1 << 21)
#define TVE_tve_notch_dac_delay_chroma_hd_mode_filter_en_SHIFT 21
#define TVE_tve_notch_dac_delay_chroma_filter_stage_0_bypass (0x1 << 18)
#define TVE_tve_notch_dac_delay_chroma_filter_stage_0_bypass_SHIFT 18
#define TVE_tve_notch_dac_delay_luma_filter_bypass (0x1 << 17)
#define TVE_tve_notch_dac_delay_luma_filter_bypass_SHIFT 17
#define TVE_tve_notch_dac_delay_notch_en (0x1 << 16)
#define TVE_tve_notch_dac_delay_notch_en_SHIFT 16
#define TVE_tve_notch_dac_delay_c_delay_before_dither (0xf << 12)
#define TVE_tve_notch_dac_delay_c_delay_before_dither_SHIFT 12
#define TVE_tve_chroma_frequency (TVE + 0x10) // TV Encoder Chroma Frequency Register ()
#define TVE_tve_chroma_frequency_OFFSET 0x10
#define TVE_tve_chroma_frequency_RESET 0x21F07C1F
#define TVE_tve_chroma_frequency_chroma_freq 0xffffffff
#define TVE_tve_chroma_frequency_chroma_freq_SHIFT 0
#define TVE_tve_front_back_porch (TVE + 0x14) // TV Encoder Front/Back Porch Register ()
#define TVE_tve_front_back_porch_OFFSET 0x14
#define TVE_tve_front_back_porch_RESET 0x00760020
#define TVE_tve_front_back_porch_back_porch (0x1ff << 16)
#define TVE_tve_front_back_porch_back_porch_SHIFT 16
#define TVE_tve_front_back_porch_front_porch 0xfff
#define TVE_tve_front_back_porch_front_porch_SHIFT 0
#define TVE_tve_hd_vsync (TVE + 0x18) // TV Encoder HD Mode VSYNC Register ()
#define TVE_tve_hd_vsync_OFFSET 0x18
#define TVE_tve_hd_vsync_RESET 0x00000016
#define TVE_tve_hd_vsync_broad_plus_cycle_number_in_hd_mode_vsync (0xfff << 16)
#define TVE_tve_hd_vsync_broad_plus_cycle_number_in_hd_mode_vsync_SHIFT 16
#define TVE_tve_hd_vsync_front_porch_like_in_hd_mode_vsync 0xfff
#define TVE_tve_hd_vsync_front_porch_like_in_hd_mode_vsync_SHIFT 0
#define TVE_tve_line_number (TVE + 0x1c) // TV Encoder Line Number Register ()
#define TVE_tve_line_number_OFFSET 0x1c
#define TVE_tve_line_number_RESET 0x0016020D
#define TVE_tve_line_number_first_video_line (0xff << 16)
#define TVE_tve_line_number_first_video_line_SHIFT 16
#define TVE_tve_line_number_num_lines 0x7ff
#define TVE_tve_line_number_num_lines_SHIFT 0
#define TVE_tve_level (TVE + 0x20) // TV Encoder Level Register ()
#define TVE_tve_level_OFFSET 0x20
#define TVE_tve_level_RESET 0x00F0011A
#define TVE_tve_level_blank_level (0x3ff << 16)
#define TVE_tve_level_blank_level_SHIFT 16
#define TVE_tve_level_black_level 0x3ff
#define TVE_tve_level_black_level_SHIFT 0
#define TVE_tve_dac2 (TVE + 0x24) // TV Encoder DAC Register2 ()
#define TVE_tve_dac2_OFFSET 0x24
#define TVE_tve_auto_detection_enable (TVE + 0x30) // TV Encoder Auto Detection Enable Register ()
#define TVE_tve_auto_detection_enable_OFFSET 0x30
#define TVE_tve_auto_detection_enable_dac_auto_detect_mode_sel (0x1 << 31)
#define TVE_tve_auto_detection_enable_dac_auto_detect_mode_sel_SHIFT 31
#define TVE_tve_auto_detection_enable_dac0_auto_detect_interrupt_en (0x1 << 16)
#define TVE_tve_auto_detection_enable_dac0_auto_detect_interrupt_en_SHIFT 16
#define TVE_tve_auto_detection_enable_dac0_auto_detect_enable 0x1
#define TVE_tve_auto_detection_enable_dac0_auto_detect_enable_SHIFT 0
#define TVE_tve_auto_detection_interrupt_status (TVE + 0x34) // TV Encoder Auto Detection Interrupt Status Register ()
#define TVE_tve_auto_detection_interrupt_status_OFFSET 0x34
#define TVE_tve_auto_detection_interrupt_status_dac0_auto_detect_interrupt_active_flag 0x1
#define TVE_tve_auto_detection_interrupt_status_dac0_auto_detect_interrupt_active_flag_SHIFT 0
#define TVE_tve_auto_detection_status (TVE + 0x38) // TV Encoder Auto Detection Status Register ()
#define TVE_tve_auto_detection_status_OFFSET 0x38
#define TVE_tve_auto_detection_status_dac0_status 0x3
#define TVE_tve_auto_detection_status_dac0_status_SHIFT 0
#define TVE_tve_auto_detection_debounce_setting (TVE + 0x3c) // TV Encoder Auto Detection De-bounce Setting Register ()
#define TVE_tve_auto_detection_debounce_setting_OFFSET 0x3c
#define TVE_tve_auto_detection_debounce_setting_dac_test_register (0x3ff << 16)
#define TVE_tve_auto_detection_debounce_setting_dac_test_register_SHIFT 16
#define TVE_tve_auto_detection_debounce_setting_dac0_de_bounce_times 0xf
#define TVE_tve_auto_detection_debounce_setting_dac0_de_bounce_times_SHIFT 0
#define TVE_tve_auto_detect_cfg0 (TVE + 0xf8) // TV Encoder Auto Detect Configuration Register0 ()
#define TVE_tve_auto_detect_cfg0_OFFSET 0xf8
#define TVE_tve_auto_detect_cfg0_detect_pulse_value 0x3ff
#define TVE_tve_auto_detect_cfg0_detect_pulse_value_SHIFT 0
#define TVE_tve_auto_detect_cfg1 (TVE + 0xfc) // TV Encoder Auto Detect Configuration Register1 ()
#define TVE_tve_auto_detect_cfg1_OFFSET 0xfc
#define TVE_tve_auto_detect_cfg1_detect_pulse_periods (0x7fff << 16)
#define TVE_tve_auto_detect_cfg1_detect_pulse_periods_SHIFT 16
#define TVE_tve_auto_detect_cfg1_detect_pulse_start 0x7fff
#define TVE_tve_auto_detect_cfg1_detect_pulse_start_SHIFT 0
#define TVE_tve_color_burst_phase_reset_cfg (TVE + 0x100) // TV Encoder Color Burst Phase Reset Configuration Register ()
#define TVE_tve_color_burst_phase_reset_cfg_OFFSET 0x100
#define TVE_tve_color_burst_phase_reset_cfg_color_phase_reset 0x3
#define TVE_tve_color_burst_phase_reset_cfg_color_phase_reset_SHIFT 0
#define TVE_tve_vsync_number (TVE + 0x104) // TV Encoder VSYNC Number Register ()
#define TVE_tve_vsync_number_OFFSET 0x104
#define TVE_tve_vsync_number_vsync5 0x1
#define TVE_tve_vsync_number_vsync5_SHIFT 0
#define TVE_tve_notch_filter_frequency (TVE + 0x108) // TV Encoder Notch Filter Frequency Register ()
#define TVE_tve_notch_filter_frequency_OFFSET 0x108
#define TVE_tve_notch_filter_frequency_RESET 0x00000002
#define TVE_tve_notch_filter_frequency_notch_freq 0x7
#define TVE_tve_notch_filter_frequency_notch_freq_SHIFT 0
#define TVE_tve_cbcr_level_gain (TVE + 0x10c) // TV Encoder Cb/Cr Level/Gain Register ()
#define TVE_tve_cbcr_level_gain_OFFSET 0x10c
#define TVE_tve_cbcr_level_gain_RESET 0x0000004F
#define TVE_tve_cbcr_level_gain_cr_burst_level (0xff << 8)
#define TVE_tve_cbcr_level_gain_cr_burst_level_SHIFT 8
#define TVE_tve_cbcr_level_gain_cb_burst_level 0xff
#define TVE_tve_cbcr_level_gain_cb_burst_level_SHIFT 0
#define TVE_tve_tint_color_burst_phase (TVE + 0x110) // TV Encoder Tint and Color Burst Phase Register ()
#define TVE_tve_tint_color_burst_phase_OFFSET 0x110
#define TVE_tve_tint_color_burst_phase_tint (0xff << 16)
#define TVE_tve_tint_color_burst_phase_tint_SHIFT 16
#define TVE_tve_tint_color_burst_phase_chroma_phase 0xff
#define TVE_tve_tint_color_burst_phase_chroma_phase_SHIFT 0
#define TVE_tve_burst_width (TVE + 0x114) // TV Encoder Burst Width Register ()
#define TVE_tve_burst_width_OFFSET 0x114
#define TVE_tve_burst_width_RESET 0x0016447E
#define TVE_tve_burst_width_back_porch (0xff << 24)
#define TVE_tve_burst_width_back_porch_SHIFT 24
#define TVE_tve_burst_width_breezeway (0x7f << 16)
#define TVE_tve_burst_width_breezeway_SHIFT 16
#define TVE_tve_burst_width_burst_width (0x7f << 8)
#define TVE_tve_burst_width_burst_width_SHIFT 8
#define TVE_tve_burst_width_hsync_width 0xff
#define TVE_tve_burst_width_hsync_width_SHIFT 0
#define TVE_tve_cbcr_gain (TVE + 0x118) // TV Encoder Cb/Cr Gain Register ()
#define TVE_tve_cbcr_gain_OFFSET 0x118
#define TVE_tve_cbcr_gain_RESET 0x0000A0A0
#define TVE_tve_cbcr_gain_cr_gain (0xff << 8)
#define TVE_tve_cbcr_gain_cr_gain_SHIFT 8
#define TVE_tve_cbcr_gain_cb_gain 0xff
#define TVE_tve_cbcr_gain_cb_gain_SHIFT 0
#define TVE_tve_sync_vbi_level (TVE + 0x11c) // TV Encoder Sync and VBI Level Register ()
#define TVE_tve_sync_vbi_level_OFFSET 0x11c
#define TVE_tve_sync_vbi_level_RESET 0x001000F0
#define TVE_tve_sync_vbi_level_sync_level (0x3ff << 16)
#define TVE_tve_sync_vbi_level_sync_level_SHIFT 16
#define TVE_tve_sync_vbi_level_vblank_level 0x3ff
#define TVE_tve_sync_vbi_level_vblank_level_SHIFT 0
#define TVE_tve_white_level (TVE + 0x120) // TV Encoder White Level Register ()
#define TVE_tve_white_level_OFFSET 0x120
#define TVE_tve_white_level_RESET 0x01E80320
#define TVE_tve_white_level_hd_sync_breezeway_level (0x3ff << 16)
#define TVE_tve_white_level_hd_sync_breezeway_level_SHIFT 16
#define TVE_tve_white_level_white_level 0x3ff
#define TVE_tve_white_level_white_level_SHIFT 0
#define TVE_tve_video_active_line (TVE + 0x124) // TV Encoder Video Active Line Register ()
#define TVE_tve_video_active_line_OFFSET 0x124
#define TVE_tve_video_active_line_RESET 0x000005A0
#define TVE_tve_video_active_line_active_line 0xfff
#define TVE_tve_video_active_line_active_line_SHIFT 0
#define TVE_tve_video_chroma_bw_comp_gain (TVE + 0x128) // TV Encoder Video Chroma BW and CompGain Register ()
#define TVE_tve_video_chroma_bw_comp_gain_OFFSET 0x128
#define TVE_tve_video_chroma_bw_comp_gain_chroma_bw (0x3 << 16)
#define TVE_tve_video_chroma_bw_comp_gain_chroma_bw_SHIFT 16
#define TVE_tve_video_chroma_bw_comp_gain_comp_ch_gain 0x3
#define TVE_tve_video_chroma_bw_comp_gain_comp_ch_gain_SHIFT 0
#define TVE_tve_notch_width_comp_yuv_en (TVE + 0x12c) // TV Encoder Register ()
#define TVE_tve_notch_width_comp_yuv_en_OFFSET 0x12c
#define TVE_tve_notch_width_comp_yuv_en_RESET 0x00000101
#define TVE_tve_notch_width_comp_yuv_en_notch_width (0x1 << 8)
#define TVE_tve_notch_width_comp_yuv_en_notch_width_SHIFT 8
#define TVE_tve_notch_width_comp_yuv_en_comp_yuv_en 0x1
#define TVE_tve_notch_width_comp_yuv_en_comp_yuv_en_SHIFT 0
#define TVE_tve_resync_parameters (TVE + 0x130) // TV Encoder Re-sync Parameters Register ()
#define TVE_tve_resync_parameters_OFFSET 0x130
#define TVE_tve_resync_parameters_RESET 0x00100001
#define TVE_tve_resync_parameters_re_sync_field (0x1 << 31)
#define TVE_tve_resync_parameters_re_sync_field_SHIFT 31
#define TVE_tve_resync_parameters_re_sync_dis (0x1 << 30)
#define TVE_tve_resync_parameters_re_sync_dis_SHIFT 30
#define TVE_tve_resync_parameters_re_sync_line_num (0x7ff << 16)
#define TVE_tve_resync_parameters_re_sync_line_num_SHIFT 16
#define TVE_tve_resync_parameters_re_sync_pixel_num 0x7ff
#define TVE_tve_resync_parameters_re_sync_pixel_num_SHIFT 0
#define TVE_tve_slave_parameter (TVE + 0x134) // TV Encoder Slave Parameter Register ()
#define TVE_tve_slave_parameter_OFFSET 0x134
#define TVE_tve_slave_parameter_slave_thresh (0x1 << 8)
#define TVE_tve_slave_parameter_slave_thresh_SHIFT 8
#define TVE_tve_slave_parameter_slave_mode 0x1
#define TVE_tve_slave_parameter_slave_mode_SHIFT 0
#define TVE_tve_configuration0 (TVE + 0x138) // TV Encoder Configuration Register0 ()
#define TVE_tve_configuration0_OFFSET 0x138
#define TVE_tve_configuration0_invert_top (0x1 << 8)
#define TVE_tve_configuration0_invert_top_SHIFT 8
#define TVE_tve_configuration0_uv_order 0x1
#define TVE_tve_configuration0_uv_order_SHIFT 0
#define TVE_tve_configuration1 (TVE + 0x13c) // TV Encoder Configuration Register1 ()
#define TVE_tve_configuration1_OFFSET 0x13c
#define TVE_tve_configuration1_RESET 0x00000001
#define TVE_tve_configuration1_rgb_sync (0x7 << 24)
#define TVE_tve_configuration1_rgb_sync_SHIFT 24
#define TVE_tve_configuration1_rgb_setup (0x1 << 16)
#define TVE_tve_configuration1_rgb_setup_SHIFT 16
#define TVE_tve_configuration1_bypass_yclamp 0x1
#define TVE_tve_configuration1_bypass_yclamp_SHIFT 0
#define TVE_tve_low_pass_control (TVE + 0x380) // TV Encoder Low Pass Control Register ()
#define TVE_tve_low_pass_control_OFFSET 0x380
#define TVE_tve_low_pass_control_user_deflicker_coef (0xf << 10)
#define TVE_tve_low_pass_control_user_deflicker_coef_SHIFT 10
#define TVE_tve_low_pass_control_fix_coef_deflicker (0x1 << 9)
#define TVE_tve_low_pass_control_fix_coef_deflicker_SHIFT 9
#define TVE_tve_low_pass_control_enable_deflicker (0x1 << 8)
#define TVE_tve_low_pass_control_enable_deflicker_SHIFT 8
#define TVE_tve_low_pass_control_en 0x1
#define TVE_tve_low_pass_control_en_SHIFT 0
#define TVE_tve_low_pass_filter_control (TVE + 0x384) // TV Encoder Low Pass Filter Control Register ()
#define TVE_tve_low_pass_filter_control_OFFSET 0x384
#define TVE_tve_low_pass_filter_control_hp_ratio (0x3f << 16)
#define TVE_tve_low_pass_filter_control_hp_ratio_SHIFT 16
#define TVE_tve_low_pass_filter_control_bp0_ratio (0x3f << 8)
#define TVE_tve_low_pass_filter_control_bp0_ratio_SHIFT 8
#define TVE_tve_low_pass_filter_control_bp1_ratio 0x3f
#define TVE_tve_low_pass_filter_control_bp1_ratio_SHIFT 0
#define TVE_tve_low_pass_gain (TVE + 0x388) // TV Encoder Low Pass Gain Register ()
#define TVE_tve_low_pass_gain_OFFSET 0x388
#define TVE_tve_low_pass_gain_gain 0xff
#define TVE_tve_low_pass_gain_gain_SHIFT 0
#define TVE_tve_low_pass_gain_control (TVE + 0x38c) // TV Encoder Low Pass Gain Control Register ()
#define TVE_tve_low_pass_gain_control_OFFSET 0x38c
#define TVE_tve_low_pass_gain_control_dif_up (0xff << 16)
#define TVE_tve_low_pass_gain_control_dif_up_SHIFT 16
#define TVE_tve_low_pass_gain_control_beta 0x1f
#define TVE_tve_low_pass_gain_control_beta_SHIFT 0
#define TVE_tve_low_pass_shoot_control (TVE + 0x390) // TV Encoder Low Pass Shoot Control Register ()
#define TVE_tve_low_pass_shoot_control_OFFSET 0x390
#define TVE_tve_low_pass_shoot_control_neg_gain 0x3f
#define TVE_tve_low_pass_shoot_control_neg_gain_SHIFT 0
#define TVE_tve_low_pass_coring (TVE + 0x394) // TV Encoder Low Pass Coring Register ()
#define TVE_tve_low_pass_coring_OFFSET 0x394
#define TVE_tve_low_pass_coring_corthr 0xff
#define TVE_tve_low_pass_coring_corthr_SHIFT 0
#define TVE_tve_noise_reduction (TVE + 0x3a0) // TV Encoder Noise Reduction Register ()
#define TVE_tve_noise_reduction_OFFSET 0x3a0
#define TVE_tve_noise_reduction_t_value (0xff << 16)
#define TVE_tve_noise_reduction_t_value_SHIFT 16
#define TVE_tve_noise_reduction_en 0x1
#define TVE_tve_noise_reduction_en_SHIFT 0

/****************************************************************
 * CMOS Sensor Interface Controller
 ****************************************************************/
#define CSIC 0x05800000

/****************************************************************
 * Television Decoder TOP
 ****************************************************************/
#define TVD_TOP 0x05c00000
#define TVD_TOP_tvd_top_map (TVD_TOP + 0x0) // TVD TOP MAP Register ()
#define TVD_TOP_tvd_top_map_OFFSET 0x0
#define TVD_TOP_tvd_3d_ctl1 (TVD_TOP + 0x8) // TVD 3D DMA CONTROL Register1 ()
#define TVD_TOP_tvd_3d_ctl1_OFFSET 0x8
#define TVD_TOP_tvd_3d_ctl2 (TVD_TOP + 0xc) // TVD 3D DMA CONTROL Register2 ()
#define TVD_TOP_tvd_3d_ctl2_OFFSET 0xc
#define TVD_TOP_tvd_3d_ctl3 (TVD_TOP + 0x10) // TVD 3D DMA CONTROL Register3 ()
#define TVD_TOP_tvd_3d_ctl3_OFFSET 0x10
#define TVD_TOP_tvd_3d_ctl4 (TVD_TOP + 0x14) // TVD 3D DMA CONTROL Register4 ()
#define TVD_TOP_tvd_3d_ctl4_OFFSET 0x14
#define TVD_TOP_tvd_3d_ctl5 (TVD_TOP + 0x18) // TVD 3D DMA CONTROL Register5 ()
#define TVD_TOP_tvd_3d_ctl5_OFFSET 0x18
#define TVD_TOP_tvd_top_ctl0 (TVD_TOP + 0x24) // TVD TOP CONTROL Register ()
#define TVD_TOP_tvd_top_ctl0_OFFSET 0x24
#define TVD_TOP_tvd_adc_ctl0 (TVD_TOP + 0x28) // TVD ADC CONTROL Register ()
#define TVD_TOP_tvd_adc_ctl0_OFFSET 0x28
#define TVD_TOP_tvd_adc_cfg0 (TVD_TOP + 0x2c) // TVD ADC CONFIGURATION Register ()
#define TVD_TOP_tvd_adc_cfg0_OFFSET 0x2c

/****************************************************************
 * Television Decoder
 ****************************************************************/
#define TVD0 0x05c01000
#define TVD0_tvd_en (TVD0 + 0x0) // TVD MODULE CONTROL Register ()
#define TVD0_tvd_en_OFFSET 0x0
#define TVD0_tvd_mode (TVD0 + 0x4) // TVD MODE CONTROL Register ()
#define TVD0_tvd_mode_OFFSET 0x4
#define TVD0_tvd_clamp_agc1 (TVD0 + 0x8) // TVD CLAMP And AGC CONTROL Register1 ()
#define TVD0_tvd_clamp_agc1_OFFSET 0x8
#define TVD0_tvd_clamp_agc2 (TVD0 + 0xc) // TVD CLAMP And AGC CONTROL Register2 ()
#define TVD0_tvd_clamp_agc2_OFFSET 0xc
#define TVD0_tvd_hlock1 (TVD0 + 0x10) // TVD HLOCK CONTROL Register1 ()
#define TVD0_tvd_hlock1_OFFSET 0x10
#define TVD0_tvd_hlock2 (TVD0 + 0x14) // TVD HLOCK CONTROL Register2 ()
#define TVD0_tvd_hlock2_OFFSET 0x14
#define TVD0_tvd_hlock3 (TVD0 + 0x18) // TVD HLOCK CONTROL Register3 ()
#define TVD0_tvd_hlock3_OFFSET 0x18
#define TVD0_tvd_hlock4 (TVD0 + 0x1c) // TVD HLOCK CONTROL Register4 ()
#define TVD0_tvd_hlock4_OFFSET 0x1c
#define TVD0_tvd_hlock5 (TVD0 + 0x20) // TVD HLOCK CONTROL Register5 ()
#define TVD0_tvd_hlock5_OFFSET 0x20
#define TVD0_tvd_vlock1 (TVD0 + 0x24) // TVD VLOCK CONTROL Register1 ()
#define TVD0_tvd_vlock1_OFFSET 0x24
#define TVD0_tvd_vlock2 (TVD0 + 0x28) // TVD VLOCK CONTROL Register2 ()
#define TVD0_tvd_vlock2_OFFSET 0x28
#define TVD0_tvd_clock1 (TVD0 + 0x30) // TVD CHROMA LOCK CONTROL Register1 ()
#define TVD0_tvd_clock1_OFFSET 0x30
#define TVD0_tvd_clock2 (TVD0 + 0x34) // TVD CHROMA LOCK CONTROL Register2 ()
#define TVD0_tvd_clock2_OFFSET 0x34
#define TVD0_tvd_yc_sep1 (TVD0 + 0x40) // TVD YC SEPERATION CONROL Register1 ()
#define TVD0_tvd_yc_sep1_OFFSET 0x40
#define TVD0_tvd_yc_sep2 (TVD0 + 0x44) // TVD YC SEPERATION CONROL Register2 ()
#define TVD0_tvd_yc_sep2_OFFSET 0x44
#define TVD0_tvd_enhance1 (TVD0 + 0x50) // TVD ENHANCEMENT CONTROL Register1 ()
#define TVD0_tvd_enhance1_OFFSET 0x50
#define TVD0_tvd_enhance2 (TVD0 + 0x54) // TVD ENHANCEMENT CONTROL Register2 ()
#define TVD0_tvd_enhance2_OFFSET 0x54
#define TVD0_tvd_enhance3 (TVD0 + 0x58) // TVD ENHANCEMENT CONTROL Register3 ()
#define TVD0_tvd_enhance3_OFFSET 0x58
#define TVD0_tvd_wb1 (TVD0 + 0x60) // TVD WB DMA CONTROL Register1 ()
#define TVD0_tvd_wb1_OFFSET 0x60
#define TVD0_tvd_wb2 (TVD0 + 0x64) // TVD WB DMA CONTROL Register2 ()
#define TVD0_tvd_wb2_OFFSET 0x64
#define TVD0_tvd_wb3 (TVD0 + 0x68) // TVD WB DMA CONTROL Register3 ()
#define TVD0_tvd_wb3_OFFSET 0x68
#define TVD0_tvd_wb4 (TVD0 + 0x6c) // TVD WB DMA CONTROL Register4 ()
#define TVD0_tvd_wb4_OFFSET 0x6c
#define TVD0_tvd_irq_ctl (TVD0 + 0x80) // TVD DMA Interrupt Control Register ()
#define TVD0_tvd_irq_ctl_OFFSET 0x80
#define TVD0_tvd_irq_status (TVD0 + 0x90) // TVD DMA Interrupt Status Register ()
#define TVD0_tvd_irq_status_OFFSET 0x90
#define TVD0_tvd_debug1 (TVD0 + 0x100) // TVD DEBUG CONTROL Register1 ()
#define TVD0_tvd_debug1_OFFSET 0x100
#define TVD0_tvd_status1 (TVD0 + 0x180) // TVD DEBUG STATUS Register1 ()
#define TVD0_tvd_status1_OFFSET 0x180
#define TVD0_tvd_status2 (TVD0 + 0x184) // TVD DEBUG STATUS Register2 ()
#define TVD0_tvd_status2_OFFSET 0x184
#define TVD0_tvd_status3 (TVD0 + 0x188) // TVD DEBUG STATUS Register3 ()
#define TVD0_tvd_status3_OFFSET 0x188
#define TVD0_tvd_status4 (TVD0 + 0x18c) // TVD DEBUG STATUS Register4 ()
#define TVD0_tvd_status4_OFFSET 0x18c
#define TVD0_tvd_status5 (TVD0 + 0x190) // TVD DEBUG STATUS Register5 ()
#define TVD0_tvd_status5_OFFSET 0x190
#define TVD0_tvd_status6 (TVD0 + 0x194) // TVD DEBUG STATUS Register6 ()
#define TVD0_tvd_status6_OFFSET 0x194

/****************************************************************
 * SD/MMC Host Controller
 ****************************************************************/
#define SMHC0 0x04020000
#define SMHC0_smhc_ctrl (SMHC0 + 0x0) // Control Register ()
#define SMHC0_smhc_ctrl_OFFSET 0x0
#define SMHC0_smhc_ctrl_fifo_ac_mod (0x1 << 31)
#define SMHC0_smhc_ctrl_fifo_ac_mod_SHIFT 31
#define SMHC0_smhc_ctrl_time_unit_cmd (0x1 << 12)
#define SMHC0_smhc_ctrl_time_unit_cmd_SHIFT 12
#define SMHC0_smhc_ctrl_time_unit_dat (0x1 << 11)
#define SMHC0_smhc_ctrl_time_unit_dat_SHIFT 11
#define SMHC0_smhc_ctrl_ddr_mod_sel (0x1 << 10)
#define SMHC0_smhc_ctrl_ddr_mod_sel_SHIFT 10
#define SMHC0_smhc_ctrl_cd_dbc_enb (0x1 << 8)
#define SMHC0_smhc_ctrl_cd_dbc_enb_SHIFT 8
#define SMHC0_smhc_ctrl_dma_enb (0x1 << 5)
#define SMHC0_smhc_ctrl_dma_enb_SHIFT 5
#define SMHC0_smhc_ctrl_ine_enb (0x1 << 4)
#define SMHC0_smhc_ctrl_ine_enb_SHIFT 4
#define SMHC0_smhc_ctrl_dma_rst (0x1 << 2)
#define SMHC0_smhc_ctrl_dma_rst_SHIFT 2
#define SMHC0_smhc_ctrl_fifo_rst (0x1 << 1)
#define SMHC0_smhc_ctrl_fifo_rst_SHIFT 1
#define SMHC0_smhc_ctrl_soft_rst 0x1
#define SMHC0_smhc_ctrl_soft_rst_SHIFT 0
#define SMHC0_smhc_clkdiv (SMHC0 + 0x4) // Clock Control Register ()
#define SMHC0_smhc_clkdiv_OFFSET 0x4
#define SMHC0_smhc_clkdiv_mask_data0 (0x1 << 31)
#define SMHC0_smhc_clkdiv_mask_data0_SHIFT 31
#define SMHC0_smhc_clkdiv_cclk_ctrl (0x1 << 17)
#define SMHC0_smhc_clkdiv_cclk_ctrl_SHIFT 17
#define SMHC0_smhc_clkdiv_cclk_enb (0x1 << 16)
#define SMHC0_smhc_clkdiv_cclk_enb_SHIFT 16
#define SMHC0_smhc_clkdiv_cclk_div 0xff
#define SMHC0_smhc_clkdiv_cclk_div_SHIFT 0
#define SMHC0_smhc_tmout (SMHC0 + 0x8) // Time Out Register ()
#define SMHC0_smhc_tmout_OFFSET 0x8
#define SMHC0_smhc_tmout_dto_lmt (0xffffff << 8)
#define SMHC0_smhc_tmout_dto_lmt_SHIFT 8
#define SMHC0_smhc_tmout_rto_lmt 0xff
#define SMHC0_smhc_tmout_rto_lmt_SHIFT 0
#define SMHC0_smhc_ctype (SMHC0 + 0xc) // Bus Width Register ()
#define SMHC0_smhc_ctype_OFFSET 0xc
#define SMHC0_smhc_ctype_card_wid 0x3
#define SMHC0_smhc_ctype_card_wid_SHIFT 0
#define SMHC0_smhc_blksiz (SMHC0 + 0x10) // Block Size Register ()
#define SMHC0_smhc_blksiz_OFFSET 0x10
#define SMHC0_smhc_blksiz_blk_sz 0xffff
#define SMHC0_smhc_blksiz_blk_sz_SHIFT 0
#define SMHC0_smhc_bytcnt (SMHC0 + 0x14) // Byte Count Register ()
#define SMHC0_smhc_bytcnt_OFFSET 0x14
#define SMHC0_smhc_cmd (SMHC0 + 0x18) // Command Register ()
#define SMHC0_smhc_cmd_OFFSET 0x18
#define SMHC0_smhc_cmd_cmd_load (0x1 << 31)
#define SMHC0_smhc_cmd_cmd_load_SHIFT 31
#define SMHC0_smhc_cmd_vol_sw (0x1 << 28)
#define SMHC0_smhc_cmd_vol_sw_SHIFT 28
#define SMHC0_smhc_cmd_boot_abt (0x1 << 27)
#define SMHC0_smhc_cmd_boot_abt_SHIFT 27
#define SMHC0_smhc_cmd_exp_boot_ack (0x1 << 26)
#define SMHC0_smhc_cmd_exp_boot_ack_SHIFT 26
#define SMHC0_smhc_cmd_boot_mod (0x3 << 24)
#define SMHC0_smhc_cmd_boot_mod_SHIFT 24
#define SMHC0_smhc_cmd_prg_clk (0x1 << 21)
#define SMHC0_smhc_cmd_prg_clk_SHIFT 21
#define SMHC0_smhc_cmd_send_init_seq (0x1 << 15)
#define SMHC0_smhc_cmd_send_init_seq_SHIFT 15
#define SMHC0_smhc_cmd_stop_abt_cmd (0x1 << 14)
#define SMHC0_smhc_cmd_stop_abt_cmd_SHIFT 14
#define SMHC0_smhc_cmd_wait_pre_over (0x1 << 13)
#define SMHC0_smhc_cmd_wait_pre_over_SHIFT 13
#define SMHC0_smhc_cmd_stop_cmd_flag (0x1 << 12)
#define SMHC0_smhc_cmd_stop_cmd_flag_SHIFT 12
#define SMHC0_smhc_cmd_trans_mode (0x1 << 11)
#define SMHC0_smhc_cmd_trans_mode_SHIFT 11
#define SMHC0_smhc_cmd_trans_dir (0x1 << 10)
#define SMHC0_smhc_cmd_trans_dir_SHIFT 10
#define SMHC0_smhc_cmd_data_trans (0x1 << 9)
#define SMHC0_smhc_cmd_data_trans_SHIFT 9
#define SMHC0_smhc_cmd_chk_resp_crc (0x1 << 8)
#define SMHC0_smhc_cmd_chk_resp_crc_SHIFT 8
#define SMHC0_smhc_cmd_long_resp (0x1 << 7)
#define SMHC0_smhc_cmd_long_resp_SHIFT 7
#define SMHC0_smhc_cmd_resp_rcv (0x1 << 6)
#define SMHC0_smhc_cmd_resp_rcv_SHIFT 6
#define SMHC0_smhc_cmd_cmd_idx 0x3f
#define SMHC0_smhc_cmd_cmd_idx_SHIFT 0
#define SMHC0_smhc_cmdarg (SMHC0 + 0x1c) // Command Argument Register ()
#define SMHC0_smhc_cmdarg_OFFSET 0x1c
#define SMHC0_smhc_resp0 (SMHC0 + 0x20) // Response 0 Register (R only)
#define SMHC0_smhc_resp0_OFFSET 0x20
#define SMHC0_smhc_resp1 (SMHC0 + 0x24) // Response 1 Register (R only)
#define SMHC0_smhc_resp1_OFFSET 0x24
#define SMHC0_smhc_resp2 (SMHC0 + 0x28) // Response 2 Register (R only)
#define SMHC0_smhc_resp2_OFFSET 0x28
#define SMHC0_smhc_resp3 (SMHC0 + 0x2c) // Response 3 Register (R only)
#define SMHC0_smhc_resp3_OFFSET 0x2c
#define SMHC0_smhc_intmask (SMHC0 + 0x30) // Interrupt Mask Register ()
#define SMHC0_smhc_intmask_OFFSET 0x30
#define SMHC0_smhc_intmask_card_removal_int_en (0x1 << 31)
#define SMHC0_smhc_intmask_card_removal_int_en_SHIFT 31
#define SMHC0_smhc_intmask_card_insert_int_en (0x1 << 30)
#define SMHC0_smhc_intmask_card_insert_int_en_SHIFT 30
#define SMHC0_smhc_intmask_sdio_int_en (0x1 << 16)
#define SMHC0_smhc_intmask_sdio_int_en_SHIFT 16
#define SMHC0_smhc_intmask_dee_int_en (0x1 << 15)
#define SMHC0_smhc_intmask_dee_int_en_SHIFT 15
#define SMHC0_smhc_intmask_acd_int_en (0x1 << 14)
#define SMHC0_smhc_intmask_acd_int_en_SHIFT 14
#define SMHC0_smhc_intmask_dse_bc_int_en (0x1 << 13)
#define SMHC0_smhc_intmask_dse_bc_int_en_SHIFT 13
#define SMHC0_smhc_intmask_cb_iw_int_en (0x1 << 12)
#define SMHC0_smhc_intmask_cb_iw_int_en_SHIFT 12
#define SMHC0_smhc_intmask_fu_fo_int_en (0x1 << 11)
#define SMHC0_smhc_intmask_fu_fo_int_en_SHIFT 11
#define SMHC0_smhc_intmask_dsto_vsd_int_en (0x1 << 10)
#define SMHC0_smhc_intmask_dsto_vsd_int_en_SHIFT 10
#define SMHC0_smhc_intmask_dto_bds_int_en (0x1 << 9)
#define SMHC0_smhc_intmask_dto_bds_int_en_SHIFT 9
#define SMHC0_smhc_intmask_rto_back_int_en (0x1 << 8)
#define SMHC0_smhc_intmask_rto_back_int_en_SHIFT 8
#define SMHC0_smhc_intmask_dce_int_en (0x1 << 7)
#define SMHC0_smhc_intmask_dce_int_en_SHIFT 7
#define SMHC0_smhc_intmask_rce_int_en (0x1 << 6)
#define SMHC0_smhc_intmask_rce_int_en_SHIFT 6
#define SMHC0_smhc_intmask_drr_int_en (0x1 << 5)
#define SMHC0_smhc_intmask_drr_int_en_SHIFT 5
#define SMHC0_smhc_intmask_dtr_int_en (0x1 << 4)
#define SMHC0_smhc_intmask_dtr_int_en_SHIFT 4
#define SMHC0_smhc_intmask_dtc_int_en (0x1 << 3)
#define SMHC0_smhc_intmask_dtc_int_en_SHIFT 3
#define SMHC0_smhc_intmask_cc_int_en (0x1 << 2)
#define SMHC0_smhc_intmask_cc_int_en_SHIFT 2
#define SMHC0_smhc_intmask_re_int_en (0x1 << 1)
#define SMHC0_smhc_intmask_re_int_en_SHIFT 1
#define SMHC0_smhc_mintsts (SMHC0 + 0x34) // Masked Interrupt Status Register (R only)
#define SMHC0_smhc_mintsts_OFFSET 0x34
#define SMHC0_smhc_mintsts_m_card_removal_int (0x1 << 31)
#define SMHC0_smhc_mintsts_m_card_removal_int_SHIFT 31
#define SMHC0_smhc_mintsts_m_card_insert (0x1 << 30)
#define SMHC0_smhc_mintsts_m_card_insert_SHIFT 30
#define SMHC0_smhc_mintsts_m_sdio_int (0x1 << 16)
#define SMHC0_smhc_mintsts_m_sdio_int_SHIFT 16
#define SMHC0_smhc_mintsts_m_dee_int (0x1 << 15)
#define SMHC0_smhc_mintsts_m_dee_int_SHIFT 15
#define SMHC0_smhc_mintsts_m_acd_int (0x1 << 14)
#define SMHC0_smhc_mintsts_m_acd_int_SHIFT 14
#define SMHC0_smhc_mintsts_m_dse_bc_int (0x1 << 13)
#define SMHC0_smhc_mintsts_m_dse_bc_int_SHIFT 13
#define SMHC0_smhc_mintsts_m_cb_iw_int (0x1 << 12)
#define SMHC0_smhc_mintsts_m_cb_iw_int_SHIFT 12
#define SMHC0_smhc_mintsts_m_fu_fo_int (0x1 << 11)
#define SMHC0_smhc_mintsts_m_fu_fo_int_SHIFT 11
#define SMHC0_smhc_mintsts_m_dsto_vsd_int (0x1 << 10)
#define SMHC0_smhc_mintsts_m_dsto_vsd_int_SHIFT 10
#define SMHC0_smhc_mintsts_m_dto_bds_int (0x1 << 9)
#define SMHC0_smhc_mintsts_m_dto_bds_int_SHIFT 9
#define SMHC0_smhc_mintsts_m_rto_back_int (0x1 << 8)
#define SMHC0_smhc_mintsts_m_rto_back_int_SHIFT 8
#define SMHC0_smhc_mintsts_m_dce_int (0x1 << 7)
#define SMHC0_smhc_mintsts_m_dce_int_SHIFT 7
#define SMHC0_smhc_mintsts_m_rce_int (0x1 << 6)
#define SMHC0_smhc_mintsts_m_rce_int_SHIFT 6
#define SMHC0_smhc_mintsts_m_drr_int (0x1 << 5)
#define SMHC0_smhc_mintsts_m_drr_int_SHIFT 5
#define SMHC0_smhc_mintsts_m_dtr_int (0x1 << 4)
#define SMHC0_smhc_mintsts_m_dtr_int_SHIFT 4
#define SMHC0_smhc_mintsts_m_dtc_int (0x1 << 3)
#define SMHC0_smhc_mintsts_m_dtc_int_SHIFT 3
#define SMHC0_smhc_mintsts_m_cc_int (0x1 << 2)
#define SMHC0_smhc_mintsts_m_cc_int_SHIFT 2
#define SMHC0_smhc_mintsts_m_re_int (0x1 << 1)
#define SMHC0_smhc_mintsts_m_re_int_SHIFT 1
#define SMHC0_smhc_rintsts (SMHC0 + 0x38) // Raw Interrupt Status Register ()
#define SMHC0_smhc_rintsts_OFFSET 0x38
#define SMHC0_smhc_rintsts_card_removal (0x1 << 31)
#define SMHC0_smhc_rintsts_card_removal_SHIFT 31
#define SMHC0_smhc_rintsts_card_insert (0x1 << 30)
#define SMHC0_smhc_rintsts_card_insert_SHIFT 30
#define SMHC0_smhc_rintsts_sdioi_int (0x1 << 16)
#define SMHC0_smhc_rintsts_sdioi_int_SHIFT 16
#define SMHC0_smhc_rintsts_dee (0x1 << 15)
#define SMHC0_smhc_rintsts_dee_SHIFT 15
#define SMHC0_smhc_rintsts_acd (0x1 << 14)
#define SMHC0_smhc_rintsts_acd_SHIFT 14
#define SMHC0_smhc_rintsts_dse_bc (0x1 << 13)
#define SMHC0_smhc_rintsts_dse_bc_SHIFT 13
#define SMHC0_smhc_rintsts_cb_iw (0x1 << 12)
#define SMHC0_smhc_rintsts_cb_iw_SHIFT 12
#define SMHC0_smhc_rintsts_fu_fo (0x1 << 11)
#define SMHC0_smhc_rintsts_fu_fo_SHIFT 11
#define SMHC0_smhc_rintsts_dsto_vsd (0x1 << 10)
#define SMHC0_smhc_rintsts_dsto_vsd_SHIFT 10
#define SMHC0_smhc_rintsts_dto_bds (0x1 << 9)
#define SMHC0_smhc_rintsts_dto_bds_SHIFT 9
#define SMHC0_smhc_rintsts_rto_back (0x1 << 8)
#define SMHC0_smhc_rintsts_rto_back_SHIFT 8
#define SMHC0_smhc_rintsts_dce (0x1 << 7)
#define SMHC0_smhc_rintsts_dce_SHIFT 7
#define SMHC0_smhc_rintsts_rce (0x1 << 6)
#define SMHC0_smhc_rintsts_rce_SHIFT 6
#define SMHC0_smhc_rintsts_drr (0x1 << 5)
#define SMHC0_smhc_rintsts_drr_SHIFT 5
#define SMHC0_smhc_rintsts_dtr (0x1 << 4)
#define SMHC0_smhc_rintsts_dtr_SHIFT 4
#define SMHC0_smhc_rintsts_dtc (0x1 << 3)
#define SMHC0_smhc_rintsts_dtc_SHIFT 3
#define SMHC0_smhc_rintsts_cc (0x1 << 2)
#define SMHC0_smhc_rintsts_cc_SHIFT 2
#define SMHC0_smhc_rintsts_re (0x1 << 1)
#define SMHC0_smhc_rintsts_re_SHIFT 1
#define SMHC0_smhc_status (SMHC0 + 0x3c) // Status Register (R only)
#define SMHC0_smhc_status_OFFSET 0x3c
#define SMHC0_smhc_status_dma_req (0x1 << 31)
#define SMHC0_smhc_status_dma_req_SHIFT 31
#define SMHC0_smhc_status_fifo_level (0x1ff << 17)
#define SMHC0_smhc_status_fifo_level_SHIFT 17
#define SMHC0_smhc_status_resp_idx (0x3f << 11)
#define SMHC0_smhc_status_resp_idx_SHIFT 11
#define SMHC0_smhc_status_fsm_busy (0x1 << 10)
#define SMHC0_smhc_status_fsm_busy_SHIFT 10
#define SMHC0_smhc_status_card_busy (0x1 << 9)
#define SMHC0_smhc_status_card_busy_SHIFT 9
#define SMHC0_smhc_status_card_present (0x1 << 8)
#define SMHC0_smhc_status_card_present_SHIFT 8
#define SMHC0_smhc_status_fsm_sta (0xf << 4)
#define SMHC0_smhc_status_fsm_sta_SHIFT 4
#define SMHC0_smhc_status_fifo_full (0x1 << 3)
#define SMHC0_smhc_status_fifo_full_SHIFT 3
#define SMHC0_smhc_status_fifo_empty (0x1 << 2)
#define SMHC0_smhc_status_fifo_empty_SHIFT 2
#define SMHC0_smhc_status_fifo_tx_level (0x1 << 1)
#define SMHC0_smhc_status_fifo_tx_level_SHIFT 1
#define SMHC0_smhc_status_fifo_rx_level 0x1
#define SMHC0_smhc_status_fifo_rx_level_SHIFT 0
#define SMHC0_smhc_fifoth (SMHC0 + 0x40) // FIFO Water Level Register ()
#define SMHC0_smhc_fifoth_OFFSET 0x40
#define SMHC0_smhc_fifoth_bsize_of_trans (0x7 << 28)
#define SMHC0_smhc_fifoth_bsize_of_trans_SHIFT 28
#define SMHC0_smhc_fifoth_rx_tl (0xff << 16)
#define SMHC0_smhc_fifoth_rx_tl_SHIFT 16
#define SMHC0_smhc_fifoth_tx_tl 0xff
#define SMHC0_smhc_fifoth_tx_tl_SHIFT 0
#define SMHC0_smhc_funs (SMHC0 + 0x44) // FIFO Function Select Register ()
#define SMHC0_smhc_funs_OFFSET 0x44
#define SMHC0_smhc_funs_abt_rdata (0x1 << 2)
#define SMHC0_smhc_funs_abt_rdata_SHIFT 2
#define SMHC0_smhc_funs_read_wait (0x1 << 1)
#define SMHC0_smhc_funs_read_wait_SHIFT 1
#define SMHC0_smhc_funs_host_send_mimc_irqresq 0x1
#define SMHC0_smhc_funs_host_send_mimc_irqresq_SHIFT 0
#define SMHC0_smhc_tbc0 (SMHC0 + 0x48) // Transferred Byte Count between Controller and Card (R only)
#define SMHC0_smhc_tbc0_OFFSET 0x48
#define SMHC0_smhc_tbc1 (SMHC0 + 0x4c) // Transferred Byte Count between Host Memory and Internal FIFO (R only)
#define SMHC0_smhc_tbc1_OFFSET 0x4c
#define SMHC0_smhc_dbgc (SMHC0 + 0x50) // Current Debug Control Register ()
#define SMHC0_smhc_dbgc_OFFSET 0x50
#define SMHC0_smhc_csdc (SMHC0 + 0x54) // CRC Status Detect Control Registers ()
#define SMHC0_smhc_csdc_OFFSET 0x54
#define SMHC0_smhc_csdc_crc_det_para 0xf
#define SMHC0_smhc_csdc_crc_det_para_SHIFT 0
#define SMHC0_smhc_a12a (SMHC0 + 0x58) // Auto Command 12 Argument Register ()
#define SMHC0_smhc_a12a_OFFSET 0x58
#define SMHC0_smhc_a12a_sd_a12a 0xffff
#define SMHC0_smhc_a12a_sd_a12a_SHIFT 0
#define SMHC0_smhc_ntsr (SMHC0 + 0x5c) // SD New Timing Set Register ()
#define SMHC0_smhc_ntsr_OFFSET 0x5c
#define SMHC0_smhc_ntsr_mode_select (0x1 << 31)
#define SMHC0_smhc_ntsr_mode_select_SHIFT 31
#define SMHC0_smhc_ntsr_cmd_dat_rx_phase_clr (0x1 << 24)
#define SMHC0_smhc_ntsr_cmd_dat_rx_phase_clr_SHIFT 24
#define SMHC0_smhc_ntsr_dat_crc_status_rx_phase_clr (0x1 << 22)
#define SMHC0_smhc_ntsr_dat_crc_status_rx_phase_clr_SHIFT 22
#define SMHC0_smhc_ntsr_dat_trans_rx_phase_clr (0x1 << 21)
#define SMHC0_smhc_ntsr_dat_trans_rx_phase_clr_SHIFT 21
#define SMHC0_smhc_ntsr_dat_recv_rx_phase_clr (0x1 << 20)
#define SMHC0_smhc_ntsr_dat_recv_rx_phase_clr_SHIFT 20
#define SMHC0_smhc_ntsr_cmd_send_rx_phase_clr (0x1 << 16)
#define SMHC0_smhc_ntsr_cmd_send_rx_phase_clr_SHIFT 16
#define SMHC0_smhc_ntsr_dat_sample_timing_phase (0x3 << 8)
#define SMHC0_smhc_ntsr_dat_sample_timing_phase_SHIFT 8
#define SMHC0_smhc_ntsr_cmd_sample_timing_phase (0x3 << 4)
#define SMHC0_smhc_ntsr_cmd_sample_timing_phase_SHIFT 4
#define SMHC0_smhc_ntsr_hs400_new_sample_en 0x1
#define SMHC0_smhc_ntsr_hs400_new_sample_en_SHIFT 0
#define SMHC0_smhc_hwrst (SMHC0 + 0x78) // Hardware Reset Register ()
#define SMHC0_smhc_hwrst_OFFSET 0x78
#define SMHC0_smhc_hwrst_hw_rst 0x1
#define SMHC0_smhc_hwrst_hw_rst_SHIFT 0
#define SMHC0_smhc_idmac (SMHC0 + 0x80) // IDMAC Control Register ()
#define SMHC0_smhc_idmac_OFFSET 0x80
#define SMHC0_smhc_idmac_des_load_ctrl (0x1 << 31)
#define SMHC0_smhc_idmac_des_load_ctrl_SHIFT 31
#define SMHC0_smhc_idmac_idmac_enb (0x1 << 7)
#define SMHC0_smhc_idmac_idmac_enb_SHIFT 7
#define SMHC0_smhc_idmac_fix_bust_ctrl (0x1 << 1)
#define SMHC0_smhc_idmac_fix_bust_ctrl_SHIFT 1
#define SMHC0_smhc_idmac_idmac_rst 0x1
#define SMHC0_smhc_idmac_idmac_rst_SHIFT 0
#define SMHC0_smhc_dlba (SMHC0 + 0x84) // Descriptor List Base Address Register ()
#define SMHC0_smhc_dlba_OFFSET 0x84
#define SMHC0_smhc_idst (SMHC0 + 0x88) // IDMAC Status Register ()
#define SMHC0_smhc_idst_OFFSET 0x88
#define SMHC0_smhc_idst_idmac_err_sta (0x7 << 10)
#define SMHC0_smhc_idst_idmac_err_sta_SHIFT 10
#define SMHC0_smhc_idst_abn_int_sum (0x1 << 9)
#define SMHC0_smhc_idst_abn_int_sum_SHIFT 9
#define SMHC0_smhc_idst_nor_int_sum (0x1 << 8)
#define SMHC0_smhc_idst_nor_int_sum_SHIFT 8
#define SMHC0_smhc_idst_err_flag_sum (0x1 << 5)
#define SMHC0_smhc_idst_err_flag_sum_SHIFT 5
#define SMHC0_smhc_idst_des_unavl_int (0x1 << 4)
#define SMHC0_smhc_idst_des_unavl_int_SHIFT 4
#define SMHC0_smhc_idst_fatal_berr_int (0x1 << 2)
#define SMHC0_smhc_idst_fatal_berr_int_SHIFT 2
#define SMHC0_smhc_idst_rx_int (0x1 << 1)
#define SMHC0_smhc_idst_rx_int_SHIFT 1
#define SMHC0_smhc_idst_tx_int 0x1
#define SMHC0_smhc_idst_tx_int_SHIFT 0
#define SMHC0_smhc_idie (SMHC0 + 0x8c) // IDMAC Interrupt Enable Register ()
#define SMHC0_smhc_idie_OFFSET 0x8c
#define SMHC0_smhc_idie_err_sum_int_enb (0x1 << 5)
#define SMHC0_smhc_idie_err_sum_int_enb_SHIFT 5
#define SMHC0_smhc_idie_des_unavl_int_enb (0x1 << 4)
#define SMHC0_smhc_idie_des_unavl_int_enb_SHIFT 4
#define SMHC0_smhc_idie_ferr_int_enb (0x1 << 2)
#define SMHC0_smhc_idie_ferr_int_enb_SHIFT 2
#define SMHC0_smhc_idie_rx_int_enb (0x1 << 1)
#define SMHC0_smhc_idie_rx_int_enb_SHIFT 1
#define SMHC0_smhc_idie_tx_int_enb 0x1
#define SMHC0_smhc_idie_tx_int_enb_SHIFT 0
#define SMHC0_smhc_thld (SMHC0 + 0x100) // Card Threshold Control Register ()
#define SMHC0_smhc_thld_OFFSET 0x100
#define SMHC0_smhc_thld_card_wr_thld (0xfff << 16)
#define SMHC0_smhc_thld_card_wr_thld_SHIFT 16
#define SMHC0_smhc_thld_card_wr_thld_enb (0x1 << 2)
#define SMHC0_smhc_thld_card_wr_thld_enb_SHIFT 2
#define SMHC0_smhc_thld_bcig (0x1 << 1)
#define SMHC0_smhc_thld_bcig_SHIFT 1
#define SMHC0_smhc_thld_card_rd_thld_enb 0x1
#define SMHC0_smhc_thld_card_rd_thld_enb_SHIFT 0
#define SMHC0_smhc_sfc (SMHC0 + 0x104) // Sample FIFO Control Register ()
#define SMHC0_smhc_sfc_OFFSET 0x104
#define SMHC0_smhc_sfc_stop_clk_ctrl (0xf << 1)
#define SMHC0_smhc_sfc_stop_clk_ctrl_SHIFT 1
#define SMHC0_smhc_sfc_bypass_en 0x1
#define SMHC0_smhc_sfc_bypass_en_SHIFT 0
#define SMHC0_smhc_a23a (SMHC0 + 0x108) // Auto Command 23 Argument Register ()
#define SMHC0_smhc_a23a_OFFSET 0x108
#define SMHC0_emmc_ddr_sbit_det (SMHC0 + 0x10c) // eMMC4.5 DDR Start Bit Detection Control Register ()
#define SMHC0_emmc_ddr_sbit_det_OFFSET 0x10c
#define SMHC0_emmc_ddr_sbit_det_hs400_md_en (0x1 << 31)
#define SMHC0_emmc_ddr_sbit_det_hs400_md_en_SHIFT 31
#define SMHC0_emmc_ddr_sbit_det_half_start_bit 0x1
#define SMHC0_emmc_ddr_sbit_det_half_start_bit_SHIFT 0
#define SMHC0_smhc_ext_cmd (SMHC0 + 0x138) // Extended Command Register ()
#define SMHC0_smhc_ext_cmd_OFFSET 0x138
#define SMHC0_smhc_ext_cmd_auto_cmd23_en 0x1
#define SMHC0_smhc_ext_cmd_auto_cmd23_en_SHIFT 0
#define SMHC0_smhc_ext_resp (SMHC0 + 0x13c) // Extended Response Register (R only)
#define SMHC0_smhc_ext_resp_OFFSET 0x13c
#define SMHC0_smhc_drv_dl (SMHC0 + 0x140) // Drive Delay Control Register ()
#define SMHC0_smhc_drv_dl_OFFSET 0x140
#define SMHC0_smhc_drv_dl_dat_drv_ph_sel (0x1 << 17)
#define SMHC0_smhc_drv_dl_dat_drv_ph_sel_SHIFT 17
#define SMHC0_smhc_drv_dl_cmd_drv_ph_sel (0x1 << 16)
#define SMHC0_smhc_drv_dl_cmd_drv_ph_sel_SHIFT 16
#define SMHC0_smhc_smap_dl (SMHC0 + 0x144) // Sample Delay Control Register ()
#define SMHC0_smhc_smap_dl_OFFSET 0x144
#define SMHC0_smhc_smap_dl_samp_dl_cal_start (0x1 << 15)
#define SMHC0_smhc_smap_dl_samp_dl_cal_start_SHIFT 15
#define SMHC0_smhc_smap_dl_samp_dl_cal_done (0x1 << 14)
#define SMHC0_smhc_smap_dl_samp_dl_cal_done_SHIFT 14
#define SMHC0_smhc_smap_dl_samp_dl (0x3f << 8)
#define SMHC0_smhc_smap_dl_samp_dl_SHIFT 8
#define SMHC0_smhc_smap_dl_samp_dl_sw_en (0x1 << 7)
#define SMHC0_smhc_smap_dl_samp_dl_sw_en_SHIFT 7
#define SMHC0_smhc_smap_dl_samp_dl_sw 0x3f
#define SMHC0_smhc_smap_dl_samp_dl_sw_SHIFT 0
#define SMHC0_smhc_ds_dl (SMHC0 + 0x148) // Data Strobe Delay Control Register ()
#define SMHC0_smhc_ds_dl_OFFSET 0x148
#define SMHC0_smhc_ds_dl_ds_dl_cal_start (0x1 << 15)
#define SMHC0_smhc_ds_dl_ds_dl_cal_start_SHIFT 15
#define SMHC0_smhc_ds_dl_ds_dl_cal_done (0x1 << 14)
#define SMHC0_smhc_ds_dl_ds_dl_cal_done_SHIFT 14
#define SMHC0_smhc_ds_dl_ds_dl (0x3f << 8)
#define SMHC0_smhc_ds_dl_ds_dl_SHIFT 8
#define SMHC0_smhc_ds_dl_ds_dl_sw_en (0x1 << 7)
#define SMHC0_smhc_ds_dl_ds_dl_sw_en_SHIFT 7
#define SMHC0_smhc_ds_dl_ds_dl_sw 0x3f
#define SMHC0_smhc_ds_dl_ds_dl_sw_SHIFT 0
#define SMHC0_smhc_hs400_dl (SMHC0 + 0x14c) // HS400 Delay Control Register ()
#define SMHC0_smhc_hs400_dl_OFFSET 0x14c
#define SMHC0_smhc_hs400_dl_hs400_dl_cal_start (0x1 << 15)
#define SMHC0_smhc_hs400_dl_hs400_dl_cal_start_SHIFT 15
#define SMHC0_smhc_hs400_dl_hs400_dl_cal_done (0x1 << 14)
#define SMHC0_smhc_hs400_dl_hs400_dl_cal_done_SHIFT 14
#define SMHC0_smhc_hs400_dl_hs400_dl (0xf << 8)
#define SMHC0_smhc_hs400_dl_hs400_dl_SHIFT 8
#define SMHC0_smhc_hs400_dl_hs400_dl_sw_en (0x1 << 7)
#define SMHC0_smhc_hs400_dl_hs400_dl_sw_en_SHIFT 7
#define SMHC0_smhc_hs400_dl_hs400_dl_sw 0xf
#define SMHC0_smhc_hs400_dl_hs400_dl_sw_SHIFT 0
#define SMHC0_smhc_fifo (SMHC0 + 0x200) // Read/Write FIFO ()
#define SMHC0_smhc_fifo_OFFSET 0x200

/****************************************************************
 * I2S/PCM
 ****************************************************************/
#define I2S_PCM0 0x02032000
#define I2S_PCM0_i2s_pcm_ctl (I2S_PCM0 + 0x0) // I2S/PCM Control Register ()
#define I2S_PCM0_i2s_pcm_ctl_OFFSET 0x0
#define I2S_PCM0_i2s_pcm_ctl_rx_sync_en_start (0x1 << 21)
#define I2S_PCM0_i2s_pcm_ctl_rx_sync_en_start_SHIFT 21
#define I2S_PCM0_i2s_pcm_ctl_rx_sync_en (0x1 << 20)
#define I2S_PCM0_i2s_pcm_ctl_rx_sync_en_SHIFT 20
#define I2S_PCM0_i2s_pcm_ctl_bclk_out (0x1 << 18)
#define I2S_PCM0_i2s_pcm_ctl_bclk_out_SHIFT 18
#define I2S_PCM0_i2s_pcm_ctl_lrck_out (0x1 << 17)
#define I2S_PCM0_i2s_pcm_ctl_lrck_out_SHIFT 17
#define I2S_PCM0_i2s_pcm_ctl_dout0_en (0x1 << 8)
#define I2S_PCM0_i2s_pcm_ctl_dout0_en_SHIFT 8
#define I2S_PCM0_i2s_pcm_ctl_out_mute (0x1 << 6)
#define I2S_PCM0_i2s_pcm_ctl_out_mute_SHIFT 6
#define I2S_PCM0_i2s_pcm_ctl_mode_sel (0x3 << 4)
#define I2S_PCM0_i2s_pcm_ctl_mode_sel_SHIFT 4
#define I2S_PCM0_i2s_pcm_ctl_loopback (0x1 << 3)
#define I2S_PCM0_i2s_pcm_ctl_loopback_SHIFT 3
#define I2S_PCM0_i2s_pcm_ctl_txen (0x1 << 2)
#define I2S_PCM0_i2s_pcm_ctl_txen_SHIFT 2
#define I2S_PCM0_i2s_pcm_ctl_rxen (0x1 << 1)
#define I2S_PCM0_i2s_pcm_ctl_rxen_SHIFT 1
#define I2S_PCM0_i2s_pcm_ctl_gen 0x1
#define I2S_PCM0_i2s_pcm_ctl_gen_SHIFT 0
#define I2S_PCM0_i2s_pcm_fmt0 (I2S_PCM0 + 0x4) // I2S/PCM Format Register 0 ()
#define I2S_PCM0_i2s_pcm_fmt0_OFFSET 0x4
#define I2S_PCM0_i2s_pcm_fmt0_lrck_width (0x1 << 30)
#define I2S_PCM0_i2s_pcm_fmt0_lrck_width_SHIFT 30
#define I2S_PCM0_i2s_pcm_fmt0_lrck_polarity (0x1 << 19)
#define I2S_PCM0_i2s_pcm_fmt0_lrck_polarity_SHIFT 19
#define I2S_PCM0_i2s_pcm_fmt0_lrck_period (0x3ff << 8)
#define I2S_PCM0_i2s_pcm_fmt0_lrck_period_SHIFT 8
#define I2S_PCM0_i2s_pcm_fmt0_blck_polarity (0x1 << 7)
#define I2S_PCM0_i2s_pcm_fmt0_blck_polarity_SHIFT 7
#define I2S_PCM0_i2s_pcm_fmt0_sr (0x7 << 4)
#define I2S_PCM0_i2s_pcm_fmt0_sr_SHIFT 4
#define I2S_PCM0_i2s_pcm_fmt0_edge_transfer (0x1 << 3)
#define I2S_PCM0_i2s_pcm_fmt0_edge_transfer_SHIFT 3
#define I2S_PCM0_i2s_pcm_fmt0_sw 0x7
#define I2S_PCM0_i2s_pcm_fmt0_sw_SHIFT 0
#define I2S_PCM0_i2s_pcm_fmt1 (I2S_PCM0 + 0x8) // I2S/PCM Format Register 1 ()
#define I2S_PCM0_i2s_pcm_fmt1_OFFSET 0x8
#define I2S_PCM0_i2s_pcm_fmt1_rx_mls (0x1 << 7)
#define I2S_PCM0_i2s_pcm_fmt1_rx_mls_SHIFT 7
#define I2S_PCM0_i2s_pcm_fmt1_tx_mls (0x1 << 6)
#define I2S_PCM0_i2s_pcm_fmt1_tx_mls_SHIFT 6
#define I2S_PCM0_i2s_pcm_fmt1_sext (0x3 << 4)
#define I2S_PCM0_i2s_pcm_fmt1_sext_SHIFT 4
#define I2S_PCM0_i2s_pcm_fmt1_rx_pdm (0x3 << 2)
#define I2S_PCM0_i2s_pcm_fmt1_rx_pdm_SHIFT 2
#define I2S_PCM0_i2s_pcm_fmt1_tx_pdm 0x3
#define I2S_PCM0_i2s_pcm_fmt1_tx_pdm_SHIFT 0
#define I2S_PCM0_i2s_pcm_ista (I2S_PCM0 + 0xc) // I2S/PCM Interrupt Status Register ()
#define I2S_PCM0_i2s_pcm_ista_OFFSET 0xc
#define I2S_PCM0_i2s_pcm_ista_txu_int (0x1 << 6)
#define I2S_PCM0_i2s_pcm_ista_txu_int_SHIFT 6
#define I2S_PCM0_i2s_pcm_ista_txo_int (0x1 << 5)
#define I2S_PCM0_i2s_pcm_ista_txo_int_SHIFT 5
#define I2S_PCM0_i2s_pcm_ista_txe_int (0x1 << 4)
#define I2S_PCM0_i2s_pcm_ista_txe_int_SHIFT 4
#define I2S_PCM0_i2s_pcm_ista_rxu_int (0x1 << 6)
#define I2S_PCM0_i2s_pcm_ista_rxu_int_SHIFT 6
#define I2S_PCM0_i2s_pcm_ista_rxo_int (0x1 << 5)
#define I2S_PCM0_i2s_pcm_ista_rxo_int_SHIFT 5
#define I2S_PCM0_i2s_pcm_ista_rxa_int (0x1 << 4)
#define I2S_PCM0_i2s_pcm_ista_rxa_int_SHIFT 4
#define I2S_PCM0_i2s_pcm_rxfifo (I2S_PCM0 + 0x10) // I2S/PCM RXFIFO Register ()
#define I2S_PCM0_i2s_pcm_rxfifo_OFFSET 0x10
#define I2S_PCM0_i2s_pcm_rxfifo_rx_data 0xffffffff
#define I2S_PCM0_i2s_pcm_rxfifo_rx_data_SHIFT 0
#define I2S_PCM0_i2s_pcm_fctl (I2S_PCM0 + 0x14) // I2S/PCM FIFO Control Register ()
#define I2S_PCM0_i2s_pcm_fctl_OFFSET 0x14
#define I2S_PCM0_i2s_pcm_fctl_hub_en (0x1 << 31)
#define I2S_PCM0_i2s_pcm_fctl_hub_en_SHIFT 31
#define I2S_PCM0_i2s_pcm_fctl_ftx (0x1 << 25)
#define I2S_PCM0_i2s_pcm_fctl_ftx_SHIFT 25
#define I2S_PCM0_i2s_pcm_fctl_frx (0x1 << 24)
#define I2S_PCM0_i2s_pcm_fctl_frx_SHIFT 24
#define I2S_PCM0_i2s_pcm_fctl_txtl (0x7f << 12)
#define I2S_PCM0_i2s_pcm_fctl_txtl_SHIFT 12
#define I2S_PCM0_i2s_pcm_fctl_rxtl (0x3f << 4)
#define I2S_PCM0_i2s_pcm_fctl_rxtl_SHIFT 4
#define I2S_PCM0_i2s_pcm_fctl_txim (0x1 << 2)
#define I2S_PCM0_i2s_pcm_fctl_txim_SHIFT 2
#define I2S_PCM0_i2s_pcm_fctl_rxom 0x3
#define I2S_PCM0_i2s_pcm_fctl_rxom_SHIFT 0
#define I2S_PCM0_i2s_pcm_fsta (I2S_PCM0 + 0x18) // I2S/PCM FIFO Status Register ()
#define I2S_PCM0_i2s_pcm_fsta_OFFSET 0x18
#define I2S_PCM0_i2s_pcm_fsta_txe (0x1 << 28)
#define I2S_PCM0_i2s_pcm_fsta_txe_SHIFT 28
#define I2S_PCM0_i2s_pcm_fsta_txe_cnt (0xff << 16)
#define I2S_PCM0_i2s_pcm_fsta_txe_cnt_SHIFT 16
#define I2S_PCM0_i2s_pcm_fsta_rxa (0x1 << 8)
#define I2S_PCM0_i2s_pcm_fsta_rxa_SHIFT 8
#define I2S_PCM0_i2s_pcm_fsta_rxa_cnt 0x7f
#define I2S_PCM0_i2s_pcm_fsta_rxa_cnt_SHIFT 0
#define I2S_PCM0_i2s_pcm_int (I2S_PCM0 + 0x1c) // I2S/PCM DMA and Interrupt Control Register ()
#define I2S_PCM0_i2s_pcm_int_OFFSET 0x1c
#define I2S_PCM0_i2s_pcm_int_tx_drq (0x1 << 7)
#define I2S_PCM0_i2s_pcm_int_tx_drq_SHIFT 7
#define I2S_PCM0_i2s_pcm_int_txui_en (0x1 << 6)
#define I2S_PCM0_i2s_pcm_int_txui_en_SHIFT 6
#define I2S_PCM0_i2s_pcm_int_txoi_en (0x1 << 5)
#define I2S_PCM0_i2s_pcm_int_txoi_en_SHIFT 5
#define I2S_PCM0_i2s_pcm_int_txei_en (0x1 << 4)
#define I2S_PCM0_i2s_pcm_int_txei_en_SHIFT 4
#define I2S_PCM0_i2s_pcm_int_rx_drq (0x1 << 3)
#define I2S_PCM0_i2s_pcm_int_rx_drq_SHIFT 3
#define I2S_PCM0_i2s_pcm_int_rxui_en (0x1 << 2)
#define I2S_PCM0_i2s_pcm_int_rxui_en_SHIFT 2
#define I2S_PCM0_i2s_pcm_int_rxoi_en (0x1 << 1)
#define I2S_PCM0_i2s_pcm_int_rxoi_en_SHIFT 1
#define I2S_PCM0_i2s_pcm_int_rxai_en 0x1
#define I2S_PCM0_i2s_pcm_int_rxai_en_SHIFT 0
#define I2S_PCM0_i2s_pcm_txfifo (I2S_PCM0 + 0x20) // I2S/PCM TXFIFO Register ()
#define I2S_PCM0_i2s_pcm_txfifo_OFFSET 0x20
#define I2S_PCM0_i2s_pcm_txfifo_txdata 0xffffffff
#define I2S_PCM0_i2s_pcm_txfifo_txdata_SHIFT 0
#define I2S_PCM0_i2s_pcm_clkd (I2S_PCM0 + 0x24) // I2S/PCM Clock Divide Register ()
#define I2S_PCM0_i2s_pcm_clkd_OFFSET 0x24
#define I2S_PCM0_i2s_pcm_clkd_mclko_en (0x1 << 8)
#define I2S_PCM0_i2s_pcm_clkd_mclko_en_SHIFT 8
#define I2S_PCM0_i2s_pcm_clkd_bclkdiv (0xf << 4)
#define I2S_PCM0_i2s_pcm_clkd_bclkdiv_SHIFT 4
#define I2S_PCM0_i2s_pcm_clkd_mclkdiv 0xf
#define I2S_PCM0_i2s_pcm_clkd_mclkdiv_SHIFT 0
#define I2S_PCM0_i2s_pcm_txcnt (I2S_PCM0 + 0x28) // I2S/PCM TX Sample Counter Register ()
#define I2S_PCM0_i2s_pcm_txcnt_OFFSET 0x28
#define I2S_PCM0_i2s_pcm_txcnt_tx_cnt 0xffffffff
#define I2S_PCM0_i2s_pcm_txcnt_tx_cnt_SHIFT 0
#define I2S_PCM0_i2s_pcm_rxcnt (I2S_PCM0 + 0x2c) // I2S/PCM RX Sample Counter Register ()
#define I2S_PCM0_i2s_pcm_rxcnt_OFFSET 0x2c
#define I2S_PCM0_i2s_pcm_rxcnt_rx_cnt 0xffffffff
#define I2S_PCM0_i2s_pcm_rxcnt_rx_cnt_SHIFT 0
#define I2S_PCM0_i2s_pcm_chcfg (I2S_PCM0 + 0x30) // I2S/PCM Channel Configuration Register ()
#define I2S_PCM0_i2s_pcm_chcfg_OFFSET 0x30
#define I2S_PCM0_i2s_pcm_chcfg_tx_slot_hiz (0x1 << 9)
#define I2S_PCM0_i2s_pcm_chcfg_tx_slot_hiz_SHIFT 9
#define I2S_PCM0_i2s_pcm_chcfg_tx_state (0x1 << 8)
#define I2S_PCM0_i2s_pcm_chcfg_tx_state_SHIFT 8
#define I2S_PCM0_i2s_pcm_chcfg_rx_slot_num (0xf << 4)
#define I2S_PCM0_i2s_pcm_chcfg_rx_slot_num_SHIFT 4
#define I2S_PCM0_i2s_pcm_chcfg_tx_slot_num 0xf
#define I2S_PCM0_i2s_pcm_chcfg_tx_slot_num_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx0chsel (I2S_PCM0 + 0x34) // I2S/PCM TX0 Channel Select Register ()
#define I2S_PCM0_i2s_pcm_tx0chsel_OFFSET 0x34
#define I2S_PCM0_i2s_pcm_tx0chsel_offset (0x3 << 20)
#define I2S_PCM0_i2s_pcm_tx0chsel_offset_SHIFT 20
#define I2S_PCM0_i2s_pcm_tx0chsel_chsel (0xf << 16)
#define I2S_PCM0_i2s_pcm_tx0chsel_chsel_SHIFT 16
#define I2S_PCM0_i2s_pcm_tx0chsel_chen 0xffff
#define I2S_PCM0_i2s_pcm_tx0chsel_chen_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx1chsel (I2S_PCM0 + 0x38) // I2S/PCM TX1 Channel Select Register ()
#define I2S_PCM0_i2s_pcm_tx1chsel_OFFSET 0x38
#define I2S_PCM0_i2s_pcm_tx1chsel_offset (0x3 << 20)
#define I2S_PCM0_i2s_pcm_tx1chsel_offset_SHIFT 20
#define I2S_PCM0_i2s_pcm_tx1chsel_chsel (0xf << 16)
#define I2S_PCM0_i2s_pcm_tx1chsel_chsel_SHIFT 16
#define I2S_PCM0_i2s_pcm_tx1chsel_chen 0xffff
#define I2S_PCM0_i2s_pcm_tx1chsel_chen_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx2chsel (I2S_PCM0 + 0x3c) // I2S/PCM TX2 Channel Select Register ()
#define I2S_PCM0_i2s_pcm_tx2chsel_OFFSET 0x3c
#define I2S_PCM0_i2s_pcm_tx2chsel_offset (0x3 << 20)
#define I2S_PCM0_i2s_pcm_tx2chsel_offset_SHIFT 20
#define I2S_PCM0_i2s_pcm_tx2chsel_chsel (0xf << 16)
#define I2S_PCM0_i2s_pcm_tx2chsel_chsel_SHIFT 16
#define I2S_PCM0_i2s_pcm_tx2chsel_chen 0xffff
#define I2S_PCM0_i2s_pcm_tx2chsel_chen_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx3chsel (I2S_PCM0 + 0x40) // I2S/PCM TX3 Channel Select Register ()
#define I2S_PCM0_i2s_pcm_tx3chsel_OFFSET 0x40
#define I2S_PCM0_i2s_pcm_tx3chsel_offset (0x3 << 20)
#define I2S_PCM0_i2s_pcm_tx3chsel_offset_SHIFT 20
#define I2S_PCM0_i2s_pcm_tx3chsel_chsel (0xf << 16)
#define I2S_PCM0_i2s_pcm_tx3chsel_chsel_SHIFT 16
#define I2S_PCM0_i2s_pcm_tx3chsel_chen 0xffff
#define I2S_PCM0_i2s_pcm_tx3chsel_chen_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx0chmap0 (I2S_PCM0 + 0x44) // I2S/PCM TX0 Channel Mapping Register0 ()
#define I2S_PCM0_i2s_pcm_tx0chmap0_OFFSET 0x44
#define I2S_PCM0_i2s_pcm_tx0chmap0_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx0chmap0_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx0chmap1 (I2S_PCM0 + 0x48) // I2S/PCM TX0 Channel Mapping Register1 ()
#define I2S_PCM0_i2s_pcm_tx0chmap1_OFFSET 0x48
#define I2S_PCM0_i2s_pcm_tx0chmap1_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx0chmap1_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx1chmap0 (I2S_PCM0 + 0x4c) // I2S/PCM TX1 Channel Mapping Register0 ()
#define I2S_PCM0_i2s_pcm_tx1chmap0_OFFSET 0x4c
#define I2S_PCM0_i2s_pcm_tx1chmap0_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx1chmap0_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx1chmap1 (I2S_PCM0 + 0x50) // I2S/PCM TX1 Channel Mapping Register1 ()
#define I2S_PCM0_i2s_pcm_tx1chmap1_OFFSET 0x50
#define I2S_PCM0_i2s_pcm_tx1chmap1_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx1chmap1_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx2chmap0 (I2S_PCM0 + 0x54) // I2S/PCM TX2 Channel Mapping Register0 ()
#define I2S_PCM0_i2s_pcm_tx2chmap0_OFFSET 0x54
#define I2S_PCM0_i2s_pcm_tx2chmap0_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx2chmap0_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx2chmap1 (I2S_PCM0 + 0x58) // I2S/PCM TX2 Channel Mapping Register1 ()
#define I2S_PCM0_i2s_pcm_tx2chmap1_OFFSET 0x58
#define I2S_PCM0_i2s_pcm_tx2chmap1_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx2chmap1_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx3chmap0 (I2S_PCM0 + 0x5c) // I2S/PCM TX3 Channel Mapping Register0 ()
#define I2S_PCM0_i2s_pcm_tx3chmap0_OFFSET 0x5c
#define I2S_PCM0_i2s_pcm_tx3chmap0_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx3chmap0_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_tx3chmap1 (I2S_PCM0 + 0x60) // I2S/PCM TX3 Channel Mapping Register1 ()
#define I2S_PCM0_i2s_pcm_tx3chmap1_OFFSET 0x60
#define I2S_PCM0_i2s_pcm_tx3chmap1_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_tx3chmap1_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_rxchsel (I2S_PCM0 + 0x64) // I2S/PCM RX Channel Select Register ()
#define I2S_PCM0_i2s_pcm_rxchsel_OFFSET 0x64
#define I2S_PCM0_i2s_pcm_rxchsel_offset (0x3 << 20)
#define I2S_PCM0_i2s_pcm_rxchsel_offset_SHIFT 20
#define I2S_PCM0_i2s_pcm_rxchsel_chsel (0xf << 16)
#define I2S_PCM0_i2s_pcm_rxchsel_chsel_SHIFT 16
#define I2S_PCM0_i2s_pcm_rxchmap0 (I2S_PCM0 + 0x68) // I2S/PCM RX Channel Mapping Register0 ()
#define I2S_PCM0_i2s_pcm_rxchmap0_OFFSET 0x68
#define I2S_PCM0_i2s_pcm_rxchmap0_ch0_select (0x3 << 4)
#define I2S_PCM0_i2s_pcm_rxchmap0_ch0_select_SHIFT 4
#define I2S_PCM0_i2s_pcm_rxchmap0_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_rxchmap0_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_rxchmap1 (I2S_PCM0 + 0x6c) // I2S/PCM RX Channel Mapping Register1 ()
#define I2S_PCM0_i2s_pcm_rxchmap1_OFFSET 0x6c
#define I2S_PCM0_i2s_pcm_rxchmap1_ch0_select (0x3 << 4)
#define I2S_PCM0_i2s_pcm_rxchmap1_ch0_select_SHIFT 4
#define I2S_PCM0_i2s_pcm_rxchmap1_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_rxchmap1_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_rxchmap2 (I2S_PCM0 + 0x70) // I2S/PCM RX Channel Mapping Register2 ()
#define I2S_PCM0_i2s_pcm_rxchmap2_OFFSET 0x70
#define I2S_PCM0_i2s_pcm_rxchmap2_ch0_select (0x3 << 4)
#define I2S_PCM0_i2s_pcm_rxchmap2_ch0_select_SHIFT 4
#define I2S_PCM0_i2s_pcm_rxchmap2_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_rxchmap2_ch0_map_SHIFT 0
#define I2S_PCM0_i2s_pcm_rxchmap3 (I2S_PCM0 + 0x74) // I2S/PCM RX Channel Mapping Register3 ()
#define I2S_PCM0_i2s_pcm_rxchmap3_OFFSET 0x74
#define I2S_PCM0_i2s_pcm_rxchmap3_ch0_select (0x3 << 4)
#define I2S_PCM0_i2s_pcm_rxchmap3_ch0_select_SHIFT 4
#define I2S_PCM0_i2s_pcm_rxchmap3_ch0_map 0xf
#define I2S_PCM0_i2s_pcm_rxchmap3_ch0_map_SHIFT 0
#define I2S_PCM0_mclkcfg (I2S_PCM0 + 0x80) // ASRC MCLK Configuration Register ()
#define I2S_PCM0_mclkcfg_OFFSET 0x80
#define I2S_PCM0_mclkcfg_asrc_mclk_gate (0x1 << 16)
#define I2S_PCM0_mclkcfg_asrc_mclk_gate_SHIFT 16
#define I2S_PCM0_mclkcfg_asrc_mclk_freq_div_coe 0xf
#define I2S_PCM0_mclkcfg_asrc_mclk_freq_div_coe_SHIFT 0
#define I2S_PCM0_fsout_cfg (I2S_PCM0 + 0x84) // ASRC Out Sample Rate Configuration Register ()
#define I2S_PCM0_fsout_cfg_OFFSET 0x84
#define I2S_PCM0_fsout_cfg_fsout_gate (0x1 << 20)
#define I2S_PCM0_fsout_cfg_fsout_gate_SHIFT 20
#define I2S_PCM0_fsin_extcfg (I2S_PCM0 + 0x88) // ASRC Input Sample Pulse Extend Configuration Register ()
#define I2S_PCM0_fsin_extcfg_OFFSET 0x88
#define I2S_PCM0_fsin_extcfg_extend (0x1 << 16)
#define I2S_PCM0_fsin_extcfg_extend_SHIFT 16
#define I2S_PCM0_fsin_extcfg_cyclenum 0xffff
#define I2S_PCM0_fsin_extcfg_cyclenum_SHIFT 0
#define I2S_PCM0_asrcen (I2S_PCM0 + 0x8c) // ASRC Enable Register ()
#define I2S_PCM0_asrcen_OFFSET 0x8c
#define I2S_PCM0_asrcen_asrc_fn (0x1 << 31)
#define I2S_PCM0_asrcen_asrc_fn_SHIFT 31
#define I2S_PCM0_asrcmancfg (I2S_PCM0 + 0x90) // ASRC Manual Ratio Configuration Register ()
#define I2S_PCM0_asrcmancfg_OFFSET 0x90
#define I2S_PCM0_asrcmancfg_asrc_ratio_manual_en (0x1 << 31)
#define I2S_PCM0_asrcmancfg_asrc_ratio_manual_en_SHIFT 31
#define I2S_PCM0_asrcmancfg_asrc_ratio_value_manual_cfg 0x3ffffff
#define I2S_PCM0_asrcmancfg_asrc_ratio_value_manual_cfg_SHIFT 0
#define I2S_PCM0_asrcratiostat (I2S_PCM0 + 0x94) // ASRC Status Register ()
#define I2S_PCM0_asrcratiostat_OFFSET 0x94
#define I2S_PCM0_asrcratiostat_asrc_buf_overflow_sta (0x1 << 29)
#define I2S_PCM0_asrcratiostat_asrc_buf_overflow_sta_SHIFT 29
#define I2S_PCM0_asrcratiostat_adapt_comput_lock (0x1 << 28)
#define I2S_PCM0_asrcratiostat_adapt_comput_lock_SHIFT 28
#define I2S_PCM0_asrcratiostat_adapt_comput_value 0x3ffffff
#define I2S_PCM0_asrcratiostat_adapt_comput_value_SHIFT 0
#define I2S_PCM0_asrcfifostat (I2S_PCM0 + 0x98) // ASRC FIFO Level Status Register ()
#define I2S_PCM0_asrcfifostat_OFFSET 0x98
#define I2S_PCM0_asrcfifostat_asrc_rx_fifo_full_leval 0x1ff
#define I2S_PCM0_asrcfifostat_asrc_rx_fifo_full_leval_SHIFT 0
#define I2S_PCM0_asrcmbistcfg (I2S_PCM0 + 0x9c) // ASRC MBIST Test Configuration Register ()
#define I2S_PCM0_asrcmbistcfg_OFFSET 0x9c
#define I2S_PCM0_asrcmbistcfg_asrc_ram_bist_en (0x1 << 8)
#define I2S_PCM0_asrcmbistcfg_asrc_ram_bist_en_SHIFT 8
#define I2S_PCM0_asrcmbistcfg_asrc_rom_bist_en 0x1
#define I2S_PCM0_asrcmbistcfg_asrc_rom_bist_en_SHIFT 0
#define I2S_PCM0_asrcmbiststat (I2S_PCM0 + 0xa0) // ASRC MBIST Test Status Register ()
#define I2S_PCM0_asrcmbiststat_OFFSET 0xa0
#define I2S_PCM0_asrcmbiststat_rom_bist_error_xor (0x1 << 18)
#define I2S_PCM0_asrcmbiststat_rom_bist_error_xor_SHIFT 18
#define I2S_PCM0_asrcmbiststat_rom_bist_error_sum (0x1 << 17)
#define I2S_PCM0_asrcmbiststat_rom_bist_error_sum_SHIFT 17
#define I2S_PCM0_asrcmbiststat_rom_busy_status (0x1 << 16)
#define I2S_PCM0_asrcmbiststat_rom_busy_status_SHIFT 16
#define I2S_PCM0_asrcmbiststat_ram_bist_err_status (0x1 << 7)
#define I2S_PCM0_asrcmbiststat_ram_bist_err_status_SHIFT 7
#define I2S_PCM0_asrcmbiststat_ram_bist_error_pattern (0x7 << 4)
#define I2S_PCM0_asrcmbiststat_ram_bist_error_pattern_SHIFT 4
#define I2S_PCM0_asrcmbiststat_ram_bist_error_cycle (0x3 << 2)
#define I2S_PCM0_asrcmbiststat_ram_bist_error_cycle_SHIFT 2
#define I2S_PCM0_asrcmbiststat_ram_stop_status (0x1 << 1)
#define I2S_PCM0_asrcmbiststat_ram_stop_status_SHIFT 1
#define I2S_PCM0_asrcmbiststat_ram_busy_status 0x1
#define I2S_PCM0_asrcmbiststat_ram_busy_status_SHIFT 0

/****************************************************************
 * DMIC
 ****************************************************************/
#define DMIC 0x02031000
#define DMIC_dmic_en (DMIC + 0x0) // DMIC Enable Control Register ()
#define DMIC_dmic_en_OFFSET 0x0
#define DMIC_dmic_sr (DMIC + 0x4) // DMIC Sample Rate Register ()
#define DMIC_dmic_sr_OFFSET 0x4
#define DMIC_dmic_ctr (DMIC + 0x8) // DMIC Control Register ()
#define DMIC_dmic_ctr_OFFSET 0x8
#define DMIC_dmic_data (DMIC + 0x10) // DMIC Data Register ()
#define DMIC_dmic_data_OFFSET 0x10
#define DMIC_dmic_intc (DMIC + 0x14) // DMIC Interrupt Control Register ()
#define DMIC_dmic_intc_OFFSET 0x14
#define DMIC_dmic_ints (DMIC + 0x18) // DMIC Interrupt Status Register ()
#define DMIC_dmic_ints_OFFSET 0x18
#define DMIC_dmic_rxfifo_ctr (DMIC + 0x1c) // DMIC RXFIFO Control Register ()
#define DMIC_dmic_rxfifo_ctr_OFFSET 0x1c
#define DMIC_dmic_rxfifo_sta (DMIC + 0x20) // DMIC RXFIFO Status Register ()
#define DMIC_dmic_rxfifo_sta_OFFSET 0x20
#define DMIC_dmic_ch_num (DMIC + 0x24) // DMIC Channel Numbers Register ()
#define DMIC_dmic_ch_num_OFFSET 0x24
#define DMIC_dmic_ch_map (DMIC + 0x28) // DMIC Channel Mapping Register ()
#define DMIC_dmic_ch_map_OFFSET 0x28
#define DMIC_dmic_cnt (DMIC + 0x2c) // DMIC Counter Register ()
#define DMIC_dmic_cnt_OFFSET 0x2c
#define DMIC_data0_data1_vol_ctr (DMIC + 0x30) // Data0 and Data1 Volume Control Register ()
#define DMIC_data0_data1_vol_ctr_OFFSET 0x30
#define DMIC_data2_data3_vol_ctr (DMIC + 0x34) // Data2 And Data3 Volume Control Register ()
#define DMIC_data2_data3_vol_ctr_OFFSET 0x34
#define DMIC_hpf_en_ctr (DMIC + 0x38) // High Pass Filter Enable Control Register ()
#define DMIC_hpf_en_ctr_OFFSET 0x38
#define DMIC_hpf_coef (DMIC + 0x3c) // High Pass Filter Coefficient Register ()
#define DMIC_hpf_coef_OFFSET 0x3c
#define DMIC_hpf_gain (DMIC + 0x40) // High Pass Filter Gain Register ()
#define DMIC_hpf_gain_OFFSET 0x40

/****************************************************************
 * One Wire Audio
 ****************************************************************/
#define OWA 0x02036000
#define OWA_owa_gen_ctl (OWA + 0x0) // OWA General Control Register ()
#define OWA_owa_gen_ctl_OFFSET 0x0
#define OWA_owa_tx_cfig (OWA + 0x4) // OWA TX Configuration Register ()
#define OWA_owa_tx_cfig_OFFSET 0x4
#define OWA_owa_rx_cfig (OWA + 0x8) // OWA RX Configuration Register ()
#define OWA_owa_rx_cfig_OFFSET 0x8
#define OWA_owa_ista (OWA + 0xc) // OWA Interrupt Status Register ()
#define OWA_owa_ista_OFFSET 0xc
#define OWA_owa_rxfifo (OWA + 0x10) // OWA RXFIFO Register ()
#define OWA_owa_rxfifo_OFFSET 0x10
#define OWA_owa_fctl (OWA + 0x14) // OWA FIFO Control Register ()
#define OWA_owa_fctl_OFFSET 0x14
#define OWA_owa_fsta (OWA + 0x18) // OWA FIFO Status Register ()
#define OWA_owa_fsta_OFFSET 0x18
#define OWA_owa_int (OWA + 0x1c) // OWA Interrupt Control Register ()
#define OWA_owa_int_OFFSET 0x1c
#define OWA_owa_tx_fifo (OWA + 0x20) // OWA TX FIFO Register ()
#define OWA_owa_tx_fifo_OFFSET 0x20
#define OWA_owa_tx_cnt (OWA + 0x24) // OWA TX Counter Register ()
#define OWA_owa_tx_cnt_OFFSET 0x24
#define OWA_owa_rx_cnt (OWA + 0x28) // OWA RX Counter Register ()
#define OWA_owa_rx_cnt_OFFSET 0x28
#define OWA_owa_tx_chsta0 (OWA + 0x2c) // OWA TX Channel Status Register0 ()
#define OWA_owa_tx_chsta0_OFFSET 0x2c
#define OWA_owa_tx_chsta1 (OWA + 0x30) // OWA TX Channel Status Register1 ()
#define OWA_owa_tx_chsta1_OFFSET 0x30
#define OWA_owa_rxchsta0 (OWA + 0x34) // OWA RX Channel Status Register0 ()
#define OWA_owa_rxchsta0_OFFSET 0x34
#define OWA_owa_rxchsta1 (OWA + 0x38) // OWA RX Channel Status Register1 ()
#define OWA_owa_rxchsta1_OFFSET 0x38
#define OWA_owa_exp_ctl (OWA + 0x40) // OWA Expand Control Register ()
#define OWA_owa_exp_ctl_OFFSET 0x40
#define OWA_owa_exp_ista (OWA + 0x44) // OWA Expand Interrupt Status Register ()
#define OWA_owa_exp_ista_OFFSET 0x44
#define OWA_owa_exp_info_0 (OWA + 0x48) // OWA Expand Infomation Register0 ()
#define OWA_owa_exp_info_0_OFFSET 0x48
#define OWA_owa_exp_info_1 (OWA + 0x4c) // OWA Expand Infomation Register1 ()
#define OWA_owa_exp_info_1_OFFSET 0x4c
#define OWA_owa_exp_dbg_0 (OWA + 0x50) // OWA Expand Debug Register0 ()
#define OWA_owa_exp_dbg_0_OFFSET 0x50
#define OWA_owa_exp_dbg_1 (OWA + 0x54) // OWA Expand Debug Register1 ()
#define OWA_owa_exp_dbg_1_OFFSET 0x54

/****************************************************************
 * Audio Codec
 ****************************************************************/
#define AUDIO_CODEC 0x02030000
#define AUDIO_CODEC_ac_dac_dpc (AUDIO_CODEC + 0x0) // DAC Digital Part Control Register ()
#define AUDIO_CODEC_ac_dac_dpc_OFFSET 0x0
#define AUDIO_CODEC_ac_dac_dpc_en_da (0x1 << 31)
#define AUDIO_CODEC_ac_dac_dpc_en_da_SHIFT 31
#define AUDIO_CODEC_ac_dac_dpc_modqu (0xf << 25)
#define AUDIO_CODEC_ac_dac_dpc_modqu_SHIFT 25
#define AUDIO_CODEC_ac_dac_dpc_dwa (0x1 << 24)
#define AUDIO_CODEC_ac_dac_dpc_dwa_SHIFT 24
#define AUDIO_CODEC_ac_dac_dpc_hpf_en (0x1 << 18)
#define AUDIO_CODEC_ac_dac_dpc_hpf_en_SHIFT 18
#define AUDIO_CODEC_ac_dac_dpc_dvol (0x3f << 12)
#define AUDIO_CODEC_ac_dac_dpc_dvol_SHIFT 12
#define AUDIO_CODEC_ac_dac_dpc_hub_en 0x1
#define AUDIO_CODEC_ac_dac_dpc_hub_en_SHIFT 0
#define AUDIO_CODEC_dac_vol_ctrl (AUDIO_CODEC + 0x4) // DAC Volume Control Register ()
#define AUDIO_CODEC_dac_vol_ctrl_OFFSET 0x4
#define AUDIO_CODEC_dac_vol_ctrl_dac_vol_sel (0x1 << 16)
#define AUDIO_CODEC_dac_vol_ctrl_dac_vol_sel_SHIFT 16
#define AUDIO_CODEC_dac_vol_ctrl_dac_vol_l (0xff << 8)
#define AUDIO_CODEC_dac_vol_ctrl_dac_vol_l_SHIFT 8
#define AUDIO_CODEC_dac_vol_ctrl_dac_vol_r 0xff
#define AUDIO_CODEC_dac_vol_ctrl_dac_vol_r_SHIFT 0
#define AUDIO_CODEC_ac_dac_fifoc (AUDIO_CODEC + 0x10) // DAC FIFO Control Register ()
#define AUDIO_CODEC_ac_dac_fifoc_OFFSET 0x10
#define AUDIO_CODEC_ac_dac_fifoc_dac_fs (0x7 << 29)
#define AUDIO_CODEC_ac_dac_fifoc_dac_fs_SHIFT 29
#define AUDIO_CODEC_ac_dac_fifoc_fir_ver (0x1 << 28)
#define AUDIO_CODEC_ac_dac_fifoc_fir_ver_SHIFT 28
#define AUDIO_CODEC_ac_dac_fifoc_send_last (0x1 << 26)
#define AUDIO_CODEC_ac_dac_fifoc_send_last_SHIFT 26
#define AUDIO_CODEC_ac_dac_fifoc_fifo_mode (0x3 << 24)
#define AUDIO_CODEC_ac_dac_fifoc_fifo_mode_SHIFT 24
#define AUDIO_CODEC_ac_dac_fifoc_dac_drq_clr_cnt (0x7f << 8)
#define AUDIO_CODEC_ac_dac_fifoc_dac_drq_clr_cnt_SHIFT 8
#define AUDIO_CODEC_ac_dac_fifoc_tx_trig_level (0x7f << 8)
#define AUDIO_CODEC_ac_dac_fifoc_tx_trig_level_SHIFT 8
#define AUDIO_CODEC_ac_dac_fifoc_dac_mono_en (0x1 << 6)
#define AUDIO_CODEC_ac_dac_fifoc_dac_mono_en_SHIFT 6
#define AUDIO_CODEC_ac_dac_fifoc_tx_sample_bits (0x1 << 5)
#define AUDIO_CODEC_ac_dac_fifoc_tx_sample_bits_SHIFT 5
#define AUDIO_CODEC_ac_dac_fifoc_dac_drq_en (0x1 << 4)
#define AUDIO_CODEC_ac_dac_fifoc_dac_drq_en_SHIFT 4
#define AUDIO_CODEC_ac_dac_fifoc_dac_irq_en (0x1 << 3)
#define AUDIO_CODEC_ac_dac_fifoc_dac_irq_en_SHIFT 3
#define AUDIO_CODEC_ac_dac_fifoc_fifo_underrun_irq_en (0x1 << 2)
#define AUDIO_CODEC_ac_dac_fifoc_fifo_underrun_irq_en_SHIFT 2
#define AUDIO_CODEC_ac_dac_fifoc_fifo_overrun_irq_en (0x1 << 1)
#define AUDIO_CODEC_ac_dac_fifoc_fifo_overrun_irq_en_SHIFT 1
#define AUDIO_CODEC_ac_dac_fifoc_fifo_flush 0x1
#define AUDIO_CODEC_ac_dac_fifoc_fifo_flush_SHIFT 0
#define AUDIO_CODEC_ac_dac_fifos (AUDIO_CODEC + 0x14) // DAC FIFO Status Register ()
#define AUDIO_CODEC_ac_dac_fifos_OFFSET 0x14
#define AUDIO_CODEC_ac_dac_fifos_tx_empty (0x1 << 23)
#define AUDIO_CODEC_ac_dac_fifos_tx_empty_SHIFT 23
#define AUDIO_CODEC_ac_dac_fifos_txe_cnt (0x7fff << 8)
#define AUDIO_CODEC_ac_dac_fifos_txe_cnt_SHIFT 8
#define AUDIO_CODEC_ac_dac_fifos_txe_int (0x1 << 3)
#define AUDIO_CODEC_ac_dac_fifos_txe_int_SHIFT 3
#define AUDIO_CODEC_ac_dac_fifos_txu_int (0x1 << 2)
#define AUDIO_CODEC_ac_dac_fifos_txu_int_SHIFT 2
#define AUDIO_CODEC_ac_dac_fifos_txo_int (0x1 << 1)
#define AUDIO_CODEC_ac_dac_fifos_txo_int_SHIFT 1
#define AUDIO_CODEC_ac_dac_txdata (AUDIO_CODEC + 0x20) // DAC TX DATA Register (W only)
#define AUDIO_CODEC_ac_dac_txdata_OFFSET 0x20
#define AUDIO_CODEC_ac_dac_txdata_tx_data 0xffffffff
#define AUDIO_CODEC_ac_dac_txdata_tx_data_SHIFT 0
#define AUDIO_CODEC_ac_dac_cnt (AUDIO_CODEC + 0x24) // DAC TX FIFO Counter Register ()
#define AUDIO_CODEC_ac_dac_cnt_OFFSET 0x24
#define AUDIO_CODEC_ac_dac_cnt_tx_cnt 0xffffffff
#define AUDIO_CODEC_ac_dac_cnt_tx_cnt_SHIFT 0
#define AUDIO_CODEC_ac_dac_dg (AUDIO_CODEC + 0x28) // DAC Debug Register ()
#define AUDIO_CODEC_ac_dac_dg_OFFSET 0x28
#define AUDIO_CODEC_ac_dac_dg_dac_modu_select (0x1 << 11)
#define AUDIO_CODEC_ac_dac_dg_dac_modu_select_SHIFT 11
#define AUDIO_CODEC_ac_dac_dg_dac_pattern_select (0x3 << 9)
#define AUDIO_CODEC_ac_dac_dg_dac_pattern_select_SHIFT 9
#define AUDIO_CODEC_ac_dac_dg_codec_clk_select (0x1 << 8)
#define AUDIO_CODEC_ac_dac_dg_codec_clk_select_SHIFT 8
#define AUDIO_CODEC_ac_dac_dg_da_swp (0x1 << 6)
#define AUDIO_CODEC_ac_dac_dg_da_swp_SHIFT 6
#define AUDIO_CODEC_ac_dac_dg_adda_loop_mode 0x7
#define AUDIO_CODEC_ac_dac_dg_adda_loop_mode_SHIFT 0
#define AUDIO_CODEC_ac_adc_fifoc (AUDIO_CODEC + 0x30) // ADC FIFO Control Register ()
#define AUDIO_CODEC_ac_adc_fifoc_OFFSET 0x30
#define AUDIO_CODEC_ac_adc_fifoc_RESET 0x00000400
#define AUDIO_CODEC_ac_adc_fifoc_adfs (0x7 << 29)
#define AUDIO_CODEC_ac_adc_fifoc_adfs_SHIFT 29
#define AUDIO_CODEC_ac_adc_fifoc_en_ad (0x1 << 28)
#define AUDIO_CODEC_ac_adc_fifoc_en_ad_SHIFT 28
#define AUDIO_CODEC_ac_adc_fifoc_adcfdt (0x3 << 26)
#define AUDIO_CODEC_ac_adc_fifoc_adcfdt_SHIFT 26
#define AUDIO_CODEC_ac_adc_fifoc_adcdfen (0x1 << 25)
#define AUDIO_CODEC_ac_adc_fifoc_adcdfen_SHIFT 25
#define AUDIO_CODEC_ac_adc_fifoc_rx_fifo_mode (0x1 << 24)
#define AUDIO_CODEC_ac_adc_fifoc_rx_fifo_mode_SHIFT 24
#define AUDIO_CODEC_ac_adc_fifoc_rx_sync_en_start (0x1 << 21)
#define AUDIO_CODEC_ac_adc_fifoc_rx_sync_en_start_SHIFT 21
#define AUDIO_CODEC_ac_adc_fifoc_rx_sync_en (0x1 << 20)
#define AUDIO_CODEC_ac_adc_fifoc_rx_sync_en_SHIFT 20
#define AUDIO_CODEC_ac_adc_fifoc_rx_sample_bits (0x1 << 16)
#define AUDIO_CODEC_ac_adc_fifoc_rx_sample_bits_SHIFT 16
#define AUDIO_CODEC_ac_adc_fifoc_rx_fifo_trg_level (0xff << 4)
#define AUDIO_CODEC_ac_adc_fifoc_rx_fifo_trg_level_SHIFT 4
#define AUDIO_CODEC_ac_adc_fifoc_adc_drq_en (0x1 << 3)
#define AUDIO_CODEC_ac_adc_fifoc_adc_drq_en_SHIFT 3
#define AUDIO_CODEC_ac_adc_fifoc_adc_irq_en (0x1 << 2)
#define AUDIO_CODEC_ac_adc_fifoc_adc_irq_en_SHIFT 2
#define AUDIO_CODEC_ac_adc_fifoc_adc_overrun_irq_en (0x1 << 1)
#define AUDIO_CODEC_ac_adc_fifoc_adc_overrun_irq_en_SHIFT 1
#define AUDIO_CODEC_ac_adc_fifoc_adc_fifo_flush 0x1
#define AUDIO_CODEC_ac_adc_fifoc_adc_fifo_flush_SHIFT 0
#define AUDIO_CODEC_adc_vol_ctrl1 (AUDIO_CODEC + 0x34) // ADC Volume Control1 Register ()
#define AUDIO_CODEC_adc_vol_ctrl1_OFFSET 0x34
#define AUDIO_CODEC_adc_vol_ctrl1_RESET 0xA0A0A0A0
#define AUDIO_CODEC_adc_vol_ctrl1_adc0_vol 0xff
#define AUDIO_CODEC_adc_vol_ctrl1_adc0_vol_SHIFT 0
#define AUDIO_CODEC_ac_adc_fifos (AUDIO_CODEC + 0x38) // ADC FIFO Status Register ()
#define AUDIO_CODEC_ac_adc_fifos_OFFSET 0x38
#define AUDIO_CODEC_ac_adc_fifos_RESET 0x00000001
#define AUDIO_CODEC_ac_adc_fifos_rxa (0x1 << 23)
#define AUDIO_CODEC_ac_adc_fifos_rxa_SHIFT 23
#define AUDIO_CODEC_ac_adc_fifos_rxa_cnt (0x1ff << 8)
#define AUDIO_CODEC_ac_adc_fifos_rxa_cnt_SHIFT 8
#define AUDIO_CODEC_ac_adc_fifos_rxa_int (0x1 << 3)
#define AUDIO_CODEC_ac_adc_fifos_rxa_int_SHIFT 3
#define AUDIO_CODEC_ac_adc_fifos_rxo_int (0x1 << 1)
#define AUDIO_CODEC_ac_adc_fifos_rxo_int_SHIFT 1
#define AUDIO_CODEC_ac_adc_rxdata (AUDIO_CODEC + 0x40) // ADC RX Data Register ()
#define AUDIO_CODEC_ac_adc_rxdata_OFFSET 0x40
#define AUDIO_CODEC_ac_adc_rxdata_rx_data 0xffffffff
#define AUDIO_CODEC_ac_adc_rxdata_rx_data_SHIFT 0
#define AUDIO_CODEC_ac_adc_cnt (AUDIO_CODEC + 0x44) // ADC RX Counter Register ()
#define AUDIO_CODEC_ac_adc_cnt_OFFSET 0x44
#define AUDIO_CODEC_ac_adc_cnt_rx_cnt 0xffffffff
#define AUDIO_CODEC_ac_adc_cnt_rx_cnt_SHIFT 0
#define AUDIO_CODEC_ac_adc_dg (AUDIO_CODEC + 0x4c) // ADC Debug Register ()
#define AUDIO_CODEC_ac_adc_dg_OFFSET 0x4c
#define AUDIO_CODEC_ac_adc_dg_ad_swp2 (0x1 << 25)
#define AUDIO_CODEC_ac_adc_dg_ad_swp2_SHIFT 25
#define AUDIO_CODEC_ac_adc_dg_ad_swp1 (0x1 << 24)
#define AUDIO_CODEC_ac_adc_dg_ad_swp1_SHIFT 24
#define AUDIO_CODEC_adc_dig_ctrl (AUDIO_CODEC + 0x50) // ADC Digtial Control Register ()
#define AUDIO_CODEC_adc_dig_ctrl_OFFSET 0x50
#define AUDIO_CODEC_adc_dig_ctrl_adc3_vol_en (0x1 << 17)
#define AUDIO_CODEC_adc_dig_ctrl_adc3_vol_en_SHIFT 17
#define AUDIO_CODEC_adc_dig_ctrl_adc1_2_vol_en (0x1 << 16)
#define AUDIO_CODEC_adc_dig_ctrl_adc1_2_vol_en_SHIFT 16
#define AUDIO_CODEC_adc_dig_ctrl_adc_channel_en 0x7
#define AUDIO_CODEC_adc_dig_ctrl_adc_channel_en_SHIFT 0
#define AUDIO_CODEC_vra1speedup_ctrl (AUDIO_CODEC + 0x54) // VRA1 Speedup Down Control Register ()
#define AUDIO_CODEC_vra1speedup_ctrl_OFFSET 0x54
#define AUDIO_CODEC_vra1speedup_ctrl_vra1speedup_state (0x1 << 4)
#define AUDIO_CODEC_vra1speedup_ctrl_vra1speedup_state_SHIFT 4
#define AUDIO_CODEC_vra1speedup_ctrl_vra1speedup_ctrl (0x1 << 1)
#define AUDIO_CODEC_vra1speedup_ctrl_vra1speedup_ctrl_SHIFT 1
#define AUDIO_CODEC_vra1speedup_ctrl_vra1speedup_rst_ctrl 0x1
#define AUDIO_CODEC_vra1speedup_ctrl_vra1speedup_rst_ctrl_SHIFT 0
#define AUDIO_CODEC_ac_dac_dap_ctr (AUDIO_CODEC + 0xf0) // DAC DAP Control Register ()
#define AUDIO_CODEC_ac_dac_dap_ctr_OFFSET 0xf0
#define AUDIO_CODEC_ac_dac_dap_ctr_ddap_en (0x1 << 31)
#define AUDIO_CODEC_ac_dac_dap_ctr_ddap_en_SHIFT 31
#define AUDIO_CODEC_ac_dac_dap_ctr_ddap_drc_en (0x1 << 29)
#define AUDIO_CODEC_ac_dac_dap_ctr_ddap_drc_en_SHIFT 29
#define AUDIO_CODEC_ac_dac_dap_ctr_ddap_hpf_en (0x1 << 28)
#define AUDIO_CODEC_ac_dac_dap_ctr_ddap_hpf_en_SHIFT 28
#define AUDIO_CODEC_ac_adc_dap_ctr (AUDIO_CODEC + 0xf8) // ADC DAP Control Register ()
#define AUDIO_CODEC_ac_adc_dap_ctr_OFFSET 0xf8
#define AUDIO_CODEC_ac_adc_dap_ctr_adc_dap0_en (0x1 << 27)
#define AUDIO_CODEC_ac_adc_dap_ctr_adc_dap0_en_SHIFT 27
#define AUDIO_CODEC_ac_adc_dap_ctr_adc_drc0_en (0x1 << 25)
#define AUDIO_CODEC_ac_adc_dap_ctr_adc_drc0_en_SHIFT 25
#define AUDIO_CODEC_ac_adc_dap_ctr_adc_hpf0_en (0x1 << 24)
#define AUDIO_CODEC_ac_adc_dap_ctr_adc_hpf0_en_SHIFT 24
#define AUDIO_CODEC_ac_dac_drc_hhpfc (AUDIO_CODEC + 0x100) // DAC DRC High HPF Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_hhpfc_OFFSET 0x100
#define AUDIO_CODEC_ac_dac_drc_hhpfc_RESET 0x000000FF
#define AUDIO_CODEC_ac_dac_drc_hhpfc_hhpfc 0x7ff
#define AUDIO_CODEC_ac_dac_drc_hhpfc_hhpfc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lhpfc (AUDIO_CODEC + 0x104) // DAC DRC Low HPF Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lhpfc_OFFSET 0x104
#define AUDIO_CODEC_ac_dac_drc_lhpfc_RESET 0x0000FAC1
#define AUDIO_CODEC_ac_dac_drc_lhpfc_lhpfc 0xffff
#define AUDIO_CODEC_ac_dac_drc_lhpfc_lhpfc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_ctrl (AUDIO_CODEC + 0x108) // DAC DRC Control Register ()
#define AUDIO_CODEC_ac_dac_drc_ctrl_OFFSET 0x108
#define AUDIO_CODEC_ac_dac_drc_ctrl_RESET 0x00000080
#define AUDIO_CODEC_ac_dac_drc_ctrl_drc_dealy_buffer_data_output_state (0x1 << 15)
#define AUDIO_CODEC_ac_dac_drc_ctrl_drc_dealy_buffer_data_output_state_SHIFT 15
#define AUDIO_CODEC_ac_dac_drc_ctrl_signal_delay_time_setting (0x3f << 8)
#define AUDIO_CODEC_ac_dac_drc_ctrl_signal_delay_time_setting_SHIFT 8
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_delay_buf_en (0x1 << 7)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_delay_buf_en_SHIFT 7
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_gain_max_limit_en (0x1 << 6)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_gain_max_limit_en_SHIFT 6
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_gain_min_limit_en (0x1 << 5)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_gain_min_limit_en_SHIFT 5
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_detect_noise_en (0x1 << 4)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_detect_noise_en_SHIFT 4
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_signal_func_sel (0x1 << 3)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_signal_func_sel_SHIFT 3
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_delay_func_en (0x1 << 2)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_delay_func_en_SHIFT 2
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_lt_en (0x1 << 1)
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_lt_en_SHIFT 1
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_et_en 0x1
#define AUDIO_CODEC_ac_dac_drc_ctrl_dac_drc_et_en_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lpfhat (AUDIO_CODEC + 0x10c) // DAC DRC Left Peak Filter High Attack Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lpfhat_OFFSET 0x10c
#define AUDIO_CODEC_ac_dac_drc_lpfhat_RESET 0x0000000B
#define AUDIO_CODEC_ac_dac_drc_lpfhat_dac_drc_lpfhat 0x7ff
#define AUDIO_CODEC_ac_dac_drc_lpfhat_dac_drc_lpfhat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lpflat (AUDIO_CODEC + 0x110) // DAC DRC Left Peak Filter Low Attack Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lpflat_OFFSET 0x110
#define AUDIO_CODEC_ac_dac_drc_lpflat_RESET 0x000077BF
#define AUDIO_CODEC_ac_dac_drc_lpflat_dac_drc_lpflat 0xffff
#define AUDIO_CODEC_ac_dac_drc_lpflat_dac_drc_lpflat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_rpfhat (AUDIO_CODEC + 0x114) // DAC DRC Right Peak Filter High Attack Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_rpfhat_OFFSET 0x114
#define AUDIO_CODEC_ac_dac_drc_rpfhat_RESET 0x0000000B
#define AUDIO_CODEC_ac_dac_drc_rpfhat_dac_drc_rpfhat 0xffff
#define AUDIO_CODEC_ac_dac_drc_rpfhat_dac_drc_rpfhat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_rpflat (AUDIO_CODEC + 0x118) // DAC DRC Peak Filter Low Attack Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_rpflat_OFFSET 0x118
#define AUDIO_CODEC_ac_dac_drc_rpflat_RESET 0x000077BF
#define AUDIO_CODEC_ac_dac_drc_rpflat_dac_drc_rpflat 0xffff
#define AUDIO_CODEC_ac_dac_drc_rpflat_dac_drc_rpflat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lpfhrt (AUDIO_CODEC + 0x11c) // DAC DRC Left Peak Filter High Release Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lpfhrt_OFFSET 0x11c
#define AUDIO_CODEC_ac_dac_drc_lpfhrt_RESET 0x000000FF
#define AUDIO_CODEC_ac_dac_drc_lpfhrt_dac_drc_lpfhrt 0x7ff
#define AUDIO_CODEC_ac_dac_drc_lpfhrt_dac_drc_lpfhrt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lpflrt (AUDIO_CODEC + 0x120) // DAC DRC Left Peak Filter Low Release Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lpflrt_OFFSET 0x120
#define AUDIO_CODEC_ac_dac_drc_lpflrt_RESET 0x0000E1F8
#define AUDIO_CODEC_ac_dac_drc_lpflrt_dac_drc_lpflrt 0xffff
#define AUDIO_CODEC_ac_dac_drc_lpflrt_dac_drc_lpflrt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_rpfhrt (AUDIO_CODEC + 0x124) // DAC DRC Right Peak filter High Release Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_rpfhrt_OFFSET 0x124
#define AUDIO_CODEC_ac_dac_drc_rpfhrt_RESET 0x000000FF
#define AUDIO_CODEC_ac_dac_drc_rpfhrt_dac_drc_rpfhrt 0xffff
#define AUDIO_CODEC_ac_dac_drc_rpfhrt_dac_drc_rpfhrt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_rpflrt (AUDIO_CODEC + 0x128) // DAC DRC Right Peak filter Low Release Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_rpflrt_OFFSET 0x128
#define AUDIO_CODEC_ac_dac_drc_rpflrt_RESET 0x0000E1F8
#define AUDIO_CODEC_ac_dac_drc_rpflrt_dac_drc_rpflrt 0xffff
#define AUDIO_CODEC_ac_dac_drc_rpflrt_dac_drc_rpflrt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lrmshat (AUDIO_CODEC + 0x12c) // DAC DRC Left RMS Filter High Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lrmshat_OFFSET 0x12c
#define AUDIO_CODEC_ac_dac_drc_lrmshat_RESET 0x00000001
#define AUDIO_CODEC_ac_dac_drc_lrmshat_dac_drc_lrmshat 0x7ff
#define AUDIO_CODEC_ac_dac_drc_lrmshat_dac_drc_lrmshat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lrmslat (AUDIO_CODEC + 0x130) // DAC DRC Left RMS Filter Low Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_lrmslat_OFFSET 0x130
#define AUDIO_CODEC_ac_dac_drc_lrmslat_RESET 0x00002BAF
#define AUDIO_CODEC_ac_dac_drc_lrmslat_dac_drc_lrmslat 0xffff
#define AUDIO_CODEC_ac_dac_drc_lrmslat_dac_drc_lrmslat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_rrmshat (AUDIO_CODEC + 0x134) // DAC DRC Right RMS Filter High Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_rrmshat_OFFSET 0x134
#define AUDIO_CODEC_ac_dac_drc_rrmshat_RESET 0x00002BAF
#define AUDIO_CODEC_ac_dac_drc_rrmshat_dac_drc_rrmshat 0xffff
#define AUDIO_CODEC_ac_dac_drc_rrmshat_dac_drc_rrmshat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_rrmslat (AUDIO_CODEC + 0x138) // DAC DRC Right RMS Filter Low Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_rrmslat_OFFSET 0x138
#define AUDIO_CODEC_ac_dac_drc_rrmslat_RESET 0x00002BAF
#define AUDIO_CODEC_ac_dac_drc_rrmslat_dac_drc_rrmslat 0xffff
#define AUDIO_CODEC_ac_dac_drc_rrmslat_dac_drc_rrmslat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hct (AUDIO_CODEC + 0x13c) // DAC DRC Compressor Threshold High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_hct_OFFSET 0x13c
#define AUDIO_CODEC_ac_dac_drc_hct_RESET 0x000006A4
#define AUDIO_CODEC_ac_dac_drc_hct_dac_drc_hct 0xffff
#define AUDIO_CODEC_ac_dac_drc_hct_dac_drc_hct_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lct (AUDIO_CODEC + 0x140) // DAC DRC Compressor Slope High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_lct_OFFSET 0x140
#define AUDIO_CODEC_ac_dac_drc_lct_RESET 0x0000D3C0
#define AUDIO_CODEC_ac_dac_drc_lct_dac_drc_lct 0xffff
#define AUDIO_CODEC_ac_dac_drc_lct_dac_drc_lct_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hkc (AUDIO_CODEC + 0x144) // DAC DRC Compressor Slope High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_hkc_OFFSET 0x144
#define AUDIO_CODEC_ac_dac_drc_hkc_RESET 0x00000080
#define AUDIO_CODEC_ac_dac_drc_hkc_dac_drc_hkc 0xffff
#define AUDIO_CODEC_ac_dac_drc_hkc_dac_drc_hkc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lkc (AUDIO_CODEC + 0x148) // DAC DRC Compressor Slope Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_lkc_OFFSET 0x148
#define AUDIO_CODEC_ac_dac_drc_lkc_dac_drc_lkc 0xffff
#define AUDIO_CODEC_ac_dac_drc_lkc_dac_drc_lkc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hopc (AUDIO_CODEC + 0x14c) // DAC DRC Compressor High Output at Compressor Threshold Register ()
#define AUDIO_CODEC_ac_dac_drc_hopc_OFFSET 0x14c
#define AUDIO_CODEC_ac_dac_drc_hopc_RESET 0x0000F95B
#define AUDIO_CODEC_ac_dac_drc_hopc_dac_drc_hopc 0xffff
#define AUDIO_CODEC_ac_dac_drc_hopc_dac_drc_hopc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lopc (AUDIO_CODEC + 0x150) // DAC DRC Compressor Low Output at Compressor Threshold Register ()
#define AUDIO_CODEC_ac_dac_drc_lopc_OFFSET 0x150
#define AUDIO_CODEC_ac_dac_drc_lopc_RESET 0x00002C3F
#define AUDIO_CODEC_ac_dac_drc_lopc_dac_drc_lopc 0xffff
#define AUDIO_CODEC_ac_dac_drc_lopc_dac_drc_lopc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hlt (AUDIO_CODEC + 0x154) // DAC DRC Limiter Threshold High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_hlt_OFFSET 0x154
#define AUDIO_CODEC_ac_dac_drc_hlt_RESET 0x000001A9
#define AUDIO_CODEC_ac_dac_drc_hlt_dac_drc_hlt 0xffff
#define AUDIO_CODEC_ac_dac_drc_hlt_dac_drc_hlt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_llt (AUDIO_CODEC + 0x158) // DAC DRC Limiter Threshold Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_llt_OFFSET 0x158
#define AUDIO_CODEC_ac_dac_drc_llt_RESET 0x000034F0
#define AUDIO_CODEC_ac_dac_drc_llt_dac_drc_llt 0xffff
#define AUDIO_CODEC_ac_dac_drc_llt_dac_drc_llt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hkl (AUDIO_CODEC + 0x15c) // DAC DRC Limiter Slope High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_hkl_OFFSET 0x15c
#define AUDIO_CODEC_ac_dac_drc_hkl_RESET 0x00000005
#define AUDIO_CODEC_ac_dac_drc_hkl_dac_drc_hkl 0xffff
#define AUDIO_CODEC_ac_dac_drc_hkl_dac_drc_hkl_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lkl (AUDIO_CODEC + 0x160) // DAC DRC Limiter Slope Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_lkl_OFFSET 0x160
#define AUDIO_CODEC_ac_dac_drc_lkl_RESET 0x00001EB8
#define AUDIO_CODEC_ac_dac_drc_lkl_dac_drc_lkl 0xffff
#define AUDIO_CODEC_ac_dac_drc_lkl_dac_drc_lkl_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hopl (AUDIO_CODEC + 0x164) // DAC DRC Limiter High Output at Limiter Threshold ()
#define AUDIO_CODEC_ac_dac_drc_hopl_OFFSET 0x164
#define AUDIO_CODEC_ac_dac_drc_hopl_RESET 0x0000FBD8
#define AUDIO_CODEC_ac_dac_drc_hopl_dac_drc_hopl 0xffff
#define AUDIO_CODEC_ac_dac_drc_hopl_dac_drc_hopl_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lopl (AUDIO_CODEC + 0x168) // DAC DRC Limiter Low Output at Limiter Threshold ()
#define AUDIO_CODEC_ac_dac_drc_lopl_OFFSET 0x168
#define AUDIO_CODEC_ac_dac_drc_lopl_RESET 0x0000FBA7
#define AUDIO_CODEC_ac_dac_drc_lopl_dac_drc_lopl 0xffff
#define AUDIO_CODEC_ac_dac_drc_lopl_dac_drc_lopl_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_het (AUDIO_CODEC + 0x16c) // DAC DRC Expander Threshold High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_het_OFFSET 0x16c
#define AUDIO_CODEC_ac_dac_drc_het_RESET 0x00000BA0
#define AUDIO_CODEC_ac_dac_drc_het_dac_drc_het 0xffff
#define AUDIO_CODEC_ac_dac_drc_het_dac_drc_het_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_let (AUDIO_CODEC + 0x170) // DAC DRC Expander Threshold Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_let_OFFSET 0x170
#define AUDIO_CODEC_ac_dac_drc_let_RESET 0x00007291
#define AUDIO_CODEC_ac_dac_drc_let_dac_drc_let 0xffff
#define AUDIO_CODEC_ac_dac_drc_let_dac_drc_let_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hke (AUDIO_CODEC + 0x174) // DAC DRC Expander Slope High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_hke_OFFSET 0x174
#define AUDIO_CODEC_ac_dac_drc_hke_RESET 0x00000500
#define AUDIO_CODEC_ac_dac_drc_hke_dac_drc_hke 0x3fff
#define AUDIO_CODEC_ac_dac_drc_hke_dac_drc_hke_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lke (AUDIO_CODEC + 0x178) // DAC DRC Expander Slope Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_lke_OFFSET 0x178
#define AUDIO_CODEC_ac_dac_drc_lke_RESET 0x00000000
#define AUDIO_CODEC_ac_dac_drc_lke_dac_drc_lke 0xffff
#define AUDIO_CODEC_ac_dac_drc_lke_dac_drc_lke_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hope (AUDIO_CODEC + 0x17c) // DAC DRC Expander High Output at Expander Threshold ()
#define AUDIO_CODEC_ac_dac_drc_hope_OFFSET 0x17c
#define AUDIO_CODEC_ac_dac_drc_hope_RESET 0x0000F45F
#define AUDIO_CODEC_ac_dac_drc_hope_dac_drc_hope 0xffff
#define AUDIO_CODEC_ac_dac_drc_hope_dac_drc_hope_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lope (AUDIO_CODEC + 0x180) // DAC DRC Expander Low Output at Expander Threshold ()
#define AUDIO_CODEC_ac_dac_drc_lope_OFFSET 0x180
#define AUDIO_CODEC_ac_dac_drc_lope_RESET 0x00008D6E
#define AUDIO_CODEC_ac_dac_drc_lope_dac_drc_lope 0xffff
#define AUDIO_CODEC_ac_dac_drc_lope_dac_drc_lope_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hkn (AUDIO_CODEC + 0x184) // DAC DRC Linear Slope High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_hkn_OFFSET 0x184
#define AUDIO_CODEC_ac_dac_drc_hkn_RESET 0x00000100
#define AUDIO_CODEC_ac_dac_drc_hkn_dac_drc_hkn 0xffff
#define AUDIO_CODEC_ac_dac_drc_hkn_dac_drc_hkn_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_lkn (AUDIO_CODEC + 0x188) // DAC DRC Linear Slope Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_lkn_OFFSET 0x188
#define AUDIO_CODEC_ac_dac_drc_lkn_RESET 0x00000000
#define AUDIO_CODEC_ac_dac_drc_lkn_dac_drc_lkn 0xffff
#define AUDIO_CODEC_ac_dac_drc_lkn_dac_drc_lkn_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_sfhat (AUDIO_CODEC + 0x18c) // DAC DRC Smooth filter Gain High Attack Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_sfhat_OFFSET 0x18c
#define AUDIO_CODEC_ac_dac_drc_sfhat_RESET 0x00000002
#define AUDIO_CODEC_ac_dac_drc_sfhat_dac_drc_sfhat 0x7ff
#define AUDIO_CODEC_ac_dac_drc_sfhat_dac_drc_sfhat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_sflat (AUDIO_CODEC + 0x190) // DAC DRC Smooth filter Gain Low Attack Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_sflat_OFFSET 0x190
#define AUDIO_CODEC_ac_dac_drc_sflat_RESET 0x00005600
#define AUDIO_CODEC_ac_dac_drc_sflat_dac_drc_sflat 0xffff
#define AUDIO_CODEC_ac_dac_drc_sflat_dac_drc_sflat_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_sfhrt (AUDIO_CODEC + 0x194) // DAC DRC Smooth filter Gain High Release Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_sfhrt_OFFSET 0x194
#define AUDIO_CODEC_ac_dac_drc_sfhrt_RESET 0x00000000
#define AUDIO_CODEC_ac_dac_drc_sfhrt_dac_drc_sfhrt 0x7ff
#define AUDIO_CODEC_ac_dac_drc_sfhrt_dac_drc_sfhrt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_sflrt (AUDIO_CODEC + 0x198) // DAC DRC Smooth filter Gain Low Release Time Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_sflrt_OFFSET 0x198
#define AUDIO_CODEC_ac_dac_drc_sflrt_RESET 0x00000F04
#define AUDIO_CODEC_ac_dac_drc_sflrt_dac_drc_sflrt 0xffff
#define AUDIO_CODEC_ac_dac_drc_sflrt_dac_drc_sflrt_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_mxghs (AUDIO_CODEC + 0x19c) // DAC DRC MAX Gain High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_mxghs_OFFSET 0x19c
#define AUDIO_CODEC_ac_dac_drc_mxghs_RESET 0x0000FE56
#define AUDIO_CODEC_ac_dac_drc_mxghs_dac_drc_mxghs 0xffff
#define AUDIO_CODEC_ac_dac_drc_mxghs_dac_drc_mxghs_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_mxgls (AUDIO_CODEC + 0x1a0) // DAC DRC MAX Gain Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_mxgls_OFFSET 0x1a0
#define AUDIO_CODEC_ac_dac_drc_mxgls_RESET 0x0000CB0F
#define AUDIO_CODEC_ac_dac_drc_mxgls_dac_drc_mxgls 0xffff
#define AUDIO_CODEC_ac_dac_drc_mxgls_dac_drc_mxgls_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_mnghs (AUDIO_CODEC + 0x1a4) // DAC DRC MIN Gain High Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_mnghs_OFFSET 0x1a4
#define AUDIO_CODEC_ac_dac_drc_mnghs_RESET 0x0000F95B
#define AUDIO_CODEC_ac_dac_drc_mnghs_dac_drc_mnghs 0xffff
#define AUDIO_CODEC_ac_dac_drc_mnghs_dac_drc_mnghs_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_mngls (AUDIO_CODEC + 0x1a8) // DAC DRC MIN Gain Low Setting Register ()
#define AUDIO_CODEC_ac_dac_drc_mngls_OFFSET 0x1a8
#define AUDIO_CODEC_ac_dac_drc_mngls_RESET 0x00002C3F
#define AUDIO_CODEC_ac_dac_drc_mngls_dac_drc_mngls 0xffff
#define AUDIO_CODEC_ac_dac_drc_mngls_dac_drc_mngls_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_epshc (AUDIO_CODEC + 0x1ac) // DAC DRC Expander Smooth Time High Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_epshc_OFFSET 0x1ac
#define AUDIO_CODEC_ac_dac_drc_epshc_RESET 0x00000000
#define AUDIO_CODEC_ac_dac_drc_epshc_dac_drc_epshc 0x7ff
#define AUDIO_CODEC_ac_dac_drc_epshc_dac_drc_epshc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_epslc (AUDIO_CODEC + 0x1b0) // DAC DRC Expander Smooth Time Low Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_epslc_OFFSET 0x1b0
#define AUDIO_CODEC_ac_dac_drc_epslc_RESET 0x0000640C
#define AUDIO_CODEC_ac_dac_drc_epslc_dac_drc_epslc 0xffff
#define AUDIO_CODEC_ac_dac_drc_epslc_dac_drc_epslc_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hpfhgain (AUDIO_CODEC + 0x1b8) // DAC DRC HPF Gain High Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_hpfhgain_OFFSET 0x1b8
#define AUDIO_CODEC_ac_dac_drc_hpfhgain_RESET 0x00000100
#define AUDIO_CODEC_ac_dac_drc_hpfhgain_dac_drc_hpfhgain 0x7ff
#define AUDIO_CODEC_ac_dac_drc_hpfhgain_dac_drc_hpfhgain_SHIFT 0
#define AUDIO_CODEC_ac_dac_drc_hpflgain (AUDIO_CODEC + 0x1bc) // DAC DRC HPF Gain Low Coef Register ()
#define AUDIO_CODEC_ac_dac_drc_hpflgain_OFFSET 0x1bc
#define AUDIO_CODEC_ac_dac_drc_hpflgain_RESET 0x00000000
#define AUDIO_CODEC_ac_dac_drc_hpflgain_dac_drc_hpflgain 0xffff
#define AUDIO_CODEC_ac_dac_drc_hpflgain_dac_drc_hpflgain_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hhpfc (AUDIO_CODEC + 0x200) // ADC DRC High HPF Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_hhpfc_OFFSET 0x200
#define AUDIO_CODEC_ac_adc_drc_hhpfc_RESET 0x000000FF
#define AUDIO_CODEC_ac_adc_drc_hhpfc_hhpfc 0x7ff
#define AUDIO_CODEC_ac_adc_drc_hhpfc_hhpfc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lhpfc (AUDIO_CODEC + 0x204) // ADC DRC Low HPF Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lhpfc_OFFSET 0x204
#define AUDIO_CODEC_ac_adc_drc_lhpfc_RESET 0x0000FAC1
#define AUDIO_CODEC_ac_adc_drc_lhpfc_lhpfc 0xffff
#define AUDIO_CODEC_ac_adc_drc_lhpfc_lhpfc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_ctrl (AUDIO_CODEC + 0x208) // ADC DRC Control Register ()
#define AUDIO_CODEC_ac_adc_drc_ctrl_OFFSET 0x208
#define AUDIO_CODEC_ac_adc_drc_ctrl_RESET 0x00000080
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_delay_buf_output_state (0x1 << 15)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_delay_buf_output_state_SHIFT 15
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_signal_delay_time_set (0x3f << 8)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_signal_delay_time_set_SHIFT 8
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_delay_buf_en (0x1 << 7)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_delay_buf_en_SHIFT 7
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_gain_max_limit_en (0x1 << 6)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_gain_max_limit_en_SHIFT 6
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_gain_min_limit_en (0x1 << 5)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_gain_min_limit_en_SHIFT 5
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_detect_noise_en (0x1 << 4)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_detect_noise_en_SHIFT 4
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_signal_func_sel (0x1 << 3)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_signal_func_sel_SHIFT 3
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_delay_func_en (0x1 << 2)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_delay_func_en_SHIFT 2
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_lt_en (0x1 << 1)
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_lt_en_SHIFT 1
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_et_en 0x1
#define AUDIO_CODEC_ac_adc_drc_ctrl_adc_drc_et_en_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lpfhat (AUDIO_CODEC + 0x20c) // ADC DRC Left Peak Filter High Attack Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lpfhat_OFFSET 0x20c
#define AUDIO_CODEC_ac_adc_drc_lpfhat_RESET 0x0000000B
#define AUDIO_CODEC_ac_adc_drc_lpfhat_adc_drc_lpfhat 0x7ff
#define AUDIO_CODEC_ac_adc_drc_lpfhat_adc_drc_lpfhat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lpflat (AUDIO_CODEC + 0x210) // ADC DRC Left Peak Filter Low Attack Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lpflat_OFFSET 0x210
#define AUDIO_CODEC_ac_adc_drc_lpflat_RESET 0x000077BF
#define AUDIO_CODEC_ac_adc_drc_lpflat_adc_drc_lpflat 0xffff
#define AUDIO_CODEC_ac_adc_drc_lpflat_adc_drc_lpflat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_rpfhat (AUDIO_CODEC + 0x214) // ADC DRC Right Peak Filter High Attack Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_rpfhat_OFFSET 0x214
#define AUDIO_CODEC_ac_adc_drc_rpfhat_RESET 0x0000000B
#define AUDIO_CODEC_ac_adc_drc_rpfhat_adc_drc_rpfhat 0xffff
#define AUDIO_CODEC_ac_adc_drc_rpfhat_adc_drc_rpfhat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_rpflat (AUDIO_CODEC + 0x218) // ADC DRC Right Peak Filter Low Attack Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_rpflat_OFFSET 0x218
#define AUDIO_CODEC_ac_adc_drc_rpflat_RESET 0x000077BF
#define AUDIO_CODEC_ac_adc_drc_rpflat_adc_drc_rpflat 0xffff
#define AUDIO_CODEC_ac_adc_drc_rpflat_adc_drc_rpflat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lpfhrt (AUDIO_CODEC + 0x21c) // ADC DRC Left Peak Filter High Release Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lpfhrt_OFFSET 0x21c
#define AUDIO_CODEC_ac_adc_drc_lpfhrt_RESET 0x000000FF
#define AUDIO_CODEC_ac_adc_drc_lpfhrt_adc_drc_lpfhrt 0x7ff
#define AUDIO_CODEC_ac_adc_drc_lpfhrt_adc_drc_lpfhrt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lpflrt (AUDIO_CODEC + 0x220) // ADC DRC Left Peak Filter Low Release Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lpflrt_OFFSET 0x220
#define AUDIO_CODEC_ac_adc_drc_lpflrt_RESET 0x0000E1F8
#define AUDIO_CODEC_ac_adc_drc_lpflrt_adc_drc_lpflrt 0xffff
#define AUDIO_CODEC_ac_adc_drc_lpflrt_adc_drc_lpflrt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_rpfhrt (AUDIO_CODEC + 0x224) // ADC DRC Right Peak Filter High Release Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_rpfhrt_OFFSET 0x224
#define AUDIO_CODEC_ac_adc_drc_rpfhrt_RESET 0x000000FF
#define AUDIO_CODEC_ac_adc_drc_rpfhrt_adc_drc_rpfhrt 0xffff
#define AUDIO_CODEC_ac_adc_drc_rpfhrt_adc_drc_rpfhrt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_rpflrt (AUDIO_CODEC + 0x228) // ADC DRC Right Peak Filter Low Release Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_rpflrt_OFFSET 0x228
#define AUDIO_CODEC_ac_adc_drc_rpflrt_RESET 0x0000E1F8
#define AUDIO_CODEC_ac_adc_drc_rpflrt_adc_drc_rpflrt 0xffff
#define AUDIO_CODEC_ac_adc_drc_rpflrt_adc_drc_rpflrt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lrmshat (AUDIO_CODEC + 0x22c) // ADC DRC Left RMS Filter High Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lrmshat_OFFSET 0x22c
#define AUDIO_CODEC_ac_adc_drc_lrmshat_RESET 0x00000001
#define AUDIO_CODEC_ac_adc_drc_lrmshat_adc_drc_lrmshat 0x7ff
#define AUDIO_CODEC_ac_adc_drc_lrmshat_adc_drc_lrmshat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lrmslat (AUDIO_CODEC + 0x230) // ADC DRC Left RMS Filter Low Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_lrmslat_OFFSET 0x230
#define AUDIO_CODEC_ac_adc_drc_lrmslat_RESET 0x00002BAF
#define AUDIO_CODEC_ac_adc_drc_lrmslat_adc_drc_lrmslat 0xffff
#define AUDIO_CODEC_ac_adc_drc_lrmslat_adc_drc_lrmslat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_rrmshat (AUDIO_CODEC + 0x234) // ADC DRC Right RMS Filter High Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_rrmshat_OFFSET 0x234
#define AUDIO_CODEC_ac_adc_drc_rrmshat_RESET 0x00000001
#define AUDIO_CODEC_ac_adc_drc_rrmshat_adc_drc_rrmshat 0x7ff
#define AUDIO_CODEC_ac_adc_drc_rrmshat_adc_drc_rrmshat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_rrmslat (AUDIO_CODEC + 0x238) // ADC DRC Right RMS Filter Low Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_rrmslat_OFFSET 0x238
#define AUDIO_CODEC_ac_adc_drc_rrmslat_RESET 0x00002BAF
#define AUDIO_CODEC_ac_adc_drc_rrmslat_adc_drc_rrmslat 0xffff
#define AUDIO_CODEC_ac_adc_drc_rrmslat_adc_drc_rrmslat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hct (AUDIO_CODEC + 0x23c) // ADC DRC Compressor Threshold High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_hct_OFFSET 0x23c
#define AUDIO_CODEC_ac_adc_drc_hct_RESET 0x000006A4
#define AUDIO_CODEC_ac_adc_drc_hct_adc_drc_hct 0xffff
#define AUDIO_CODEC_ac_adc_drc_hct_adc_drc_hct_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lct (AUDIO_CODEC + 0x240) // ADC DRC Compressor Slope High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_lct_OFFSET 0x240
#define AUDIO_CODEC_ac_adc_drc_lct_RESET 0x0000D3C0
#define AUDIO_CODEC_ac_adc_drc_lct_adc_drc_lct 0xffff
#define AUDIO_CODEC_ac_adc_drc_lct_adc_drc_lct_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hkc (AUDIO_CODEC + 0x244) // ADC DRC Compressor Slope High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_hkc_OFFSET 0x244
#define AUDIO_CODEC_ac_adc_drc_hkc_RESET 0x00000080
#define AUDIO_CODEC_ac_adc_drc_hkc_adc_drc_hkc 0xffff
#define AUDIO_CODEC_ac_adc_drc_hkc_adc_drc_hkc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lkc (AUDIO_CODEC + 0x248) // ADC DRC Compressor Slope Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_lkc_OFFSET 0x248
#define AUDIO_CODEC_ac_adc_drc_lkc_RESET 0x00000000
#define AUDIO_CODEC_ac_adc_drc_lkc_adc_drc_lkc 0xffff
#define AUDIO_CODEC_ac_adc_drc_lkc_adc_drc_lkc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hopc (AUDIO_CODEC + 0x24c) // ADC DRC Compressor High Output at Compressor Threshold Register ()
#define AUDIO_CODEC_ac_adc_drc_hopc_OFFSET 0x24c
#define AUDIO_CODEC_ac_adc_drc_hopc_RESET 0x0000F95B
#define AUDIO_CODEC_ac_adc_drc_hopc_adc_drc_hopc 0xffff
#define AUDIO_CODEC_ac_adc_drc_hopc_adc_drc_hopc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lopc (AUDIO_CODEC + 0x250) // ADC DRC Compressor Low Output at Compressor Threshold Register ()
#define AUDIO_CODEC_ac_adc_drc_lopc_OFFSET 0x250
#define AUDIO_CODEC_ac_adc_drc_lopc_RESET 0x00002C3F
#define AUDIO_CODEC_ac_adc_drc_lopc_adc_drc_lopc 0xffff
#define AUDIO_CODEC_ac_adc_drc_lopc_adc_drc_lopc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hlt (AUDIO_CODEC + 0x254) // ADC DRC Limiter Threshold High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_hlt_OFFSET 0x254
#define AUDIO_CODEC_ac_adc_drc_hlt_RESET 0x000001A9
#define AUDIO_CODEC_ac_adc_drc_hlt_adc_drc_hlt 0xffff
#define AUDIO_CODEC_ac_adc_drc_hlt_adc_drc_hlt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_llt (AUDIO_CODEC + 0x258) // ADC DRC Limiter Threshold Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_llt_OFFSET 0x258
#define AUDIO_CODEC_ac_adc_drc_llt_RESET 0x000034F0
#define AUDIO_CODEC_ac_adc_drc_llt_adc_drc_llt 0xffff
#define AUDIO_CODEC_ac_adc_drc_llt_adc_drc_llt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hkl (AUDIO_CODEC + 0x25c) // ADC DRC Limiter Slope High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_hkl_OFFSET 0x25c
#define AUDIO_CODEC_ac_adc_drc_hkl_RESET 0x00000005
#define AUDIO_CODEC_ac_adc_drc_hkl_adc_drc_hkl 0x3fff
#define AUDIO_CODEC_ac_adc_drc_hkl_adc_drc_hkl_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lkl (AUDIO_CODEC + 0x260) // ADC DRC Limiter Slope Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_lkl_OFFSET 0x260
#define AUDIO_CODEC_ac_adc_drc_lkl_RESET 0x00001EB8
#define AUDIO_CODEC_ac_adc_drc_lkl_adc_drc_lkl 0xffff
#define AUDIO_CODEC_ac_adc_drc_lkl_adc_drc_lkl_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hopl (AUDIO_CODEC + 0x264) // ADC DRC Limiter High Output at Limiter Threshold ()
#define AUDIO_CODEC_ac_adc_drc_hopl_OFFSET 0x264
#define AUDIO_CODEC_ac_adc_drc_hopl_RESET 0x0000FBD8
#define AUDIO_CODEC_ac_adc_drc_hopl_adc_drc_hopl 0xffff
#define AUDIO_CODEC_ac_adc_drc_hopl_adc_drc_hopl_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lopl (AUDIO_CODEC + 0x268) // ADC DRC Limiter Low Output at Limiter Threshold ()
#define AUDIO_CODEC_ac_adc_drc_lopl_OFFSET 0x268
#define AUDIO_CODEC_ac_adc_drc_lopl_RESET 0x0000FBA7
#define AUDIO_CODEC_ac_adc_drc_lopl_adc_drc_lopl 0xffff
#define AUDIO_CODEC_ac_adc_drc_lopl_adc_drc_lopl_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_het (AUDIO_CODEC + 0x26c) // ADC DRC Expander Threshold High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_het_OFFSET 0x26c
#define AUDIO_CODEC_ac_adc_drc_het_RESET 0x00000BA0
#define AUDIO_CODEC_ac_adc_drc_het_adc_drc_het 0xffff
#define AUDIO_CODEC_ac_adc_drc_het_adc_drc_het_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_let (AUDIO_CODEC + 0x270) // ADC DRC Expander Threshold Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_let_OFFSET 0x270
#define AUDIO_CODEC_ac_adc_drc_let_RESET 0x00007291
#define AUDIO_CODEC_ac_adc_drc_let_adc_drc_let 0xffff
#define AUDIO_CODEC_ac_adc_drc_let_adc_drc_let_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hke (AUDIO_CODEC + 0x274) // ADC DRC Expander Slope High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_hke_OFFSET 0x274
#define AUDIO_CODEC_ac_adc_drc_hke_RESET 0x00000500
#define AUDIO_CODEC_ac_adc_drc_hke_adc_drc_hke 0xffff
#define AUDIO_CODEC_ac_adc_drc_hke_adc_drc_hke_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lke (AUDIO_CODEC + 0x278) // ADC DRC Expander Slope Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_lke_OFFSET 0x278
#define AUDIO_CODEC_ac_adc_drc_lke_RESET 0x00000000
#define AUDIO_CODEC_ac_adc_drc_lke_adc_drc_lke 0xffff
#define AUDIO_CODEC_ac_adc_drc_lke_adc_drc_lke_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hope (AUDIO_CODEC + 0x27c) // ADC DRC Expander High Output at Expander Threshold ()
#define AUDIO_CODEC_ac_adc_drc_hope_OFFSET 0x27c
#define AUDIO_CODEC_ac_adc_drc_hope_RESET 0x0000F45F
#define AUDIO_CODEC_ac_adc_drc_hope_adc_drc_hope 0xffff
#define AUDIO_CODEC_ac_adc_drc_hope_adc_drc_hope_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lope (AUDIO_CODEC + 0x280) // ADC DRC Expander Low Output at Expander Threshold ()
#define AUDIO_CODEC_ac_adc_drc_lope_OFFSET 0x280
#define AUDIO_CODEC_ac_adc_drc_lope_RESET 0x00008D6E
#define AUDIO_CODEC_ac_adc_drc_lope_adc_drc_lope 0xffff
#define AUDIO_CODEC_ac_adc_drc_lope_adc_drc_lope_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hkn (AUDIO_CODEC + 0x284) // ADC DRC Linear Slope High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_hkn_OFFSET 0x284
#define AUDIO_CODEC_ac_adc_drc_hkn_RESET 0x00000100
#define AUDIO_CODEC_ac_adc_drc_hkn_adc_drc_hkn 0xffff
#define AUDIO_CODEC_ac_adc_drc_hkn_adc_drc_hkn_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_lkn (AUDIO_CODEC + 0x288) // ADC DRC Linear Slope Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_lkn_OFFSET 0x288
#define AUDIO_CODEC_ac_adc_drc_lkn_RESET 0x00000000
#define AUDIO_CODEC_ac_adc_drc_lkn_adc_drc_lkn 0xffff
#define AUDIO_CODEC_ac_adc_drc_lkn_adc_drc_lkn_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_sfhat (AUDIO_CODEC + 0x28c) // ADC DRC Smooth filter Gain High Attack Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_sfhat_OFFSET 0x28c
#define AUDIO_CODEC_ac_adc_drc_sfhat_RESET 0x00000002
#define AUDIO_CODEC_ac_adc_drc_sfhat_adc_drc_sfhat 0x7ff
#define AUDIO_CODEC_ac_adc_drc_sfhat_adc_drc_sfhat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_sflat (AUDIO_CODEC + 0x290) // ADC DRC Smooth filter Gain Low Attack Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_sflat_OFFSET 0x290
#define AUDIO_CODEC_ac_adc_drc_sflat_RESET 0x00005600
#define AUDIO_CODEC_ac_adc_drc_sflat_adc_drc_sflat 0xffff
#define AUDIO_CODEC_ac_adc_drc_sflat_adc_drc_sflat_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_sfhrt (AUDIO_CODEC + 0x294) // ADC DRC Smooth filter Gain High Release Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_sfhrt_OFFSET 0x294
#define AUDIO_CODEC_ac_adc_drc_sfhrt_RESET 0x00000000
#define AUDIO_CODEC_ac_adc_drc_sfhrt_adc_drc_sfhrt 0x7ff
#define AUDIO_CODEC_ac_adc_drc_sfhrt_adc_drc_sfhrt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_sflrt (AUDIO_CODEC + 0x298) // ADC DRC Smooth filter Gain Low Release Time Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_sflrt_OFFSET 0x298
#define AUDIO_CODEC_ac_adc_drc_sflrt_RESET 0x00000F04
#define AUDIO_CODEC_ac_adc_drc_sflrt_adc_drc_sflrt 0xffff
#define AUDIO_CODEC_ac_adc_drc_sflrt_adc_drc_sflrt_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_mxghs (AUDIO_CODEC + 0x29c) // ADC DRC MAX Gain High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_mxghs_OFFSET 0x29c
#define AUDIO_CODEC_ac_adc_drc_mxghs_RESET 0x0000FE56
#define AUDIO_CODEC_ac_adc_drc_mxghs_adc_drc_mxghs 0xffff
#define AUDIO_CODEC_ac_adc_drc_mxghs_adc_drc_mxghs_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_mxgls (AUDIO_CODEC + 0x2a0) // ADC DRC MAX Gain Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_mxgls_OFFSET 0x2a0
#define AUDIO_CODEC_ac_adc_drc_mxgls_RESET 0x0000CB0F
#define AUDIO_CODEC_ac_adc_drc_mxgls_adc_drc_mxgls 0xffff
#define AUDIO_CODEC_ac_adc_drc_mxgls_adc_drc_mxgls_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_mnghs (AUDIO_CODEC + 0x2a4) // ADC DRC MIN Gain High Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_mnghs_OFFSET 0x2a4
#define AUDIO_CODEC_ac_adc_drc_mnghs_RESET 0x0000F95B
#define AUDIO_CODEC_ac_adc_drc_mnghs_adc_drc_mnghs 0xffff
#define AUDIO_CODEC_ac_adc_drc_mnghs_adc_drc_mnghs_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_mngls (AUDIO_CODEC + 0x2a8) // ADC DRC MIN Gain Low Setting Register ()
#define AUDIO_CODEC_ac_adc_drc_mngls_OFFSET 0x2a8
#define AUDIO_CODEC_ac_adc_drc_mngls_RESET 0x00002C3F
#define AUDIO_CODEC_ac_adc_drc_mngls_adc_drc_mngls 0xffff
#define AUDIO_CODEC_ac_adc_drc_mngls_adc_drc_mngls_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_epshc (AUDIO_CODEC + 0x2ac) // ADC DRC Expander Smooth Time High Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_epshc_OFFSET 0x2ac
#define AUDIO_CODEC_ac_adc_drc_epshc_RESET 0x00000000
#define AUDIO_CODEC_ac_adc_drc_epshc_adc_drc_epshc 0x7ff
#define AUDIO_CODEC_ac_adc_drc_epshc_adc_drc_epshc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_epslc (AUDIO_CODEC + 0x2b0) // ADC DRC Expander Smooth Time Low Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_epslc_OFFSET 0x2b0
#define AUDIO_CODEC_ac_adc_drc_epslc_RESET 0x0000640C
#define AUDIO_CODEC_ac_adc_drc_epslc_adc_drc_epslc 0xffff
#define AUDIO_CODEC_ac_adc_drc_epslc_adc_drc_epslc_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hpfhgain (AUDIO_CODEC + 0x2b8) // ADC DRC HPF Gain High Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_hpfhgain_OFFSET 0x2b8
#define AUDIO_CODEC_ac_adc_drc_hpfhgain_RESET 0x00000100
#define AUDIO_CODEC_ac_adc_drc_hpfhgain_adc_drc_hpfhgain 0x7ff
#define AUDIO_CODEC_ac_adc_drc_hpfhgain_adc_drc_hpfhgain_SHIFT 0
#define AUDIO_CODEC_ac_adc_drc_hpflgain (AUDIO_CODEC + 0x2bc) // ADC DRC HPF Gain Low Coef Register ()
#define AUDIO_CODEC_ac_adc_drc_hpflgain_OFFSET 0x2bc
#define AUDIO_CODEC_ac_adc_drc_hpflgain_RESET 0x00000000
#define AUDIO_CODEC_ac_adc_drc_hpflgain_adc_drc_hpflgain 0xffff
#define AUDIO_CODEC_ac_adc_drc_hpflgain_adc_drc_hpflgain_SHIFT 0
#define AUDIO_CODEC_adc0 (AUDIO_CODEC + 0x300) // ADCi Analog Control Register ()
#define AUDIO_CODEC_adc0_OFFSET 0x300
#define AUDIO_CODEC_adc0_RESET 0x001CC055
#define AUDIO_CODEC_adc0_adc_en (0x1 << 31)
#define AUDIO_CODEC_adc0_adc_en_SHIFT 31
#define AUDIO_CODEC_adc0_mic_pga_en (0x1 << 30)
#define AUDIO_CODEC_adc0_mic_pga_en_SHIFT 30
#define AUDIO_CODEC_adc0_adc_d_itcher_c_ontrol (0x1 << 29)
#define AUDIO_CODEC_adc0_adc_d_itcher_c_ontrol_SHIFT 29
#define AUDIO_CODEC_adc0_mic_sin_en (0x1 << 28)
#define AUDIO_CODEC_adc0_mic_sin_en_SHIFT 28
#define AUDIO_CODEC_adc0_fminlen (0x1 << 27)
#define AUDIO_CODEC_adc0_fminlen_SHIFT 27
#define AUDIO_CODEC_adc0_fminlg (0x1 << 26)
#define AUDIO_CODEC_adc0_fminlg_SHIFT 26
#define AUDIO_CODEC_adc0_dsm_dither_lvl (0x3 << 24)
#define AUDIO_CODEC_adc0_dsm_dither_lvl_SHIFT 24
#define AUDIO_CODEC_adc0_lineinlen (0x1 << 23)
#define AUDIO_CODEC_adc0_lineinlen_SHIFT 23
#define AUDIO_CODEC_adc0_lineinlg (0x1 << 22)
#define AUDIO_CODEC_adc0_lineinlg_SHIFT 22
#define AUDIO_CODEC_adc0_iopbuffer (0x3 << 20)
#define AUDIO_CODEC_adc0_iopbuffer_SHIFT 20
#define AUDIO_CODEC_adc0_adc_pga_ctrl_rcm (0x3 << 18)
#define AUDIO_CODEC_adc0_adc_pga_ctrl_rcm_SHIFT 18
#define AUDIO_CODEC_adc0_adc_pga_in_vcm_ctrl (0x3 << 16)
#define AUDIO_CODEC_adc0_adc_pga_in_vcm_ctrl_SHIFT 16
#define AUDIO_CODEC_adc0_iopadc (0x3 << 14)
#define AUDIO_CODEC_adc0_iopadc_SHIFT 14
#define AUDIO_CODEC_adc0_adc_pga_gain_ctrl (0x1f << 8)
#define AUDIO_CODEC_adc0_adc_pga_gain_ctrl_SHIFT 8
#define AUDIO_CODEC_adc0_adc_iopaaf (0x3 << 6)
#define AUDIO_CODEC_adc0_adc_iopaaf_SHIFT 6
#define AUDIO_CODEC_adc0_adc_iopsdm0 (0x3 << 4)
#define AUDIO_CODEC_adc0_adc_iopsdm0_SHIFT 4
#define AUDIO_CODEC_adc0_adc_iopmic 0x3
#define AUDIO_CODEC_adc0_adc_iopmic_SHIFT 0
#define AUDIO_CODEC_dac (AUDIO_CODEC + 0x310) // DAC Analog Control Register ()
#define AUDIO_CODEC_dac_OFFSET 0x310
#define AUDIO_CODEC_dac_current_test_select (0x1 << 23)
#define AUDIO_CODEC_dac_current_test_select_SHIFT 23
#define AUDIO_CODEC_dac_iopvrs (0x3 << 20)
#define AUDIO_CODEC_dac_iopvrs_SHIFT 20
#define AUDIO_CODEC_dac_ilineoutamps (0x3 << 18)
#define AUDIO_CODEC_dac_ilineoutamps_SHIFT 18
#define AUDIO_CODEC_dac_iopdacs (0x3 << 16)
#define AUDIO_CODEC_dac_iopdacs_SHIFT 16
#define AUDIO_CODEC_dac_dacl_en (0x1 << 15)
#define AUDIO_CODEC_dac_dacl_en_SHIFT 15
#define AUDIO_CODEC_dac_dacr_en (0x1 << 14)
#define AUDIO_CODEC_dac_dacr_en_SHIFT 14
#define AUDIO_CODEC_dac_lineoutlen (0x1 << 13)
#define AUDIO_CODEC_dac_lineoutlen_SHIFT 13
#define AUDIO_CODEC_dac_lmute (0x1 << 12)
#define AUDIO_CODEC_dac_lmute_SHIFT 12
#define AUDIO_CODEC_dac_lineoutren (0x1 << 11)
#define AUDIO_CODEC_dac_lineoutren_SHIFT 11
#define AUDIO_CODEC_dac_rmute (0x1 << 10)
#define AUDIO_CODEC_dac_rmute_SHIFT 10
#define AUDIO_CODEC_dac_lineoutl_diffen (0x1 << 6)
#define AUDIO_CODEC_dac_lineoutl_diffen_SHIFT 6
#define AUDIO_CODEC_dac_lineoutr_diffen (0x1 << 5)
#define AUDIO_CODEC_dac_lineoutr_diffen_SHIFT 5
#define AUDIO_CODEC_dac_lineout_vol_ctrl 0x1f
#define AUDIO_CODEC_dac_lineout_vol_ctrl_SHIFT 0
#define AUDIO_CODEC_micbias (AUDIO_CODEC + 0x318) // MICBIAS Analog Control Register ()
#define AUDIO_CODEC_micbias_OFFSET 0x318
#define AUDIO_CODEC_micbias_RESET 0x40003030
#define AUDIO_CODEC_micbias_seldetadcfs (0x7 << 28)
#define AUDIO_CODEC_micbias_seldetadcfs_SHIFT 28
#define AUDIO_CODEC_micbias_seldetadcdb (0x3 << 26)
#define AUDIO_CODEC_micbias_seldetadcdb_SHIFT 26
#define AUDIO_CODEC_micbias_seldetadcbf (0x3 << 24)
#define AUDIO_CODEC_micbias_seldetadcbf_SHIFT 24
#define AUDIO_CODEC_micbias_jackdeten (0x1 << 23)
#define AUDIO_CODEC_micbias_jackdeten_SHIFT 23
#define AUDIO_CODEC_micbias_seldetadcdy (0x3 << 21)
#define AUDIO_CODEC_micbias_seldetadcdy_SHIFT 21
#define AUDIO_CODEC_micbias_micadcen (0x1 << 20)
#define AUDIO_CODEC_micbias_micadcen_SHIFT 20
#define AUDIO_CODEC_micbias_popfree (0x1 << 19)
#define AUDIO_CODEC_micbias_popfree_SHIFT 19
#define AUDIO_CODEC_micbias_det_mode (0x1 << 18)
#define AUDIO_CODEC_micbias_det_mode_SHIFT 18
#define AUDIO_CODEC_micbias_autoplen (0x1 << 17)
#define AUDIO_CODEC_micbias_autoplen_SHIFT 17
#define AUDIO_CODEC_micbias_micdetpl (0x1 << 16)
#define AUDIO_CODEC_micbias_micdetpl_SHIFT 16
#define AUDIO_CODEC_micbias_hmicbiasen (0x1 << 15)
#define AUDIO_CODEC_micbias_hmicbiasen_SHIFT 15
#define AUDIO_CODEC_micbias_hbiassel (0x3 << 13)
#define AUDIO_CODEC_micbias_hbiassel_SHIFT 13
#define AUDIO_CODEC_micbias_hmic_bias_chopper_en (0x1 << 12)
#define AUDIO_CODEC_micbias_hmic_bias_chopper_en_SHIFT 12
#define AUDIO_CODEC_micbias_hmic_bias_chopper_clk_sel (0x3 << 10)
#define AUDIO_CODEC_micbias_hmic_bias_chopper_clk_sel_SHIFT 10
#define AUDIO_CODEC_micbias_mmicbiasen (0x1 << 7)
#define AUDIO_CODEC_micbias_mmicbiasen_SHIFT 7
#define AUDIO_CODEC_micbias_mbiassel (0x3 << 5)
#define AUDIO_CODEC_micbias_mbiassel_SHIFT 5
#define AUDIO_CODEC_micbias_mmic_bias_chopper_en (0x1 << 4)
#define AUDIO_CODEC_micbias_mmic_bias_chopper_en_SHIFT 4
#define AUDIO_CODEC_micbias_mmic_bias_chopper_clk_sel (0x3 << 2)
#define AUDIO_CODEC_micbias_mmic_bias_chopper_clk_sel_SHIFT 2
#define AUDIO_CODEC_ramp (AUDIO_CODEC + 0x31c) // BIAS Analog Control Register ()
#define AUDIO_CODEC_ramp_OFFSET 0x31c
#define AUDIO_CODEC_ramp_ramp_rise_int_en (0x1 << 31)
#define AUDIO_CODEC_ramp_ramp_rise_int_en_SHIFT 31
#define AUDIO_CODEC_ramp_ramp_rise_int (0x1 << 30)
#define AUDIO_CODEC_ramp_ramp_rise_int_SHIFT 30
#define AUDIO_CODEC_ramp_ramp_fall_int_en (0x1 << 29)
#define AUDIO_CODEC_ramp_ramp_fall_int_en_SHIFT 29
#define AUDIO_CODEC_ramp_ramp_fall_int (0x1 << 28)
#define AUDIO_CODEC_ramp_ramp_fall_int_SHIFT 28
#define AUDIO_CODEC_ramp_ramp_srst (0x1 << 24)
#define AUDIO_CODEC_ramp_ramp_srst_SHIFT 24
#define AUDIO_CODEC_ramp_ramp_clk_div_m (0x1f << 16)
#define AUDIO_CODEC_ramp_ramp_clk_div_m_SHIFT 16
#define AUDIO_CODEC_ramp_hp_pull_out_en (0x1 << 15)
#define AUDIO_CODEC_ramp_hp_pull_out_en_SHIFT 15
#define AUDIO_CODEC_ramp_ramp_hold_step (0x7 << 12)
#define AUDIO_CODEC_ramp_ramp_hold_step_SHIFT 12
#define AUDIO_CODEC_ramp_gap_step (0x3 << 8)
#define AUDIO_CODEC_ramp_gap_step_SHIFT 8
#define AUDIO_CODEC_ramp_ramp_step (0x7 << 4)
#define AUDIO_CODEC_ramp_ramp_step_SHIFT 4
#define AUDIO_CODEC_ramp_rmd_en (0x1 << 3)
#define AUDIO_CODEC_ramp_rmd_en_SHIFT 3
#define AUDIO_CODEC_ramp_rmu_en (0x1 << 2)
#define AUDIO_CODEC_ramp_rmu_en_SHIFT 2
#define AUDIO_CODEC_ramp_rmc_en (0x1 << 1)
#define AUDIO_CODEC_ramp_rmc_en_SHIFT 1
#define AUDIO_CODEC_ramp_rd_en 0x1
#define AUDIO_CODEC_ramp_rd_en_SHIFT 0
#define AUDIO_CODEC_bias (AUDIO_CODEC + 0x320) // BIAS Analog Control Register ()
#define AUDIO_CODEC_bias_OFFSET 0x320
#define AUDIO_CODEC_bias_RESET 0x00000080
#define AUDIO_CODEC_bias_biasdata 0xff
#define AUDIO_CODEC_bias_biasdata_SHIFT 0
#define AUDIO_CODEC_hmic_ctrl (AUDIO_CODEC + 0x328) // HMIC Control Register ()
#define AUDIO_CODEC_hmic_ctrl_OFFSET 0x328
#define AUDIO_CODEC_hmic_ctrl_RESET 0x00000008
#define AUDIO_CODEC_hmic_ctrl_hmic_sample_select (0x3 << 21)
#define AUDIO_CODEC_hmic_ctrl_hmic_sample_select_SHIFT 21
#define AUDIO_CODEC_hmic_ctrl_mdata_threshold (0x1f << 16)
#define AUDIO_CODEC_hmic_ctrl_mdata_threshold_SHIFT 16
#define AUDIO_CODEC_hmic_ctrl_hmic_sf (0x3 << 14)
#define AUDIO_CODEC_hmic_ctrl_hmic_sf_SHIFT 14
#define AUDIO_CODEC_hmic_ctrl_hmic_m (0xf << 10)
#define AUDIO_CODEC_hmic_ctrl_hmic_m_SHIFT 10
#define AUDIO_CODEC_hmic_ctrl_hmic_n (0xf << 6)
#define AUDIO_CODEC_hmic_ctrl_hmic_n_SHIFT 6
#define AUDIO_CODEC_hmic_ctrl_mdata_threshold_debounce (0x7 << 3)
#define AUDIO_CODEC_hmic_ctrl_mdata_threshold_debounce_SHIFT 3
#define AUDIO_CODEC_hmic_ctrl_jack_out_irq_en (0x1 << 2)
#define AUDIO_CODEC_hmic_ctrl_jack_out_irq_en_SHIFT 2
#define AUDIO_CODEC_hmic_ctrl_jack_in_irq_en (0x1 << 1)
#define AUDIO_CODEC_hmic_ctrl_jack_in_irq_en_SHIFT 1
#define AUDIO_CODEC_hmic_ctrl_mic_det_irq_en 0x1
#define AUDIO_CODEC_hmic_ctrl_mic_det_irq_en_SHIFT 0
#define AUDIO_CODEC_hmic_sts (AUDIO_CODEC + 0x32c) // HMIC Status Register ()
#define AUDIO_CODEC_hmic_sts_OFFSET 0x32c
#define AUDIO_CODEC_hmic_sts_RESET 0x00006000
#define AUDIO_CODEC_hmic_sts_mdata_discard (0x3 << 13)
#define AUDIO_CODEC_hmic_sts_mdata_discard_SHIFT 13
#define AUDIO_CODEC_hmic_sts_hmic_data (0x1f << 8)
#define AUDIO_CODEC_hmic_sts_hmic_data_SHIFT 8
#define AUDIO_CODEC_hmic_sts_jack_det_oirq (0x1 << 4)
#define AUDIO_CODEC_hmic_sts_jack_det_oirq_SHIFT 4
#define AUDIO_CODEC_hmic_sts_jack_det_iirq (0x1 << 3)
#define AUDIO_CODEC_hmic_sts_jack_det_iirq_SHIFT 3
#define AUDIO_CODEC_hmic_sts_mic_det_st 0x1
#define AUDIO_CODEC_hmic_sts_mic_det_st_SHIFT 0
#define AUDIO_CODEC_hp2 (AUDIO_CODEC + 0x340) // Headphone2 Analog Control Register ()
#define AUDIO_CODEC_hp2_OFFSET 0x340
#define AUDIO_CODEC_hp2_hpfb_buf_en (0x1 << 31)
#define AUDIO_CODEC_hp2_hpfb_buf_en_SHIFT 31
#define AUDIO_CODEC_hp2_headphone_gain (0x7 << 28)
#define AUDIO_CODEC_hp2_headphone_gain_SHIFT 28
#define AUDIO_CODEC_hp2_hpfb_res (0x3 << 26)
#define AUDIO_CODEC_hp2_hpfb_res_SHIFT 26
#define AUDIO_CODEC_hp2_opdrv_cur (0x3 << 24)
#define AUDIO_CODEC_hp2_opdrv_cur_SHIFT 24
#define AUDIO_CODEC_hp2_iophp (0x3 << 22)
#define AUDIO_CODEC_hp2_iophp_SHIFT 22
#define AUDIO_CODEC_hp2_hp_drven (0x1 << 21)
#define AUDIO_CODEC_hp2_hp_drven_SHIFT 21
#define AUDIO_CODEC_hp2_hp_drvouten (0x1 << 20)
#define AUDIO_CODEC_hp2_hp_drvouten_SHIFT 20
#define AUDIO_CODEC_hp2_rswitch (0x1 << 19)
#define AUDIO_CODEC_hp2_rswitch_SHIFT 19
#define AUDIO_CODEC_hp2_rampen (0x1 << 18)
#define AUDIO_CODEC_hp2_rampen_SHIFT 18
#define AUDIO_CODEC_hp2_hpfb_in_en (0x1 << 17)
#define AUDIO_CODEC_hp2_hpfb_in_en_SHIFT 17
#define AUDIO_CODEC_hp2_ramp_final_control (0x1 << 16)
#define AUDIO_CODEC_hp2_ramp_final_control_SHIFT 16
#define AUDIO_CODEC_hp2_ramp_out_en (0x1 << 15)
#define AUDIO_CODEC_hp2_ramp_out_en_SHIFT 15
#define AUDIO_CODEC_hp2_ramp_final_state_res (0x3 << 13)
#define AUDIO_CODEC_hp2_ramp_final_state_res_SHIFT 13
#define AUDIO_CODEC_hp2_hpfb_buf_output_current (0x3 << 8)
#define AUDIO_CODEC_hp2_hpfb_buf_output_current_SHIFT 8
#define AUDIO_CODEC_power (AUDIO_CODEC + 0x348) // POWER Analog Control Register\n\nThe register is not controlled by the clock and reset of Audio Codec, only controlled by the clock and reset of system bus. ()
#define AUDIO_CODEC_power_OFFSET 0x348
#define AUDIO_CODEC_power_aldo_en (0x1 << 31)
#define AUDIO_CODEC_power_aldo_en_SHIFT 31
#define AUDIO_CODEC_power_hpldo_en (0x1 << 30)
#define AUDIO_CODEC_power_hpldo_en_SHIFT 30
#define AUDIO_CODEC_power_var1speedup_further_ctrl (0x1 << 29)
#define AUDIO_CODEC_power_var1speedup_further_ctrl_SHIFT 29
#define AUDIO_CODEC_power_avccpor (0x1 << 16)
#define AUDIO_CODEC_power_avccpor_SHIFT 16
#define AUDIO_CODEC_power_aldo_output_voltage (0x7 << 12)
#define AUDIO_CODEC_power_aldo_output_voltage_SHIFT 12
#define AUDIO_CODEC_power_hpldo_output_voltage (0x7 << 8)
#define AUDIO_CODEC_power_hpldo_output_voltage_SHIFT 8
#define AUDIO_CODEC_power_bg_trim 0xff
#define AUDIO_CODEC_power_bg_trim_SHIFT 0

/****************************************************************
 * Two Wire Interface
 ****************************************************************/
#define TWI0 0x02502000
#define TWI0_twi_addr (TWI0 + 0x0) // TWI Slave Address Register ()
#define TWI0_twi_addr_OFFSET 0x0
#define TWI0_twi_addr_sla (0x7f << 1)
#define TWI0_twi_addr_sla_SHIFT 1
#define TWI0_twi_addr_gce 0x1
#define TWI0_twi_addr_gce_SHIFT 0
#define TWI0_twi_xaddr (TWI0 + 0x4) // TWI Extended Slave Address Register ()
#define TWI0_twi_xaddr_OFFSET 0x4
#define TWI0_twi_xaddr_slax 0xff
#define TWI0_twi_xaddr_slax_SHIFT 0
#define TWI0_twi_data (TWI0 + 0x8) // TWI Data Byte Register ()
#define TWI0_twi_data_OFFSET 0x8
#define TWI0_twi_data_data 0xff
#define TWI0_twi_data_data_SHIFT 0
#define TWI0_twi_cntr (TWI0 + 0xc) // TWI Control Register ()
#define TWI0_twi_cntr_OFFSET 0xc
#define TWI0_twi_cntr_int_en (0x1 << 7)
#define TWI0_twi_cntr_int_en_SHIFT 7
#define TWI0_twi_cntr_bus_en (0x1 << 6)
#define TWI0_twi_cntr_bus_en_SHIFT 6
#define TWI0_twi_cntr_m_sta (0x1 << 5)
#define TWI0_twi_cntr_m_sta_SHIFT 5
#define TWI0_twi_cntr_m_stp (0x1 << 4)
#define TWI0_twi_cntr_m_stp_SHIFT 4
#define TWI0_twi_cntr_int_flag (0x1 << 3)
#define TWI0_twi_cntr_int_flag_SHIFT 3
#define TWI0_twi_cntr_a_ack (0x1 << 2)
#define TWI0_twi_cntr_a_ack_SHIFT 2
#define TWI0_twi_cntr_clk_count_mode 0x1
#define TWI0_twi_cntr_clk_count_mode_SHIFT 0
#define TWI0_twi_stat (TWI0 + 0x10) // TWI Status Register (R only)
#define TWI0_twi_stat_OFFSET 0x10
#define TWI0_twi_stat_sta 0xff
#define TWI0_twi_stat_sta_SHIFT 0
#define TWI0_twi_ccr (TWI0 + 0x14) // TWI Clock Control Register ()
#define TWI0_twi_ccr_OFFSET 0x14
#define TWI0_twi_ccr_clk_duty (0x1 << 7)
#define TWI0_twi_ccr_clk_duty_SHIFT 7
#define TWI0_twi_ccr_clk_m (0xf << 3)
#define TWI0_twi_ccr_clk_m_SHIFT 3
#define TWI0_twi_ccr_clk_n 0x7
#define TWI0_twi_ccr_clk_n_SHIFT 0
#define TWI0_twi_srst (TWI0 + 0x18) // TWI Software Reset Register ()
#define TWI0_twi_srst_OFFSET 0x18
#define TWI0_twi_srst_soft_rst 0x1
#define TWI0_twi_srst_soft_rst_SHIFT 0
#define TWI0_twi_efr (TWI0 + 0x1c) // TWI Enhance Feature Register ()
#define TWI0_twi_efr_OFFSET 0x1c
#define TWI0_twi_efr_dbn 0x3
#define TWI0_twi_efr_dbn_SHIFT 0
#define TWI0_twi_lcr (TWI0 + 0x20) // TWI Line Control Register ()
#define TWI0_twi_lcr_OFFSET 0x20
#define TWI0_twi_lcr_scl_state (0x1 << 5)
#define TWI0_twi_lcr_scl_state_SHIFT 5
#define TWI0_twi_lcr_sda_state (0x1 << 4)
#define TWI0_twi_lcr_sda_state_SHIFT 4
#define TWI0_twi_lcr_scl_ctl (0x1 << 3)
#define TWI0_twi_lcr_scl_ctl_SHIFT 3
#define TWI0_twi_lcr_scl_ctl_en (0x1 << 2)
#define TWI0_twi_lcr_scl_ctl_en_SHIFT 2
#define TWI0_twi_lcr_sda_ctl (0x1 << 1)
#define TWI0_twi_lcr_sda_ctl_SHIFT 1
#define TWI0_twi_lcr_sda_ctl_en 0x1
#define TWI0_twi_lcr_sda_ctl_en_SHIFT 0
#define TWI0_twi_drv_ctrl (TWI0 + 0x200) // TWI_DRV Control Register ()
#define TWI0_twi_drv_ctrl_OFFSET 0x200
#define TWI0_twi_drv_ctrl_start_tran (0x1 << 31)
#define TWI0_twi_drv_ctrl_start_tran_SHIFT 31
#define TWI0_twi_drv_ctrl_restart_mode (0x1 << 29)
#define TWI0_twi_drv_ctrl_restart_mode_SHIFT 29
#define TWI0_twi_drv_ctrl_read_tran_mode (0x1 << 28)
#define TWI0_twi_drv_ctrl_read_tran_mode_SHIFT 28
#define TWI0_twi_drv_ctrl_tran_result (0xf << 24)
#define TWI0_twi_drv_ctrl_tran_result_SHIFT 24
#define TWI0_twi_drv_ctrl_twi_sta (0xff << 16)
#define TWI0_twi_drv_ctrl_twi_sta_SHIFT 16
#define TWI0_twi_drv_ctrl_timeout_n (0xff << 8)
#define TWI0_twi_drv_ctrl_timeout_n_SHIFT 8
#define TWI0_twi_drv_ctrl_soft_reset (0x1 << 1)
#define TWI0_twi_drv_ctrl_soft_reset_SHIFT 1
#define TWI0_twi_drv_ctrl_twi_drv_en 0x1
#define TWI0_twi_drv_ctrl_twi_drv_en_SHIFT 0
#define TWI0_twi_drv_cfg (TWI0 + 0x204) // TWI_DRV Transmission Configuration Register ()
#define TWI0_twi_drv_cfg_OFFSET 0x204
#define TWI0_twi_drv_cfg_pkt_interval (0xffff << 16)
#define TWI0_twi_drv_cfg_pkt_interval_SHIFT 16
#define TWI0_twi_drv_cfg_packet_cnt 0xffff
#define TWI0_twi_drv_cfg_packet_cnt_SHIFT 0
#define TWI0_twi_drv_slv (TWI0 + 0x208) // TWI_DRV Slave ID Register ()
#define TWI0_twi_drv_slv_OFFSET 0x208
#define TWI0_twi_drv_slv_slv_id (0x7f << 9)
#define TWI0_twi_drv_slv_slv_id_SHIFT 9
#define TWI0_twi_drv_slv_cmd (0x1 << 8)
#define TWI0_twi_drv_slv_cmd_SHIFT 8
#define TWI0_twi_drv_slv_slv_id_x 0xff
#define TWI0_twi_drv_slv_slv_id_x_SHIFT 0
#define TWI0_twi_drv_fmt (TWI0 + 0x20c) // TWI_DRV Packet Format Register ()
#define TWI0_twi_drv_fmt_OFFSET 0x20c
#define TWI0_twi_drv_fmt_addr_byte (0xff << 16)
#define TWI0_twi_drv_fmt_addr_byte_SHIFT 16
#define TWI0_twi_drv_fmt_data_byte 0xffff
#define TWI0_twi_drv_fmt_data_byte_SHIFT 0
#define TWI0_twi_drv_bus_ctrl (TWI0 + 0x210) // TWI_DRV Bus Control Register ()
#define TWI0_twi_drv_bus_ctrl_OFFSET 0x210
#define TWI0_twi_drv_bus_ctrl_clk_count_mode (0x1 << 16)
#define TWI0_twi_drv_bus_ctrl_clk_count_mode_SHIFT 16
#define TWI0_twi_drv_bus_ctrl_clk_duty (0x1 << 15)
#define TWI0_twi_drv_bus_ctrl_clk_duty_SHIFT 15
#define TWI0_twi_drv_bus_ctrl_clk_n (0x7 << 12)
#define TWI0_twi_drv_bus_ctrl_clk_n_SHIFT 12
#define TWI0_twi_drv_bus_ctrl_clk_m (0xf << 8)
#define TWI0_twi_drv_bus_ctrl_clk_m_SHIFT 8
#define TWI0_twi_drv_bus_ctrl_scl_sta (0x1 << 7)
#define TWI0_twi_drv_bus_ctrl_scl_sta_SHIFT 7
#define TWI0_twi_drv_bus_ctrl_sda_sta (0x1 << 6)
#define TWI0_twi_drv_bus_ctrl_sda_sta_SHIFT 6
#define TWI0_twi_drv_bus_ctrl_scl_mov (0x1 << 3)
#define TWI0_twi_drv_bus_ctrl_scl_mov_SHIFT 3
#define TWI0_twi_drv_bus_ctrl_sda_mov (0x1 << 2)
#define TWI0_twi_drv_bus_ctrl_sda_mov_SHIFT 2
#define TWI0_twi_drv_bus_ctrl_scl_moe (0x1 << 1)
#define TWI0_twi_drv_bus_ctrl_scl_moe_SHIFT 1
#define TWI0_twi_drv_bus_ctrl_sda_moe 0x1
#define TWI0_twi_drv_bus_ctrl_sda_moe_SHIFT 0
#define TWI0_twi_drv_int_ctrl (TWI0 + 0x214) // TWI_DRV Interrupt Control Register ()
#define TWI0_twi_drv_int_ctrl_OFFSET 0x214
#define TWI0_twi_drv_int_ctrl_rx_req_int_en (0x1 << 19)
#define TWI0_twi_drv_int_ctrl_rx_req_int_en_SHIFT 19
#define TWI0_twi_drv_int_ctrl_tx_req_int_en (0x1 << 18)
#define TWI0_twi_drv_int_ctrl_tx_req_int_en_SHIFT 18
#define TWI0_twi_drv_int_ctrl_tran_err_int_en (0x1 << 17)
#define TWI0_twi_drv_int_ctrl_tran_err_int_en_SHIFT 17
#define TWI0_twi_drv_int_ctrl_tran_com_int_en (0x1 << 16)
#define TWI0_twi_drv_int_ctrl_tran_com_int_en_SHIFT 16
#define TWI0_twi_drv_int_ctrl_rx_req_pd (0x1 << 3)
#define TWI0_twi_drv_int_ctrl_rx_req_pd_SHIFT 3
#define TWI0_twi_drv_int_ctrl_tx_req_pd (0x1 << 2)
#define TWI0_twi_drv_int_ctrl_tx_req_pd_SHIFT 2
#define TWI0_twi_drv_int_ctrl_tran_err_pd (0x1 << 1)
#define TWI0_twi_drv_int_ctrl_tran_err_pd_SHIFT 1
#define TWI0_twi_drv_int_ctrl_tran_com_pd 0x1
#define TWI0_twi_drv_int_ctrl_tran_com_pd_SHIFT 0
#define TWI0_twi_drv_dma_cfg (TWI0 + 0x218) // TWI_DRV DMA Configure Register ()
#define TWI0_twi_drv_dma_cfg_OFFSET 0x218
#define TWI0_twi_drv_dma_cfg_dma_rx_en (0x3 << 23)
#define TWI0_twi_drv_dma_cfg_dma_rx_en_SHIFT 23
#define TWI0_twi_drv_dma_cfg_rx_trig (0x3f << 16)
#define TWI0_twi_drv_dma_cfg_rx_trig_SHIFT 16
#define TWI0_twi_drv_dma_cfg_dma_tx_en (0x1 << 8)
#define TWI0_twi_drv_dma_cfg_dma_tx_en_SHIFT 8
#define TWI0_twi_drv_dma_cfg_tx_trig 0x3f
#define TWI0_twi_drv_dma_cfg_tx_trig_SHIFT 0
#define TWI0_twi_drv_fifo_con (TWI0 + 0x21c) // TWI_DRV FIFO Content Register ()
#define TWI0_twi_drv_fifo_con_OFFSET 0x21c
#define TWI0_twi_drv_fifo_con_recv_fifo_clear (0x1 << 22)
#define TWI0_twi_drv_fifo_con_recv_fifo_clear_SHIFT 22
#define TWI0_twi_drv_fifo_con_recv_fifo_content (0x3f << 16)
#define TWI0_twi_drv_fifo_con_recv_fifo_content_SHIFT 16
#define TWI0_twi_drv_fifo_con_send_fifo_clear (0x1 << 6)
#define TWI0_twi_drv_fifo_con_send_fifo_clear_SHIFT 6
#define TWI0_twi_drv_fifo_con_send_fifo_content 0x3f
#define TWI0_twi_drv_fifo_con_send_fifo_content_SHIFT 0
#define TWI0_twi_drv_send_fifo_acc (TWI0 + 0x300) // TWI_DRV Send Data FIFO Access Register (W only)
#define TWI0_twi_drv_send_fifo_acc_OFFSET 0x300
#define TWI0_twi_drv_send_fifo_acc_send_data_fifo 0xff
#define TWI0_twi_drv_send_fifo_acc_send_data_fifo_SHIFT 0
#define TWI0_twi_drv_recv_fifo_acc (TWI0 + 0x304) // TWI_DRV Receive Data FIFO Access Register (R only)
#define TWI0_twi_drv_recv_fifo_acc_OFFSET 0x304
#define TWI0_twi_drv_recv_fifo_acc_recv_data_fifo 0xff
#define TWI0_twi_drv_recv_fifo_acc_recv_data_fifo_SHIFT 0

/****************************************************************
 * Universal Asynchronous Receiver Transmitter
 ****************************************************************/
#define UART0 0x02500000
#define UART0_rbr (UART0 + 0x0) // UART Receive Buffer Register (R only)
#define UART0_rbr_OFFSET 0x0
#define UART0_rbr_rbr 0xff
#define UART0_rbr_rbr_SHIFT 0
#define UART0_thr (UART0 + 0x0) // UART Transmit Holding Register (W only)
#define UART0_thr_OFFSET 0x0
#define UART0_thr_thr 0xff
#define UART0_thr_thr_SHIFT 0
#define UART0_dll (UART0 + 0x0) // UART Divisor Latch Low Register ()
#define UART0_dll_OFFSET 0x0
#define UART0_dll_dll 0xff
#define UART0_dll_dll_SHIFT 0
#define UART0_dlh (UART0 + 0x4) // UART Divisor Latch High Register ()
#define UART0_dlh_OFFSET 0x4
#define UART0_dlh_dlh 0xff
#define UART0_dlh_dlh_SHIFT 0
#define UART0_ier (UART0 + 0x4) // UART Interrupt Enable Register ()
#define UART0_ier_OFFSET 0x4
#define UART0_ier_ptime (0x1 << 7)
#define UART0_ier_ptime_SHIFT 7
#define UART0_ier_rs485_int_en (0x1 << 4)
#define UART0_ier_rs485_int_en_SHIFT 4
#define UART0_ier_edssi (0x1 << 3)
#define UART0_ier_edssi_SHIFT 3
#define UART0_ier_elsi (0x1 << 2)
#define UART0_ier_elsi_SHIFT 2
#define UART0_ier_etbei (0x1 << 1)
#define UART0_ier_etbei_SHIFT 1
#define UART0_ier_erbfi 0x1
#define UART0_ier_erbfi_SHIFT 0
#define UART0_iir (UART0 + 0x8) // UART Interrupt Identity Register (R only)
#define UART0_iir_OFFSET 0x8
#define UART0_iir_feflag (0x3 << 6)
#define UART0_iir_feflag_SHIFT 6
#define UART0_iir_iid 0xf
#define UART0_iir_iid_SHIFT 0
#define UART0_fcr (UART0 + 0x8) // UART FIFO Control Register (W only)
#define UART0_fcr_OFFSET 0x8
#define UART0_fcr_rt (0x3 << 6)
#define UART0_fcr_rt_SHIFT 6
#define UART0_fcr_tft (0x3 << 4)
#define UART0_fcr_tft_SHIFT 4
#define UART0_fcr_dmam (0x1 << 3)
#define UART0_fcr_dmam_SHIFT 3
#define UART0_fcr_xfifor (0x1 << 2)
#define UART0_fcr_xfifor_SHIFT 2
#define UART0_fcr_rfifor (0x1 << 1)
#define UART0_fcr_rfifor_SHIFT 1
#define UART0_fcr_fifoe 0x1
#define UART0_fcr_fifoe_SHIFT 0
#define UART0_lcr (UART0 + 0xc) // UART Line Control Register ()
#define UART0_lcr_OFFSET 0xc
#define UART0_lcr_dlab (0x1 << 7)
#define UART0_lcr_dlab_SHIFT 7
#define UART0_lcr_bc (0x1 << 6)
#define UART0_lcr_bc_SHIFT 6
#define UART0_lcr_eps (0x3 << 4)
#define UART0_lcr_eps_SHIFT 4
#define UART0_lcr_pen (0x1 << 3)
#define UART0_lcr_pen_SHIFT 3
#define UART0_lcr_stop (0x1 << 2)
#define UART0_lcr_stop_SHIFT 2
#define UART0_lcr_dls 0x3
#define UART0_lcr_dls_SHIFT 0
#define UART0_mcr (UART0 + 0x10) // UART Modem Control Register ()
#define UART0_mcr_OFFSET 0x10
#define UART0_mcr_function (0x3 << 6)
#define UART0_mcr_function_SHIFT 6
#define UART0_mcr_afce (0x1 << 5)
#define UART0_mcr_afce_SHIFT 5
#define UART0_mcr_loop (0x1 << 4)
#define UART0_mcr_loop_SHIFT 4
#define UART0_mcr_rts (0x1 << 1)
#define UART0_mcr_rts_SHIFT 1
#define UART0_mcr_dtr 0x1
#define UART0_mcr_dtr_SHIFT 0
#define UART0_lsr (UART0 + 0x14) // UART Line Status Register (R only)
#define UART0_lsr_OFFSET 0x14
#define UART0_lsr_fifoerr (0x1 << 7)
#define UART0_lsr_fifoerr_SHIFT 7
#define UART0_lsr_temt (0x1 << 6)
#define UART0_lsr_temt_SHIFT 6
#define UART0_lsr_thre (0x1 << 5)
#define UART0_lsr_thre_SHIFT 5
#define UART0_lsr_bi (0x1 << 4)
#define UART0_lsr_bi_SHIFT 4
#define UART0_lsr_fe (0x1 << 3)
#define UART0_lsr_fe_SHIFT 3
#define UART0_lsr_pe (0x1 << 2)
#define UART0_lsr_pe_SHIFT 2
#define UART0_lsr_oe (0x1 << 1)
#define UART0_lsr_oe_SHIFT 1
#define UART0_lsr_dr 0x1
#define UART0_lsr_dr_SHIFT 0
#define UART0_msr (UART0 + 0x18) // UART Modem Status Register (R only)
#define UART0_msr_OFFSET 0x18
#define UART0_msr_dcd (0x1 << 7)
#define UART0_msr_dcd_SHIFT 7
#define UART0_msr_ri (0x1 << 6)
#define UART0_msr_ri_SHIFT 6
#define UART0_msr_dsr (0x1 << 5)
#define UART0_msr_dsr_SHIFT 5
#define UART0_msr_cts (0x1 << 4)
#define UART0_msr_cts_SHIFT 4
#define UART0_msr_ddcd (0x1 << 3)
#define UART0_msr_ddcd_SHIFT 3
#define UART0_msr_teri (0x1 << 2)
#define UART0_msr_teri_SHIFT 2
#define UART0_msr_ddsr (0x1 << 1)
#define UART0_msr_ddsr_SHIFT 1
#define UART0_msr_dcts 0x1
#define UART0_msr_dcts_SHIFT 0
#define UART0_sch (UART0 + 0x1c) // UART Scratch Register ()
#define UART0_sch_OFFSET 0x1c
#define UART0_sch_scratch 0xff
#define UART0_sch_scratch_SHIFT 0
#define UART0_usr (UART0 + 0x7c) // UART Status Register (R only)
#define UART0_usr_OFFSET 0x7c
#define UART0_usr_rff (0x1 << 4)
#define UART0_usr_rff_SHIFT 4
#define UART0_usr_rfne (0x1 << 3)
#define UART0_usr_rfne_SHIFT 3
#define UART0_usr_tfe (0x1 << 2)
#define UART0_usr_tfe_SHIFT 2
#define UART0_usr_tfnf (0x1 << 1)
#define UART0_usr_tfnf_SHIFT 1
#define UART0_usr_busy 0x1
#define UART0_usr_busy_SHIFT 0
#define UART0_tfl (UART0 + 0x80) // UART Transmit FIFO Level Register (R only)
#define UART0_tfl_OFFSET 0x80
#define UART0_tfl_tfl 0x1ff
#define UART0_tfl_tfl_SHIFT 0
#define UART0_rfl (UART0 + 0x84) // UART Receive FIFO Level Register (R only)
#define UART0_rfl_OFFSET 0x84
#define UART0_rfl_rfl 0x1ff
#define UART0_rfl_rfl_SHIFT 0
#define UART0_hsk (UART0 + 0x88) // UART DMA Handshake Configuration Register ()
#define UART0_hsk_OFFSET 0x88
#define UART0_hsk_hsk 0xff
#define UART0_hsk_hsk_SHIFT 0
#define UART0_dma_req_en (UART0 + 0x8c) // UART DMA Request Enable Register ()
#define UART0_dma_req_en_OFFSET 0x8c
#define UART0_dma_req_en_timeout_enable (0x1 << 2)
#define UART0_dma_req_en_timeout_enable_SHIFT 2
#define UART0_dma_req_en_tx_req_enable (0x1 << 1)
#define UART0_dma_req_en_tx_req_enable_SHIFT 1
#define UART0_dma_req_en_rx_req_enable 0x1
#define UART0_dma_req_en_rx_req_enable_SHIFT 0
#define UART0_halt (UART0 + 0xa4) // UART Halt TX Register ()
#define UART0_halt_OFFSET 0xa4
#define UART0_halt_pte (0x1 << 7)
#define UART0_halt_pte_SHIFT 7
#define UART0_halt_dma_pte_rx (0x1 << 6)
#define UART0_halt_dma_pte_rx_SHIFT 6
#define UART0_halt_sir_rx_invert (0x1 << 5)
#define UART0_halt_sir_rx_invert_SHIFT 5
#define UART0_halt_sir_tx_invert (0x1 << 4)
#define UART0_halt_sir_tx_invert_SHIFT 4
#define UART0_halt_change_update (0x1 << 2)
#define UART0_halt_change_update_SHIFT 2
#define UART0_halt_chcfg_at_busy (0x1 << 1)
#define UART0_halt_chcfg_at_busy_SHIFT 1
#define UART0_halt_halt_tx 0x1
#define UART0_halt_halt_tx_SHIFT 0
#define UART0_dbg_dll (UART0 + 0xb0) // UART Debug DLL Register (R only)
#define UART0_dbg_dll_OFFSET 0xb0
#define UART0_dbg_dll_dbg_dll 0xff
#define UART0_dbg_dll_dbg_dll_SHIFT 0
#define UART0_dbg_dlh (UART0 + 0xb4) // UART Debug DLH Register (R only)
#define UART0_dbg_dlh_OFFSET 0xb4
#define UART0_dbg_dlh_dbg_dlh 0xff
#define UART0_dbg_dlh_dbg_dlh_SHIFT 0
#define UART0_fcc (UART0 + 0xf0) // UART FIFO Clock Control Register ()
#define UART0_fcc_OFFSET 0xf0
#define UART0_fcc_fifo_depth (0xffffff << 8)
#define UART0_fcc_fifo_depth_SHIFT 8
#define UART0_fcc_rx_fifo_clock_mode (0x1 << 2)
#define UART0_fcc_rx_fifo_clock_mode_SHIFT 2
#define UART0_fcc_tx_fifo_clock_enable (0x1 << 1)
#define UART0_fcc_tx_fifo_clock_enable_SHIFT 1
#define UART0_fcc_rx_fifo_clock_enable 0x1
#define UART0_fcc_rx_fifo_clock_enable_SHIFT 0
#define UART0_rxdma_ctrl (UART0 + 0x100) // UART RXDMA Control Register ()
#define UART0_rxdma_ctrl_OFFSET 0x100
#define UART0_rxdma_ctrl_timeout_threshold (0xffff << 8)
#define UART0_rxdma_ctrl_timeout_threshold_SHIFT 8
#define UART0_rxdma_ctrl_timeout_enable (0x1 << 6)
#define UART0_rxdma_ctrl_timeout_enable_SHIFT 6
#define UART0_rxdma_ctrl_ahb_burst_mode (0x3 << 4)
#define UART0_rxdma_ctrl_ahb_burst_mode_SHIFT 4
#define UART0_rxdma_ctrl_blk_size (0x3 << 2)
#define UART0_rxdma_ctrl_blk_size_SHIFT 2
#define UART0_rxdma_ctrl_mode (0x1 << 1)
#define UART0_rxdma_ctrl_mode_SHIFT 1
#define UART0_rxdma_ctrl_enable 0x1
#define UART0_rxdma_ctrl_enable_SHIFT 0
#define UART0_rxdma_str (UART0 + 0x104) // UART RXDMA Start Register ()
#define UART0_rxdma_str_OFFSET 0x104
#define UART0_rxdma_str_start 0x1
#define UART0_rxdma_str_start_SHIFT 0
#define UART0_rxdma_sta (UART0 + 0x108) // UART RXDMA Status Register ()
#define UART0_rxdma_sta_OFFSET 0x108
#define UART0_rxdma_sta_buffer_read_address_updating (0x1 << 1)
#define UART0_rxdma_sta_buffer_read_address_updating_SHIFT 1
#define UART0_rxdma_sta_busy 0x1
#define UART0_rxdma_sta_busy_SHIFT 0
#define UART0_rxdma_lmt (UART0 + 0x10c) // UART RXDMA Limit Register ()
#define UART0_rxdma_lmt_OFFSET 0x10c
#define UART0_rxdma_lmt_limit_size 0xffff
#define UART0_rxdma_lmt_limit_size_SHIFT 0
#define UART0_rxdma_saddrl (UART0 + 0x110) // UART RXDMA Buffer Start Address Low Register ()
#define UART0_rxdma_saddrl_OFFSET 0x110
#define UART0_rxdma_saddrh (UART0 + 0x114) // UART RXDMA Buffer Start Address High Register ()
#define UART0_rxdma_saddrh_OFFSET 0x114
#define UART0_rxdma_saddrh_saddr 0x3
#define UART0_rxdma_saddrh_saddr_SHIFT 0
#define UART0_rxdma_bl (UART0 + 0x118) // UART RXDMA Buffer Length Register ()
#define UART0_rxdma_bl_OFFSET 0x118
#define UART0_rxdma_bl_buffer_length 0xffff
#define UART0_rxdma_bl_buffer_length_SHIFT 0
#define UART0_rxdma_ie (UART0 + 0x120) // UART RXDMA Interrupt Enable Register ()
#define UART0_rxdma_ie_OFFSET 0x120
#define UART0_rxdma_ie_buffer_overrun (0x1 << 3)
#define UART0_rxdma_ie_buffer_overrun_SHIFT 3
#define UART0_rxdma_ie_timeout_done (0x1 << 2)
#define UART0_rxdma_ie_timeout_done_SHIFT 2
#define UART0_rxdma_ie_blk_done (0x1 << 1)
#define UART0_rxdma_ie_blk_done_SHIFT 1
#define UART0_rxdma_ie_limit_done 0x1
#define UART0_rxdma_ie_limit_done_SHIFT 0
#define UART0_rxdma_is (UART0 + 0x124) // UART RXDMA Interrupt Status Register ()
#define UART0_rxdma_is_OFFSET 0x124
#define UART0_rxdma_is_buffer_overrun (0x1 << 3)
#define UART0_rxdma_is_buffer_overrun_SHIFT 3
#define UART0_rxdma_is_timeout_done (0x1 << 2)
#define UART0_rxdma_is_timeout_done_SHIFT 2
#define UART0_rxdma_is_blk_done (0x1 << 1)
#define UART0_rxdma_is_blk_done_SHIFT 1
#define UART0_rxdma_is_limit_done 0x1
#define UART0_rxdma_is_limit_done_SHIFT 0
#define UART0_rxdma_waddrl (UART0 + 0x128) // UART RXDMA Write Address Low Register (R only)
#define UART0_rxdma_waddrl_OFFSET 0x128
#define UART0_rxdma_waddrh (UART0 + 0x12c) // UART RXDMA Write Address High Register (R only)
#define UART0_rxdma_waddrh_OFFSET 0x12c
#define UART0_rxdma_waddrh_waddr 0x3
#define UART0_rxdma_waddrh_waddr_SHIFT 0
#define UART0_rxdma_raddrl (UART0 + 0x130) // UART RXDMA Read Address Low Register ()
#define UART0_rxdma_raddrl_OFFSET 0x130
#define UART0_rxdma_raddrh (UART0 + 0x134) // UART RXDMA Read Address High Register ()
#define UART0_rxdma_raddrh_OFFSET 0x134
#define UART0_rxdma_raddrh_raddr 0x3
#define UART0_rxdma_raddrh_raddr_SHIFT 0
#define UART0_rxdma_dcnt (UART0 + 0x138) // UART RXDMA Data Count Register ()
#define UART0_rxdma_dcnt_OFFSET 0x138
#define UART0_rxdma_dcnt_data_count 0xffff
#define UART0_rxdma_dcnt_data_count_SHIFT 0

/****************************************************************
 * Serial Peripheral Interface
 ****************************************************************/
#define SPI0 0x04025000
#define SPI0_spi_gcr (SPI0 + 0x4) // SPI Global Control Register ()
#define SPI0_spi_gcr_OFFSET 0x4
#define SPI0_spi_gcr_srst (0x1 << 31)
#define SPI0_spi_gcr_srst_SHIFT 31
#define SPI0_spi_gcr_tp_en (0x1 << 7)
#define SPI0_spi_gcr_tp_en_SHIFT 7
#define SPI0_spi_gcr_mode_selec (0x1 << 2)
#define SPI0_spi_gcr_mode_selec_SHIFT 2
#define SPI0_spi_gcr_mode (0x1 << 1)
#define SPI0_spi_gcr_mode_SHIFT 1
#define SPI0_spi_gcr_en 0x1
#define SPI0_spi_gcr_en_SHIFT 0
#define SPI0_spi_tcr (SPI0 + 0x8) // SPI Transfer Control Register ()
#define SPI0_spi_tcr_OFFSET 0x8
#define SPI0_spi_tcr_xch (0x1 << 31)
#define SPI0_spi_tcr_xch_SHIFT 31
#define SPI0_spi_tcr_sdc1 (0x1 << 15)
#define SPI0_spi_tcr_sdc1_SHIFT 15
#define SPI0_spi_tcr_sddm (0x1 << 14)
#define SPI0_spi_tcr_sddm_SHIFT 14
#define SPI0_spi_tcr_sdm (0x1 << 13)
#define SPI0_spi_tcr_sdm_SHIFT 13
#define SPI0_spi_tcr_fbs (0x1 << 12)
#define SPI0_spi_tcr_fbs_SHIFT 12
#define SPI0_spi_tcr_sdc (0x1 << 11)
#define SPI0_spi_tcr_sdc_SHIFT 11
#define SPI0_spi_tcr_rpsm (0x1 << 10)
#define SPI0_spi_tcr_rpsm_SHIFT 10
#define SPI0_spi_tcr_ddb (0x1 << 9)
#define SPI0_spi_tcr_ddb_SHIFT 9
#define SPI0_spi_tcr_dhb (0x1 << 8)
#define SPI0_spi_tcr_dhb_SHIFT 8
#define SPI0_spi_tcr_ss_level (0x1 << 7)
#define SPI0_spi_tcr_ss_level_SHIFT 7
#define SPI0_spi_tcr_ss_owner (0x1 << 6)
#define SPI0_spi_tcr_ss_owner_SHIFT 6
#define SPI0_spi_tcr_ss_sel (0x3 << 4)
#define SPI0_spi_tcr_ss_sel_SHIFT 4
#define SPI0_spi_tcr_ssctl (0x1 << 3)
#define SPI0_spi_tcr_ssctl_SHIFT 3
#define SPI0_spi_tcr_spol (0x1 << 2)
#define SPI0_spi_tcr_spol_SHIFT 2
#define SPI0_spi_tcr_cpol (0x1 << 1)
#define SPI0_spi_tcr_cpol_SHIFT 1
#define SPI0_spi_tcr_cpha 0x1
#define SPI0_spi_tcr_cpha_SHIFT 0
#define SPI0_spi_ier (SPI0 + 0x10) // SPI Interrupt Control Register ()
#define SPI0_spi_ier_OFFSET 0x10
#define SPI0_spi_ier_ss_int_en (0x1 << 13)
#define SPI0_spi_ier_ss_int_en_SHIFT 13
#define SPI0_spi_ier_tc_int_en (0x1 << 12)
#define SPI0_spi_ier_tc_int_en_SHIFT 12
#define SPI0_spi_ier_tf_udr_int_en (0x1 << 11)
#define SPI0_spi_ier_tf_udr_int_en_SHIFT 11
#define SPI0_spi_ier_tf_ovf_int_en (0x1 << 10)
#define SPI0_spi_ier_tf_ovf_int_en_SHIFT 10
#define SPI0_spi_ier_rf_udr_int_en (0x1 << 9)
#define SPI0_spi_ier_rf_udr_int_en_SHIFT 9
#define SPI0_spi_ier_rf_ovf_int_en (0x1 << 8)
#define SPI0_spi_ier_rf_ovf_int_en_SHIFT 8
#define SPI0_spi_ier_tf_full_int_en (0x1 << 6)
#define SPI0_spi_ier_tf_full_int_en_SHIFT 6
#define SPI0_spi_ier_tf_emp_int_en (0x1 << 5)
#define SPI0_spi_ier_tf_emp_int_en_SHIFT 5
#define SPI0_spi_ier_tf_erq_int_en (0x1 << 4)
#define SPI0_spi_ier_tf_erq_int_en_SHIFT 4
#define SPI0_spi_ier_rf_full_int_en (0x1 << 2)
#define SPI0_spi_ier_rf_full_int_en_SHIFT 2
#define SPI0_spi_ier_rf_emp_int_en (0x1 << 1)
#define SPI0_spi_ier_rf_emp_int_en_SHIFT 1
#define SPI0_spi_ier_rf_rdy_int_en 0x1
#define SPI0_spi_ier_rf_rdy_int_en_SHIFT 0
#define SPI0_spi_isr (SPI0 + 0x14) // SPI Interrupt Status Register ()
#define SPI0_spi_isr_OFFSET 0x14
#define SPI0_spi_isr_ssi (0x1 << 13)
#define SPI0_spi_isr_ssi_SHIFT 13
#define SPI0_spi_isr_tc (0x1 << 12)
#define SPI0_spi_isr_tc_SHIFT 12
#define SPI0_spi_isr_tf_udr (0x1 << 11)
#define SPI0_spi_isr_tf_udr_SHIFT 11
#define SPI0_spi_isr_tf_ovf (0x1 << 10)
#define SPI0_spi_isr_tf_ovf_SHIFT 10
#define SPI0_spi_isr_rf_udr (0x1 << 9)
#define SPI0_spi_isr_rf_udr_SHIFT 9
#define SPI0_spi_isr_rf_ovf (0x1 << 8)
#define SPI0_spi_isr_rf_ovf_SHIFT 8
#define SPI0_spi_isr_tf_full (0x1 << 6)
#define SPI0_spi_isr_tf_full_SHIFT 6
#define SPI0_spi_isr_tf_emp (0x1 << 5)
#define SPI0_spi_isr_tf_emp_SHIFT 5
#define SPI0_spi_isr_tf_ready (0x1 << 4)
#define SPI0_spi_isr_tf_ready_SHIFT 4
#define SPI0_spi_isr_rf_full (0x1 << 2)
#define SPI0_spi_isr_rf_full_SHIFT 2
#define SPI0_spi_isr_rf_emp (0x1 << 1)
#define SPI0_spi_isr_rf_emp_SHIFT 1
#define SPI0_spi_isr_rf_rdy 0x1
#define SPI0_spi_isr_rf_rdy_SHIFT 0
#define SPI0_spi_fcr (SPI0 + 0x18) // SPI FIFO Control Register ()
#define SPI0_spi_fcr_OFFSET 0x18
#define SPI0_spi_fcr_tf_rst (0x1 << 31)
#define SPI0_spi_fcr_tf_rst_SHIFT 31
#define SPI0_spi_fcr_tf_test_en (0x1 << 30)
#define SPI0_spi_fcr_tf_test_en_SHIFT 30
#define SPI0_spi_fcr_tf_drq_en (0x1 << 24)
#define SPI0_spi_fcr_tf_drq_en_SHIFT 24
#define SPI0_spi_fcr_tf_trig_level (0xff << 16)
#define SPI0_spi_fcr_tf_trig_level_SHIFT 16
#define SPI0_spi_fcr_rf_rst (0x1 << 15)
#define SPI0_spi_fcr_rf_rst_SHIFT 15
#define SPI0_spi_fcr_rf_test_en (0x1 << 14)
#define SPI0_spi_fcr_rf_test_en_SHIFT 14
#define SPI0_spi_fcr_rf_drq_en (0x1 << 8)
#define SPI0_spi_fcr_rf_drq_en_SHIFT 8
#define SPI0_spi_fcr_rf_trig_level 0xff
#define SPI0_spi_fcr_rf_trig_level_SHIFT 0
#define SPI0_spi_fsr (SPI0 + 0x1c) // SPI FIFO Status Register (R only)
#define SPI0_spi_fsr_OFFSET 0x1c
#define SPI0_spi_fsr_tb_wr (0x1 << 31)
#define SPI0_spi_fsr_tb_wr_SHIFT 31
#define SPI0_spi_fsr_tb_cnt (0x7 << 28)
#define SPI0_spi_fsr_tb_cnt_SHIFT 28
#define SPI0_spi_fsr_tf_cnt (0xff << 16)
#define SPI0_spi_fsr_tf_cnt_SHIFT 16
#define SPI0_spi_fsr_rb_wr (0x1 << 15)
#define SPI0_spi_fsr_rb_wr_SHIFT 15
#define SPI0_spi_fsr_rb_cnt (0x7 << 12)
#define SPI0_spi_fsr_rb_cnt_SHIFT 12
#define SPI0_spi_fsr_rf_cnt 0xff
#define SPI0_spi_fsr_rf_cnt_SHIFT 0
#define SPI0_spi_wcr (SPI0 + 0x20) // SPI Wait Clock Register ()
#define SPI0_spi_wcr_OFFSET 0x20
#define SPI0_spi_wcr_swc (0xf << 16)
#define SPI0_spi_wcr_swc_SHIFT 16
#define SPI0_spi_wcr_wwc 0xffff
#define SPI0_spi_wcr_wwc_SHIFT 0
#define SPI0_spi_samp_dl (SPI0 + 0x28) // SPI Sample Delay Control Register ()
#define SPI0_spi_samp_dl_OFFSET 0x28
#define SPI0_spi_samp_dl_samp_dl_cal_start (0x1 << 15)
#define SPI0_spi_samp_dl_samp_dl_cal_start_SHIFT 15
#define SPI0_spi_samp_dl_samp_dl_cal_done (0x1 << 14)
#define SPI0_spi_samp_dl_samp_dl_cal_done_SHIFT 14
#define SPI0_spi_samp_dl_samp_dl (0x3f << 8)
#define SPI0_spi_samp_dl_samp_dl_SHIFT 8
#define SPI0_spi_samp_dl_samp_dl_sw_en (0x1 << 7)
#define SPI0_spi_samp_dl_samp_dl_sw_en_SHIFT 7
#define SPI0_spi_samp_dl_samp_dl_sw 0x3f
#define SPI0_spi_samp_dl_samp_dl_sw_SHIFT 0
#define SPI0_spi_mbc (SPI0 + 0x30) // SPI Master Burst Counter Register ()
#define SPI0_spi_mbc_OFFSET 0x30
#define SPI0_spi_mbc_mbc 0xffffff
#define SPI0_spi_mbc_mbc_SHIFT 0
#define SPI0_spi_mtc (SPI0 + 0x34) // SPI Master Transmit Counter Register ()
#define SPI0_spi_mtc_OFFSET 0x34
#define SPI0_spi_mtc_mwtc 0xffffff
#define SPI0_spi_mtc_mwtc_SHIFT 0
#define SPI0_spi_bcc (SPI0 + 0x38) // SPI Master Burst Control Register ()
#define SPI0_spi_bcc_OFFSET 0x38
#define SPI0_spi_bcc_quad_en (0x1 << 29)
#define SPI0_spi_bcc_quad_en_SHIFT 29
#define SPI0_spi_bcc_drm (0x1 << 28)
#define SPI0_spi_bcc_drm_SHIFT 28
#define SPI0_spi_bcc_dbc (0xf << 24)
#define SPI0_spi_bcc_dbc_SHIFT 24
#define SPI0_spi_bcc_stc 0xffffff
#define SPI0_spi_bcc_stc_SHIFT 0
#define SPI0_spi_batc (SPI0 + 0x40) // SPI Bit-Aligned Transfer Configure Register ()
#define SPI0_spi_batc_OFFSET 0x40
#define SPI0_spi_batc_tce (0x1 << 31)
#define SPI0_spi_batc_tce_SHIFT 31
#define SPI0_spi_batc_msms (0x1 << 30)
#define SPI0_spi_batc_msms_SHIFT 30
#define SPI0_spi_batc_tbc (0x1 << 25)
#define SPI0_spi_batc_tbc_SHIFT 25
#define SPI0_spi_batc_tbc_int_en (0x1 << 24)
#define SPI0_spi_batc_tbc_int_en_SHIFT 24
#define SPI0_spi_batc_rx_frm_len (0x3f << 16)
#define SPI0_spi_batc_rx_frm_len_SHIFT 16
#define SPI0_spi_batc_tx_frm_len (0x3f << 8)
#define SPI0_spi_batc_tx_frm_len_SHIFT 8
#define SPI0_spi_batc_ss_level (0x1 << 7)
#define SPI0_spi_batc_ss_level_SHIFT 7
#define SPI0_spi_batc_ss_owner (0x1 << 6)
#define SPI0_spi_batc_ss_owner_SHIFT 6
#define SPI0_spi_batc_spol (0x1 << 5)
#define SPI0_spi_batc_spol_SHIFT 5
#define SPI0_spi_batc_ss_sel (0x3 << 2)
#define SPI0_spi_batc_ss_sel_SHIFT 2
#define SPI0_spi_batc_wms 0x3
#define SPI0_spi_batc_wms_SHIFT 0
#define SPI0_spi_ba_ccr (SPI0 + 0x44) // SPI Bit-Aligned Clock Configuration Register ()
#define SPI0_spi_ba_ccr_OFFSET 0x44
#define SPI0_spi_ba_ccr_cdr_n 0xff
#define SPI0_spi_ba_ccr_cdr_n_SHIFT 0
#define SPI0_spi_tbr (SPI0 + 0x48) // SPI TX Bit Register\n\nVTB 31:0: The Value of the Transmit Bits ()
#define SPI0_spi_tbr_OFFSET 0x48
#define SPI0_spi_rbr (SPI0 + 0x4c) // SPI RX Bit Register\n\nVRB 31:0: The Value of the Receive Bits ()
#define SPI0_spi_rbr_OFFSET 0x4c
#define SPI0_spi_ndma_mode_ctl (SPI0 + 0x88) // SPI Normal DMA Mode Control Register ()
#define SPI0_spi_ndma_mode_ctl_OFFSET 0x88
#define SPI0_spi_ndma_mode_ctl_spi_act_m (0x3 << 6)
#define SPI0_spi_ndma_mode_ctl_spi_act_m_SHIFT 6
#define SPI0_spi_ndma_mode_ctl_spi_ack_m (0x1 << 5)
#define SPI0_spi_ndma_mode_ctl_spi_ack_m_SHIFT 5
#define SPI0_spi_ndma_mode_ctl_spi_dma_wait 0x1f
#define SPI0_spi_ndma_mode_ctl_spi_dma_wait_SHIFT 0
#define SPI0_spi_txd (SPI0 + 0x200) // SPI TX Data Register\n\nTDATA 31:0: Transmit Data in word method ()
#define SPI0_spi_txd_OFFSET 0x200
#define SPI0_spi_txd_16 (SPI0 + 0x200) // SPI TX Data Register\n\nTDATA 15:0: Transmit Data in half-word method ()
#define SPI0_spi_txd_16_OFFSET 0x200
#define SPI0_spi_txd_8 (SPI0 + 0x200) // SPI TX Data Register\n\nTDATA 7:0: Transmit Data in byte method ()
#define SPI0_spi_txd_8_OFFSET 0x200
#define SPI0_spi_rxd (SPI0 + 0x300) // SPI RX Data Register\n\nRDATA 31:0: Receive Data and access in word method ()
#define SPI0_spi_rxd_OFFSET 0x300
#define SPI0_spi_rxd_16 (SPI0 + 0x300) // SPI RX Data Register\n\nRDATA 15:0: Receive Data and access in half-word method ()
#define SPI0_spi_rxd_16_OFFSET 0x300
#define SPI0_spi_rxd_8 (SPI0 + 0x300) // SPI RX Data Register\n\nRDATA 7:0: Receive Data and access in byte method ()
#define SPI0_spi_rxd_8_OFFSET 0x300

/****************************************************************
 * Serial Peripheral Interface Display Bus Interface
 ****************************************************************/
#define SPI_DBI 0x04026000
#define SPI_DBI_spi_gcr (SPI_DBI + 0x4) // SPI Global Control Register ()
#define SPI_DBI_spi_gcr_OFFSET 0x4
#define SPI_DBI_spi_gcr_srst (0x1 << 31)
#define SPI_DBI_spi_gcr_srst_SHIFT 31
#define SPI_DBI_spi_gcr_tp_en (0x1 << 7)
#define SPI_DBI_spi_gcr_tp_en_SHIFT 7
#define SPI_DBI_spi_gcr_mode_selec (0x1 << 2)
#define SPI_DBI_spi_gcr_mode_selec_SHIFT 2
#define SPI_DBI_spi_gcr_mode (0x1 << 1)
#define SPI_DBI_spi_gcr_mode_SHIFT 1
#define SPI_DBI_spi_gcr_en 0x1
#define SPI_DBI_spi_gcr_en_SHIFT 0
#define SPI_DBI_spi_tcr (SPI_DBI + 0x8) // SPI Transfer Control Register ()
#define SPI_DBI_spi_tcr_OFFSET 0x8
#define SPI_DBI_spi_tcr_xch (0x1 << 31)
#define SPI_DBI_spi_tcr_xch_SHIFT 31
#define SPI_DBI_spi_tcr_sdc1 (0x1 << 15)
#define SPI_DBI_spi_tcr_sdc1_SHIFT 15
#define SPI_DBI_spi_tcr_sddm (0x1 << 14)
#define SPI_DBI_spi_tcr_sddm_SHIFT 14
#define SPI_DBI_spi_tcr_sdm (0x1 << 13)
#define SPI_DBI_spi_tcr_sdm_SHIFT 13
#define SPI_DBI_spi_tcr_fbs (0x1 << 12)
#define SPI_DBI_spi_tcr_fbs_SHIFT 12
#define SPI_DBI_spi_tcr_sdc (0x1 << 11)
#define SPI_DBI_spi_tcr_sdc_SHIFT 11
#define SPI_DBI_spi_tcr_rpsm (0x1 << 10)
#define SPI_DBI_spi_tcr_rpsm_SHIFT 10
#define SPI_DBI_spi_tcr_ddb (0x1 << 9)
#define SPI_DBI_spi_tcr_ddb_SHIFT 9
#define SPI_DBI_spi_tcr_dhb (0x1 << 8)
#define SPI_DBI_spi_tcr_dhb_SHIFT 8
#define SPI_DBI_spi_tcr_ss_level (0x1 << 7)
#define SPI_DBI_spi_tcr_ss_level_SHIFT 7
#define SPI_DBI_spi_tcr_ss_owner (0x1 << 6)
#define SPI_DBI_spi_tcr_ss_owner_SHIFT 6
#define SPI_DBI_spi_tcr_ss_sel (0x3 << 4)
#define SPI_DBI_spi_tcr_ss_sel_SHIFT 4
#define SPI_DBI_spi_tcr_ssctl (0x1 << 3)
#define SPI_DBI_spi_tcr_ssctl_SHIFT 3
#define SPI_DBI_spi_tcr_spol (0x1 << 2)
#define SPI_DBI_spi_tcr_spol_SHIFT 2
#define SPI_DBI_spi_tcr_cpol (0x1 << 1)
#define SPI_DBI_spi_tcr_cpol_SHIFT 1
#define SPI_DBI_spi_tcr_cpha 0x1
#define SPI_DBI_spi_tcr_cpha_SHIFT 0
#define SPI_DBI_spi_ier (SPI_DBI + 0x10) // SPI Interrupt Control Register ()
#define SPI_DBI_spi_ier_OFFSET 0x10
#define SPI_DBI_spi_ier_ss_int_en (0x1 << 13)
#define SPI_DBI_spi_ier_ss_int_en_SHIFT 13
#define SPI_DBI_spi_ier_tc_int_en (0x1 << 12)
#define SPI_DBI_spi_ier_tc_int_en_SHIFT 12
#define SPI_DBI_spi_ier_tf_udr_int_en (0x1 << 11)
#define SPI_DBI_spi_ier_tf_udr_int_en_SHIFT 11
#define SPI_DBI_spi_ier_tf_ovf_int_en (0x1 << 10)
#define SPI_DBI_spi_ier_tf_ovf_int_en_SHIFT 10
#define SPI_DBI_spi_ier_rf_udr_int_en (0x1 << 9)
#define SPI_DBI_spi_ier_rf_udr_int_en_SHIFT 9
#define SPI_DBI_spi_ier_rf_ovf_int_en (0x1 << 8)
#define SPI_DBI_spi_ier_rf_ovf_int_en_SHIFT 8
#define SPI_DBI_spi_ier_tf_full_int_en (0x1 << 6)
#define SPI_DBI_spi_ier_tf_full_int_en_SHIFT 6
#define SPI_DBI_spi_ier_tf_emp_int_en (0x1 << 5)
#define SPI_DBI_spi_ier_tf_emp_int_en_SHIFT 5
#define SPI_DBI_spi_ier_tf_erq_int_en (0x1 << 4)
#define SPI_DBI_spi_ier_tf_erq_int_en_SHIFT 4
#define SPI_DBI_spi_ier_rf_full_int_en (0x1 << 2)
#define SPI_DBI_spi_ier_rf_full_int_en_SHIFT 2
#define SPI_DBI_spi_ier_rf_emp_int_en (0x1 << 1)
#define SPI_DBI_spi_ier_rf_emp_int_en_SHIFT 1
#define SPI_DBI_spi_ier_rf_rdy_int_en 0x1
#define SPI_DBI_spi_ier_rf_rdy_int_en_SHIFT 0
#define SPI_DBI_spi_isr (SPI_DBI + 0x14) // SPI Interrupt Status Register ()
#define SPI_DBI_spi_isr_OFFSET 0x14
#define SPI_DBI_spi_isr_ssi (0x1 << 13)
#define SPI_DBI_spi_isr_ssi_SHIFT 13
#define SPI_DBI_spi_isr_tc (0x1 << 12)
#define SPI_DBI_spi_isr_tc_SHIFT 12
#define SPI_DBI_spi_isr_tf_udr (0x1 << 11)
#define SPI_DBI_spi_isr_tf_udr_SHIFT 11
#define SPI_DBI_spi_isr_tf_ovf (0x1 << 10)
#define SPI_DBI_spi_isr_tf_ovf_SHIFT 10
#define SPI_DBI_spi_isr_rf_udr (0x1 << 9)
#define SPI_DBI_spi_isr_rf_udr_SHIFT 9
#define SPI_DBI_spi_isr_rf_ovf (0x1 << 8)
#define SPI_DBI_spi_isr_rf_ovf_SHIFT 8
#define SPI_DBI_spi_isr_tf_full (0x1 << 6)
#define SPI_DBI_spi_isr_tf_full_SHIFT 6
#define SPI_DBI_spi_isr_tf_emp (0x1 << 5)
#define SPI_DBI_spi_isr_tf_emp_SHIFT 5
#define SPI_DBI_spi_isr_tf_ready (0x1 << 4)
#define SPI_DBI_spi_isr_tf_ready_SHIFT 4
#define SPI_DBI_spi_isr_rf_full (0x1 << 2)
#define SPI_DBI_spi_isr_rf_full_SHIFT 2
#define SPI_DBI_spi_isr_rf_emp (0x1 << 1)
#define SPI_DBI_spi_isr_rf_emp_SHIFT 1
#define SPI_DBI_spi_isr_rf_rdy 0x1
#define SPI_DBI_spi_isr_rf_rdy_SHIFT 0
#define SPI_DBI_spi_fcr (SPI_DBI + 0x18) // SPI FIFO Control Register ()
#define SPI_DBI_spi_fcr_OFFSET 0x18
#define SPI_DBI_spi_fcr_tf_rst (0x1 << 31)
#define SPI_DBI_spi_fcr_tf_rst_SHIFT 31
#define SPI_DBI_spi_fcr_tf_test_en (0x1 << 30)
#define SPI_DBI_spi_fcr_tf_test_en_SHIFT 30
#define SPI_DBI_spi_fcr_tf_drq_en (0x1 << 24)
#define SPI_DBI_spi_fcr_tf_drq_en_SHIFT 24
#define SPI_DBI_spi_fcr_tf_trig_level (0xff << 16)
#define SPI_DBI_spi_fcr_tf_trig_level_SHIFT 16
#define SPI_DBI_spi_fcr_rf_rst (0x1 << 15)
#define SPI_DBI_spi_fcr_rf_rst_SHIFT 15
#define SPI_DBI_spi_fcr_rf_test_en (0x1 << 14)
#define SPI_DBI_spi_fcr_rf_test_en_SHIFT 14
#define SPI_DBI_spi_fcr_rf_drq_en (0x1 << 8)
#define SPI_DBI_spi_fcr_rf_drq_en_SHIFT 8
#define SPI_DBI_spi_fcr_rf_trig_level 0xff
#define SPI_DBI_spi_fcr_rf_trig_level_SHIFT 0
#define SPI_DBI_spi_fsr (SPI_DBI + 0x1c) // SPI FIFO Status Register (R only)
#define SPI_DBI_spi_fsr_OFFSET 0x1c
#define SPI_DBI_spi_fsr_tb_wr (0x1 << 31)
#define SPI_DBI_spi_fsr_tb_wr_SHIFT 31
#define SPI_DBI_spi_fsr_tb_cnt (0x7 << 28)
#define SPI_DBI_spi_fsr_tb_cnt_SHIFT 28
#define SPI_DBI_spi_fsr_tf_cnt (0xff << 16)
#define SPI_DBI_spi_fsr_tf_cnt_SHIFT 16
#define SPI_DBI_spi_fsr_rb_wr (0x1 << 15)
#define SPI_DBI_spi_fsr_rb_wr_SHIFT 15
#define SPI_DBI_spi_fsr_rb_cnt (0x7 << 12)
#define SPI_DBI_spi_fsr_rb_cnt_SHIFT 12
#define SPI_DBI_spi_fsr_rf_cnt 0xff
#define SPI_DBI_spi_fsr_rf_cnt_SHIFT 0
#define SPI_DBI_spi_wcr (SPI_DBI + 0x20) // SPI Wait Clock Register ()
#define SPI_DBI_spi_wcr_OFFSET 0x20
#define SPI_DBI_spi_wcr_swc (0xf << 16)
#define SPI_DBI_spi_wcr_swc_SHIFT 16
#define SPI_DBI_spi_wcr_wwc 0xffff
#define SPI_DBI_spi_wcr_wwc_SHIFT 0
#define SPI_DBI_spi_samp_dl (SPI_DBI + 0x28) // SPI Sample Delay Control Register ()
#define SPI_DBI_spi_samp_dl_OFFSET 0x28
#define SPI_DBI_spi_samp_dl_samp_dl_cal_start (0x1 << 15)
#define SPI_DBI_spi_samp_dl_samp_dl_cal_start_SHIFT 15
#define SPI_DBI_spi_samp_dl_samp_dl_cal_done (0x1 << 14)
#define SPI_DBI_spi_samp_dl_samp_dl_cal_done_SHIFT 14
#define SPI_DBI_spi_samp_dl_samp_dl (0x3f << 8)
#define SPI_DBI_spi_samp_dl_samp_dl_SHIFT 8
#define SPI_DBI_spi_samp_dl_samp_dl_sw_en (0x1 << 7)
#define SPI_DBI_spi_samp_dl_samp_dl_sw_en_SHIFT 7
#define SPI_DBI_spi_samp_dl_samp_dl_sw 0x3f
#define SPI_DBI_spi_samp_dl_samp_dl_sw_SHIFT 0
#define SPI_DBI_spi_mbc (SPI_DBI + 0x30) // SPI Master Burst Counter Register ()
#define SPI_DBI_spi_mbc_OFFSET 0x30
#define SPI_DBI_spi_mbc_mbc 0xffffff
#define SPI_DBI_spi_mbc_mbc_SHIFT 0
#define SPI_DBI_spi_mtc (SPI_DBI + 0x34) // SPI Master Transmit Counter Register ()
#define SPI_DBI_spi_mtc_OFFSET 0x34
#define SPI_DBI_spi_mtc_mwtc 0xffffff
#define SPI_DBI_spi_mtc_mwtc_SHIFT 0
#define SPI_DBI_spi_bcc (SPI_DBI + 0x38) // SPI Master Burst Control Register ()
#define SPI_DBI_spi_bcc_OFFSET 0x38
#define SPI_DBI_spi_bcc_quad_en (0x1 << 29)
#define SPI_DBI_spi_bcc_quad_en_SHIFT 29
#define SPI_DBI_spi_bcc_drm (0x1 << 28)
#define SPI_DBI_spi_bcc_drm_SHIFT 28
#define SPI_DBI_spi_bcc_dbc (0xf << 24)
#define SPI_DBI_spi_bcc_dbc_SHIFT 24
#define SPI_DBI_spi_bcc_stc 0xffffff
#define SPI_DBI_spi_bcc_stc_SHIFT 0
#define SPI_DBI_spi_batc (SPI_DBI + 0x40) // SPI Bit-Aligned Transfer Configure Register ()
#define SPI_DBI_spi_batc_OFFSET 0x40
#define SPI_DBI_spi_batc_tce (0x1 << 31)
#define SPI_DBI_spi_batc_tce_SHIFT 31
#define SPI_DBI_spi_batc_msms (0x1 << 30)
#define SPI_DBI_spi_batc_msms_SHIFT 30
#define SPI_DBI_spi_batc_tbc (0x1 << 25)
#define SPI_DBI_spi_batc_tbc_SHIFT 25
#define SPI_DBI_spi_batc_tbc_int_en (0x1 << 24)
#define SPI_DBI_spi_batc_tbc_int_en_SHIFT 24
#define SPI_DBI_spi_batc_rx_frm_len (0x3f << 16)
#define SPI_DBI_spi_batc_rx_frm_len_SHIFT 16
#define SPI_DBI_spi_batc_tx_frm_len (0x3f << 8)
#define SPI_DBI_spi_batc_tx_frm_len_SHIFT 8
#define SPI_DBI_spi_batc_ss_level (0x1 << 7)
#define SPI_DBI_spi_batc_ss_level_SHIFT 7
#define SPI_DBI_spi_batc_ss_owner (0x1 << 6)
#define SPI_DBI_spi_batc_ss_owner_SHIFT 6
#define SPI_DBI_spi_batc_spol (0x1 << 5)
#define SPI_DBI_spi_batc_spol_SHIFT 5
#define SPI_DBI_spi_batc_ss_sel (0x3 << 2)
#define SPI_DBI_spi_batc_ss_sel_SHIFT 2
#define SPI_DBI_spi_batc_wms 0x3
#define SPI_DBI_spi_batc_wms_SHIFT 0
#define SPI_DBI_spi_ba_ccr (SPI_DBI + 0x44) // SPI Bit-Aligned Clock Configuration Register ()
#define SPI_DBI_spi_ba_ccr_OFFSET 0x44
#define SPI_DBI_spi_ba_ccr_cdr_n 0xff
#define SPI_DBI_spi_ba_ccr_cdr_n_SHIFT 0
#define SPI_DBI_spi_tbr (SPI_DBI + 0x48) // SPI TX Bit Register\n\nVTB 31:0: The Value of the Transmit Bits ()
#define SPI_DBI_spi_tbr_OFFSET 0x48
#define SPI_DBI_spi_rbr (SPI_DBI + 0x4c) // SPI RX Bit Register\n\nVRB 31:0: The Value of the Receive Bits ()
#define SPI_DBI_spi_rbr_OFFSET 0x4c
#define SPI_DBI_spi_ndma_mode_ctl (SPI_DBI + 0x88) // SPI Normal DMA Mode Control Register ()
#define SPI_DBI_spi_ndma_mode_ctl_OFFSET 0x88
#define SPI_DBI_spi_ndma_mode_ctl_spi_act_m (0x3 << 6)
#define SPI_DBI_spi_ndma_mode_ctl_spi_act_m_SHIFT 6
#define SPI_DBI_spi_ndma_mode_ctl_spi_ack_m (0x1 << 5)
#define SPI_DBI_spi_ndma_mode_ctl_spi_ack_m_SHIFT 5
#define SPI_DBI_spi_ndma_mode_ctl_spi_dma_wait 0x1f
#define SPI_DBI_spi_ndma_mode_ctl_spi_dma_wait_SHIFT 0
#define SPI_DBI_dbi_ctl_0 (SPI_DBI + 0x100) // DBI Control Register 0 ()
#define SPI_DBI_dbi_ctl_0_OFFSET 0x100
#define SPI_DBI_dbi_ctl_0_cmdt (0x1 << 31)
#define SPI_DBI_dbi_ctl_0_cmdt_SHIFT 31
#define SPI_DBI_dbi_ctl_0_wcdc (0x7ff << 20)
#define SPI_DBI_dbi_ctl_0_wcdc_SHIFT 20
#define SPI_DBI_dbi_ctl_0_dat_seq (0x1 << 19)
#define SPI_DBI_dbi_ctl_0_dat_seq_SHIFT 19
#define SPI_DBI_dbi_ctl_0_rgb_seq (0x7 << 16)
#define SPI_DBI_dbi_ctl_0_rgb_seq_SHIFT 16
#define SPI_DBI_dbi_ctl_0_tran_mod (0x1 << 15)
#define SPI_DBI_dbi_ctl_0_tran_mod_SHIFT 15
#define SPI_DBI_dbi_ctl_0_dat_fmt (0x7 << 12)
#define SPI_DBI_dbi_ctl_0_dat_fmt_SHIFT 12
#define SPI_DBI_dbi_ctl_0_dbi_interface (0x7 << 8)
#define SPI_DBI_dbi_ctl_0_dbi_interface_SHIFT 8
#define SPI_DBI_dbi_ctl_0_rgb_src_fmt (0xf << 4)
#define SPI_DBI_dbi_ctl_0_rgb_src_fmt_SHIFT 4
#define SPI_DBI_dbi_ctl_0_dum_val (0x1 << 3)
#define SPI_DBI_dbi_ctl_0_dum_val_SHIFT 3
#define SPI_DBI_dbi_ctl_0_rgb_bo (0x1 << 2)
#define SPI_DBI_dbi_ctl_0_rgb_bo_SHIFT 2
#define SPI_DBI_dbi_ctl_0_element_a_pos (0x1 << 1)
#define SPI_DBI_dbi_ctl_0_element_a_pos_SHIFT 1
#define SPI_DBI_dbi_ctl_0_vi_src_type 0x1
#define SPI_DBI_dbi_ctl_0_vi_src_type_SHIFT 0
#define SPI_DBI_dbi_ctl_1 (SPI_DBI + 0x104) // DBI Control Register 1 ()
#define SPI_DBI_dbi_ctl_1_OFFSET 0x104
#define SPI_DBI_dbi_ctl_1_dbi_soft_trg (0x1 << 31)
#define SPI_DBI_dbi_ctl_1_dbi_soft_trg_SHIFT 31
#define SPI_DBI_dbi_ctl_1_dbi_en_mode_sel (0x3 << 29)
#define SPI_DBI_dbi_ctl_1_dbi_en_mode_sel_SHIFT 29
#define SPI_DBI_dbi_ctl_1_rgb666_fmt (0x3 << 26)
#define SPI_DBI_dbi_ctl_1_rgb666_fmt_SHIFT 26
#define SPI_DBI_dbi_ctl_1_dbi_rxclk_inv (0x1 << 25)
#define SPI_DBI_dbi_ctl_1_dbi_rxclk_inv_SHIFT 25
#define SPI_DBI_dbi_ctl_1_dbi_clko_mod (0x1 << 24)
#define SPI_DBI_dbi_ctl_1_dbi_clko_mod_SHIFT 24
#define SPI_DBI_dbi_ctl_1_dbi_clko_inv (0x1 << 23)
#define SPI_DBI_dbi_ctl_1_dbi_clko_inv_SHIFT 23
#define SPI_DBI_dbi_ctl_1_dcx_data (0x1 << 22)
#define SPI_DBI_dbi_ctl_1_dcx_data_SHIFT 22
#define SPI_DBI_dbi_ctl_1_rgb16_data_source_select (0x1 << 21)
#define SPI_DBI_dbi_ctl_1_rgb16_data_source_select_SHIFT 21
#define SPI_DBI_dbi_ctl_1_rdat_lsb (0x1 << 20)
#define SPI_DBI_dbi_ctl_1_rdat_lsb_SHIFT 20
#define SPI_DBI_dbi_ctl_1_rcdc (0xff << 8)
#define SPI_DBI_dbi_ctl_1_rcdc_SHIFT 8
#define SPI_DBI_dbi_ctl_1_rdbn 0xff
#define SPI_DBI_dbi_ctl_1_rdbn_SHIFT 0
#define SPI_DBI_dbi_ctl_2 (SPI_DBI + 0x108) // DBI Control Register 2 ()
#define SPI_DBI_dbi_ctl_2_OFFSET 0x108
#define SPI_DBI_dbi_ctl_2_dbi_fifo_drq_en (0x1 << 15)
#define SPI_DBI_dbi_ctl_2_dbi_fifo_drq_en_SHIFT 15
#define SPI_DBI_dbi_ctl_2_dbi_trig_level (0x7f << 8)
#define SPI_DBI_dbi_ctl_2_dbi_trig_level_SHIFT 8
#define SPI_DBI_dbi_ctl_2_dbi_sdq_out_sel (0x1 << 6)
#define SPI_DBI_dbi_ctl_2_dbi_sdq_out_sel_SHIFT 6
#define SPI_DBI_dbi_ctl_2_dbi_dcx_sel (0x1 << 5)
#define SPI_DBI_dbi_ctl_2_dbi_dcx_sel_SHIFT 5
#define SPI_DBI_dbi_ctl_2_dbi_sdi_sel (0x3 << 3)
#define SPI_DBI_dbi_ctl_2_dbi_sdi_sel_SHIFT 3
#define SPI_DBI_dbi_ctl_2_te_dbc_sel (0x1 << 2)
#define SPI_DBI_dbi_ctl_2_te_dbc_sel_SHIFT 2
#define SPI_DBI_dbi_ctl_2_te_trig_sel (0x1 << 1)
#define SPI_DBI_dbi_ctl_2_te_trig_sel_SHIFT 1
#define SPI_DBI_dbi_ctl_2_te_en 0x1
#define SPI_DBI_dbi_ctl_2_te_en_SHIFT 0
#define SPI_DBI_dbi_timer (SPI_DBI + 0x10c) // DBI Timer Control Register ()
#define SPI_DBI_dbi_timer_OFFSET 0x10c
#define SPI_DBI_dbi_timer_dbi_tm_en (0x1 << 31)
#define SPI_DBI_dbi_timer_dbi_tm_en_SHIFT 31
#define SPI_DBI_dbi_timer_dbi_timer_value 0x7fffffff
#define SPI_DBI_dbi_timer_dbi_timer_value_SHIFT 0
#define SPI_DBI_dbi_video_szie (SPI_DBI + 0x110) // DBI Video Size Configuration Register ()
#define SPI_DBI_dbi_video_szie_OFFSET 0x110
#define SPI_DBI_dbi_video_szie_v_size (0x7ff << 16)
#define SPI_DBI_dbi_video_szie_v_size_SHIFT 16
#define SPI_DBI_dbi_video_szie_h_size 0x7ff
#define SPI_DBI_dbi_video_szie_h_size_SHIFT 0
#define SPI_DBI_dbi_int (SPI_DBI + 0x120) // DBI Interrupt Register ()
#define SPI_DBI_dbi_int_OFFSET 0x120
#define SPI_DBI_dbi_int_dbi_fifo_empty_int (0x1 << 14)
#define SPI_DBI_dbi_int_dbi_fifo_empty_int_SHIFT 14
#define SPI_DBI_dbi_int_dbi_fifo_full_int (0x1 << 13)
#define SPI_DBI_dbi_int_dbi_fifo_full_int_SHIFT 13
#define SPI_DBI_dbi_int_timer_int (0x1 << 12)
#define SPI_DBI_dbi_int_timer_int_SHIFT 12
#define SPI_DBI_dbi_int_rd_done_int (0x1 << 11)
#define SPI_DBI_dbi_int_rd_done_int_SHIFT 11
#define SPI_DBI_dbi_int_te_int (0x1 << 10)
#define SPI_DBI_dbi_int_te_int_SHIFT 10
#define SPI_DBI_dbi_int_fram_done_int (0x1 << 9)
#define SPI_DBI_dbi_int_fram_done_int_SHIFT 9
#define SPI_DBI_dbi_int_line_done_int (0x1 << 8)
#define SPI_DBI_dbi_int_line_done_int_SHIFT 8
#define SPI_DBI_dbi_int_dbi_fifo_empty_int_en (0x1 << 6)
#define SPI_DBI_dbi_int_dbi_fifo_empty_int_en_SHIFT 6
#define SPI_DBI_dbi_int_dbi_fifo_full_int_en (0x1 << 5)
#define SPI_DBI_dbi_int_dbi_fifo_full_int_en_SHIFT 5
#define SPI_DBI_dbi_int_timer_int_en (0x1 << 4)
#define SPI_DBI_dbi_int_timer_int_en_SHIFT 4
#define SPI_DBI_dbi_int_rd_done_int_en (0x1 << 3)
#define SPI_DBI_dbi_int_rd_done_int_en_SHIFT 3
#define SPI_DBI_dbi_int_te_int_en (0x1 << 2)
#define SPI_DBI_dbi_int_te_int_en_SHIFT 2
#define SPI_DBI_dbi_int_fram_done_int_en (0x1 << 1)
#define SPI_DBI_dbi_int_fram_done_int_en_SHIFT 1
#define SPI_DBI_dbi_int_line_done_int_en 0x1
#define SPI_DBI_dbi_int_line_done_int_en_SHIFT 0
#define SPI_DBI_dbi_debug_0 (SPI_DBI + 0x124) // DBI BEBUG 0 Register (R only)
#define SPI_DBI_dbi_debug_0_OFFSET 0x124
#define SPI_DBI_dbi_debug_0_dbi_fifo_avail (0x7f << 16)
#define SPI_DBI_dbi_debug_0_dbi_fifo_avail_SHIFT 16
#define SPI_DBI_dbi_debug_0_te_val (0x1 << 12)
#define SPI_DBI_dbi_debug_0_te_val_SHIFT 12
#define SPI_DBI_dbi_debug_0_dbi_rxcs (0xf << 8)
#define SPI_DBI_dbi_debug_0_dbi_rxcs_SHIFT 8
#define SPI_DBI_dbi_debug_0_sh_cs (0xf << 4)
#define SPI_DBI_dbi_debug_0_sh_cs_SHIFT 4
#define SPI_DBI_dbi_debug_0_dbi_txcs (0x3 << 2)
#define SPI_DBI_dbi_debug_0_dbi_txcs_SHIFT 2
#define SPI_DBI_dbi_debug_0_mem_cs 0x3
#define SPI_DBI_dbi_debug_0_mem_cs_SHIFT 0
#define SPI_DBI_dbi_debug_1 (SPI_DBI + 0x128) // DBI BEBUG 1 Register (R only)
#define SPI_DBI_dbi_debug_1_OFFSET 0x128
#define SPI_DBI_dbi_debug_1_lcnt (0x3ff << 16)
#define SPI_DBI_dbi_debug_1_lcnt_SHIFT 16
#define SPI_DBI_dbi_debug_1_ccnt 0xfff
#define SPI_DBI_dbi_debug_1_ccnt_SHIFT 0
#define SPI_DBI_spi_txd (SPI_DBI + 0x200) // SPI TX Data Register\n\nTDATA 31:0: Transmit Data ()
#define SPI_DBI_spi_txd_OFFSET 0x200
#define SPI_DBI_spi_rxd (SPI_DBI + 0x300) // SPI RX Data Register\n\nRDATA 31:0: Receive Data ()
#define SPI_DBI_spi_rxd_OFFSET 0x300

/****************************************************************
 * USB2.0 DRD
 ****************************************************************/
#define USB0 0x04100000

/****************************************************************
 * USB2.0 HOST
 ****************************************************************/
#define USB1 0x04200000

/****************************************************************
 * Gerneral Purpose Input/Output
 ****************************************************************/
#define GPIO 0x02000000
#define GPIO_pb_cfg0 (GPIO + 0x30) // PB Configure Register 0 ()
#define GPIO_pb_cfg0_OFFSET 0x30
#define GPIO_pb_cfg0_pb7_select (0xf << 28)
#define GPIO_pb_cfg0_pb7_select_SHIFT 28
#define GPIO_pb_cfg0_pb6_select (0xf << 24)
#define GPIO_pb_cfg0_pb6_select_SHIFT 24
#define GPIO_pb_cfg0_pb5_select (0xf << 20)
#define GPIO_pb_cfg0_pb5_select_SHIFT 20
#define GPIO_pb_cfg0_pb4_select (0xf << 16)
#define GPIO_pb_cfg0_pb4_select_SHIFT 16
#define GPIO_pb_cfg0_pb3_select (0xf << 12)
#define GPIO_pb_cfg0_pb3_select_SHIFT 12
#define GPIO_pb_cfg0_pb2_select (0xf << 8)
#define GPIO_pb_cfg0_pb2_select_SHIFT 8
#define GPIO_pb_cfg0_pb1_select (0xf << 4)
#define GPIO_pb_cfg0_pb1_select_SHIFT 4
#define GPIO_pb_cfg0_pb0_select 0xf
#define GPIO_pb_cfg0_pb0_select_SHIFT 0
#define GPIO_pb_cfg1 (GPIO + 0x34) // PB Configure Register 1 ()
#define GPIO_pb_cfg1_OFFSET 0x34
#define GPIO_pb_cfg1_pb12_select (0xf << 16)
#define GPIO_pb_cfg1_pb12_select_SHIFT 16
#define GPIO_pb_cfg1_pb11_select (0xf << 12)
#define GPIO_pb_cfg1_pb11_select_SHIFT 12
#define GPIO_pb_cfg1_pb10_select (0xf << 8)
#define GPIO_pb_cfg1_pb10_select_SHIFT 8
#define GPIO_pb_cfg1_pb9_select (0xf << 4)
#define GPIO_pb_cfg1_pb9_select_SHIFT 4
#define GPIO_pb_cfg1_pb8_select 0xf
#define GPIO_pb_cfg1_pb8_select_SHIFT 0
#define GPIO_pb_dat (GPIO + 0x40) // PB Data Register ()
#define GPIO_pb_dat_OFFSET 0x40
#define GPIO_pb_dat_pb_dat 0x1fff
#define GPIO_pb_dat_pb_dat_SHIFT 0
#define GPIO_pb_drv0 (GPIO + 0x44) // PB Multi_Driving Register 0 ()
#define GPIO_pb_drv0_OFFSET 0x44
#define GPIO_pb_drv0_pb0_drv 0x3
#define GPIO_pb_drv0_pb0_drv_SHIFT 0
#define GPIO_pb_drv1 (GPIO + 0x48) // PB Multi_Driving Register 1 ()
#define GPIO_pb_drv1_OFFSET 0x48
#define GPIO_pb_drv1_pb0_drv 0x3
#define GPIO_pb_drv1_pb0_drv_SHIFT 0
#define GPIO_pb_pull0 (GPIO + 0x54) // PB Pull Register 0 ()
#define GPIO_pb_pull0_OFFSET 0x54
#define GPIO_pb_pull0_pc0_pull 0x3
#define GPIO_pb_pull0_pc0_pull_SHIFT 0
#define GPIO_pc_cfg0 (GPIO + 0x60) // PC Configure Register 0 ()
#define GPIO_pc_cfg0_OFFSET 0x60
#define GPIO_pc_cfg0_pc7_select (0xf << 28)
#define GPIO_pc_cfg0_pc7_select_SHIFT 28
#define GPIO_pc_cfg0_pc6_select (0xf << 24)
#define GPIO_pc_cfg0_pc6_select_SHIFT 24
#define GPIO_pc_cfg0_pc5_select (0xf << 20)
#define GPIO_pc_cfg0_pc5_select_SHIFT 20
#define GPIO_pc_cfg0_pc4_select (0xf << 16)
#define GPIO_pc_cfg0_pc4_select_SHIFT 16
#define GPIO_pc_cfg0_pc3_select (0xf << 12)
#define GPIO_pc_cfg0_pc3_select_SHIFT 12
#define GPIO_pc_cfg0_pc2_select (0xf << 8)
#define GPIO_pc_cfg0_pc2_select_SHIFT 8
#define GPIO_pc_cfg0_pc1_select (0xf << 4)
#define GPIO_pc_cfg0_pc1_select_SHIFT 4
#define GPIO_pc_cfg0_pc0_select 0xf
#define GPIO_pc_cfg0_pc0_select_SHIFT 0
#define GPIO_pc_dat (GPIO + 0x70) // PC Data Register ()
#define GPIO_pc_dat_OFFSET 0x70
#define GPIO_pc_dat_pc_dat 0xff
#define GPIO_pc_dat_pc_dat_SHIFT 0
#define GPIO_pc_drv0 (GPIO + 0x74) // PC Multi_Driving Register 0 ()
#define GPIO_pc_drv0_OFFSET 0x74
#define GPIO_pc_drv0_pc0_drv 0x3
#define GPIO_pc_drv0_pc0_drv_SHIFT 0
#define GPIO_pc_pull0 (GPIO + 0x84) // PC Pull Register 0 ()
#define GPIO_pc_pull0_OFFSET 0x84
#define GPIO_pc_pull0_pc0_pull 0x3
#define GPIO_pc_pull0_pc0_pull_SHIFT 0
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
#define GPIO_pd_cfg1 (GPIO + 0x94) // PD Configure Register 1 ()
#define GPIO_pd_cfg1_OFFSET 0x94
#define GPIO_pd_cfg1_pd15_select (0xf << 28)
#define GPIO_pd_cfg1_pd15_select_SHIFT 28
#define GPIO_pd_cfg1_pd14_select (0xf << 24)
#define GPIO_pd_cfg1_pd14_select_SHIFT 24
#define GPIO_pd_cfg1_pd13_select (0xf << 20)
#define GPIO_pd_cfg1_pd13_select_SHIFT 20
#define GPIO_pd_cfg1_pd12_select (0xf << 16)
#define GPIO_pd_cfg1_pd12_select_SHIFT 16
#define GPIO_pd_cfg1_pd11_select (0xf << 12)
#define GPIO_pd_cfg1_pd11_select_SHIFT 12
#define GPIO_pd_cfg1_pd10_select (0xf << 8)
#define GPIO_pd_cfg1_pd10_select_SHIFT 8
#define GPIO_pd_cfg1_pd9_select (0xf << 4)
#define GPIO_pd_cfg1_pd9_select_SHIFT 4
#define GPIO_pd_cfg1_pd8_select 0xf
#define GPIO_pd_cfg1_pd8_select_SHIFT 0
#define GPIO_pd_cfg2 (GPIO + 0x98) // PD Configure Register 2 ()
#define GPIO_pd_cfg2_OFFSET 0x98
#define GPIO_pd_cfg2_pd22_select (0xf << 24)
#define GPIO_pd_cfg2_pd22_select_SHIFT 24
#define GPIO_pd_cfg2_pd21_select (0xf << 20)
#define GPIO_pd_cfg2_pd21_select_SHIFT 20
#define GPIO_pd_cfg2_pd20_select (0xf << 16)
#define GPIO_pd_cfg2_pd20_select_SHIFT 16
#define GPIO_pd_cfg2_pd19_select (0xf << 12)
#define GPIO_pd_cfg2_pd19_select_SHIFT 12
#define GPIO_pd_cfg2_pd18_select (0xf << 8)
#define GPIO_pd_cfg2_pd18_select_SHIFT 8
#define GPIO_pd_cfg2_pd17_select (0xf << 4)
#define GPIO_pd_cfg2_pd17_select_SHIFT 4
#define GPIO_pd_cfg2_pd16_select 0xf
#define GPIO_pd_cfg2_pd16_select_SHIFT 0
#define GPIO_pd_dat (GPIO + 0xa0) // PD Data Register ()
#define GPIO_pd_dat_OFFSET 0xa0
#define GPIO_pd_dat_pd_dat 0x7fffff
#define GPIO_pd_dat_pd_dat_SHIFT 0
#define GPIO_pd_drv0 (GPIO + 0xa4) // PD Multi_Driving Register 0 ()
#define GPIO_pd_drv0_OFFSET 0xa4
#define GPIO_pd_drv0_pd0_drv 0x3
#define GPIO_pd_drv0_pd0_drv_SHIFT 0
#define GPIO_pd_drv1 (GPIO + 0xa8) // PD Multi_Driving Register 1 ()
#define GPIO_pd_drv1_OFFSET 0xa8
#define GPIO_pd_drv1_pd0_drv 0x3
#define GPIO_pd_drv1_pd0_drv_SHIFT 0
#define GPIO_pd_drv2 (GPIO + 0xac) // PD Multi_Driving Register 2 ()
#define GPIO_pd_drv2_OFFSET 0xac
#define GPIO_pd_drv2_pd0_drv 0x3
#define GPIO_pd_drv2_pd0_drv_SHIFT 0
#define GPIO_pd_pull0 (GPIO + 0xb4) // PD Pull Register 0 ()
#define GPIO_pd_pull0_OFFSET 0xb4
#define GPIO_pd_pull0_pd0_pull 0x3
#define GPIO_pd_pull0_pd0_pull_SHIFT 0
#define GPIO_pd_pull1 (GPIO + 0xb8) // PD Pull Register 1 ()
#define GPIO_pd_pull1_OFFSET 0xb8
#define GPIO_pd_pull1_pd0_pull 0x3
#define GPIO_pd_pull1_pd0_pull_SHIFT 0
#define GPIO_pe_cfg0 (GPIO + 0xc0) // PE Configure Register 0 ()
#define GPIO_pe_cfg0_OFFSET 0xc0
#define GPIO_pe_cfg0_pe7_select (0xf << 28)
#define GPIO_pe_cfg0_pe7_select_SHIFT 28
#define GPIO_pe_cfg0_pe6_select (0xf << 24)
#define GPIO_pe_cfg0_pe6_select_SHIFT 24
#define GPIO_pe_cfg0_pe5_select (0xf << 20)
#define GPIO_pe_cfg0_pe5_select_SHIFT 20
#define GPIO_pe_cfg0_pe4_select (0xf << 16)
#define GPIO_pe_cfg0_pe4_select_SHIFT 16
#define GPIO_pe_cfg0_pe3_select (0xf << 12)
#define GPIO_pe_cfg0_pe3_select_SHIFT 12
#define GPIO_pe_cfg0_pe2_select (0xf << 8)
#define GPIO_pe_cfg0_pe2_select_SHIFT 8
#define GPIO_pe_cfg0_pe1_select (0xf << 4)
#define GPIO_pe_cfg0_pe1_select_SHIFT 4
#define GPIO_pe_cfg0_pe0_select 0xf
#define GPIO_pe_cfg0_pe0_select_SHIFT 0
#define GPIO_pe_cfg1 (GPIO + 0xc4) // PE Configure Register 1 ()
#define GPIO_pe_cfg1_OFFSET 0xc4
#define GPIO_pe_cfg1_pe15_select (0xf << 28)
#define GPIO_pe_cfg1_pe15_select_SHIFT 28
#define GPIO_pe_cfg1_pe14_select (0xf << 24)
#define GPIO_pe_cfg1_pe14_select_SHIFT 24
#define GPIO_pe_cfg1_pe13_select (0xf << 20)
#define GPIO_pe_cfg1_pe13_select_SHIFT 20
#define GPIO_pe_cfg1_pe12_select (0xf << 16)
#define GPIO_pe_cfg1_pe12_select_SHIFT 16
#define GPIO_pe_cfg1_pe11_select (0xf << 12)
#define GPIO_pe_cfg1_pe11_select_SHIFT 12
#define GPIO_pe_cfg1_pe10_select (0xf << 8)
#define GPIO_pe_cfg1_pe10_select_SHIFT 8
#define GPIO_pe_cfg1_pe9_select (0xf << 4)
#define GPIO_pe_cfg1_pe9_select_SHIFT 4
#define GPIO_pe_cfg1_pe8_select 0xf
#define GPIO_pe_cfg1_pe8_select_SHIFT 0
#define GPIO_pe_cfg2 (GPIO + 0xc8) // PE Configure Register 2 ()
#define GPIO_pe_cfg2_OFFSET 0xc8
#define GPIO_pe_cfg2_pe17_select (0xf << 4)
#define GPIO_pe_cfg2_pe17_select_SHIFT 4
#define GPIO_pe_cfg2_pe16_select 0xf
#define GPIO_pe_cfg2_pe16_select_SHIFT 0
#define GPIO_pe_dat (GPIO + 0xd0) // PE Data Register ()
#define GPIO_pe_dat_OFFSET 0xd0
#define GPIO_pe_dat_pe_dat 0x3ffff
#define GPIO_pe_dat_pe_dat_SHIFT 0
#define GPIO_pe_drv0 (GPIO + 0xd4) // PE Multi_Driving Register 0 ()
#define GPIO_pe_drv0_OFFSET 0xd4
#define GPIO_pe_drv0_pe0_drv 0x3
#define GPIO_pe_drv0_pe0_drv_SHIFT 0
#define GPIO_pe_drv1 (GPIO + 0xd8) // PE Multi_Driving Register 1 ()
#define GPIO_pe_drv1_OFFSET 0xd8
#define GPIO_pe_drv1_pe0_drv 0x3
#define GPIO_pe_drv1_pe0_drv_SHIFT 0
#define GPIO_pe_drv2 (GPIO + 0xdc) // PE Multi_Driving Register 2 ()
#define GPIO_pe_drv2_OFFSET 0xdc
#define GPIO_pe_drv2_pe0_drv 0x3
#define GPIO_pe_drv2_pe0_drv_SHIFT 0
#define GPIO_pe_pull0 (GPIO + 0xe4) // PE Pull Register 0 ()
#define GPIO_pe_pull0_OFFSET 0xe4
#define GPIO_pe_pull0_pe0_pull 0x3
#define GPIO_pe_pull0_pe0_pull_SHIFT 0
#define GPIO_pe_pull1 (GPIO + 0xe8) // PE Pull Register 1 ()
#define GPIO_pe_pull1_OFFSET 0xe8
#define GPIO_pe_pull1_pe0_pull 0x3
#define GPIO_pe_pull1_pe0_pull_SHIFT 0
#define GPIO_pf_cfg0 (GPIO + 0xf0) // PF Configure Register 0 ()
#define GPIO_pf_cfg0_OFFSET 0xf0
#define GPIO_pf_cfg0_pf6_select (0xf << 24)
#define GPIO_pf_cfg0_pf6_select_SHIFT 24
#define GPIO_pf_cfg0_pf5_select (0xf << 20)
#define GPIO_pf_cfg0_pf5_select_SHIFT 20
#define GPIO_pf_cfg0_pf4_select (0xf << 16)
#define GPIO_pf_cfg0_pf4_select_SHIFT 16
#define GPIO_pf_cfg0_pf3_select (0xf << 12)
#define GPIO_pf_cfg0_pf3_select_SHIFT 12
#define GPIO_pf_cfg0_pf2_select (0xf << 8)
#define GPIO_pf_cfg0_pf2_select_SHIFT 8
#define GPIO_pf_cfg0_pf1_select (0xf << 4)
#define GPIO_pf_cfg0_pf1_select_SHIFT 4
#define GPIO_pf_cfg0_pf0_select 0xf
#define GPIO_pf_cfg0_pf0_select_SHIFT 0
#define GPIO_pf_dat (GPIO + 0x100) // PF Data Register ()
#define GPIO_pf_dat_OFFSET 0x100
#define GPIO_pf_dat_pf_dat 0x7f
#define GPIO_pf_dat_pf_dat_SHIFT 0
#define GPIO_pf_drv0 (GPIO + 0x104) // PF Multi_Driving Register 0 ()
#define GPIO_pf_drv0_OFFSET 0x104
#define GPIO_pf_drv0_pf0_drv 0x3
#define GPIO_pf_drv0_pf0_drv_SHIFT 0
#define GPIO_pf_pull0 (GPIO + 0x114) // PF Pull Register 0 ()
#define GPIO_pf_pull0_OFFSET 0x114
#define GPIO_pf_pull0_pf0_pull 0x3
#define GPIO_pf_pull0_pf0_pull_SHIFT 0
#define GPIO_pg_cfg0 (GPIO + 0x120) // PG Configure Register 0 ()
#define GPIO_pg_cfg0_OFFSET 0x120
#define GPIO_pg_cfg0_pg7_select (0xf << 28)
#define GPIO_pg_cfg0_pg7_select_SHIFT 28
#define GPIO_pg_cfg0_pg6_select (0xf << 24)
#define GPIO_pg_cfg0_pg6_select_SHIFT 24
#define GPIO_pg_cfg0_pg5_select (0xf << 20)
#define GPIO_pg_cfg0_pg5_select_SHIFT 20
#define GPIO_pg_cfg0_pg4_select (0xf << 16)
#define GPIO_pg_cfg0_pg4_select_SHIFT 16
#define GPIO_pg_cfg0_pg3_select (0xf << 12)
#define GPIO_pg_cfg0_pg3_select_SHIFT 12
#define GPIO_pg_cfg0_pg2_select (0xf << 8)
#define GPIO_pg_cfg0_pg2_select_SHIFT 8
#define GPIO_pg_cfg0_pg1_select (0xf << 4)
#define GPIO_pg_cfg0_pg1_select_SHIFT 4
#define GPIO_pg_cfg0_pg0_select 0xf
#define GPIO_pg_cfg0_pg0_select_SHIFT 0
#define GPIO_pg_cfg1 (GPIO + 0x124) // PG Configure Register 1 ()
#define GPIO_pg_cfg1_OFFSET 0x124
#define GPIO_pg_cfg1_pg15_select (0xf << 28)
#define GPIO_pg_cfg1_pg15_select_SHIFT 28
#define GPIO_pg_cfg1_pg14_select (0xf << 24)
#define GPIO_pg_cfg1_pg14_select_SHIFT 24
#define GPIO_pg_cfg1_pg13_select (0xf << 20)
#define GPIO_pg_cfg1_pg13_select_SHIFT 20
#define GPIO_pg_cfg1_pg12_select (0xf << 16)
#define GPIO_pg_cfg1_pg12_select_SHIFT 16
#define GPIO_pg_cfg1_pg11_select (0xf << 12)
#define GPIO_pg_cfg1_pg11_select_SHIFT 12
#define GPIO_pg_cfg1_pg10_select (0xf << 8)
#define GPIO_pg_cfg1_pg10_select_SHIFT 8
#define GPIO_pg_cfg1_pg9_select (0xf << 4)
#define GPIO_pg_cfg1_pg9_select_SHIFT 4
#define GPIO_pg_cfg1_pg8_select 0xf
#define GPIO_pg_cfg1_pg8_select_SHIFT 0
#define GPIO_pg_cfg2 (GPIO + 0x128) // PG Configure Register 2 ()
#define GPIO_pg_cfg2_OFFSET 0x128
#define GPIO_pg_cfg2_pg18_select (0xf << 8)
#define GPIO_pg_cfg2_pg18_select_SHIFT 8
#define GPIO_pg_cfg2_pg17_select (0xf << 4)
#define GPIO_pg_cfg2_pg17_select_SHIFT 4
#define GPIO_pg_cfg2_pg16_select 0xf
#define GPIO_pg_cfg2_pg16_select_SHIFT 0
#define GPIO_pg_dat (GPIO + 0x130) // PG Data Register ()
#define GPIO_pg_dat_OFFSET 0x130
#define GPIO_pg_dat_pg_dat 0x7ffff
#define GPIO_pg_dat_pg_dat_SHIFT 0
#define GPIO_pg_drv0 (GPIO + 0x134) // PG Multi_Driving Register 0 ()
#define GPIO_pg_drv0_OFFSET 0x134
#define GPIO_pg_drv0_pg0_drv 0x3
#define GPIO_pg_drv0_pg0_drv_SHIFT 0
#define GPIO_pg_drv1 (GPIO + 0x138) // PG Multi_Driving Register 1 ()
#define GPIO_pg_drv1_OFFSET 0x138
#define GPIO_pg_drv1_pg0_drv 0x3
#define GPIO_pg_drv1_pg0_drv_SHIFT 0
#define GPIO_pg_drv2 (GPIO + 0x13c) // PG Multi_Driving Register 2 ()
#define GPIO_pg_drv2_OFFSET 0x13c
#define GPIO_pg_drv2_pg0_drv 0x3
#define GPIO_pg_drv2_pg0_drv_SHIFT 0
#define GPIO_pg_pull0 (GPIO + 0x144) // PG Pull Register 0 ()
#define GPIO_pg_pull0_OFFSET 0x144
#define GPIO_pg_pull0_pg0_pull 0x3
#define GPIO_pg_pull0_pg0_pull_SHIFT 0
#define GPIO_pg_pull1 (GPIO + 0x148) // PG Pull Register 1 ()
#define GPIO_pg_pull1_OFFSET 0x148
#define GPIO_pg_pull1_pg0_pull 0x3
#define GPIO_pg_pull1_pg0_pull_SHIFT 0
#define GPIO_pb_eint_cfg0 (GPIO + 0x220) // PB External Interrupt Configure Register 0 ()
#define GPIO_pb_eint_cfg0_OFFSET 0x220
#define GPIO_pb_eint_cfg0_eint0_cfg 0xf
#define GPIO_pb_eint_cfg0_eint0_cfg_SHIFT 0
#define GPIO_pb_eint_cfg1 (GPIO + 0x224) // PB External Interrupt Configure Register 1 ()
#define GPIO_pb_eint_cfg1_OFFSET 0x224
#define GPIO_pb_eint_cfg1_eint0_cfg 0xf
#define GPIO_pb_eint_cfg1_eint0_cfg_SHIFT 0
#define GPIO_pb_eint_ctl (GPIO + 0x230) // PB External Interrupt Control Register ()
#define GPIO_pb_eint_ctl_OFFSET 0x230
#define GPIO_pb_eint_ctl_eint0_ctl 0x1
#define GPIO_pb_eint_ctl_eint0_ctl_SHIFT 0
#define GPIO_pb_eint_status (GPIO + 0x234) // PB External Interrupt Status Register ()
#define GPIO_pb_eint_status_OFFSET 0x234
#define GPIO_pb_eint_status_eint0_status 0x1
#define GPIO_pb_eint_status_eint0_status_SHIFT 0
#define GPIO_pb_eint_deb (GPIO + 0x238) // PB External Interrupt Debounce Register ()
#define GPIO_pb_eint_deb_OFFSET 0x238
#define GPIO_pb_eint_deb_deb_clk_pre_scale (0x7 << 4)
#define GPIO_pb_eint_deb_deb_clk_pre_scale_SHIFT 4
#define GPIO_pb_eint_deb_pio_int_clk_select 0x1
#define GPIO_pb_eint_deb_pio_int_clk_select_SHIFT 0
#define GPIO_pc_eint_cfg0 (GPIO + 0x240) // PC External Interrupt Configure Register 0 ()
#define GPIO_pc_eint_cfg0_OFFSET 0x240
#define GPIO_pc_eint_cfg0_eint0_cfg 0xf
#define GPIO_pc_eint_cfg0_eint0_cfg_SHIFT 0
#define GPIO_pc_eint_ctl (GPIO + 0x250) // PC External Interrupt Control Register ()
#define GPIO_pc_eint_ctl_OFFSET 0x250
#define GPIO_pc_eint_ctl_eint0_ctl 0x1
#define GPIO_pc_eint_ctl_eint0_ctl_SHIFT 0
#define GPIO_pc_eint_status (GPIO + 0x254) // PC External Interrupt Status Register ()
#define GPIO_pc_eint_status_OFFSET 0x254
#define GPIO_pc_eint_status_eint0_status 0x1
#define GPIO_pc_eint_status_eint0_status_SHIFT 0
#define GPIO_pc_eint_deb (GPIO + 0x258) // PC External Interrupt Debounce Register ()
#define GPIO_pc_eint_deb_OFFSET 0x258
#define GPIO_pc_eint_deb_deb_clk_pre_scale (0x7 << 4)
#define GPIO_pc_eint_deb_deb_clk_pre_scale_SHIFT 4
#define GPIO_pc_eint_deb_pio_int_clk_select 0x1
#define GPIO_pc_eint_deb_pio_int_clk_select_SHIFT 0
#define GPIO_pd_eint_cfg0 (GPIO + 0x260) // PD External Interrupt Configure Register 0 ()
#define GPIO_pd_eint_cfg0_OFFSET 0x260
#define GPIO_pd_eint_cfg0_eint0_cfg 0xf
#define GPIO_pd_eint_cfg0_eint0_cfg_SHIFT 0
#define GPIO_pd_eint_cfg1 (GPIO + 0x264) // PD External Interrupt Configure Register 1 ()
#define GPIO_pd_eint_cfg1_OFFSET 0x264
#define GPIO_pd_eint_cfg1_eint0_cfg 0xf
#define GPIO_pd_eint_cfg1_eint0_cfg_SHIFT 0
#define GPIO_pd_eint_cfg2 (GPIO + 0x268) // PD External Interrupt Configure Register 2 ()
#define GPIO_pd_eint_cfg2_OFFSET 0x268
#define GPIO_pd_eint_cfg2_eint0_cfg 0xf
#define GPIO_pd_eint_cfg2_eint0_cfg_SHIFT 0
#define GPIO_pd_eint_ctl (GPIO + 0x270) // PD External Interrupt Control Register ()
#define GPIO_pd_eint_ctl_OFFSET 0x270
#define GPIO_pd_eint_ctl_eint0_ctl 0x1
#define GPIO_pd_eint_ctl_eint0_ctl_SHIFT 0
#define GPIO_pd_eint_status (GPIO + 0x274) // PD External Interrupt Status Register ()
#define GPIO_pd_eint_status_OFFSET 0x274
#define GPIO_pd_eint_status_eint0_status 0x1
#define GPIO_pd_eint_status_eint0_status_SHIFT 0
#define GPIO_pd_eint_deb (GPIO + 0x278) // PD External Interrupt Debounce Register ()
#define GPIO_pd_eint_deb_OFFSET 0x278
#define GPIO_pd_eint_deb_deb_clk_pre_scale (0x7 << 4)
#define GPIO_pd_eint_deb_deb_clk_pre_scale_SHIFT 4
#define GPIO_pd_eint_deb_pio_int_clk_select 0x1
#define GPIO_pd_eint_deb_pio_int_clk_select_SHIFT 0
#define GPIO_pe_eint_cfg0 (GPIO + 0x280) // PE External Interrupt Configure Register 0 ()
#define GPIO_pe_eint_cfg0_OFFSET 0x280
#define GPIO_pe_eint_cfg0_eint0_cfg 0xf
#define GPIO_pe_eint_cfg0_eint0_cfg_SHIFT 0
#define GPIO_pe_eint_cfg1 (GPIO + 0x284) // PE External Interrupt Configure Register 1 ()
#define GPIO_pe_eint_cfg1_OFFSET 0x284
#define GPIO_pe_eint_cfg1_eint0_cfg 0xf
#define GPIO_pe_eint_cfg1_eint0_cfg_SHIFT 0
#define GPIO_pe_eint_cfg2 (GPIO + 0x288) // PE External Interrupt Configure Register 2 ()
#define GPIO_pe_eint_cfg2_OFFSET 0x288
#define GPIO_pe_eint_cfg2_eint0_cfg 0xf
#define GPIO_pe_eint_cfg2_eint0_cfg_SHIFT 0
#define GPIO_pe_eint_ctl (GPIO + 0x290) // PE External Interrupt Control Register ()
#define GPIO_pe_eint_ctl_OFFSET 0x290
#define GPIO_pe_eint_ctl_eint0_ctl 0x1
#define GPIO_pe_eint_ctl_eint0_ctl_SHIFT 0
#define GPIO_pe_eint_status (GPIO + 0x294) // PE External Interrupt Status Register ()
#define GPIO_pe_eint_status_OFFSET 0x294
#define GPIO_pe_eint_status_eint0_status 0x1
#define GPIO_pe_eint_status_eint0_status_SHIFT 0
#define GPIO_pe_eint_deb (GPIO + 0x298) // PE External Interrupt Debounce Register ()
#define GPIO_pe_eint_deb_OFFSET 0x298
#define GPIO_pe_eint_deb_deb_clk_pre_scale (0x7 << 4)
#define GPIO_pe_eint_deb_deb_clk_pre_scale_SHIFT 4
#define GPIO_pe_eint_deb_pio_int_clk_select 0x1
#define GPIO_pe_eint_deb_pio_int_clk_select_SHIFT 0
#define GPIO_pf_eint_cfg0 (GPIO + 0x2a0) // PF External Interrupt Configure Register 0 ()
#define GPIO_pf_eint_cfg0_OFFSET 0x2a0
#define GPIO_pf_eint_cfg0_eint0_cfg 0xf
#define GPIO_pf_eint_cfg0_eint0_cfg_SHIFT 0
#define GPIO_pf_eint_ctl (GPIO + 0x2b0) // PF External Interrupt Control Register ()
#define GPIO_pf_eint_ctl_OFFSET 0x2b0
#define GPIO_pf_eint_ctl_eint0_ctl 0x1
#define GPIO_pf_eint_ctl_eint0_ctl_SHIFT 0
#define GPIO_pf_eint_status (GPIO + 0x2b4) // PF External Interrupt Status Register ()
#define GPIO_pf_eint_status_OFFSET 0x2b4
#define GPIO_pf_eint_status_eint0_status 0x1
#define GPIO_pf_eint_status_eint0_status_SHIFT 0
#define GPIO_pf_eint_deb (GPIO + 0x2b8) // PF External Interrupt Debounce Register ()
#define GPIO_pf_eint_deb_OFFSET 0x2b8
#define GPIO_pf_eint_deb_deb_clk_pre_scale (0x7 << 4)
#define GPIO_pf_eint_deb_deb_clk_pre_scale_SHIFT 4
#define GPIO_pf_eint_deb_pio_int_clk_select 0x1
#define GPIO_pf_eint_deb_pio_int_clk_select_SHIFT 0
#define GPIO_pg_eint_cfg0 (GPIO + 0x2c0) // PG External Interrupt Configure Register 0 ()
#define GPIO_pg_eint_cfg0_OFFSET 0x2c0
#define GPIO_pg_eint_cfg0_eint0_cfg 0xf
#define GPIO_pg_eint_cfg0_eint0_cfg_SHIFT 0
#define GPIO_pg_eint_cfg1 (GPIO + 0x2c4) // PG External Interrupt Configure Register 1 ()
#define GPIO_pg_eint_cfg1_OFFSET 0x2c4
#define GPIO_pg_eint_cfg1_eint0_cfg 0xf
#define GPIO_pg_eint_cfg1_eint0_cfg_SHIFT 0
#define GPIO_pg_eint_cfg2 (GPIO + 0x2c8) // PG External Interrupt Configure Register 2 ()
#define GPIO_pg_eint_cfg2_OFFSET 0x2c8
#define GPIO_pg_eint_cfg2_eint0_cfg 0xf
#define GPIO_pg_eint_cfg2_eint0_cfg_SHIFT 0
#define GPIO_pg_eint_ctl (GPIO + 0x2d0) // PG External Interrupt Control Register ()
#define GPIO_pg_eint_ctl_OFFSET 0x2d0
#define GPIO_pg_eint_ctl_eint0_ctl 0x1
#define GPIO_pg_eint_ctl_eint0_ctl_SHIFT 0
#define GPIO_pg_eint_status (GPIO + 0x2d4) // PG External Interrupt Status Register ()
#define GPIO_pg_eint_status_OFFSET 0x2d4
#define GPIO_pg_eint_status_eint0_status 0x1
#define GPIO_pg_eint_status_eint0_status_SHIFT 0
#define GPIO_pg_eint_deb (GPIO + 0x2d8) // PG External Interrupt Debounce Register ()
#define GPIO_pg_eint_deb_OFFSET 0x2d8
#define GPIO_pg_eint_deb_deb_clk_pre_scale (0x7 << 4)
#define GPIO_pg_eint_deb_deb_clk_pre_scale_SHIFT 4
#define GPIO_pg_eint_deb_pio_int_clk_select 0x1
#define GPIO_pg_eint_deb_pio_int_clk_select_SHIFT 0
#define GPIO_pio_pow_mod_sel (GPIO + 0x340) // PIO Group Withstand Voltage Mode Select Register ()
#define GPIO_pio_pow_mod_sel_OFFSET 0x340
#define GPIO_pio_pow_mod_sel_vcc_io_pwr_mod_sel (0x1 << 12)
#define GPIO_pio_pow_mod_sel_vcc_io_pwr_mod_sel_SHIFT 12
#define GPIO_pio_pow_mod_sel_p0_pwr_mod_sel (0x1 << 2)
#define GPIO_pio_pow_mod_sel_p0_pwr_mod_sel_SHIFT 2
#define GPIO_pio_pow_ms_ctl (GPIO + 0x344) // PIO Group Withstand Voltage Mode Select Control Register ()
#define GPIO_pio_pow_ms_ctl_OFFSET 0x344
#define GPIO_pio_pow_ms_ctl_vccio_ws_vol_mod_sel (0x1 << 12)
#define GPIO_pio_pow_ms_ctl_vccio_ws_vol_mod_sel_SHIFT 12
#define GPIO_pio_pow_ms_ctl_vcc_p0_ws_vol_mod_sel (0x1 << 2)
#define GPIO_pio_pow_ms_ctl_vcc_p0_ws_vol_mod_sel_SHIFT 2
#define GPIO_pio_pow_val (GPIO + 0x348) // PIO Group Power Value Register (R only)
#define GPIO_pio_pow_val_OFFSET 0x348
#define GPIO_pio_pow_val_vccio_pws_val (0x1 << 12)
#define GPIO_pio_pow_val_vccio_pws_val_SHIFT 12
#define GPIO_pio_pow_val_p0_pwr_val (0x1 << 2)
#define GPIO_pio_pow_val_p0_pwr_val_SHIFT 2
#define GPIO_pio_pow_vol_sel_ctl (GPIO + 0x350) // PIO Group Power Voltage Select Control Register ()
#define GPIO_pio_pow_vol_sel_ctl_OFFSET 0x350
#define GPIO_pio_pow_vol_sel_ctl_vcc_pf_pwr_vol_sel 0x1
#define GPIO_pio_pow_vol_sel_ctl_vcc_pf_pwr_vol_sel_SHIFT 0

/****************************************************************
 * General Purpose ADC
 ****************************************************************/
#define GPADC 0x02009000
#define GPADC_gp_sr_con (GPADC + 0x0) // GPADC Sample Rate Configure Register ()
#define GPADC_gp_sr_con_OFFSET 0x0
#define GPADC_gp_sr_con_RESET 0x01DF002F
#define GPADC_gp_sr_con_fs_div (0xffff << 16)
#define GPADC_gp_sr_con_fs_div_SHIFT 16
#define GPADC_gp_sr_con_tacq 0xffff
#define GPADC_gp_sr_con_tacq_SHIFT 0
#define GPADC_gp_ctrl (GPADC + 0x4) // GPADC Control Register ()
#define GPADC_gp_ctrl_OFFSET 0x4
#define GPADC_gp_ctrl_RESET 0x00800000
#define GPADC_gp_ctrl_adc_first_dly (0xff << 24)
#define GPADC_gp_ctrl_adc_first_dly_SHIFT 24
#define GPADC_gp_ctrl_adc_autocali_en (0x1 << 23)
#define GPADC_gp_ctrl_adc_autocali_en_SHIFT 23
#define GPADC_gp_ctrl_adc_op_bias (0x3 << 20)
#define GPADC_gp_ctrl_adc_op_bias_SHIFT 20
#define GPADC_gp_ctrl_gpadc_work_mode (0x3 << 18)
#define GPADC_gp_ctrl_gpadc_work_mode_SHIFT 18
#define GPADC_gp_ctrl_adc_cali_en (0x1 << 17)
#define GPADC_gp_ctrl_adc_cali_en_SHIFT 17
#define GPADC_gp_ctrl_adc_en (0x1 << 16)
#define GPADC_gp_ctrl_adc_en_SHIFT 16
#define GPADC_gp_cs_en (GPADC + 0x8) // GPADC Compare and Select Enable Register ()
#define GPADC_gp_cs_en_OFFSET 0x8
#define GPADC_gp_cs_en_RESET 0x00000000
#define GPADC_gp_cs_en_adc_ch0_cmp_en (0x1 << 16)
#define GPADC_gp_cs_en_adc_ch0_cmp_en_SHIFT 16
#define GPADC_gp_cs_en_adc_ch0_select 0x1
#define GPADC_gp_cs_en_adc_ch0_select_SHIFT 0
#define GPADC_gp_fifo_intc (GPADC + 0xc) // GPADC FIFO Interrupt Control Register ()
#define GPADC_gp_fifo_intc_OFFSET 0xc
#define GPADC_gp_fifo_intc_RESET 0x00001F00
#define GPADC_gp_fifo_intc_fifo_data_drq_en (0x1 << 18)
#define GPADC_gp_fifo_intc_fifo_data_drq_en_SHIFT 18
#define GPADC_gp_fifo_intc_fifo_overrun_irq_en (0x1 << 17)
#define GPADC_gp_fifo_intc_fifo_overrun_irq_en_SHIFT 17
#define GPADC_gp_fifo_intc_fifo_data_irq_en (0x1 << 16)
#define GPADC_gp_fifo_intc_fifo_data_irq_en_SHIFT 16
#define GPADC_gp_fifo_intc_fifo_trig_level (0x3f << 8)
#define GPADC_gp_fifo_intc_fifo_trig_level_SHIFT 8
#define GPADC_gp_fifo_intc_fifo_flush (0x1 << 4)
#define GPADC_gp_fifo_intc_fifo_flush_SHIFT 4
#define GPADC_gp_fifo_ints (GPADC + 0x10) // GPADC FIFO Interrupt Status Register ()
#define GPADC_gp_fifo_ints_OFFSET 0x10
#define GPADC_gp_fifo_ints_RESET 0x00000000
#define GPADC_gp_fifo_ints_fifo_overrun_pending (0x1 << 17)
#define GPADC_gp_fifo_ints_fifo_overrun_pending_SHIFT 17
#define GPADC_gp_fifo_ints_fifo_data_pending (0x1 << 16)
#define GPADC_gp_fifo_ints_fifo_data_pending_SHIFT 16
#define GPADC_gp_fifo_ints_rxa_cnt (0x3f << 8)
#define GPADC_gp_fifo_ints_rxa_cnt_SHIFT 8
#define GPADC_gp_fifo_data (GPADC + 0x14) // GPADC FIFO Data Register ()
#define GPADC_gp_fifo_data_OFFSET 0x14
#define GPADC_gp_fifo_data_RESET 0x00000000
#define GPADC_gp_fifo_data_gp_fifo_data 0xfff
#define GPADC_gp_fifo_data_gp_fifo_data_SHIFT 0
#define GPADC_gp_cdata (GPADC + 0x18) // GPADC Calibration Data Register ()
#define GPADC_gp_cdata_OFFSET 0x18
#define GPADC_gp_cdata_RESET 0x00000000
#define GPADC_gp_cdata_gp_cdata 0xfff
#define GPADC_gp_cdata_gp_cdata_SHIFT 0
#define GPADC_gp_datal_intc (GPADC + 0x20) // GPADC Data Low Interrupt Configure Register ()
#define GPADC_gp_datal_intc_OFFSET 0x20
#define GPADC_gp_datal_intc_RESET 0x00000000
#define GPADC_gp_datal_intc_ch0_low_irq_en 0x1
#define GPADC_gp_datal_intc_ch0_low_irq_en_SHIFT 0
#define GPADC_gp_datah_intc (GPADC + 0x24) // GPADC Data High Interrupt Configure Register ()
#define GPADC_gp_datah_intc_OFFSET 0x24
#define GPADC_gp_datah_intc_RESET 0x00000000
#define GPADC_gp_datah_intc_ch0_hig_irq_en 0x1
#define GPADC_gp_datah_intc_ch0_hig_irq_en_SHIFT 0
#define GPADC_gp_data_intc (GPADC + 0x28) // GPADC Data Interrupt Configure Register ()
#define GPADC_gp_data_intc_OFFSET 0x28
#define GPADC_gp_data_intc_RESET 0x00000000
#define GPADC_gp_data_intc_ch0_data_irq_en 0x1
#define GPADC_gp_data_intc_ch0_data_irq_en_SHIFT 0
#define GPADC_gp_datal_ints (GPADC + 0x30) // GPADC Data Low Interrupt Status Register ()
#define GPADC_gp_datal_ints_OFFSET 0x30
#define GPADC_gp_datal_ints_RESET 0x00000000
#define GPADC_gp_datal_ints_ch0_low_pengding 0x1
#define GPADC_gp_datal_ints_ch0_low_pengding_SHIFT 0
#define GPADC_gp_datah_ints (GPADC + 0x34) // GPADC Data High Interrupt Status Register ()
#define GPADC_gp_datah_ints_OFFSET 0x34
#define GPADC_gp_datah_ints_RESET 0x00000000
#define GPADC_gp_datah_ints_ch0_hig_pengding 0x1
#define GPADC_gp_datah_ints_ch0_hig_pengding_SHIFT 0
#define GPADC_gp_data_ints (GPADC + 0x38) // GPADC Data Interrupt Status Register ()
#define GPADC_gp_data_ints_OFFSET 0x38
#define GPADC_gp_data_ints_RESET 0x00000000
#define GPADC_gp_data_ints_ch0_data_pengding 0x1
#define GPADC_gp_data_ints_ch0_data_pengding_SHIFT 0
#define GPADC_gp_ch0_cmp_data (GPADC + 0x40) // GPADC CH0 Compare Data Register ()
#define GPADC_gp_ch0_cmp_data_OFFSET 0x40
#define GPADC_gp_ch0_cmp_data_RESET 0x0BFF0400
#define GPADC_gp_ch0_cmp_data_ch0_cmp_hig_data (0xfff << 16)
#define GPADC_gp_ch0_cmp_data_ch0_cmp_hig_data_SHIFT 16
#define GPADC_gp_ch0_cmp_data_ch0_cmp_low_data 0xfff
#define GPADC_gp_ch0_cmp_data_ch0_cmp_low_data_SHIFT 0
#define GPADC_gp_ch1_cmp_data (GPADC + 0x44) // GPADC CH1 Compare Data Register ()
#define GPADC_gp_ch1_cmp_data_OFFSET 0x44
#define GPADC_gp_ch1_cmp_data_RESET 0x0BFF0400
#define GPADC_gp_ch1_cmp_data_ch1_cmp_hig_data (0xfff << 16)
#define GPADC_gp_ch1_cmp_data_ch1_cmp_hig_data_SHIFT 16
#define GPADC_gp_ch1_cmp_data_ch1_cmp_low_data 0xfff
#define GPADC_gp_ch1_cmp_data_ch1_cmp_low_data_SHIFT 0
#define GPADC_gp_ch0_data (GPADC + 0x80) // GPADC CH0 Data Register ()
#define GPADC_gp_ch0_data_OFFSET 0x80
#define GPADC_gp_ch0_data_RESET 0x00000000
#define GPADC_gp_ch0_data_gp_ch0_data 0xfff
#define GPADC_gp_ch0_data_gp_ch0_data_SHIFT 0
#define GPADC_gp_ch1_data (GPADC + 0x84) // GPADC CH1 Data Register ()
#define GPADC_gp_ch1_data_OFFSET 0x84
#define GPADC_gp_ch1_data_RESET 0x00000000
#define GPADC_gp_ch1_data_gp_ch1_data 0xfff
#define GPADC_gp_ch1_data_gp_ch1_data_SHIFT 0

/****************************************************************
 * Touch Panel ADC
 ****************************************************************/
#define TPADC 0x02009c00
#define TPADC_tp_ctrl0 (TPADC + 0x0) // TP Control Register 0 ()
#define TPADC_tp_ctrl0_OFFSET 0x0
#define TPADC_tp_ctrl0_adc_first_dly (0xff << 24)
#define TPADC_tp_ctrl0_adc_first_dly_SHIFT 24
#define TPADC_tp_ctrl0_adc_first_dly_mode (0x1 << 23)
#define TPADC_tp_ctrl0_adc_first_dly_mode_SHIFT 23
#define TPADC_tp_ctrl0_adc_clk_divider (0x3 << 20)
#define TPADC_tp_ctrl0_adc_clk_divider_SHIFT 20
#define TPADC_tp_ctrl0_fs_div (0xf << 16)
#define TPADC_tp_ctrl0_fs_div_SHIFT 16
#define TPADC_tp_ctrl0_tacq 0xffff
#define TPADC_tp_ctrl0_tacq_SHIFT 0
#define TPADC_tp_ctrl1 (TPADC + 0x4) // TP Control Register 1 ()
#define TPADC_tp_ctrl1_OFFSET 0x4
#define TPADC_tp_ctrl1_stylus_up_debounce (0xff << 12)
#define TPADC_tp_ctrl1_stylus_up_debounce_SHIFT 12
#define TPADC_tp_ctrl1_stylus_up_debounce_en (0x1 << 9)
#define TPADC_tp_ctrl1_stylus_up_debounce_en_SHIFT 9
#define TPADC_tp_ctrl1_chopper_en (0x1 << 8)
#define TPADC_tp_ctrl1_chopper_en_SHIFT 8
#define TPADC_tp_ctrl1_touch_pan_cali_en (0x1 << 7)
#define TPADC_tp_ctrl1_touch_pan_cali_en_SHIFT 7
#define TPADC_tp_ctrl1_tp_dual_en (0x1 << 6)
#define TPADC_tp_ctrl1_tp_dual_en_SHIFT 6
#define TPADC_tp_ctrl1_tp_en (0x1 << 5)
#define TPADC_tp_ctrl1_tp_en_SHIFT 5
#define TPADC_tp_ctrl1_tp_mode_select (0x1 << 4)
#define TPADC_tp_ctrl1_tp_mode_select_SHIFT 4
#define TPADC_tp_ctrl1_adc_chan0_select 0x1
#define TPADC_tp_ctrl1_adc_chan0_select_SHIFT 0
#define TPADC_tp_ctrl2 (TPADC + 0x8) // TP Control Register 2 ()
#define TPADC_tp_ctrl2_OFFSET 0x8
#define TPADC_tp_ctrl2_tp_sensitive_adjust (0xf << 28)
#define TPADC_tp_ctrl2_tp_sensitive_adjust_SHIFT 28
#define TPADC_tp_ctrl2_tp_fifo_mode_select (0x3 << 26)
#define TPADC_tp_ctrl2_tp_fifo_mode_select_SHIFT 26
#define TPADC_tp_ctrl2_pre_mea_en (0x1 << 24)
#define TPADC_tp_ctrl2_pre_mea_en_SHIFT 24
#define TPADC_tp_ctrl2_pre_mea_thre_cnt 0xffffff
#define TPADC_tp_ctrl2_pre_mea_thre_cnt_SHIFT 0
#define TPADC_tp_ctrl3 (TPADC + 0xc) // TP Control Register 3 ()
#define TPADC_tp_ctrl3_OFFSET 0xc
#define TPADC_tp_ctrl3_filter_en (0x1 << 2)
#define TPADC_tp_ctrl3_filter_en_SHIFT 2
#define TPADC_tp_ctrl3_filter_type 0x3
#define TPADC_tp_ctrl3_filter_type_SHIFT 0
#define TPADC_tp_int_fifo_ctrl (TPADC + 0x10) // TP Interrupt FIFO Control Register ()
#define TPADC_tp_int_fifo_ctrl_OFFSET 0x10
#define TPADC_tp_int_fifo_ctrl_tp_overrun_irq_en (0x1 << 17)
#define TPADC_tp_int_fifo_ctrl_tp_overrun_irq_en_SHIFT 17
#define TPADC_tp_int_fifo_ctrl_tp_data_irq_en (0x1 << 16)
#define TPADC_tp_int_fifo_ctrl_tp_data_irq_en_SHIFT 16
#define TPADC_tp_int_fifo_ctrl_tp_data_xy_change (0x1 << 13)
#define TPADC_tp_int_fifo_ctrl_tp_data_xy_change_SHIFT 13
#define TPADC_tp_int_fifo_ctrl_tp_fifo_trig_level (0x1f << 8)
#define TPADC_tp_int_fifo_ctrl_tp_fifo_trig_level_SHIFT 8
#define TPADC_tp_int_fifo_ctrl_tp_data_erq_en (0x1 << 7)
#define TPADC_tp_int_fifo_ctrl_tp_data_erq_en_SHIFT 7
#define TPADC_tp_int_fifo_ctrl_tp_fifo_flush (0x1 << 4)
#define TPADC_tp_int_fifo_ctrl_tp_fifo_flush_SHIFT 4
#define TPADC_tp_int_fifo_ctrl_tp_up_irq_en (0x1 << 1)
#define TPADC_tp_int_fifo_ctrl_tp_up_irq_en_SHIFT 1
#define TPADC_tp_int_fifo_ctrl_tp_down_irq_en 0x1
#define TPADC_tp_int_fifo_ctrl_tp_down_irq_en_SHIFT 0
#define TPADC_tp_int_fifo_stat (TPADC + 0x14) // TP Interrupt FIFO Status Register ()
#define TPADC_tp_int_fifo_stat_OFFSET 0x14
#define TPADC_tp_int_fifo_stat_fifo_overrun_pending (0x1 << 17)
#define TPADC_tp_int_fifo_stat_fifo_overrun_pending_SHIFT 17
#define TPADC_tp_int_fifo_stat_fifo_data_pending (0x1 << 16)
#define TPADC_tp_int_fifo_stat_fifo_data_pending_SHIFT 16
#define TPADC_tp_int_fifo_stat_rxa_cnt (0x3f << 8)
#define TPADC_tp_int_fifo_stat_rxa_cnt_SHIFT 8
#define TPADC_tp_int_fifo_stat_tp_idle_flg (0x1 << 2)
#define TPADC_tp_int_fifo_stat_tp_idle_flg_SHIFT 2
#define TPADC_tp_int_fifo_stat_tp_up_pending (0x1 << 1)
#define TPADC_tp_int_fifo_stat_tp_up_pending_SHIFT 1
#define TPADC_tp_int_fifo_stat_tp_down_pending 0x1
#define TPADC_tp_int_fifo_stat_tp_down_pending_SHIFT 0
#define TPADC_tp_cali_data (TPADC + 0x1c) // TP Calibration Data Register ()
#define TPADC_tp_cali_data_OFFSET 0x1c
#define TPADC_tp_cali_data_tp_cdat 0xfff
#define TPADC_tp_cali_data_tp_cdat_SHIFT 0
#define TPADC_tp_data (TPADC + 0x24) // TP Data Register (R only)
#define TPADC_tp_data_OFFSET 0x24
#define TPADC_tp_data_tp_data 0xfff
#define TPADC_tp_data_tp_data_SHIFT 0

/****************************************************************
 * Low Rate ADC
 ****************************************************************/
#define LRADC 0x02009800
#define LRADC_lradc_ctrl (LRADC + 0x0) // LRADC Control Register ()
#define LRADC_lradc_ctrl_OFFSET 0x0
#define LRADC_lradc_ctrl_first_convert_dly (0xff << 24)
#define LRADC_lradc_ctrl_first_convert_dly_SHIFT 24
#define LRADC_lradc_ctrl_continue_time_select (0xf << 16)
#define LRADC_lradc_ctrl_continue_time_select_SHIFT 16
#define LRADC_lradc_ctrl_key_mode_select (0x3 << 12)
#define LRADC_lradc_ctrl_key_mode_select_SHIFT 12
#define LRADC_lradc_ctrl_levela_b_cnt (0xf << 8)
#define LRADC_lradc_ctrl_levela_b_cnt_SHIFT 8
#define LRADC_lradc_ctrl_lradc_hold_key_en (0x1 << 7)
#define LRADC_lradc_ctrl_lradc_hold_key_en_SHIFT 7
#define LRADC_lradc_ctrl_lradc_channel_en (0x1 << 6)
#define LRADC_lradc_ctrl_lradc_channel_en_SHIFT 6
#define LRADC_lradc_ctrl_levelb_vol (0x3 << 4)
#define LRADC_lradc_ctrl_levelb_vol_SHIFT 4
#define LRADC_lradc_ctrl_lradc_sample_rate (0x3 << 2)
#define LRADC_lradc_ctrl_lradc_sample_rate_SHIFT 2
#define LRADC_lradc_ctrl_lradc_en 0x1
#define LRADC_lradc_ctrl_lradc_en_SHIFT 0
#define LRADC_lradc_intc (LRADC + 0x4) // LRADC Interrupt Control Register ()
#define LRADC_lradc_intc_OFFSET 0x4
#define LRADC_lradc_intc_adc0_keyup_irq_en (0x1 << 4)
#define LRADC_lradc_intc_adc0_keyup_irq_en_SHIFT 4
#define LRADC_lradc_intc_adc0_alrdy_hold_irq_en (0x1 << 3)
#define LRADC_lradc_intc_adc0_alrdy_hold_irq_en_SHIFT 3
#define LRADC_lradc_intc_adc0_hold_irq_en (0x1 << 2)
#define LRADC_lradc_intc_adc0_hold_irq_en_SHIFT 2
#define LRADC_lradc_intc_adc0_keydown_irq_en (0x1 << 1)
#define LRADC_lradc_intc_adc0_keydown_irq_en_SHIFT 1
#define LRADC_lradc_intc_adc0_data_irq_en 0x1
#define LRADC_lradc_intc_adc0_data_irq_en_SHIFT 0
#define LRADC_lradc_ints (LRADC + 0x8) // LRADC Interrupt Status Register ()
#define LRADC_lradc_ints_OFFSET 0x8
#define LRADC_lradc_ints_adc0_keyup_pending (0x1 << 4)
#define LRADC_lradc_ints_adc0_keyup_pending_SHIFT 4
#define LRADC_lradc_ints_adc0_alrdy_hold_pending (0x1 << 3)
#define LRADC_lradc_ints_adc0_alrdy_hold_pending_SHIFT 3
#define LRADC_lradc_ints_adc0_hold_pending (0x1 << 2)
#define LRADC_lradc_ints_adc0_hold_pending_SHIFT 2
#define LRADC_lradc_ints_adc0_keydown_pending (0x1 << 1)
#define LRADC_lradc_ints_adc0_keydown_pending_SHIFT 1
#define LRADC_lradc_ints_adc0_data_pending 0x1
#define LRADC_lradc_ints_adc0_data_pending_SHIFT 0
#define LRADC_lradc_data (LRADC + 0xc) // LRADC Data Register (R only)
#define LRADC_lradc_data_OFFSET 0xc
#define LRADC_lradc_data_lradc_data 0x3f
#define LRADC_lradc_data_lradc_data_SHIFT 0

/****************************************************************
 * Pulse Width Modulation
 ****************************************************************/
#define PWM 0x02000c00
#define PWM_pier (PWM + 0x0) // PWM IRQ Enable Register ()
#define PWM_pier_OFFSET 0x0
#define PWM_pier_RESET 0x00000000
#define PWM_pier_pgie0 (0x1 << 16)
#define PWM_pier_pgie0_SHIFT 16
#define PWM_pier_pcie0 0x1
#define PWM_pier_pcie0_SHIFT 0
#define PWM_pisr (PWM + 0x4) // PWM IRQ Status Register ()
#define PWM_pisr_OFFSET 0x4
#define PWM_pisr_RESET 0x00000000
#define PWM_pisr_pgis0 (0x1 << 16)
#define PWM_pisr_pgis0_SHIFT 16
#define PWM_pisr_pis0 0x1
#define PWM_pisr_pis0_SHIFT 0
#define PWM_cier (PWM + 0x10) // Capture IRQ Enable Register ()
#define PWM_cier_OFFSET 0x10
#define PWM_cier_RESET 0x00000000
#define PWM_cier_cfie0 (0x1 << 1)
#define PWM_cier_cfie0_SHIFT 1
#define PWM_cier_crie0 0x1
#define PWM_cier_crie0_SHIFT 0
#define PWM_cisr (PWM + 0x14) // Capture IRQ Status Register ()
#define PWM_cisr_OFFSET 0x14
#define PWM_cisr_RESET 0x00000000
#define PWM_cisr_cfis0 (0x1 << 1)
#define PWM_cisr_cfis0_SHIFT 1
#define PWM_cisr_cris0 0x1
#define PWM_cisr_cris0_SHIFT 0
#define PWM_pccr01 (PWM + 0x20) // PWM01 Clock Configuration Register ()
#define PWM_pccr01_OFFSET 0x20
#define PWM_pccr01_RESET 0x00000000
#define PWM_pccr01_pwm01_clk_src (0x3 << 7)
#define PWM_pccr01_pwm01_clk_src_SHIFT 7
#define PWM_pccr01_pwm01_clk_div_m 0xf
#define PWM_pccr01_pwm01_clk_div_m_SHIFT 0
#define PWM_pccr23 (PWM + 0x24) // PWM23 Clock Configuration Register ()
#define PWM_pccr23_OFFSET 0x24
#define PWM_pccr23_RESET 0x00000000
#define PWM_pccr23_pwm23_clk_src_sel (0x3 << 7)
#define PWM_pccr23_pwm23_clk_src_sel_SHIFT 7
#define PWM_pccr23_pwm23_clk_div_m 0xf
#define PWM_pccr23_pwm23_clk_div_m_SHIFT 0
#define PWM_pccr45 (PWM + 0x28) // PWM45 Clock Configuration Register ()
#define PWM_pccr45_OFFSET 0x28
#define PWM_pccr45_RESET 0x00000000
#define PWM_pccr45_pwm45_clk_src_sel (0x3 << 7)
#define PWM_pccr45_pwm45_clk_src_sel_SHIFT 7
#define PWM_pccr45_pwm45_clk_div_m 0xf
#define PWM_pccr45_pwm45_clk_div_m_SHIFT 0
#define PWM_pccr67 (PWM + 0x2c) // PWM67 Clock Configuration Register ()
#define PWM_pccr67_OFFSET 0x2c
#define PWM_pccr67_RESET 0x00000000
#define PWM_pccr67_pwm67_clk_src_sel (0x3 << 7)
#define PWM_pccr67_pwm67_clk_src_sel_SHIFT 7
#define PWM_pccr67_pwm67_clk_div_m 0xf
#define PWM_pccr67_pwm67_clk_div_m_SHIFT 0
#define PWM_pcgr (PWM + 0x40) // PWM Clock Gating Register ()
#define PWM_pcgr_OFFSET 0x40
#define PWM_pcgr_RESET 0x00000000
#define PWM_pcgr_pwm0_clk_bypass (0x1 << 16)
#define PWM_pcgr_pwm0_clk_bypass_SHIFT 16
#define PWM_pcgr_pwm0_clk_gating 0x1
#define PWM_pcgr_pwm0_clk_gating_SHIFT 0
#define PWM_pdzcr01 (PWM + 0x60) // PWM01 Dead Zone Control Register ()
#define PWM_pdzcr01_OFFSET 0x60
#define PWM_pdzcr01_RESET 0x00000000
#define PWM_pdzcr01_pwm01_dz_intv (0xff << 8)
#define PWM_pdzcr01_pwm01_dz_intv_SHIFT 8
#define PWM_pdzcr01_pwm01_dz_en 0x1
#define PWM_pdzcr01_pwm01_dz_en_SHIFT 0
#define PWM_pdzcr23 (PWM + 0x64) // PWM23 Dead Zone Control Register ()
#define PWM_pdzcr23_OFFSET 0x64
#define PWM_pdzcr23_RESET 0x00000000
#define PWM_pdzcr23_pwm23_dz_intv (0xff << 8)
#define PWM_pdzcr23_pwm23_dz_intv_SHIFT 8
#define PWM_pdzcr23_pwm23_dz_en 0x1
#define PWM_pdzcr23_pwm23_dz_en_SHIFT 0
#define PWM_pdzcr45 (PWM + 0x68) // PWM45 Dead Zone Control Register ()
#define PWM_pdzcr45_OFFSET 0x68
#define PWM_pdzcr45_RESET 0x00000000
#define PWM_pdzcr45_pwm45_dz_intv (0xff << 8)
#define PWM_pdzcr45_pwm45_dz_intv_SHIFT 8
#define PWM_pdzcr45_pwm45_dz_en 0x1
#define PWM_pdzcr45_pwm45_dz_en_SHIFT 0
#define PWM_pdzcr67 (PWM + 0x6c) // PWM67 Dead Zone Control Register ()
#define PWM_pdzcr67_OFFSET 0x6c
#define PWM_pdzcr67_RESET 0x00000000
#define PWM_pdzcr67_pwm67_dz_intv (0xff << 8)
#define PWM_pdzcr67_pwm67_dz_intv_SHIFT 8
#define PWM_pdzcr67_pwm67_dz_en 0x1
#define PWM_pdzcr67_pwm67_dz_en_SHIFT 0
#define PWM_per (PWM + 0x80) // PWM Enable Register ()
#define PWM_per_OFFSET 0x80
#define PWM_per_RESET 0x00000000
#define PWM_per_pwm0_en 0x1
#define PWM_per_pwm0_en_SHIFT 0
#define PWM_pgr0 (PWM + 0x90) // PWM Groupg Register ()
#define PWM_pgr0_OFFSET 0x90
#define PWM_pgr0_RESET 0x00000000
#define PWM_pgr0_start (0x1 << 17)
#define PWM_pgr0_start_SHIFT 17
#define PWM_pgr0_en (0x1 << 16)
#define PWM_pgr0_en_SHIFT 16
#define PWM_pgr0_cs 0xffff
#define PWM_pgr0_cs_SHIFT 0
#define PWM_cer (PWM + 0xc0) // Capture Enable Register ()
#define PWM_cer_OFFSET 0xc0
#define PWM_cer_RESET 0x00000000
#define PWM_cer_cap0_en 0x1
#define PWM_cer_cap0_en_SHIFT 0
#define PWM_pcr0 (PWM + 0x100) // PWM Control Register ()
#define PWM_pcr0_OFFSET 0x100
#define PWM_pcr0_pwm_pul_num (0xffff << 16)
#define PWM_pcr0_pwm_pul_num_SHIFT 16
#define PWM_pcr0_pwm_period_rdy (0x1 << 11)
#define PWM_pcr0_pwm_period_rdy_SHIFT 11
#define PWM_pcr0_pwm_pul_start (0x1 << 10)
#define PWM_pcr0_pwm_pul_start_SHIFT 10
#define PWM_pcr0_pwm_mode (0x1 << 9)
#define PWM_pcr0_pwm_mode_SHIFT 9
#define PWM_pcr0_pwm_act_sta (0x1 << 8)
#define PWM_pcr0_pwm_act_sta_SHIFT 8
#define PWM_pcr0_pwm_prescal_k 0xff
#define PWM_pcr0_pwm_prescal_k_SHIFT 0
#define PWM_ppr0 (PWM + 0x104) // PWM Period Register ()
#define PWM_ppr0_OFFSET 0x104
#define PWM_ppr0_RESET 0x00000000
#define PWM_ppr0_pwm_entire_cycle (0xffff << 16)
#define PWM_ppr0_pwm_entire_cycle_SHIFT 16
#define PWM_ppr0_pwm_act_cycle 0xffff
#define PWM_ppr0_pwm_act_cycle_SHIFT 0
#define PWM_pcntr0 (PWM + 0x108) // PWM Count Register ()
#define PWM_pcntr0_OFFSET 0x108
#define PWM_pcntr0_RESET 0x00000000
#define PWM_pcntr0_pwm_counter_start (0xffff << 16)
#define PWM_pcntr0_pwm_counter_start_SHIFT 16
#define PWM_pcntr0_pwm_counter_status 0xffff
#define PWM_pcntr0_pwm_counter_status_SHIFT 0
#define PWM_ppcntr0 (PWM + 0x10c) // PWM Pulse Counter Register (R only)
#define PWM_ppcntr0_OFFSET 0x10c
#define PWM_ppcntr0_pwm_pul_counter_status 0xffff
#define PWM_ppcntr0_pwm_pul_counter_status_SHIFT 0
#define PWM_ccr0 (PWM + 0x110) // Capture Control Register ()
#define PWM_ccr0_OFFSET 0x110
#define PWM_ccr0_RESET 0x00000000
#define PWM_ccr0_crlf (0x1 << 4)
#define PWM_ccr0_crlf_SHIFT 4
#define PWM_ccr0_cflf (0x1 << 3)
#define PWM_ccr0_cflf_SHIFT 3
#define PWM_ccr0_crte (0x1 << 2)
#define PWM_ccr0_crte_SHIFT 2
#define PWM_ccr0_cfte (0x1 << 1)
#define PWM_ccr0_cfte_SHIFT 1
#define PWM_ccr0_capinv 0x1
#define PWM_ccr0_capinv_SHIFT 0
#define PWM_crlr0 (PWM + 0x114) // Capture Rise Lock Register (R only)
#define PWM_crlr0_OFFSET 0x114
#define PWM_crlr0_crlr 0xffff
#define PWM_crlr0_crlr_SHIFT 0
#define PWM_cflr0 (PWM + 0x118) // Capture Fall Lock Register (R only)
#define PWM_cflr0_OFFSET 0x118
#define PWM_cflr0_cflr 0xffff
#define PWM_cflr0_cflr_SHIFT 0

/****************************************************************
 * LEDC
 ****************************************************************/
#define LEDC 0x02008000
#define LEDC_ledc_ctrl (LEDC + 0x0) // LEDC Control Register ()
#define LEDC_ledc_ctrl_OFFSET 0x0
#define LEDC_ledc_ctrl_total_data_length (0x1fff << 16)
#define LEDC_ledc_ctrl_total_data_length_SHIFT 16
#define LEDC_ledc_ctrl_reset_led_en (0x1 << 10)
#define LEDC_ledc_ctrl_reset_led_en_SHIFT 10
#define LEDC_ledc_ctrl_led_rgb_mode (0x7 << 6)
#define LEDC_ledc_ctrl_led_rgb_mode_SHIFT 6
#define LEDC_ledc_ctrl_led_msb_0 (0x1 << 2)
#define LEDC_ledc_ctrl_led_msb_0_SHIFT 2
#define LEDC_ledc_ctrl_ledc_soft_reset (0x1 << 1)
#define LEDC_ledc_ctrl_ledc_soft_reset_SHIFT 1
#define LEDC_ledc_ctrl_ledc_en 0x1
#define LEDC_ledc_ctrl_ledc_en_SHIFT 0
#define LEDC_led_t01_timing_ctrl (LEDC + 0x4) // LEDC T0 T1 Timing Control Register ()
#define LEDC_led_t01_timing_ctrl_OFFSET 0x4
#define LEDC_led_t01_timing_ctrl_t1h_time (0x3f << 21)
#define LEDC_led_t01_timing_ctrl_t1h_time_SHIFT 21
#define LEDC_led_t01_timing_ctrl_t1l_time (0x1f << 16)
#define LEDC_led_t01_timing_ctrl_t1l_time_SHIFT 16
#define LEDC_led_t01_timing_ctrl_t0h_time (0x1f << 6)
#define LEDC_led_t01_timing_ctrl_t0h_time_SHIFT 6
#define LEDC_led_t01_timing_ctrl_t0l_time 0x3f
#define LEDC_led_t01_timing_ctrl_t0l_time_SHIFT 0
#define LEDC_ledc_data_finish_cnt (LEDC + 0x8) // LEDC Data Finish Counter Register ()
#define LEDC_ledc_data_finish_cnt_OFFSET 0x8
#define LEDC_ledc_data_finish_cnt_led_wait_data_time (0x3fff << 16)
#define LEDC_ledc_data_finish_cnt_led_wait_data_time_SHIFT 16
#define LEDC_ledc_data_finish_cnt_led_data_finish_cnt 0x1fff
#define LEDC_ledc_data_finish_cnt_led_data_finish_cnt_SHIFT 0
#define LEDC_led_reset_timing_ctrl (LEDC + 0xc) // LEDC Reset Timing Control Register ()
#define LEDC_led_reset_timing_ctrl_OFFSET 0xc
#define LEDC_led_reset_timing_ctrl_tr_time (0x1fff << 16)
#define LEDC_led_reset_timing_ctrl_tr_time_SHIFT 16
#define LEDC_led_reset_timing_ctrl_led_num 0x3ff
#define LEDC_led_reset_timing_ctrl_led_num_SHIFT 0
#define LEDC_ledc_wait_time0_ctrl (LEDC + 0x10) // LEDC Wait Time0 Control Register ()
#define LEDC_ledc_wait_time0_ctrl_OFFSET 0x10
#define LEDC_ledc_wait_time0_ctrl_wait_tim0_en (0x1 << 8)
#define LEDC_ledc_wait_time0_ctrl_wait_tim0_en_SHIFT 8
#define LEDC_ledc_wait_time0_ctrl_total_wait_time0 0xff
#define LEDC_ledc_wait_time0_ctrl_total_wait_time0_SHIFT 0
#define LEDC_ledc_data (LEDC + 0x14) // LEDC Data Register (W only)
#define LEDC_ledc_data_OFFSET 0x14
#define LEDC_ledc_dma_ctrl (LEDC + 0x18) // LEDC DMA Control Register ()
#define LEDC_ledc_dma_ctrl_OFFSET 0x18
#define LEDC_ledc_dma_ctrl_ledc_dma_en (0x1 << 5)
#define LEDC_ledc_dma_ctrl_ledc_dma_en_SHIFT 5
#define LEDC_ledc_dma_ctrl_ledc_fifo_trig_level 0x1f
#define LEDC_ledc_dma_ctrl_ledc_fifo_trig_level_SHIFT 0
#define LEDC_ledc_int_ctrl (LEDC + 0x1c) // LEDC Interrupt Control Register ()
#define LEDC_ledc_int_ctrl_OFFSET 0x1c
#define LEDC_ledc_int_ctrl_global_int_en (0x1 << 5)
#define LEDC_ledc_int_ctrl_global_int_en_SHIFT 5
#define LEDC_ledc_int_ctrl_fifo_overflow_int_en (0x1 << 4)
#define LEDC_ledc_int_ctrl_fifo_overflow_int_en_SHIFT 4
#define LEDC_ledc_int_ctrl_waitdata_timeout_int_en (0x1 << 3)
#define LEDC_ledc_int_ctrl_waitdata_timeout_int_en_SHIFT 3
#define LEDC_ledc_int_ctrl_fifo_cpureq_int_en (0x1 << 1)
#define LEDC_ledc_int_ctrl_fifo_cpureq_int_en_SHIFT 1
#define LEDC_ledc_int_ctrl_led_trans_finish_int_en 0x1
#define LEDC_ledc_int_ctrl_led_trans_finish_int_en_SHIFT 0
#define LEDC_ledc_int_sts (LEDC + 0x20) // LEDC Interrupt Status Register ()
#define LEDC_ledc_int_sts_OFFSET 0x20
#define LEDC_ledc_int_sts_fifo_empty (0x1 << 17)
#define LEDC_ledc_int_sts_fifo_empty_SHIFT 17
#define LEDC_ledc_int_sts_fifo_full (0x1 << 16)
#define LEDC_ledc_int_sts_fifo_full_SHIFT 16
#define LEDC_ledc_int_sts_fifo_wlw (0x3f << 10)
#define LEDC_ledc_int_sts_fifo_wlw_SHIFT 10
#define LEDC_ledc_int_sts_fifo_overflow_int (0x1 << 4)
#define LEDC_ledc_int_sts_fifo_overflow_int_SHIFT 4
#define LEDC_ledc_int_sts_waitdata_timeout_int (0x1 << 3)
#define LEDC_ledc_int_sts_waitdata_timeout_int_SHIFT 3
#define LEDC_ledc_int_sts_fifo_cpureq_int (0x1 << 1)
#define LEDC_ledc_int_sts_fifo_cpureq_int_SHIFT 1
#define LEDC_ledc_int_sts_lec_trans_finish_int 0x1
#define LEDC_ledc_int_sts_lec_trans_finish_int_SHIFT 0
#define LEDC_ledc_wait_time1_ctrl (LEDC + 0x28) // LEDC Wait Time1 Control Register ()
#define LEDC_ledc_wait_time1_ctrl_OFFSET 0x28
#define LEDC_ledc_wait_time1_ctrl_wait_tim1_en (0x1 << 31)
#define LEDC_ledc_wait_time1_ctrl_wait_tim1_en_SHIFT 31
#define LEDC_ledc_wait_time1_ctrl_total_wait_time1 0x7fffffff
#define LEDC_ledc_wait_time1_ctrl_total_wait_time1_SHIFT 0
#define LEDC_ledc_fifo_data0 (LEDC + 0x30) // LEDC FIFO Data Register (R only)
#define LEDC_ledc_fifo_data0_OFFSET 0x30

/****************************************************************
 * Ethernet Medium Access Controller
 ****************************************************************/
#define EMAC 0x04500000
#define EMAC_emac_basic_ctl0 (EMAC + 0x0) // EMAC Basic Control Register0 ()
#define EMAC_emac_basic_ctl0_OFFSET 0x0
#define EMAC_emac_basic_ctl0_speed (0x3 << 2)
#define EMAC_emac_basic_ctl0_speed_SHIFT 2
#define EMAC_emac_basic_ctl0_loopback (0x1 << 1)
#define EMAC_emac_basic_ctl0_loopback_SHIFT 1
#define EMAC_emac_basic_ctl0_duplex 0x1
#define EMAC_emac_basic_ctl0_duplex_SHIFT 0
#define EMAC_emac_basic_ctl1 (EMAC + 0x4) // EMAC Basic Control Register1 ()
#define EMAC_emac_basic_ctl1_OFFSET 0x4
#define EMAC_emac_basic_ctl1_burst_len (0x3f << 24)
#define EMAC_emac_basic_ctl1_burst_len_SHIFT 24
#define EMAC_emac_basic_ctl1_rx_tx_pri (0x1 << 1)
#define EMAC_emac_basic_ctl1_rx_tx_pri_SHIFT 1
#define EMAC_emac_basic_ctl1_soft_rst 0x1
#define EMAC_emac_basic_ctl1_soft_rst_SHIFT 0
#define EMAC_emac_int_sta (EMAC + 0x8) // EMAC Interrupt Status Register ()
#define EMAC_emac_int_sta_OFFSET 0x8
#define EMAC_emac_int_sta_rgmii_link_sta_p (0x1 << 16)
#define EMAC_emac_int_sta_rgmii_link_sta_p_SHIFT 16
#define EMAC_emac_int_sta_rx_early_p (0x1 << 13)
#define EMAC_emac_int_sta_rx_early_p_SHIFT 13
#define EMAC_emac_int_sta_rx_overflow_p (0x1 << 12)
#define EMAC_emac_int_sta_rx_overflow_p_SHIFT 12
#define EMAC_emac_int_sta_rx_timeout_p (0x1 << 11)
#define EMAC_emac_int_sta_rx_timeout_p_SHIFT 11
#define EMAC_emac_int_sta_rx_dma_stopped_p (0x1 << 10)
#define EMAC_emac_int_sta_rx_dma_stopped_p_SHIFT 10
#define EMAC_emac_int_sta_rx_buf_ua_p (0x1 << 9)
#define EMAC_emac_int_sta_rx_buf_ua_p_SHIFT 9
#define EMAC_emac_int_sta_rx_p (0x1 << 8)
#define EMAC_emac_int_sta_rx_p_SHIFT 8
#define EMAC_emac_int_sta_tx_early_p (0x1 << 5)
#define EMAC_emac_int_sta_tx_early_p_SHIFT 5
#define EMAC_emac_int_sta_tx_underflow_p (0x1 << 4)
#define EMAC_emac_int_sta_tx_underflow_p_SHIFT 4
#define EMAC_emac_int_sta_tx_timeout_p (0x1 << 3)
#define EMAC_emac_int_sta_tx_timeout_p_SHIFT 3
#define EMAC_emac_int_sta_tx_buf_ua_p (0x1 << 2)
#define EMAC_emac_int_sta_tx_buf_ua_p_SHIFT 2
#define EMAC_emac_int_sta_tx_dma_stopped_p (0x1 << 1)
#define EMAC_emac_int_sta_tx_dma_stopped_p_SHIFT 1
#define EMAC_emac_int_sta_tx_p 0x1
#define EMAC_emac_int_sta_tx_p_SHIFT 0
#define EMAC_emac_int_en (EMAC + 0xc) // EMAC Interrupt Enable Register ()
#define EMAC_emac_int_en_OFFSET 0xc
#define EMAC_emac_int_en_rx_early_int_en (0x1 << 13)
#define EMAC_emac_int_en_rx_early_int_en_SHIFT 13
#define EMAC_emac_int_en_rx_overflow_int_en (0x1 << 12)
#define EMAC_emac_int_en_rx_overflow_int_en_SHIFT 12
#define EMAC_emac_int_en_rx_timeout_int_en (0x1 << 11)
#define EMAC_emac_int_en_rx_timeout_int_en_SHIFT 11
#define EMAC_emac_int_en_rx_dma_stopped_int_en (0x1 << 10)
#define EMAC_emac_int_en_rx_dma_stopped_int_en_SHIFT 10
#define EMAC_emac_int_en_rx_buf_ua_int_en (0x1 << 9)
#define EMAC_emac_int_en_rx_buf_ua_int_en_SHIFT 9
#define EMAC_emac_int_en_rx_int_en (0x1 << 8)
#define EMAC_emac_int_en_rx_int_en_SHIFT 8
#define EMAC_emac_int_en_tx_early_int_en (0x1 << 5)
#define EMAC_emac_int_en_tx_early_int_en_SHIFT 5
#define EMAC_emac_int_en_tx_underflow_int_en (0x1 << 4)
#define EMAC_emac_int_en_tx_underflow_int_en_SHIFT 4
#define EMAC_emac_int_en_tx_timeout_int_en (0x1 << 3)
#define EMAC_emac_int_en_tx_timeout_int_en_SHIFT 3
#define EMAC_emac_int_en_tx_buf_ua_int_en (0x1 << 2)
#define EMAC_emac_int_en_tx_buf_ua_int_en_SHIFT 2
#define EMAC_emac_int_en_tx_dma_stopped_int_en (0x1 << 1)
#define EMAC_emac_int_en_tx_dma_stopped_int_en_SHIFT 1
#define EMAC_emac_int_en_tx_int_en 0x1
#define EMAC_emac_int_en_tx_int_en_SHIFT 0
#define EMAC_emac_tx_ctl0 (EMAC + 0x10) // EMAC Transmit Control Register0 ()
#define EMAC_emac_tx_ctl0_OFFSET 0x10
#define EMAC_emac_tx_ctl0_tx_en (0x1 << 31)
#define EMAC_emac_tx_ctl0_tx_en_SHIFT 31
#define EMAC_emac_tx_ctl0_tx_frm_len_ctl (0x1 << 30)
#define EMAC_emac_tx_ctl0_tx_frm_len_ctl_SHIFT 30
#define EMAC_emac_tx_ctl1 (EMAC + 0x14) // EMAC Transmit Control Register1 ()
#define EMAC_emac_tx_ctl1_OFFSET 0x14
#define EMAC_emac_tx_ctl1_tx_dma_start (0x1 << 31)
#define EMAC_emac_tx_ctl1_tx_dma_start_SHIFT 31
#define EMAC_emac_tx_ctl1_tx_dma_en (0x1 << 30)
#define EMAC_emac_tx_ctl1_tx_dma_en_SHIFT 30
#define EMAC_emac_tx_ctl1_tx_th (0x7 << 8)
#define EMAC_emac_tx_ctl1_tx_th_SHIFT 8
#define EMAC_emac_tx_ctl1_tx_md (0x1 << 1)
#define EMAC_emac_tx_ctl1_tx_md_SHIFT 1
#define EMAC_emac_tx_ctl1_flush_tx_fifo 0x1
#define EMAC_emac_tx_ctl1_flush_tx_fifo_SHIFT 0
#define EMAC_emac_tx_flow_ctl (EMAC + 0x1c) // EMAC Transmit Flow Control Register ()
#define EMAC_emac_tx_flow_ctl_OFFSET 0x1c
#define EMAC_emac_tx_flow_ctl_tx_flow_ctl_sta (0x1 << 31)
#define EMAC_emac_tx_flow_ctl_tx_flow_ctl_sta_SHIFT 31
#define EMAC_emac_tx_flow_ctl_tx_pause_frm_slot (0x3 << 20)
#define EMAC_emac_tx_flow_ctl_tx_pause_frm_slot_SHIFT 20
#define EMAC_emac_tx_flow_ctl_pause_time (0xffff << 4)
#define EMAC_emac_tx_flow_ctl_pause_time_SHIFT 4
#define EMAC_emac_tx_flow_ctl_zqp_frm_en (0x1 << 1)
#define EMAC_emac_tx_flow_ctl_zqp_frm_en_SHIFT 1
#define EMAC_emac_tx_flow_ctl_tx_flow_ctl_en 0x1
#define EMAC_emac_tx_flow_ctl_tx_flow_ctl_en_SHIFT 0
#define EMAC_emac_tx_dma_desc_list (EMAC + 0x20) // EMAC Transmit Descriptor List Address Register ()
#define EMAC_emac_tx_dma_desc_list_OFFSET 0x20
#define EMAC_emac_rx_ctl0 (EMAC + 0x24) // EMAC Receive Control Register0 ()
#define EMAC_emac_rx_ctl0_OFFSET 0x24
#define EMAC_emac_rx_ctl0_rx_en (0x1 << 31)
#define EMAC_emac_rx_ctl0_rx_en_SHIFT 31
#define EMAC_emac_rx_ctl0_rx_frm_len_ctl (0x1 << 30)
#define EMAC_emac_rx_ctl0_rx_frm_len_ctl_SHIFT 30
#define EMAC_emac_rx_ctl0_jumbo_frm_en (0x1 << 29)
#define EMAC_emac_rx_ctl0_jumbo_frm_en_SHIFT 29
#define EMAC_emac_rx_ctl0_strip_fcs (0x1 << 28)
#define EMAC_emac_rx_ctl0_strip_fcs_SHIFT 28
#define EMAC_emac_rx_ctl0_check_crc (0x1 << 27)
#define EMAC_emac_rx_ctl0_check_crc_SHIFT 27
#define EMAC_emac_rx_ctl0_rx_pause_frm_md (0x1 << 17)
#define EMAC_emac_rx_ctl0_rx_pause_frm_md_SHIFT 17
#define EMAC_emac_rx_ctl0_rx_flow_ctl_en (0x1 << 16)
#define EMAC_emac_rx_ctl0_rx_flow_ctl_en_SHIFT 16
#define EMAC_emac_rx_ctl1 (EMAC + 0x28) // EMAC Receive Control Register1 ()
#define EMAC_emac_rx_ctl1_OFFSET 0x28
#define EMAC_emac_rx_ctl1_rx_dma_start (0x1 << 31)
#define EMAC_emac_rx_ctl1_rx_dma_start_SHIFT 31
#define EMAC_emac_rx_ctl1_rx_ema_en (0x1 << 30)
#define EMAC_emac_rx_ctl1_rx_ema_en_SHIFT 30
#define EMAC_emac_rx_ctl1_rx_fifo_flow_ctl (0x1 << 24)
#define EMAC_emac_rx_ctl1_rx_fifo_flow_ctl_SHIFT 24
#define EMAC_emac_rx_ctl1_rx_flow_ctl_th_deact (0x3 << 22)
#define EMAC_emac_rx_ctl1_rx_flow_ctl_th_deact_SHIFT 22
#define EMAC_emac_rx_ctl1_rx_flow_ctl_th_act (0x3 << 20)
#define EMAC_emac_rx_ctl1_rx_flow_ctl_th_act_SHIFT 20
#define EMAC_emac_rx_ctl1_rx_th (0x3 << 4)
#define EMAC_emac_rx_ctl1_rx_th_SHIFT 4
#define EMAC_emac_rx_ctl1_rx_err_frm (0x1 << 3)
#define EMAC_emac_rx_ctl1_rx_err_frm_SHIFT 3
#define EMAC_emac_rx_ctl1_rx_runt_frm (0x1 << 2)
#define EMAC_emac_rx_ctl1_rx_runt_frm_SHIFT 2
#define EMAC_emac_rx_ctl1_rx_md (0x1 << 1)
#define EMAC_emac_rx_ctl1_rx_md_SHIFT 1
#define EMAC_emac_rx_ctl1_flush_rx_frm 0x1
#define EMAC_emac_rx_ctl1_flush_rx_frm_SHIFT 0
#define EMAC_emac_rx_dma_desc_list (EMAC + 0x34) // EMAC Receive Descriptor List Address Register ()
#define EMAC_emac_rx_dma_desc_list_OFFSET 0x34
#define EMAC_emac_rx_frm_flt (EMAC + 0x38) // EMAC Receive Frame Filter Register ()
#define EMAC_emac_rx_frm_flt_OFFSET 0x38
#define EMAC_emac_rx_frm_flt_dis_addr_filter (0x1 << 31)
#define EMAC_emac_rx_frm_flt_dis_addr_filter_SHIFT 31
#define EMAC_emac_rx_frm_flt_dis_broadcast (0x1 << 17)
#define EMAC_emac_rx_frm_flt_dis_broadcast_SHIFT 17
#define EMAC_emac_rx_frm_flt_rx_all_multicast (0x1 << 16)
#define EMAC_emac_rx_frm_flt_rx_all_multicast_SHIFT 16
#define EMAC_emac_rx_frm_flt_ctl_frm_filter (0x3 << 12)
#define EMAC_emac_rx_frm_flt_ctl_frm_filter_SHIFT 12
#define EMAC_emac_rx_frm_flt_hash_multicast (0x1 << 9)
#define EMAC_emac_rx_frm_flt_hash_multicast_SHIFT 9
#define EMAC_emac_rx_frm_flt_hash_unicast (0x1 << 8)
#define EMAC_emac_rx_frm_flt_hash_unicast_SHIFT 8
#define EMAC_emac_rx_frm_flt_sa_filter_en (0x1 << 6)
#define EMAC_emac_rx_frm_flt_sa_filter_en_SHIFT 6
#define EMAC_emac_rx_frm_flt_sa_inv_filter (0x1 << 5)
#define EMAC_emac_rx_frm_flt_sa_inv_filter_SHIFT 5
#define EMAC_emac_rx_frm_flt_da_inv_filter (0x1 << 4)
#define EMAC_emac_rx_frm_flt_da_inv_filter_SHIFT 4
#define EMAC_emac_rx_frm_flt_flt_md (0x1 << 1)
#define EMAC_emac_rx_frm_flt_flt_md_SHIFT 1
#define EMAC_emac_rx_frm_flt_rx_all 0x1
#define EMAC_emac_rx_frm_flt_rx_all_SHIFT 0
#define EMAC_emac_rx_hash0 (EMAC + 0x40) // EMAC Hash Table Register0 ()
#define EMAC_emac_rx_hash0_OFFSET 0x40
#define EMAC_emac_rx_hash1 (EMAC + 0x44) // EMAC Hash Table Register1 ()
#define EMAC_emac_rx_hash1_OFFSET 0x44
#define EMAC_emac_mii_cmd (EMAC + 0x48) // EMAC Management Interface Command Register ()
#define EMAC_emac_mii_cmd_OFFSET 0x48
#define EMAC_emac_mii_cmd_mdc_div_ratio_m (0x7 << 20)
#define EMAC_emac_mii_cmd_mdc_div_ratio_m_SHIFT 20
#define EMAC_emac_mii_cmd_phy_addr (0x1f << 12)
#define EMAC_emac_mii_cmd_phy_addr_SHIFT 12
#define EMAC_emac_mii_cmd_phy_reg_addr (0x1f << 4)
#define EMAC_emac_mii_cmd_phy_reg_addr_SHIFT 4
#define EMAC_emac_mii_cmd_mii_wr (0x1 << 1)
#define EMAC_emac_mii_cmd_mii_wr_SHIFT 1
#define EMAC_emac_mii_cmd_mii_busy 0x1
#define EMAC_emac_mii_cmd_mii_busy_SHIFT 0
#define EMAC_emac_mii_data (EMAC + 0x4c) // EMAC Management Interface Data Register ()
#define EMAC_emac_mii_data_OFFSET 0x4c
#define EMAC_emac_mii_data_mii_data 0xffff
#define EMAC_emac_mii_data_mii_data_SHIFT 0
/*
#warning check these definitions:
#define EMAC_emac_addr_high0 (EMAC + 0x50) // EMAC MAC Address High Register ()
#define EMAC_emac_addr_high0_OFFSET 0x50
#define EMAC_emac_addr_high0_mac_addr_high0 0xffff
#define EMAC_emac_addr_high0_mac_addr_high0_SHIFT 0
#define EMAC_emac_addr_high1 (EMAC + 0x58) // EMAC MAC Address High Register ()
#define EMAC_emac_addr_high1_OFFSET 0x58
#define EMAC_emac_addr_high1_mac_addr_ctl (0x1 << 31)
#define EMAC_emac_addr_high1_mac_addr_ctl_SHIFT 31
#define EMAC_emac_addr_high1_mac_addr_type (0x1 << 30)
#define EMAC_emac_addr_high1_mac_addr_type_SHIFT 30
#define EMAC_emac_addr_high1_mac_addr_byte_ctl (0x3f << 24)
#define EMAC_emac_addr_high1_mac_addr_byte_ctl_SHIFT 24
#define EMAC_emac_addr_high1_mac_addr_high 0xffff
#define EMAC_emac_addr_high1_mac_addr_high_SHIFT 0
*/
#define EMAC_emac_addr_low0 (EMAC + 0x54) // EMAC MAC Address Low Register ()
#define EMAC_emac_addr_low0_OFFSET 0x54
#define EMAC_emac_tx_dma_sta (EMAC + 0xb0) // EMAC Transmit DMA Status Register (R only)
#define EMAC_emac_tx_dma_sta_OFFSET 0xb0
#define EMAC_emac_tx_dma_sta_tx_dma_sta 0x7
#define EMAC_emac_tx_dma_sta_tx_dma_sta_SHIFT 0
#define EMAC_emac_tx_cur_desc (EMAC + 0xb4) // EMAC Current Transmit Descriptor Register (R only)
#define EMAC_emac_tx_cur_desc_OFFSET 0xb4
#define EMAC_emac_tx_cur_buf (EMAC + 0xb8) // EMAC Current Transmit Buffer Address Register (R only)
#define EMAC_emac_tx_cur_buf_OFFSET 0xb8
#define EMAC_emac_rx_dma_sta (EMAC + 0xc0) // EMAC Receive DMA Status Register (R only)
#define EMAC_emac_rx_dma_sta_OFFSET 0xc0
#define EMAC_emac_rx_dma_sta_rx_dma_sta 0x7
#define EMAC_emac_rx_dma_sta_rx_dma_sta_SHIFT 0
#define EMAC_emac_rx_cur_desc (EMAC + 0xc4) // EMAC Current Receive Descriptor Register (R only)
#define EMAC_emac_rx_cur_desc_OFFSET 0xc4
#define EMAC_emac_rx_cur_buf (EMAC + 0xc8) // EMAC Current Receive Buffer Address Register (R only)
#define EMAC_emac_rx_cur_buf_OFFSET 0xc8
#define EMAC_emac_rgmii_sta (EMAC + 0xd0) // EMAC RGMII Status Register ()
#define EMAC_emac_rgmii_sta_OFFSET 0xd0
#define EMAC_emac_rgmii_sta_rgmii_link (0x1 << 3)
#define EMAC_emac_rgmii_sta_rgmii_link_SHIFT 3
#define EMAC_emac_rgmii_sta_rgmii_link_spd (0x3 << 1)
#define EMAC_emac_rgmii_sta_rgmii_link_spd_SHIFT 1
#define EMAC_emac_rgmii_sta_rgmii_link_md 0x1
#define EMAC_emac_rgmii_sta_rgmii_link_md_SHIFT 0

/****************************************************************
 * Counsumer Infrared Receiver
 ****************************************************************/
#define CIR_RX 0x07040000
#define CIR_RX_cir_ctl (CIR_RX + 0x0) // CIR Control Register ()
#define CIR_RX_cir_ctl_OFFSET 0x0
#define CIR_RX_cir_ctl_RESET 0x00000000
#define CIR_RX_cir_ctl_apam (0x3 << 6)
#define CIR_RX_cir_ctl_apam_SHIFT 6
#define CIR_RX_cir_ctl_ciren (0x3 << 4)
#define CIR_RX_cir_ctl_ciren_SHIFT 4
#define CIR_RX_cir_ctl_rxen (0x1 << 1)
#define CIR_RX_cir_ctl_rxen_SHIFT 1
#define CIR_RX_cir_ctl_gen 0x1
#define CIR_RX_cir_ctl_gen_SHIFT 0
#define CIR_RX_cir_rxpcfg (CIR_RX + 0x10) // CIR Receiver Pulse Configure Register ()
#define CIR_RX_cir_rxpcfg_OFFSET 0x10
#define CIR_RX_cir_rxpcfg_RESET 0x00000004
#define CIR_RX_cir_rxpcfg_rppi (0x1 << 2)
#define CIR_RX_cir_rxpcfg_rppi_SHIFT 2
#define CIR_RX_cir_rxfifo (CIR_RX + 0x20) // CIR Receiver FIFO Register ()
#define CIR_RX_cir_rxfifo_OFFSET 0x20
#define CIR_RX_cir_rxfifo_RESET 0x00000000
#define CIR_RX_cir_rxfifo_rbf 0xff
#define CIR_RX_cir_rxfifo_rbf_SHIFT 0
#define CIR_RX_cir_rxint (CIR_RX + 0x2c) // CIR Receiver Interrupt Control Register ()
#define CIR_RX_cir_rxint_OFFSET 0x2c
#define CIR_RX_cir_rxint_RESET 0x00000000
#define CIR_RX_cir_rxint_ral (0x3f << 8)
#define CIR_RX_cir_rxint_ral_SHIFT 8
#define CIR_RX_cir_rxint_drq_en (0x1 << 5)
#define CIR_RX_cir_rxint_drq_en_SHIFT 5
#define CIR_RX_cir_rxint_rai_en (0x1 << 4)
#define CIR_RX_cir_rxint_rai_en_SHIFT 4
#define CIR_RX_cir_rxint_rpei_en (0x1 << 1)
#define CIR_RX_cir_rxint_rpei_en_SHIFT 1
#define CIR_RX_cir_rxint_roi_en 0x1
#define CIR_RX_cir_rxint_roi_en_SHIFT 0
#define CIR_RX_cir_rxsta (CIR_RX + 0x30) // CIR Receiver Status Register ()
#define CIR_RX_cir_rxsta_OFFSET 0x30
#define CIR_RX_cir_rxsta_RESET 0x00000000
#define CIR_RX_cir_rxsta_rac (0x7f << 8)
#define CIR_RX_cir_rxsta_rac_SHIFT 8
#define CIR_RX_cir_rxsta_stat (0x1 << 7)
#define CIR_RX_cir_rxsta_stat_SHIFT 7
#define CIR_RX_cir_rxsta_ra (0x1 << 4)
#define CIR_RX_cir_rxsta_ra_SHIFT 4
#define CIR_RX_cir_rxsta_rpe (0x1 << 1)
#define CIR_RX_cir_rxsta_rpe_SHIFT 1
#define CIR_RX_cir_rxsta_roi 0x1
#define CIR_RX_cir_rxsta_roi_SHIFT 0
#define CIR_RX_cir_rxcfg (CIR_RX + 0x34) // CIR Receiver Configure Register ()
#define CIR_RX_cir_rxcfg_OFFSET 0x34
#define CIR_RX_cir_rxcfg_RESET 0x00001828
#define CIR_RX_cir_rxcfg_scs2 (0x1 << 24)
#define CIR_RX_cir_rxcfg_scs2_SHIFT 24
#define CIR_RX_cir_rxcfg_athc (0x1 << 23)
#define CIR_RX_cir_rxcfg_athc_SHIFT 23
#define CIR_RX_cir_rxcfg_athr (0x7f << 16)
#define CIR_RX_cir_rxcfg_athr_SHIFT 16
#define CIR_RX_cir_rxcfg_ithr (0xff << 8)
#define CIR_RX_cir_rxcfg_ithr_SHIFT 8
#define CIR_RX_cir_rxcfg_nthr (0x3f << 2)
#define CIR_RX_cir_rxcfg_nthr_SHIFT 2
#define CIR_RX_cir_rxcfg_scs 0x3
#define CIR_RX_cir_rxcfg_scs_SHIFT 0

/****************************************************************
 * Counsumer Infrared Transmitter
 ****************************************************************/
#define CIR_TX 0x02003000
#define CIR_TX_cir_tglr (CIR_TX + 0x0) // CIR Transmit Global Register ()
#define CIR_TX_cir_tglr_OFFSET 0x0
#define CIR_TX_cir_tglr_RESET 0x00000000
#define CIR_TX_cir_tglr_ims (0x1 << 7)
#define CIR_TX_cir_tglr_ims_SHIFT 7
#define CIR_TX_cir_tglr_drmc (0x3 << 5)
#define CIR_TX_cir_tglr_drmc_SHIFT 5
#define CIR_TX_cir_tglr_tppi (0x1 << 2)
#define CIR_TX_cir_tglr_tppi_SHIFT 2
#define CIR_TX_cir_tglr_tr (0x1 << 1)
#define CIR_TX_cir_tglr_tr_SHIFT 1
#define CIR_TX_cir_tglr_txen 0x1
#define CIR_TX_cir_tglr_txen_SHIFT 0
#define CIR_TX_cir_tmcr (CIR_TX + 0x4) // CIR Transmit Modulation Control Register ()
#define CIR_TX_cir_tmcr_OFFSET 0x4
#define CIR_TX_cir_tmcr_RESET 0x0000009E
#define CIR_TX_cir_tmcr_rfmc 0xff
#define CIR_TX_cir_tmcr_rfmc_SHIFT 0
#define CIR_TX_cir_tcr (CIR_TX + 0x8) // CIR Transmit Control Register ()
#define CIR_TX_cir_tcr_OFFSET 0x8
#define CIR_TX_cir_tcr_RESET 0x00000000
#define CIR_TX_cir_tcr_css (0x1 << 7)
#define CIR_TX_cir_tcr_css_SHIFT 7
#define CIR_TX_cir_tcr_rcs (0x7 << 1)
#define CIR_TX_cir_tcr_rcs_SHIFT 1
#define CIR_TX_cir_tcr_tts 0x1
#define CIR_TX_cir_tcr_tts_SHIFT 0
#define CIR_TX_cir_idc_h (CIR_TX + 0xc) // CIR Transmit Idle Duration Threshold High Bit Register ()
#define CIR_TX_cir_idc_h_OFFSET 0xc
#define CIR_TX_cir_idc_h_RESET 0x00000000
#define CIR_TX_cir_idc_h_idc_h 0xf
#define CIR_TX_cir_idc_h_idc_h_SHIFT 0
#define CIR_TX_cir_idc_l (CIR_TX + 0x10) // CIR Transmit Idle Duration Threshold Low Bit Register ()
#define CIR_TX_cir_idc_l_OFFSET 0x10
#define CIR_TX_cir_idc_l_RESET 0x00000000
#define CIR_TX_cir_idc_l_idc_l 0xff
#define CIR_TX_cir_idc_l_idc_l_SHIFT 0
#define CIR_TX_cir_ticr_h (CIR_TX + 0x14) // CIR Transmit Idle Counter High Bit Register ()
#define CIR_TX_cir_ticr_h_OFFSET 0x14
#define CIR_TX_cir_ticr_h_RESET 0x00000000
#define CIR_TX_cir_ticr_h_tic_h 0xff
#define CIR_TX_cir_ticr_h_tic_h_SHIFT 0
#define CIR_TX_cir_ticr_l (CIR_TX + 0x18) // CIR Transmit Idle Counter Low Bit Register ()
#define CIR_TX_cir_ticr_l_OFFSET 0x18
#define CIR_TX_cir_ticr_l_RESET 0x00000000
#define CIR_TX_cir_ticr_l_tic_l 0xff
#define CIR_TX_cir_ticr_l_tic_l_SHIFT 0
#define CIR_TX_cir_tel (CIR_TX + 0x20) // CIR TX FIFO Empty Level Register ()
#define CIR_TX_cir_tel_OFFSET 0x20
#define CIR_TX_cir_tel_RESET 0x00000000
#define CIR_TX_cir_tel_tel 0xff
#define CIR_TX_cir_tel_tel_SHIFT 0
#define CIR_TX_cir_txint (CIR_TX + 0x24) // CIR Transmit Interrupt Control Register ()
#define CIR_TX_cir_txint_OFFSET 0x24
#define CIR_TX_cir_txint_RESET 0x00000000
#define CIR_TX_cir_txint_drq_en (0x1 << 2)
#define CIR_TX_cir_txint_drq_en_SHIFT 2
#define CIR_TX_cir_txint_tai_en (0x1 << 1)
#define CIR_TX_cir_txint_tai_en_SHIFT 1
#define CIR_TX_cir_txint_tpei_tui_en 0x1
#define CIR_TX_cir_txint_tpei_tui_en_SHIFT 0
#define CIR_TX_cir_tac (CIR_TX + 0x28) // CIR Transmit FIFO Available Counter Register ()
#define CIR_TX_cir_tac_OFFSET 0x28
#define CIR_TX_cir_tac_RESET 0x00000080
#define CIR_TX_cir_tac_tac 0xff
#define CIR_TX_cir_tac_tac_SHIFT 0
#define CIR_TX_cir_txsta (CIR_TX + 0x2c) // CIR Transmit Status Register ()
#define CIR_TX_cir_txsta_OFFSET 0x2c
#define CIR_TX_cir_txsta_RESET 0x00000002
#define CIR_TX_cir_txsta_stct (0x1 << 3)
#define CIR_TX_cir_txsta_stct_SHIFT 3
#define CIR_TX_cir_txsta_drq (0x1 << 2)
#define CIR_TX_cir_txsta_drq_SHIFT 2
#define CIR_TX_cir_txsta_tai (0x1 << 1)
#define CIR_TX_cir_txsta_tai_SHIFT 1
#define CIR_TX_cir_txsta_tpe_tur 0x1
#define CIR_TX_cir_txsta_tpe_tur_SHIFT 0
#define CIR_TX_cir_txt (CIR_TX + 0x30) // CIR Transmit Threshold Register ()
#define CIR_TX_cir_txt_OFFSET 0x30
#define CIR_TX_cir_txt_RESET 0x00000000
#define CIR_TX_cir_txt_nctt 0xff
#define CIR_TX_cir_txt_nctt_SHIFT 0
#define CIR_TX_cir_dma_ctl (CIR_TX + 0x34) // CIR DMA Control Register ()
#define CIR_TX_cir_dma_ctl_OFFSET 0x34
#define CIR_TX_cir_dma_ctl_RESET 0x000000A5
#define CIR_TX_cir_dma_ctl_dma 0xff
#define CIR_TX_cir_dma_ctl_dma_SHIFT 0
#define CIR_TX_cir_txfifo (CIR_TX + 0x80) // CIR Transmit FIFO Data Register ()
#define CIR_TX_cir_txfifo_OFFSET 0x80
#define CIR_TX_cir_txfifo_RESET 0x00000000
#define CIR_TX_cir_txfifo_tbf 0xff
#define CIR_TX_cir_txfifo_tbf_SHIFT 0

/****************************************************************
 * Crypoto Engine
 ****************************************************************/
#define CE_NS 0x03040000
#define CE_NS_ce_tda (CE_NS + 0x0) // Task Descriptor Address ()
#define CE_NS_ce_tda_OFFSET 0x0
#define CE_NS_ce_tda_RESET 0x00000000
#define CE_NS_ce_tda_task 0xffffffff
#define CE_NS_ce_tda_task_SHIFT 0
#define CE_NS_ce_icr (CE_NS + 0x8) // Interrupt Control Register ()
#define CE_NS_ce_icr_OFFSET 0x8
#define CE_NS_ce_icr_RESET 0x00000000
#define CE_NS_ce_icr_task0_irq_en 0xf
#define CE_NS_ce_icr_task0_irq_en_SHIFT 0
#define CE_NS_ce_isr (CE_NS + 0xc) // Interrupt Status Register ()
#define CE_NS_ce_isr_OFFSET 0xc
#define CE_NS_ce_isr_RESET 0x00000000
#define CE_NS_ce_isr_task0_pending 0xf
#define CE_NS_ce_isr_task0_pending_SHIFT 0
#define CE_NS_ce_tlr (CE_NS + 0x10) // Task Load Register ()
#define CE_NS_ce_tlr_OFFSET 0x10
#define CE_NS_ce_tlr_RESET 0x00000000
#define CE_NS_ce_tlr_task_load 0x1
#define CE_NS_ce_tlr_task_load_SHIFT 0
#define CE_NS_ce_tsr (CE_NS + 0x14) // Task Status Register ()
#define CE_NS_ce_tsr_OFFSET 0x14
#define CE_NS_ce_tsr_RESET 0x00000000
#define CE_NS_ce_tsr_running_channel_number 0x3
#define CE_NS_ce_tsr_running_channel_number_SHIFT 0
#define CE_NS_ce_esr (CE_NS + 0x18) // Error Status Register ()
#define CE_NS_ce_esr_OFFSET 0x18
#define CE_NS_ce_esr_RESET 0x00000000
#define CE_NS_ce_esr_task_channel0_error_type 0xf
#define CE_NS_ce_esr_task_channel0_error_type_SHIFT 0
#define CE_NS_ce_csa (CE_NS + 0x24) // Current Source Address Register ()
#define CE_NS_ce_csa_OFFSET 0x24
#define CE_NS_ce_csa_RESET 0x00000000
#define CE_NS_ce_csa_cur_src_addr 0xffffffff
#define CE_NS_ce_csa_cur_src_addr_SHIFT 0
#define CE_NS_ce_cda (CE_NS + 0x28) // Current Destination Address Register ()
#define CE_NS_ce_cda_OFFSET 0x28
#define CE_NS_ce_cda_RESET 0x00000000
#define CE_NS_ce_cda_cur_dst_addr 0xffffffff
#define CE_NS_ce_cda_cur_dst_addr_SHIFT 0
#define CE_NS_ce_tpr (CE_NS + 0x2c) // Throughput Register ()
#define CE_NS_ce_tpr_OFFSET 0x2c
#define CE_NS_ce_tpr_RESET 0x00000000
#define CE_NS_ce_tpr_tp_num 0xffffffff
#define CE_NS_ce_tpr_tp_num_SHIFT 0

/****************************************************************
 * Interrupt handlers
 ****************************************************************/
#define IRQ_UART0 18 // UART0
#define IRQ_UART1 19 // UART1
#define IRQ_UART2 20 // UART2
#define IRQ_UART3 21 // UART3
#define IRQ_UART4 22 // UART4
#define IRQ_UART5 23 // UART5
#define IRQ_TWI0 25 // TWI0
#define IRQ_TWI1 26 // TWI1
#define IRQ_TWI2 27 // TWI2
#define IRQ_TWI3 28 // TWI3
#define IRQ_SPI0 31 // SPI0
#define IRQ_SPI1 32 // SPI1
#define IRQ_PWM 34 // PWM
#define IRQ_IR_TX 35 // IR_TX
#define IRQ_LEDC 36 // LEDC
#define IRQ_OWA 39 // OWA
#define IRQ_DMIC 40 // DMIC
#define IRQ_AUDIO_CODEC 41 // AUDIO_CODEC
#define IRQ_I2S_PCM0 42 // I2S_PCM0
#define IRQ_I2S_PCM1 43 // I2S_PCM1
#define IRQ_I2S_PCM2 44 // I2S_PCM2
#define IRQ_USB0_DEVICE 45 // USB0_DEVICE
#define IRQ_USB0_EHCI 46 // USB0_EHCI
#define IRQ_USB0_OHCI 47 // USB0_OHCI
#define IRQ_USB1_EHCI 49 // USB1_EHCI
#define IRQ_USB1_OHCI 50 // USB1_OHCI
#define IRQ_SMHC0 56 // SMHC0
#define IRQ_SMHC1 57 // SMHC1
#define IRQ_SMHC2 58 // SMHC2
#define IRQ_EMAC 62 // EMAC
#define IRQ_DMAC_NS 66 // DMAC_NS
#define IRQ_CE_NS 68 // CE_NS
#define IRQ_SPINLOCK 70 // SPINLOCK
#define IRQ_HSTIMER0 71 // HSTIMER0
#define IRQ_HSTIMER1 72 // HSTIMER1
#define IRQ_GPADC 73 // GPADC
#define IRQ_THS 74 // THS
#define IRQ_TIMER0 75 // TIMER0
#define IRQ_TIMER1 76 // TIMER1
#define IRQ_LRADC 77 // LRADC
#define IRQ_TPADC 78 // TPADC
#define IRQ_WATCHDOG 79 // WATCHDOG
#define IRQ_IOMMU 80 // IOMMU
#define IRQ_GPIOB_NS 85 // GPIOB_NS
#define IRQ_GPIOC_NS 87 // GPIOC_NS
#define IRQ_GPIOD_NS 89 // GPIOD_NS
#define IRQ_GPIOE_NS 91 // GPIOE_NS
#define IRQ_GPIOF_NS 93 // GPIOF_NS
#define IRQ_CSI_DMA0 111 // CSI_DMA0
#define IRQ_CSI_DMA1 112 // CSI_DMA1
#define IRQ_CSI_TOP_PKT 122 // CSI_TOP_PKT
#define IRQ_TVD 123 // TVD
#define IRQ_DSP_MBOX_RV_W 140 // DSP_MBOX_RV_W
#define IRQ_RV_MBOX_RV 144 // RV_MBOX_RV
#define IRQ_RV_MBOX_DSP 145 // RV_MBOX_DSP
#define IRQ_IR_RX 167 // IR_RX
#endif
