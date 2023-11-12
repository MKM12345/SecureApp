// Database.cpp
#include "Database.h"

Database::Database(String^ dbName)
{
    this->dbName = dbName;

    // Open or create the SQLite database
    int result = sqlite3_open(dbName->ToString(), &db);

    if (result != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        // Handle the error as needed
    }

    // Initialize the database
    initializeDatabase();
}

Database::~Database()
{
    sqlite3_close(db);
}

void Database::initializeDatabase()
{
    // Create the 'users' table if it doesn't exist
    const char* createTableQuery =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT NOT NULL UNIQUE,"
        "password TEXT NOT NULL,"
        "salt TEXT NOT NULL"
        ");";

    int result = sqlite3_exec(db, createTableQuery, nullptr, nullptr, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "Error creating 'users' table: " << sqlite3_errmsg(db) << std::endl;
        // Handle the error as needed
    }
}

bool Database::createUser(String^ username, String^ password)
{
    String^ salt = generateRandomBytes(SALT_LENGTH);
    String^ hashedPassword = hashPassword(password, salt);

    String^ query = "INSERT INTO users (username, password, salt) VALUES ('" + username + "', '" + hashedPassword + "', '" + salt + "');";

    int result = sqlite3_exec(db, query->ToString(), nullptr, nullptr, nullptr);

    return result == SQLITE_OK;
}

bool Database::authenticateUser(String^ username, String^ password)
{
    String^ query = "SELECT password, salt FROM users WHERE username = ?;";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query->ToString(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, username->ToString(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            String^ storedPassword = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            String^ salt = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));

            String^ inputHashedPassword = hashPassword(password, salt);

            sqlite3_finalize(stmt);

            return (inputHashedPassword == storedPassword);
        }
        else
        {
            sqlite3_finalize(stmt);
            return false;
        }
    }
    else
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
}

String^ Database::generateRandomBytes(int size)
{
    // Cryptographic logic for generating random bytes using CryptoUtils
    return CryptoUtils::generateRandomBytes(size);
}

String^ Database::hashPassword(String^ password, String^ salt)
{
    // Cryptographic logic for hashing password using CryptoUtils
    return CryptoUtils::hashPassword(password, salt);
}
