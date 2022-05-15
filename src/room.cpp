#include "room.h"

Room::Room(int argc, char *argv[]) {

    modules = make_unique<Modules>();
    modules->_sys(RWNIO_SYS_CLEAR);
    modules->verifyNet();
    modules->verifyDatabase();
    modules.reset();

    switch (argc)
    {
    case 3:
         prepare(std::move(argv[1]),std::move(argv[2]));
        break;
    case 2:
        prepare(std::move(argv[1]));
    default:
        prepare();
        break;
    }
}



Room::~Room() {
    access.reset();
    name.reset();
    hash.reset();
}


void Room::prepare(string _name, string _secret) {
 name = make_unique<Name>(_name);

 if(name->verify()) {
     name->setName(_name);
 }
 access = make_unique<Seed>((string)(_secret + name->getName() + access->genRandInit()));
 access->genSeed();
 hash = make_shared<string>(access->getSeed());
}


//sobrecarga de PREAPRE
void Room::prepare(string _secret) {
    name = make_unique<Name>();
    access = make_unique<Seed>((string)(_secret+name->getName() + access->genRandInit()));
    access->genSeed(); 
    hash = make_shared<string>(access->getSeed());
}


void Room::prepare() {
    name = make_unique<Name>();
     access = make_unique<Seed>((string)("public"+name->getName() + access->genRandInit()));
     access->genSeed();
     hash = make_shared<string>(access->getSeed());
}

void Room::MainLoop() {
    
    modules = make_unique<Modules>();
    screen = make_shared<Screen>();

    modules->welcome(name->getName());
    
    char key = '0';

    do
    { 
        modules->_sys(RWNIO_SYS_CLEAR);

        rwnio::screen( C, "  [i]     Iniciar grupo", N );
        rwnio::screen( C, "  [u]     Unirse a un grupo", N );
        rwnio::screen( C, "  [n]     Cambiar Nombre", N );
        rwnio::screen( C, "  [q]     Quit", N);

        rwnio::screen(C , N,  "> " );
        std::cin >> key;        

        switch (key)
        {
        
        case 'i':
          
          startRoom();

        break;

        case 'n':
            modules->_sys(RWNIO_SYS_CLEAR);

            rwnio::screen(C, "ingresa tu nuevo nombre: ");
            string _temp{};
            std::cin>>_temp;
            name->setName(std::move(_temp));
            break;
        }

    } while (key!='q');

    modules.reset();
}


void Room::startRoom() {

        modules->_sys(RWNIO_SYS_CLEAR);        
        screen->write(" [*] Grupos", 1, 1);

        rwnio::screen( C, N, N, "El hash de la sala:  ", *hash, N, N);
        rwnio::screen(C, "> X ");
        
        char ch;
        std::cin>>ch;

        custom = make_shared<Custom>(name->getName(),*hash);
        custom->loopCustom();

}