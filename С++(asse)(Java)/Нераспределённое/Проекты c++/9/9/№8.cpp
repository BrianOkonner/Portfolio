#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL,"rus");
	char *q,w='И';
	string s,s1,s2,s3="п";
	int pos=0,e=0;
	s="И упасть, опалённым звездой по имени Солнце. ";
	s1="опалённым";
	s2="Солнце";
	cout<<"Первоначальная строчка: "<<endl<<s<<endl;   
	//Преобразование С-строк в String


	//Найти подстроку (начиная с начала и с конца)
	pos=s.find(s1);
	if (pos!=-1)
		cout<<"Посдстрока гласящая: \""<<s1<<"\" найдена в месте с номером "<<pos<<endl;
	else 
		cout<<"В предложении нет такой подстроки"<<endl;
		pos=s.rfind(s2);
	if (pos!=-1)
		cout<<"Посдстрока гласящая: \""<<s2<<"\" найдена в месте с номером "<<pos<<endl;
	else
		cout<<"В предложении нет такой подстроки";

	//Копирование
	s1=s.substr(pos,s.size()-pos);
	cout<<s1<<endl;
	//можно так s1=s2;

	 //Сравнение
	if (s>s2)
		cout<<"Строка s больше строки s2";
	else 
		if(s<s2) 
			cout<<"Строка s меньше строки s2";
		else 
			cout<<"строки равны лексикографически";
		cout<<endl;

	//Замещение фрагмента строки на другой фрагмент
	s.replace( s.find("Солнце"), 6, "DDR138");
	cout << s << endl;

	//Вставка в строку другую строку с заданной позиции
	s.insert(s.find("И упасть ")+10,"приземлиться");
	cout << s << endl;

	//Поиск символа (начиная с начала и с конца);
	pos=s.find(w); //s.rfind(w); 
	if (pos!=-1) cout<<"символ -"<<w<<"- найден в позиции номер "<<pos<<endl;


	//Использовать итераторы
	for (string::iterator it=s.begin(); it<s.end(); it++)
	if (*it=='н') e++ ;
	cout<<"Количество букв (н) в предложении равно = "<<e<<endl;
	system("pause");
	return 0;
}
