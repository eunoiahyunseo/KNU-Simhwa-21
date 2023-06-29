# computer architecture risc-v assembly programming assignment
# date: 31-10-2021 18:12
# student code: 2020111854
# writer: shin chan-gyu
# description: calculate the expression entered by the user
# attention: this programm can only process +, -, x and /

.data
exp: .asciz "Expression: "
rec: .asciz "Received: "
buf: .space 512

.text
main:
	# print "Expression: "
	la a0, exp
	li a7, 4
	ecall
 	
  	# get user input (expression)
  	la a0, buf
  	li a1, 512
  	li a7, 8
  	ecall
  
  	# print "Received: "
  	la a0, rec
  	li a7, 4
  	ecall
 
  	# print user input
  	la a0, buf
  	li a7, 4
  	ecall
  	
  	# t0: buffer pointer
  	la t0, buf
  	
  	li a0, 0
	li a1, 0

get_operand:  
	# t2 = buf[ptr]
 	lb t2, 0(t0)
 	
 	# go to calculate if buf[ptr] is operator 'x'
 	li t1, 120
 	beq t2, t1, calculate
 	
 	# else go to get_operand_loop if buf[ptr] is number
 	li t1, 48
 	bge t2, t1, get_operand_loop
 	
 	# go to calculate if buf[ptr] is other opeartor 
	jal x0, calculate
	
get_operand_loop:
 	# a0 = a0 * 10
 	li t1, 10
	mul a0, a0, t1
	
	# a0 = a0 + buf[ptr] - '0'
	lb t1, 0(t0)
	add a0, a0, t1
	addi a0, a0, -48
	
	# ptr++
	addi t0, t0, 1
	
	jal x0, get_operand

calculate:
	# t2 = buf[ptr] (it's operator)
	# branch according operator
	li t3, 61               # =
	beq t2, t3, exit
	li t3, 43		# +
 	beq t2, t3, cal_plus
 	li t3, 45		# -
 	beq t2, t3, cal_minus
 	li t3, 120		# x
 	beq t2, t3, cal_times
 	li t3, 47		# /
 	beq t2, t3, cal_divide

cal_plus:
	jal x1, get_second_operand_loop
	add a0, a0, a1
	li a1, 0
	jal x0, print

cal_minus:
	jal x1, get_second_operand_loop
	sub a0, a0, a1
	li a1, 0
	jal x0, print
	
cal_times:
	jal x1, get_second_operand_loop
	mul a0, a0, a1
	li a1, 0
	jal x0, print
	
cal_divide:
	jal x1, get_second_operand_loop
	div a0, a0, a1
	li a1, 0
	jal x0, print

get_second_operand_loop:
	# ptr++
	addi t0, t0, 1
	
	# t1 = buf[ptr]
	lb t1, 0(t0)
	
	# go to return if buf[ptr] is operator
	li t2, 48
	blt t1, t2, return
	li t2, 120
	beq t1, t2, return
	
	# else go to exit if buf[ptr] is '='
	li t2, 61
	beq t1, t2, return

	# else (buf[ptr] is number)
	# a1 = a1 * 10
	li t1, 10
	mul a1, a1, t1	
	
	# a1 = a1 + buf[ptr]	
	lb t1, 0(t0)
	add a1, a1, t1		
	addi a1, a1, -48

	jal x0, get_second_operand_loop

return:
	# t2 = buf[ptr] (it's operator)
	addi t2, t1, 0
	jalr x0, 0(x1)

print:
	# print result
	li a7, 1
 	ecall
 	
	# print '\n'
 	addi t4, a0, 0
 	li a0, 10
 	li a7, 11
 	ecall
 	addi a0, t4, 0
 	
 	jal x0, calculate
 	
exit:
	li a7, 10
	ecall
