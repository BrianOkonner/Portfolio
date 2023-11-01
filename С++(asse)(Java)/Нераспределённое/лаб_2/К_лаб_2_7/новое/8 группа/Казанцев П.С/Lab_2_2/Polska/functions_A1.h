// стек чисел
#define _CRT_SECURE_NO_WARNINGS
class numbers_stack
{
public:
	double number; //информационный элемент
	numbers_stack *next; //указатель на следующий элемент
	void push_n(double number);
	double pop_n();
	double element_n();
	void show_numbers_stek();
};
extern numbers_stack *number_head;//Голова стека 

class operations_stack
{
public:
	char operation; //информационный элемент
	operations_stack *next; //указатель на следующий элемент
	void push(char operation);
	char pop();
	char element();
	void show_stek();
};
extern operations_stack *head;// Голова стека

int isNumber(char *word);
bool st_to_str_opn(char *str, char *str_opn);
double value_of_opn(char *str_opn);


