//Simon Karasik, group 5
/*15. В файле input.txt задан набор целых чисел.
Записать их в память используя свой стек-массив.
Просматривая стек, поменяйте порядок элементов на обратный.
Pезультат из стека записать в стандартный список и вывести в файл Output.txt*/

#include "ArrayStack.h"
#include <fstream>
#include <list>

using namespace std;

void reverse(ArrayStack& stack)
{
    if (stack.isEmpty())
        return;
    int t = stack.top();
    stack.pop();
    reverse(stack);
    stack.push(t);
}

int main()
{
    const int MAX_STACK_SIZE = 250;

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    ArrayStack stack(MAX_STACK_SIZE);
    list<int> list;

    while (!fin.eof())
    {
        int t;
        fin >> t;
        stack.push(t);
    }
    reverse(stack);
    while (!stack.isEmpty())
    {
        list.push_back(stack.top());
        stack.pop();
    }

    while (!list.empty())
    {
        fout << list.front() << ' ';
        list.pop_front();
    }

    return 0;
}