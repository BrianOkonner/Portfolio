/*
Андреев Дмитрий 1 курс 8 группа

Учебная практика. Задание 9: вектор

Разработать программу, запрашивающую у пользователя два вектора - размерности N.  Использовать готовые стандартные функции.

0Оба вектора создаются с заданной размерностью кнопкой создать, их элементы выводятся в списках (вактор А - первый, вектор Б - второй).
Автоматически подсчитывается количество элементов и их сумма. Для изменения элемента его нужно выбрать в списке, затем ввести новое значение
в поле Изменение. В поле Добавление (А/Б) вводится новый элемент соответствующего вектора.

Приложение Windows Forms.
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