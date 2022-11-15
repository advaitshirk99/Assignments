;find length of string
		AREA Reset, CODE, READONLY
		ENTRY
Main
		LDR 	R0, =Data1
		EOR 	R1,R1,R1
		LDR 	R4, CharCount
    
Loop
		LDRB 	R2, [R0], #1
		CMP 	R2, #CR
		BEQ 	Done
		ADD 	R1,R1, #1
		BAL 	Loop
Done
		STR 	R1, [R4]
STOP	B		STOP
    
Data1
		DCB 	"Hello", CR
		ALIGN
        
CharCount 
		DCD 	&40000000
CR 		EQU 	0x0D
		END