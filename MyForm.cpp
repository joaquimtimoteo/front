#include "MyForm.h"

namespace Lb11 {

    // Construtor e inicialização da interface
    MyForm::MyForm(void) {
        InitializeComponent();
    }

    MyForm::~MyForm() {
        if (components) {
            delete components;
        }
    }

    void MyForm::InitializeComponent() {
        this->txtInput = gcnew TextBox();
        this->btnSolve = gcnew Button();
        this->lstOutput = gcnew ListBox();
        this->lblInstructions = gcnew Label();
        this->lblStatus = gcnew Label();

        // Configuração do txtInput
        this->txtInput->Location = Point(75, 86);
        this->txtInput->Multiline = true;
        this->txtInput->ScrollBars = ScrollBars::Vertical;
        this->txtInput->Size = System::Drawing::Size(100, 100);

        // Configuração do btnSolve
        this->btnSolve->Location = Point(46, 180);
        this->btnSolve->Text = "Resolver Tarefa";
        this->btnSolve->Click += gcnew EventHandler(this, &MyForm::btnSolve_Click);

        // Configuração do lstOutput
        this->lstOutput->Location = Point(200, 86);
        this->lstOutput->Size = System::Drawing::Size(120, 100);

        // Configuração do lblInstructions
        this->lblInstructions->Location = Point(75, 39);
        this->lblInstructions->Text = "Insira os números do array (um por linha):";

        // Adiciona componentes ao formulário
        this->Controls->Add(txtInput);
        this->Controls->Add(btnSolve);
        this->Controls->Add(lstOutput);
        this->Controls->Add(lblInstructions);
        this->Text = "Tarefa 24";
        this->Size = System::Drawing::Size(400, 300);
    }

    // Função para ler o array do TextBox
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

    // Função para exibir o array no ListBox
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

    // Função para verificar se um número é de dois dígitos
    bool MyForm::isTwoDigit(int num) {
        return (num >= 10 && num <= 99);
    }

    // Função para calcular a média dos números de dois dígitos
    double MyForm::calculateAverage(int* array, int size, int& count) {
        double sum = 0.0;
        count = 0;

        for (int i = 0; i < size; i++) {
            if (isTwoDigit(array[i])) {
                sum += array[i];
                count++;
            }
        }

        return (count > 0) ? sum / count : 0.0;
    }

    // Função principal da Tarefa 24
    int* MyForm::task(int* array, int size, int& newSize) {
        newSize = 0;

        // Passo 1: Calcular a média dos números de dois dígitos
        int twoDigitCount = 0;
        double average = calculateAverage(array, size, twoDigitCount);

        if (twoDigitCount == 0) {
            return nullptr; // Nenhum número de dois dígitos encontrado
        }

        // Passo 2: Filtrar elementos maiores que a média
        std::vector<int> tempResult;
        for (int i = 0; i < size; i++) {
            if (array[i] > average) {
                tempResult.push_back(array[i]);
            }
        }

        // Passo 3: Converter o vetor para um array dinâmico
        newSize = tempResult.size();
        if (newSize == 0) {
            return nullptr;
        }

        int* result = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            result[i] = tempResult[i];
        }

        return result;
    }

    // Manipulador de eventos do botão "Resolver Tarefa"
    void MyForm::btnSolve_Click(System::Object^ sender, System::EventArgs^ e) {
        int size = 0;
        int* array = inputArray(txtInput, size);

        if (array == nullptr || size == 0) {
            MessageBox::Show("Por favor, insira um array válido.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        int newSize = 0;
        int* newArray = task(array, size, newSize);

        outputArray(newArray, newSize, lstOutput);

        // Liberar memória
        delete[] array;
        if (newArray != nullptr) {
            delete[] newArray;
        }
    }
}
