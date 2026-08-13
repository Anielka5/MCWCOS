
#include "../../functions/colors/colors.h"
#include "../../functions/printSpecialA.h"

namespace draw{
    void Desktop(const int width, const int height){
        /* Generowanie i rysowanie szachownicy */
        int y, x;
        for (y = 0; y < width; ++y) {
            for (x = 0; x < width; ++x) {
                if ((x + y) % 2 == 0) {
                    printSpecialA(RETRO_ZOLTY);
                } 
                else {
                    printSpecialA(RETRO_JASNO_NIEBIESKI);
                }
            }
        }
    }
}
