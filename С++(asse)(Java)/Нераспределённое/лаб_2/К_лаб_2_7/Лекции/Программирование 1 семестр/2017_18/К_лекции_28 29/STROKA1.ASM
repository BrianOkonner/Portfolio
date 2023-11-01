; Операции со строками
 dosseg
 .model small
 .stack 100h
 .data
  h_vv   db  50,50 dup (?)
  hello  db  'Введи строку !',10,13,'$'
  h_main db  '12345'
  hello1 db  'Cтрокa !',10,13,'$'
  NE_st  db  'Не совп !',10,13,'$'
  EQU_st db  'Cовп !',10,13,'$'
  _NE    db  'Нет нуля !',10,13,'$'
  _NUL   db  'ЕСть нуль !',10,13,'$'
  h_viv  db  50 dup (?)
 .code
  my_prog:
    mov  AX,@data
    mov  DS,AX
    mov  ES,AX
; чистка буфера ввода
;---------------------
    cld            ;слева направо
;   sld            ;справо налево
    mov cx,50
    mov al,' '
    lea di,h_viv   ;приемник: ES:DI
 rep stosb
;   ввод и пересылка данных
;   из ввода в вывода
    mov DX,offset Hello
    mov Ah,9
    int 21h
    mov DX,offset H_vv
    mov Ah,10
    int 21h
    xor cx,cx
    lea di,h_viv   ;приемник: ES:DI
    lea si,h_vv    ;источник: DS:Si
    lodsb
    lodsb
    mov cl,al
    rep movsb  ;сравнивает пока СХ<>0
    mov ax,0a0dh
    stosw
    mov al,'$'
    stosb
;   вывод  данных
;-----------------------
    mov DX,offset Hello1
    mov Ah,09h
    int 21h
    mov DX,offset H_viv
    mov Ah,9h
    int 21h
; сравнивание строк
;--------------------
    lea di,h_main   ;приемник: ES:DI
    lea si,h_vv     ;источник: DS:Si
    lodsb
    lodsb
    mov cl,al
;    CMPSW при сравнении переставляет байты,
;    вместо > может получиться <
;    верный результат , если - числовые данные
     repe cmpsb   ;сравнивает пока СХ<>0 и ZF=1
                  ;т.е. пока строки совпадают
                  ; ищет несовпадающие символы
    jcxz  _EQU    ; перейти , если CX=0
    lea DX,NE_st
    mov Ah,9h
    int 21h
    jmp kon
_EQU:
    lea DX,EQU_st
    mov Ah,9h
    int 21h
kon:
;   поиск нулей
;---------------
    lea di,h_vv     ;источник: ES:DI
    lodsb
    lodsb
    mov cl,al
    mov al,'0'
    lea si,h_vv
 repne scasb      ;сравнивает пока СХ<>0 и ZF=0
                  ;т.е. пока не нуль
    jcxz  _NE_0   ; перейти , если CX=0
    lea DX,_NUL
    mov Ah,9h
    int 21h
    jmp kon1
_NE_0:
    lea DX,_NE
    mov Ah,9h
    int 21h
kon1:
    mov AH,4CH
    int 21h
  end my_prog
