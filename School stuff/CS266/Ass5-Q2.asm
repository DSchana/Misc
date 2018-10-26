TITLE Ass5-Q2.asm

; Author:	Dilpreet S. Chana
; Desription:	Iterative factorial

INCLUDE Irvine32.inc 
	                 
.data
	prompt BYTE "Please enter a number N to get N factorial: ", 0h
	
.code
main PROC
	call Clrscr  
	lea EDX, prompt
	call writeString
	call readInt
	
	call crlf
	call FACT
	call writeDec
	call crlf

	exit
main ENDP

FACT PROC
	; Function Prologue
	push EBP
	mov EBP, ESP

	; N in ECX , 1 in EAX
	mov ECX, EAX
	mov EAX, 1h

	L1:
		mul ECX
		loop L1

		pop EBP
		ret 
FACT ENDP

END main
