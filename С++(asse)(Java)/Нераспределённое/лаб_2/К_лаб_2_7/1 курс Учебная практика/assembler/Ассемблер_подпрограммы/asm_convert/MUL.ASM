dosseg; ПРОИЗВЕДЕНИЕ
.model small
.stack 100h
.data
vvstr db '          $'
.code
 extrn Myoutput:far

    mov ax,@data
    mov ds,eax
    mov ax,100
    mov cx,2
    mul cx 
;вывод pезультата
    mov dx,10  ;длина стpоки вывода
    push dx
    lea dx,vvstr
    push dx
    call Myoutput
    mov ah,9
    lea dx,vvstr
    int 21h

    mov ah,4ch
    int 21h
End
 