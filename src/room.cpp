#include "room.h"

Room::Room(int argc, char *argv[])
{

    modules = make_unique<Modules>();
    modules->_sys(RWNIO_SYS_CLEAR);
    modules->verifyNet();
    modules->verifyDatabase();
    modules.reset();

    models = make_unique<MODELS>();
    switch (argc)
    {
    case 3:
        prepare(std::move(argv[1]), std::move(argv[2]));
        break;
    case 2:
        prepare(std::move(argv[1]));
    default:
        prepare();
        break;
    }
}

char Room::KEY = '1';

Room::~Room()
{
    access.reset();
    name.reset();
    hash.reset();
    models.reset();
}

void Room::prepare(string _name, string _secret)
{
    name = make_unique<Name>(_name);

    if (name->verify())
    {
        name->setName(_name);
    }
    access = make_unique<Seed>((string)(_secret + name->getName() + access->genRandInit()));
    access->genSeed();
    hash = make_shared<string>(access->getSeed());
}

// sobrecarga de PREAPRE
void Room::prepare(string _secret)
{
    name = make_unique<Name>();
    access = make_unique<Seed>((string)(_secret + name->getName() + access->genRandInit()));
    access->genSeed();
    hash = make_shared<string>(access->getSeed());
}

void Room::prepare()
{
    name = make_unique<Name>();
    access = make_unique<Seed>((string)("public" + name->getName() + access->genRandInit()));
    access->genSeed();
    hash = make_shared<string>(access->getSeed());
}

void Room::MainLoop()
{

    modules = make_unique<Modules>();
    screen = make_shared<Screen>();
    modules->welcome(name->getName());

    do
    {
        models->mainLoop();
        READKEY

        switch (GETKEY)
        {
        case 'u':
            joinRoom();
            break;
        case 'i':
            startRoom();
            break;
        case 'n':
            modules->_sys(RWNIO_SYS_CLEAR);
            name->setName(std::move(models->changeName()));
            break;
        }
    } while (GETKEY != 'q');
    modules.reset();
}

void Room::setupMessage()
{
    message = make_shared<Message>(RWNIO_NAME, *hash);
    message->setUrl(RWNIO_HTTP_URL);
    message->send("rwnio");
    message->send("test");
    message->send("runtime");
    message.reset();
}

void Room::welcomeRoom(string _hash)
{
    message = make_shared<Message>(RWNIO_NAME, _hash);
    message->setUrl(RWNIO_HTTP_URL);
    message->send(name->getName()+" ha ingresado a la sala. ");
    message.reset();
}

void Room::startRoom()
{

    modules->_sys(RWNIO_SYS_CLEAR);
    models->startRoom(*hash);

    setupMessage();

    custom = make_shared<Custom>(name->getName(), *hash);
    custom->loopCustom();
}

void Room::joinRoom()
{
    modules->_sys(RWNIO_SYS_CLEAR);
    string hash = models->joinRoom();
    welcomeRoom(hash);
    custom = make_shared<Custom>(name->getName(),std::move(hash));
    custom->loopCustom();
}