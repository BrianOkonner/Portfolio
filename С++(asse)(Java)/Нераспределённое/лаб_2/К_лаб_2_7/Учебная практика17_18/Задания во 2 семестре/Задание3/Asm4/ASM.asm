.386
.model flat
.data
		x dq   ?; 

		eps dq 0.00000001; погрешность
			
		i    dd 2
 
.code
Public _Mysin
		_Mysin proc
finit

		fld qword ptr [esp+4]	
		fstp x

		
		fld x
		fmul st,st;  st(0)=x*х
		fld x
			fld st
	a0: fabs
		fcom eps  ;|N| < Eps ?
		fstsw ax
		sahf
		jb exit
		fmul st,st(2); N*x*x
		test i,2     ; менять знак или нет?
		jz a1
		fchs

	a1: fidiv i      ; N*x*x/i
		inc i
		fidiv i      ; N*x*x/(i*(i+1))
		inc i        ; i = i + 2
		fadd st(1),st; SinT = SinT + N*x*x/(i*(i+1))
		jmp a0
	exit:   fxch st(1)
		

    ret	
_Mysin endp
end			