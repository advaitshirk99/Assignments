;program to add 16 bit numbers

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
		LDRH	R0, =0x40000000		;load address of 1st 16 bit number using LDR half word instruction
		LDRH	R1, [R0]			;load value of 1st number in R1
		LDRH	R2, [R0, #2]		;load the value of 2nd number in R2
		ADD		R3, R2, R1			;Store the sum of R1 and R2 in R3
		
		LDRH 	R0, =0x4000F000		;load the address where the result is to be stored
		STRH	R3, [R0]			;Store sum from R3, in the location pointed by R0
		END
		