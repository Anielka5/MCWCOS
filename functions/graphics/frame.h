#ifndef SJHKK
#define SJHKK
#include "..\colors\colors.h"
#include "..\render\endPrintA.h"
#include "..\render\printSpecialA.h"
void frame(int pos){
    int StartX = 0;
    int StartY = 0;

    switch (pos)
    {
    // Kolumna 1
    case 1:  StartX = 6; StartY = 6; break;
    case 2:  StartX = 6; StartY = 48; break;
    case 3:  StartX = 6; StartY = 90; break;
    case 4:  StartX = 6; StartY = 132; break;
    case 5:  StartX = 6; StartY = 174; break;

    // Kolumna 2
    case 6:  StartX = 37; StartY = 6; break;
    case 7:  StartX = 37; StartY = 48; break;
    case 8:  StartX = 37; StartY = 90; break;
    case 9:  StartX = 37; StartY = 132; break;
    case 10: StartX = 37; StartY = 174; break;

    // Kolumna 3
    case 11: StartX = 68; StartY = 6; break;
    case 12: StartX = 68; StartY = 48; break;
    case 13: StartX = 68; StartY = 90; break;
    case 14: StartX = 68; StartY = 132; break;
    case 15: StartX = 68; StartY = 174; break;

    // Kolumna 4
    case 16: StartX = 99; StartY = 6; break;
    case 17: StartX = 99; StartY = 48; break;
    case 18: StartX = 99; StartY = 90; break;
    case 19: StartX = 99; StartY = 132; break;
    case 20: StartX = 99; StartY = 174; break;

    // Kolumna 5
    case 21: StartX = 130; StartY = 6; break;
    case 22: StartX = 130; StartY = 48; break;
    case 23: StartX = 130; StartY = 90; break;
    case 24: StartX = 130; StartY = 132; break;
    case 25: StartX = 130; StartY = 174; break;

    // Kolumna 6
    case 26: StartX = 161; StartY = 6; break;
    case 27: StartX = 161; StartY = 48; break;
    case 28: StartX = 161; StartY = 90; break;
    case 29: StartX = 161; StartY = 132; break;
    case 30: StartX = 161; StartY = 174; break;

    // Kolumna 7
    case 31: StartX = 192; StartY = 6; break;
    case 32: StartX = 192; StartY = 48; break;
    case 33: StartX = 192; StartY = 90; break;
    case 34: StartX = 192; StartY = 132; break;
    case 35: StartX = 192; StartY = 174; break;

    // Kolumna 8
    case 36: StartX = 223; StartY = 6; break;
    case 37: StartX = 223; StartY = 48; break;
    case 38: StartX = 223; StartY = 90; break;
    case 39: StartX = 223; StartY = 132; break;
    case 40: StartX = 223; StartY = 174; break;

    // Kolumna 9
    case 41: StartX = 254; StartY = 6; break;
    case 42: StartX = 254; StartY = 48; break;
    case 43: StartX = 254; StartY = 90; break;
    case 44: StartX = 254; StartY = 132; break;
    case 45: StartX = 254; StartY = 174; break;

    // Kolumna 10
    case 46: StartX = 285; StartY = 6; break;
    case 47: StartX = 285; StartY = 48; break;
    case 48: StartX = 285; StartY = 90; break;
    case 49: StartX = 285; StartY = 132; break;
    case 50: StartX = 285; StartY = 174; break;

    default:
        StartX = 0;
        StartY = 0;
        break;
    }
    int x, y;
    // Wypełnianie/modyfikacja brzegów tablicy niebieską obwódką:
    for (y = 0+StartY; y < 34+StartY; y++) {
        for (x = 0+StartX; x < 29+StartX; x++) {
            // Sprawdzamy czy piksel leży na krawędzi (góra, dół, lewo, prawo)
            if (y == 0+StartY || y == 33+StartY || x == 0+StartX || x == 28+StartX) {
                printSpecialA(x, y, RETRO_JASNO_NIEBIESKI);
            } else {
                // Tutaj pozostają oryginalne piksele ikony
                // ikona_zaznaczona[y][x] = ikona_oryginalna[y][x];
            }
        }
    }
    A::flush(320, 240);
}
void unframe(int pos){
    int StartX = 0;
    int StartY = 0;

    switch (pos)
    {
    // Kolumna 1
    case 1:  StartX = 6; StartY = 6; break;
    case 2:  StartX = 6; StartY = 48; break;
    case 3:  StartX = 6; StartY = 90; break;
    case 4:  StartX = 6; StartY = 132; break;
    case 5:  StartX = 6; StartY = 174; break;

    // Kolumna 2
    case 6:  StartX = 37; StartY = 6; break;
    case 7:  StartX = 37; StartY = 48; break;
    case 8:  StartX = 37; StartY = 90; break;
    case 9:  StartX = 37; StartY = 132; break;
    case 10: StartX = 37; StartY = 174; break;

    // Kolumna 3
    case 11: StartX = 68; StartY = 6; break;
    case 12: StartX = 68; StartY = 48; break;
    case 13: StartX = 68; StartY = 90; break;
    case 14: StartX = 68; StartY = 132; break;
    case 15: StartX = 68; StartY = 174; break;

    // Kolumna 4
    case 16: StartX = 99; StartY = 6; break;
    case 17: StartX = 99; StartY = 48; break;
    case 18: StartX = 99; StartY = 90; break;
    case 19: StartX = 99; StartY = 132; break;
    case 20: StartX = 99; StartY = 174; break;

    // Kolumna 5
    case 21: StartX = 130; StartY = 6; break;
    case 22: StartX = 130; StartY = 48; break;
    case 23: StartX = 130; StartY = 90; break;
    case 24: StartX = 130; StartY = 132; break;
    case 25: StartX = 130; StartY = 174; break;

    // Kolumna 6
    case 26: StartX = 161; StartY = 6; break;
    case 27: StartX = 161; StartY = 48; break;
    case 28: StartX = 161; StartY = 90; break;
    case 29: StartX = 161; StartY = 132; break;
    case 30: StartX = 161; StartY = 174; break;

    // Kolumna 7
    case 31: StartX = 192; StartY = 6; break;
    case 32: StartX = 192; StartY = 48; break;
    case 33: StartX = 192; StartY = 90; break;
    case 34: StartX = 192; StartY = 132; break;
    case 35: StartX = 192; StartY = 174; break;

    // Kolumna 8
    case 36: StartX = 223; StartY = 6; break;
    case 37: StartX = 223; StartY = 48; break;
    case 38: StartX = 223; StartY = 90; break;
    case 39: StartX = 223; StartY = 132; break;
    case 40: StartX = 223; StartY = 174; break;

    // Kolumna 9
    case 41: StartX = 254; StartY = 6; break;
    case 42: StartX = 254; StartY = 48; break;
    case 43: StartX = 254; StartY = 90; break;
    case 44: StartX = 254; StartY = 132; break;
    case 45: StartX = 254; StartY = 174; break;

    // Kolumna 10
    case 46: StartX = 285; StartY = 6; break;
    case 47: StartX = 285; StartY = 48; break;
    case 48: StartX = 285; StartY = 90; break;
    case 49: StartX = 285; StartY = 132; break;
    case 50: StartX = 285; StartY = 174; break;

    default:
        StartX = 0;
        StartY = 0;
        break;
    }
    int x, y;
    // Wypełnianie/modyfikacja brzegów tablicy niebieską obwódką:
    for (y = 0+StartY; y < 34+StartY; y++) {
        for (x = 0+StartX; x < 29+StartX; x++) {
            // Sprawdzamy czy piksel leży na krawędzi (góra, dół, lewo, prawo)
            if (y == 0+StartY || y == 33+StartY || x == 0+StartX || x == 28+StartX) {
                printSpecialA(x, y, RETRO_ZOLTY);
            } else {
                // Tutaj pozostają oryginalne piksele ikony
                // ikona_zaznaczona[y][x] = ikona_oryginalna[y][x];
            }
        }
    }
    A::flush(320, 240);
}
#endif