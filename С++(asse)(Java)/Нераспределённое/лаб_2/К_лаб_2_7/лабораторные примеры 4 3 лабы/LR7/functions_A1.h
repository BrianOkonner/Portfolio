// ���� �����
struct numbers_stack
{
	double number; //�������������� �������
	numbers_stack *next; //��������� �� ��������� �������
};
extern numbers_stack *number_head;//������ ����� 

struct operations_stack
{
	char operation; //�������������� �������
	operations_stack *next; //��������� �� ��������� �������
};
extern operations_stack *head;// ������ �����

void push_n(double number);
double pop_n();
double element_n();
void show_numbers_stek();

void push(char operation);
char pop();
char element();
void show_stek();
int isNumber(char *word);
bool st_to_str_opn(char *str, char *str_opn);
double value_of_opn(char *str_opn);
