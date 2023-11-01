/*
Палазнік І. ПМ-8.
Вучэбная практыка 6.
Семестр 2.
*/

#pragma once
#include "Matrix_lib.h"
#include <string>

namespace MatrixWFDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Matrix matr(3, 3); // Demo-matrix 3x3
	Matrix b(3, 1);

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
	private: System::Windows::Forms::Button^  buttonCount;
	protected: 
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBoxA11;
	private: System::Windows::Forms::TextBox^  textBoxA31;


	private: System::Windows::Forms::TextBox^  textBoxA21;
	private: System::Windows::Forms::TextBox^  textBoxA22;
	private: System::Windows::Forms::TextBox^  textBoxA32;



	private: System::Windows::Forms::TextBox^  textBoxA12;
	private: System::Windows::Forms::TextBox^  textBoxA23;
	private: System::Windows::Forms::TextBox^  textBoxA33;



	private: System::Windows::Forms::TextBox^  textBoxA13;

	private: System::Windows::Forms::TextBox^  textBoxColumns;

	private: System::Windows::Forms::TextBox^  textBoxRows;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxB1;
	private: System::Windows::Forms::TextBox^  textBoxB3;
	private: System::Windows::Forms::TextBox^  textBoxB2;
	private: System::Windows::Forms::TextBox^  textBoxResult;
	private: System::Windows::Forms::Label^  labelEqual1;
	private: System::Windows::Forms::Label^  labelEqual2;
	private: System::Windows::Forms::Label^  labelEqual3;






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
			this->buttonCount = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxA11 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA31 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA21 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA22 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA32 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA12 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA23 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA33 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA13 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxColumns = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRows = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxB1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->labelEqual1 = (gcnew System::Windows::Forms::Label());
			this->labelEqual2 = (gcnew System::Windows::Forms::Label());
			this->labelEqual3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonCount
			// 
			this->buttonCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->buttonCount->Location = System::Drawing::Point(26, 12);
			this->buttonCount->Name = L"buttonCount";
			this->buttonCount->Size = System::Drawing::Size(138, 39);
			this->buttonCount->TabIndex = 0;
			this->buttonCount->Text = L"Вылічыць";
			this->buttonCount->UseVisualStyleBackColor = true;
			this->buttonCount->Click += gcnew System::EventHandler(this, &Form1::buttonCount_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownHeight = 200;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->IntegralHeight = false;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Адваротная матрыца", L"Вызначнік", L"Вырашенне па метадзе Крамера", 
				L"Вырашэнне па метадзе Гаўса"});
			this->comboBox1->Location = System::Drawing::Point(192, 21);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(265, 24);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// textBoxA11
			// 
			this->textBoxA11->AcceptsTab = true;
			this->textBoxA11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA11->Location = System::Drawing::Point(29, 90);
			this->textBoxA11->MaxLength = 3;
			this->textBoxA11->Name = L"textBoxA11";
			this->textBoxA11->Size = System::Drawing::Size(50, 24);
			this->textBoxA11->TabIndex = 2;
			this->textBoxA11->Text = L"0";
			this->textBoxA11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA11->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA31
			// 
			this->textBoxA31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA31->Location = System::Drawing::Point(29, 196);
			this->textBoxA31->MaxLength = 3;
			this->textBoxA31->Name = L"textBoxA31";
			this->textBoxA31->Size = System::Drawing::Size(50, 24);
			this->textBoxA31->TabIndex = 8;
			this->textBoxA31->Text = L"0";
			this->textBoxA31->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA31->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA21
			// 
			this->textBoxA21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA21->Location = System::Drawing::Point(29, 142);
			this->textBoxA21->MaxLength = 3;
			this->textBoxA21->Name = L"textBoxA21";
			this->textBoxA21->Size = System::Drawing::Size(50, 24);
			this->textBoxA21->TabIndex = 5;
			this->textBoxA21->Text = L"0";
			this->textBoxA21->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA21->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA22
			// 
			this->textBoxA22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA22->Location = System::Drawing::Point(103, 142);
			this->textBoxA22->MaxLength = 3;
			this->textBoxA22->Name = L"textBoxA22";
			this->textBoxA22->Size = System::Drawing::Size(50, 24);
			this->textBoxA22->TabIndex = 6;
			this->textBoxA22->Text = L"0";
			this->textBoxA22->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA22->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA32
			// 
			this->textBoxA32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA32->Location = System::Drawing::Point(103, 196);
			this->textBoxA32->MaxLength = 3;
			this->textBoxA32->Name = L"textBoxA32";
			this->textBoxA32->Size = System::Drawing::Size(50, 24);
			this->textBoxA32->TabIndex = 9;
			this->textBoxA32->Text = L"0";
			this->textBoxA32->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA32->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA12
			// 
			this->textBoxA12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA12->Location = System::Drawing::Point(103, 90);
			this->textBoxA12->MaxLength = 3;
			this->textBoxA12->Name = L"textBoxA12";
			this->textBoxA12->Size = System::Drawing::Size(50, 24);
			this->textBoxA12->TabIndex = 3;
			this->textBoxA12->Text = L"0";
			this->textBoxA12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA12->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA23
			// 
			this->textBoxA23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA23->Location = System::Drawing::Point(179, 142);
			this->textBoxA23->MaxLength = 3;
			this->textBoxA23->Name = L"textBoxA23";
			this->textBoxA23->Size = System::Drawing::Size(50, 24);
			this->textBoxA23->TabIndex = 7;
			this->textBoxA23->Text = L"0";
			this->textBoxA23->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA23->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA33
			// 
			this->textBoxA33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA33->Location = System::Drawing::Point(179, 196);
			this->textBoxA33->MaxLength = 3;
			this->textBoxA33->Name = L"textBoxA33";
			this->textBoxA33->Size = System::Drawing::Size(50, 24);
			this->textBoxA33->TabIndex = 10;
			this->textBoxA33->Text = L"0";
			this->textBoxA33->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA33->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxA13
			// 
			this->textBoxA13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxA13->Location = System::Drawing::Point(179, 90);
			this->textBoxA13->MaxLength = 3;
			this->textBoxA13->Name = L"textBoxA13";
			this->textBoxA13->Size = System::Drawing::Size(50, 24);
			this->textBoxA13->TabIndex = 4;
			this->textBoxA13->Text = L"0";
			this->textBoxA13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA13->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxA11_TextChanged);
			// 
			// textBoxColumns
			// 
			this->textBoxColumns->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxColumns->Enabled = false;
			this->textBoxColumns->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxColumns->ForeColor = System::Drawing::Color::DarkRed;
			this->textBoxColumns->Location = System::Drawing::Point(560, 18);
			this->textBoxColumns->Name = L"textBoxColumns";
			this->textBoxColumns->Size = System::Drawing::Size(40, 26);
			this->textBoxColumns->TabIndex = 0;
			this->textBoxColumns->Text = L"3";
			this->textBoxColumns->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxRows
			// 
			this->textBoxRows->Enabled = false;
			this->textBoxRows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxRows->ForeColor = System::Drawing::Color::DarkRed;
			this->textBoxRows->Location = System::Drawing::Point(492, 18);
			this->textBoxRows->Name = L"textBoxRows";
			this->textBoxRows->Size = System::Drawing::Size(40, 26);
			this->textBoxRows->TabIndex = 0;
			this->textBoxRows->Text = L"3";
			this->textBoxRows->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(538, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 20);
			this->label1->TabIndex = 13;
			this->label1->Text = L"x";
			// 
			// textBoxB1
			// 
			this->textBoxB1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxB1->Location = System::Drawing::Point(277, 90);
			this->textBoxB1->MaxLength = 3;
			this->textBoxB1->Name = L"textBoxB1";
			this->textBoxB1->Size = System::Drawing::Size(50, 24);
			this->textBoxB1->TabIndex = 11;
			this->textBoxB1->Text = L"0";
			this->textBoxB1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxB1->Visible = false;
			this->textBoxB1->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxB2_TextChanged);
			// 
			// textBoxB3
			// 
			this->textBoxB3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxB3->Location = System::Drawing::Point(277, 196);
			this->textBoxB3->MaxLength = 3;
			this->textBoxB3->Name = L"textBoxB3";
			this->textBoxB3->Size = System::Drawing::Size(50, 24);
			this->textBoxB3->TabIndex = 13;
			this->textBoxB3->Text = L"0";
			this->textBoxB3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxB3->Visible = false;
			this->textBoxB3->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxB2_TextChanged);
			// 
			// textBoxB2
			// 
			this->textBoxB2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxB2->Location = System::Drawing::Point(277, 142);
			this->textBoxB2->MaxLength = 3;
			this->textBoxB2->Name = L"textBoxB2";
			this->textBoxB2->Size = System::Drawing::Size(50, 24);
			this->textBoxB2->TabIndex = 12;
			this->textBoxB2->Text = L"0";
			this->textBoxB2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxB2->Visible = false;
			this->textBoxB2->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxB2_TextChanged);
			// 
			// textBoxResult
			// 
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(364, 90);
			this->textBoxResult->Multiline = true;
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(236, 130);
			this->textBoxResult->TabIndex = 0;
			this->textBoxResult->Text = L"Тут будуць вылічэнні";
			this->textBoxResult->Visible = false;
			// 
			// labelEqual1
			// 
			this->labelEqual1->AutoSize = true;
			this->labelEqual1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelEqual1->Location = System::Drawing::Point(244, 92);
			this->labelEqual1->Name = L"labelEqual1";
			this->labelEqual1->Size = System::Drawing::Size(18, 20);
			this->labelEqual1->TabIndex = 13;
			this->labelEqual1->Text = L"=";
			this->labelEqual1->Visible = false;
			// 
			// labelEqual2
			// 
			this->labelEqual2->AutoSize = true;
			this->labelEqual2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelEqual2->Location = System::Drawing::Point(244, 142);
			this->labelEqual2->Name = L"labelEqual2";
			this->labelEqual2->Size = System::Drawing::Size(18, 20);
			this->labelEqual2->TabIndex = 13;
			this->labelEqual2->Text = L"=";
			this->labelEqual2->Visible = false;
			// 
			// labelEqual3
			// 
			this->labelEqual3->AutoSize = true;
			this->labelEqual3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelEqual3->Location = System::Drawing::Point(244, 196);
			this->labelEqual3->Name = L"labelEqual3";
			this->labelEqual3->Size = System::Drawing::Size(18, 20);
			this->labelEqual3->TabIndex = 13;
			this->labelEqual3->Text = L"=";
			this->labelEqual3->Visible = false;
			// 
			// Form1
			// 
			this->AcceptButton = this->buttonCount;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 262);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->labelEqual3);
			this->Controls->Add(this->labelEqual2);
			this->Controls->Add(this->labelEqual1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxColumns);
			this->Controls->Add(this->textBoxRows);
			this->Controls->Add(this->textBoxB2);
			this->Controls->Add(this->textBoxA23);
			this->Controls->Add(this->textBoxB3);
			this->Controls->Add(this->textBoxB1);
			this->Controls->Add(this->textBoxA33);
			this->Controls->Add(this->textBoxA13);
			this->Controls->Add(this->textBoxA22);
			this->Controls->Add(this->textBoxA32);
			this->Controls->Add(this->textBoxA12);
			this->Controls->Add(this->textBoxA21);
			this->Controls->Add(this->textBoxA31);
			this->Controls->Add(this->textBoxA11);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->buttonCount);
			this->MinimumSize = System::Drawing::Size(650, 300);
			this->Name = L"Form1";
			this->Text = L"Matrix Demo";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
			 {
				 comboBox1->SelectedIndex = 0; // Выбіраем першы элемент са спісу

				 textBoxA11->Text = Matrix::string_to_String(Matrix::double_to_string(matr(0, 0)));
				 textBoxA12->Text = Matrix::string_to_String(Matrix::double_to_string(matr(0, 1)));
				 textBoxA13->Text = Matrix::string_to_String(Matrix::double_to_string(matr(0, 2)));
				 textBoxA21->Text = Matrix::string_to_String(Matrix::double_to_string(matr(1, 0)));
				 textBoxA22->Text = Matrix::string_to_String(Matrix::double_to_string(matr(1, 1)));
				 textBoxA23->Text = Matrix::string_to_String(Matrix::double_to_string(matr(1, 2)));
				 textBoxA31->Text = Matrix::string_to_String(Matrix::double_to_string(matr(2, 0)));
				 textBoxA32->Text = Matrix::string_to_String(Matrix::double_to_string(matr(2, 1)));
				 textBoxA33->Text = Matrix::string_to_String(Matrix::double_to_string(matr(2, 2)));				 

				 textBoxB1->Text = Matrix::string_to_String(Matrix::double_to_string(b(0, 0)));
				 textBoxB2->Text = Matrix::string_to_String(Matrix::double_to_string(b(1, 0)));
				 textBoxB3->Text = Matrix::string_to_String(Matrix::double_to_string(b(2, 0)));
			 }
