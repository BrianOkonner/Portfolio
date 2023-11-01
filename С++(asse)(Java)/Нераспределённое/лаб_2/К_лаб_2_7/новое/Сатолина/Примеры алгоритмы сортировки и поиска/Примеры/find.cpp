#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
int years[] = { 1942, 1952, 1962, 1972, 1982, 1992 };

int main ()
{
  const unsigned yearCount = sizeof (years) / sizeof (years[0]);
  int* location = find (years, years + yearCount, 1972);
  cout << "Found 1972 at offset " << (location - years) << endl;
  return 0;
}