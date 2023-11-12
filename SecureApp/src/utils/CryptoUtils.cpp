// utils/CryptoUtils.cpp
#include "CryptoUtils.h"

using namespace System;

namespace SecureApp {

    String^ CryptoUtils::generateRandomBytes(int size)
    {
        array<unsigned char>^ buffer = gcnew array<unsigned char>(size);
        RAND_bytes(buffer, size);

        String^ result = BitConverter::ToString(buffer);
        result = result->Replace("-", "");
        return result;
    }

    String^ CryptoUtils::hashPassword(String^ password, String^ salt)
    {
        String^ input = password + salt;
        array<unsigned char>^ hashed = gcnew array<unsigned char>(SHA256_DIGEST_LENGTH);

        pin_ptr<const wchar_t> wch = PtrToStringChars(input);
        pin_ptr<unsigned char> hash = &hashed[0];

        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, wch, input->Length);
        SHA256_Final(hash, &sha256);

        return BitConverter::ToString(hashed);
    }
}
