void InsStrNum( char*S1,const char*S2,int num)
	//Вставляет в строку S1 строку  S2  после num
{   int n,n2;
	char* s1,*s2,*s3;             //Поиск строки В в строке А
    n=strlen(S2);         //Длина подстроки
	  if (strlen(S1)>=num) 
	  {
        n2=strlen(S1)-num;//длина строки после num
	    s2=new char(strlen(S1)+n+1);
		s3=new char(n2+1);
	    strncpy(s2,S1,num);//строка  до  num
		s2[num]='\0';
        strcat(s2," " );
		strcpy(s3,S1+num); //часть строки после num
		strcat(s2,S2);    //вставляем слово
		 strcat(s2," " );
		strcat(s2,s3);     
		 
		strcpy(S1,s2);
     }
	  else 
		  strcat(S1,S2);
}



void InsStr( char*S1,const char*S2,const char*S3)
	//Вставляет в строку S1 строку  S2  после строки S3
{   int n,n1,n2;
	char* s1,*s2,*s3;             //Поиск строки В в строке А
    n=strlen(S2);         //Длина подстроки
 s1=(char*)strstr(S1,S3);
	  if (s1!=NULL) 
	  {
        n1=s1-S1+n;      //длина строки с найденным словом
    	n2=strlen(S1)-n1;//длина строки после слова
	    s2=new char(strlen(S1)+n+1);
		s3=new char(n2+1);
	    strncpy(s2,S1,n1);//строка с найденным словом
		s2[n1]='\0';
        strcat(s2," " );
		strcpy(s3,S1+n1); //часть строки после найденного слова
		strcat(s2,S2);    //вставляем слово
		 strcat(s2," " );
		strcat(s2,s3);     
		 
		strcpy(S1,s2);
     }
	  else 
		  strcat(S1,S2);
}

  //Удаляет подстроку из строки
void Delstr1( char*S1,const char*S2)
{   int n,n1,n2;
	char* s1,*s2,*s3;             //Поиск строки В в строке А
    n=strlen(S1);         //Длина подстроки
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

   //Удаляет все подстроки из строки
void Delstr(char*A,const char*B)
{ char* s;             //Поиск строки В в строке А
 int n=strlen(B);         //Длина подстроки
 while((s=(char*)strstr(A,B))!=NULL)    
           //Пока в строке есть заданные подстроки:
 {  while(*(s+n)!=NULL)
{ //Сдвигаем всю строку влево стирая найденную подстроку
     *s=*(s+n);
       s++;
}
   *s=NULL;         //Ограничиваем ее 
 }}


void main()
{
 printf("Enter your string:");
 char c[80],w[80];
 gets(c);                                   //Ввод строки
 printf("Enter the word:");
 gets(w);                                   //Ввод подстроки
 InsStrNum(c,w,5);
 puts(c);                                   //Вывод результата
 getch();
}

