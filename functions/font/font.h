#ifndef FONT_H
#define FONT_H

#include <windows.h>

static void UstawRozmiarCzcionki(HANDLE hConsole) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 2; /* Szerokość: 2 piksele */
    cfi.dwFontSize.Y = 2; /* Wysokość: 2 piksele */
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    
    /* Stary, bezpieczny sposób kopiowania tekstu w Windows 95 */
    lstrcpyW(cfi.FaceName, L"small fonts"); 
    
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

#endif