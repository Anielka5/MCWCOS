#include <iostream>
#include <conio.h>
#include <windows.h> // Potrzebne do GetConsoleWindow i GetEnvironmentVariableA
#include "C:\\MyOS\\functions\\font\\font2x2.hpp"
#include "C:\\MyOS\\functions\\colors\\colors.hpp"
#include <conio.h> // Specjalna biblioteka dla starych konsoli

const int EKRAN_SZEROKOSC = 60;
const int EKRAN_WYSOKOSC = 80;

// Nasz dwuwymiarowy bufor ekranu z kodami kolorów
std::string ekran[EKRAN_WYSOKOSC][EKRAN_SZEROKOSC];

// funcja używa conio aby ustawić kolor tła i jednocześnie litery "A", która w mojej specjalnej czcionce jest pełnym kwadratem
void printSpecialA(){

}

void printScreen() {
    char esc = 27; // Kod ASCII klawisza Escape

    for (int y = 0; y < EKRAN_WYSOKOSC; ++y) {
        for (int x = 0; x < EKRAN_SZEROKOSC; ++x) {
            std::string kolor = ekran[y][x];
            // Klasyczne wysyłanie sekwencji: ESC + [ + KOD + m + Litera
            std::cout << esc << "[" << kolor << "mA";
        }
        std::cout << esc << "[0m\n"; // Reset koloru na końcu każdego wiersza
    }
    std::fflush(stdout);
}

int main() {
    // --- GWARANTOWANY AS W RĘKAWIE: WYMUSZENIE RETRO KONSOLI (conhost.exe) ---
    // Sprawdzamy, czy program odpalił się w nowym Windows Terminalu (WT_SESSION).
    // Jeśli tak, natychmiast otwieramy go ponownie w starym oknie conhost.exe, które akceptuje własne czcionki!
    if (!GetConsoleWindow() || GetEnvironmentVariableA("WT_SESSION", NULL, 0) != 0) {
        system("start conhost.exe ./main_screen/main.exe");
        return 0; // Zamykamy niewydajną wersję z Windows Terminala
    }
    // -------------------------------------------------------------------------

#if defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0603)
    // SEKJA DLA WINDOWS 10 / WINDOWS 11:
    // Odblokowujemy interpretowanie kodów ESC przez system Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif

    // Odpalamy font (użytkownik retro wybiera "Small Fonts" we właściwościach okna)
    if (!font2::font2x2()) {
        std::cerr << "Blad ladowania fontu!" << std::endl;
        system("pause");
        return 1;
    }

    // PRZYKŁADOWA LOGIKA RYSOWANIA (Ustawianie kolorów na pozycjach)
    for (int y = 0; y < EKRAN_WYSOKOSC; ++y) {
        for (int x = 0; x < EKRAN_SZEROKOSC; ++x) {
            if (x == y) {
                ekran[y][x] = c::RETRO_J_ZOLTY; // Żółty krzyż na ukos
            } else {
                ekran[y][x] = c::RETRO_NIEBIESKI; // Niebieskie tło
            }
        }
    }

    char esc = 27;
    system("cls"); // Czyścimy okno raz przed startem rysowania

    // Główna pętla programu
    while (true) {
        std::cout << esc << "[H"; // Błyskawiczny reset pozycji kursora na (0,0)
        printScreen();             // Rysowanie Twojej matrycy

        // --- RETRO PRZYCISK AWARYJNY ---
        // Sprawdzamy, czy użytkownik wcisnął JAKIKOLWIEK klawisz
        if (_kbhit()) {
            char klawisz = _getch(); // Pobieramy wciśnięty klawisz
            
            // Jeśli tym klawiszem był Twój ESC (kod ASCII 27)
            if (klawisz == 27) {
                system("start explorer.exe"); // Włączamy normalny pulpit
                font2::zamknijFont2x2();      // Wyrejestrowujemy czcionkę
                return 0;                     // Zamykamy program natychmiast!
            }
        }

        // Zwiększamy czas oczekiwania na 150 ms, żeby dać systemowi czas na odświeżenie ekranu
        Sleep(150); 
    }

    return 0;
}