TITLE Ass5-Q1.asm

; Author:	Dilpreet S. Chana
; Description:	Recursive GCD

INCLUDE Irvine32.inc 
	                 
.data
;Void

.code
main PROC
	call Clrscr  

	; GCD(5,20)
	push 5
	push 20
    call GCD
	call writeDec
	call crlf

	; GCD(24,18)
	push 24
	push 18
    call GCD
	call writeDec
	call crlf

	; GCD(11,27)
	push 11
	push 7
    call GCD
	call writeDec
	call crlf

	; GCD(432,226)
	push 432
	push 226
    call GCD
	call writeDec
	call crlf

	; GCD(0,0)
	push 0
	push 0
    call GCD
	call writeDec
	call crlf

	exit
main ENDP

GCD PROC
	
	; Function prologue
	push EBP
	mov EBP, ESP
	
	mov EAX, [EBP + 12]                
	mov EBX, [EBP + 8]                
	mov EDX, 0  
	
	; Checks if EBX is 0
	cmp EBX, 0
	je L2

	div EBX
	mul EBX
	mov EBX, EAX
	mov EAX, [EBP + 12]
	mov EDX, [EBP + 8] 
	sub EAX, EBX
	cmp EAX, 0
	je L2
	push EDX
	push EAX
	call GCD

	L1:
		pop EBP
		ret 8

	L2:
		; When done
		mov EAX, EDX
		jmp L1

GCD ENDP

END main
