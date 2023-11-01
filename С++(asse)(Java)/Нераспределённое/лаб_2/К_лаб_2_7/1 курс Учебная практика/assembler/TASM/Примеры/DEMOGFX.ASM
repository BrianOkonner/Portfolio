VideoSeg	equ 0a000h
.model small
.code
	mov ax,13h
	int 10h
	mov ax,VideoSeg
	mov es,ax
	xor di,di
	cld

	mov cx,-1
L:	
	add al,1
	stosb
	loop L

	mov ah,1
	int 21h

	mov ax,3
	int 10h

	mov ah,4ch
	int 21h
end