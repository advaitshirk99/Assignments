;program to find the factorial of a number

		AREA mycode, CODE, READONLY
		ENTRY

Main
		LDR		R0, =05;					;Loading the number who's factorial is to be taken into R0
		LDR		R6, =0x40000000				;Loading the address of the result
		BL 		FACTORIAL
		STR		R0, [R6]					;Storing the result in memory
STOP	B		STOP

FACTORIAL
		PUSH 	{R4, LR}					;pushing R4 and lr on the top of the stack
		MOV 	R4, R0						;Make a copy of R0
		CMP		R0, #0						;Compare R0 with 0
		BNE		NOT_ZERO					;branch to NOT_ZERO if not equal
		MOV		R0, #1						;R0 = 1
		B		LAST						;branch to LAST
		
NOT_ZERO
		SUB		R0, R0, #1					;Subtract 1 from R0 and store it back in R0
		BL		FACTORIAL					;Branch link to FACTORIAL, call the function recursively
		MOV 	R1, R4				
		MUL		R0, R1, R0					;R0 = R0 * R1

LAST
		POP		{R4, LR}					;popping R4 and LR out of the stack
		BX		LR
		END
		