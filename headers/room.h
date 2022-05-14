#ifndef _ROOM_H
#define _ROOM_H

#include <memory>
#include <string>
#include "seed.h"
#include "namecon.h"
#include "http.h"

#include <iostream>


using std::make_unique;
using std::unique_ptr;
using std::string;

class Room {

    private: 

        unique_ptr<Seed> access = nullptr; 
        unique_ptr<Name> name = nullptr;
        unique_ptr<string> hash = nullptr;   
               

    public:

    explicit Room(int, char**);
            ~Room();

        bool MainLoop();
        bool getRoom();

        void prepare(string, string);
        void prepare(string);
        void prepare();
        
        void Launch();

};


#endif // !_R00M_H