#include "models.h"

MODELS::MODELS()
{
    modules = std::make_unique<Modules>();
    screen = std::make_unique<Screen>();
}

MODELS::~MODELS()
{
    modules.reset();
    screen.reset();
}

char MODELS::__key = '1';

void MODELS::startRoom(std::string hash)
{
    rwnio::screen(C, "--[rwnio] start rooms", N, N);

    screen->write("-> hash: "+hash, 1,5);

    rwnio::screen(C, N, N, "-> la sala existe solo al continuar", N, N);
    rwnio::screen(C, "-> comparte tu hash desde:  "+(string)RWNIO_HTTP_URL+"rwnio/hash?hash="+hash, N, N);
    rwnio::screen(C, N, "[y]: ");
    PAUSE
}

string MODELS::joinRoom() {
    rwnio::screen(C, "--[rwnio] join rooms", N, N);
    rwnio::screen(C, "pueden volver a unirse si mantienen el hash!", N, N);
    rwnio::screen(C, "ingresa el hash unico de la sala: ", N);
    string _temp{};
    std::cin>>_temp;
    return _temp;
}

void MODELS::mainLoop()
{
    rwnio::screen(C,"    __________________________",    N);
    rwnio::screen(C,"---| [i]     Iniciar grupo     |",  N);
    rwnio::screen(C,"---| [u]     Unirse a un grupo |",  N);
    rwnio::screen(C,"   | [n]     Cambiar Nombre    |",  N);
    rwnio::screen(C,"   | [q]     Quitar            |",  N);
    rwnio::screen(C,"   |                           |",  N);
    rwnio::screen(C,"   -----------------------------",  N );

    rwnio::screen(C, N, "-->> ");
}
string MODELS::changeName()
{
    rwnio::screen(C, "---[rwnio] settings", N,N);
    rwnio::screen(C,"\t","ingresa tu nuevo nombre: ");
    string _temp{};
    std::cin >> _temp;
    modules->_sys(RWNIO_SYS_CLEAR);
    modules->welcome(_temp);
    return _temp;
}
