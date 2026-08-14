/*Some decription 
This is from 2026
made by Anielka5555*/
/*Predispositions bla bla bla bla*/

//importing
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "./functions/font/font.h"
#include "./screens/main/main.h"

//definitons of vars
CHAR_INFO globalny_ekran[320 * 240];
//settings
// Bezpieczna metoda pobierania HWND okna działająca od Windows 95 do Windows 11
HWND GetConsoleWindowUniversal() {
    char szNewTitle[64];
    char szOldTitle[1024];
    
    GetConsoleTitleA(szOldTitle, sizeof(szOldTitle));
    sprintf(szNewTitle, "KONSOLA_%u", (unsigned int)GetTickCount());
    SetConsoleTitleA(szNewTitle);
    Sleep(100);
    
    HWND hWnd = FindWindowA("ConsoleWindowClass", szNewTitle);
    SetConsoleTitleA(szOldTitle);
    return hWnd;
}

void needed_settings(const int width, const int height){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /* 1. Ustawienie czcionki 2x2 z pliku font.h */
    UstawRozmiarCzcionki(hConsole);

    /* 2. Dopasowanie bufora konsoli pod wymiar retro */
    COORD rozmiarBufora;
    rozmiarBufora.X = (SHORT)width;
    rozmiarBufora.Y = (SHORT)height;
    SetConsoleScreenBufferSize(hConsole, rozmiarBufora);

    /* 3. Dopasowanie fizycznego okna do rozmiaru bufora */
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = (SHORT)(width - 1);
    rect.Bottom = (SHORT)(height - 1);
    SetConsoleWindowInfo(hConsole, TRUE, &rect);

    /* 4. Całkowite ukrycie kursora tekstowego */
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    /* 5. Wyłączenie trybu zaznaczania myszką (Zapobiega zamrażaniu i napisowi "Wybierz") */
    DWORD trybWejscia;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &trybWejscia);
    trybWejscia &= ~ENABLE_QUICK_EDIT_MODE; 
    SetConsoleMode(hInput, trybWejscia);

    /* 6. Przejście nakładki w tryb ABSOLUTNEGO FULLSCREENU */
    HWND hWnd = GetConsoleWindowUniversal();
    if (hWnd != NULL) {
        // Wycinamy belkę tytułową, krzyżyk zamknięcia, przyciski minimalizacji i ramki okna
        LONG stylOkna = GetWindowLongA(hWnd, GWL_STYLE);
        stylOkna &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
        SetWindowLongA(hWnd, GWL_STYLE, stylOkna);

        // Rozciągamy okno na pełne wymiary aktualnego monitora i wymuszamy odświeżenie
        SetWindowPos(hWnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
    }
}

//main
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Wymiary ekranu nakładki w pseudo-pikselach
    const int SZEROKOSC = 320; 
    const int WYSOKOSC = 240; 

    needed_settings(SZEROKOSC, WYSOKOSC);

    // Wywołanie rysowania Twojego retro pulpitu
    draw::Desktop(SZEROKOSC, WYSOKOSC);

    // FIX: Usunięto ponowną deklarację HANDLE hConsole, używamy tej z góry main()
    COORD coord = {0, 0};
    SetConsoleCursorPosition(hConsole, coord);

     /* PANCERNA PĘTLA ZAMYKANIA – SPRAWDZANIE BEZPOŚREDNIO W WINDOWS 11 */
    while (TRUE) {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break; // Gwarancja wyjścia z pętli po kliknięciu ESC
        }
        Sleep(20); 
    }

    // === REAKCJA NA ESCAPE ===
    Beep(880, 150);

    // 1. OBRONA PRZED WIDMEM DWM: Ukrywamy fizyczne okno konsoli przed systemem!
    // Dzięki temu Windows 11 natychmiast wymaże bufor graficzny Twojej aplikacji z ekranu.
    HWND hWndDoZamkniecia = GetConsoleWindowUniversal();
    if (hWndDoZamkniecia != NULL) {
        ShowWindow(hWndDoZamkniecia, SW_HIDE); 
    }

    /* AWARYJNY I UKRYTY RESTART PULPITU */
    WinExec("cmd.exe /c start explorer.exe", SW_HIDE);
    
    Beep(880, 150);
    Sleep(200); // Bardzo krótkie uśpienie na załapanie procesu

    /* OSTATECZNY STRZAŁ Z POZIOMU JĄDRA SYSTEMU (KERNEL) */
    TerminateProcess(GetCurrentProcess(), 0);

    return 0; 
}