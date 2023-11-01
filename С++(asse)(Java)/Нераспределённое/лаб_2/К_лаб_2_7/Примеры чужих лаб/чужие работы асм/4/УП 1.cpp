/*Мацкевич Максим ПМ 8
В 8
Задан текстовый файл Input.txt, состоящий  из слов.
Разделителями между словами является некоторое множество знаков препинания. 
Найти в каждой строке  слова, состоящие из заглавных букв, удалить и дописать в начало  строки.  
Результат записать  в новый файл Output.txt.
Упорядочить слова  в полученных  строках по  убыванию длин слов
результат сортировки записать в файл Out_sort.txt. 

Решение 
1) Разбиваем текст (s) на слова. Проверяем слова на  "Заглавность"(Ф-ЦИЯ НА АССЕМБЛЕРЕ).
Заглавные слова в каждой строчке сохраняем в новый массив строк (text[i]) и
удаляем из текста (Ф-ЦИЯ НА АССЕМБЛЕРЕ)(s).  Потом необходимую строку получаем соединив массив сторк
из заглавных слов с исходным массивом строк (в котором заглавные слова удалены).
2)Попутно с решением п.1 будем сохранять максимальную длину слова в в каждой строке.(max[i])
Чтобы отсортировать каждую строку по убыванию длин слова, сначала ищем слова с длиной
равной max ,  затем с длинной max-1  ... до 1. 

3) Строкоые команды  выполним на ассемблере
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
using namespace std;
int strlen_asm(char *s);        //asm
char * strcpy_asm(char *c, char *a);  //asm
void swap_asm(char *a,char *b);
bool zaglavn_asm(char *s);          //asm
char * strcat_asm(char *a, char *b);  //asm
void delete_s_asm(char *s,char *s1);   //asm

bool comp(char s)
{ int i=(int)s;
	if (i>=-64 && i<=-33     ||    i>=65  &&  i<=90) return 1;
else return 0;
}
 
int main()
{
char s[100][200],text[100][200],*sl,zag[200],r[]={",.!?:;- "};
int i,j,n,*max;
ifstream in;    in.open("input.txt");            
ofstream out;   out.open("output.txt"); 
ofstream f;     f.open("out_sort.txt");
for (i=0; i<100; i++)    {
in.getline(s[i],200);
if (!s[i][0]) break;
strcpy_asm(text[i],s[i]);
    }

n=i;
max=new int[n];
for (i=0; i<n; i++)
max[i]=0;
strcpy_asm(zag,"");

for (i=0; i<n; i++)    
{


sl=strtok(text[i],r);
while (sl)
    {   if (strlen_asm(sl)>max[i]) max[i]=strlen_asm(sl); //Находим максимальную длинну слова в строке 

		if ( zaglavn_asm(sl) )  //Проверка на "Заглавность"
		         {
				  strcat_asm(zag,sl);
		          strcat_asm(zag," "); 
                  delete_s_asm(s[i],sl); //Удаление слова
		         }		                    
        sl=strtok(0,r);
       
     }
strcpy_asm(text[i],zag);  // в text имеем Заглавные слова в начале строки
strcpy_asm(zag,"");
}

for(i=0; i<n; i++)
{
strcat_asm(text[i],s[i]);  
strcpy_asm(s[i],text[i]);
out<<text[i]<<endl;
}

for (i=0; i<n; i++)             //Сортировка по убыванию           
{
 for (j=max[i]; j>1; j--)
 {
	 sl=strtok(text[i],r);
     while (sl)
	     {
		 if (strlen_asm(sl)==j) f<<sl<<" ";
         sl=strtok(0,r);	 
	     }
    strcpy_asm(text[i],s[i]);
 }
f<<endl;
}
system("pause");
return 0;
 }

int strlen_asm(char *s)
{int len;
_asm
{      mov esi,s   //в еsi адрес s
       dec esi     
	   mov ecx,-1    
m1:    inc ecx     //В есx длина строки
	   inc esi
       cmp [esi],0   //пока не конец строки
       jnz m1

	   mov len,ecx
}
return len;
}



char* strcpy_asm(char *c, char *a)
{
	_asm
	{  push a
	   call strlen_asm
	   pop edx
	   mov ecx, eax
		
	    inc ecx
		mov ax,ds
		mov es,ax 
		mov esi, a
		mov edi, c
	
	    rep movsb	
	}
	return c;
}

void swap_asm(char *a,char *b)
{char c[100]="";
strcpy_asm(c,a);
strcpy_asm(a,b);
strcpy_asm(b,c);
}

bool zaglavn_asm(char *s)
{bool r; int k;
  _asm
  {
	push s
call strlen_asm
pop edx
mov ecx,eax
mov esi,s
dec esi
beg:
	mov k,ecx     //сохраняем длину строки
	inc esi
	mov ebx,[esi]
	push ebx
	call comp       //проверка буквы на заглавность
	pop edx
	cmp eax,0   //если не прописная
	je end
	mov ecx,k
    loop beg

end: mov r,al
  }
return r;
}


char * strcat_asm(char *a, char *b)
{ int k;
	_asm
     {  push a
        call strlen_asm
        pop edx
        mov k,eax          //k-len a

        push b
        call strlen_asm
        pop edx          //eax-len b


        mov esi,b
        mov edi,a
        add edi,k   //  подготовили esi и edi 

		mov ecx,eax     //  подготовили ecx
		inc ecx

        rep movsb
     }
return a;
 }


void delete_s_asm(char *s,char *s1)
{char *s2=strstr(s,s1);
int k;
_asm
   {    push s2
        call strlen_asm
        pop edx
		mov k,eax
	   
	   
	   push s1
        call strlen_asm
        pop edx
   
        mov edi,s2
        mov esi,s2
        add esi,eax  //esi=s2+strlen(s1)

		mov ecx,k
		inc ecx
        rep movsb

   }
}

/*

void delete_s(char *s,char *s1)
{int j; char *s2=strstr(s,s1);
for ( j=s2-s; j<strlen(s)-strlen(s1); j++)
s[j]=s[j+strlen(s1)];

s[j]=NULL;
}*/