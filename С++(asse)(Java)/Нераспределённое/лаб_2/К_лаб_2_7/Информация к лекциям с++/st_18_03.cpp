#include <cstring>  
#include <string> 
#include <fstream>
using namespace std; 
class char_stack {
      int size;		// max ������ ������� 
      char* top;	// �������� �����
      char* s;		// ������ �������
      char_stack(){} // ����������� �� ��������� � ������� private, 
					 //	����� ��������� ������������ ��������� ������ �� ������� ������
  public:
      
	  char_stack(int sz)
		{ top=s=new char[size=sz]; }	// ����������� ��� ��������� ������
      
	  char_stack(const char_stack&);	//����������� �����������
      
	  ~char_stack() { delete s; }		// ����������
      
	  void push(char c)					
		{ if (top!=s+size) *top++ = c;  }
      
	  char pop() 
	  { if (top-s) return *--top; else return 0; }  // 0 ������� ������� �����
	  
	  char_stack& operator=( const char_stack&);
  };

  char_stack::char_stack(const char_stack& r):size(r.size) // ������������� � ������
  { 
	  top=s=new char[size=r.size];  // ������������� � ���� ������������
	  memcpy(s,r.s,size);
	  top= s+(r.top-r.s);
  }

  char_stack& char_stack::operator=(const char_stack& r)
  { 
	  if (this != &r)
	  {
		  delete s;
	  size= r.size;
	  top=s=new char[size=r.size]; 
	  memcpy(s,r.s,size);
	  top= s+(r.top-r.s);
	  }
	  return *this;
  }
  
  main()
  {
	  ifstream in("in.txt");
	  ofstream out("out.txt");
	  char_stack A(10);
	  string s;
	  char c;
	  in>>s;
	  out<<s<<endl;

	  for (int i=0; i<s.length(); i++)
		  A.push(s[i]);

	  char_stack B(A);
	  while (c=B.pop())
		  out<<c;
	  out<<endl;

	  A.push('O');
	  A.push('k');

	  B=A; // B �����, ����� �� ��������� A
	  while (c=B.pop())
		  out<<c;
	  out<<endl;
	  
	  A.push('O'); A.push('O'); A.push('O'); A.push('O'); A.push('O'); A.push('O');
	  // ������� �� ������� �������
	  B=A;
	  while (c=B.pop())
		  out<<c;
	  out<<endl;
  }





