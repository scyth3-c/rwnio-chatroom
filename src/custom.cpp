#include "custom.h"


Custom::Custom(string _name, string _hash)
{

    hash = make_shared<string>(_hash);
    name = make_shared<string>(_name);
    screen = make_shared<Screen>();
    modules = make_shared<Modules>();
   
  
} 
Custom::~Custom() {
    hash.reset();
    screen.reset();
    modules.reset();
    messages.~vector();
    message_t.reset();

}

void Custom::charge() {
  message_t = make_shared<Message>(*name, "this is secret");
  message_t->setUrl(RWNIO_HTTP_URL);
  MSG_t *_temp = new MSG_t(message_t->last()); 
  messages.push_back(std::move(_temp));
  message_t.reset();
}


void Custom::view(Custom *obj) {
     obj->charge();
     std::this_thread::sleep_for (std::chrono::milliseconds(1000));
     for (auto &it : obj->messages)
     {
        rwnio::screen(C, it->hora, " [",it->creador,"]: ", it->contenido ,N,N);
     }
}


void Custom::loopCustom() {
 
 modules->_sys(RWNIO_SYS_CLEAR);
 std::thread hilo(view, this);
 string msg="";

 while (1)
 {  
   
 }

}