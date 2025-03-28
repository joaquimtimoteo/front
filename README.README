#pragma once

#include <cmath>
#include <string>

namespace CalculoPi {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MainForm
    /// </summary>
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::Label^ lblValorX;
    private: System::Windows::Forms::TextBox^ txtValorX;
    private: System::Windows::Forms::Label^ lblEpsilon;
    private: System::Windows::Forms::TextBox^ txtEpsilon;
    private: System::Windows::Forms::Label^ lblNMax;
    private: System::Windows::Forms::TextBox^ txtNMax;
    private: System::Windows::Forms::Button^ btnCalcular;
    private: System::Windows::Forms::Button^ btnSair;
    private: System::Windows::Forms::ListBox^ lstResultados;
    private: System::Windows::Forms::Panel^ panelTop;
    private: System::Windows::Forms::Panel^ panelBottom;
    private: System::Windows::Forms::Panel^ panelMain;

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
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lblValorX = (gcnew System::Windows::Forms::Label());
            this->txtValorX = (gcnew System::Windows::Forms::TextBox());
            this->lblEpsilon = (gcnew System::Windows::Forms::Label());
            this->txtEpsilon = (gcnew System::Windows::Forms::TextBox());
            this->lblNMax = (gcnew System::Windows::Forms::Label());
            this->txtNMax = (gcnew System::Windows::Forms::TextBox());
            this->btnCalcular = (gcnew System::Windows::Forms::Button());
            this->btnSair = (gcnew System::Windows::Forms::Button());
            this->lstResultados = (gcnew System::Windows::Forms::ListBox());
            this->panelTop = (gcnew System::Windows::Forms::Panel());
            this->panelBottom = (gcnew System::Windows::Forms::Panel());
            this->panelMain = (gcnew System::Windows::Forms::Panel());
            this->panelTop->SuspendLayout();
            this->panelBottom->SuspendLayout();
            this->panelMain->SuspendLayout();
            this->SuspendLayout();
            // 
            // lblTitle
            // 
            this->lblTitle->Dock = System::Windows::Forms::DockStyle::Top;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->lblTitle->Location = System::Drawing::Point(0, 0);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(644, 40);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Cálculo de π usando Série de Arctg";
            this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblValorX
            // 
            this->lblValorX->AutoSize = true;
            this->lblValorX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblValorX->Location = System::Drawing::Point(12, 17);
            this->lblValorX->Name = L"lblValorX";
            this->lblValorX->Size = System::Drawing::Size(78, 19);
            this->lblValorX->TabIndex = 1;
            this->lblValorX->Text = L"Valor de x:";
            // 
            // txtValorX
            // 
            this->txtValorX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtValorX->Location = System::Drawing::Point(96, 15);
            this->txtValorX->Name = L"txtValorX";
            this->txtValorX->Size = System::Drawing::Size(100, 25);
            this->txtValorX->TabIndex = 2;
            this->txtValorX->Text = L"10";
            this->txtValorX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // lblEpsilon
            // 
            this->lblEpsilon->AutoSize = true;
            this->lblEpsilon->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblEpsilon->Location = System::Drawing::Point(223, 17);
            this->lblEpsilon->Name = L"lblEpsilon";
            this->lblEpsilon->Size = System::Drawing::Size(84, 19);
            this->lblEpsilon->TabIndex = 3;
            this->lblEpsilon->Text = L"Precisão (ε):";
            // 
            // txtEpsilon
            // 
            this->txtEpsilon->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtEpsilon->Location = System::Drawing::Point(313, 15);
            this->txtEpsilon->Name = L"txtEpsilon";
            this->txtEpsilon->Size = System::Drawing::Size(100, 25);
            this->txtEpsilon->TabIndex = 4;
            this->txtEpsilon->Text = L"0.0001";
            this->txtEpsilon->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // lblNMax
            // 
            this->lblNMax->AutoSize = true;
            this->lblNMax->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblNMax->Location = System::Drawing::Point(435, 17);
            this->lblNMax->Name = L"lblNMax";
            this->lblNMax->Size = System::Drawing::Size(92, 19);
            this->lblNMax->TabIndex = 5;
            this->lblNMax->Text = L"Iter. Máximas:";
            // 
            // txtNMax
            // 
            this->txtNMax->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtNMax->Location = System::Drawing::Point(533, 15);
            this->txtNMax->Name = L"txtNMax";
            this->txtNMax->Size = System::Drawing::Size(100, 25);
            this->txtNMax->TabIndex = 6;
            this->txtNMax->Text = L"100";
            this->txtNMax->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // btnCalcular
            // 
            this->btnCalcular->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->btnCalcular->FlatAppearance->BorderSize = 0;
            this->btnCalcular->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCalcular->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnCalcular->ForeColor = System::Drawing::Color::White;
            this->btnCalcular->Location = System::Drawing::Point(216, 10);
            this->btnCalcular->Name = L"btnCalcular";
            this->btnCalcular->Size = System::Drawing::Size(120, 35);
            this->btnCalcular->TabIndex = 7;
            this->btnCalcular->Text = L"Calcular";
            this->btnCalcular->UseVisualStyleBackColor = false;
            this->btnCalcular->Click += gcnew System::EventHandler(this, &MainForm::btnCalcular_Click);
            // 
            // btnSair
            // 
            this->btnSair->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnSair->FlatAppearance->BorderSize = 0;
            this->btnSair->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSair->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnSair->ForeColor = System::Drawing::Color::White;
            this->btnSair->Location = System::Drawing::Point(342, 10);
            this->btnSair->Name = L"btnSair";
            this->btnSair->Size = System::Drawing::Size(120, 35);
            this->btnSair->TabIndex = 8;
            this->btnSair->Text = L"Sair";
            this->btnSair->UseVisualStyleBackColor = false;
            this->btnSair->Click += gcnew System::EventHandler(this, &MainForm::btnSair_Click);
            // 
            // lstResultados
            // 
            this->lstResultados->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lstResultados->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lstResultados->FormattingEnabled = true;
            this->lstResultados->ItemHeight = 15;
            this->lstResultados->Location = System::Drawing::Point(10, 10);
            this->lstResultados->Name = L"lstResultados";
            this->lstResultados->Size = System::Drawing::Size(624, 294);
            this->lstResultados->TabIndex = 9;
            // 
            // panelTop
            // 
            this->panelTop->BackColor = System::Drawing::Color::WhiteSmoke;
            this->panelTop->Controls->Add(this->lblValorX);
            this->panelTop->Controls->Add(this->txtValorX);
            this->panelTop->Controls->Add(this->lblEpsilon);
            this->panelTop->Controls->Add(this->txtEpsilon);
            this->panelTop->Controls->Add(this->lblNMax);
            this->panelTop->Controls->Add(this->txtNMax);
            this->panelTop->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelTop->Location = System::Drawing::Point(0, 40);
            this->panelTop->Name = L"panelTop";
            this->panelTop->Size = System::Drawing::Size(644, 55);
            this->panelTop->TabIndex = 10;
            // 
            // panelBottom
            // 
            this->panelBottom->BackColor = System::Drawing::Color::WhiteSmoke;
            this->panelBottom->Controls->Add(this->btnCalcular);
            this->panelBottom->Controls->Add(this->btnSair);
            this->panelBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->panelBottom->Location = System::Drawing::Point(0, 399);
            this->panelBottom->Name = L"panelBottom";
            this->panelBottom->Size = System::Drawing::Size(644, 55);
            this->panelBottom->TabIndex = 11;
            // 
            // panelMain
            // 
            this->panelMain->Controls->Add(this->lstResultados);
            this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panelMain->Location = System::Drawing::Point(0, 95);
            this->panelMain->Name = L"panelMain";
            this->panelMain->Padding = System::Windows::Forms::Padding(10);
            this->panelMain->Size = System::Drawing::Size(644, 304);
            this->panelMain->TabIndex = 12;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(644, 454);
            this->Controls->Add(this->panelMain);
            this->Controls->Add(this->panelTop);
            this->Controls->Add(this->panelBottom);
            this->Controls->Add(this->lblTitle);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Cálculo de π - Variante 24";
            this->panelTop->ResumeLayout(false);
            this->panelTop->PerformLayout();
            this->panelBottom->ResumeLayout(false);
            this->panelMain->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void btnCalcular_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Limpar o ListBox
            lstResultados->Items->Clear();
            
            // Obter os valores dos controles
            double x = Convert::ToDouble(txtValorX->Text);
