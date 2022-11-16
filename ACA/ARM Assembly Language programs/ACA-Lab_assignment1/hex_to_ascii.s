;program to convert hex number to ascii value
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
		LDR 	R0, =0x40000000				;Get the memory loc of Hex Digit source
		LDR 	R5, [R0]
		;LDR		R6, =DST
		LDR 	R6, =0x40000004				;Load R6 with Address of Destination location 
		MOV		R1, #08						;R1 = 8, indicating 8 HEX digits
		
UP
		AND 	R2,	R5, #0x0F 				;Masking to get only LSB byte in case of multidigit number
		CMP 	R2, #09 					;Affects the carry flag if no>9 c = 1 else C = 0
		BLO 	DOWN						;Branch to DOWN if low
		ADD 	R2, #07						;If no > 9, add 7 + 30
DOWN
		ADD 	R2, #0x30
		STRB 	R2, [R6], #01  				;Storing the result in Memory pointed by R6
		ROR 	R5, #4  					;Rotate the number by 4 bits for next digit
		SUBS 	R1, #01 					;decrement the count by 1 and check for zero condition
		BNE 	UP 							;if Z = 0 repeat the process else exit
STOP	B		STOP

		AREA ASCII, DATA, READWRITE 
DST 	DCD 	0
		
		END 
