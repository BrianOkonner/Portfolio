.386
.model flat
.data
	e dq 0.00000000001
	f1 dq 1.0
	f2 dq 2.0
	cos dq 1.0
	s1 dq 1.0
	s2 dq ?
	z dq 1.0
	doubl dq 2.0
.code
Public _Cosin
		_Cosin proc
		fld qword ptr [esp+4]	
		fmul st(0),st(0)
		fst s2	
		
		fld1
		fst s1
		fst f1
		fst cos
		
		fld1
		fmul doubl
		fst f2									 

sign:
		finit

		fld s1
		fmul s2
		fdiv f1
		fdiv f2
		fchs  
		fstp s1

		fld f1
		fadd doubl
		fst f1

		fld f2
		fadd doubl
		fst f2

		fld cos
		fadd s1
		fst cos

		fld s1
		fabs
		fst z
		
		fld z
		fcomp e
		fstsw  ax
		fstp z 
		test ax,1 shl 8
		jz sign

		fld cos 
		ret 		
_Cosin endp
end															