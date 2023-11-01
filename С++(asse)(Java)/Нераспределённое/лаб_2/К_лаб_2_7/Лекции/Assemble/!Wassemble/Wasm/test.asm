.model small
.stack 100h
.data
	str1      db 255 dup (?)
.code
extrn   writenum:far
start:
	mov	ax,@data
	mov	ds,ax

	mov	ah,2Ch
	int	21h

	xor	ah,ah
	mov	al,dh

	xor	dx,dx
	mov	bl,ch
	xor	bh,bh
	mul	bx

	add	al,cl


	mov	dx,1
	push	dx
	mov	dx,10
	push	dx
	call	writenum

@exit:
; ----- Завершение работы -----
	mov	ah,4ch
	int	21h
end start
end.