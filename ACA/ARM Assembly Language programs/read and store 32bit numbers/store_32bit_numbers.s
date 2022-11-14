;read and store 5 32-bit numbers

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
		LDR 	R0, =0x40000000		;loading pointer to the 1st number
		LDR		R1, [R0]			;Load 1st number
		LDR		R2, [R0, #4]!		;Increment memory location by 4 bytes and load next number
		LDR		R3, [R0, #4]!		;Increment memory location by 4 bytes and load next number
		LDR		R4, [R0, #4]!		;Increment memory location by 4 bytes and load next number
		LDR		R5, [R0, #4]		;Increment memory location by 4 bytes and load next number
		
		LDR 	R0, =0x4000F000		;loading pointer to the loaction where result has to be stored
		STR		R1, [R0]			;Store 1st number at 4000F000H
		STR		R2, [R0, #4]!		;Store next number at 4000F004H
		STR		R3, [R0, #4]!		;Store next number at 4000F008H
		STR		R4, [R0, #4]!		;Store next number at 4000F00CH
		STR		R5, [R0, #4]		;Store next number at 4000F010H
		NOP
STOP	B		STOP
		END