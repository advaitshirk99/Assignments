;program to add two 32 bit numbers

		AREA RESET, DATA, READONLY
		EXPORT __Vectors
			
__Vectors
		DCD 	0x100000FF					;Stack pointer value when stack is empty
		DCD		Reset_Handler				;Reset vector
		
		ALIGN
			
		AREA mycode, CODE, READONLY
		EXPORT Reset_Handler
		ENTRY

Reset_Handler
		LDR		R0, =Value1					;Load the address of value1
		LDR		R1, [R0]					;Store value located at address pointed by R0
		LDR		R0, =Value2					;Load address of Value2
		LDR 	R2, [R0]					;Store value located at address pointed by R0
		ADD		R3, R1, R2					;Store the sum of R1 and R2 in R3
		
		LDR		R0, =Result					;Load the address of Result
		STR		R3, [R0]					;Store the result in code memory

STOP	B		STOP	

Value1	DCD		0x12345678
Value2	DCD		0x98765432
		
		AREA data, DATA, READWRITE
Result	DCD 	0
		END