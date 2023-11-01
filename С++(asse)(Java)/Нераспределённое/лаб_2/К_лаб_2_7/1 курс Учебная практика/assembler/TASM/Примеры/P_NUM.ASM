;Copyright (C) by Frolov A.V.,1998
;Программа вычисления первых 32 совершенных чисел в порядке возрастания.
;6,28,496,8128,...
;Использована формула n=2^(k-1)*(2^k-1), где k - простое число.
;Формула приведена к виду 2^(2*k-1)-2^(k-1).

.286
.model small
.stack	200h

.data
Ten_10		db	10
Ten_16		db	10h
Zero		db	0
PrN_line	db	0,0,130 dup (1),'$'	;Массив, в котором простые числа будут отмечены 1
PrN_line_length	db	131			;длина массива
Subtrahend	db	40 dup (0)		;2 в степени К-1, где К - простое число
Power		db	0			;степень
Res_Number16	db	80 dup (0),'$'		;Результат в 16 с/с (т.е. совершенное число)
Res_Number10	db	80 dup (0),'$'		;Результат в 10 с/с
Quotient	db	80 dup (0)			;необходимо при переводе результата и 16 в 10 c/с
Length		db	80			;длина делимого (см. proc. Translate)
Digit_Pos	db	0			;Номер позиции числа в массиве простых чисел
HowMuch_Number	db	3,0,3 dup (0)		;Полученное от пользователя
						;требуемое количество совершенных чисел в ASCII
PfN_Quantity	db	0			;HowMuch_Number в числовом формате
ErrorCode	db	0			;код ошибки (значения см. в процедуре)
Info_Message	db	10,13,'Данная программа расчитана на вывод первых 32 ',10,13,'совершенных чисел в порядке возрастания.',10,13,10,'$'
Query_Message	db	10,13,'Сколько совершенных чисел вам необходимо? ','$'
ErrorMessage1	db	10,13,'Недопустимый формат данных.',10,13,'Повторите ввод.',10,13,'$'
ErrorMessage2	db	10,13,'Данные отсутствуют. Программа завершена.',10,13,'$'
ErrorMessage3	db	10,13,'Число должно находиться в пределах от 1 до 32.',10,13,'$'


.code
;************************** MAIN PART *******************************
Begin:
	call	Initialization
	call	ClrScr
	call	SetCursor
	call	GetTheNumber		;Required quantity --> PfN_Quantity
	call	ClrScr
	call	SetCursor
	call	C&P_PfNumber		;Calculating and Printing required
					;qauntity of Perfect Numbers
	jmp	ProgramEnd
	
;************************* PROCEDURES *******************************

;------------------------ Initialization ----------------------------
Initialization	proc
	mov	ax,@data
	mov	ds,ax			;ES,DS initializing
	mov	es,ax
	ret
Initialization	endp

;---------------------- Screen clearing -----------------------------
ClrScr		proc
	mov	ax,0600h
	mov	bh,07h
	mov	cx,0
	mov	dx,184fh
	int	10h
	ret
ClrScr	endp

;------------------ Filling the Prime Numbers Line -------------------
FillLine	proc
					;n/2 --> CX
	xor	ax,ax
	mov	al,[PrN_line_length]
	mov	bl,2
	div	bl
	xor	cx,cx
	xchg	al,cl
	lea	si,PrN_line
Next_Pos:				;Main Cycle (from 1 to n/2)
	push	cx
	mov	ah,[si]
	cmp	ah,1
	jne	Next_Number
					;Elimitation of the multiples
	push	si
	xor	bx,bx
	mov	bl,[Digit_Pos]		;number --> BL
	xor	ax,ax
	mov	al,PrN_line_length
	div	bl
	dec	al
	mov	cl,al
	add	si,bx
E_C:					;Elimination cycle
	mov	[si],bh			;bh=0
	add	si,bx			;step = Digit_Pos
	loop	E_C
	
	pop	si
Next_Number:	
	pop	cx
	inc	si
	inc	Digit_Pos
	loop	Next_Pos
	ret
FillLine	endp	
	
;---------------------------- GetTheNumber ------------------------
GetTheNumber	proc
	mov	ah,9			;Asking how many perfect numbers
	lea	dx,Info_Message		;have to be displayed
	int	21h
GN_Begin:	
	mov	ah,9
	lea	dx,Query_Message
	int	21h
	mov	ah,0ah			;Receiving the answer
	lea	dx,HowMuch_Number
	int	21h
	lea	si,HowMuch_Number
	mov	al,[si+1]		;Checking presence of data
	cmp	al,0
	jne	GN_Step2		
	mov	[ErrorCode],2
	call	DisplayError
	jmp	ProgramEnd
