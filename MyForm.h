#pragma once

namespace Lab12Variante24 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing; // Para Point e Size
    #include <cstdlib> // Para rand
    #include <ctime>   // Para time

    public ref class MyForm : public Form {
    public:
        MyForm(void) {
            InitializeComponent();
            components = nullptr;
            srand(static_cast<unsigned int>(time(nullptr))); // Inicializa srand no construtor
        }

    protected:
        ~MyForm() {
            if (components) delete components;
        }

    private:
        System::ComponentModel::Container^ components;
        TextBox^ textM;
        TextBox^ textN;
        TextBox^ textA;
        TextBox^ textB;
        ListBox^ listBox1;
        ListBox^ listBox2;
        Button^ btnTask;
        Button^ btnExit;
        Label^ labelM;
        Label^ labelN;
        Label^ labelA;
        Label^ labelB;
        Label^ labelMatr1;
        Label^ labelMatr2;

        void InitializeComponent(void) {
            this->textM = gcnew TextBox();
            this->textN = gcnew TextBox();
            this->textA = gcnew TextBox();
            this->textB = gcnew TextBox();
            this->listBox1 = gcnew ListBox();
            this->listBox2 = gcnew ListBox();
            this->btnTask = gcnew Button();
            this->btnExit = gcnew Button();
            this->labelM = gcnew Label();
            this->labelN = gcnew Label();
            this->labelA = gcnew Label();
            this->labelB = gcnew Label();
            this->labelMatr1 = gcnew Label();
            this->labelMatr2 = gcnew Label();

            // Configuração dos elementos
            this->textM->Location = System::Drawing::Point(27, 59);
            this->textM->Size = System::Drawing::Size(100, 20);
            this->textN->Location = System::Drawing::Point(27, 97);
            this->textN->Size = System::Drawing::Size(100, 20);
            this->textA->Location = System::Drawing::Point(27, 133);
            this->textA->Size = System::Drawing::Size(100, 20);
            this->textB->Location = System::Drawing::Point(27, 172);
            this->textB->Size = System::Drawing::Size(100, 20);

            this->listBox1->Location = System::Drawing::Point(304, 22);
            this->listBox1->Size = System::Drawing::Size(120, 95);
            this->listBox2->Location = System::Drawing::Point(304, 142);
            this->listBox2->Size = System::Drawing::Size(120, 95);

            this->btnTask->Location = System::Drawing::Point(27, 214);
            this->btnTask->Text = "Решить";
            this->btnExit->Location = System::Drawing::Point(127, 214);
            this->btnExit->Text = "Выход";

            this->labelM->Location = System::Drawing::Point(27, 36);
            this->labelM->Text = "Número de Linhas (m):";
            this->labelN->Location = System::Drawing::Point(27, 74);
            this->labelN->Text = "Número de Colunas (n):";
            this->labelA->Location = System::Drawing::Point(27, 110);
            this->labelA->Text = "Limite Inferior (a):";
            this->labelB->Location = System::Drawing::Point(27, 149);
            this->labelB->Text = "Limite Superior (b):";
            this->labelMatr1->Location = System::Drawing::Point(304, 2);
            this->labelMatr1->Text = "Matriz Original:";
            this->labelMatr2->Location = System::Drawing::Point(304, 122);
            this->labelMatr2->Text = "Matriz Processada:";

            this->btnTask->Click += gcnew EventHandler(this, &MyForm::btnTask_Click);
            this->btnExit->Click += gcnew EventHandler(this, &MyForm::btnExit_Click);

            this->Controls->Add(textM);
            this->Controls->Add(textN);
            this->Controls->Add(textA);
            this->Controls->Add(textB);
            this->Controls->Add(listBox1);
            this->Controls->Add(listBox2);
            this->Controls->Add(btnTask);
            this->Controls->Add(btnExit);
            this->Controls->Add(labelM);
            this->Controls->Add(labelN);
            this->Controls->Add(labelA);
            this->Controls->Add(labelB);
            this->Controls->Add(labelMatr1);
            this->Controls->Add(labelMatr2);

            this->Text = "Lab12 Variante 24";
            this->ClientSize = System::Drawing::Size(450, 280);
        }

        // Função para criar uma matriz dinâmica com números aleatórios
        double** CreateMatrix(int m, int n, double a, double b) {
            double** matrix = new double* [m];
            for (int i = 0; i < m; i++) {
                matrix[i] = new double[n];
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
                }
            }
            return matrix;
        }

        // Função para exibir uma matriz em um ListBox
        void OutputMatrix(double** matrix, int m, int n, ListBox^ listBox) {
            listBox->Items->Clear();
            for (int i = 0; i < m; i++) {
                String^ row = "";
                for (int j = 0; j < n; j++) {
                    row += matrix[i][j].ToString("F2") + "\t"; // Adiciona tabulação
                }
                listBox->Items->Add(row);
            }
        }

        // Função para liberar a memória alocada para a matriz
        void FreeMatrix(double** matrix, int m) {
            for (int i = 0; i < m; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        // Função para encontrar os índices dos elementos máximo e mínimo na matriz
        void FindMinMax(double** matrix, int m, int n, int& i_max, int& j_max, int& i_min, int& j_min) {
            double max_val = matrix[0][0], min_val = matrix[0][0];
            i_max = j_max = i_min = j_min = 0;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] > max_val) {
                        max_val = matrix[i][j];
                        i_max = i;
                        j_max = j;
                    }
                    if (matrix[i][j] < min_val) {
                        min_val = matrix[i][j];
                        i_min = i;
                        j_min = j;
                    }
                }
            }
        }

        // Função para trocar linhas ou colunas conforme especificado
        void SwapRowsOrColumns(double** matrix, int m, int n) {
            int i_max, j_max, i_min, j_min;
            FindMinMax(matrix, m, n, i_max, j_max, i_min, j_min);

            if (i_max != i_min) {
                // Trocar linhas
                double* temp = matrix[i_max];
                matrix[i_max] = matrix[i_min];
                matrix[i_min] = temp;
            } else {
                // Trocar colunas
                for (int i = 0; i < m; i++) {
                    double temp = matrix[i][j_max];
                    matrix[i][j_max] = matrix[i][j_min];
                    matrix[i][j_min] = temp;
                }
            }
        }

        // Evento do botão "Решить"
        void btnTask_Click(Object^ sender, EventArgs^ e) {
            try {
                // Validação de entrada
                if (String::IsNullOrWhiteSpace(textM->Text) || String::IsNullOrWhiteSpace(textN->Text) ||
                    String::IsNullOrWhiteSpace(textA->Text) || String::IsNullOrWhiteSpace(textB->Text)) {
                    MessageBox::Show("Por favor, preencha todos os campos.");
                    return;
                }

                int m = Convert::ToInt32(textM->Text);
                int n = Convert::ToInt32(textN->Text);
                double a = Convert::ToDouble(textA->Text);
                double b = Convert::ToDouble(textB->Text);

                if (m <= 0 || n <= 0) {
                    MessageBox::Show("O número de linhas e colunas deve ser maior que zero.");
                    return;
                }

                if (a >= b) {
                    MessageBox::Show("O limite inferior (a) deve ser menor que o limite superior (b).");
                    return;
                }

                // Chamada das funções
                double** matrix = CreateMatrix(m, n, a, b);
                OutputMatrix(matrix, m, n, listBox1);

                // Processamento
                SwapRowsOrColumns(matrix, m, n);

                // Saída
                OutputMatrix(matrix, m, n, listBox2);

                // Liberação de memória
                FreeMatrix(matrix, m);
            } catch (Exception^ ex) {
                MessageBox::Show("Erro: " + ex->Message);
            }
        }

        // Evento do botão "Выход"
        void btnExit_Click(Object^ sender, EventArgs^ e) {
            this->Close();
        }
    };
}
