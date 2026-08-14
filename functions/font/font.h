#ifndef FONT_H
#define FONT_H

#include <windows.h>

// Definiujemy wskaźniki dynamiczne – dzięki temu program uruchomi się na Win95
typedef BOOL (WINAPI *SetConsoleFont_t)(HANDLE, DWORD);
typedef BOOL (WINAPI *SetCurrentConsoleFontEx_t)(HANDLE, BOOL, PCONSOLE_FONT_INFOEX);

static void UstawRozmiarCzcionki(HANDLE hConsole) {
    HMODULE hKernel = GetModuleHandleA("kernel32.dll");
    if (hKernel == NULL) return;

    // Próbujemy pobrać obie funkcje z biblioteki systemowej
    SetConsoleFont_t SetConsoleFont = (SetConsoleFont_t)GetProcAddress(hKernel, "SetConsoleFont");
    SetCurrentConsoleFontEx_t SetCurrentFontEx = (SetCurrentConsoleFontEx_t)GetProcAddress(hKernel, "SetCurrentConsoleFontEx");

    if (SetCurrentFontEx != NULL) {
        /* [WINDOWS VISTA / 10 / 11] */
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 2; // Szerokość pseudo-piksela
        cfi.dwFontSize.Y = 2; // Wysokość pseudo-piksela
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        
        // Lucida Console to czcionka wektorowa – Windows 11 ją uwielbia 
        // i pozwala zmniejszyć ją aż do rozmiaru 2x2 bez żadnych błędów!
        lstrcpyW(cfi.FaceName, L"Lucida Console");
        
        SetCurrentFontEx(hConsole, FALSE, &cfi);
    } 
    else if (SetCurrentFontEx == NULL && SetConsoleFont != NULL) {
        /* [WINDOWS 95 / 98 / ME / XP] */
        // Teraz mamy absolutną pewność, że jesteśmy na starym systemie!
        SetConsoleFont(hConsole, 0); 
    }
    else{
        printf("Odpalenie było niemożliwe.");
    }
}

#endif