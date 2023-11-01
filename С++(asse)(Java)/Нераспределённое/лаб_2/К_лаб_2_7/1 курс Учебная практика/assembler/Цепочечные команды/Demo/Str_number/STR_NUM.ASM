COMMENT*
процедуры:
	- преобразования строки символов в число:
		Cnv_Str_Num
	- преобразования числa в строку символов:	
		Cnv_Num_Str
с указанием системы счисления:	2h,8h,0a,10h
*
.286
.model small
.stack 100h
.data			;длина поля в зависимости от системы счисления
			;(для беззнаковых чисел)
Field_Length	db	0,0,16,5 dup (0),6,0,5,5 dup(0),5
Digits		db	'0123456789ABCDEFabcdef'

.code
public Cnv_Str_Num, Cnv_Num_Str

COMMENT*
-------------------------  Cnv_Str_Num --------------------
INFO  : преобразования строки символов в число с указанием системы
	счисления. Беззнаковое (0..65535), знаковое (-32768..32767)
INPUT : последовательность сохранения параметров в стеке:
	-сегмент,
	-смещение строки,
	-тип числа (знаковый =0 /беззнаковый =1):BYTE
	-система счисления (2,8,10,16):BYTE
		напр.:000Ah - беззнаковое, 10 с\с
		      0110h - знаковое 16 с\с
		      0002h - беззнаковое 2 с\с	
	строка в формате для (0Ah) 21h	
OUTPUT: стек: результат обработки
		CF = 0 - число (WORD)
		CF = 1 - код ошибки
	 код ошибки:
	 	1 - некорректные данные
	 	2 - слишком большое число
SAVE  :	ALL
*

Cnv_Str_Num	proc	far
	pusha
	mov	bp,sp
	add	bp,20			;сдвиг на переданные параметры + адрес возврата
	mov	ds,word ptr[bp+4]
	mov	si,word ptr[bp+2]
	call	Check_Format		;проверка корректности данных
	jc	Format_Error		;
	
	xor	ax,ax
	xor	bx,bx
	xor	di,di			;контроль за величиной числа
	mov	bl,byte ptr [bp]	;с\с
	mov	cs:Basis,bx
C_S_U_Loop:
	mul	cs:Basis
	adc	di,0
	add	di,dx
	mov	bl,byte ptr [si]
	cmp	bl,'a'
	jb	C_S_Upper_Case
	and	bl,11011111b		;коррекция регистра
C_S_Upper_Case:	
	cmp	bl,'A'
	jb	C_S_Not_Hex
	sub	bl,55			;коррекция для шестнадц. чисел
	jmp short C_S_Hex_Done
C_S_Not_Hex:	
	and	bl,0fh
C_S_Hex_Done:	
	add	ax,bx
	adc	di,0
	inc	si
	loop	C_S_U_Loop
	cmp	di,0
	jne	Big_Number
	call	Check_Sign		;коррекция знака и проверка величины (в
					;случае знакового числа)
	jc	Big_Number			
	mov	word ptr [bp+4],ax	;сохраняем результат
	popa
	clc				;нет ошибок
	ret	4
Format_Error:
	mov	word ptr [bp+4],1	;неверный формат
	popa
	stc
	ret	4
Big_Number:
	mov	word ptr [bp+4],2	;слишком большое число
	popa
	stc
	ret	4			;КОНЕЦ ПРОЦЕДУРЫ
	
;- - - SUBR- - - Check_Format - - - - - - - -
;INFO  : проверка корректности формата данных
;INPUT : DS,SI - сегмент и смещение строки,
;	 BP   - система счисления :(BYTE)
;	 BP+1 - тип числа (знаковое = 1/ беззнаковое = 0):(BYTE)
;OUTOUT: CF = 0 - OK, CF = 1 - ошибка
;	 SI - смещение числа
;	 CX - количество цифр в числе
;SAVE  : ALL

Check_Format	proc
	push	ax bx dx bp es ds di ;[si cx] - будут сохранены позже
	xor	cx,cx
	mov	cl,byte ptr [si+1]	;длина строки
	cmp	byte ptr [bp+1],1
	jne	C_F_Check_Plus
	cmp	byte ptr[si+2],'-'
	jne	C_F_Check_Plus
	inc	si
	dec	cx
C_F_Check_Plus:	
	cmp	byte ptr[si+2],'+'
	jne	C_F_Unsigned
	inc	si
	dec	cx
	
C_F_Unsigned:
	mov	ax,seg Digits		;строка сравнения
	mov	es,ax
	lea	di,Digits
	add	si,2
	push	si cx			;сохраняем смещение числа + кол-во цифр
	xor	bx,bx
	mov	bl,byte ptr [bp]	;c\c
	cmp	bl,8			;коррекция для 8 с\с
	jne	Not_8
	inc	bx
	jmp short C_F_Scan_Loop
Not_8:	
	cmp	bl,16			;коррекция для 16 с\с
	jne	Not_16
	add	bx,6
Not_16:	
	cld
C_F_Scan_Loop:
	push	cx
	lodsb
	mov	cx,bx
	push	di
	xor	dx,dx			;счетчик
	repne	scasb			;сверяем символ с матрицей
	pop	di
	pop	cx
	jnz	C_F_Error
	loop	C_F_Scan_Loop
	pop	cx si di ds es bp dx bx ax
	clc
	ret
	
C_F_Error:
	pop	cx si di ds es bp dx bx ax
	stc
	ret
