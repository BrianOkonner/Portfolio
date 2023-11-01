#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
unsigned limit, //количество чисел
candidat,nonprost; //индексы кандидатов в простые и непростые
char*bit; //адрес массива для побитовой работы
int d; //для значения числа
int nbit; //для номера бита в активном байте
char *byte_ptr; //для адреса активного байта
const first=3; //первое простое
 
 
//подпрограмма обнуления бита с заданным номером i в массиве
//char-элементов с указателем bit
 
inline void sbros_bit(long i,char*b)
{char*bptr=b+(i>>3);//номер байта с заданным битом char
nbit=7-(i&7); //номер бита в байте
*bptr&=~(1<<nbit);
}
//Собственно алгоритм Эратосфена
void eratosfen()
{
//необходимая память в байтах для хранения битовой модели
//массива нечетных - примерно вдвое меньше заданного пре-
//дельного числа, т.к. нечетных - половина
 
unsigned lbyte=limit>>2; //адрес выделенного массива
bit = new char[100];
for (int i=0; i<10; i++)
bit[i]=-1;
//bit=(char*)malloc(lbyte); //выделим память
//memset(bit,lbyte,0xff);//заполним массив единицами
 
//цикл перебора битовых элементов массива
for(candidat=0;candidat<=limit;candidat++)
{
byte_ptr=bit+(candidat>>3); //адрес активного байта
nbit=7-(candidat & 7); //номер бита счетом справа налево
if(*byte_ptr & (1<<nbit)) //если число простое
{
d=2*candidat+first; //вычисляем его
printf("%d ",d); //и печатаем
nonprost=d+candidat;
/*находим индекс непростого (кратного простому)*/
for(;nonprost<=limit;) 	/*в цикле обнулим все кратные текущему простому */
{
sbros_bit(nonprost,bit);
nonprost+=d;
} 
} //if }
}
delete[]bit; //освободим память

}
//И теперь главная функция main()
void main(int c,char*w[])
{
if(c<2) {
cprintf("Не задан предел для простых");return;
}
//Получаем количество нечетных чисел - их половина
limit=atoi(w[1])>>1;
eratosfen(); //Вызываем подпрограмму печати простых чисел
}
