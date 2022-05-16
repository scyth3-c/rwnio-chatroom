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
    rwnio::screen(C, "[rwnio] start rooms", N);
    rwnio::screen(C, N, "hash de la sala: ", hash, N);
    rwnio::screen(C, N, "al continuar, se genera la sala, de otro modo no existira", N, N);
    rwnio::screen(C, "comparte tu hash desde "+(string)RWNIO_HTTP_URL+"rwnio/hash?hash="+hash, N, N);
    rwnio::screen(C, N, "[Y]: ");
    PAUSE
}

string MODELS::joinRoom() {
    rwnio::screen(C, "[rwnio] start rooms", N, N);
    rwnio::screen(C, "ingresa el hash unico de la sala: ", N);
    string _temp{};
    std::cin>>_temp;
    return _temp;
}

void MODELS::mainLoop()
{
    rwnio::screen(C, "  [i]     Iniciar grupo", N);
    rwnio::screen(C, "  [u]     Unirse a un grupo", N);
    rwnio::screen(C, "  [n]     Cambiar Nombre", N);
    rwnio::screen(C, "  [q]     Quit", N);

    rwnio::screen(C, N, "> ");
}

string MODELS::changeName()
{
    rwnio::screen(C, "ingresa tu nuevo nombre: ");
    string _temp{};
    std::cin >> _temp;
    modules->_sys(RWNIO_SYS_CLEAR);
    modules->welcome(_temp);
    return _temp;
}
