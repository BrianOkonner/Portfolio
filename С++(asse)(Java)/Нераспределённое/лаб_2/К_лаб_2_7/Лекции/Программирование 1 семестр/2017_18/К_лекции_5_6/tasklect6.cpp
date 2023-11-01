void Сode ()

 { //Печать кодировочной таблицы 	
   printf("Current table: \n");
 	for ( int c=0;c<=255;c++) {
 		printf("%3d-%c  ",c,c);
 	if((c+1)%11==0)
        printf("\n");   }  }
// Вызов функции
//Сode (); 


void Swap (  int   a, int b) 
// Работает неверно, не обменивает значения переменных
{    
   int tmp = a;
   a = b;  
  b = tmp; 
}
// Вызов функции, если объявлены и введены переменные a b
// int a,b;
// Swap (a,b); 


void Swap (  int   *px, int *py) 
// Работает верно,  обменивает значения переменных
// Формальные параметры, это указатели

{    
    int tmp = *px;
   *px = *py;  
   *py = tmp; 
}

// Вызов функции, если объявлены и введены переменные a b
// int a,b;
// Swap(&a,&b);


void Swap (  int   &a, int &b) 
// Работает верно,  обменивает значения переменных
// Формальные параметры, это ссылки

{    
   tmp = a;
   a = b;  
  b = tmp; 
}

// Вызов функции, если объявлены и введены переменные a b
// int a,b;
// Swap(a,b);


//Пример 6.10. Функция sort3 сортирует три  числа, 
используем функцию Swap для обмена двух значений:
void sort3 (int &a, int &b, int &c)
 {
    	if (a>b) Swap (a,b);
	if (a>c) Swap (a,c); 	
        if (b>c) Swap (a,c); 	}
//Ее вызов теперь будет иметь вид
int a1=5, a2=8, a3=2;
sort3(a1, a2, a3);



//Пример 6.11. 

 void print ( int num_k=1, int num_d=1,char* name="Красивая ")
     { cout << name << "дом " << num_d <<
	cout<< " кв. " <<num_k << endl;
      }
// Примеры вызова 
      { print();
	 print(15);
	 print(15,32);
	 print(3,5,"Моя ");
     }



//Вычисление N!
long fact(int num)
 { 
int res=1;
   for (;num>1;num--)
	 res*=num;
  return res;
}

