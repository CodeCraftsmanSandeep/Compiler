	.file	1 "s5.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.globl	a
	.data
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.word	5
	.globl	b
	.align	2
	.type	b, @object
	.size	b, 4
b:
	.word	10
	.globl	arr
	.section	.bss,"aw",@nobits
	.align	2
	.type	arr, @object
	.size	arr, 60
arr:
	.space	60
	.rdata
	.align	2
$LC0:
	.ascii	"%d\012\000"
	.align	2
$LC1:
	.ascii	"s = %d\012\000"
	.align	2
$LC2:
	.ascii	"z = %d\012\000"
	.align	2
$LC3:
	.ascii	"e = %d\012\000"
	.align	2
$LC4:
	.ascii	"f = %d\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	li	$5,2			# 0x2
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$5,3			# 0x3
	lui	$2,%hi($LC1)
	addiu	$4,$2,%lo($LC1)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$5,3			# 0x3
	lui	$2,%hi($LC2)
	addiu	$4,$2,%lo($LC2)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$5,3			# 0x3
	lui	$2,%hi($LC3)
	addiu	$4,$2,%lo($LC3)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$5,3			# 0x3
	lui	$2,%hi($LC4)
	addiu	$4,$2,%lo($LC4)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$0,28($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
