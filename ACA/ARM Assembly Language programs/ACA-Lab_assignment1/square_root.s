;program to find the square root of a perfect square ((64)hex = (100)decimal)

		AREA PROGRAM,CODE,READONLY
		ENTRY
MAIN
		MOV 	R2, #0x64					;R2 stores the hex value of the number
		LDR 	R0, =0x01 					;Stores the subtrahend
		LDR 	R1, =0x01 					;Stores the result
LOOP1   SUB 	R2, R2, R0
		CMP 	R2, #0
		BEQ 	LOOP
		ADD 	R0, #1
		ADD 	R0, #1
		ADD 	R1, #1
		B 		LOOP1
LOOP
		LDR 	R3, =0x40000000
		STR 	R1, [R3]				;Storing result in memory
    
STOP 	B 		STOP
		END 