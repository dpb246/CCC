	.file	"fastMatrix.cpp"
	.text
	.p2align 4,,15
	.globl	__Z17multiply_matricesPA256_dS0_
	.def	__Z17multiply_matricesPA256_dS0_;	.scl	2;	.type	32;	.endef
__Z17multiply_matricesPA256_dS0_:
LFB3616:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$524880, %eax
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-32, %esp
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	leal	592(%esp), %eax
	movl	$524288, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	movl	12(%ebp), %eax
	movl	$0, 120(%esp)
	movl	%eax, 36(%esp)
	movl	120(%esp), %eax
L8:
	addl	$15, %eax
	movl	%eax, 132(%esp)
	leal	592(%esp), %eax
	movl	%eax, 40(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 140(%esp)
	leal	592(%esp), %eax
	movl	%eax, 44(%esp)
L7:
	movl	140(%esp), %eax
	movl	$0, 96(%esp)
	addl	$2048, %eax
	movl	%eax, 136(%esp)
	movl	140(%esp), %eax
	addl	$4096, %eax
	movl	%eax, 124(%esp)
	movl	140(%esp), %eax
	addl	$6144, %eax
	movl	%eax, 128(%esp)
	movl	44(%esp), %eax
	leal	32(%eax), %edx
	leal	2080(%eax), %ecx
	movl	%eax, 104(%esp)
	movl	%edx, 52(%esp)
	leal	64(%eax), %edx
	movl	%ecx, 64(%esp)
	leal	2144(%eax), %ecx
	movl	%edx, 56(%esp)
	leal	96(%eax), %edx
	movl	%ecx, 72(%esp)
	leal	4128(%eax), %ecx
	movl	%edx, 60(%esp)
	leal	2048(%eax), %edx
	movl	%ecx, 76(%esp)
	leal	4192(%eax), %ecx
	movl	%edx, 108(%esp)
	leal	2112(%eax), %edx
	movl	%ecx, 84(%esp)
	leal	6176(%eax), %ecx
	movl	%edx, 68(%esp)
	leal	4096(%eax), %edx
	movl	%ecx, 88(%esp)
	leal	6240(%eax), %ecx
	movl	%edx, 112(%esp)
	leal	4160(%eax), %edx
	movl	%ecx, 48(%esp)
	movl	%edx, 80(%esp)
	leal	6144(%eax), %edx
	movl	%edx, 116(%esp)
	leal	6208(%eax), %edx
	movl	%edx, 92(%esp)
	movl	36(%esp), %edx
	movl	%edx, 100(%esp)
	.p2align 4,,10
L6:
	movl	120(%esp), %eax
	testl	%eax, %eax
	je	L32
	movl	104(%esp), %eax
	vmovapd	(%eax), %ymm7
	vmovapd	32(%eax), %ymm6
	vmovapd	%ymm7, 560(%esp)
	vmovapd	%ymm6, 272(%esp)
	vmovapd	64(%eax), %ymm7
	vmovapd	96(%eax), %ymm6
	movl	108(%esp), %eax
	vmovapd	%ymm7, 528(%esp)
	vmovapd	%ymm6, 432(%esp)
	vmovapd	32(%eax), %ymm7
	vmovapd	96(%eax), %ymm1
	vmovapd	(%eax), %ymm6
	vmovapd	%ymm7, 208(%esp)
	vmovapd	64(%eax), %ymm7
	movl	112(%esp), %eax
	vmovapd	%ymm1, 400(%esp)
	vmovapd	(%eax), %ymm1
	vmovapd	%ymm1, 240(%esp)
	vmovapd	32(%eax), %ymm1
	vmovapd	%ymm1, 144(%esp)
	vmovapd	64(%eax), %ymm1
	vmovapd	%ymm1, 464(%esp)
	vmovapd	96(%eax), %ymm1
	movl	116(%esp), %eax
	vmovapd	%ymm1, 368(%esp)
	vmovapd	(%eax), %ymm1
	vmovapd	%ymm1, 176(%esp)
	vmovapd	32(%eax), %ymm1
	vmovapd	%ymm1, 304(%esp)
	vmovapd	64(%eax), %ymm1
	vmovapd	%ymm1, 496(%esp)
	vmovapd	96(%eax), %ymm1
	vmovapd	%ymm1, 336(%esp)
L3:
	movl	132(%esp), %edi
	movl	120(%esp), %eax
	cmpl	%edi, %eax
	movl	%edi, %ecx
	jg	L4
	movl	100(%esp), %esi
	movl	140(%esp), %ebx
	subl	%eax, %ecx
	vmovapd	560(%esp), %ymm5
	movl	124(%esp), %edx
	andl	$1, %ecx
	vmovupd	(%esi), %ymm4
	vbroadcastsd	(%ebx,%eax,8), %ymm0
	movl	136(%esp), %ebx
	vmovupd	32(%esi), %ymm3
	vmovupd	64(%esi), %ymm2
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovupd	96(%esi), %ymm1
	vmovapd	%ymm5, 560(%esp)
	vmovapd	272(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 272(%esp)
	vmovapd	528(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vfmadd213pd	432(%esp), %ymm1, %ymm0
	vmovapd	%ymm5, 528(%esp)
	vmovapd	%ymm0, 432(%esp)
	vmovapd	208(%esp), %ymm5
	vbroadcastsd	(%ebx,%eax,8), %ymm0
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vfmadd231pd	%ymm0, %ymm4, %ymm6
	vmovapd	%ymm5, 208(%esp)
	vfmadd231pd	%ymm0, %ymm2, %ymm7
	vmovapd	240(%esp), %ymm5
	vfmadd213pd	400(%esp), %ymm1, %ymm0
	vmovapd	%ymm0, 400(%esp)
	vbroadcastsd	(%edx,%eax,8), %ymm0
	movl	128(%esp), %edx
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovapd	%ymm5, 240(%esp)
	vmovapd	144(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 144(%esp)
	vmovapd	464(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vfmadd213pd	368(%esp), %ymm1, %ymm0
	vmovapd	%ymm5, 464(%esp)
	vmovapd	%ymm0, 368(%esp)
	vbroadcastsd	(%edx,%eax,8), %ymm0
	leal	1(%eax), %edx
	leal	2048(%esi), %eax
	cmpl	%edi, %edx
	vfmadd213pd	176(%esp), %ymm0, %ymm4
	vfmadd213pd	304(%esp), %ymm0, %ymm3
	vfmadd213pd	496(%esp), %ymm0, %ymm2
	vfmadd213pd	336(%esp), %ymm0, %ymm1
	vmovapd	%ymm4, 176(%esp)
	vmovapd	%ymm3, 304(%esp)
	vmovapd	%ymm2, 496(%esp)
	vmovapd	%ymm1, 336(%esp)
	jg	L4
	testl	%ecx, %ecx
	je	L5
	movl	140(%esp), %ebx
	vmovupd	(%eax), %ymm4
	movl	100(%esp), %eax
	vmovapd	560(%esp), %ymm5
	movl	124(%esp), %edi
	movl	128(%esp), %ecx
	vbroadcastsd	(%ebx,%edx,8), %ymm0
	movl	136(%esp), %ebx
	vmovupd	2080(%eax), %ymm3
	addl	$4096, %eax
	vmovupd	-1984(%eax), %ymm2
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovupd	-1952(%eax), %ymm1
	vmovapd	%ymm5, 560(%esp)
	vmovapd	272(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 272(%esp)
	vmovapd	528(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vfmadd213pd	432(%esp), %ymm1, %ymm0
	vmovapd	%ymm5, 528(%esp)
	vmovapd	%ymm0, 432(%esp)
	vmovapd	208(%esp), %ymm5
	vbroadcastsd	(%ebx,%edx,8), %ymm0
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vfmadd231pd	%ymm0, %ymm4, %ymm6
	vmovapd	%ymm5, 208(%esp)
	vfmadd231pd	%ymm0, %ymm2, %ymm7
	vmovapd	240(%esp), %ymm5
	vfmadd213pd	400(%esp), %ymm1, %ymm0
	vmovapd	%ymm0, 400(%esp)
	vbroadcastsd	(%edi,%edx,8), %ymm0
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovapd	%ymm5, 240(%esp)
	vmovapd	144(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 144(%esp)
	vmovapd	464(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vfmadd213pd	368(%esp), %ymm1, %ymm0
	vmovapd	%ymm5, 464(%esp)
	vmovapd	%ymm0, 368(%esp)
	vbroadcastsd	(%ecx,%edx,8), %ymm0
	movl	120(%esp), %edx
	vfmadd213pd	176(%esp), %ymm0, %ymm4
	vfmadd213pd	304(%esp), %ymm0, %ymm3
	vfmadd213pd	496(%esp), %ymm0, %ymm2
	vfmadd213pd	336(%esp), %ymm0, %ymm1
	vmovapd	%ymm4, 176(%esp)
	addl	$2, %edx
	cmpl	132(%esp), %edx
	vmovapd	%ymm3, 304(%esp)
	vmovapd	%ymm2, 496(%esp)
	vmovapd	%ymm1, 336(%esp)
	jg	L4
	.p2align 4,,10
L5:
	movl	140(%esp), %esi
	vmovupd	(%eax), %ymm4
	leal	1(%edx), %ecx
	vmovapd	560(%esp), %ymm5
	movl	124(%esp), %edi
	addl	$4096, %eax
	vmovupd	-4064(%eax), %ymm3
	vbroadcastsd	(%esi,%edx,8), %ymm0
	movl	128(%esp), %esi
	vmovupd	-4032(%eax), %ymm2
	vmovupd	-4000(%eax), %ymm1
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovapd	%ymm5, 560(%esp)
	vmovapd	272(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 272(%esp)
	vmovapd	528(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vfmadd213pd	432(%esp), %ymm1, %ymm0
	vmovapd	%ymm5, 528(%esp)
	vmovapd	%ymm0, 432(%esp)
	vmovapd	208(%esp), %ymm5
	vbroadcastsd	(%ebx,%edx,8), %ymm0
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vfmadd231pd	%ymm0, %ymm4, %ymm6
	vfmadd231pd	%ymm0, %ymm2, %ymm7
	vmovapd	%ymm5, 208(%esp)
	vfmadd213pd	400(%esp), %ymm1, %ymm0
	vmovapd	240(%esp), %ymm5
	vmovapd	%ymm0, 400(%esp)
	vbroadcastsd	(%edi,%edx,8), %ymm0
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovapd	%ymm5, 240(%esp)
	vmovapd	144(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 144(%esp)
	vmovapd	464(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vfmadd213pd	368(%esp), %ymm1, %ymm0
	vmovapd	%ymm0, 368(%esp)
	vbroadcastsd	(%esi,%edx,8), %ymm0
	addl	$2, %edx
	vmovapd	%ymm5, 464(%esp)
	vfmadd213pd	176(%esp), %ymm0, %ymm4
	vmovapd	%ymm4, 176(%esp)
	movl	140(%esp), %ebx
	vfmadd213pd	304(%esp), %ymm0, %ymm3
	vfmadd213pd	496(%esp), %ymm0, %ymm2
	vmovapd	%ymm3, 304(%esp)
	vmovapd	%ymm2, 496(%esp)
	vfmadd213pd	336(%esp), %ymm0, %ymm1
	vmovapd	%ymm1, 336(%esp)
	vbroadcastsd	(%ebx,%ecx,8), %ymm0
	vmovupd	-2048(%eax), %ymm4
	vmovapd	560(%esp), %ymm5
	movl	136(%esp), %ebx
	vmovupd	-2016(%eax), %ymm3
	vmovupd	-1984(%eax), %ymm2
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovupd	-1952(%eax), %ymm1
	vmovapd	%ymm5, 560(%esp)
	vmovapd	272(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 272(%esp)
	vmovapd	528(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vmovapd	%ymm5, 528(%esp)
	vmovapd	%ymm0, %ymm5
	vbroadcastsd	(%ebx,%ecx,8), %ymm0
	vfmadd213pd	432(%esp), %ymm1, %ymm5
	vmovapd	%ymm5, 432(%esp)
	vmovapd	208(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm4, %ymm6
	vfmadd231pd	%ymm0, %ymm2, %ymm7
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 208(%esp)
	vmovapd	%ymm0, %ymm5
	vbroadcastsd	(%edi,%ecx,8), %ymm0
	vfmadd213pd	400(%esp), %ymm1, %ymm5
	vmovapd	%ymm5, 400(%esp)
	vmovapd	240(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm4, %ymm5
	vmovapd	%ymm5, 240(%esp)
	vmovapd	144(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm3, %ymm5
	vmovapd	%ymm5, 144(%esp)
	vmovapd	464(%esp), %ymm5
	vfmadd231pd	%ymm0, %ymm2, %ymm5
	vmovapd	%ymm5, 464(%esp)
	vfmadd213pd	368(%esp), %ymm1, %ymm0
	cmpl	132(%esp), %edx
	vmovapd	%ymm0, 368(%esp)
	vmovapd	%ymm3, %ymm5
	vbroadcastsd	(%esi,%ecx,8), %ymm0
	vfmadd213pd	176(%esp), %ymm0, %ymm4
	vmovapd	%ymm4, 176(%esp)
	vmovapd	%ymm2, %ymm4
	vfmadd213pd	304(%esp), %ymm0, %ymm5
	vfmadd213pd	336(%esp), %ymm0, %ymm1
	vmovapd	%ymm5, 304(%esp)
	vfmadd213pd	496(%esp), %ymm0, %ymm4
	vmovapd	%ymm1, 336(%esp)
	vmovapd	%ymm4, 496(%esp)
	jle	L5
L4:
	movl	104(%esp), %eax
	vmovapd	560(%esp), %ymm1
	vmovupd	%ymm1, (%eax)
	movl	52(%esp), %edx
	vmovapd	272(%esp), %ymm1
	subl	$-128, %edx
	vmovupd	%ymm1, -128(%edx)
	movl	56(%esp), %ecx
	vmovapd	528(%esp), %ymm1
	subl	$-128, %ecx
	vmovupd	%ymm1, -128(%ecx)
	movl	60(%esp), %esi
	vmovapd	432(%esp), %ymm1
	subl	$-128, %esi
	vmovupd	%ymm1, -128(%esi)
	movl	108(%esp), %eax
	vmovupd	%ymm6, (%eax)
	movl	64(%esp), %eax
	vmovapd	208(%esp), %ymm6
	vmovupd	%ymm6, (%eax)
	movl	68(%esp), %eax
	vmovupd	%ymm7, (%eax)
	movl	72(%esp), %eax
	vmovapd	400(%esp), %ymm7
	vmovupd	%ymm7, (%eax)
	movl	112(%esp), %eax
	vmovapd	240(%esp), %ymm6
	vmovupd	%ymm6, (%eax)
	movl	76(%esp), %eax
	vmovapd	144(%esp), %ymm7
	vmovupd	%ymm7, (%eax)
	movl	80(%esp), %eax
	vmovapd	464(%esp), %ymm6
	vmovupd	%ymm6, (%eax)
	movl	84(%esp), %eax
	vmovapd	368(%esp), %ymm7
	vmovupd	%ymm7, (%eax)
	movl	116(%esp), %eax
	vmovapd	176(%esp), %ymm6
	vmovupd	%ymm6, (%eax)
	movl	88(%esp), %eax
	vmovapd	304(%esp), %ymm7
	vmovupd	%ymm7, (%eax)
	movl	92(%esp), %edi
	vmovapd	496(%esp), %ymm6
	subl	$-128, %edi
	vmovupd	%ymm6, -128(%edi)
	movl	48(%esp), %eax
	vmovapd	336(%esp), %ymm7
	subl	$-128, %eax
	vmovupd	%ymm7, -128(%eax)
	movl	%edx, 52(%esp)
	addl	$16, 96(%esp)
	subl	$-128, 104(%esp)
	movl	%ecx, 56(%esp)
	subl	$-128, 108(%esp)
	subl	$-128, 64(%esp)
	subl	$-128, 68(%esp)
	subl	$-128, 72(%esp)
	movl	%esi, 60(%esp)
	subl	$-128, 112(%esp)
	subl	$-128, 76(%esp)
	subl	$-128, 80(%esp)
	subl	$-128, 84(%esp)
	movl	%edi, 92(%esp)
	subl	$-128, 116(%esp)
	movl	%eax, 48(%esp)
	subl	$-128, 88(%esp)
	subl	$-128, 100(%esp)
	cmpl	$256, 96(%esp)
	jne	L6
	addl	$8192, 44(%esp)
	leal	524880(%esp), %edi
	addl	$8192, 140(%esp)
	movl	44(%esp), %eax
	cmpl	%eax, %edi
	jne	L7
	addl	$16, 120(%esp)
	addl	$32768, 36(%esp)
	movl	120(%esp), %eax
	cmpl	$256, %eax
	jne	L8
	vxorpd	%xmm1, %xmm1, %xmm1
	movl	40(%esp), %eax
L10:
	leal	2048(%eax), %edx
L9:
	movl	40(%esp), %edi
	vmovsd	(%edi), %xmm0
	movl	%edi, %eax
	addl	$64, %eax
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	8(%edi), %xmm0
	cmpl	%eax, %edx
	movl	%eax, 40(%esp)
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	16(%edi), %xmm0
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	24(%edi), %xmm0
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	32(%edi), %xmm0
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	40(%edi), %xmm0
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	48(%edi), %xmm0
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	vmovsd	56(%edi), %xmm0
	vfmadd231sd	%xmm0, %xmm0, %xmm1
	jne	L9
	movl	44(%esp), %ebx
	movl	%edx, %eax
	movl	%edx, 40(%esp)
	cmpl	%ebx, %edx
	jne	L10
	vmovsd	%xmm1, 560(%esp)
	vzeroupper
	fldl	560(%esp)
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
L32:
	.cfi_restore_state
	vxorpd	%xmm6, %xmm6, %xmm6
	vmovapd	%ymm6, 336(%esp)
	vmovapd	%ymm6, %ymm7
	vmovapd	%ymm6, 368(%esp)
	vmovapd	%ymm6, 400(%esp)
	vmovapd	%ymm6, 432(%esp)
	vmovapd	%ymm6, 496(%esp)
	vmovapd	%ymm6, 464(%esp)
	vmovapd	%ymm6, 528(%esp)
	vmovapd	%ymm6, 304(%esp)
	vmovapd	%ymm6, 176(%esp)
	vmovapd	%ymm6, 144(%esp)
	vmovapd	%ymm6, 240(%esp)
	vmovapd	%ymm6, 208(%esp)
	vmovapd	%ymm6, 272(%esp)
	vmovapd	%ymm6, 560(%esp)
	jmp	L3
	.cfi_endproc
LFE3616:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_memset;	.scl	2;	.type	32;	.endef
