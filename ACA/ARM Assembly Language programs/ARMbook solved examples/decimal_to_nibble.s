;convert an ASCII numeric character to decimal

	AREA	Program, CODE, READONLY
	ENTRY

Main
	MOV	R1, #-1				;set -1 as error flag
	LDRB	R0, Char		;get the character
	SUBS	R0, R0, #"0"	;convert and check if character is < 0
	BCC	Done				;if so do nothing
	CMP	R0, #9				;check if character is > 9
	BHI	Done				;if so do nothing
	MOV	R1, R0				;otherwise....
Done
	STR	R1, Result			;.....store the decimal no
	SWI	&11					;all done

	AREA	Data1, DATA
Char	DCB	&37				;ASCII representation of 7
	ALIGN

	AREA	Data2, DATA
Result	DCD	0				;storage for result

	END