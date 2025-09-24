    .section .rodata
    .global _binary_bmpimage_start
    .global _binary_bmpimage_end

    .align 16
    .type _binary_bmpimage_start, @object

_binary_bmpimage_start:
    .incbin "barbara.bmp"
_binary_bmpimage_end:


