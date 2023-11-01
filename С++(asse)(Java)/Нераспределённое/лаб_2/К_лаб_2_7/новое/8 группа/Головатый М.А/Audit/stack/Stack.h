#ifndef STACK
#define STACK // исключаем повторное ключение h-файла

class Stack
{//если нет ограничения доступа значит private
	struct Link // вложенная в класс структура на которой работает список
	{
		void* data;
		Link* next;
		Link(void*, Link*);
		~Link();
	} *head; // указатель на верхушку стека
public:
	Stack(); // конструктор по умолчанию
	~Stack(); // 
	void Push(void*); 
	void* Top();//Peek
	bool isEmpty();
	void Pop();
};

#endif