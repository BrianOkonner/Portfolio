class List		/* ������ ����������������*/
{
	struct node	/* ������� ������ */
	{
		int item;		 /* ������ */
		struct node*  p;	 /* ��������� �� ��������� ������� */
	};
	struct node *head;	 /* ��������� �� ������ ������� � ������ */
public:
List();	             /* ����������� */
List(const List& lst);   // ����������� �����������
~List();	             /* ���������� */
void push_head(int n);		//�������� ������� � ������ ������
void push_back(int n);		//�������� ������� � ����� ������
node* remove_head();	// ��������� ������� �� ������ ������
node* remove_tail();		// ��������� ������� �� ����� ������  
bool isEmpty();	       /* ������ ������? */
int size();
}; //�������������
/*
node* search()			// ����� ������� ������ ������
void remove(node* adr)		// ������� ������� c �������  adr
void print ()			//������ ����������� ������
int remove(int pos)	  //���������  �������� �������
void delchet ()		//�������� � ������� ��������
int smin ()		    	//����� min
void invert ()		//������������� �������� ������ �������� ������*/
