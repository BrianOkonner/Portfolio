;!!!!!!!!!!!com file only!!!!!!!!!!!!!!!!
.model tiny
.code
        org     100h
start:
;����砥� ����� ���뢠���
;� ॣ���஢�� ���� ES:BX
        mov     ah,35h
        mov     al,1ah       ;����� ���뢠���
                             ;(int 1ah - ���짮��⥫�᪨� ⠩��� )
        int     21h
;���������� ���� �����
        mov     ax,es
        mov     ad,ax
        mov     adm,bx
;����ᨬ ���� ��砫� १����⭮� ���
;� ॣ���஢�� ���� DS:DX
        mov     dx,cs
        mov     ds,dx
        lea     dx,nach
;��⠭�������� ����� ���뢠���
;�� ��� १�����
        mov     al,1ah       ;����� ���뢠���
                             ;(int 1ah - ���짮��⥫�᪨� ⠩��� )
        mov     ah,25h
        int     21h
;��室 �� �ணࠬ��
;��⠢��� १����� � �����
        mov     ah,31h
        mov     al,0
        mov     dx,100       ;ࠧ��� १����⭮� ��� �
                             ;16-� ���⮢�� ��ࠣ���
        int     21h
NACH:
;१����⭠� ���� �ணࠬ��
;���������� �� ॣ�����, ����� �����
;���������� � १���� ࠡ��� ⥫� १�����
        pushf
        push    ds
        push    dx
        push    si
;��砫� ⥫� १�����
        mov     dx,0b800h
        mov     ds,dx
        mov     si,1994
        mov     byte ptr [si],'H'       ;�뢮� � 業�� ��⮢��� ��࠭�
        mov     byte ptr [si+2],'e'     ;����饭�� Hello!
        mov     byte ptr [si+4],'l'
        mov     byte ptr [si+6],'l'
        mov     byte ptr [si+8],'o'
        mov     byte ptr [si+10],'!'
;�����  ⥫� १�����
;����⠭�������� ॣ�����
        pop     si
        pop     dx
        pop     ds
        popf
;jmp far �� ���� ����� ���뢠���
        db      0eah
adm     dw      ?
ad      dw      ?
end start
