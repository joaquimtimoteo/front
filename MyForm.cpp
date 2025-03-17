#include "MyForm.h"

using namespace Lab;
using namespace System;
using namespace System::Windows::Forms;

double MyForm::CalcularSerie(double x)
{
    double soma = 0;
    int n = 10; // Exemplo: 10 termos da série
    for (int i = 1; i <= n; i++)
    {
        soma += Math::Pow(x, i) / i; // Exemplo: soma x^i / i
    }
    return soma;
}

double MyForm::CalcularFuncao(double x)
{
    return Math::Exp(x) - 1; // Exemplo usando exponencial
}

System::Void MyForm::cmdCalc_Click(System::Object^ sender, System::EventArgs^ e)
{
    double x;
    if (!Double::TryParse(txtX->Text, x))
    {
        MessageBox::Show("Por favor, insira um número válido.");
        return;
    }
    
    double resultadoSerie = CalcularSerie(x);
    txtResult->Text = resultadoSerie.ToString("F2");

    double resultadoLib = CalcularFuncao(x);
    txtLib->Text = resultadoLib.ToString("F2");

    double diferenca = Math::Abs(resultadoSerie - resultadoLib);
    lblDiff->Text = "Diferença: " + diferenca.ToString("F2");

    return;
}

System::Void MyForm::cmdExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return;
}

// Função main permanece a mesma
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
}
