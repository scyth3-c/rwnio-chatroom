#ifndef _ROOM_H
#define _ROOM_H

#include <memory>
#include <string>
#include "rwnio.h"
#include "seed.h"
#include "namecon.h"
#include "http.h"

#include <iostream>
#include <vector>


using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;
using std::string;



template<class...LIST> 
struct PARAMS {

    std::vector<LIST...> list;    
    PARAMS(std::initializer_list<LIST...> arguments) : list(arguments) {}

    string http_params{};
    string transform() {
    uint8_t it = 0;

        for (size_t i = 0; i<list.size(); i++)
        {  
            it++;
            if(it == 2) { 
                http_params += list[i]; 
                it=0;
            }
            else if( it != 2 && i != 0){
                http_params += "&"+list[i];
            } else {
                http_params += list[i];
            }
        }
        return http_params;
    }
};


class Room {

    private: 

        unique_ptr<Seed> access = nullptr; 
        unique_ptr<Name> name = nullptr;
        shared_ptr<string> hash = nullptr;
        shared_ptr<string> message_secret = nullptr;   
               
        unique_ptr<HTTP> http = nullptr;

    public:

    explicit Room(int, char**);
            ~Room();

        bool MainLoop();
        bool getRoom();

        void prepare(string, string);
        void prepare(string);
        void prepare();

        string Launch();
        string getMeSecret();

};



#endif // !_R00M_H