// ��9(vector+algorithm).cpp: ������� ���� �������.

#include "stdafx.h"
#include "Form1.h"
#include <vector>
#include <algorithm>
using namespace ��9vectoralgorithm;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());
	return 0;
}
