#ifndef PSTASH_H
#define PSTASH_H
#include <iosfwd>
#include <iostream>
using std::ostream;
using std::istream;

class PStash {
  int quantity; // ���������� ���������
  int next; // ��������� ������ �������
   // ������ ��� �������� ����������:
  void** storage;
  void inflate(int increase);
public:
  PStash() : quantity(0), storage(0), next(0) {}
  ~PStash();

  int add(void* element);
  void* operator[](int index) const; // �������
  // �������� ������ �� PStash:
  void* remove(int index);
  // ���������� ��������� � Stash:
  int count() const { return next; }

};
#endif // PSTASH_H ///:~