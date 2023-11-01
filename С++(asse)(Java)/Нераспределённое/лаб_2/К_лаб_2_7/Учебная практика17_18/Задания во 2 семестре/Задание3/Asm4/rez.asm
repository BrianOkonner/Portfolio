.386
.model flat
.data
 
 rez dq ?
 j   dq  2.0
 l   dq  1.0
 k   dq  10.0

.code
Public _Result
		_Result proc
				
		finit
		;fld rez 
		fld qword ptr [esp+4]

		fsin
		fldlg2
		;fld rez
		fld qword ptr [esp+4]
		
		fyl2x
		fld j
		fmulp st(1) , st
		fld l
		faddp st(1), st
		fdivp st(1) , st
		fld k
		fmulp st(1) , st
	
	ret
	
_Result endp
end				