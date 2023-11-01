/*�������� ������ �� 8
� 8
����� ��������� ���� Input.txt, ���������  �� ����.
������������� ����� ������� �������� ��������� ��������� ������ ����������. 
����� � ������ ������  �����, ��������� �� ��������� ����, ������� � �������� � ������  ������.  
��������� ��������  � ����� ���� Output.txt.
����������� �����  � ����������  ������� ��  �������� ���� ����
��������� ���������� �������� � ���� Out_sort.txt. 

������� 
1) ��������� ����� (s) �� �����. ��������� ����� ��  "�����������"(�-��� �� ����������).
��������� ����� � ������ ������� ��������� � ����� ������ ����� (text[i]) �
������� �� ������ (�-��� �� ����������)(s).  ����� ����������� ������ �������� �������� ������ �����
�� ��������� ���� � �������� �������� ����� (� ������� ��������� ����� �������).
2)������� � �������� �.1 ����� ��������� ������������ ����� ����� � � ������ ������.(max[i])
����� ������������� ������ ������ �� �������� ���� �����, ������� ���� ����� � ������
������ max ,  ����� � ������� max-1  ... �� 1. 

3) �������� �������  �������� �� ����������
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
    {   if (strlen_asm(sl)>max[i]) max[i]=strlen_asm(sl); //������� ������������ ������ ����� � ������ 

		if ( zaglavn_asm(sl) )  //�������� �� "�����������"
		         {
				  strcat_asm(zag,sl);
		          strcat_asm(zag," "); 
                  delete_s_asm(s[i],sl); //�������� �����
		         }		                    
        sl=strtok(0,r);
       
     }
strcpy_asm(text[i],zag);  // � text ����� ��������� ����� � ������ ������
strcpy_asm(zag,"");
}

for(i=0; i<n; i++)
{
strcat_asm(text[i],s[i]);  
strcpy_asm(s[i],text[i]);
out<<text[i]<<endl;
}

for (i=0; i<n; i++)             //���������� �� ��������           
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
{      mov esi,s   //� �si ����� s
       dec esi     
	   mov ecx,-1    
m1:    inc ecx     //� ��x ����� ������
	   inc esi
       cmp [esi],0   //���� �� ����� ������
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
	mov k,ecx     //��������� ����� ������
	inc esi
	mov ebx,[esi]
	push ebx
	call comp       //�������� ����� �� �����������
	pop edx
	cmp eax,0   //���� �� ���������
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
        add edi,k   //  ����������� esi � edi 

		mov ecx,eax     //  ����������� ecx
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