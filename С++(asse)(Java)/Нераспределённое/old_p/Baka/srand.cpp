#include <iostream>
#include <cstdlib>
#include <ctime>
 
int main ()
{
  std::cout << "������ �����: "          << (rand() % 100) << "\n";
  srand ( time(NULL) );
  std::cout << "��������� �����: "     << (rand() % 100) << "\n";
  srand ( 1 );
  std::cout << "����� ������ �����: " << (rand() % 100) << "\n";
  system("pause");
 
  return 0;
}