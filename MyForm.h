#pragma once

#include <Windows.h>
#include <msclr/marshal_cppstd.h> // Para conversão de strings
#include "task_din.h" // Inclui o cabeçalho personalizado com as funções do projeto

namespace MyNamespace {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form {
    public:
        MyForm(void);

    protected:
        ~MyForm();

    private:
        // Componentes da interface gráfica
        TextBox^ txtInput; // Campo de texto para entrada de dados
        Button^ btnSolve;  // Botão para resolver a tarefa
        ListBox^ lstOutput; // Lista para exibir resultados
        Label^ lblInstructions; // Rótulo para instruções

        // Funções de manipulação da interface
        void InitializeComponent();
        void btnSolve_Click(System::Object^ sender, System::EventArgs^ e); // Evento do botão

        // Funções auxiliares
        int* inputArray(TextBox^ textBox, int& size); // Função para ler o array
        void outputArray(int* array, int size, ListBox^ listBox); // Função para exibir o array
    };
}
