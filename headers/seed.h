#ifndef _SEED_H
#define _SEED_H

#include <memory>
#include <iostream>
#include <cstring>
#include <openssl/sha.h>
#include <stdio.h>
#include <random>

using std::string;

class Seed {

private:
 
    unsigned char digest[SHA_DIGEST_LENGTH];
    const char* cadena{};
    std::unique_ptr<string> SEED = nullptr;

public:

    Seed(string);
    Seed();
    ~Seed();
    void genSeed();
    void setPlain(const char*);
    string getSeed();
    string getSeedX();
    string genRandInit();
    string SHA(string);
};


#endif // !_SEED_H