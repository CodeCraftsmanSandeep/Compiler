	.file	1 "sample.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.globl	a
	.section	.bss,"aw",@nobits
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.space	4
	.globl	b
	.align	2
	.type	b, @object
	.size	b, 4
b:
	.space	4
	.globl	arr
	.align	2
	.type	arr, @object
	.size	arr, 40
arr:
	.space	40
	.globl	c
	.align	2
	.type	c, @object
	.size	c, 4
c:
	.space	4
	.globl	d
	.align	2
	.type	d, @object
	.size	d, 4
d:
	.space	4
	.rdata
	.align	2
$LC0:
	.ascii	"%d%d%d%d\000"
	.align	2
$LC1:
	.ascii	"%d \012\000"
	.align	2
$LC2:
	.ascii	" %d \012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 0, regs= 2/0, args= 24, gp= 8
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
	.cprestore	24
	lui	$2,%hi(d)
	addiu	$2,$2,%lo(d)
	sw	$2,16($sp)
	lui	$2,%hi(c)
	addiu	$7,$2,%lo(c)
	lui	$2,%hi(b)
	addiu	$6,$2,%lo(b)
	lui	$2,%hi(a)
	addiu	$5,$2,%lo(a)
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(__isoc99_scanf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,__isoc99_scanf
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi(a)
	lw	$3,%lo(a)($2)
	lui	$2,%hi(b)
	lw	$2,%lo(b)($2)
	slt	$2,$2,$3
	beq	$2,$0,$L2
	nop

	lui	$2,%hi(a)
	lw	$3,%lo(a)($2)
	lui	$2,%hi(c)
	sw	$3,%lo(c)($2)
	.option	pic0
	b	$L3
	nop

	.option	pic2
$L2:
	lui	$2,%hi(b)
	lw	$3,%lo(b)($2)
	lui	$2,%hi(c)
	sw	$3,%lo(c)($2)
$L3:
	lui	$2,%hi(c)
	lw	$2,%lo(c)($2)
	move	$5,$2
	lui	$2,%hi($LC1)
	addiu	$4,$2,%lo($LC1)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi(arr)
	li	$3,20			# 0x14
	sw	$3,%lo(arr)($2)
	lui	$2,%hi(arr)
	lw	$2,%lo(arr)($2)
	move	$5,$2
	lui	$2,%hi($LC2)
	addiu	$4,$2,%lo($LC2)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,24($fp)
	lui	$2,%hi(arr)
	addiu	$2,$2,%lo(arr)
	li	$3,20			# 0x14
	sw	$3,8($2)
	lui	$2,%hi(arr)
	addiu	$2,$2,%lo(arr)
	li	$3,30			# 0x1e
	sw	$3,12($2)
	lui	$2,%hi(arr)
	addiu	$2,$2,%lo(arr)
	lw	$2,12($2)
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
