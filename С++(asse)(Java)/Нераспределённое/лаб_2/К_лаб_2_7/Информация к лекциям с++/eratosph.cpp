#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
unsigned limit, //���������� �����
candidat,nonprost; //������� ���������� � ������� � ���������
char*bit; //����� ������� ��� ��������� ������
int d; //��� �������� �����
int nbit; //��� ������ ���� � �������� �����
char *byte_ptr; //��� ������ ��������� �����
const first=3; //������ �������
 
 
//������������ ��������� ���� � �������� ������� i � �������
//char-��������� � ���������� bit
 
inline void sbros_bit(long i,char*b)
{char*bptr=b+(i>>3);//����� ����� � �������� ����� char
nbit=7-(i&7); //����� ���� � �����
*bptr&=~(1<<nbit);
}
//���������� �������� ����������
void eratosfen()
{
//����������� ������ � ������ ��� �������� ������� ������
//������� �������� - �������� ����� ������ ��������� ���-
//�������� �����, �.�. �������� - ��������
 
unsigned lbyte=limit>>2; //����� ����������� �������
bit = new char[100];
for (int i=0; i<10; i++)
bit[i]=-1;
//bit=(char*)malloc(lbyte); //������� ������
//memset(bit,lbyte,0xff);//�������� ������ ���������
 
//���� �������� ������� ��������� �������
for(candidat=0;candidat<=limit;candidat++)
{
byte_ptr=bit+(candidat>>3); //����� ��������� �����
nbit=7-(candidat & 7); //����� ���� ������ ������ ������
if(*byte_ptr & (1<<nbit)) //���� ����� �������
{
d=2*candidat+first; //��������� ���
printf("%d ",d); //� ��������
nonprost=d+candidat;
/*������� ������ ���������� (�������� ��������)*/
for(;nonprost<=limit;) 	/*� ����� ������� ��� ������� �������� �������� */
{
sbros_bit(nonprost,bit);
nonprost+=d;
} 
} //if }
}
delete[]bit; //��������� ������

}
//� ������ ������� ������� main()
void main(int c,char*w[])
{
if(c<2) {
cprintf("�� ����� ������ ��� �������");return;
}
//�������� ���������� �������� ����� - �� ��������
limit=atoi(w[1])>>1;
eratosfen(); //�������� ������������ ������ ������� �����
}
