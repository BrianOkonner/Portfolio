dosseg;��������� �᫠ �� 2
.model small
.stack 100h
.data
str1  db '������ ��ப�:$'
str2  db '�������:$'
; ��p��� �뢮��
strvv db '          ',0ah,0dh,'$'
;  ��p��� �����
vvstr db 80,81 dup(?)
kol dw 0
.code
 extrn Myinput:far
 extrn Myoutput:far
 extrn crlf:far
;���� � �p���p��������
    mov ax,@data
    mov ds,ax
    mov ah,9
    lea dx,str1
    int 21h
    lea dx,vvstr
    mov ah,10
    int 21h
    mov dx,0
    mov dl,vvstr+1
    push dx
    xor si,si
    mov kol,0
    mov cx,dx
; ��ࢮ��砫�� ���� ???
;-----------------------
z1: mov al,vvstr[si+2] 
    cmp al,' '
    jne else1
then1: inc kol
else1: inc si   
    loop z1
;��騩 ����
;-----------
	mov cx,dx
	mov si,2
z11:	mov al,vvstr[si]
 	cmp al,' '
        je else2
then2:  mov bl,vvstr[si]
        mov di,si
        mov kol,0
        inc dx
 	inc dx
z2:     cmp di,dx
        jge endz2
	cmp bl,vvstr[di]             
	jne else3
then3:	inc kol
        mov al,' '
 	mov vvstr[di],al
else3:  inc di
	jmp z2
endz2:
;�뢮� p������
    call crlf
    mov ah,9
    lea dx,str2
    int 21h
    mov ax,kol
    mov dx,10  ;����� ��p��� �뢮��
    push dx
    lea dx,strvv
    push dx
    call Myoutput
    mov ah,9
    lea dx,strvv
    int 21h
else2: inc si
    loop z11
    mov ah,4ch
    int 21h
End
 