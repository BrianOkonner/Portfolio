; C������� ⥪�⮢��� 䠩��
;   30 ������ 1996 ����
;       �㭪�� 3ch - ᮧ����� 䠩��
;  �室 CX     - ��ਡ�� 䠩��
;       DS:DX  - ���� ASCIIZ-��ப� ����� 䠩��
;  ��室 AX    - �����᪨� �����
;      �㭪�� 40h - ������ � 䠩�
;  �室 BX     - ��ਡ�� 䠩��
;       CX     - ��� �����뢠���� ����
;       DS:DX  - ���� ����
;  ��室 AX    - �᫮ ����ᠭ��� ����
;      �㭪�� 3eh - �����⨥ 䠩��
;  �室 BX     - �����᪨� �����  䠩��
;                        ����� ���������� ���� �訡��
dosseg
.model small
.stack 20h
.data
file_name db 'file.txt',0
handle    dw 0
text1     db 10,13,'䠩� �� �����','$'
text2     db 10,13,'�����','$'
vv        db '12345678901234567890999$$$$$$$$$'
.code
go:        mov ax,@data
           mov ds,ax
         mov cx,5
nach:         mov ah,40h
         lea dx,vv+2
         int 21h
;         loop nach
          mov ah,4ch
          int 21h
end go

