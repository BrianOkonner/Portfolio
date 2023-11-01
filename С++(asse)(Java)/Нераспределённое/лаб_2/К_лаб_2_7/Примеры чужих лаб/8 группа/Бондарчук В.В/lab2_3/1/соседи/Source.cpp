//Бондарчук Владимир 
//1 курс, группа 8

#include"Header.h"
int main()
{
	ArrayStack S(100);
	int a;
	for (;;)
	{
		cin >> a;
		if (a == -1) break;
		S.push(a);
	}
	int a1 = S.Top();
	S.pop();
	int a2 = S.Top();
	S.pop();
	int a3 = S.Top();
	S.pop();
	int count = 0;
	for (;;)
	{
		if (a1 == a3)
			count++;
		if (S.isEmpty() == 1) break;
		a1 = a2;
		a2 = a3;
		a3 = S.Top();
		S.pop();
		if (S.isEmpty() == 1)
		{
			if (a1 == a3)
				count++;
		}
		if (S.isEmpty() == 1) break;
	}
	cout << count;
	system("pause");
}