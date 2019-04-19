	.file	"ext.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.rodata
	.type	A0, @object
	.size	A0, 1
A0:
	.byte	1
	.type	A1, @object
	.size	A1, 1
A1:
	.byte	2
	.type	A2, @object
	.size	A2, 1
A2:
	.byte	4
	.type	A3, @object
	.size	A3, 1
A3:
	.byte	8
	.type	A4, @object
	.size	A4, 1
A4:
	.byte	16
	.type	A5, @object
	.size	A5, 1
A5:
	.byte	32
	.type	A6, @object
	.size	A6, 1
A6:
	.byte	64
	.type	A7, @object
	.size	A7, 1
A7:
	.byte	-128
	.type	B0, @object
	.size	B0, 1
B0:
	.byte	1
	.type	B1, @object
	.size	B1, 1
B1:
	.byte	2
	.type	B2, @object
	.size	B2, 1
B2:
	.byte	4
	.type	B3, @object
	.size	B3, 1
B3:
	.byte	8
	.type	B4, @object
	.size	B4, 1
B4:
	.byte	16
	.type	B5, @object
	.size	B5, 1
B5:
	.byte	32
	.type	B6, @object
	.size	B6, 1
B6:
	.byte	64
	.type	B7, @object
	.size	B7, 1
B7:
	.byte	-128
	.type	C0, @object
	.size	C0, 1
C0:
	.byte	1
	.type	C1, @object
	.size	C1, 1
C1:
	.byte	2
	.type	C2, @object
	.size	C2, 1
C2:
	.byte	4
	.type	C3, @object
	.size	C3, 1
C3:
	.byte	8
	.type	C4, @object
	.size	C4, 1
C4:
	.byte	16
	.type	C5, @object
	.size	C5, 1
C5:
	.byte	32
	.type	C6, @object
	.size	C6, 1
C6:
	.byte	64
	.type	C7, @object
	.size	C7, 1
C7:
	.byte	-128
	.type	D0, @object
	.size	D0, 1
D0:
	.byte	1
	.type	D1, @object
	.size	D1, 1
D1:
	.byte	2
	.type	D2, @object
	.size	D2, 1
D2:
	.byte	4
	.type	D3, @object
	.size	D3, 1
D3:
	.byte	8
	.type	D4, @object
	.size	D4, 1
D4:
	.byte	16
	.type	D5, @object
	.size	D5, 1
D5:
	.byte	32
	.type	D6, @object
	.size	D6, 1
D6:
	.byte	64
	.type	D7, @object
	.size	D7, 1
D7:
	.byte	-128
	.type	E0, @object
	.size	E0, 1
E0:
	.byte	1
	.type	E1, @object
	.size	E1, 1
E1:
	.byte	2
	.type	E2, @object
	.size	E2, 1
E2:
	.byte	4
	.type	E3, @object
	.size	E3, 1
E3:
	.byte	8
	.type	E4, @object
	.size	E4, 1
E4:
	.byte	16
	.type	E5, @object
	.size	E5, 1
E5:
	.byte	32
	.type	E6, @object
	.size	E6, 1
E6:
	.byte	64
	.type	E7, @object
	.size	E7, 1
E7:
	.byte	-128
	.type	F0, @object
	.size	F0, 1
F0:
	.byte	1
	.type	F1, @object
	.size	F1, 1
F1:
	.byte	2
	.type	F2, @object
	.size	F2, 1
F2:
	.byte	4
	.type	F3, @object
	.size	F3, 1
F3:
	.byte	8
	.type	F4, @object
	.size	F4, 1
F4:
	.byte	16
	.type	F5, @object
	.size	F5, 1
F5:
	.byte	32
	.type	F6, @object
	.size	F6, 1
F6:
	.byte	64
	.type	F7, @object
	.size	F7, 1
F7:
	.byte	-128
	.text
.global	foo
	.type	foo, @function
foo:
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
/* epilogue start */
	pop r29
	pop r28
	ret
	.size	foo, .-foo
	.ident	"GCC: (GNU) 4.9.2"
.global __do_copy_data
