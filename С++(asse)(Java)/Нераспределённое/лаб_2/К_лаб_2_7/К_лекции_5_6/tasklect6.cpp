void �ode ()

 { //������ ������������ ������� 	
   printf("Current table: \n");
 	for ( int c=0;c<=255;c++) {
 		printf("%3d-%c  ",c,c);
 	if((c+1)%11==0)
        printf("\n");   }  }
// ����� �������
//�ode (); 


void Swap (  int   a, int b) 
// �������� �������, �� ���������� �������� ����������
{    
   int tmp = a;
   a = b;  
  b = tmp; 
}
// ����� �������, ���� ��������� � ������� ���������� a b
// int a,b;
// Swap (a,b); 


void Swap (  int   *px, int *py) 
// �������� �����,  ���������� �������� ����������
// ���������� ���������, ��� ���������

{    
    int tmp = *px;
   *px = *py;  
   *py = tmp; 
}

// ����� �������, ���� ��������� � ������� ���������� a b
// int a,b;
// Swap(&a,&b);


void Swap (  int   &a, int &b) 
// �������� �����,  ���������� �������� ����������
// ���������� ���������, ��� ������

{    
   tmp = a;
   a = b;  
  b = tmp; 
}

// ����� �������, ���� ��������� � ������� ���������� a b
// int a,b;
// Swap(a,b);


//������ 6.10. ������� sort3 ��������� ���  �����, 
���������� ������� Swap ��� ������ ���� ��������:
void sort3 (int &a, int &b, int &c)
 {
    	if (a>b) Swap (a,b);
	if (a>c) Swap (a,c); 	
        if (b>c) Swap (a,c); 	}
//�� ����� ������ ����� ����� ���
int a1=5, a2=8, a3=2;
sort3(a1, a2, a3);



//������ 6.11. 

 void print ( int num_k=1, int num_d=1,char* name="�������� ")
     { cout << name << "��� " << num_d <<
	cout<< " ��. " <<num_k << endl;
      }
// ������� ������ 
      { print();
	 print(15);
	 print(15,32);
	 print(3,5,"��� ");
     }



//���������� N!
long fact(int num)
 { 
int res=1;
   for (;num>1;num--)
	 res*=num;
  return res;
}

