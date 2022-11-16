;program to find the square root of a number

		AREA PROGRAM,CODE,READONLY
		ENTRY
MAIN
		MOV 	R2, #20					;A
		LDR 	R0, =0x01 				;D
		LDR 	R1, =0x01 				;E
LOOP1   SUB 	R2, R2, R0
		CMP 	R2, #0
		BEQ 	LOOP
		ADD 	R0, #1
		ADD 	R0, #1
		ADD 	R1, #1
		B 		LOOP1
LOOP
		LDR 	R3, =0x40000000
		STR 	R1, [R3]
    
STOP 	B 		STOP
		END 