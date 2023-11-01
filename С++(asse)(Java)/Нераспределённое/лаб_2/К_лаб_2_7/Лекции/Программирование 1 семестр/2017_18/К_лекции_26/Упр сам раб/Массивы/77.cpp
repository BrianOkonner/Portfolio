#include <iostream.h>
#include <math.h>
int a[100];
int n,p,f;   
//Найти все простые  делители заданного натурального числа.
  //процедура ищет и выводит на экран простые делители числа
  void prost(int n)
  //n-это число, у которого мы ищем простые делители. Передается по значению
  {  int k,t;
  _asm
	{
		mov eax,n
     mov ebx,a                           //засылаем адрес начала массива
     mov ecx,2                           //первый возможный простой делитель
     mov esi,0                           //счетчик для нумерации эл-ов массива
     //подобие паскалевского цикла while
     _for: //если делитель больше, чем делимое, то выходим из цикла
           cmp ecx,eax
           jg _end
           cdq
           push eax
           idiv ecx
           pop eax
           //если остаток при делении на делитель = 0, то заносим его в массив
           cmp edx,0
           je _add
           // если остаток <> 0, увеличиваем счетчик и идем в начало цикла
           inc ecx
           jmp _for
     //добавление в массив простых делителей
     _add: mov [ebx][esi*4],ecx
     //удаляем у числа делители, кратные текущему простому делителю
     _del:  mov t,eax
            idiv ecx
            cmp edx,0
            je _del
            inc esi
            inc ecx
            mov eax,t
            jmp _for                   //возвращаемся к началу цикла
     _end: mov f,esi                   //фиксируем кол-во эл-ов в массиве
	};
}
void main()
{
int a[100];
int n,p,f;   
cout<<"Enter the number, simple dividers:";
cin>>n;
p= n / 2;
  prost(n);
cout<<"Simple dividers of the number"<<n<<" are:";
      //выводим на экран делители
  for (int k=0;k<f;k++}
        cout<<a[k]<<' ';
} 
