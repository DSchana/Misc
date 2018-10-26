TITLE Ass4.asm

; Author:	Dilpreet S. Chana

INCLUDE Irvine32.inc 
	                 
.data
	newline BYTE 0ah, 0
	prompt  BYTE "What do you want to do?", 0ah, 0
	prompt1 BYTE "h", 0ah, 0
	prompt2 BYTE "Get Lost Sweetey Honey Bun", 0ah, 0
	prompt3 BYTE "Thank you Sweetey Honey Bun", 0ah, 0
	prompt4 BYTE "Please enter a decimal number: ", 0
	prompt5 BYTE "Please enter a hexadecimal number: ", 0
	charA BYTE 'A', 0
	charB BYTE 'B', 0
	charC BYTE 'C', 0
	charD BYTE 'D', 0
	charE BYTE 'E', 0
	charF BYTE 'F', 0

.code
main PROC

    mov EDX, OFFSET prompt
    call writeString
    mov EDX, OFFSET newline

    call readChar
    call writeChar				
    call writeString

    cmp AL, 'R'
    je Hexin
    cmp AL, 'r'
    je Hexin
    cmp AL, 'W'
    je Hexout
    cmp AL, 'w'
    je Hexout

    mov EDX, OFFSET prompt2
    call writeString
    jmp quit

    Hexin:
    	call HexInput

    Hexout:
    	mov EDX, OFFSET prompt4
	    call writeString
	    mov EDX, OFFSET newline

	    call readDec

	    mov EBX, EAX
	    mov EAX, 0ah
	    
    	call HexOutput

    quit:
    	exit
main ENDP

;Displays the content of register EBX
;as hexadecimal string
HexOutput PROC
	mov ECX, 8

	hexD:
		rol EBX, 4
		mov DL, BL
		and DL, 0Fh

		mov AL, DL 
		
		cmp AL, 10
		jnb hexW
		call writeDec
		jmp lend

		hexW:
			cmp AL, 10
			jne L1
			mov EDX, OFFSET charA
			call writeString
			jmp lend

		L1:
			cmp AL, 11
			jne L2
			mov EDX, OFFSET charB
			call writeString
			jmp lend

		L2:
			cmp AL, 12
			jne L3
			mov EDX, OFFSET charC
			call writeString
			jmp lend

		L3:
			cmp AL, 13
			jne L4
			mov EDX, OFFSET charD
			call writeString
			jmp lend

		L4:
			cmp AL, 14
			jne L5
			mov EDX, OFFSET charE
			call writeString
			jmp lend

		L5:
			cmp AL, 15
			jne lend
			mov EDX, OFFSET charF
			call writeString

		lend:
			loop hexD

	mov EDX, OFFSET newline
	call writeString
	mov EDX, OFFSET prompt3
	call writeString

	exit
HexOutput ENDP

;Loads the register EAX with the numerical value of the hexadecimal
;string entered at the keyboard
HexInput PROC
	xor EBX, EBX

	mov EDX, OFFSET prompt5
	call writeString

	hexI:
		call readChar
        call writeChar
        cmp AL, 'h'
        je hexEnd

        hexN:

        	cmp AL, '0'
        	jne L1
        	mov AL, 0
        	jmp hexL

        L1:
        	cmp AL, '1'
        	jne L2
        	mov AL, 1
        	jmp hexL

        L2:
        	cmp AL, '2'
        	jne L3
        	mov AL, 2
        	jmp hexL

        L3:
        	cmp AL, '3'
        	jne L4
        	mov AL, 3
        	jmp hexL

        L4:
        	cmp AL, '4'
        	jne L5
        	mov AL, 4
        	jmp hexL

        L5:
        	cmp AL, '5'
        	jne L6
        	mov AL, 5
        	jmp hexL

        L6:
        	cmp AL, '6'
        	jne L7
        	mov AL, 6
        	jmp hexL

        L7:
        	cmp AL, '7'
        	jne L8
        	mov AL, 7
        	jmp hexL

        L8:
        	cmp AL, '8'
        	jne L9
        	mov AL, 8
        	jmp hexL

        L9:
        	cmp AL, '9'
        	jne LA
        	mov AL, 9
        	jmp hexL

        LA:
        	cmp AL, 'A'
        	jne LB
        	mov AL, 10
        	jmp hexL

        LB:
        	cmp AL, 'B'
        	jne LC
        	mov AL, 11
        	jmp hexL

        LC:
        	cmp AL, 'C'
        	jne LD
        	mov AL, 12
        	jmp hexL

        LD:
        	cmp AL, 'D'
        	jne L14
        	mov AL, 13
        	jmp hexL

        L14:
        	cmp AL, 'E'
        	jne LF
        	mov AL, 14
        	jmp hexL

        LF:
        	cmp AL, 'F'
        	jne hexL
        	mov AL, 15

        hexL:
        shl EBX, 4
        add BL, AL
        jmp hexI


    hexEnd:
    	mov EDX, OFFSET newline
		call writeString

		mov EAX, EBX
		call writeBin
		call writeString
		mov EDX, OFFSET prompt3
		call writeString

	exit
HexInput ENDP
END main  
