;program to find the factorial of a number (7! = (5040) decimal = (13B0) hexadecimal)

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
		LDR		R5,=0x40000000				;Result will be stored in this destination address
		MOV 	R0, #07						;Loading the number who's factorial is to be calculated
		MOV		R1, R0						;Copy the content of R0 to R1
	
FACT	SUBS	R1, R1, #1					;R1 = R1 - 1
		CMP		R1, #1						;Comparing R1 with 1
		BEQ		DONE						;Branch to STOP if equal
		MUL		R3, R0, R1					;Store the product of R0 and R1 in R3
		MOV		R0, R3						;Copy the result from R3 to R0
		BNE		FACT						;Branch to FACT if not equal
		
DONE	STR		R3, [R5]
STOP	B		STOP
		END