#include <iostream>
#include <conio.h>
#include "../functions/font/font2x2.hpp"
#include "../functions/colors/colors.hpp"

const int EKRAN_SZEROKOSC = 60;
const int EKRAN_WYSOKOSC = 80;

// Zamiast tablicy stringów, tworzymy oficjalny bufor systemowy Windowsa (CHAR_INFO)
CHAR_INFO buforEkranu[EKRAN_WYSOKOSC][EKRAN_SZEROKOSC];

// Funkcja pomocnicza zamieniająca Twoje teksty ANSI na liczby zrozumiałe dla karty graficznej
WORD konwertujKolorRetro(const std::string& kodANSI) {
    if (kodANSI == "31" || kodANSI == "41") return FOREGROUND_RED;
    if (kodANSI == "32" || kodANSI == "42") return FOREGROUND_GREEN;
    if (kodANSI == "34" || kodANSI == "44") return FOREGROUND_BLUE;
    if (kodANSI == "33" || kodANSI == "43") return FOREGROUND_RED | FOREGROUND_GREEN; // Żółty
    if (kodANSI == "93" || kodANSI == "103") return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; // Jasny żółty
    if (kodANSI == "35" || kodANSI == "45") return FOREGROUND_RED | FOREGROUND_BLUE; // Fiolet
    // Jeśli tło ma być niebieskie:
    return FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
}

void renderujBufor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Określamy wymiary naszej matrycy
    COORD rozmiarBufora = { EKRAN_SZEROKOSC, EKRAN_WYSOKOSC };
    COORD pozycjaStartowa = { 0, 0 };
    
    // Określamy gdzie na ekranie ma się to narysować (całe okno od 0,0 do 59,79)
    SMALL_RECT obszarZapisu = { 0, 0, EKRAN_SZEROKOSC - 1, EKRAN_WYSOKOSC - 1 };

    // Błyskawiczny taran dla Windows 11: wrzucamy całą pamięć na monitor w 1 milisekundę!
    WriteConsoleOutputA(hConsole, (CHAR_INFO*)buforEkranu, rozmiarBufora, pozycjaStartowa, &obszarZapisu);
}

int main() {
    // --- GWARANTOWANY AS W RĘKAWIE DLA WINDOWS 11 ---
    // Pobieramy uchwyt do fizycznego okna i zmuszamy je do przejścia w tryb pełnoekranowy
    HWND hwnd = GetConsoleWindow();
    SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0); 
    // ------------------------------------------------
    // Odpalamy font
    if (!font2::font2x2()) {
        std::cerr << "Blad ladowania fontu!" << std::endl;
        system("pause");
        return 1;
    }

    // GENEROWANIE GRAFIKI BEZPOŚREDNIO W STRUKTURZE WINDOWS
    for (int y = 0; y < EKRAN_WYSOKOSC; ++y) {
        for (int x = 0; x < EKRAN_SZEROKOSC; ++x) {
            // Każdemu klockowi przypisujemy literę 'A' z Twojej czcionki
            buforEkranu[y][x].Char.AsciiChar = 'A';

            // Przypisujemy kolory na podstawie pozycji
            if (x == y) {
                buforEkranu[y][x].Attributes = konwertujKolorRetro(c::RETRO_J_ZOLTY);
            } else {
                buforEkranu[y][x].Attributes = konwertujKolorRetro(c::RETRO_NIEBIESKI);
            }
        }
    }

    system("cls");

    // GŁÓWNA PĘTLA SYSTEMOWA
    while (true) {
        // Rysujemy gotową pamięć na monitorze (brak migania, 0% zużycia CPU)
        renderujBufor();

        // Bezpieczny, błyskawiczny przycisk awaryjny klawisza ESC
        if (_kbhit()) {
            char klawisz = _getch();
            if (klawisz == 27) { 
                system("start explorer.exe");
                font2::zamknijFont2x2();
                return 0; 
            }
        }

        Sleep(50); // Możemy odświeżać ekran jeszcze szybciej!
    }

    return 0;
}