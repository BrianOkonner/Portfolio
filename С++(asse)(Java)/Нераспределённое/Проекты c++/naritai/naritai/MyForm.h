#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

#define helpstr "Учебная практика вектор. Выполнил Андреев Дмитрий 1 к. 8 гр.\nПрограмма выполняет действия с векторами STL. Оба вектора создаются с заданной размерностью кнопкой создать, их элементы выводятся в списках (вактор А - первый, вектор Б - второй). Автоматически подсчитывается количество элементов и их сумма. Для изменения элемента его нужно выбрать в списке, затем ввести новое значение в поле Изменение. В поле Добавление (А/Б) вводится новый элемент соответствующего вектора.\nКнопки:\n ОК - принять изменения элемента\n Del - Удалить выделенный элемент\n Sort(A/B) - Отсортировать вектор\n p.Sort - Отсортировать половину вектора\n Кон.(А/Б) - Добавление элемента в конец\n Сер.(А/Б) - Добавление в середину\n Поиск - Проверка наличия элемента в векторе Б\n count - Посчитать количество элементов, равных данному\n -> - Копирование вектора А в Б\n + - Сложение элементов векторов\nПримечание: кнопка поиск доступна только после сортировки вектора Б. Приложение Windows Forms."

std::vector <double> a;
std::vector <double> b;

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
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
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;


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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(13, 13);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(136, 84);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Location = System::Drawing::Point(198, 12);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(137, 84);
			this->listBox2->TabIndex = 1;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox2_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 200);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(198, 200);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"ОК";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(11, 172);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 22);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(198, 172);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(137, 22);
			this->textBox2->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(357, 44);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Создать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(357, 13);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(75, 22);
			this->textBox3->TabIndex = 7;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(86, 285);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Кон. А";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 285);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(68, 22);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(198, 287);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(70, 22);
			this->textBox5->TabIndex = 10;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(88, 318);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(62, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Сер. Б";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(274, 286);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(61, 22);
			this->button6->TabIndex = 12;
			this->button6->Text = L"Кон. Б";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(274, 318);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(61, 23);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Сер. Б";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(86, 200);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(63, 23);
			this->button8->TabIndex = 14;
			this->button8->Text = L"Del";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(274, 200);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(61, 23);
			this->button9->TabIndex = 15;
			this->button9->Text = L"Del";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(12, 229);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(68, 23);
			this->button10->TabIndex = 16;
			this->button10->Text = L"Sort A";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(198, 229);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(70, 23);
			this->button11->TabIndex = 17;
			this->button11->Text = L"Sort B";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(87, 229);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(62, 23);
			this->button12->TabIndex = 18;
			this->button12->Text = L"p.sort A";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(274, 229);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(61, 23);
			this->button13->TabIndex = 19;
			this->button13->Text = L"p.Sort B";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 17);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Количество";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(103, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 21;
			this->label2->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(198, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 17);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Количество";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(291, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 17);
			this->label4->TabIndex = 23;
			this->label4->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 17);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Сумма";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(201, 125);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 17);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Сумма";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(103, 125);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 17);
			this->label7->TabIndex = 26;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(291, 125);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(16, 17);
			this->label8->TabIndex = 27;
			this->label8->Text = L"0";
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(155, 13);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(37, 40);
			this->button14->TabIndex = 28;
			this->button14->Text = L"->";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(198, 383);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(68, 22);
			this->textBox6->TabIndex = 29;
			// 
			// button15
			// 
			this->button15->Enabled = false;
			this->button15->Location = System::Drawing::Point(272, 382);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(61, 23);
			this->button15->TabIndex = 30;
			this->button15->Text = L"Поиск";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(198, 264);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(103, 17);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Добавление Б";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(11, 264);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(107, 17);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Добавление А:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(198, 360);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(139, 17);
			this->label11->TabIndex = 33;
			this->label11->Text = L"Проверить наличие";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(13, 152);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(82, 17);
			this->label12->TabIndex = 34;
			this->label12->Text = L"Изменение";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(198, 152);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(82, 17);
			this->label13->TabIndex = 35;
			this->label13->Text = L"Изменение";
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(11, 415);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(75, 23);
			this->button16->TabIndex = 36;
			this->button16->Text = L"Справка";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(272, 411);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(61, 23);
			this->button17->TabIndex = 37;
			this->button17->Text = L"count";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(155, 60);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(37, 37);
			this->button18->TabIndex = 38;
			this->button18->Text = L"+";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 450);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
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

	label2->Text = a.size().ToString();
	label4->Text = b.size().ToString();
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
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) { //кн. добавить в конец a
if (textBox4->Text!="")
	a.push_back(Convert::ToDouble(textBox4->Text));
	RenewListbox();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) { //кн. добавить в середину a
	
	if (textBox4->Text != "") {
		std::vector <double>::iterator it;
		it = a.begin();
		it += a.size() / 2;
		a.insert(it, Convert::ToDouble(textBox4->Text));
	}
	RenewListbox();
}


private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) { //кн добавить в конец б
	if (textBox5->Text != "") {
		button15->Enabled = false;
		b.push_back(Convert::ToDouble(textBox5->Text));
	}
	RenewListbox();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) { // кн добавить в середину б
	std::vector <double>::iterator it;
	if (textBox5->Text != ""){
		button15->Enabled = false;
	it = b.begin();
	it += b.size() / 2;
	b.insert(it, Convert::ToDouble(textBox5->Text));
	}
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

private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show(helpstr, "Справка");
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
};
}
