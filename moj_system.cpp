
/*Some decription 
This is from 2026
made by Anielka5555*/
/*Predispositions bla bla bla bla*/

//importing
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "./functions/font/font.h"
#include "./screens/main/main.h"

//settings
// Bezpieczna metoda pobierania HWND okna działająca od Windows 95 do Windows 11
HWND GetConsoleWindowUniversal() {
    // Próba użycia nowoczesnej funkcji systemowej
    HWND hWnd = GetConsoleWindow();
    if (hWnd != NULL) return hWnd;

    // Jeśli funkcja wyżej zwróci NULL (starsze systemy), używamy triku z tytułem
    char szNewTitle[64];
    char szOldTitle[1024];
    GetConsoleTitleA(szOldTitle, sizeof(szOldTitle));
    sprintf(szNewTitle, "KONSOLA_%d", GetTickCount());
    SetConsoleTitleA(szNewTitle);
    Sleep(40);
    hWnd = FindWindowA("ConsoleWindowClass", szNewTitle);
    SetConsoleTitleA(szOldTitle);
    return hWnd;
}

void needed_settings(const int width, const int height){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /* 1. Ustawienie czonki 2x2 z pliku font.h */
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

    /* 5. Przejście nakładki w tryb ABSOLUTNEGO FULLSCREENU */
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

    draw::Desktop(SZEROKOSC, WYSOKOSC);

    /* PĘTLA NAKŁADKI ALPHA 1.0 – Globalne oczekiwanie na klawisz ESC */
    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        Sleep(10); // Odpoczynek dla procesora
    }

    /* POWRÓT NA PULPIT – Przywrócenie ikon i paska zadań */
    WinExec("explorer.exe", SW_SHOW);

    return 0;
}