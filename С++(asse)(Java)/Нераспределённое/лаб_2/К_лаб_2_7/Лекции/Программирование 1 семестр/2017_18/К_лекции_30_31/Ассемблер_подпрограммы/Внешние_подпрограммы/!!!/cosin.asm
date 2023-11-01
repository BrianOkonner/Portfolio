.386
.model flat
.data
 
.code
Public _Cosinasm
		_Cosinasm proc
		fld qword ptr [esp+4]	
		fcos 
		ret 		
_Cosinasm endp
end					