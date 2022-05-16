#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

#if !defined(_WIN32) && !defined(_WIN64)
#include <unistd.h>
#endif

using std::string;

class Screen
{
private:
public:
    Screen();

    void write(string, int, int);
    void gotoxy(int x, int y);

    void _wait(int);
};

#endif // ! SCREEN_H