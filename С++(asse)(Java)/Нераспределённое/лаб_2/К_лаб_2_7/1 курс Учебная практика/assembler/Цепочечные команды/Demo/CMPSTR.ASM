.model small
.stack 20h
.code
	
;------------------ Cmp_Str ------------------------
;INFO  : сравнение ASCIIZ строки1 со строкой2 (поиск первого несовпадени€)
;	 длина строки < 32000
;INPUT : стек|-->: строка2 (смещение, сегмент), строка1 (смещение, сегмент)
;OUTPUT: стек|-->: результат сравнени€, номер первого несовпавшего символа
;	   –езультат сравнени€:
;		=0 - длина строки1 = длине строки2
;		<0 - строка1 < строки2
;		>0 - строка1 > строки2
;	   Ќомер первого несовпавшего символа:
;		=0  - строки идентичны
;		<>0 - номер символа (1,2,...)
;	   CF: = 1 - длина одной их строк =0
;SAVE  : ALL

public	Cmp_Str
Cmp_Str	proc	far
	pusha
	mov	bp,sp
	mov	es,word ptr [bp+26]
	mov	di,word ptr [bp+24]
	call	Get_Length
	mov	dx,cx
	mov	es,word ptr [bp+22]
	mov	di,word ptr [bp+20]
	call	Get_Length
	mov	bx,dx
	sub	bx,cx
	cmp	bx,0
	jge	C_S_1
	mov	cx,dx
C_S_1:	
	mov	ds,word ptr [bp+22]
	mov	si,word ptr [bp+20]
	mov	es,word ptr [bp+26]
	mov	di,word ptr [bp+24]
	mov	word ptr [bp+24],bx
	mov	ax,cx
	cmp	cx,0
	jne	C_S_2
	cmp	bx,0
	je	C_S_2
	inc	cx
C_S_2:	
	inc	cx
	mov	bx,cx
	mov	dx,cx
	repe	cmpsb
	sub	bx,cx
	cmp	bx,dx
	jne	C_S_4
	xor	bx,bx
C_S_4:	
	mov	word ptr [bp+26],bx
	stc
	pushf
	cmp	ax,0
	je	C_S_5
	popf
	clc
	pushf
C_S_5:	
	popf
	popa
	ret	4
Cmp_Str	endp
;------------------- Get_Length ---------------------
;INFO  : вычисление длины ASCIIZ строки
;INPUT : DI - адрес строки
;OUTPUT: CX - длина
;SAVE  :

Get_Length	proc
	mov	al,0
	mov	cx,-1
	repne	scasb
	neg	cx
	dec	cx
	dec	cx
	ret
Get_Length	endp

;------------------------------------------
	end