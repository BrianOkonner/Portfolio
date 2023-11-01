/*
	Петров Константин
	     8 группа
*/

#include <iostream>
#include "stack.h"
#include <ctime>
using namespace std;

int main(void){
	MyStack S;
	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		S.Push(new int(rand() % 10));
	}

	while (!S.isEmpty()){
		int val = *(int*)S.Top();
		S.Pop();
		cout << val << endl;
	}

	system("pause");
	return 0;
}
