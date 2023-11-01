.model small
.data
  a db ?
  b db ?
  str1 db 'Введите код первого символа ','$'
.code
main:	
	mov ax,@data
	mov ds,ax
	
	lea ds,str1
	mov ah,9
	int 21h
	
	
end	main
	
