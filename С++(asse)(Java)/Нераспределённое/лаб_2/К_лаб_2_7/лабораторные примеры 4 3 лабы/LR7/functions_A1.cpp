#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "Header.h"
using namespace std;

numbers_stack *number_head;
operations_stack *head;

void push_n(double number)
{
	numbers_stack *temp = new numbers_stack;
	temp->number = number;
	temp->next = number_head;
	number_head = temp;
}

double pop_n()
{
	double temp = number_head->number;
	numbers_stack *tmp = number_head;
	number_head = number_head->next;
	delete tmp;
	return temp;
}

double element_n()
{
	return number_head->number;
}

void show_numbers_stek()
{
	numbers_stack *temp = number_head;
	while (temp != NULL)
	{
		cout << temp->number;
		temp = temp->next;
	}
}

void push(char operation)
{
	operations_stack *temp = new operations_stack;
	temp->operation = operation;
	temp->next = head;
	head = temp;
}

char pop()
{
	char temp = head->operation;
	operations_stack *tmp = head;
	head = head->next;
	delete tmp;
	return temp;
}

char element()
{
	return head->operation;
}

void show_stek()
{
	operations_stack *temp = head;
	while (temp != NULL)
	{
		cout << temp->operation;
		temp = temp->next;
	}
}

int isNumber(char *word){
	int l1;
	char *tmp;
	l1 = strtol(word, &tmp, 0);
	if (*tmp == 0)
		return 1;
	double l2;
	l2 = strtod(word, &tmp);
	if (*tmp == 0)
		return -1;
	return 0;
}

bool st_to_str_opn(char *str, char *str_opn)
{
	int i, number = 0;
	//	char symbol;
	for (i = 0; i < strlen(str); i++)
	{

		if (str[i] >= '0' && str[i] <= '9')
		{
			number = number * 10 + (str[i] - '0');
			continue;
		}
		else
		{
			char temp_number[80];
			sprintf(temp_number, "%d", number);
			if (i != 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
			{
				strcat(str_opn, temp_number);
				strcat(str_opn, " ");
			}
			number = 0;
			switch (str[i])
			{
			case '+':
			{
						while (head)
						{
							if (head->operation == '*' || head->operation == '/' || head->operation == '^' || head->operation == '+' || head->operation == '-')
							{
								char *temp_symbol = new char[2];
								temp_symbol[0] = pop();
								temp_symbol[1] = '\0';
								strcat(str_opn, temp_symbol);
								strcat(str_opn, " ");
								//cout << temp_symbol << " ";
							}
							else
								break;
						}
						push(str[i]);
						break;
			}
			case '-':
			{
						if (i == 0 || str[i - 1] == '(')
							strcat(str_opn, "0 ");
						while (head)
						{
							if (head->operation == '*' || head->operation == '/' || head->operation == '^' || head->operation == '+' || head->operation == '-')
							{
								char *temp_symbol = new char[2];
								temp_symbol[0] = pop();
								temp_symbol[1] = '\0';
								strcat(str_opn, temp_symbol);
								strcat(str_opn, " ");
								//cout << temp_symbol << " ";
							}
							else
								break;
						}
						push(str[i]);
						break;
			}
			case '*':
			case '/':
			{
						while (head)
						{
							if (head->operation == '*' || head->operation == '/' || head->operation == '^')
							{
								char *temp_symbol = new char[2];
								temp_symbol[0] = pop();
								temp_symbol[1] = '\0';
								strcat(str_opn, temp_symbol);
								strcat(str_opn, " ");
							}
							else
								break;
						}
						push(str[i]);
						break;
			}
			case '^':
			{
						while (head)
						{
							if (head->operation == '^')
							{
								char *temp_symbol = new char[2];
								temp_symbol[0] = pop();
								temp_symbol[1] = '\0';
								strcat(str_opn, temp_symbol);
								strcat(str_opn, " ");
							}
							else
								break;
						}
						push(str[i]);
						break;
			}
			case '(':
			{
						push(str[i]);
						break;
			}
			case ')':
			{
						while (head)
						{
							if (head->operation != '(')
							{
								char *temp_symbol = new char[2];
								temp_symbol[0] = pop();
								temp_symbol[1] = '\0';
								strcat(str_opn, temp_symbol);
								strcat(str_opn, " ");
							}
							else
							{
								pop();
								break;
							}
						}
						break;
			}
			default:
			{
					   cout << " Incorrect input!" << endl;
					   return false;
			}
			}
		}
	}

	if (str[strlen(str) - 1] >= '0' && str[strlen(str) - 1] <= '9')
	{
		char temp_number[80];
		sprintf(temp_number, "%d", number);
		strcat(str_opn, temp_number);
		strcat(str_opn, " ");
	}
	while (head)
	{
		char *temp_symbol = new char[2];
		temp_symbol[0] = pop();
		temp_symbol[1] = '\0';
		strcat(str_opn, temp_symbol);
		strcat(str_opn, " ");
	}
	return true;
}

double value_of_opn(char *str_opn)
{
	char * tmp = strtok(str_opn, " ");
	while (tmp)
	{
		if (isNumber(tmp))
			push_n(atoi(tmp));
		else
		{
			switch (tmp[0])
			{
			case '+':
			{
						push_n(pop_n() + pop_n());
						break;
			}
			case '-':
			{
						push_n((pop_n() - pop_n())*(-1));
						break;
			}
			case '*':
			{
						push_n(pop_n()*pop_n());
						break;
			}
			case '/':
			{
						push_n((1 / pop_n())*pop_n());
						break;
			}
			case '^':
			{
						double temp_numb = pop_n();
						push_n(pow(pop_n(), temp_numb));
						break;
			}
			}
		}
		tmp = strtok(NULL, " ");
	}
	return number_head->number;
}