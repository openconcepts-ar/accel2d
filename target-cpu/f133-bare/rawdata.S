	.section .data
	.global splash640x480_data, splash640x480_data_len
	.align 16

splash640x480_data:
	.incbin "splash640x480.data"
splash640x480_data_len:
	.word . - splash640x480_data