GN_Step2:				;Checking data format
	lea	si,HowMuch_Number
	xor	cx,cx
	mov	cl,[si+1]
	add	si,2
GN_CH_loop:
	mov	al,[si]			;< 0 - ?
	cmp	al,30h
	jae	CH_L_s1
	mov	[ErrorCode],9
CH_L_s1:
	cmp	al,39h			;> 9 - ?
	jbe	CH_L_s2
	mov	[ErrorCode],9
CH_L_s2:
	inc	si
	loop	GN_CH_loop
	mov	al,[ErrorCode]
	cmp	al,9
	jne	GN_Step3
	mov	[ErrorCode],1
	call	DisplayError
	jmp	GN_Begin
GN_Step3:				;Translating data from ASCII
	lea	si,HowMuch_Number
	mov	ah,[si+1]
	cmp	ah,1
	jne	GN_Step4
	mov	ax,[si+2]
	mov	ah,0
	xchg	ah,al
	mov	[si+2],ax	
GN_Step4:	
	mov	ax,[si+2]
	xchg	ah,al
	and	ax,0f0fh
	aad
	cmp	al,32
	jbe	GN_Step5
	mov	[ErrorCode],3
	call	DisplayError
	jmp	GN_Begin
GN_Step5:
	cmp	al,1
	jae	GN_Step6
	mov	[ErrorCode],3
	call	DisplayError
	jmp	GN_Begin
GN_Step6:			
	mov	[PfN_Quantity],al
	ret
GetTheNumber	endp

;------------------------- Display error message ------------------
;00 - OK (no errors)
;01 - Uncorrect format of received data
;02 - No data
;03 - value of the power exceed 32

DisplayError	proc
        xor	cx,cx
        mov	ah,9
	mov	cl,ErrorCode
	cmp	cx,3
	je	Err3
	cmp	cx,2
	je	Err2
Err1:	
	lea	dx,ErrorMessage1
	int	21h
	jmp	DE_End
Err2:	
	lea	dx,ErrorMessage2
	int	21h
	jmp	DE_End
Err3:	
	lea	dx,ErrorMessage3
	int	21h
DE_End:	
	mov	[ErrorCode],0
	ret
DisplayError	endp

;----------------- Printing the result ---------------------------
Print	proc
	pusha
	mov	cx,80
	lea	si,Res_Number10+79
P_Loop:
	mov	al,byte ptr[si]
	or	al,30h
	mov	byte ptr[si],al
	dec	si
	loop	P_Loop
	call	Del_Zero			;Eliminating zeros from the
						;result
	mov	ah,9
	lea	dx,Res_Number10
	int	21h
	popa
	call	Clear_Res_Number16		;clearing Res_Number16
	ret
Print	endp	

;---------------------- Setting cursor ---------------------------
SetCursor	proc
	pusha
	mov	ah,2
	mov	bh,0
	mov	dx,0
	int	10h
	popa
	ret
SetCursor	endp

;--------------- Eliminating 0's from Res_Number10 ------------------
Del_Zero	proc
	pusha
	lea	si,Res_Number10
	mov	bl,20h
DZ_Loop:
	cmp	byte ptr [si],30h
	jne	DZ_End
	mov	[si],bl
	inc	si
	jmp	DZ_Loop
DZ_End:		
	popa
	ret
Del_Zero	endp		

;---------------------- Clearing Res_Number16 ------------------
Clear_Res_Number16	proc
	pusha
	lea	si,Res_Number16
	mov	cx,80
Cl_Loop:
	mov	byte ptr[si],0
	inc	si
	loop	Cl_Loop
	popa
	ret
Clear_Res_Number16	endp	

;------------------ Calculating & printing Perfect numbers ------------------
C&P_PfNumber	proc
	call	FillLine
	xor	cx,cx
        mov	cl,PfN_Quantity
        lea	si,PrN_line
Print_Loop:
Power_Loop:
	mov	ah,[si]			;calculating power
	cmp	ah,1
	je	S&P_Step1
	inc	si
	inc	[Power]
	jmp	Power_Loop
S&P_Step1:
	call	Form_M&S		;forming Minuend and Subtrahend
	call	Subtract		;performing subtraction
	call	Translate		;Translating result from 16 to 10 notation
	call	Print			;displaying the result
	inc	si
	inc	[Power]
	loop	Print_Loop
	ret
C&P_PfNumber	endp	

;------------------ Forming Minuend & Subtrahend -------------------
;required parameter: Power
;Result: Minuend --> Res_Number16, Subtrahend --> Subtrahend

Form_M&S		proc
	pusha
	lea	si,Subtrahend  		;forming the Subtrahend
	add	si,39
	xor	ax,ax
	mov	al,[Power]		;k
	dec	ax			;k-1
	mov	bl,4
	div	bl
	xor	cx,cx
	mov	cl,al
	cmp	cl,0
	je	F_M&S_Step1
