/*
������� ������� 1 ���� 8 ������

������� ��������. ������� 9: ������

����������� ���������, ������������� � ������������ ��� ������� - ����������� N.  ������������ ������� ����������� �������.

0��� ������� ��������� � �������� ������������ ������� �������, �� �������� ��������� � ������� (������ � - ������, ������ � - ������).
������������� �������������� ���������� ��������� � �� �����. ��� ��������� �������� ��� ����� ������� � ������, ����� ������ ����� ��������
� ���� ���������. � ���� ���������� (�/�) �������� ����� ������� ���������������� �������.

���������� Windows Forms.
*/


#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project5::MyForm form;
	Application::Run(%form);
}