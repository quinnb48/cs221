main:

	jal Arr_Count
jr $ra

Arr_Count:
		lh $a0, $a0		#array- set here just for testing
		li $a1, 8		#array length- set here just for testing
		li $t0, 2		#val 1- set here just for testing
		li $t1, 4		#val 2- set here just for testing
		li $t2, 5		#val 3- set here just for testing
		li $t3, 4		#place you are at in the array, by bytes
		lh $t4, $a0		#address of place in array
		li $s0, 0		#counting result 1
		li $s1, 0		#counting result 2
		li $s2, 0		#counting result 3
		li $s3, 0		#counting result 4
		
CheckZero:	slt $t5, $t4, $t0		#Is $a0[$t3] < $t0?
		beq $t5, $zero, CheckOne	#if yes continue, If no skip to next check
		addi $s0, 1					#increase counting result
		addi $t3, 4					#increase place in array
		lh $t4, $t3($a0)			#t4 = array address + place in array
		j CheckZero	
CheckOne:	slt $t5, $t4, $t1		#is $a0[$t3] <$t1?
		beq $t5, $zero, CheckTwo	#if yes continue, If no skip to next check
		addi $s1, 1					#increase counting result
		addi $t3, 4					#increase place in array
		lh $t4, $t3($a0)			#t4 = array address + place in array
		j CheckOne
CheckTwo:	slt $t5, $t4, $t2		#is $a0[$t3] <$t2?
		beq $t5, $zero, CheckThree	#if yes continue, If no skip to next check
		addi $s2, 1					#increase counting result
		addi $t3, 4					#increase place in array
		lh $t4, $t3($a0)			#t4 = array address + place in array
		j CheckTwo
CheckThree:	slt $t5, $t4, $a1		#is $a0[$t3] < $a1?
		beq $t5, $zero, End			#if yes continue, If no skip to end
		addi $s3, 1					#increase counting result
		addi $t3, 4					#increase place in array
		lh $t4, $t3($a0)			#t4 = array address + place in array
		j CheckThree
End:		jr $ra