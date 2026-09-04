#ifndef ela
#define ela
#include "../render/printSpecialA.h"
#include "../render/endPrintA.h"

void rysujZnak(int startX, int startY, const unsigned char sprite[5][5]) {
        #define c RETRO_CZERWONY
        for (int rzad = 0; rzad < 5; rzad++) {
            for (int kolumna = 0; kolumna < 5; kolumna++) {
                unsigned char kolor = sprite[rzad][kolumna];
                
                if (kolor != '_'){
                    // Funkcja po prostu bierze numer koloru z tablicy i go rysuje!
                    printSpecialA(startX + kolumna, startY + rzad, c);
                }
            }
        }
}
const unsigned char zero[5][5] = {
    {'_', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', 'O'},
    {'O', '_', '_', '_', 'O'},
    {'O', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'}
};
const unsigned char one[5][5] = {
    {'_', '_', 'O', '_', '_'}, 
    {'_', 'O', 'O', '_', '_'}, 
    {'O', '_', 'O', '_', '_'},
    {'_', '_', 'O', '_', '_'}, 
    {'_', '_', 'O', '_', '_'}
};
const unsigned char two[5][5] = {
    {'O', 'O', 'O', 'O', '_'},
    {'_', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', '_'},
    {'O', 'O', 'O', 'O', 'O'}
};

const unsigned char three[5][5] = {
    {'O', 'O', 'O', 'O', '_'},
    {'_', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'},
    {'_', '_', '_', '_', 'O'},
    {'O', 'O', 'O', 'O', '_'}
};

const unsigned char four[5][5] = {
    {'O', '_', '_', '_', 'O'},
    {'O', '_', '_', '_', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'_', '_', '_', '_', 'O'},
    {'_', '_', '_', '_', 'O'}
};

const unsigned char five[5][5] = {
    {'O', 'O', 'O', 'O', 'O'},
    {'O', '_', '_', '_', '_'},
    {'O', 'O', 'O', 'O', '_'},
    {'_', '_', '_', '_', 'O'},
    {'O', 'O', 'O', 'O', '_'}
};

const unsigned char six[5][5] = {
    {'_', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', '_'},
    {'O', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'}
};

const unsigned char seven[5][5] = {
    {'O', 'O', 'O', 'O', 'O'},
    {'_', '_', '_', '_', 'O'},
    {'_', '_', '_', 'O', '_'},
    {'_', '_', 'O', '_', '_'},
    {'_', '_', 'O', '_', '_'}
};

const unsigned char eight[5][5] = {
    {'_', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'}
};

const unsigned char nine[5][5] = {
    {'_', 'O', 'O', 'O', '_'},
    {'O', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', 'O'},
    {'_', '_', '_', '_', 'O'},
    {'_', 'O', 'O', 'O', '_'}
};

#endif