	.section .data
#if 0
	.global splash640x480_data, splash640x480_data_len
	.align 16
splash640x480_data:
	.incbin "splash640x480.data"
splash640x480_data_len:
	.word . - splash640x480_data
#endif
	
	.global jpeg_test_image_640x480_data, jpeg_test_image_640x480_data_len
	.align 16
jpeg_test_image_640x480_data:
	.incbin "splash640x480.jpeg"
jpeg_test_image_640x480_data_len:
	.word . - jpeg_test_image_640x480_data
