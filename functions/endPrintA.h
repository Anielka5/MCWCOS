#ifndef ER
#define ER
#include <windows.h>

extern CHAR_INFO globalny_ekran[320 * 240];

namespace A{
    void flush(int width, int height){
        /* 
           Gdy pętle skończą rysować na naszej niewidzialnej kartce,
           tutaj (na samym dole funkcji, PO pętlach) robimy jedno tąpnięcie 
           i wysyłamy gotowy obraz na monitor:
        */
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD rozmarBufora = { (SHORT)width, (SHORT)height };
        COORD wspolrzedneStartu = { 0, 0 };
        SMALL_RECT obszarRysowania = { 0, 0, (SHORT)(width - 1), (SHORT)(height - 1) };
        
        WriteConsoleOutputW(hConsole, globalny_ekran, rozmarBufora, wspolrzedneStartu, &obszarRysowania);
    }
}
#endif