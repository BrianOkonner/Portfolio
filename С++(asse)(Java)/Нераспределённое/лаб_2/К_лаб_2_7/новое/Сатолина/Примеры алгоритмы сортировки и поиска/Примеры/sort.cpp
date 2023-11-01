#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int array [4] = { 3, 1, 4, 2 };

int main ()
{
  sort (array, array + 4, greater <int> ());
  for (int i = 0; i < 4; i++)
    cout << array[i] << endl;
  return 0;
}
 