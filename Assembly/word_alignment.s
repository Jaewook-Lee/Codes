	.data 0x10010000
a:
	.byte 1
	.byte -2
	.space 3
	.byte 's'

w1:
	.word 1
	.word -1
	.word 0xabcdfe12
	.word 0xffff

	.text
	.globl main

main:
	la $5, a
	la $6, w1
	lw $4, 0($6)
