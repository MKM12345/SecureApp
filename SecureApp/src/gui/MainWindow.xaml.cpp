// gui/MainWindow.xaml.cpp
#include "MainWindow.xaml.h"
#include "Database.h"
#include "CryptoUtils.h"

using namespace System;
using namespace System::Windows;

namespace SecureApp {

    MainWindow::MainWindow()
    {
        InitializeComponent();

        // Hook up event handlers
        btnSignup->Click += gcnew RoutedEventHandler(this, &MainWindow::btnSignup_Click);
        btnLogin->Click += gcnew RoutedEventHandler(this, &MainWindow::btnLogin_Click);
    }

    void MainWindow::btnSignup_Click(Object^ sender, RoutedEventArgs^ e)
    {
        String^ username = txtUsername->Text;
        String^ password = txtPassword->Password;

        Database db("users.db");

        if (db.createUser(username, password))
        {
            MessageBox::Show("User created successfully.");
        }
        else
        {
            MessageBox::Show("Failed to create user.");
        }
    }

    void MainWindow::btnLogin_Click(Object^ sender, RoutedEventArgs^ e)
    {
        String^ username = txtUsername->Text;
        String^ password = txtPassword->Password;

        Database db("users.db");

        if (db.authenticateUser(username, password))
        {
            MessageBox::Show("Authentication successful. Welcome, " + username + "!");
        }
        else
        {
            MessageBox::Show("Invalid username or password. Authentication failed.");
        }
    }
}
