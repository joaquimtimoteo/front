#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Criar e rodar o formulário
    ProjectName::MyForm form; 
    Application::Run(%form);
    
    return 0;
}