FZ_Loop:				;Filling part of Subtrahend with Zeros
	mov	byte ptr[si],0
	dec	si
	loop	FZ_Loop
F_M&S_Step1:
	mov	bx,1
	mov	cl,ah
	shl	bx,cl
	mov	[si],bl
	
	lea	si,Res_Number16		;calculating Minuend
	add	si,79
	xor	ax,ax			
	mov	al,[Power]
	mov	bl,2
	mul	bl
	dec	ax
	mov	bl,4
	div	bl
	xor	cx,cx
	mov	cl,al
	cmp	cl,0
	je	F_M&S_Step2
FZ_Loop1:				;Filling part of Minuend with Zeros
	mov	byte ptr[si],0
	dec	si
	loop	FZ_Loop1
F_M&S_Step2:
	mov	bx,1
	mov	cl,ah
	shl	bx,cl
	mov	[si],bl
	popa
	ret
Form_M&S		endp		

;----------------- Performing Subtraction ------------------------
;required parameters: Res_Number16 - Minuend, Subtrahend - Subtrahend
;result: Difference in Res_Number16

Subtract	proc
	pusha
	lea	si,Res_Number16+79
	lea	di,Subtrahend+39
	mov	cx,40
Sub_Loop:
	mov	al,byte ptr[si]
	sub	al,byte	ptr[di]
	cmp	al,0
	jge	Sub_Step1
	add	al,16
	push	si
Correct_Loop:	
	dec	si
	mov	ah,byte	ptr[si]
	dec	ah
	cmp	ah,0
	jge	CL_Step1
	add	ah,16
	mov	byte ptr[si],ah
	jmp	Correct_Loop
CL_Step1:	
	mov	byte ptr[si],ah
	pop	si
Sub_Step1:
	mov	byte ptr[si],al
	dec	si
	dec	di
	loop	Sub_Loop
	popa
	ret
Subtract	endp

;------------- Translating from 16 to 10 notation ----------------
;required parameters: Res_Number16 - number in 16 notation
;result:number in 10 notation --> Res_Number10

Translate	proc
	pusha
	lea	si,Res_Number16		;divident
	lea	bx,Res_Number10		;number in 10 notation
	lea	di,Quotient
	mov	[Length],80
	add	bx,79			;Now address in BX pointing on the last digit
	call	SetLength		;preparing divident for division and setting its length
T_Loop_M:
	call	Divide			;performing division by 10 (remainder in AH)
	call	SaveRemainder		;saving remainder in Res_Number10 (from AH)
	call	SetLength
	mov	al,[Length]
	cmp	al,1
	jne	T_Loop_M
	
	xor	ax,ax
	mov	ah,[si]
T_Loop_1:
	mov	al,ah
	xor	ah,ah
	div	[Ten_10]
	call	SaveRemainder		;saving remainder in Res_Number10 (from AH)
	cmp	al,0
	jne	T_Loop_1	
	
	popa
	ret
Translate	endp

;------------ Finging first digit of a divident --------------
;------------ and setting length of the divident -------------
;required parameters: address of the divident in SI
;result: divident --> SI, length of the divident --> Length

SetLength	proc
	push	ax
	mov	al,[Length]
	cmp	al,1
	je	SL_Step1
SL_Loop:
	mov	al,[si]
	cmp	al,0
	jne	SL_Step1
	inc	si
	dec	[Length]
	jmp	SL_Loop
SL_Step1:
	pop	ax
	ret
SetLength	endp

;----------- Saving Remainder in Res_Number10 ----------------
;required parameters: remainder in AH, digit position of Res_Number10 in BX

SaveRemainder	proc
	mov	byte ptr [bx],ah
	dec	bx
	ret
SaveRemainder	endp	

;------------ performing division by 10 ----------------------
;required parameters: divident in SI, length of the divident in Length
;result:  qoutient in DI, remainder in AH

Divide	proc
	push	si
	push	di

	xor	cx,cx			;calculating the amount of stepts in
	mov	cl,[Length]		;division
	xor	ax,ax
D_Loop: 	
	mov	al,ah
	mul	[Ten_16]
D_Loop1:
	add	al,[si]
D_Loop2:	
	xor	ah,ah
	div	[Ten_10]
	mov	[di],al
	inc	di
	inc	si
	loop	D_Loop
D_Loop_A:
	cmp	al,0
	je	D_Step1
	mov	cx,1
	mov	al,ah
	jmp	D_Loop2
D_Step1:
	pop	di
	pop	si
	xchg	di,si
	ret
Divide	endp

;************************* finishing the program ******************
ProgramEnd:
	mov	ah,4ch			
	int	21h
	end	Begin
	
