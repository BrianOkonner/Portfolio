#pragma once


namespace winf {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	protected: 

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(89, 76);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(361, 265);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(89, 361);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 22);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Line";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(234, 360);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Rectangle";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(375, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Pen";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 425);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			    // рисует линию из малых кружков
				 Graphics^ graf = pictureBox1->CreateGraphics();
				 
				 for (int i=1;i<100;i++)
                  graf->FillEllipse(Brushes::Violet, i,i, 10,10); // толщина кисти
                 graf->FillEllipse(System::Drawing::Brushes::Red,100,100,20,20);
			     graf->DrawLine(System::Drawing::Pens::Black, 10,10,10,10);
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
				 	 //покажем картинку,если кликнуть по pictureBox1
				 pictureBox1->Load("Закат.bmp");
			 }
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 // рисует закрашенный зеленый эллипс автоматически
				 e->Graphics->DrawLine(System::Drawing::Pens::Black, 10,10,20,20);
				 e->Graphics->FillEllipse(System::Drawing::Brushes::Green,130,130,55,45);
				 

			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private:System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			// рисует закрашенный прямоугольник
			Graphics^ graf = pictureBox1->CreateGraphics();
			Brush ^ color = gcnew SolidBrush(Color::Orange);//цвет кисти
            graf->Clear(SystemColors::Control);//чистим форму
            graf->FillRectangle(color, 120, 120, 160, 160); 

			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		    //// рисует толстым синим карандашом прямоугольник
			Graphics^ graf = pictureBox1->CreateGraphics();
		    Pen^ gPen = gcnew Pen( Color::Blue,10 );
			graf->DrawRectangle(gPen, 20, 20, 60, 60); 
         
		

		 }
};
}

