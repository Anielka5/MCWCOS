#include <windows.h>
#include "icopic.h" // Plik z Twoimi ikonami 29x29

// Twój Pixel Viewer przyjmujący tablice 29x29
void PixelViewer29x29(const unsigned char ikona[29][29], int startX, int startY) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Rozmiar Twojej ikony to zawsze sztywne 29x29
    COORD bufferSize = {29, 29};
    COORD characterPos = {0, 0};
    
    // Pozycja i rozmiar docelowego okna rysowania na ekranie
    SMALL_RECT writeRegion = {
        (SHORT)startX, 
        (SHORT)startY, 
        (SHORT)(startX + 28), 
        (SHORT)(startY + 28)
    };

    // Alokujemy lokalny bufor kafelków dla konsoli
    CHAR_INFO localBuffer[29][29];

    for (int y = 0; y < 29; y++) {
        for (int x = 0; x < 29; x++) {
            unsigned char pixel = ikona[y][x];

            // Domyślne tło (np. ciemno żółte retro z pulpitu)
            WORD colorAttribute = BACKGROUND_RED | BACKGROUND_GREEN; 

            // Mapujemy Twoje kolory z pliku na atrybuty Win32 API
            if (pixel == RETRO_CZARNY) {
                colorAttribute = 0; // Brak kolorów = czarny
            }
            else if (pixel == RETRO_BIALY) {
                colorAttribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            }
            else if (pixel == RETRO_SZARY) {
                colorAttribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            }
            else if (pixel == RETRO_ZIELONY) {
                colorAttribute = BACKGROUND_GREEN;
            }
            else if (pixel == RETRO_JASNO_ZIELONY) {
                colorAttribute = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
            }
            else if (pixel == RETRO_JASNY_MORSKI) {
                colorAttribute = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            }
            else if (pixel == RETRO_ZOLTY) {
                colorAttribute = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
            }
            else if (pixel == RETRO_NIEBIESKI) {
                colorAttribute = BACKGROUND_BLUE;
            }
            else if (pixel == RETRO_JASNO_NIEBIESKI) {
                colorAttribute = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            }

            // KLUCZ DO WYGRANEJ: Ustawiamy ten sam kolor dla znaku i dla tła
            // Dzięki temu litera 'A' znika, a babcia widzi idealny retro kwadracik!
            if (pixel != '_') {
                // Jeśli to kolor ikony, ustawiamy go jako tło kafelka
                localBuffer[y][x].Attributes = colorAttribute;
            } else {
                // Jeśli to znak '_', rysujemy domyślne piaskowe tło pulpitu
                localBuffer[y][x].Attributes = BACKGROUND_RED | BACKGROUND_GREEN;
            }

            // Wypełniamy komórkę znakiem 'A'
            localBuffer[y][x].Char.AsciiChar = 'A';
        }
    }

    // Jedno szybkie wywołanie Win32 i cała ikona ląduje na ekranie bez glitchu!
    WriteConsoleOutputA(hConsole, (CHAR_INFO*)localBuffer, bufferSize, characterPos, &writeRegion);
}
int main(){
    // Rysuje idealny kosz na pozycji X=0, Y=0
PixelViewer29x29(ikona_kosz_29x29, 0, 0); 

// Rysuje internet obok na pozycji X=35, Y=0
PixelViewer29x29(ikona_internet_29x29, 35, 0); 
while (TRUE) {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break; // Gwarancja wyjścia z pętli po kliknięciu ESC
}
}
}