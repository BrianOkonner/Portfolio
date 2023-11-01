/* Каунов Кирилл
1 курс
8 группа
*/

#include"Header.h"
STACK_C s;
STACK_I s1;
int main()
{
	char str[81]; char res[81]; res[0] = '\0';
	for (int k = 0; k < 81; k++) { res[k] = '\0'; }
	cin.getline(str, 81);
	int count = strlen(str);
	int j = 0;
	int i = 0;
	while (count)
	{
		char tmp = str[i];
		if (cifra(str[i]))
		{
			res[j] = tmp; j++;
		}
		else
			if (str[i] != ')'&&str[i] != '(')
			{
				{
					if (s.empty() || (prior(s.top()) < prior(str[i])))
					{ 
						s.push(tmp);
					}
					else
					{
						while (!s.empty() && (prior(s.top()) >= prior(str[i])))
						{
							char tmp1 = s.top();
							s.pop();
							res[j] = tmp1; j++;
						}
						s.push(str[i]);
					}
				}
			}
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		if (str[i] == ')')
		{
			while (s.top() != '(')
			{
				res[j] = s.top(); j++;
				s.pop();
			}
			s.pop();
		}
		count--;
		i++;
	}
	while (!s.empty())
	{
		res[j] = s.top(); j++;
		s.pop();
	}
	cout << "polskaya zapis:" << res << endl;
	i = 0;
	count = strlen(res);
	while (count)
	{
		if (cifra(res[i]))
		{
			s1.push(Matoi(res[i]));
		}
		else
		{
			int tmp1 = s1.top();
			s1.pop();
			int tmp2 = s1.top();
			s1.pop();
			int tmp3 = operation(tmp1, tmp2, res[i]);
			s1.push(tmp3);
		}
		count--;
		i++;
	}
	int result = s1.top();
	cout << "rezultat:" << result << endl;
	system("pause");
	return 0;
}