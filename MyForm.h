Meu arquivo MyForm.h: #pragma once

namespace Lab {

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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtX;
	private: System::Windows::Forms::Button^ cmdCalc;
	private: System::Windows::Forms::Button^ cmdExit;
	private: System::Windows::Forms::TextBox^ txtResult;
	private: System::Windows::Forms::TextBox^ txtLib;
	private: System::Windows::Forms::Label^ lblDiff;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->cmdCalc = (gcnew System::Windows::Forms::Button());
			this->cmdExit = (gcnew System::Windows::Forms::Button());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->txtLib = (gcnew System::Windows::Forms::TextBox());
			this->lblDiff = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(275, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(275, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(272, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Digite o valor de x";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(264, 140);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(100, 20);
			this->txtX->TabIndex = 3;
			// 
			// cmdCalc
			// 
			this->cmdCalc->Location = System::Drawing::Point(168, 203);
			this->cmdCalc->Name = L"cmdCalc";
			this->cmdCalc->Size = System::Drawing::Size(75, 23);
			this->cmdCalc->TabIndex = 4;
			this->cmdCalc->Text = L"Calcular";
			this->cmdCalc->UseVisualStyleBackColor = true;
			// 
			// cmdExit
			// 
			this->cmdExit->Location = System::Drawing::Point(275, 166);
			this->cmdExit->Name = L"cmdExit";
			this->cmdExit->Size = System::Drawing::Size(75, 23);
			this->cmdExit->TabIndex = 5;
			this->cmdExit->Text = L"Sair";
			this->cmdExit->UseVisualStyleBackColor = true;
			// 
			// txtResult
			// 
			this->txtResult->Location = System::Drawing::Point(275, 219);
			this->txtResult->Name = L"txtResult";
			this->txtResult->Size = System::Drawing::Size(100, 20);
			this->txtResult->TabIndex = 6;
			// 
			// txtLib
			// 
			this->txtLib->Location = System::Drawing::Point(77, 140);
			this->txtLib->Name = L"txtLib";
			this->txtLib->Size = System::Drawing::Size(100, 20);
			this->txtLib->TabIndex = 7;
			// 
			// lblDiff
			// 
			this->lblDiff->AutoSize = true;
			this->lblDiff->Location = System::Drawing::Point(177, 53);
			this->lblDiff->Name = L"lblDiff";
			this->lblDiff->Size = System::Drawing::Size(56, 13);
			this->lblDiff->TabIndex = 8;
			this->lblDiff->Text = L"Diferença:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(417, 261);
			this->Controls->Add(this->lblDiff);
			this->Controls->Add(this->txtLib);
			this->Controls->Add(this->txtResult);
			this->Controls->Add(this->cmdExit);
			this->Controls->Add(this->cmdCalc);
			this->Controls->Add(this->txtX);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "Hello world.";
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
