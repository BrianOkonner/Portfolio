title nod.asm
 .model small
 .stack 100h
;****************
 .data 
  d10  db 10
  te1  db 'Введите a___','$'
  te2  db 0ah,0dh,'Введите b___','$'
  text db 0ah,0dh,0ah,0dh,' НОД = ','$'
  res  db 10,13,' НОК= ',2 dup (?),'$'
;*****************
 .code 
 ;****************************************
 ; Программа нахождеия Наибольшего Общего Делителя
 ; и Наименьшего Общего Кpатного
 ;****************************************
 nach:mov ax,@data
      mov ds,ax
  ;-------------------------------
      lea dx,te1 ;вывод строки запроса
      mov ah,9   ;
      int 21h    ;
  ;--------------------------------
      mov ah,1   ;ввод a 
      int 21h    ;
      sub al,30h ;a:=a-30h
      xor bx,bx  ;чистка bx
      mov bl,al  ;bl:=a
  ;-------------------------------
      lea dx,te2 ;вывод строки запроса 
      mov ah,9   ;
      int 21h    ;
  ;-------------------------------
      mov ah,1   ;ввод b
      int 21h    ;
      sub al,30h ;b:=b-30h
      xchg al,bl ;al:=a,bl:=b
 ;сохpанение чисел в стеке 
      push bx
      push ax
 ;нахождение НОД
 ;---------------------------------
 loop1: cmp al,bl    ;пока a<>b выполнять
       je  kon
       jg  then1    ;если а>b to a=a-b
 else1:sub bl,al    ;иначе b=b-a
       jmp kloop
 then1:sub al,bl    ;НОД=bl
 kloop:nop
       jmp loop1
 kon:  nop
 ;нахождение НОК
       pop ax
       pop dx
       mul dl
       div bl       ;HOK 
       push ax      ; в стеке
 ;вывод HOД
 ;--------------------------------------
       mov ah,9
       lea dx,text
       int 21h      
       mov ah,2
       add bl,30h   
       mov dl,bl
       int 21h
 ;вывод НОК
 ;-----------------------------------------
       pop ax
       cbw 
       div d10
       add ah,30h
       mov res+9,ah
       add al,30h 
       mov res+8,al
       lea dx,res
       mov ah,9
       int 21h 
 ;-------------------------------------  
       mov ah,4ch
       int 21h
 end nach
