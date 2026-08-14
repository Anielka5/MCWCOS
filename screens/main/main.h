
#include "../../functions/colors/colors.h"
#include "../../functions/printSpecialA.h"
#include "../../functions/endPrintA.h"

#include <windows.h>

extern CHAR_INFO globalny_ekran[320 * 240];
namespace draw{
    void Desktop(const int width, const int height){
        /* Generowanie i rysowanie szachownicy */
        int y, x;
        for (y = 0; y < height; ++y) {
            for (x = 0; x < width; ++x) {
                if ((x + y) % 2 == 0) {
                    printSpecialA(x, y, RETRO_ZOLTY);
                } 
                else {
                    printSpecialA(x, y, RETRO_JASNO_NIEBIESKI);
                }
            }
        }
        A::flush(width, height);
    }
}
