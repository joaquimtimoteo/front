#pragma once

namespace Lb11 {

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
	private: System::Windows::Forms::TextBox^ txtInput;
	private: System::Windows::Forms::Button^ btnSolve;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::ListBox^ lstOutput;
	private: System::Windows::Forms::Label^ lblInstructions;
	private: System::Windows::Forms::Label^ lblStatus;
	protected:

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
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnSolve = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->lstOutput = (gcnew System::Windows::Forms::ListBox());
			this->lblInstructions = (gcnew System::Windows::Forms::Label());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(75, 86);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(100, 20);
			this->txtInput->TabIndex = 0;
			// 
			// btnSolve
			// 
			this->btnSolve->Location = System::Drawing::Point(46, 180);
			this->btnSolve->Name = L"btnSolve";
			this->btnSolve->Size = System::Drawing::Size(75, 23);
			this->btnSolve->TabIndex = 1;
			this->btnSolve->Text = L"Resolver Tarefa";
			this->btnSolve->UseVisualStyleBackColor = true;
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(45, 151);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 2;
			this->btnClear->Text = L"Limpar";
			this->btnClear->UseVisualStyleBackColor = true;
			// 
			// lstOutput
			// 
			this->lstOutput->FormattingEnabled = true;
			this->lstOutput->Location = System::Drawing::Point(152, 140);
			this->lstOutput->Name = L"lstOutput";
			this->lstOutput->Size = System::Drawing::Size(120, 95);
			this->lstOutput->TabIndex = 3;
			// 
			// lblInstructions
			// 
			this->lblInstructions->AutoSize = true;
			this->lblInstructions->Location = System::Drawing::Point(75, 39);
			this->lblInstructions->Name = L"lblInstructions";
			this->lblInstructions->Size = System::Drawing::Size(126, 13);
			this->lblInstructions->TabIndex = 4;
			this->lblInstructions->Text = L"Instruções para o usuário";
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Location = System::Drawing::Point(13, 68);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(105, 13);
			this->lblStatus->TabIndex = 5;
			this->lblStatus->Text = L"Mensagem de status";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->lblInstructions);
			this->Controls->Add(this->lstOutput);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnSolve);
			this->Controls->Add(this->txtInput);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
