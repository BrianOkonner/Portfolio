// ���� �����
#define _CRT_SECURE_NO_WARNINGS
class numbers_stack
{
public:
	double number; //�������������� �������
	numbers_stack *next; //��������� �� ��������� �������
	void push_n(double number);
	double pop_n();
	double element_n();
	void show_numbers_stek();
};
extern numbers_stack *number_head;//������ ����� 

class operations_stack
{
public:
	char operation; //�������������� �������
	operations_stack *next; //��������� �� ��������� �������
	void push(char operation);
	char pop();
	char element();
	void show_stek();
};
extern operations_stack *head;// ������ �����

int isNumber(char *word);
bool st_to_str_opn(char *str, char *str_opn);
double value_of_opn(char *str_opn);


