#ifndef CUSTOM_H
#define CUSTOM_H

#include <string>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "http.h"
#include "screen.h"
#include "room_modules.h"
#include "rwnio.h"
#include "message.h"

// static define members
#define _MSG std::cin >> Custom::_msg;
#define _MSG_t Custom::_msg
#define _MSG_UP string Custom::_msg = "";

#define CLOCK Custom::_clock
#define CLOCK_UP unsigned int Custom::_clock = 4;
// end

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

using std::thread;

class Custom
{

private:
    shared_ptr<Message> message_view = nullptr;
    shared_ptr<Message> message_send = nullptr;

    shared_ptr<Screen> screen = nullptr;
    shared_ptr<Modules> modules = nullptr;

    shared_ptr<string> hash = nullptr;
    shared_ptr<string> name = nullptr;

    vector<MSG_t *> messages;

    static string _msg;
    static unsigned int _clock;

public:
    Custom(string, string);
    ~Custom();

    void loopCustom();
    void charge();

    static void viewLoop(Custom *);
    void sendLoop();
    void send(string msg);
    void model(string, string, string);
};

#endif // ! CUSTOM_H