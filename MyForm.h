#pragma once

namespace Lab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// TODO: Adicione o código do construtor aqui
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Button^ button1;  // Pode ser removido se não for necessário
		System::Windows::Forms::TextBox^ textBox1;   // Pode ser removido se não for utilizado
		System::Windows::Forms::Label^ label1;       // Pode ser removido se não for utilizado

		System::Windows::Forms::TextBox^ txtX;
		System::Windows::Forms::Button^ cmdCalc;
		System::Windows::Forms::Button^ cmdExit;
		System::Windows::Forms::TextBox^ txtResult;
		System::Windows::Forms::TextBox^ txtLib;
		System::Windows::Forms::Label^ lblDiff;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
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
			// button1 (opcional: exemplo "Hello world")
			// 
			this->button1->Location = System::Drawing::Point(275, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1 (opcional)
			// 
			this->textBox1->Location = System::Drawing::Point(275, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1 (opcional)
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
			this->txtX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// cmdCalc
			// 
			this->cmdCalc->Location = System::Drawing::Point(168, 203);
			this->cmdCalc->Name = L"cmdCalc";
			this->cmdCalc->Size = System::Drawing::Size(75, 23);
			this->cmdCalc->TabIndex = 4;
			this->cmdCalc->Text = L"Calcular";
			this->cmdCalc->UseVisualStyleBackColor = true;
			this->cmdCalc->Click += gcnew System::EventHandler(this, &MyForm::cmdCalc_Click);
			// 
			// cmdExit
			// 
			this->cmdExit->Location = System::Drawing::Point(275, 166);
			this->cmdExit->Name = L"cmdExit";
			this->cmdExit->Size = System::Drawing::Size(75, 23);
			this->cmdExit->TabIndex = 5;
			this->cmdExit->Text = L"Sair";
			this->cmdExit->UseVisualStyleBackColor = true;
			this->cmdExit->Click += gcnew System::EventHandler(this, &MyForm::cmdExit_Click);
			// 
			// txtResult
			// 
			this->txtResult->Location = System::Drawing::Point(275, 219);
			this->txtResult->Name = L"txtResult";
			this->txtResult->Size = System::Drawing::Size(100, 20);
			this->txtResult->TabIndex = 6;
			this->txtResult->Enabled = false;
			// 
			// txtLib
			// 
			this->txtLib->Location = System::Drawing::Point(77, 140);
			this->txtLib->Name = L"txtLib";
			this->txtLib->Size = System::Drawing::Size(100, 20);
			this->txtLib->TabIndex = 7;
			this->txtLib->Enabled = false;
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
			this->Text = L"Calculadora de Série";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// Eventos
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "Hello world.";
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Evento do label (opcional)
	}

	// Declaração dos novos eventos
	private: System::Void cmdCalc_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cmdExit_Click(System::Object^ sender, System::EventArgs^ e);

	// Declaração dos métodos de cálculo
	private: double CalcularSerie(double x);
	private: double CalcularFuncao(double x);
	};
}
