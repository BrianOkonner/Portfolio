#include "func.h"

#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

bool isOperator(char c)
{
    return OPERATORS.find(c) != string::npos;
}

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return -1;
}

void appOp(string& s, char c)
{
    s += c;
    s += ' ';
}

bool isCorrect(const std::string& raw)
{
    std::string s;
    for (int i = 0; i < raw.length(); i++)
        if (raw[i] != ' ')
            s += raw[i];
    if (isOperator(s[0]) || isOperator(s[s.length() - 1]))
        return false;
    int i = 0;
    while (i < s.length() && !isOperator(s[i]))
        i++;
    i++;
    for ( ; i < s.length(); i++)
        if (isOperator(s[i]) && isOperator(s[i - 1])) 
            return false;
    return true;
}

string toPosfix(string infix)
{
    string res;
    stack<char> st;
    //char prev = 0, prevNotBracket = 0;

    //if (isOperator(infix[0]) || isOperator(infix[infix.length() - 1]))
        //return "";
    if (!isCorrect(infix))
       return ""; 

    for (size_t i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
            continue;
        if (infix[i] == '(')
            st.push('(');
        else if (!isOperator(infix[i]) && infix[i] != ')')
            res += infix[i];
        else
        {
            if ((res.empty() == false) && (res[res.length() - 1] != ' '))
                res += ' ';

            if (infix[i] == ')')
            {
                for (; (st.empty() == false) && (st.top() != '('); st.pop())
                    appOp(res, st.top());
                if (st.empty()) //extra )
                    return "";
                st.pop();
            }
            else
            {
                for (; (st.empty() == false) && (priority(st.top()) >= priority(infix[i])); st.pop())
                    appOp(res, st.top());
                st.push(infix[i]);
            }
        }
    }

    if ((res.empty() == false) && (res[res.length() - 1] != ' '))
        res += ' ';
    for (; (st.empty() == false) && (st.top() != '('); st.pop())
        appOp(res, st.top());
    if (!st.empty()) //extra (
        return "";

    return res;
}

float doOperator(float x1, float x2, char op)
{
    switch (op)
    {
    case '+':
        return x1 + x2;
    case '-':
        return x1 - x2;
    case '*':
        return x1 * x2;
    case '/':
        return x1 / x2;
    case '^':
        return pow(x1, x2);
    default:
        return 0;
    }
}

float compute(const string& str)
{
    stack<float> st;
    char tmp[256];
    strcpy(tmp, str.c_str());
    char *tok = strtok(tmp, " ");

    while (tok != NULL)
    {
        //cout << tok << "#\n";
        if (!isOperator(tok[0]))
            st.push(atof(tok));
        else
        {
            float x1, x2;
            x2 = st.top(); st.pop();
            x1 = st.top(); st.pop();
            st.push(doOperator(x1, x2, tok[0]));
        }
        tok = strtok(NULL, " ");
    }

    return st.top();
}
