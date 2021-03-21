#include "Application.h"

int main()
{
	Effort::Application::Create();
	return static_cast<int>(Effort::GetApplication().Run());
}