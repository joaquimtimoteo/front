#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

namespace Lab10 {
    MyForm::MyForm(void) {
        InitializeComponent();
    }

    void MyForm::InitializeComponent() {
        // Configuração da interface (mesmo código do exemplo anterior)
        // ... (código da interface omitido para brevidade)
    }

    // Implementação das funções
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

    void MyForm::input(array<int>^ mas, int n, int a, int b) {
        Random^ rnd = gcnew Random();
        for (int i = 0; i < n; i++) {
            mas[i] = rnd->Next(a, b + 1);
        }
    }

    bool MyForm::isTwoDigit(int num) {
        int absNum = abs(num);
        return absNum >= 10 && absNum <= 99;
    }

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

    int MyForm::task(array<int>^ mas, int n, double avg, array<int>^% newMas) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (mas[i] > avg) {
                newMas[k++] = mas[i];
            }
        }
        return k;
    }

    void MyForm::output(array<int>^ mas, int n, ListBox^ listBox) {
        listBox->Items->Clear();
        for (int i = 0; i < n; i++) {
            listBox->Items->Add(mas[i].ToString());
        }
    }

    // Eventos dos botões
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
