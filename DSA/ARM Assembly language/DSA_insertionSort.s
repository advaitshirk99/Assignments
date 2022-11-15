;Insertion sort algorithm
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
		MOV		R0, #1			;Start index
		LSL		R0, R0, #2
		MOV		R1, #10			;size of array
		LSL 	R1, R1, #2
		BL		INSERTION

		LDR 	R0, =Array
		LDM		R0!, {R1-R10}
		B 		STOP
		
INSERTION
		SUB		SP,	SP, #12		;Move stack for keep current parameter
		STR		LR, [SP, #8]	;Save return address
		
		