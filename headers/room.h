#ifndef _ROOM_H
#define _ROOM_H

#include <memory>
#include <string>
#include "seed.h"
#include "namecon.h"
#include "rwnio.h"
#include "room_modules.h"
#include "message.h"
#include "custom.h"
#include "models.h"

#include <iostream>
#include <vector>

#define READKEY std::cin >> Room::KEY;
#define GETKEY Room::KEY

using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::string;
using std::unique_ptr;

template <class... LIST>
struct PARAMS
{

    std::vector<LIST...> list;
    PARAMS(std::initializer_list<LIST...> arguments) : list(arguments) {}

    string http_params{};
    string transform()
    {
        uint8_t it = 0;

        for (size_t i = 0; i < list.size(); i++)
        {
            it++;
            if (it == 2)
            {
                http_params += list[i];
                it = 0;
            }
            else if (it != 2 && i != 0)
            {
                http_params += "&" + list[i];
            }
            else
            {
                http_params += list[i];
            }
        }
        return http_params;
    }
};

class Room
{

private:
    unique_ptr<Seed> access = nullptr;
    unique_ptr<Name> name = nullptr;
    shared_ptr<string> hash = nullptr;

    unique_ptr<HTTP> http = nullptr;
    shared_ptr<Screen> screen = nullptr;
    unique_ptr<Modules> modules = nullptr;
    shared_ptr<Message> message = nullptr;
    shared_ptr<Custom> custom = nullptr;

    unique_ptr<MODELS> models = nullptr;


public:
    static char KEY;

    explicit Room(int, char **);
    ~Room();

    void MainLoop();
    void startRoom();
    void joinRoom();

    void prepare(string, string);
    void prepare(string);
    void prepare();
    void setupMessage(string);
    void welcomeRoom(string);
};

#endif // !_R00M_H