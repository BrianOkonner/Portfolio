#include <iostream>
#include <cstdlib>
#include <ctime>
 
int main ()
{
  std::cout << "Первое число: "          << (rand() % 100) << "\n";
  srand ( time(NULL) );
  std::cout << "Случайное число: "     << (rand() % 100) << "\n";
  srand ( 1 );
  std::cout << "Снова первое число: " << (rand() % 100) << "\n";
  system("pause");
 
  return 0;
}