Check_Format	endp

;- - - SUBR- - - Check_Sign - - - - - - - -
;INFO  : коррекция знака числа и допустимого максимума
;INPUT : AX - число
;	 SI+2 - знак числа
;OUTOUT: CF = 0 - OK, CF = 1 - ошибка

Check_Sign	proc
	mov	si,word ptr [bp+2]	;смещение строки
	cmp	byte ptr [bp+1],1	;проверка типа числа (знак./беззн.)
	jne	C_S_Unsigned
	cmp	byte ptr [si+2],'-'
	jne	C_S_Positive
	cmp	ax,32768
	ja	C_S_Error
	neg	ax
	clc
	ret
C_S_Positive:	
	cmp	ax,32767
	ja	C_S_Error
C_S_Unsigned:	
	clc
	ret
C_S_Error:
	stc
	ret	
Check_Sign	endp

Basis	dw	0			;основание системы счисления
Cnv_Str_Num	endp	

;########################################################################



COMMENT*
-------------------------  Cnv_Num_Str --------------------
INFO  : преобразование числа в строку символов  с указанием системы
	счисления. Беззнаковое (0..65535), знаковое (-32768..32767)
INPUT : последовательность сохранения параметров в стеке:
	-число (WORD)
	-тип числа (знаковый =0 /беззнаковый =1):BYTE
	-система счисления (2,8,10,16):BYTE
		напр.:000Ah - беззнаковое, 10 с\с
		      0110h - знаковое 16 с\с
		      0002h - беззнаковое 2 с\с	
	-сегмент,
	-смещение строки
	для 2 с\с длина поля 17
OUTPUT: стек: результат обработки
SAVE  :	ALL
*
Cnv_Num_Str	proc	far
	pusha
	mov	ax,seg Field_Length	;длина поля для с\с
	mov	ds,ax
	mov	bp,sp
	add	bp,20			;смещение на 8 регистров + адрес возврата
	mov	ax,word ptr[bp+4]	;тип числа
	mov	byte ptr cs:NBasis,al	;сохраняем с\с
	lea	bx,Field_Length		;матрица длин полей
	xlat
	add	al,ah			;корректируем поле (если число знаковое
					;+1 для знака)
	mov	di,word ptr [bp]	;смещение строки
	xor	ah,ah
	mov	cx,ax			;количество знакомест
	add	di,ax			;смещение на конец поля вывода
	dec	di
	mov	ax,word ptr [bp+2]
	mov	es,ax			;сегмент строки
	mov	ax,word ptr [bp+6]	;обрабатываемое число
	call	Correct_Value		;корректировка значения
	lea	bx,Digits
	std				;пишем справа налево
C_N_Translate_Loop:
	xor	dx,dx
	div	NBasis
	xchg	ax,dx
	xlat				;получаем символ соответствующей
					;цифры из таблицы
	stosb				
	xchg	ax,dx
	loop	C_N_Translate_Loop
	call	Set_Sign		;убираем незначащие нули и ставим знак
	popa
	ret	8			;КОНЕЦ ПРОЦЕДУРЫ
	
;- - - SUBR- - - Correct_Value - - - - - - - -
;INFO  : взятие модуля числа и проверка границ
;INPUT : AX - число
;	 BP+7 - тип числа (0-беззн./1-знак.)
;OUTOUT: AX - модуль числа
;	 если число <0 записываем в первую цифру бата, указывающего тип
;	 числа, 1

Correct_Value	proc
	cmp	byte ptr [bp+5],1
	jne	C_V_Unsigned
	cmp	ax,0
	jge	C_V_Unsigned
	neg	ax
	or	byte ptr [bp+5],10h	;=1 - число <0
C_V_Unsigned:	
	ret
Correct_Value	endp
	
;- - - SUBR- - - Set_Sign - - - - - - - -
;INFO  : удаление незначащих нулей и установка знака
;INPUT : BP+4 - сегмент строки (числа в строковом виде)
;	 BP+2 - смещение строки
;OUTOUT:

Set_Sign	proc
	mov	ax,word ptr [bp+2]	;сегмент строки
	mov	es,ax
	mov	di,word ptr [bp]	;смещение строки
	mov	si,di
	mov	al,30h			;начинаем искать первую значащую
	mov	cx,20			;цифру
	cld
	repe	scasb
	xor	cx,cx
	cmp	byte ptr es:[di-1],'A'	;для чисел 16 с\с ставим 0 перед
	jb	S_S_Not_16		;A-F
	dec	di			;
S_S_Not_16:	
	cmp	byte ptr [bp+5],11h	;11h - знаковое отрицательное число
	jne	S_S_Positive
	dec	di			;сдвигаемся на позицию знака
	dec	di
	mov	byte ptr es:[di],'-'	;ставим знак
	inc	cx			;корректируем количество 0 (зависит от DI)
S_S_Positive:
	add	cx,di			;вычисляем кол-во нулей
	sub	cx,si
	dec	cx
	add	si,cx			;число нулей
	dec	si			;позиция первого нуля справа
	mov	di,si
	cmp	word ptr [bp+6],0	;число = 0 ? Да - оставляем один 0
	jne	S_S_Del_0
	dec	di
S_S_Del_0:	
	std				;затираем нули пробелами справа налево
	mov	al,' '
	rep	stosb			
	ret
Set_Sign	endp

NBasis	dw	0			;основание системы счисления	
Cnv_Num_Str	endp
;##########################################################################
	end