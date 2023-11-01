// стек чисел
struct numbers_stack
{
	double number; //информационный элемент
	numbers_stack *next; //указатель на следующий элемент
};
extern numbers_stack *number_head;//Голова стека 

struct operations_stack
{
	char operation; //информационный элемент
	operations_stack *next; //указатель на следующий элемент
};
extern operations_stack *head;// Голова стека

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
