#include "room_modules.h"


Modules::Modules() {
        screen = make_shared<Screen>();
}

Modules::~Modules() {
    screen.reset();
}

void Modules::verifyNet() {
    http = make_unique<HTTP>(TEST_DOMAIN);
    screen->write("conectando...", Xpos, Ypos++);

    http->get();
    string res = http->Response();
    http.reset(); 
    if(res.length() < 1) {
        screen->write("error al conectar con internet!", Xpos, Ypos+1);
        exit(EXIT_FAILURE);
    }
}

void Modules::verifyDatabase() {

    http = make_unique<HTTP>(RWNIO_HTTP_URL);
    screen->write("verificando la base de datos...", Xpos, Ypos++);
   
   http->post("last");
   string res = http->Response();
   http.reset();
   if(res.length() < 1) {
       screen->write("error al conectar con la base de datos", Xpos, Ypos+1);
       exit(EXIT_FAILURE);
   }
}

void Modules::welcome(string _name) {

    _sys(RWNIO_SYS_CLEAR);
    screen->write("BIENVENIDO " + std::move(_name), Xpos, Ypos);
    screen->_wait(400);
    _sys(RWNIO_SYS_CLEAR);

}

int Modules::countMessages(string _secreto) {
    http = make_unique<HTTP>(RWNIO_HTTP_URL);
    http->post("count", "secreto="+_secreto);
    int count  =  std::stoi(http->Response());
    http.reset();
    return count;
}