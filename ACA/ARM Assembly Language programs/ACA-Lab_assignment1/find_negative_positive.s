;find if the 32-bit number is negative or positive

		AREA mycode, CODE, READONLY
		ENTRY
		
Main
		LDR		R1, =Value1			;Load address of Value1 in R1
		LDR		R1, [R1]			;Load value of Value1 in R1
		LDR 	R4, =0x40000000		;Load address of the result 
		MOV		R0, #00				;R0=0 if number is positive. Setting R0 to 0 in the start of the program
		STR 	R0, [R4]			;Storing result in memory
		MOV		R2, #00				;To test if carry is set or not
		ADDS	R0, R0, R0			;To set carry flag as 0
		MOVS	R1, R1, LSL #1		;Logical shift left operation to see if carry flag is being set, in case of negative number
		ADC		R2, R2, R2			;R2 = R2 + carry
		CMP		R2, #1				;Compare R2 with 1
		BEQ		NEGATIVE			;Branch to NEGATIVE if comparison is equal 
STOP	B		STOP
		
NEGATIVE
		MOV		R0, #01				;R0 set to 1 because number is negative
		STR		R0, [R4]			;Storing result in memory
		B		STOP

Value1	DCD		0xFB12986A
		END
