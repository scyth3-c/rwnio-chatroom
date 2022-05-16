#include "seed.h"
Seed::Seed() : cadena("default") {}
Seed::Seed(string temp) : cadena(temp.c_str()) {}
Seed::~Seed()
{
    SEED.reset();
}

void Seed::genSeed()
{
    SHA256((unsigned char *)&cadena, strlen(cadena), (unsigned char *)&digest);
    char mdstring[SHA_DIGEST_LENGTH * 2 + 1];
    for (size_t i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        sprintf(&mdstring[i * 2], "%02x", (unsigned int)digest[i]);
    }
    SEED = std::make_unique<string>(mdstring);
}

string Seed::SHA(string plain)
{

    SHA1((unsigned char *)&plain, strlen(plain.c_str()), (unsigned char *)&digest);
    char mdstring[SHA_DIGEST_LENGTH * 2 + 1];
    for (size_t i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        sprintf(&mdstring[i * 2], "%02x", (unsigned int)digest[i]);
    }
    return (string)mdstring;
}

string Seed::getSeed()
{
    string temp = std::move(*SEED);
    SEED.reset();
    return temp;
}

void Seed::setPlain(const char *temp) { cadena = std::move(temp); }

string Seed::genRandInit()
{
    std::random_device RD;
    std::mt19937_64 MT(RD());
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    float container{};
    for (size_t i = 0; i < 16; i++)
    {
        container += dist(MT);
    }
    return std::to_string(container);
}