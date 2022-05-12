#ifndef _SEED_H
#define _SEED_H

#include <memory>
#include <iostream>
#include <cstring>
#include <openssl/sha.h>
#include <stdio.h>

#define STRING(string) #string

using std::string;

class Seed {

private:
 
    unsigned char digest[SHA_DIGEST_LENGTH];
    const char* cadena;
    std::unique_ptr<string> SEED = nullptr;

public:

    explicit Seed(const char*);
    ~Seed();
    void genSeed();
    string getSeed();
};


#endif // !_SEED_H