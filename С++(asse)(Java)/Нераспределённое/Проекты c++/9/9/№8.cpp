#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL,"rus");
	char *q,w='�';
	string s,s1,s2,s3="�";
	int pos=0,e=0;
	s="� ������, �������� ������� �� ����� ������. ";
	s1="��������";
	s2="������";
	cout<<"�������������� �������: "<<endl<<s<<endl;   
	//�������������� �-����� � String


	//����� ��������� (������� � ������ � � �����)
	pos=s.find(s1);
	if (pos!=-1)
		cout<<"���������� ��������: \""<<s1<<"\" ������� � ����� � ������� "<<pos<<endl;
	else 
		cout<<"� ����������� ��� ����� ���������"<<endl;
		pos=s.rfind(s2);
	if (pos!=-1)
		cout<<"���������� ��������: \""<<s2<<"\" ������� � ����� � ������� "<<pos<<endl;
	else
		cout<<"� ����������� ��� ����� ���������";

	//�����������
	s1=s.substr(pos,s.size()-pos);
	cout<<s1<<endl;
	//����� ��� s1=s2;

	 //���������
	if (s>s2)
		cout<<"������ s ������ ������ s2";
	else 
		if(s<s2) 
			cout<<"������ s ������ ������ s2";
		else 
			cout<<"������ ����� �����������������";
		cout<<endl;

	//��������� ��������� ������ �� ������ ��������
	s.replace( s.find("������"), 6, "DDR138");
	cout << s << endl;

	//������� � ������ ������ ������ � �������� �������
	s.insert(s.find("� ������ ")+10,"������������");
	cout << s << endl;

	//����� ������� (������� � ������ � � �����);
	pos=s.find(w); //s.rfind(w); 
	if (pos!=-1) cout<<"������ -"<<w<<"- ������ � ������� ����� "<<pos<<endl;


	//������������ ���������
	for (string::iterator it=s.begin(); it<s.end(); it++)
	if (*it=='�') e++ ;
	cout<<"���������� ���� (�) � ����������� ����� = "<<e<<endl;
	system("pause");
	return 0;
}
