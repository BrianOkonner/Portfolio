#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
using namespace std;
//�������� ��������� �������� ��������� ���, ����� 
//������� *nth ������� ���������� � �������� ���������� �����, 
//�.�. ��� ���������� �������� ������ ���, � ����������� ������.
int main ()
{
  vector <int> v1 (10);
  for (int i = 0; i < v1.size (); i++)
    v1[i] = rand () % 10;
  ostream_iterator<int> iter (cout, " ");
  copy (v1.begin (), v1.end (), iter);
  cout << endl;
  nth_element (v1.begin (),
               /*v1.begin () + v1.size () / 2*/v1.begin()+2,
               v1.end ());
  copy (v1.begin (), v1.end (), iter);
  cout << endl;
  return 0;
}