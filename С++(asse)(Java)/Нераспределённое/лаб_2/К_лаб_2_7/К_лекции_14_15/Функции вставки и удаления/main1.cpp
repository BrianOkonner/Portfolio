void InsStrNum( char*S1,const char*S2,int num)
	//��������� � ������ S1 ������  S2  ����� num
{   int n,n2;
	char* s1,*s2,*s3;             //����� ������ � � ������ �
    n=strlen(S2);         //����� ���������
	  if (strlen(S1)>=num) 
	  {
        n2=strlen(S1)-num;//����� ������ ����� num
	    s2=new char(strlen(S1)+n+1);
		s3=new char(n2+1);
	    strncpy(s2,S1,num);//������  ��  num
		s2[num]='\0';
        strcat(s2," " );
		strcpy(s3,S1+num); //����� ������ ����� num
		strcat(s2,S2);    //��������� �����
		 strcat(s2," " );
		strcat(s2,s3);     
		 
		strcpy(S1,s2);
     }
	  else 
		  strcat(S1,S2);
}



void InsStr( char*S1,const char*S2,const char*S3)
	//��������� � ������ S1 ������  S2  ����� ������ S3
{   int n,n1,n2;
	char* s1,*s2,*s3;             //����� ������ � � ������ �
    n=strlen(S2);         //����� ���������
 s1=(char*)strstr(S1,S3);
	  if (s1!=NULL) 
	  {
        n1=s1-S1+n;      //����� ������ � ��������� ������
    	n2=strlen(S1)-n1;//����� ������ ����� �����
	    s2=new char(strlen(S1)+n+1);
		s3=new char(n2+1);
	    strncpy(s2,S1,n1);//������ � ��������� ������
		s2[n1]='\0';
        strcat(s2," " );
		strcpy(s3,S1+n1); //����� ������ ����� ���������� �����
		strcat(s2,S2);    //��������� �����
		 strcat(s2," " );
		strcat(s2,s3);     
		 
		strcpy(S1,s2);
     }
	  else 
		  strcat(S1,S2);
}

  //������� ��������� �� ������
void Delstr1( char*S1,const char*S2)
{   int n,n1,n2;
	char* s1,*s2,*s3;             //����� ������ � � ������ �
    n=strlen(S1);         //����� ���������
 s1=(char*)strstr(S1,S2);
	  if (s1!=NULL) 
	  {
        n1=s1-S1;
    	n2=strlen(S1)-n1-n;
	    s2=new char(n+1);
		s3=new char(n2+1);
	    strncpy(s2,S1,n1);
		s2[n1]='\0';
		strcpy(s3,S1+n1+n);
		strcat(s2,s3);
		
		strcpy(S1,s2);
     }
}

   //������� ��� ��������� �� ������
void Delstr(char*A,const char*B)
{ char* s;             //����� ������ � � ������ �
 int n=strlen(B);         //����� ���������
 while((s=(char*)strstr(A,B))!=NULL)    
           //���� � ������ ���� �������� ���������:
 {  while(*(s+n)!=NULL)
{ //�������� ��� ������ ����� ������ ��������� ���������
     *s=*(s+n);
       s++;
}
   *s=NULL;         //������������ �� 
 }}


void main()
{
 printf("Enter your string:");
 char c[80],w[80];
 gets(c);                                   //���� ������
 printf("Enter the word:");
 gets(w);                                   //���� ���������
 InsStrNum(c,w,5);
 puts(c);                                   //����� ����������
 getch();
}

