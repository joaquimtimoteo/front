#include "MyForm.h"

namespace MyNamespace {

    // Construtor da classe MyForm
    MyForm::MyForm(void) {
        InitializeComponent();
    }

    // Destrutor da classe MyForm
    MyForm::~MyForm() {
        if (components) {
            delete components;
        }
    }

    // Método para inicializar os componentes da interface
    void MyForm::InitializeComponent() {
        this->txtInput = gcnew TextBox();
        this->btnSolve = gcnew Button();
        this->lstOutput = gcnew ListBox();
        this->lblInstructions = gcnew Label();

        // Configuração do campo de texto
        this->txtInput->Location = System::Drawing::Point(10, 30);
        this->txtInput->Multiline = true;
        this->txtInput->Size = System::Drawing::Size(200, 100);
        this->txtInput->ScrollBars = ScrollBars::Vertical;

        // Configuração do botão
        this->btnSolve->Location = System::Drawing::Point(10, 140);
        this->btnSolve->Text = "Resolver Tarefa";
        this->btnSolve->Click += gcnew EventHandler(this, &MyForm::btnSolve_Click);

        // Configuração da lista de saída
        this->lstOutput->Location = System::Drawing::Point(220, 30);
        this->lstOutput->Size = System::Drawing::Size(200, 100);

        // Configuração do rótulo de instruções
        this->lblInstructions->Location = System::Drawing::Point(10, 10);
        this->lblInstructions->Text = "Insira os números do array (um por linha):";

        // Adiciona os componentes ao formulário
        this->Controls->Add(this->txtInput);
        this->Controls->Add(this->btnSolve);
        this->Controls->Add(this->lstOutput);
        this->Controls->Add(this->lblInstructions);

        // Configuração do formulário
        this->Text = "Trabalho de Laboratório nº 11";
        this->Size = System::Drawing::Size(450, 250);
    }

    // Evento do botão "Resolver Tarefa"
    void MyForm::btnSolve_Click(System::Object^ sender, System::EventArgs^ e) {
        int size = 0;
        int* array = inputArray(txtInput, size); // Lê o array do campo de texto

        if (array == nullptr || size == 0) {
            MessageBox::Show("Por favor, insira um array válido.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Chama a função principal para resolver a tarefa
        int newSize = 0;
        int* newArray = task(array, size, newSize); // Função definida em task_din.cpp

        // Exibe o novo array na lista
        outputArray(newArray, newSize, lstOutput);

        // Libera a memória alocada
        delete[] array;
        if (newArray != nullptr) {
            delete[] newArray;
        }
    }

    // Função para ler o array do campo de texto
    int* MyForm::inputArray(TextBox^ textBox, int& size) {
        array<String^>^ lines = textBox->Lines;
        size = lines->Length;

        if (size == 0) {
            return nullptr;
        }

        int* array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = Convert::ToInt32(lines[i]);
        }

        return array;
    }

    // Função para exibir o array na lista
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
