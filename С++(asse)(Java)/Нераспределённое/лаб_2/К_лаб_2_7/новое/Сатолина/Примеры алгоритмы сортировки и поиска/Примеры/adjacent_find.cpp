#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
//Ищет два эквивалентных (равных) соседних элемента. Если искомая пара успешно 
//найдена, алгоритм возвращает итератор для первого из двух элементов; 
//в противном случае возвращается итератор last.

int numbers1 [5] = { 1, 2, 4, 8, 16 };
int numbers2 [5] = { 5, 3, 2, 1, 1 };

int main ()
{
  int* location = adjacent_find (numbers1, numbers1 + 5);

  if (location != numbers1 + 5)
    cout
      << "Found adjacent pair of: "
      << *location
      << " at offset "
      << (location - numbers1)
      << endl;
  else
    cout << "No adjacent pairs" << endl;
  location = adjacent_find (numbers2, numbers2 + 5);
  if (location != numbers2 + 5)
    cout
      << "Found adjacent pair of: "
      << *location
      << " at offset "
      << (location - numbers2)
      << endl;
  else
    cout << "No adjacent pairs" << endl;
  return 0;
}