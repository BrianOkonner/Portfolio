//yadlovskiy
int suma(int a)
{
	int x=0;
	_asm
	{
		xor esi, esi
		mov x,0
		mov eax,a
		mov ebx,10
	while_:
		mov ecx, 1
		xor edx, edx
		cmp eax,0
	jle end_
		div ebx
		imul ecx,edx
		imul ecx,edx
		imul ecx, edx
		add x, ecx

		jmp while_
end_:
		
	}
	return x;
}


void postroenie_posledovatel(int *Matr)
{
	int i=1;
	while (Matr[i]!=153)
	{
		Matr[i+1]=suma(Matr[i]);
		++i;
	}
}
//yadlovskiy