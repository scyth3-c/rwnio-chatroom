#ifndef MODELS_H
#define MODELS_H

#include "rwnio.h"
#include <iostream>
#include <memory>
#include <string>

#include "room_modules.h"
#include "screen.h"

#define PAUSE std::cin >> MODELS::__key;
#define C std::cout


class MODELS
{

private:
    std::unique_ptr<Modules> modules = nullptr;
    std::unique_ptr<Screen> screen = nullptr;

public:
    static char __key;

    MODELS();
    ~MODELS();

    void startRoom(std::string);
    std::string joinRoom();
    void mainLoop();
    std::string changeName();
};

#endif // !MODELS