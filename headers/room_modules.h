#ifndef ROOM_MODULES_H
#define ROOM_MODULES_H

#include <memory>

#include <string>
#include "screen.h"
#include "rwnio.h"
#include "http.h"

using std::make_unique;
using std::unique_ptr;

using std::make_shared;
using std::shared_ptr;

using std::string;

template <class... P>
struct MessageBox
{
    MessageBox(std::initializer_list<P...> list) : messageList(list) {}
    std::vector<P...> messageList;
};

class Modules
{

private:
    shared_ptr<Screen> screen = nullptr;
    unique_ptr<HTTP> http = nullptr;

    unsigned int Xpos = 2;
    unsigned int Ypos = 2;

public:
    Modules();
    ~Modules();

    void verifyNet();
    void verifyDatabase();
    void welcome(string);
    int countMessages(string);

    inline void _sys(const char *cmd) { system(cmd); }
};

#endif // ! ROOM_MODULES_H