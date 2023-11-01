#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <stack>
#include "Header.h"
using namespace std;


stack <int> s1;
stack <char> s2;

int isNumber(char *word) {
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
				while (!s2.empty())
				{
					if (s2.top() == '*' || s2.top() == '/' || s2.top() == '^' || s2.top() == '+' || s2.top() == '-')
					{
						char *temp_symbol = new char[2];
						temp_symbol[0] = s2.top();
						s2.pop();
						temp_symbol[1] = '\0';
						strcat(str_opn, temp_symbol);
						strcat(str_opn, " ");
						//cout << temp_symbol << " ";
					}
					else
						break;
				}
				s2.push(str[i]);
				break;
			}
			case '-':
			{
				if (i == 0 || str[i - 1] == '(')
					strcat(str_opn, "0 ");
				while (!s2.empty())
				{
					if (s2.top() == '*' || s2.top() == '/' || s2.top() == '^' || s2.top() == '+' || s2.top() == '-')
					{
						char *temp_symbol = new char[2];
						temp_symbol[0] = s2.top();
						s2.pop();
						temp_symbol[1] = '\0';
						strcat(str_opn, temp_symbol);
						strcat(str_opn, " ");
						//cout << temp_symbol << " ";
					}
					else
						break;
				}
				s2.push(str[i]);
				break;
			}
			case '*':
			case '/':
			{
				while (!s2.empty())
				{
					if (s2.top() == '*' || s2.top() == '/' || s2.top() == '^')
					{
						char *temp_symbol = new char[2];
						temp_symbol[0] = s2.top();
						s2.pop();
						temp_symbol[1] = '\0';
						strcat(str_opn, temp_symbol);
						strcat(str_opn, " ");
					}
					else
						break;
				}
				s2.push(str[i]);
				break;
			}
			case '^':
			{
				while (!s2.empty())
				{
					if (s2.top() == '^')
					{
						char *temp_symbol = new char[2];
						temp_symbol[0] = s2.top();
						s2.pop();
						temp_symbol[1] = '\0';
						strcat(str_opn, temp_symbol);
						strcat(str_opn, " ");
					}
					else
						break;
				}
				s2.push(str[i]);
				break;
			}
			case '(':
			{
				s2.push(str[i]);
				break;
			}
			case ')':
			{
				while (!s2.empty())
				{
					if (s2.top() != '(')
					{
						char *temp_symbol = new char[2];
						temp_symbol[0] = s2.top();
						s2.pop();
						temp_symbol[1] = '\0';
						strcat(str_opn, temp_symbol);
						strcat(str_opn, " ");
					}
					else
					{
						s2.pop();
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
	while (!s2.empty())
	{
		char *temp_symbol = new char[2];
		temp_symbol[0] = s2.top();
		s2.pop();
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
			s1.push(atoi(tmp));
		else
		{
			switch (tmp[0])
			{
			case '+':
			{
				int s = s1.top();
				s1.pop();
				s += s1.top();
				s1.pop();
				s1.push(s);
				break;
			}
			case '-':
			{
				int s = s1.top();
				s1.pop();
				s -= s1.top();
				s1.pop();
				s = -1 * s;
				s1.push(s);
				break;
			}
			case '*':
			{
				int s = s1.top();
				s1.pop();
				s *= s1.top();
				s1.pop();
				s1.push(s);
				break;
			}
			case '/':
			{
				int s = s1.top();
				s1.pop();
				s = s1.top()/s;
				s1.pop();
				s1.push(s);
				break;
			}
			case '^':
			{
				double temp_numb = s1.top();
				s1.pop();
				double s = s1.top();
				s1.pop();
				s1.push(pow(s, temp_numb));
				break;
			}
			}
		}
		tmp = strtok(NULL, " ");
	}
	return s1.top();
}