#pragma once

#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include "task_din.h" // Inclui o cabeçalho personalizado

namespace Lb11 {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form {
    public:
        MyForm(void);

    protected:
        ~MyForm();

    private:
        // Componentes da interface
        TextBox^ txtInput;
        Button^ btnSolve;
        ListBox^ lstOutput;
        Label^ lblInstructions;
        Label^ lblStatus;

        // Funções de manipulação da interface
        void InitializeComponent();
        void btnSolve_Click(System::Object^ sender, System::EventArgs^ e);

        // Funções auxiliares
        int* inputArray(TextBox^ textBox, int& size);
        void outputArray(int* array, int size, ListBox^ listBox);
    };
}
