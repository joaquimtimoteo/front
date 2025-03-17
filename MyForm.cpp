#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

namespace Lab10 {
    MyForm::MyForm(void) {
        InitializeComponent();
    }

    void MyForm::InitializeComponent() {
        this->label1 = gcnew Label();
        this->label2 = gcnew Label();
        this->label3 = gcnew Label();
        this->txtN = gcnew TextBox();
        this->txtA = gcnew TextBox();
        this->txtB = gcnew TextBox();
        this->btnSolve = gcnew Button();
        this->btnExit = gcnew Button();
        this->lstOriginal = gcnew ListBox();
        this->lstNew = gcnew ListBox();

        // Configuração dos componentes
        this->label1->AutoSize = true;
        this->label1->Location = Point(12, 15);
        this->label1->Text = L"n:";
        
        this->label2->AutoSize = true;
        this->label2->Location = Point(12, 41);
        this->label2->Text = L"a:";
        
        this->label3->AutoSize = true;
        this->label3->Location = Point(12, 67);
        this->label3->Text = L"b:";
        
        this->txtN->Location = Point(34, 12);
        this->txtA->Location = Point(34, 38);
        this->txtB->Location = Point(34, 64);
        
        this->btnSolve->Location = Point(15, 90);
        this->btnSolve->Text = L"Resolver";
        this->btnSolve->Click += gcnew EventHandler(this, &MyForm::btnSolve_Click);
        
        this->btnExit->Location = Point(96, 90);
        this->btnExit->Text = L"Sair";
        this->btnExit->Click += gcnew EventHandler(this, &MyForm::btnExit_Click);
        
        this->lstOriginal->Location = Point(15, 119);
        this->lstOriginal->Size = System::Drawing::Size(120, 173);
        
        this->lstNew->Location = Point(159, 119);
        this->lstNew->Size = System::Drawing::Size(120, 173);

        // Adicionar componentes ao formulário
        this->Controls->Add(this->label1);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->txtN);
        this->Controls->Add(this->txtA);
        this->Controls->Add(this->txtB);
        this->Controls->Add(this->btnSolve);
        this->Controls->Add(this->btnExit);
        this->Controls->Add(this->lstOriginal);
        this->Controls->Add(this->lstNew);
        
        this->Text = L"Laboratório 10 - Variante 24";
        this->ClientSize = System::Drawing::Size(300, 320);
    }

    // Função para validar entrada de dados
    bool MyForm::GetInt(int MaxVal, TextBox^ textBox, String^ errorMessage, int% value) {
        try {
            int num = Convert::ToInt32(textBox->Text);
            if (num < 1 || num > MaxVal) throw gcnew Exception();
            value = num;
            return true;
        } catch (...) {
            MessageBox::Show(errorMessage);
            return false;
        }
    }

    // Função para gerar array aleatório
    void MyForm::input(array<int>^ mas, int n, int a, int b) {
        Random^ rnd = gcnew Random();
        for (int i = 0; i < n; i++) {
            mas[i] = rnd->Next(a, b + 1);
        }
    }

    // Verifica se um número é de dois dígitos (incluindo negativos)
    bool MyForm::isTwoDigit(int num) {
        int absNum = abs(num);
        return absNum >= 10 && absNum <= 99;
    }

    // Calcula a média dos números de dois dígitos
    double MyForm::calculateAverage(array<int>^ mas, int n) {
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (isTwoDigit(mas[i])) {
                sum += mas[i];
                count++;
            }
        }
        return count == 0 ? 0 : static_cast<double>(sum) / count;
    }

    // Cria novo array com elementos > média
    int MyForm::task(array<int>^ mas, int n, double avg, array<int>^% newMas) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (mas[i] > avg) {
                newMas[k++] = mas[i];
            }
        }
        return k;
    }

    // Exibe array em ListBox
    void MyForm::output(array<int>^ mas, int n, ListBox^ listBox) {
        listBox->Items->Clear();
        for (int i = 0; i < n; i++) {
            listBox->Items->Add(mas[i].ToString());
        }
    }

    // Evento do botão "Resolver"
    void MyForm::btnSolve_Click(Object^ sender, EventArgs^ e) {
        int n, a, b;
        if (!GetInt(100, txtN, "Tamanho inválido (1-100)!", n) ||
            !GetInt(1000, txtA, "Intervalo inválido!", a) ||
            !GetInt(1000, txtB, "Intervalo inválido!", b) || a >= b) {
            MessageBox::Show("Dados de entrada inválidos!");
            return;
        }

        array<int>^ original = gcnew array<int>(n);
        input(original, n, a, b);
        output(original, n, lstOriginal);

        double avg = calculateAverage(original, n);
        array<int>^ newMas = gcnew array<int>(n);
        int newSize = task(original, n, avg, newMas);

        if (newSize > 0) {
            output(newMas, newSize, lstNew);
        } else {
            MessageBox::Show("Nenhum elemento maior que a média!");
        }
    }

    // Evento do botão "Sair"
    void MyForm::btnExit_Click(Object^ sender, EventArgs^ e) {
        this->Close();
    }
}

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Lab10::MyForm form;
    Application::Run(%form);
    return 0;
}
