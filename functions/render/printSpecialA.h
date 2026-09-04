#ifndef A
#define A

#include "../colors/colors.h" // Importujemy Twoją paletkę
#include <windows.h>

// Zakładamy, że tablica globalny_ekran jest zadeklarowana w projekcie
extern CHAR_INFO globalny_ekran[320 * 240];


void printSpecialA(int x, int y, int color) {
    // 1. Zabezpieczenie: jeśli piksel ucieka poza ekran 320x240, nic nie rób
    if (x < 0 || x >= 320 || y < 0 || y >= 240) return;

    // 2. Wyliczamy pozycję piksela w pamięci RAM
    int index = y * 320 + x;

    // 3. Wstawiamy Twój ukochany znak 'A' do pamięci
    globalny_ekran[index].Char.UnicodeChar = L'A';

    /* 4. MAGIA KOLORÓW WINDOWS API:
       - color & 0x0F to Twój kolor tekstu (0-15)
       - (color & 0x0F) << 4 przesuwa ten sam kolor na pozycję tła konsoli!
       Dzięki temu tekst i tło mają identyczną barwę, tworząc czysty pseudo-piksel. */
    globalny_ekran[index].Attributes = (color & 0x0F) | ((color & 0x0F) << 4);
}

#endif