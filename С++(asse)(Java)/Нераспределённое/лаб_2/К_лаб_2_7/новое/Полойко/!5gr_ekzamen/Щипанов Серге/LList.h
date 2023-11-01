/*
*   ����� ������� ��������� �������
*    1 ���� 5 ������
* 
*   21 ������ 2010
*/
#pragma once

#define NULL 0



/*
*��������� ������ ������
*/
struct base{
int a;
base *pNext;
}; 

/*
* ��� �������� ������
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
