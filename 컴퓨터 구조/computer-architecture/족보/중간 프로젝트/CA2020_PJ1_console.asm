# -------------------------------------------------------------------
# [KNU COMP411 Computer Architecture] Skeleton code for the 1st project (calculator)
#      author: 201911920_Dohyun_Kim
# Description: calculator using console mode, input operands and operation from the console
#              and not call the procedure named test in common.asm (instruction is commented)
# -------------------------------------------------------------------

.data
str: .space 400

.text
# main
main:
	
##	jal x1, test #functionality test, Do not modify!!
		
	#----TODO-------------------------------------------------------------
	#1. read a string from the console
	#2. perform arithmetic operations
	#3. print a string to the console to show the computation result
	#----------------------------------------------------------------------
	

	# ReadString
	# a0: address of input buffer
	# a1: maximum number of characters to read
	li a7, 8
	la a0, str
	li a1, 200
	ecall
	
	li a1, 0
	li a2, 0
	li a3, 0
	
	la t0, str	# t0 is string pointer
main_L1:
	li t1, 48
	lb t2, 0(t0)
	bge t2, t1, main_L2	# branch if first operand
	li t1, 43
	beq t2, t1, main_add
	li t1, 45
	beq t2, t1, main_sub
	li t1, 42
	beq t2, t1, main_multi
	li t1, 47
	beq t2, t1, main_div
	
main_L2:
	li t1, 10
	mul a2, a2, t1		# a2 *= 10
	lb t1, 0(t0)
	add a2, a2, t1		# a2 += '3'
	addi a2, a2, -48	# a2 -= '0'
	addi t0, t0, 1		# t0 += 1
	j   main_L1

main_add:
	li a1, 0
	j main_L3
main_sub:
	li a1, 1
	j main_L3
main_multi:
	li a1, 2
	j main_L3
main_div:
	li a1, 3
	j main_L3

main_L3:		# second operand
	addi t0, t0, 1		# t0 += 1
	lb t1, 0(t0)
	li t2, 10
	beq t1, t2, main_L4	# if t0 == '\n', break

	li t1, 10
	mul a3, a3, t1		# a3 *= 10
	lb t1, 0(t0)
	add a3, a3, t1		# a3 += '5'
	addi a3, a3, -48	# a3 -= '0'

	j   main_L3
	
main_L4:
	
	# Print Inputs
	la t0, str
	li t2, 10
main_L5:
	li a7, 11
	lb a0, 0(t0)
	ecall
	addi t0, t0, 1
	
	lb t1, 0(t0)
	bne t1, t2, main_L5
	
	
	jal x1, calc
	
	# Exit (93) with code 0
        li a0, 0
        li a7, 93
        ecall
        ebreak


#----------------------------------
#name: calc
#func: performs arithmetic operation
#x11(a1): arithmetic operation (0: addition, 1:  subtraction, 2:  multiplication, 3: division)
#x12(a2): the first operand
#x13(a3): the second operand
#x10(a0): return value
#x14(a4): return value (remainder for division operation)
#----------------------------------
calc:
	# PrintChar '='
	li a7, 11
	li a0, 61
	ecall
	
	addi a0, zero, 0
	addi a4, zero, 0
	
	add t6, zero, a1
	
	beqz t6, calc_add
	addi t6, t6, -1
	beqz t6, calc_sub
	addi t6, t6, -1
	beqz t6, calc_multi
	addi t6, t6, -1
	beqz t6, calc_div
	
calc_add:
	add a0, a2, a3
	
	# PrintInt
	li a7, 1
	ecall
	
	j calc_ret
	
calc_sub:
	# sub a0, a2, a3
	add t5, zero, a3
	add a0, zero, a2
calc_sub_loop:
	addi a0, a0, -1
	addi t5, t5, -1
	bnez t5, calc_sub_loop
	
	# PrintInt
	li a7, 1
	ecall
	
	j calc_ret
	
calc_multi:
	# mul a0, a2, a3
	add t5, zero, a2
calc_multi_loop:
	add a0, a0, a3
	addi t5, t5, -1
	bnez t5, calc_multi_loop

	# PrintInt
	li a7, 1
	ecall
	
	j calc_ret
	
calc_div:
	# div a0, a2, a3
	add a4, zero, a2
calc_div_loop:
	bgt a3, a4, calc_div_loop_end	 # division end

	# sub a4, a4, a3
	add t5, zero, a3
calc_div_loop2:
	addi a4, a4, -1
	addi t5, t5, -1
	bnez t5, calc_div_loop2
	
	
	addi a0, a0, 1
	j calc_div_loop
	
calc_div_loop_end:
	
	# PrintInt
	li a7, 1
	ecall
	
	# TODO: print mod number (a4)
	
	j calc_ret
	
calc_ret:
	
	jalr x0, 0(x1)


#.include "common.asm"
