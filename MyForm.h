#pragma once

#include <windows.h>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

namespace Lab10 {
    public ref class MyForm : public Form {
    public:
        MyForm(void);

    private:
        Label^ label1;
        Label^ label2;
        Label^ label3;
        TextBox^ txtN;
        TextBox^ txtA;
        TextBox^ txtB;
        Button^ btnSolve;
        Button^ btnExit;
        ListBox^ lstOriginal;
        ListBox^ lstNew;

        void InitializeComponent();
        void btnSolve_Click(Object^ sender, EventArgs^ e);
        void btnExit_Click(Object^ sender, EventArgs^ e);

        // Funções da tarefa
        static bool GetInt(int MaxVal, TextBox^ textBox, String^ errorMessage, int% value);
        static void input(array<int>^ mas, int n, int a, int b);
        static bool isTwoDigit(int num);
        static double calculateAverage(array<int>^ mas, int n);
        static int task(array<int>^ mas, int n, double avg, array<int>^% newMas);
        static void output(array<int>^ mas, int n, ListBox^ listBox);
    };
}
