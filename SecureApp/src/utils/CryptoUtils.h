// utils/CryptoUtils.h
#pragma once

#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

using namespace System;

namespace SecureApp {

    public ref class CryptoUtils
    {
    public:
        static String^ generateRandomBytes(int size);
        static String^ hashPassword(String^ password, String^ salt);
    };
}
