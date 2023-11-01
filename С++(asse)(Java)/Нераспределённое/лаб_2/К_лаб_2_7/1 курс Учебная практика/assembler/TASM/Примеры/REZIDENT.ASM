;!!!!!!!!!!!com file only!!!!!!!!!!!!!!!!
.model tiny
.code
        org     100h
start:
;получаем вектор прерывания
;в регистровую пару ES:BX
        mov     ah,35h
        mov     al,1ah       ;номер прерывания
                             ;(int 1ah - пользовательский таймер )
        int     21h
;запоминаем старый вектор
        mov     ax,es
        mov     ad,ax
        mov     adm,bx
;Заносим адрес начала резидентной части
;в регистровую пару DS:DX
        mov     dx,cs
        mov     ds,dx
        lea     dx,nach
;Устанавливаем вектор прерывания
;на наш резидент
        mov     al,1ah       ;номер прерывания
                             ;(int 1ah - пользовательский таймер )
        mov     ah,25h
        int     21h
;Выход из программы
;оставляя резидент в памяти
        mov     ah,31h
        mov     al,0
        mov     dx,100       ;размер резидентной части в
                             ;16-ти байтовых параграфах
        int     21h
NACH:
;резидентная часть программы
;запоминаем все регистры, которые могут
;измениться в результате работы тела резидента
        pushf
        push    ds
        push    dx
        push    si
;начало тело резидента
        mov     dx,0b800h
        mov     ds,dx
        mov     si,1994
        mov     byte ptr [si],'H'       ;Вывод в центр техтового экрана
        mov     byte ptr [si+2],'e'     ;Сообщения Hello!
        mov     byte ptr [si+4],'l'
        mov     byte ptr [si+6],'l'
        mov     byte ptr [si+8],'o'
        mov     byte ptr [si+10],'!'
;конец  тела резидента
;восстанавливаем регистры
        pop     si
        pop     dx
        pop     ds
        popf
;jmp far на старый вектор прерываеия
        db      0eah
adm     dw      ?
ad      dw      ?
end start
