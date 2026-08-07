#pragma once
#include <iostream>

// Sprawdzamy czy kompilujemy na systemie Windows
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#else
    // Sekcja dla macOS / Linux
    #include <unistd.h> 
#endif

namespace font2 
{
    inline bool font2x2()
    {
#if defined(_WIN32) || defined(_WIN64)
        // KOD DLA WINDOWS (To co napisałaś do tej pory)
        if (AddFontResourceA("C:\\MyOS\\functions\\font\\2x2font.ttf") == 0) {
            return false;
        }
        SendMessageA(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);

                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) return false;

        COORD bufferSize = { 60, 80 };
        SMALL_RECT windowSize = { 0, 0, 59, 79 };
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);

        if (csbi.dwSize.X < bufferSize.X || csbi.dwSize.Y < bufferSize.Y) {
            SetConsoleScreenBufferSize(hConsole, bufferSize);
            SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
        } else {
            SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
            SetConsoleScreenBufferSize(hConsole, bufferSize);
        }
        return true;
#else
        // KOD DLA MAC / LINUX
        // Terminale na Macu (POSIX) automatycznie dopasowują się do strumienia znaków.
        // Użytkownik Maca musi po prostu ręcznie ustawić czcionkę "Small Fonts" w ustawieniach Terminala.
        // Włączamy tylko obsługę sekwencji ANSI (na Macu działa to domyślnie).
               std::cout << "\x1b[8;80;60t"; // Specjalny kod ANSI, który automatycznie zmienia rozmiar okna na 80 wierszy i 60 kolumn!
        return true;
#endif
    }

    inline void zamknijFont2x2()
    {
#if defined(_WIN32) || defined(_WIN64)
        RemoveFontResourceA("C:\\MyOS\\functions\\font\\2x2font.ttf");
        SendMessageA(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
#else
        // Na Macu nie musimy czyścić pamięci z fontu, bo system nie blokuje plików .ttf
#endif
    }
}