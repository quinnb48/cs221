main:

	jal Fibonacci
jr $ra

Fibonacci:
		li $a0, 4		#nth number
		li $t0, 1 		#ith number of the fibonacci code you are at	
		li $t2, 1		#1st fibonacci number
		li $t3, 1		#2nd fibonacci  number
		li $t4, 0		#temp number for moving the fibo numbers around
		
Return:	slt $t1, $t0, $a0		#have you reached the nth number yet?
		beq $t1, $zero, Exceed 		#if yes jump to exceed
		addi $t4, $t3, 0			#put value of t3 into t4
		add $t3, $t3, $t2			#fibo num 2= itself plus the previous fibo num
		addi $t2, $t4, 0			#put value of t4 into t2
		addi $t0, $t0, 1			#increment place you are in the fibonacci sequence
		j Return
Exceed:	addi $v0, $t3, 0				#put result in v0
		jr $ra				
		
