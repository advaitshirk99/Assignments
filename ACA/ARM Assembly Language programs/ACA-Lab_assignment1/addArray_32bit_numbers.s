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
		LDM		R0!, {R1-R5}		;Load in multiple registers starting from address stored in R0 
		ADDS	R1, R1, R2			;Summing R1 and R2 and storing it in R1, while setting carry flag
		ADCS	R1, R1, R3			;Summing R1, R3 and previous carry and storing it in R1, while setting carry flag
		ADCS	R1, R1, R4			;Summing R1, R4 and previous carry and storing it in R1, while setting carry flag
		ADC		R1, R1, R5			;Summing R1, R5 and previous carry and storing it in R1
		
		LDR		R0, =0x40001000		;Loading pointer to the location where result is to be stored
		STR		R1, [R0]			;Storing the result in address stored in R0
		
STOP	B		STOP
		END