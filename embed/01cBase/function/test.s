	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"test.c"
.LC1:
	.string	"%s %s, %d\n"
.LC2:
	.string	"m=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	$624, 44(%esp)
	addl	$1, 44(%esp)
	movl	$14, 12(%esp)
	movl	$__FUNCTION__.2867, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	fildl	44(%esp)
	fstpl	(%esp)
	call	sqrt
	fnstcw	30(%esp)
	movzwl	30(%esp), %eax
	movb	$12, %ah
	movw	%ax, 28(%esp)
	fldcw	28(%esp)
	fistpl	44(%esp)
	fldcw	30(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	__FUNCTION__.2867, @object
	.size	__FUNCTION__.2867, 5
__FUNCTION__.2867:
	.string	"main"
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
