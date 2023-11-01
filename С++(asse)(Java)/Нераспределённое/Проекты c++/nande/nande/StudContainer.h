#include <fstream>


struct Student
{
	char  name[15];		// фамилия студента
	int   num;			// номер группы
	double  grade;		// средний бал
};
class StudContainer
{
	int size;	  // размерность массива
	Student* p;	  // массив записей о студентах
	int count;	  // количество студентов в контейнере
public:
	StudContainer(int& _n);	  // конструктор
	StudContainer(const StudContainer& c);  // конструктор копирования
	~StudContainer();		  // деструктор
	bool insert(const Student& s);  // включение студента в контейнер
	bool del(char* name);	  // исключение студента из контейнера
	void sortByName();	  // сортировка записей по именам
	Student* findByName(char* name);	// поиск студента по имени
	void sortByGroupAndName();	  // сортировка по группам, именам
	void report(std::ostream& out);	  // вывести отчет в файл
	void print(std::ostream& out);	  // распечатать список студентов
	int Wsize();				  // возвращает размер контейнера
	int Wcount();	  // возвращает количество записей в контейнере
};

