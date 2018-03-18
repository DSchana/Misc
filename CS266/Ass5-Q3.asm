TITLE Ass5-Q3.asm

; Author:	Dilpreet S. Chana
; Description:	Recursive fib

INCLUDE Irvine32.inc 
	                 
.data
	prompt1 BYTE "Please enter N: ", 0h
	prompt2 BYTE "Fibonnacci at ", 0h
	prompt3 BYTE " = ", 0h
	prompt4 BYTE " ", 0h
	
.code
main PROC
	call Clrscr  
	lea EDX, prompt1
	call writeString
	call readInt
	call writeDec
	call crlf

	lea EDX, prompt2
	call writeString

	call writeDec

	lea EDX, prompt3
	call writeString

	mov ECX, EAX
	inc ECX
	mov EAX, 0h
	mov EBX, 0h

	L1:
		mov EAX, EBX
		call FIB
		call writeDec
		lea EDX, prompt4
		call writeString
		inc EBX
		loop L1

	call crlf

	exit
main ENDP

FIB PROC
	; Function prologue
	push EBP

	; Base Case
	cmp  EAX, 1
	jbe  exitFIB   
	
	; Set and compute N - 1
	dec  EAX    
	push EAX         
	call FIB
	
	;Swap FIB(N-1) for previously saved N - 1
	xchg EAX,0[ESP]

	; Set and compute N - 2
	dec  EAX
	call FIB

	; FIB(N - 1)
	pop  EDX
	; FIB(N - 1) + FIB(N - 2)
	add  EAX,EDX   

	exitFIB:
		pop EBP
		ret
FIB ENDP

END main
