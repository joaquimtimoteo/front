#include "MyForm.h"

namespace Lb11 {

    MyForm::MyForm(void) {
        InitializeComponent();
    }

    MyForm::~MyForm() {
        if (components) {
            delete components;
        }
    }

    void MyForm::InitializeComponent() {
        // Configuração dos componentes (já existente)
    }

    void MyForm::btnSolve_Click(System::Object^ sender, System::EventArgs^ e) {
        int size = 0;
        int* array = inputArray(txtInput, size);

        if (array == nullptr || size == 0) {
            MessageBox::Show("Array inválido!", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        int newSize = 0;
        int* newArray = task(array, size, newSize); // Chama a função task

        outputArray(newArray, newSize, lstOutput);

        delete[] array;
        if (newArray != nullptr) {
            delete[] newArray;
        }
    }

    int* MyForm::inputArray(TextBox^ textBox, int& size) {
        array<String^>^ lines = textBox->Lines;
        size = lines->Length;

        if (size == 0) {
            lblStatus->Text = "Erro: Array vazio!";
            return nullptr;
        }

        int* array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = Convert::ToInt32(lines[i]);
        }

        return array;
    }

    void MyForm::outputArray(int* array, int size, ListBox^ listBox) {
        listBox->Items->Clear();

        if (size == 0) {
            listBox->Items->Add("O array resultante está vazio.");
            return;
        }

        for (int i = 0; i < size; i++) {
            listBox->Items->Add(array[i].ToString());
        }
    }
}
