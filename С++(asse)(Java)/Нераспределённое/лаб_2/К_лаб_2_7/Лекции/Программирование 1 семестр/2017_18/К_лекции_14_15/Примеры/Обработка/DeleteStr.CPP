//�������� �� ��ப� ��������� ᫮��(�����ப�)
//���� �������� ����਩
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void delstr(const char*,const char*);       //������ �����ப� �� ��ப�

void main()
{
 printf("Enter your string:");
 char c[80],w[80];
 gets(c);                                   //���� ��ப�
 printf("Enter the word:");
 gets(w);                                   //���� �����ப�
 delstr(c,w);
 puts(c);                                   //�뢮� १����
 getch();
}

void delstr(const char*A,const char*B)
{
 char* s;
 int n=strlen(B);                           //����� �����ப�
 while((s=(char*)strstr(A,B))!=NULL)               //���� � ��ப� ���� ������� �����ப�:
 {
   while(*(s+n)!=NULL)                      //�������� ��� ��ப� �����
    {                                       //���� ��������� �����ப�
     *s=*(s+n);
     s++;
    }
   *s=NULL;                                //��࠭�稢��� ��
 }
}