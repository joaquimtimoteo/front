Esse E o meu Botao:Myform.h: #pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "Hello world.";
	}
	};

Myform.cpp: #include "MyForm.h"

using namespace Lab;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}


