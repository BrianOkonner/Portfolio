;CnvStrNum	StrSeg,StrOffset,Type,Notation
;Преобразование строки в число
;
;CnvStrNum	сегмент_строки,смещение_строки, тип_числа,система_счисления
;
;	тип_числа:BYTE
;		00 - беззнаковое
;		01 - знаковое
;
;	система_счисления:BYTE
;       	2,8,10,16
; РЕЗУЛЬТАТ В АХ
;
;  !!! ATTENTION !!!!
;	СТРОКА ДОЛЖНА БЫТЬ СЛЕДУЮЩЕГО ФОРМАТА:
;	любое число,количество цифр,собственно число в строковом виде
;	напр.:
;		12,4,'3245'
;	----------------------------------------------------------
;
;CnvNumStr	Number,Type,Notation,StrSeg,StrOffset
;Преобразование числа в строку
;
;CnvNumStr	число:WORD, тип_числа:BYTE, система_счисления:BYTE,
;		сегмент_строки,	смещение_строки
;
;	----------------------------------------------------------
;
;________________________________________________________________________
extrn Cnv_Str_Num:far, Cnv_Num_Str:far
;________________________________________________________________________

CnvStrNum	macro	StrSeg,StrOffset,Type,Notation
	mov	ax,StrSeg
	push	ax
	mov	ax,StrOffset
	push	ax
	mov	ah,Type
	mov	al,Notation
	push	ax
	call	Cnv_Str_Num
	pop	ax
	endm
;-----------------------------------------------------

CnvNumStr	macro	Number,Type,Notation,StrSeg,StrOffset
	push	ax
	mov	ax,Number
	push	ax
	mov	ah,Type
	mov	al,Notation
	push	ax
	mov	ax,StrSeg
	push	ax
	mov	ax,StrOffset
	push	ax
	call	Cnv_Num_Str
	pop	ax
	endm
;-----------------------------------------------------	
