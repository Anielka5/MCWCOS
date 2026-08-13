#ifndef FONT_H
#define FONT_H

#include <windows.h>

static void UstawRozmiarCzcionki(HANDLE hConsole) {
    /* 1. Rejestrujemy Twój prawdziwy plik .fon w systemie przed zmianą czcionki */
    AddFontResourceW(L"C:\\MyOS\\MCWCOS\\functions\\font\\moja_retro_czcionka.fon");
    SendMessageW(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 2; /* Szerokość: 2 piksele */
    cfi.dwFontSize.Y = 2; /* Wysokość: 2 piksele */
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    
    /* 2. Zamiast wektorowego "small fonts", wpisujesz nazwę swojego pliku .fon */
    lstrcpyW(cfi.FaceName, L"MCWCOS font"); 
    
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

#endif