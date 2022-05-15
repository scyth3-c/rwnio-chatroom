#ifndef CUSTOM_H
#define CUSTOM_H


#include <string>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include "http.h"
#include "screen.h"
#include "room_modules.h"
#include "rwnio.h"
#include "message.h"

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::vector;

class Custom {

    private:

    shared_ptr<Message> message_t = nullptr; 
    shared_ptr<Screen> screen = nullptr;
    shared_ptr<Modules> modules = nullptr;

    shared_ptr<string> hash = nullptr;
    shared_ptr<string> name = nullptr;

    vector<MSG_t*> messages;

    public:

    Custom(string, string);
    ~Custom();
    
    void loopCustom();
    void charge();
    static void view(Custom*);


};



#endif // ! CUSTOM_H