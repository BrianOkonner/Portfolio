; ����樨 � ��ப���
 dosseg
 .model small
 .stack 100h
 .data
  h_vv   db  50,50 dup (?)
  hello  db  '����� ��ப� !',10,13,'$'
  h_main db  '12345'
  hello1 db  'C�பa !',10,13,'$'
  NE_st  db  '�� ᮢ� !',10,13,'$'
  EQU_st db  'C��� !',10,13,'$'
  _NE    db  '��� ��� !',10,13,'$'
  _NUL   db  '���� ��� !',10,13,'$'
  h_viv  db  50 dup (?)
 .code
  my_prog:
    mov  AX,@data
    mov  DS,AX
    mov  ES,AX
; ��⪠ ���� �����
;---------------------
    cld            ;᫥�� ���ࠢ�
;   sld            ;�ࠢ� ������
    mov cx,50
    mov al,' '
    lea di,h_viv   ;�ਥ����: ES:DI
 rep stosb
;   ���� � ����뫪� ������
;   �� ����� � �뢮��
    mov DX,offset Hello
    mov Ah,9
    int 21h
    mov DX,offset H_vv
    mov Ah,10
    int 21h
    xor cx,cx
    lea di,h_viv   ;�ਥ����: ES:DI
    lea si,h_vv    ;���筨�: DS:Si
    lodsb
    lodsb
    mov cl,al
    rep movsb  ;�ࠢ������ ���� ��<>0
    mov ax,0a0dh
    stosw
    mov al,'$'
    stosb
;   �뢮�  ������
;-----------------------
    mov DX,offset Hello1
    mov Ah,09h
    int 21h
    mov DX,offset H_viv
    mov Ah,9h
    int 21h
; �ࠢ������� ��ப
;--------------------
    lea di,h_main   ;�ਥ����: ES:DI
    lea si,h_vv     ;���筨�: DS:Si
    lodsb
    lodsb
    mov cl,al
;    CMPSW �� �ࠢ����� ����⠢��� �����,
;    ����� > ����� ��������� <
;    ���� १���� , �᫨ - �᫮�� �����
     repe cmpsb   ;�ࠢ������ ���� ��<>0 � ZF=1
                  ;�.�. ���� ��ப� ᮢ������
                  ; ��� ��ᮢ�����騥 ᨬ����
    jcxz  _EQU    ; ��३� , �᫨ CX=0
    lea DX,NE_st
    mov Ah,9h
    int 21h
    jmp kon
_EQU:
    lea DX,EQU_st
    mov Ah,9h
    int 21h
kon:
;   ���� �㫥�
;---------------
    lea di,h_vv     ;���筨�: ES:DI
    lodsb
    lodsb
    mov cl,al
    mov al,'0'
    lea si,h_vv
 repne scasb      ;�ࠢ������ ���� ��<>0 � ZF=0
                  ;�.�. ���� �� ���
    jcxz  _NE_0   ; ��३� , �᫨ CX=0
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