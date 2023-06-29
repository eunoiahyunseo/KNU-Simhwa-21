# -------------------------------------------------------------------
# [KNU COMP411 Computer Architecture] Skeleton code for the 1st project (calculator)
#      author: 201911920_Dohyun_Kim
# Description: calculator for scoring by procedure test in common.asm
#              and not using any console input (console-related instruction is fully deleted)
# -------------------------------------------------------------------

.data
str: .space 400

.text
# main
main:
	
	jal x1, test #functionality test, Do not modify!!
	
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
	
	j calc_ret
	
calc_sub:
	# sub a0, a2, a3
	add t5, zero, a3
	add a0, zero, a2
calc_sub_loop:
	addi a0, a0, -1
	addi t5, t5, -1
	bnez t5, calc_sub_loop
	
	j calc_ret
	
calc_multi:
	# mul a0, a2, a3
	add t5, zero, a2
calc_multi_loop:
	add a0, a0, a3
	addi t5, t5, -1
	bnez t5, calc_multi_loop
	
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
	
	j calc_ret
	
calc_ret:
	
	jalr x0, 0(x1)


.include "common.asm"
