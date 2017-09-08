# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.asm                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 17:06:14 by ymukmar           #+#    #+#              #
#    Updated: 2017/08/15 12:23:34 by ymukmar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.data
	SYS_WRITE	equ	0x2000004
	SYS_READ	equ	0x2000003
	STD_OUT		equ	1

section	.bss

buff: resb	512

section	.text
	global	_ft_cat

_ft_cat:
	lea		rsi, [rel buff]
	mov		rdx, 512
	mov		rax, SYS_READ
	syscall
	jc		_fn_ret
	cmp		rax, 0
	jle		_fn_ret
	push	rdi
	mov		rdi, STD_OUT
	mov		rdx, rax
	mov		rax, SYS_WRITE
	syscall
	pop		rdi
	jmp		_ft_cat

_fn_ret:
	mov		rax, 0
	ret
