/*
*   класс написан Щипановым Сергеем
*    1 курс 5 группа
* 
*   21 января 2010
*/
#pragma once

#define NULL 0



/*
*структура связки списка
*/
struct base{
int a;
base *pNext;
}; 

/*
* сам связаный список
*/
class LList
{
private:
	base *pHead,*pTail;
	int n;
public:
	LList(void);
	~LList(void);
	void push(int);
	int pop(void);
	bool is_emitry();
	int count(){return n;};
};
