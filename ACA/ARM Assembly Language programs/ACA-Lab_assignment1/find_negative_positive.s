;find if the 32-bit number is negative or positive
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
		LDR		R1, =0x40000000			;Load address of Value1 in R1
		LDR		R1, [R1]			;Load value of Value1 in R1

		MOV		R0, #00				;R0=0 if number is positive. Setting R0 to 0 in the start of the program
		MOV		R2, #00				;To test if carry is set or not
		ADDS	R0, R0, R0			;To set carry flag as 0
		MOVS	R1, R1, LSL #1		;Logical shift left operation to see if carry flag is being set, in case of negative number
		ADC		R2, R2, R2			;R2 = R2 + carry
		CMP		R2, #1				;Compare R2 with 1
		BEQ		NEGATIVE			;Branch to NEGATIVE if comparison is equal 
STOP	B		STOP
		
NEGATIVE
		MOV		R0, #01				;R0 set to 1 because number is negative
		B		STOP

;Value1	DCD 	0xF2234556
		END