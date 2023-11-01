#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <time.h>
using namespace std;

int main ()
{
  int vector[100];
  for (int i = 0; i < 100; i++)
    vector[i] = i;
  if (binary_search (vector, vector + 100, 42))
    cout << "found 42" << endl;
  else
    cout << "did not find 42" << endl;
  return 0;
}