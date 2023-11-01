#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
//объединяет две соседние отсортированные последовательности
int main ()
{
  vector <int> v1(10);
  for (int i = 0; i < v1.size (); i++)
    v1[i] = (v1.size () - i - 1) % 5;
  ostream_iterator <int> iter (cout, " ");
  copy (v1.begin (), v1.end (), iter);
  cout << endl;
  inplace_merge (v1.begin (), v1.begin () + 5,
                 v1.end (),
                 greater<int>());
  copy (v1.begin (), v1.end (), iter);
  cout << endl;
  return 0;
}