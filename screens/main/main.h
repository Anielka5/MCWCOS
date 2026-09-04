#ifndef kaczka
#define kaczka

#include "../../functions/icon/icoPic.h"
#include "../../functions/graphics/matrice.h"
#include "../../functions/icon/ico-pos/readAppPos.h"
#include <windows.h>

namespace drawEl{
    void Desktop(const int width, const int height, bool to_draw_NUM_MODE){
        for (int i = 0; i < width * height; ++i) {
            globalny_ekran[i].Char.UnicodeChar = L' ';
            globalny_ekran[i].Attributes = 0;
        }

        /* Generowanie i rysowanie szachownicy */
        int y, x;
        for (y = 0; y < 220; ++y) {
            for (x = 0; x < width; ++x) {
                printSpecialA(x, y, RETRO_ZOLTY);
            }
        }
        if (to_draw_NUM_MODE) NUM_MODE();
        rysujIkone(read::FindObjPos("data/console/consolepos.dat"), ikona_konsola_29x29);
        rysujIkone(read::FindObjPos("data/draw/drawpos.dat"), ikona_draw_29x29);
        rysujIkone(read::FindObjPos("data/info/infopos.dat"), ikona_info_29x29);
        rysujIkone(read::FindObjPos("data/notes/notepos.dat"), ikona_notatnik_29x29);
        rysujIkone(read::FindObjPos("data/settings/settingspos.dat"), ikona_ustawienia_29x29);
        rysujIkone(read::FindObjPos("data/trashbin/trashpos.dat"), ikona_kosz_29x29);
        rysujIkone(read::FindObjPos("data/my_files/myfilespos.dat"), ikona_foldery_29x29);
        rysujIkone(read::FindObjPos("data/web/webpos.dat"), ikona_internet_29x29);

        for (y = 220; y < height; ++y) {
            for (x = 0; x < width; ++x) {
                printSpecialA(x, y, RETRO_BRAZOWY);
            }
        }

        A::flush(width, height);
    }
}
#endif
