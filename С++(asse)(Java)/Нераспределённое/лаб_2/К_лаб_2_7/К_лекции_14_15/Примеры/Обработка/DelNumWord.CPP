//�������� �� ��ப� ��������� ᫮�� �� ������
//����� ࠧ������ ᨬ������ �� ��������� ������⢠
//���� �������� ����਩
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void delwrd(char*,int,const char*);           //������ ᫮�� �� ��� ������ �� ��ப�

void main()
{
 printf("Enter your string:");
 char c[80];
 int n;
 gets(c);                                     //������ ��ப�
 printf("Enter word's number:");
 scanf("%d",&n);                              //������ ����� ᫮��
 char *set=" ,;.:_";                          //������⢮ ࠧ����⥫��
 delwrd(c,n,set);                             //����塞 ...
 puts(c);                                     //�뢮��� १����
 getch();
}

void delwrd(char*A,int n,const char*set)      //������ n-�� ᫮�� �� � ���뢠� ࠧ����⥫� �� Set
{
 int i=0,c=0,p=0;
 while((*(A+i)!=NULL)&&(c!=n))               //�饬 n-�� ᫮�� ���� ��ப� �� �����稫���
  {
   if(!strchr(set,*(A+i)))                   //�஢�ઠ A[i] �� �� ࠧ����⥫�
    {
    if(!p)                                   //�᫨ �� ���� �� ࠧ����⥫�,
      {                                      //㢥��稢��� ���稪 ᫮�
	c++;
	p=1;                                 //�="�� ࠧ����⥫�"
      }
    }
   else p=0;                                 //...���� �="ࠧ����⥫�"
   i++;                                      //�����稢��� ������
  }
					    //�᫨ ������ �㦭� �����:
  if(c==n&&c)
   {
    --i;
    int j=0;                                            //j-����� �᪮���� ᫮��
    while((*(A+i+j)!=NULL)&&(!strchr(set,*(A+i+j))))    //��⠥� ��� �����
     j++;
    int t=-1;
     do                                                 //�������� ��� ��ப� �����,
      {                                                 //㤠��� �᪮���
       t++;
       *(A+i+t)=*(A+i+j+t);
      }
     while((*(A+i+j+t)!=NULL));
   }
}
