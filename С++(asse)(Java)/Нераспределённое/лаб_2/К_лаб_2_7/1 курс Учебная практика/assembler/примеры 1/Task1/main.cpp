//Ўаповалов —танислав «адача B11

//«адан текстовый файл Input.txt, состо€щий  из слов. 
//–азделител€ми между словами €вл€етс€ некоторое множество знаков препинани€. 
//Ќайти в каждой строке  пары подр€д сто€щих слов, у которых одинаковое количество прописных букв, 
//удалить и дописать первое слово из пары в начало  строки, второе - в конец строки.   
//–езультат записать  в новый файл Output.txt. 
//”пор€дочить слова  в полученных  строках по  убыванию длин слов, результат сортировки записать в файл Out_sort.txt. 
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int num(char* a,char* b)//функци€ подсчЄта количества строчных букв
{
	int kol=0;
		
	for(int zx=0;zx<(int)strlen(a);zx++)//цикл по буквам слова,в котором считаем
	{
		
	for(int q=0;q<(int)strlen(b);q++)//цикл по буквам слова,в котором перечислены строчные буквы
		if(a[zx]==b[q]) {kol++;goto here;}//проверка на совпадение и выход из цикла	
here:;
	}


	return kol;
}

void main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	FILE *sort=fopen("out_sort.txt","w");
	char *raz=" ,.!&;",*tex;
	char **s;
	char *prop="qazxswedcvfrtgbnhyujmkiolp";


	s=(char**)malloc(101*sizeof(char*));//создаЄм массив строк
	for(int i=0;i<100;i++)
		s[i]=(char*)malloc(100);
	
	
	tex=(char*)malloc(80);

	while(fgets(tex,100,in))
	{
		//читаем из файла
	puts(tex);//выводим input.txt


	char *p;//первый раз берЄм слово
	s[0]=p=strtok(tex,raz);
int k=0;

int i=0;
	while(p)//берЄм слова все остальные разы
	{
		i++;
		//puts(p);
		
		p=strtok(NULL,raz);
		s[i]=p;
		
	}
	//unsigned int hhh=strlen(s[i-1]);
	unsigned int hhh;
	//char* www;
	_asm
	{
		mov eax,i
			dec eax
			mov edi,s
			mov edi,[edi+4*eax]
		mov esi,[edi]
		//mov www,esi
		mov al,'\0'
			mov ebx,20
			mov ecx,20
			repne scasb
			sub ebx,ecx
			sub ebx,2
			mov hhh,ebx

			mov edi,s
			mov eax,i
			dec eax
			mov edx,[edi+4*eax]
			
				mov al,byte ptr [edx+ebx]
			cmp al,'\n'
			jne end
			
			mov [edx+ebx],'\0'

end:
	}
	//if(s[i-1][hhh-1]=='\n') (s[i-1][hhh-1]='\0');


	
	//if(s[i-1][hhh-1]=='\n') (s[i-1][hhh-1]='\0');
for(int j=0;j<i-1;j++)//цикл проверки на равное кол-во прописных букв соседних слов и перемещени€ строк влево и вправо
{
	if ((num(s[j],prop))==(num(s[j+1],prop)))//сравниваем кол-ва прописных букв
	{
		char* temp;

		_asm
		{
			mov eax,dword ptr [j]
			mov ecx,dword ptr [s]
			mov edx,dword ptr [ecx+eax*4]
			mov dword ptr [temp],edx
		}
		//temp=s[j];//сохран€ем s[j]
		//for(int k=j-1;k>=0;k--)//пододвигаем вправо элементы с 0 по (j-2)-й
		//s[k+1]=s[k];


_asm
{
	mov ecx,j
		dec ecx
		mov edx,s
here:
		mov eax,[edx+ecx*4]
		inc ecx
		mov [edx+4*ecx],eax
		dec ecx
		cmp ecx,0
		dec ecx
		jge here

		//s[0]=temp;//переносим j-й элемент влево.
		mov eax,dword ptr [s]
		mov ecx,dword ptr [temp]
		mov dword ptr [eax],ecx


		//temp=s[j+1];
		mov eax,dword ptr [j]
		mov ecx,dword ptr [s]
		mov edx,dword ptr [ecx+eax*4+4]
		mov dword ptr [temp],edx
}
		int kk;
		//for(kk=j+2;kk<i;kk++)
		//	s[kk-1]=s[kk];//пододвигаем влево
_asm
{
	mov ebx,j
		add ebx,2
		mov kk,ebx
here3:
		mov edx,i
		cmp ebx,edx
		jnl end3

			mov eax,dword ptr [kk]
		mov ecx,dword ptr [s]
		mov edx,dword ptr [kk]
		mov esi,dword ptr [s]
		mov edx,dword ptr [esi+edx*4]
		mov dword ptr [ecx+eax*4-4],edx
		inc ebx
		mov kk,ebx
		jmp here3
end3:

		mov eax,dword ptr [i] 
		mov ecx,dword ptr [s] 
		mov edx,dword ptr [temp] 
		mov dword ptr [ecx+eax*4-4],edx 
}	
		//s[i-1]=temp;
	}
}

//s[i-1][strlen(s[i-1])-2]='\0';
for(int j=0;j<i;j++)//запись в output.txt
{
	fputs(s[j],out);fprintf(out," ");
}
fprintf(out,"\n");
char* temp;
int j;
//for(k=0;k<i;k++)//сортировка пузырьком
//{
//	for(int j=0;j<i-1-k;j++)
//	if(strlen(s[j])>strlen(s[j+1])) {char* temp=s[j];s[j]=s[j+1];s[j+1]=temp;}//мен€ем местами если надо
//}

_asm
{
	mov  dword ptr [k],0
jmp  jmp1
jmp6:
mov  eax,dword ptr [k]     //k++
add  eax,1


mov  dword ptr [k],eax

jmp1:
mov  eax,dword ptr [k]
cmp  eax,dword ptr [i]
jge  end5					//if (k>=i)


mov  dword ptr [j],0
jmp  jmp2

jmp5:
mov  eax,dword ptr [j]	//j++
add  eax,1
mov  dword ptr [j],eax

jmp2:
mov  eax,dword ptr [i]
sub  eax,1
sub  eax,dword ptr [k]
cmp  dword ptr [j],eax //if(j>=i-1-k)
jge  jmp3

mov  eax,dword ptr [j]
mov  ecx,dword ptr [s]
mov  edi,dword ptr [ecx+eax*4+4] //edx=s[j+1]
mov esi,[edi]
//push edx
//call strlen

		//mov esi,[edi+4*eax]
		//mov www,esi
		mov al,'\0'
			mov ebx,20
			mov ecx,20
			repne scasb
			sub ebx,ecx

mov edx,ebx



//mov ebx,eax
//add esp,4
mov  eax,dword ptr [j]
mov  ecx,dword ptr [s]
mov  edi,dword ptr [ecx+eax*4] //edx=s[j]
mov esi,[edi]
//push edx


		//mov esi,[edi+4*eax]
		//mov www,esi
		mov al,'\0'
			mov ebx,20
			mov ecx,20
			repne scasb
			sub ebx,ecx

//mov edx,ebx


//call strlen
//add  esp,4
cmp  edx,ebx
jle  jmp4				//(strlen(s[j-1])>strlen(s[j]))?
mov  eax,dword ptr [j]
mov  ecx,dword ptr [s]
mov  edx,dword ptr [ecx+eax*4]   //edx=s[j]
mov  dword ptr [temp],edx		//temp=s[j]
mov  eax,dword ptr [j]
mov  ecx,dword ptr [s]
mov  edx,dword ptr [j]
mov  esi,dword ptr [s]
mov  edx,dword ptr [esi+edx*4+4] //edx=s[j+1]
mov  dword ptr [ecx+eax*4],edx		//s[j]=s[j+1]
mov  eax,dword ptr [j]
mov  ecx,dword ptr [s]
mov  edx,dword ptr [temp]
mov  dword ptr [ecx+eax*4+4],edx	//s[j+1]=temp

jmp4:
jmp  jmp5

jmp3:

jmp  jmp6

end5:
}


for(int j=0;j<i;j++)//запись в out_sort.txt
{
	fputs(s[j],sort);fprintf(sort," ");
}
fprintf(sort,"\n");
	}
}