private: System::Void textBoxB2_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 textBoxResult->Visible = false;
		 }

private: System::Void buttonCount_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 std::string input;

			 Matrix::String_to_string(textBoxA11->Text, input);
			 matr(0, 0) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA12->Text, input);
			 matr(0, 1) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA13->Text, input);
			 matr(0, 2) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA21->Text, input);
			 matr(1, 0) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA22->Text, input);
			 matr(1, 1) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA23->Text, input);
			 matr(1, 2) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA31->Text, input);
			 matr(2, 0) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA32->Text, input);
			 matr(2, 1) = atof(input.c_str());

			 Matrix::String_to_string(textBoxA33->Text, input);
			 matr(2, 2) = atof(input.c_str());

			 int index = comboBox1->SelectedIndex;
			 double det;
			 std::string output;
			 std::vector<std::string> out_matrix;

			 if(index > 1)
			 {
				 Matrix::String_to_string(textBoxB1->Text, input);
				 b(0, 0) = atof(input.c_str());

				 Matrix::String_to_string(textBoxB2->Text, input);
				 b(1, 0) = atof(input.c_str());

				 Matrix::String_to_string(textBoxB3->Text, input);
				 b(2, 0) = atof(input.c_str());
			 }

			 switch (index)
			 {
			 case inverse:
				 output = "Адваротная матрыца да A:";
				 out_matrix = matr.inverse();
				 break;

			 case determinant:
				 output = "det(A) = " + Matrix::double_to_string(matr.determinant());
				 break;

			 case Kramer:
				 output = "Крамер:";
				 out_matrix = matr.Kramer_rule(b);
				 break;

			 case Gauss:
				 output = "Гаўс:";
				 out_matrix = matr.Gauss_method(b);
				 break;
			 }

			 textBoxResult->Visible = true;
			 textBoxResult->Text = Matrix::string_to_String(output);
			 for(int i=0; i<out_matrix.size(); ++i)
				 textBoxResult->Text += Environment::NewLine // для шматрадковасці
										+ Matrix::string_to_String(out_matrix[i]);


		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(comboBox1->SelectedIndex == 2 || comboBox1->SelectedIndex == 3)
			 {
				 textBoxB1->Visible = true;	textBoxB2->Visible = true;
				 textBoxB3->Visible = true;	labelEqual1->Visible = true;
				 labelEqual2->Visible = true; labelEqual3->Visible = true;
			 }
			 else
			 {
				 textBoxB1->Visible = false;	textBoxB2->Visible = false;
				 textBoxB3->Visible = false;	labelEqual1->Visible = false;
				 labelEqual2->Visible = false;	labelEqual3->Visible = false;
			 }
			 textBoxResult->Visible = false;
		 }
private: System::Void textBoxA11_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 textBoxResult->Visible = false;
		 }
};
}

