;CnvStrNum	StrSeg,StrOffset,Type,Notation
;�८�ࠧ������ ��ப� � �᫮
;
;CnvStrNum	ᥣ����_��ப�,ᬥ饭��_��ப�, ⨯_�᫠,��⥬�_��᫥���
;
;	⨯_�᫠:BYTE
;		00 - �����������
;		01 - ��������
;
;	��⥬�_��᫥���:BYTE
;       	2,8,10,16
; ��������� � ��
;
;  !!! ATTENTION !!!!
;	������ ������ ���� ���������� �������:
;	�� �᫮,������⢮ ���,ᮡ�⢥��� �᫮ � ��ப���� ����
;	����.:
;		12,4,'3245'
;	----------------------------------------------------------
;
;CnvNumStr	Number,Type,Notation,StrSeg,StrOffset
;�८�ࠧ������ �᫠ � ��ப�
;
;CnvNumStr	�᫮:WORD, ⨯_�᫠:BYTE, ��⥬�_��᫥���:BYTE,
;		ᥣ����_��ப�,	ᬥ饭��_��ப�
;
;	----------------------------------------------------------
;
;________________________________________________________________________
extrn Cnv_Str_Num:far, Cnv_Num_Str:far
;________________________________________________________________________

CnvStrNum	macro	StrSeg,StrOffset,Type,Notation
	mov	ax,StrSeg
	push	ax
	mov	ax,StrOffset
	push	ax
	mov	ah,Type
	mov	al,Notation
	push	ax
	call	Cnv_Str_Num
	pop	ax
	endm
;-----------------------------------------------------

CnvNumStr	macro	Number,Type,Notation,StrSeg,StrOffset
	push	ax
	mov	ax,Number
	push	ax
	mov	ah,Type
	mov	al,Notation
	push	ax
	mov	ax,StrSeg
	push	ax
	mov	ax,StrOffset
	push	ax
	call	Cnv_Num_Str
	pop	ax
	endm
;-----------------------------------------------------	
