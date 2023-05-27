#include "MyForm.h"

using namespace Project8;
[STAThreadAttribute]
void main(cli::array<System::String^>^ args)
{
	Application::Run(gcnew MyForm());
}
