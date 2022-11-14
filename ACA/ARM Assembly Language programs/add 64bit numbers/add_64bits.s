;Adding two 64 bit numbers

		AREA RESET, DATA, READONLY
		EXPORT __Vectors

__Vectors
		DCD		0x100000FF				; Stack pointer value when it is empty
		DCD 	Reset_Handler			; Reset vector
		
		ALIGN

		AREA mycode, CODE, READONLY
		EXPORT Reset_Handler
		ENTRY
		
Reset_Handler
		LDR		R0, =0x40000000			;pointer to 1st number				
		LDR		R1, [R0]				;load first part of VALUE1
		LDR 	R2, [R0, #4]!			;load lower part of VALUE1				
		LDR		R3, [R0, #4]!			;load first part of VALUE2
		LDR 	R4, [R0, #4]!			;load lower part of VALUE2
		ADDS	R6, R2, R4				;Add the lower 4 bytes and set carry
		ADC		R5, R1, R3				;Add upper 4 bytes including carry
		LDR		R0, =0x4000FF00
		STR 	R5, [R0]				;Store upper part of result
		STR 	R6, [R0, #4]			;Store lower part of result
		END
			