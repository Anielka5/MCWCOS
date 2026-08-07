#ifndef TBACKGROUND_TCOLOR_H 
#define TBACKGROUND_TCOLOR_H 
#include <windows.h>
// Funkcje kolorów kompatybilne z każdym systemem (int zamiast WORD)
namespace conio{
    void textcolor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
            int current_background = csbi.wAttributes & 0xF0; 
            SetConsoleTextAttribute(hConsole, (color & 0x0F) | current_background);
        }
    }

    void textbackground(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
            int current_foreground = csbi.wAttributes & 0x0F; 
            SetConsoleTextAttribute(hConsole, current_foreground | ((color & 0x0F) << 4));
        }
    }
}
#endif