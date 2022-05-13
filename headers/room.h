#ifndef _ROOM_H
#define _ROOM_H

#include <memory>
#include <string>
#include "seed.h"


using std::make_unique;
using std::unique_ptr;

class Room {

    private: 
        
        unique_ptr<string> secret= nullptr;
        unique_ptr<string> hash = nullptr;        

    public:

    Room();

        bool prepare();
        bool getRoom();
        void Launch();
};


#endif // !_R00M_H