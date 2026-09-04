#ifndef MATRICE_H
#define MATRICE_H

struct Point {
        int x;
        int y;
};

#include "../icon/ico-pos/readAppPos.h"
#include "../render/printSpecialA.h"
#include "../render/endPrintA.h"
#include "../colors/colors.h"
#include "tablefont.h"

    void rysujIkone(Point pozycja, const unsigned char sprite[29][29]) {
        // Do not attempt to draw an invalid file position.
        if (pozycja.x < 0 || pozycja.y < 0 ||
            pozycja.x >= 320 || pozycja.y >= 240) return;

        for (int rzad = 0; rzad < 29; rzad++) {
            for (int kolumna = 0; kolumna < 29; kolumna++) {
                unsigned char kolor = sprite[rzad][kolumna];
                
                if (kolor != '_'){
                    // Korzystamy bezpośrednio ze współrzędnych x i y schowanych w obiekcie pozycja
                    printSpecialA(pozycja.x + kolumna, pozycja.y + rzad, kolor);
                }
            }
        }
    }
    void NUM_MODE(){
        // Kolumna 1 (Liczby 1-5)
        rysujZnak(7, 7, one);
        rysujZnak(7, 49, two);
        rysujZnak(7, 91, three);
        rysujZnak(7, 133, four);
        rysujZnak(7, 175, five);

        // Kolumna 2 (Liczby 6-10)
        rysujZnak(38, 7, six);
        rysujZnak(38, 49, seven);
        rysujZnak(38, 91, eight);
        rysujZnak(38, 133, nine);
        rysujZnak(38, 175, one);     // Liczba 10 (Dziesiątka)
        rysujZnak(38, 175+6, zero);   // Liczba 10 (Jedność)

        // Kolumna 3 (Liczby 11-15)
        rysujZnak(68, 7, one); rysujZnak(68, 7+6, one);         // 11
        rysujZnak(68, 49, one); rysujZnak(68, 49+6, two);       // 12
        rysujZnak(68, 91, one); rysujZnak(68, 91+6, three);     // 13
        rysujZnak(68, 133, one); rysujZnak(68, 133+6, four);    // 14
        rysujZnak(68, 175, one); rysujZnak(68, 175+6, five);    // 15

        // Kolumna 4 (Liczby 16-20)
        rysujZnak(100, 7, one); rysujZnak(100, 7+6, six);       // 16
        rysujZnak(100, 49, one); rysujZnak(100, 49+6, seven);   // 17
        rysujZnak(100, 91, one); rysujZnak(100, 91+6, eight);   // 18
        rysujZnak(100, 133, one); rysujZnak(100, 133+6, nine);  // 19
        rysujZnak(100, 175, two); rysujZnak(100, 175+6, zero);  // 20

        // Kolumna 5 (Liczby 21-25)
        rysujZnak(131, 7, two); rysujZnak(131, 7+6, one);       // 21
        rysujZnak(131, 49, two); rysujZnak(131, 49+6, two);     // 22
        rysujZnak(131, 91, two); rysujZnak(131, 91+6, three);   // 23
        rysujZnak(131, 133, two); rysujZnak(131, 133+6, four);  // 24
        rysujZnak(131, 175, two); rysujZnak(131, 175+6, five);  // 25

        // Kolumna 6 (Liczby 26-30)
        rysujZnak(162, 7, two); rysujZnak(162, 7+6, six);       // 26
        rysujZnak(162, 49, two); rysujZnak(162, 49+6, seven);   // 27
        rysujZnak(162, 91, two); rysujZnak(162, 91+6, eight);   // 28
        rysujZnak(162, 133, two); rysujZnak(162, 133+6, nine);  // 29
        rysujZnak(162, 175, three); rysujZnak(162, 175+6, zero);// 30

        // Kolumna 7 (Liczby 31-35)
        rysujZnak(193, 7, three); rysujZnak(193, 7+6, one);     // 31
        rysujZnak(193, 49, three); rysujZnak(193, 49+6, two);   // 32
        rysujZnak(193, 91, three); rysujZnak(193, 91+6, three); // 33
        rysujZnak(193, 133, three); rysujZnak(193, 133+6, four);// 34
        rysujZnak(193, 175, three); rysujZnak(193, 175+6, five);// 35

        // Kolumna 8 (Liczby 36-40)
        rysujZnak(224, 7, three); rysujZnak(224, 7+6, six);     // 36
        rysujZnak(224, 49, three); rysujZnak(224, 49+6, seven); // 37
        rysujZnak(224, 91, three); rysujZnak(224, 91+6, eight); // 38
        rysujZnak(224, 133, three); rysujZnak(224, 133+6, nine);// 39
        rysujZnak(224, 175, four); rysujZnak(224, 175+6, zero); // 40

        // Kolumna 9 (Liczby 41-45)
        rysujZnak(255, 7, four); rysujZnak(255, 7+6, one);       // 41
        rysujZnak(255, 49, four); rysujZnak(255, 49+6, two);     // 42
        rysujZnak(255, 91, four); rysujZnak(255, 91+6, three);   // 43
        rysujZnak(255, 133, four); rysujZnak(255, 133+6, four);  // 44
        rysujZnak(255, 175, four); rysujZnak(255, 175+6, five);  // 45

        // Kolumna 10 (Liczby 46-50)
        rysujZnak(286, 7, four); rysujZnak(286, 7+6, six);       // 46
        rysujZnak(286, 49, four); rysujZnak(286, 49+6, seven);   // 47
        rysujZnak(286, 91, four); rysujZnak(286, 91+6, eight);   // 48
        rysujZnak(286, 133, four); rysujZnak(286, 133+6, nine);  // 49
        rysujZnak(286, 175, five); rysujZnak(286, 175+6, zero);  // 50

    }

#endif