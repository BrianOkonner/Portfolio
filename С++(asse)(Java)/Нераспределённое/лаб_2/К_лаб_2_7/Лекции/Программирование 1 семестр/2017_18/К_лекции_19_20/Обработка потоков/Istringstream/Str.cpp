// istringstream::str

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {

  int n;

  istringstream iss;
  string s = "0 1 2";

  iss.str(s);

  for (int i = 0; i < 3; ++i)
  {
    iss >> n;
    cout << n + 1 << endl;
  }

  return 1;
}
