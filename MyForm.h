#pragma once

namespace Lab10 {

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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtN;
	private: System::Windows::Forms::TextBox^ txtA;
	private: System::Windows::Forms::TextBox^ txtB;
	private: System::Windows::Forms::Button^ btnSolve;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::ListBox^ IstOriginal;
	private: System::Windows::Forms::ListBox^ IstNew;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtN = (gcnew System::Windows::Forms::TextBox());
			this->txtA = (gcnew System::Windows::Forms::TextBox());
			this->txtB = (gcnew System::Windows::Forms::TextBox());
			this->btnSolve = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->IstOriginal = (gcnew System::Windows::Forms::ListBox());
			this->IstNew = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"n:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"a:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"b:";
			// 
			// txtN
			// 
			this->txtN->Location = System::Drawing::Point(34, 27);
			this->txtN->Name = L"txtN";
			this->txtN->Size = System::Drawing::Size(100, 20);
			this->txtN->TabIndex = 3;
			// 
			// txtA
			// 
			this->txtA->Location = System::Drawing::Point(34, 97);
			this->txtA->Name = L"txtA";
			this->txtA->Size = System::Drawing::Size(100, 20);
			this->txtA->TabIndex = 4;
			// 
			// txtB
			// 
			this->txtB->Location = System::Drawing::Point(34, 159);
			this->txtB->Name = L"txtB";
			this->txtB->Size = System::Drawing::Size(100, 20);
			this->txtB->TabIndex = 5;
			// 
			// btnSolve
			// 
			this->btnSolve->Location = System::Drawing::Point(15, 269);
			this->btnSolve->Name = L"btnSolve";
			this->btnSolve->Size = System::Drawing::Size(75, 23);
			this->btnSolve->TabIndex = 6;
			this->btnSolve->Text = L"Resolver";
			this->btnSolve->UseVisualStyleBackColor = true;
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(115, 269);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 7;
			this->btnExit->Text = L"Sair";
			this->btnExit->UseVisualStyleBackColor = true;
			// 
			// IstOriginal
			// 
			this->IstOriginal->FormattingEnabled = true;
			this->IstOriginal->Location = System::Drawing::Point(291, 27);
			this->IstOriginal->Name = L"IstOriginal";
			this->IstOriginal->Size = System::Drawing::Size(120, 95);
			this->IstOriginal->TabIndex = 8;
			// 
			// IstNew
			// 
			this->IstNew->FormattingEnabled = true;
			this->IstNew->Location = System::Drawing::Point(291, 197);
			this->IstNew->Name = L"IstNew";
			this->IstNew->Size = System::Drawing::Size(120, 95);
			this->IstNew->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(517, 346);
			this->Controls->Add(this->IstNew);
			this->Controls->Add(this->IstOriginal);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnSolve);
			this->Controls->Add(this->txtB);
			this->Controls->Add(this->txtA);
			this->Controls->Add(this->txtN);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
