dosseg
;��� ��������� ����� ������������ ������ ������� ��!!!
;������������ SP � �������� �������� ������!!!
;�p�����p� �p���p�������� ����� �� AX � ����. ��p���
;1-� ��p����p - ����� ��p��� ������ (BP+8)
;2-� ��p����p - ��p�� ��p��� ������  (BP+6)
.model small
.data
 d10 dw 10
.stack 20h
.code
Public Myoutput
Myoutput proc far
        push bp
        mov bp,sp
      //  pusha
        push ax
        push bx
        push cx
        push dx
        push di
        push si
        mov si,[bp+6]
        mov di,si
        mov cx,[bp+8]
;������ ������� ������
pr200:  mov byte ptr[si],' '
        inc si
        loop pr200
        mov bl,0
;��������� �������������� �����
        cmp ax,0
        jnl pr20
        mov bl,'-'
        neg ax
pr20:   mov cx,0
;�p���p�������� ����� � ��������� � ����
pr21:   mov dx,0
        div d10
        add dl,30h
        push dx
        inc  cx
        cmp ax,0
        jne pr21
;��������� p��������� � ��p��� ������
        cmp bl,'-'
        jne pr22
        mov byte ptr[di],'-'
        inc di
pr22:   pop dx
        mov byte ptr[di],dl
        inc di
        loop pr22
        pop si
        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        pop bp
        ret 4
Myoutput endp
         end
