#ifndef CUSTOM_H
#define CUSTOM_H


#include <memory>
#include <thread>
#include <chrono>
#include <iomanip>

#include <string>
#include <vector>
#include <iostream>
#include <sstream>


#include "http.h"
#include "screen.h"
#include "room_modules.h"
#include "rwnio.h"
#include "message.h"

#if !defined(_WIN32) || !defined(_WIN64)
#include <termio.h>
#include <unistd.h>
#endif


// static define members
#define _MSG std::cin >> Custom::_msg;
#define _MSG_t Custom::_msg
#define _MSG_UP string Custom::_msg = "tasty!";

#define CLOCK Custom::_clock
#define CLOCK_UP unsigned int Custom::_clock = 2;
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
    char reader{};

public:
    Custom(string, string);
    ~Custom();

    void loopCustom();
    void charge();

    static void viewLoop(Custom *);
    void sendLoop();
    void send(string msg);
    void model(string, string, string);

    #if !defined(_WIN64) || !defined(_WIN32)

    int getch();

    #endif

};

#endif // ! CUSTOM_H