//������ � ��ப� ᫮�� ������� ᫮���
//����� ࠧ������ ᨬ������ �� ��������� ������⢠
//���� �������� ����਩
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char* repwrd(char*,const char*,const char*,const char*);

void main()
{
 char  c[80], w1[80], w2[80];
 int n;
 printf("Enter your string:");
 gets(c);                                     //������ ��ப�
 printf("Enter replaced word:");
 gets(w1);                                    //������ �����塞�� ᫮��
 printf("Enter new word:");
 gets(w2);                                    //������ ����� ᫮��
 char *set=" ,;.:_";                          //������⢮ ࠧ����⥫��
 char*s=repwrd(c,w1,w2,set);                  //�����塞...
 puts(s);                                     //�뢮��� १����
 getch();
}

char* repwrd(char *c,const char*w1,const char*w2,const char*set)      //�-��室��� ��ப�, w1-�����塞�� ᫮��,
{                                                                     //w2-����� ᫮��,  set-ࠧ����⥫�
  char* i;                                 //�ᯮ����⥫�� 㪠��⥫�
  int n1=strlen(w1);                       //�饬 �����...
  int n2=strlen(w2);
  int m=strlen(c);
  char *S=(char*)malloc(m);                //��⮢�� �����頥��� ��ப�
  strcpy(S,c);                             //�����㥬 � ��� ��室���
  int ind=0,p=0;                           //�-⥪�騩 ������ � ��ᬠ�ਢ����� ��ப�
  i=strstr(S,w1);                          //�饬 ��ࢮ� �宦����� ᫮�� ��� �����ப�
  if(i)ind=1;                              //�᫨ ����:
  while(ind)
    {
      if(i==S||strchr(set,*(i-1)))            //�᫨ �� �����ப�-᫮��,
       if(i==S+m-n1||strchr(set,*(i+n1)))     //㤠�塞 ��� � �����塞 ����:
	 {
	  ind=1;                              //�.�.:
	  if(n1>n2)                           //�᫨ ��஥ ����� ������
	    {
	       int t=n2-1;
	       do                             //�������� ��� ��ப� �����,
		 {                            //㪮�稢�� ��஥ �� �����
		   t++;                       //������
		   i[t]=i[n1-n2+t];
		 }
	       while(i[n1-n2+t]!=NULL);
	    }
	  else if(n1<n2)                          //�᫨ ��஥ ���� ������
	    {
	      int k=strlen(S);
	      S=(char*)realloc(S,k+n2-n1+1);     //�뤥�塞 ����� ������
	      S[k]=NULL;                         //������祬 � ��� ����� ��ன ��ப�
	      i=strstr(S+p,w1);                  //�� �⮡� �ᯮ����⥫�� 㪠��⥫� �த����� 㪠�.
						 //�� ���� ���஢�७��� ���� ��ப�
	      while(k>=(i-S)+n1)            	  //�������� ���� ��ப� ��ࠢ�,
	       {                                  //��稭�� � ���� �᪮���� ᫮��,
		S[k+n2-n1]=S[k];                   //�.�. ������塞 �� ����� ������
		--k;
	       }
	    }
	   for(int t=0;t<n2;++t)                  //�����뢠�� �� �����⮢������ ����
	     {                                    //���� ��ப�
	      i[t]=w2[t];
	     }
	 }
       ind=0;
       m=strlen(S);	                          //�᫨ ����� � ��ப� ����砥��� ��஥
       i=strstr(i+n2,w1);                         //᫮�� ��� �����ப� - �த������ 横�
       if(i&&i<S+m)ind=1;
       p=i-S;                                     //����⠢�塞 ������
    }

  return S;                                       //�����頥� 㪠��⥫� �� ����� ��ப�
}

