# -------------------------------------------------------------------
# [KNU COMP411 Computer Architecture] Test code for the 1st project (calculator)
# -------------------------------------------------------------------

.data
mul_str: .string "multiplication "
add_str: .string "addition "
sub_str: .string "subtraction "
div_str: .string "division "
success_str: .string "success counts:"
total_testnum_str: .string "/100"
.align 2

int_input1: .space 400		#reserve memory space to store the input values for the test
int_input2: .space 400



.text
##----------------------------------
#name: init_test
#func: initialize input values that will be used for test
#----------------------------------
init_test:
	addi t0, zero, 221		#1st operand
	addi t1, zero, 10		#2nd operand
	addi t2, zero, 100		#iteration count
	la t3, int_input1		#base address for 1st operand
	la t4, int_input2		#base address for 2nd operand
	init_test_loop:
	sw t0, 0(t3)
	sw t1, 0(t4)
	addi t0, t0, 1
	addi t1, t1, 1
	addi t3, t3, 4
	addi t4, t4, 4
	addi t2, t2, -1
	bne t2, zero, init_test_loop
	jalr zero, 0(ra)
	

##----------------------------------
#name: test_core
#func: core procedure of basic functionality test	
#x10(a0): result
#x11(a1): arithmetic operation (0: addition, 1:  subtraction, 2:  multiplication, 3: division)

#----------------------------------
test_core:
	addi sp, sp, -88			#adjust stack pointer
	sw ra, 0(sp)				#push register values to stack
	sw a0, 8(sp)
	sw a1, 16(sp)
	sw a2, 24(sp)
	sw a3, 32(sp)
	sw a4, 40(sp)
	sw a5, 48(sp)
	sw s0, 56(sp)
	sw s1, 64(sp)
	sw s2, 72(sp)
	sw s3, 80(sp)
	
	#test for integer arithmetic
	addi s3, zero, 0				#test success count
	addi s0, zero, 100				#set the number of test
	la s1, int_input1				#store the base oddress array input1 in x6
	la s2, int_input2				#store the base oddress array input1 in x7
	
	test_loop:
	lw a2, 0(s1)				#load input1 to x12 (a2)
	lw a3, 0(s2)				#load input2 to x13 (a3)
	
	
	addi t0, zero, 0
	bne a1, t0, get_answer_sub
	get_answer_add:
	add t1, a2, a3
	beq zero,zero, get_answer_done
	get_answer_sub:
	addi t0, zero, 1
	bne a1, t0, get_answer_mul
	sub t1, a2, a3
	beq zero,zero, get_answer_done
	get_answer_mul:
	addi t0, zero, 2
	bne a1, t0, get_answer_div
	mul t1, a2, a3
	beq zero,zero, get_answer_done
	get_answer_div:
	addi t0, zero, 3
	bne a1, t0, get_answer_done
	div t1, a2, a3
	rem t2, a2, a3
	
	get_answer_done: 
	jal ra, calc				#call calc()
	bne a0, t1, test_done			#check if the result of calc is correct
	addi s3, s3, 1				#increase the success count if the result is correct
	addi t0, zero, 3			#if the operation is division, check the remainer as well
	bne a1, t0, test_done			
	beq a4, t2, test_done			#decrease the success count if the remainder is not correct
	addi s3, s3, -1			
	test_done:		
	add a5, zero, s3			#store an argument (success count) in a5
	jal x1, print_test_message		#call print_test_message
	addi x6, x6, 4				#increase base address of the array input1 by 4
	addi x7, x7, 4				#increase base address of the array input2 by 4
	addi s0, s0, -1				#decrease loop count
	addi s1, s1, 4				#increase the index for input1
	addi s2, s2, 4				#increase the index for input2
	bne s0, x0, test_loop
	
	
	lw ra, 0(sp)				#pop register values from stack
	lw a0, 8(sp)
	lw a1, 16(sp)
	lw a2, 24(sp)
	lw a3, 32(sp)
	lw a4, 40(sp)
	lw a5, 48(sp)
	lw s0, 56(sp)
	lw s1, 64(sp)
	lw s2, 72(sp)
	lw s3, 80(sp)	
	addi sp, sp, 88				#adjust stack pointer	
	jalr zero, 0(ra)
	
