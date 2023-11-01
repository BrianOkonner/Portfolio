/*	������ ����������
		8 ������

  3.1	������ ������. ������ ����������  ����� N �������, ��  ������� ������� ������, �  
  ���������  ������������  ��  ������� �������  ������� �� 2 �� N. ���������,  ������� � 
  ����-��, ����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����. ���� 
  ������������ �� ���������� �������� � ��� �� ��� ���, ���� ��  ���������  ���� �������.  
  ���������� ����� ����������� ��������, ���� �������� M � ��, ��� ���� ��������� � 
  ������� ��������. ��������� �������� � ���������  ����.


  �����

*/

#include<iostream>
#include<fstream>
using namespace std;

struct Item {
	Item *next;
	Item *prev;
	int num;
};

class MyList {
	Item *head;
	Item *tail;
public:
	void PushFront(int n);				/* �������� ������� � ������ ������  */
	void PushBack(int n);				/* �������� ������� � ����� ������   */
	int PopFront();						/* ��������� ������� �� ����� ������ */
	int PopBack();						/* ��������� ������� �� ����� ������ */
	void Insert(int data, int pos);		/* �������� � ������� pos+1          */
	int Remove(int pos);				/* ������� ������� c ������� pos*/
	bool IsEmpty();						/* ������ ������? */
	MyList(){							
		head = 0;
		tail = 0;
	}
	~MyList() {
		while (head != 0)
		{
			Item* tmp = head;
			head = head->next;
			delete tmp;
		}
		head = 0;
		tail = 0;
	}
};

void MyList :: PushFront(int n)	{
	Item* tmp = new Item;
	tmp->num = n;
	tmp->prev = 0;
	tmp->next = head;
	if (head)
		head->prev = tmp;
	else
		tail = tmp;
	head = tmp;
}
void MyList :: PushBack(int n){
	Item* tmp = new Item;
	tmp->num = n;
	tmp->next = 0;
	tmp->prev = tail;
	if (tail)
		tail->next = tmp;
	else
		head = tmp;
	tail = tmp;
}
int MyList :: PopFront(){
	if (head){
		int res = head->num;
		Item *tmp = head;
		if (head->next)
			head->next->prev = 0;
		else
			tail = 0;
		head = head->next;
		delete tmp;
		return res;
	}
	return 0;
}
int MyList :: PopBack()	{
	if (tail){
		int res = tail->num;
		Item *tmp = tail;
		if (tail->prev)
			tail->prev->next = 0;
		else
			head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}
void MyList :: Insert(int data, int pos){
	Item* tmp = new Item;
	tmp->num = data;
	Item* ptmp = head;
	
	if (ptmp == 0){
		tmp->next = 0;
		tmp->prev = 0;
		head = tmp;
		tail = tmp;
		return;
	}
	
	int i = 0;
	
	while ((i<pos) && (ptmp->next)){
		ptmp = ptmp->next;
		i++;
	}

	if (ptmp->next == 0){
		ptmp->next = tmp;
		tmp->prev = ptmp;
		tmp->next = 0;
		tail = tmp;
		return;
	}

	ptmp->next->prev = tmp;
	tmp->next = ptmp->next;
	ptmp->next = tmp;
	tmp->prev = ptmp;
}
int MyList :: Remove(int pos){
	Item* ptmp = head;
	for (int i = 0; i<pos; i++){
		if (ptmp == 0){
			return 0;
		}
		ptmp = ptmp->next;
	}
	ptmp->next->prev = ptmp->prev;
	if (ptmp->prev != 0)
		ptmp->prev->next = ptmp->next;
	int res = ptmp->num;
	delete ptmp;
	return res;
}
bool MyList :: IsEmpty(){						
	return head == 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	int N, M;
	cout << "������� ����� ���������� ���������� " << endl;
	cin >> N;
	cout << "������� ��� ��������" << endl;
	cin >> M;
	if (M == 0) {
		cout << "Error!" << endl;
		exit(0);
	}
	if (M == 1) {
		cout << "��������� �������� - " << N << endl;
		return 0;
	}

	MyList List;

	for (int i = 1; i <= N; List.PushBack(i), i++);
	
	while (N != 1) {
		for (int j = 1; j <= M; j++) {
			if (j == M)
				int y = List.PopFront();
			else {
				int y = List.PopFront();
				List.PushBack(y);
			}
		}
		--N;
	}

	cout << "��������� ������� - " << List.PopFront() << endl;


	return 0;
}