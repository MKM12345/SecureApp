// include/gui/MainWindow.xaml.h
#pragma once

#include <Windows.h>

namespace SecureApp {

    public ref class MainWindow : public Window
    {
    public:
        MainWindow();

    private:
        void btnSignup_Click(Object^ sender, RoutedEventArgs^ e);
        void btnLogin_Click(Object^ sender, RoutedEventArgs^ e);
    };
}