##----------------------------------
#name: test
#func: functional test	
#x11: arithmetic operation (0:addition, 1: subtraction, 2: multiplication, 3: division)
#x12: result calculated with the calc
#----------------------------------
test:
	addi sp, sp, -16
	sd a1, 0(sp)
	sd ra, 8(sp)
	
	jal ra, init_test			#initialize test inputs
	addi a1, zero, 0
	jal ra, test_core
	addi a1, zero, 1
	jal ra, test_core
	addi a1, zero, 2
	jal ra, test_core
	addi a1, zero, 3
	jal ra, test_core
	
	ld a1, 0(sp)
	ld ra, 8(sp)
	addi sp, sp, 16
	
	jalr zero, 0(ra)
	
	
	

#----------------------------------
#name: print_test_message
#func: print a test message	
#x10(a0): result
#x11(a1): arithmetic operation (0:int addition, 1: int subtraction, 2: int multiplication, 4: division)
#x12(a2): 1st operand
#x13(a3): 2nd operand
#x14(a4): remainder 
#x15(a5): success count
#----------------------------------
print_test_message:
	addi sp, sp, -24
	sd a0, 0(sp)
	sd a1, 8(sp)
	sd a7, 16(sp)
	
	add t2, a0, zero				#store result in t2
	print_test_message_int_add:	
	bne a1, zero, print_test_message_int_sub
	la a0, add_str
	addi t3, zero, 43				#store ascii code of operator in t3
	beq zero, zero, print_test_message_op
	print_test_message_int_sub:
	addi t0, zero, 1
	bne a1, t0, print_test_message_int_mul
	la a0, sub_str
	addi t3, zero, 45				#store ascii code of operator in t3
	beq zero,zero, print_test_message_op
	print_test_message_int_mul:	
	addi t0, zero, 2
	bne a1, t0, print_test_message_int_div
	la a0, mul_str
	addi t3, zero, 42				#store ascii code of operator in t3
	beq zero,zero, print_test_message_op
	print_test_message_int_div:
	la a0, div_str
	addi t3, zero, 47				#store ascii code of operator in t3
	print_test_message_op:
	li a7, 4
	ecall
	
	#print operation, operands, result
	li a7, 11
	li a0, 91		#display '['
	ecall
	li a7, 1
	addi a0, a2, 0		#display 1st operand
	ecall
	li a7, 11
	addi a0, t3, 0		#display operator
	ecall
	li a7, 1
	addi a0, a3, 0		#display 2nd operand
	ecall
	li a7, 11
	addi a0, zero, 61		#display '='
	ecall
	li a7, 1
	addi a0, t2, 0		#display result
	ecall
	addi t0, zero, 3
	bne a1, t0, print_success_cnt
	li a7, 11
	li a0, 44		#display ','
	ecall
	li a7, 1
	addi a0, a4, 0		#display remainder if the operation is division
	ecall
	print_success_cnt:
	li a7, 11
	li a0, 93		#display ']'
	ecall
	li a0, 44		#display ','
	ecall
	li a7, 1
	addi a0, t2, 0		
	ecall
	la a0, success_str
	li a7, 4
	ecall
	li a7, 1
	add a0, zero, a5	#display the success count
	ecall
	li a7, 4
	la a0, total_testnum_str
	ecall
	
	li a7, 11
	addi a0, zero, 10	#next line
	ecall
	
	
	ld a0, 0(sp)
	ld a1, 8(sp)
	ld a7, 16(sp)
	addi sp, sp, 24
	
	jalr x0, 0(ra)
