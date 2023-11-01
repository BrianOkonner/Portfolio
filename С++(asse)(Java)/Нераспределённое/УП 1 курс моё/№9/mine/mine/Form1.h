#pragma once
#include "StdAfx.h"
#include <vector>
#include <algorithm>
#include <numeric>

std::vector <double> a;
std::vector <double> b;

namespace mine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox3;






	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;






	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button15;







	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;


	private: System::Windows::Forms::Label^  label15;

	private: System::Windows::Forms::Label^  label17;

	private: System::Windows::Forms::Label^  label19;

	private: System::Windows::Forms::Label^  label20;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(11, 11);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(75, 173);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(11, 244);
			this->listBox2->Margin = System::Windows::Forms::Padding(2);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(75, 173);
			this->listBox2->TabIndex = 1;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox2_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(248, 55);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(51, 19);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(247, 282);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(52, 19);
			this->button2->TabIndex = 3;
			this->button2->Text = L"ОК";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(179, 51);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 49);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(179, 282);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(64, 49);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(299, 205);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(69, 19);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Создать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(238, 205);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(57, 20);
			this->textBox3->TabIndex = 7;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(249, 80);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(47, 19);
			this->button8->TabIndex = 14;
			this->button8->Text = L"OK";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(249, 310);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(46, 19);
			this->button9->TabIndex = 15;
			this->button9->Text = L"OK";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(107, 104);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(158, 19);
			this->button10->TabIndex = 16;
			this->button10->Text = L"Сортировать вектор №1";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(107, 338);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(158, 19);
			this->button11->TabIndex = 17;
			this->button11->Text = L"Сортировать вектор №2";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(104, 11);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"№1: сумма ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(104, 244);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"№2: сумма ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(174, 11);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(174, 244);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 27;
			this->label8->Text = L"0";
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(20, 197);
			this->button14->Margin = System::Windows::Forms::Padding(2);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(28, 32);
			this->button14->TabIndex = 28;
			this->button14->Text = L"↓";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(448, 200);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(52, 20);
			this->textBox6->TabIndex = 29;
			// 
			// button15
			// 
			this->button15->Enabled = false;
			this->button15->Location = System::Drawing::Point(437, 224);
			this->button15->Margin = System::Windows::Forms::Padding(2);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(73, 19);
			this->button15->TabIndex = 30;
			this->button15->Text = L"Поиск";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(52, 198);
			this->button18->Margin = System::Windows::Forms::Padding(2);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(28, 30);
			this->button18->TabIndex = 38;
			this->button18->Text = L"+";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(95, 207);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(139, 13);
			this->label14->TabIndex = 78;
			this->label14->Text = L"Вектора с размерностью:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(104, 34);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 80;
			this->label1->Text = L"Выбранный элемент";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(104, 80);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(50, 13);
			this->label12->TabIndex = 83;
			this->label12->Text = L"Удалить";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(104, 58);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(71, 13);
			this->label13->TabIndex = 84;
			this->label13->Text = L"изменить на";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(420, 185);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(113, 13);
			this->label15->TabIndex = 87;
			this->label15->Text = L"Найти элемент в №2";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(104, 313);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(50, 13);
			this->label17->TabIndex = 91;
			this->label17->Text = L"Удалить";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(104, 267);
			this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(112, 13);
			this->label19->TabIndex = 89;
			this->label19->Text = L"Выбранный элемент";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(104, 289);
			this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(71, 13);
			this->label20->TabIndex = 93;
			this->label20->Text = L"изменить на";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 447);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void RenewListbox() {
	listBox1->Items->Clear();
	listBox2->Items->Clear();
	for (int i = 0; i < a.size(); i++) listBox1->Items->Add(a.at(i));
	for (int i = 0; i < b.size(); i++) listBox2->Items->Add(b.at(i));

	double suma = std::accumulate(a.begin(), a.end(), 0);
	double sumb = std::accumulate(b.begin(), b.end(), 0);

	label7->Text = suma.ToString();
	label8->Text = sumb.ToString();

}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	int size;
	if (textBox3->Text!=""){
		button15->Enabled = false;
	size = Convert::ToInt32(textBox3->Text);
	if (!a.empty()) a.clear();
	if (!b.empty()) b.clear();
	a.resize(size, 0);
	b.resize(size, 0);
}
	RenewListbox();

	/*listBox1->Items->Clear();
	listBox2->Items->Clear();
	for (int i = 0; i < size; i++) {
		listBox1->Items->Add(a.at(i));
		listBox2->Items->Add(b.at(i));
	}*/
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text = a.at(listBox1->SelectedIndex).ToString();
	textBox1->Focus();
}
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox2->Text = b.at(listBox2->SelectedIndex).ToString();
	textBox2->Focus();
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (listBox1->SelectedIndex>=0)
		a.at(listBox1->SelectedIndex) = Convert::ToDouble(textBox1->Text);
	RenewListbox();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	if (listBox2->SelectedIndex >= 0)
		b.at(listBox2->SelectedIndex) = Convert::ToDouble(textBox2->Text);
	RenewListbox();
}


private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) { //кн удалить из а
	std::vector <double>::iterator it;

	if (listBox1->SelectedIndex >= 0) {

		it = a.begin();
		it += listBox1->SelectedIndex;
		a.erase(it);
	}
	RenewListbox();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) { //кн. удалить из б
	std::vector <double>::iterator it;
	if (listBox2->SelectedIndex >= 0) {
		button15->Enabled = false;
		it = b.begin();
		it += listBox2->SelectedIndex;

		b.erase(it);
	}

	RenewListbox();
}


private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) { // сортировка a
	if (!a.empty()) std::sort(a.begin(), a.end());
	
	RenewListbox();
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {// сортировка b
	if (!b.empty()) std::sort(b.begin(), b.end());
	button15->Enabled = true;
	RenewListbox();
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) { // частичная сортировка a
	
	std::vector <double>::iterator it = a.begin();
	it += a.size() / 2;
	if (!a.empty()) std::partial_sort(a.begin(), it, a.end());

	RenewListbox();
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	std::vector <double>::iterator it = b.begin();
	it += b.size() / 2;
	if (!b.empty()) std::partial_sort(b.begin(), it, b.end());

	RenewListbox();

}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	b.clear();
	b.resize(a.size());
	std::copy(a.begin(), a.end(), b.begin());
	RenewListbox();
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox6->Text != "") {
		double k = Convert::ToDouble(textBox6->Text);
		if (std::binary_search(b.begin(), b.end(), k))
			MessageBox::Show("Элемент найден", "Бинарный поиск:");
		else
			MessageBox::Show("Элемент не найден или вектор не отсортирован", "Бинарный поиск: ");
	}
}

private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox6->Text != "") {
		int k = Convert::ToInt32(textBox6->Text);
		int res = std::count(b.begin(), b.end(), k);
		MessageBox::Show("Найдено " + res.ToString() + " элемента", "count:");
	}
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	
	for (int i = 0; i < a.size() && i < b.size(); i++) {
		a.at(i) += b.at(i);
	}

	RenewListbox();
}

private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
