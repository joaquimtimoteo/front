#include "MyForm.h"

Лабораторная работа №9.2


using namespace Lab;
using namespace System;
using namespace System::Windows::Forms;

// Função que calcula ln(1+x) usando a expansão em série
double MyForm::CalcularSerie(double x)
{
    double soma = 0;
    int i = 1;
    double termo = 0;
    // Calcula os termos até que o valor absoluto do termo seja menor que 0.0001
    do {
        // Calcula o termo: x^i / i
        termo = Math::Pow(x, i) / i;
        // Alterna o sinal: positivo para i ímpar, negativo para i par
        if (i % 2 == 0)
            termo = -termo;
        soma += termo;
        i++;
    } while (Math::Abs(termo) >= 0.0001);
    return soma;
}

// Função que utiliza a função da biblioteca para calcular ln(1+x)
double MyForm::CalcularFuncao(double x)
{
    return Math::Log(1 + x);
}

// Evento do botão "Calcular"
System::Void MyForm::cmdCalc_Click(System::Object^ sender, System::EventArgs^ e)
{
    double x;
    if (!Double::TryParse(txtX->Text, x))
    {
        MessageBox::Show("Por favor, insira um número válido.");
        return;
    }
    
    double resultadoSerie = CalcularSerie(x);
    txtResult->Text = resultadoSerie.ToString("F4"); // Formata com 4 casas decimais

    double resultadoLib = CalcularFuncao(x);
    txtLib->Text = resultadoLib.ToString("F4");

    double diferenca = Math::Abs(resultadoSerie - resultadoLib);
    lblDiff->Text = "Diferença: " + diferenca.ToString("F4");

    return;
}

// Evento do botão "Sair"
System::Void MyForm::cmdExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return;
}

// Função main permanece inalterada
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
}

--------




    #include "MyForm.h"
using namespace Lab;
using namespace System;
using namespace System::Windows::Forms;

// Cálculo da série alternada para ln(1+x)
double MyForm::CalcularSerie(double x) {
    double soma = 0;
    int i = 1;
    double termo;
    do {
        termo = Math::Pow(x, i) / i;
        if (i % 2 == 0) termo *= -1; // Alterna o sinal
        soma += termo;
        i++;
    } while (Math::Abs(termo) >= 0.0001); // Critério de parada
    return soma;
}

// Cálculo usando a função da biblioteca
double MyForm::CalcularFuncao(double x) {
    return Math::Log(1 + x);
}

// Evento do botão "Calcular"
Void MyForm::cmdCalc_Click(Object^ sender, EventArgs^ e) {
    double x;
    if (!Double::TryParse(txtX->Text, x) || x <= -1 || x > 1) {
        MessageBox::Show("Insira um número entre (-1, 1].");
        return;
    }

    double serie = CalcularSerie(x);
    double biblioteca = CalcularFuncao(x);
    double diferenca = Math::Abs(serie - biblioteca);

    txtResult->Text = serie.ToString("F4");
    txtLib->Text = biblioteca.ToString("F4");
    lblDiff->Text = "Diferença: " + diferenca.ToString("F4");
}

// Evento do botão "Sair"
Void MyForm::cmdExit_Click(Object^ sender, EventArgs^ e) {
    this->Close();
}

// Função Main
int main() {
    Application::EnableVisualStyles();
    Application::Run(gcnew MyForm());
    return 0;
}
