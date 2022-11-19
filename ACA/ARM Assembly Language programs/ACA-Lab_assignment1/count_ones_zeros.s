;count the number of 1s and 0s in a 32 bit number
		
		AREA RESET, DATA, READONLY
		EXPORT __Vectors

__Vectors
		DCD		0x100000FF			;stack pointer value when stack is empty
		DCD		Reset_Handler		;Reset vector

		ALIGN
			
		AREA mycode, CODE, READONLY
		EXPORT Reset_Handler
		ENTRY
		
Reset_Handler
		LDR		R0, =0x40000000				;Load the address of value1
		LDR		R1, [R0]					;Store value located at address pointed by R0
		MOV		R2, #32						;Counter set to 31F
JUMP	MOVS	R1, R1, LSR #1				;Logical right shift by 1 bit and set carry if carry is generated
		ADDCS	R3, R3, #1					;R3 holds number of ones
		ADDCC	R4, R4, #1					;R4 holds the number of zeros
		SUB		R2, R2, #1					;Decrementing count by 1
		CMP		R2, #01						;Check if counter has reached the msb (32nd bit)
		BNE		JUMP	
		LDR 	R0, =0x40000004				;Load the address where number of 1s are to be stored
		STR		R3, [R0]					;Store the count of 1s in the address stored in R0
		STR		R4, [R0, #4]				;Store the count of 1s in the address stored in R0, after incrementing location by 4 bytes (32 bits)
	
STOP	B		STOP
		END
		