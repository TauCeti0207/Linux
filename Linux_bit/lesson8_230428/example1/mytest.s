	.arch armv8-a
	.file	"mytest.c"
	.text
.Ltext0:
	.file 0 "/home/yzq0207/Linux/Linux_bit/lesson8_230428/example1" "mytest.c"
	.section	.rodata
	.align	3
.LC0:
	.string	"hello Linux"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB0:
	.file 1 "mytest.c"
	.loc 1 11 1
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	x29, sp
	.loc 1 12 3
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	printf
	.loc 1 13 3
	adrp	x0, :got:stdout
	ldr	x0, [x0, #:got_lo12:stdout]
	ldr	x0, [x0]
	bl	fflush
	.loc 1 14 3
	mov	w0, 2
	bl	sleep
	.loc 1 15 10
	mov	w0, 0
	.loc 1 16 1
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/lib/gcc/aarch64-linux-gnu/11/include/stddef.h"
	.file 3 "/usr/include/aarch64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/aarch64-linux-gnu/bits/types/struct_FILE.h"
	.file 5 "/usr/include/aarch64-linux-gnu/bits/types/FILE.h"
	.file 6 "/usr/include/unistd.h"
	.file 7 "/usr/include/stdio.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.4byte	0x2d9
	.2byte	0x5
	.byte	0x1
	.byte	0x8
	.4byte	.Ldebug_abbrev0
	.uleb128 0xa
	.4byte	.LASF49
	.byte	0x1d
	.4byte	.LASF0
	.4byte	.LASF1
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x4
	.4byte	.LASF9
	.byte	0x2
	.byte	0xd1
	.byte	0x1b
	.4byte	0x3a
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF2
	.uleb128 0xb
	.byte	0x8
	.uleb128 0xc
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF4
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF8
	.uleb128 0x4
	.4byte	.LASF10
	.byte	0x3
	.byte	0x98
	.byte	0x12
	.4byte	0x6d
	.uleb128 0x4
	.4byte	.LASF11
	.byte	0x3
	.byte	0x99
	.byte	0x12
	.4byte	0x6d
	.uleb128 0x3
	.4byte	0x91
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF12
	.uleb128 0xd
	.4byte	0x91
	.uleb128 0xe
	.4byte	.LASF50
	.byte	0xd8
	.byte	0x4
	.byte	0x31
	.byte	0x8
	.4byte	0x207
	.uleb128 0x1
	.4byte	.LASF13
	.byte	0x33
	.byte	0x7
	.4byte	0x43
	.byte	0
	.uleb128 0x1
	.4byte	.LASF14
	.byte	0x36
	.byte	0x9
	.4byte	0x8c
	.byte	0x8
	.uleb128 0x1
	.4byte	.LASF15
	.byte	0x37
	.byte	0x9
	.4byte	0x8c
	.byte	0x10
	.uleb128 0x1
	.4byte	.LASF16
	.byte	0x38
	.byte	0x9
	.4byte	0x8c
	.byte	0x18
	.uleb128 0x1
	.4byte	.LASF17
	.byte	0x39
	.byte	0x9
	.4byte	0x8c
	.byte	0x20
	.uleb128 0x1
	.4byte	.LASF18
	.byte	0x3a
	.byte	0x9
	.4byte	0x8c
	.byte	0x28
	.uleb128 0x1
	.4byte	.LASF19
	.byte	0x3b
	.byte	0x9
	.4byte	0x8c
	.byte	0x30
	.uleb128 0x1
	.4byte	.LASF20
	.byte	0x3c
	.byte	0x9
	.4byte	0x8c
	.byte	0x38
	.uleb128 0x1
	.4byte	.LASF21
	.byte	0x3d
	.byte	0x9
	.4byte	0x8c
	.byte	0x40
	.uleb128 0x1
	.4byte	.LASF22
	.byte	0x40
	.byte	0x9
	.4byte	0x8c
	.byte	0x48
	.uleb128 0x1
	.4byte	.LASF23
	.byte	0x41
	.byte	0x9
	.4byte	0x8c
	.byte	0x50
	.uleb128 0x1
	.4byte	.LASF24
	.byte	0x42
	.byte	0x9
	.4byte	0x8c
	.byte	0x58
	.uleb128 0x1
	.4byte	.LASF25
	.byte	0x44
	.byte	0x16
	.4byte	0x220
	.byte	0x60
	.uleb128 0x1
	.4byte	.LASF26
	.byte	0x46
	.byte	0x14
	.4byte	0x225
	.byte	0x68
	.uleb128 0x1
	.4byte	.LASF27
	.byte	0x48
	.byte	0x7
	.4byte	0x43
	.byte	0x70
	.uleb128 0x1
	.4byte	.LASF28
	.byte	0x49
	.byte	0x7
	.4byte	0x43
	.byte	0x74
	.uleb128 0x1
	.4byte	.LASF29
	.byte	0x4a
	.byte	0xb
	.4byte	0x74
	.byte	0x78
	.uleb128 0x1
	.4byte	.LASF30
	.byte	0x4d
	.byte	0x12
	.4byte	0x51
	.byte	0x80
	.uleb128 0x1
	.4byte	.LASF31
	.byte	0x4e
	.byte	0xf
	.4byte	0x5f
	.byte	0x82
	.uleb128 0x1
	.4byte	.LASF32
	.byte	0x4f
	.byte	0x8
	.4byte	0x22a
	.byte	0x83
	.uleb128 0x1
	.4byte	.LASF33
	.byte	0x51
	.byte	0xf
	.4byte	0x23a
	.byte	0x88
	.uleb128 0x1
	.4byte	.LASF34
	.byte	0x59
	.byte	0xd
	.4byte	0x80
	.byte	0x90
	.uleb128 0x1
	.4byte	.LASF35
	.byte	0x5b
	.byte	0x17
	.4byte	0x244
	.byte	0x98
	.uleb128 0x1
	.4byte	.LASF36
	.byte	0x5c
	.byte	0x19
	.4byte	0x24e
	.byte	0xa0
	.uleb128 0x1
	.4byte	.LASF37
	.byte	0x5d
	.byte	0x14
	.4byte	0x225
	.byte	0xa8
	.uleb128 0x1
	.4byte	.LASF38
	.byte	0x5e
	.byte	0x9
	.4byte	0x41
	.byte	0xb0
	.uleb128 0x1
	.4byte	.LASF39
	.byte	0x5f
	.byte	0xa
	.4byte	0x2e
	.byte	0xb8
	.uleb128 0x1
	.4byte	.LASF40
	.byte	0x60
	.byte	0x7
	.4byte	0x43
	.byte	0xc0
	.uleb128 0x1
	.4byte	.LASF41
	.byte	0x62
	.byte	0x8
	.4byte	0x253
	.byte	0xc4
	.byte	0
	.uleb128 0x4
	.4byte	.LASF42
	.byte	0x5
	.byte	0x7
	.byte	0x19
	.4byte	0x9d
	.uleb128 0xf
	.4byte	.LASF51
	.byte	0x4
	.byte	0x2b
	.byte	0xe
	.uleb128 0x5
	.4byte	.LASF43
	.uleb128 0x3
	.4byte	0x21b
	.uleb128 0x3
	.4byte	0x9d
	.uleb128 0x7
	.4byte	0x91
	.4byte	0x23a
	.uleb128 0x8
	.4byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x3
	.4byte	0x213
	.uleb128 0x5
	.4byte	.LASF44
	.uleb128 0x3
	.4byte	0x23f
	.uleb128 0x5
	.4byte	.LASF45
	.uleb128 0x3
	.4byte	0x249
	.uleb128 0x7
	.4byte	0x91
	.4byte	0x263
	.uleb128 0x8
	.4byte	0x3a
	.byte	0x13
	.byte	0
	.uleb128 0x3
	.4byte	0x207
	.uleb128 0x10
	.4byte	.LASF52
	.byte	0x7
	.byte	0x90
	.byte	0xe
	.4byte	0x263
	.uleb128 0x9
	.4byte	.LASF46
	.byte	0x6
	.2byte	0x1d0
	.byte	0x15
	.4byte	0x58
	.4byte	0x28b
	.uleb128 0x6
	.4byte	0x58
	.byte	0
	.uleb128 0x11
	.4byte	.LASF47
	.byte	0x7
	.byte	0xe6
	.byte	0xc
	.4byte	0x43
	.4byte	0x2a1
	.uleb128 0x6
	.4byte	0x263
	.byte	0
	.uleb128 0x9
	.4byte	.LASF48
	.byte	0x7
	.2byte	0x164
	.byte	0xc
	.4byte	0x43
	.4byte	0x2b9
	.uleb128 0x6
	.4byte	0x2b9
	.uleb128 0x12
	.byte	0
	.uleb128 0x3
	.4byte	0x98
	.uleb128 0x13
	.4byte	.LASF53
	.byte	0x1
	.byte	0xa
	.byte	0x5
	.4byte	0x43
	.8byte	.LFB0
	.8byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 4
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x8
	.byte	0
	.2byte	0
	.2byte	0
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.8byte	0
	.8byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF16:
	.string	"_IO_read_base"
.LASF15:
	.string	"_IO_read_end"
.LASF9:
	.string	"size_t"
.LASF50:
	.string	"_IO_FILE"
.LASF17:
	.string	"_IO_write_base"
.LASF21:
	.string	"_IO_buf_end"
.LASF10:
	.string	"__off_t"
.LASF52:
	.string	"stdout"
.LASF39:
	.string	"__pad5"
.LASF34:
	.string	"_offset"
.LASF47:
	.string	"fflush"
.LASF40:
	.string	"_mode"
.LASF11:
	.string	"__off64_t"
.LASF27:
	.string	"_fileno"
.LASF22:
	.string	"_IO_save_base"
.LASF3:
	.string	"unsigned char"
.LASF43:
	.string	"_IO_marker"
.LASF2:
	.string	"long unsigned int"
.LASF4:
	.string	"short unsigned int"
.LASF24:
	.string	"_IO_save_end"
.LASF51:
	.string	"_IO_lock_t"
.LASF25:
	.string	"_markers"
.LASF53:
	.string	"main"
.LASF42:
	.string	"FILE"
.LASF49:
	.string	"GNU C17 11.4.0 -mlittle-endian -mabi=lp64 -g -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection"
.LASF29:
	.string	"_old_offset"
.LASF33:
	.string	"_lock"
.LASF5:
	.string	"unsigned int"
.LASF36:
	.string	"_wide_data"
.LASF12:
	.string	"char"
.LASF44:
	.string	"_IO_codecvt"
.LASF30:
	.string	"_cur_column"
.LASF20:
	.string	"_IO_buf_base"
.LASF28:
	.string	"_flags2"
.LASF31:
	.string	"_vtable_offset"
.LASF45:
	.string	"_IO_wide_data"
.LASF38:
	.string	"_freeres_buf"
.LASF41:
	.string	"_unused2"
.LASF26:
	.string	"_chain"
.LASF14:
	.string	"_IO_read_ptr"
.LASF35:
	.string	"_codecvt"
.LASF48:
	.string	"printf"
.LASF19:
	.string	"_IO_write_end"
.LASF7:
	.string	"short int"
.LASF23:
	.string	"_IO_backup_base"
.LASF13:
	.string	"_flags"
.LASF8:
	.string	"long int"
.LASF18:
	.string	"_IO_write_ptr"
.LASF37:
	.string	"_freeres_list"
.LASF6:
	.string	"signed char"
.LASF46:
	.string	"sleep"
.LASF32:
	.string	"_shortbuf"
	.section	.debug_line_str,"MS",@progbits,1
.LASF0:
	.string	"mytest.c"
.LASF1:
	.string	"/home/yzq0207/Linux/Linux_bit/lesson8_230428/example1"
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
