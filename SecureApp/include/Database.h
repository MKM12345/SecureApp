// Database.h
#pragma once

#include <iostream>
#include <string>
#include <sqlite3.h>
#include "CryptoUtils.h"

using namespace System;

public ref class Database
{
public:
    Database(String^ dbName);
    ~Database();

    bool createUser(String^ username, String^ password);
    bool authenticateUser(String^ username, String^ password);

private:
    static const int SALT_LENGTH = 32;

    sqlite3* db;
    String^ dbName;

    String^ generateRandomBytes(int size);
    String^ hashPassword(String^ password, String^ salt);

    // Initialization logic
    void initializeDatabase();
};
