#pragma once
#include <windows.h>
#include <iostream>

// Poprawny zapis przestrzeni nazw w C++
namespace font2 
{
    // Funkcja inicjalizująca - wywołujesz ją TYLKO RAZ na początku programu
    // Dodajemy 'inline', ponieważ kod jest w pliku .hpp
    inline bool font2x2()
    {
        LPCWSTR fontPath = L"2x2font.ttf"; 

        if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) == 0) {
            std::cerr << "Blad ladowania pliku czcionki!" << std::endl;
            return false;
        }

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        
        cfi.dwFontSize.X = 4;                  
        cfi.dwFontSize.Y = 4;                  
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;             

        wcscpy_s(cfi.FaceName, L"small fonts"); 

        SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

        return true;
    }

    // Osobna, mała funkcja czyszcząca - wywołujesz ją TYLKO RAZ na samym końcu programu
    inline void zamknijFont2x2()
    {
        LPCWSTR fontPath = L"2x2font.ttf"; 
        RemoveFontResourceEx(fontPath, FR_PRIVATE, NULL);
    }
} // Koniec przestrzeni nazw font2
