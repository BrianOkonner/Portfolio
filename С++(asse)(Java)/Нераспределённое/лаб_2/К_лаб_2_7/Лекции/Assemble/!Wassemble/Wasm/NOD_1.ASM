title nod.asm
 .model small
 .stack 100h
;****************
 .data 
  d10  db 10
  te1  db '������ a___','$'
  te2  db 0ah,0dh,'������ b___','$'
  text db 0ah,0dh,0ah,0dh,' ��� = ','$'
  res  db 10,13,' ���= ',2 dup (?),'$'
;*****************
 .code 
 ;****************************************
 ; �ணࠬ�� ��宦���� �������襣� ��饣� ����⥫�
 ; � �������襣� ��饣� �p�⭮��
 ;****************************************
 nach:mov ax,@data
      mov ds,ax
  ;-------------------------------
      lea dx,te1 ;�뢮� ��ப� �����
      mov ah,9   ;
      int 21h    ;
  ;--------------------------------
      mov ah,1   ;���� a 
      int 21h    ;
      sub al,30h ;a:=a-30h
      xor bx,bx  ;��⪠ bx
      mov bl,al  ;bl:=a
  ;-------------------------------
      lea dx,te2 ;�뢮� ��ப� ����� 
      mov ah,9   ;
      int 21h    ;
  ;-------------------------------
      mov ah,1   ;���� b
      int 21h    ;
      sub al,30h ;b:=b-30h
      xchg al,bl ;al:=a,bl:=b
 ;��p������ �ᥫ � �⥪� 
      push bx
      push ax
 ;��宦����� ���
 ;---------------------------------
 loop1: cmp al,bl    ;���� a<>b �믮�����
       je  kon
       jg  then1    ;�᫨ �>b to a=a-b
 else1:sub bl,al    ;���� b=b-a
       jmp kloop
 then1:sub al,bl    ;���=bl
 kloop:nop
       jmp loop1
 kon:  nop
 ;��宦����� ���
       pop ax
       pop dx
       mul dl
       div bl       ;HOK 
       push ax      ; � �⥪�
 ;�뢮� HO�
 ;--------------------------------------
       mov ah,9
       lea dx,text
       int 21h      
       mov ah,2
       add bl,30h   
       mov dl,bl
       int 21h
 ;�뢮� ���
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
