.model small
.data
n db ?
.code
a:
mov ax,@data
mov ds,ax
mov ah,1
int 21h
mov dl,al
int 21h
mov cl,al
mov ah,2
add dl,1
cmp dl,cl
je @2
cmp dl,cl
jb @1
sub dl,1
mov al,dl
mov dl,cl
mov cl,al
add dl,1
@1:int 21h
add dl,1
cmp cl,dl
ja @1
@2 mov ah,4ch
int 21h 
end a