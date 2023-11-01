#include <iostream>
#include <fstream>
#include <string>
#include "S_It.h"
using namespace std;

int main() {
  StackTemplate<int> is;
  for(int i = 0; i < 20; i++)
    is.push(i);
  // Traverse with an iterator:
  cout << "Traverse the whole StackTemplate\n";
  StackTemplate<int>::iterator it = is.begin();
  while(it != is.end())
    cout << it++ << endl;
  cout << "Traverse a portion\n";
  StackTemplate<int>::iterator 
    start = is.begin(), end = is.begin();
  start += 5, end += 15;
  cout << "start = " << start << endl;
  cout << "end = " << end << endl;
  while(start != end)
    cout << start++ << endl;
  ifstream in("m1.cpp");
 
  string line;
  StackTemplate<string,10> strings;
  try
  {
  while(getline(in, line))
    strings.push(line);
  StackTemplate<string,10>::iterator 
    sb = strings.begin(), se = strings.end();
  while(sb != se)
    cout << sb++ << endl;
  }
  catch (Bad B)
  {
	  cout<<B.str<<endl;
  }
} ///:~