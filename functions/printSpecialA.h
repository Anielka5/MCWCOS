#ifndef A
#define A
#include "./existing_func_not_working_defined_here/conio/tbackground_tcolor.h"
#include <conio.h>
// Funkcja rysująca jeden pseudo-piksel za pomocą litery 'A'
void printSpecialA(int color) {
    conio::textcolor(color);
    conio::textbackground(color);
    putch('A'); 
    conio::textcolor(7);   // Powrót do standardowego szarego tekstu
    conio::textbackground(0); // Powrót do czarnego tła
}
#endif