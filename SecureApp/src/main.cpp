// main.cpp
#include "gui/MainWindow.xaml.h"

using namespace System;
using namespace System::Windows;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    Application^ app = gcnew Application();
    SecureApp::MainWindow^ mainWindow = gcnew SecureApp::MainWindow();
    app->Run(mainWindow);

    return 0;
}
