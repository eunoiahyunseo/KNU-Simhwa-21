.globl main
.data
.eqv	MAX_BUFFER_SIZE 512
.eqv 	ZERO 0
.eqv 	INSTRUCTION_BYTE 4
.eqv	BASE_OF_OPERAND 48
.eqv	ASCII_OF_MULTIPLY 120
.eqv 	ASCII_OF_PLUS 43
.eqv 	ASCII_OF_MINUS 45
.eqv 	ASCII_OF_DIVISION 47
.eqv	ASCII_OF_EQAUL 61
.eqv	BASE_OF_BUFFER	s0
.eqv 	BUFFER_INDEX_COUNTER s1
.eqv 	RESULT_REGISTER s2
.eqv	TEMP t4
.eqv	TEMP2 t2
.eqv	TEMP3 t6
# to get user input declare global variable buffer1
inputBuffer:
	# max character length is 512 -> that's condition of homework ( .space directive's unit is byte )
	.space MAX_BUFFER_SIZE
sharp:
	# .string directive is diff with .asciz with NULL
	.string "# "
	
inputBufferCounter:
	.word ZERO

# body of assembly main code	
.text 
main:
	# print "# " to get user's input
	la 	a0, sharp
	li 	a7, 4
	ecall
	
	# get user's input in buffer
	la 	a0, inputBuffer
	li 	a1, 512
	# system call code 8is ReadString
	# a0 -> address of input buffer
	# a1 -> maximum number of characters to read
	# not outputs
	li 	a7, 8
	ecall
	
	# print buffer what we have to calculate
	la 	a0, inputBuffer
	li	a7, 4
	ecall
	
	# set register's role
	la 	BASE_OF_BUFFER, inputBuffer
	li	BUFFER_INDEX_COUNTER, 0
	lb 	BUFFER_INDEX_COUNTER, inputBufferCounter

	# reset the argument for next system-call 
	li	a0, ZERO
	li	a1, ZERO
	
	li 	t3, 0
	li	t5, 0
	
	
get_operand:
	# testcase1: 12+21=
	add	TEMP, BASE_OF_BUFFER, BUFFER_INDEX_COUNTER
	lb	TEMP2, ZERO(TEMP)
	
	# there's exception because ascii code 'x' is 120
	# so operand is 120 go to operate loop
	li 	TEMP, ASCII_OF_MULTIPLY
	beq 	TEMP, TEMP2, operate
	
	# if not found operator
	li	TEMP, BASE_OF_OPERAND
	bge 	TEMP2, TEMP, get_operand_loop
	
	jal 	x0, operate
	

get_operand_loop:
	# seperate t3 value from TEMP2
	
	# t3 * 10 + [ incoming t3 ]
	li	TEMP, 10
	mul	t3, t3, TEMP
	
	add	TEMP, BASE_OF_BUFFER, BUFFER_INDEX_COUNTER	
	lb	TEMP2, ZERO(TEMP)
	add	t3, t3, TEMP2
	
	# t3 - 48 ('0') -> because actual number save in t3
	li 	TEMP, BASE_OF_OPERAND
	sub 	TEMP, x0, TEMP
	add	t3, t3, TEMP
	
	# BUFFER_INDEX_COUNTER++
	addi BUFFER_INDEX_COUNTER, BUFFER_INDEX_COUNTER, 1
	
	jal 	x0, get_operand

get_operand_loop_v2:
	# BUFFER_INDEX_COUNTER++
	addi BUFFER_INDEX_COUNTER, BUFFER_INDEX_COUNTER, 1
	
	# get first operand
	add	TEMP, BASE_OF_BUFFER, BUFFER_INDEX_COUNTER	
	lb	TEMP2, ZERO(TEMP)
	
	# go to back if TEMP is operator
	# we guess that's operand ( we have to handle 'x' operator )
	li 	TEMP, ASCII_OF_MULTIPLY
	beq	TEMP, TEMP2, back
	
	li 	TEMP, BASE_OF_OPERAND
	blt	TEMP2, TEMP, back
	
	li	TEMP, ASCII_OF_EQAUL
	beq	TEMP, TEMP2, back
	
	# almost same with upper one
	li	TEMP, 10
	mul	t5, t5, TEMP
	
	add	TEMP, BASE_OF_BUFFER, BUFFER_INDEX_COUNTER	
	lb	TEMP2, ZERO(TEMP)
	add	t5, t5, TEMP2
	
	# t5 - 48 ('0') -> because actual number save in t5
	li 	TEMP, BASE_OF_OPERAND
	sub 	TEMP, x0, TEMP
	add	t5, t5, TEMP
	
	jal	x0, get_operand_loop_v2
	
back:
	jalr 	x0, 0(x1)

operate:
	add	TEMP, BASE_OF_BUFFER, BUFFER_INDEX_COUNTER	
	lb	TEMP2, ZERO(TEMP)
	
	li	TEMP, ASCII_OF_EQAUL
	beq	TEMP, TEMP2, exit
	
	li 	TEMP, ASCII_OF_PLUS
	beq 	TEMP, TEMP2, operate_plus
	
	li 	TEMP, ASCII_OF_MINUS
	beq 	TEMP, TEMP2, operate_minus
	
	li 	TEMP, ASCII_OF_MULTIPLY
	beq 	TEMP, TEMP2, operate_multiply
	
	li 	TEMP, ASCII_OF_DIVISION
	beq 	TEMP, TEMP2, operate_divide
	
	
operate_plus:
	# get second operand ( second operand is in t5 )
	jal	x1, get_operand_loop_v2
	
	# a0 is accumulated and a1 is temporary
	
	# t3 -> 12, t5 -> 21
	add	t3, t3, t5
	add	a0, x0, t3
	
	jal	x0, print_result
	
operate_minus:
	jal	x1, get_operand_loop_v2
	
	sub	t3, t3, t5
	add	a0, x0, t3
	
	jal	x0, print_result
	
operate_multiply:
	jal	x1, get_operand_loop_v2
	
	mul	t3, t3, t5
	add	a0, x0, t3
	
	jal	x0, print_result
	
	
operate_divide:
	jal	x1, get_operand_loop_v2
	
	div	t3, t3, t5
	add	a0, x0, t3
	
	jal	x0, print_result
	
	
	
print_result:
	# print a0 ( step by step )
	li	a7, 1
	ecall
	
	# print '\n'
	li	a0, 10
	li 	a7, 11
	ecall
	
	li	t5, ZERO
	jal 	x0, operate
	
exit:
	li 	a7, 10
	ecall
