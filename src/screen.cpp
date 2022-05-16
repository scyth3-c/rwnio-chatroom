#include "screen.h"

Screen::Screen() {}

#if defined(_WIN32) || defined(_WIN64)
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
#else

void Screen::gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
#endif

void Screen::write(string _type, int x, int y)
{
    for (size_t i = 0; i < _type.length(); i++)
    {
        _wait(50);
        gotoxy(x++, y);
        std::cout << _type[i] << " " << std::flush;
    }
}

void Screen::_wait(int milis)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milis));
}
