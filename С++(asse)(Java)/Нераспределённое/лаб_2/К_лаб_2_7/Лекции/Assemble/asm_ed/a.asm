model small
.data
kk	db	'hello!$'
.code
aa:	mov	ax,@data
	mov	ds,ax
	lea	dx,kk
	mov	ah,9
	int	21h
	mov	ax,4c00h
	int 21h
end aa