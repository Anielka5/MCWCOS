#ifndef diwh
#define diwh

#include <cstdlib>

namespace read {
    // Zakładam, że struktura Point jest zdefiniowana globalnie
    using Point = ::Point;

    Point FindObjPos(const char* link) {
        HANDLE plik;
        DWORD przeczytano;
        char tekst[16] = {0};
        int pos = 0; 
        bool wczytanoPoprawnie = false;

        plik = CreateFileA(link, GENERIC_READ, FILE_SHARE_READ, NULL, 
                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if (plik != INVALID_HANDLE_VALUE) {
            // tekst has 16 bytes: reserve the last byte for the terminator.
            if (ReadFile(plik, tekst, sizeof(tekst) - 1, &przeczytano, NULL)) {
                if (przeczytano > 0) {
                    tekst[przeczytano] = '\0';
                    // Pozbywamy się ewentualnych znaków nowej linii \r lub \n na końcu bufora
                    for (DWORD i = 0; i < przeczytano; i++) {
                        if (tekst[i] == '\r' || tekst[i] == '\n') {
                            tekst[i] = '\0';
                            break;
                        }
                    }
                    char* koniec = NULL;
                    const long odczytanaPozycja = std::strtol(tekst, &koniec, 10);
                    if (koniec != tekst && *koniec == '\0' &&
                        odczytanaPozycja >= 1 && odczytanaPozycja <= 50) {
                        pos = static_cast<int>(odczytanaPozycja);
                        wczytanoPoprawnie = true;
                    }
                }
            }
            CloseHandle(plik);
        }

        // Jeśli nie wczytano pliku, zwracamy pozycję ujemną jako flagę błędu.
        if (!wczytanoPoprawnie) {
            return Point{-1, -1}; 
        }

        switch (pos)
        {
        // Kolumna 1
        case 1:  return Point{6, 6};
        case 2:  return Point{6, 48};
        case 3:  return Point{6, 90};
        case 4:  return Point{6, 132};
        case 5:  return Point{6, 174};
        
        // Kolumna 2
        case 6:  return Point{37, 6};
        case 7:  return Point{37, 48};
        case 8:  return Point{37, 90};
        case 9:  return Point{37, 132};
        case 10: return Point{37, 174};
        
        // Kolumna 3
        case 11: return Point{68, 6};
        case 12: return Point{68, 48};
        case 13: return Point{68, 90};
        case 14: return Point{68, 132};
        case 15: return Point{68, 174};
        
        // Kolumna 4
        case 16: return Point{99, 6};
        case 17: return Point{99, 48};
        case 18: return Point{99, 90};
        case 19: return Point{99, 132};
        case 20: return Point{99, 174};
        
        // Kolumna 5
        case 21: return Point{130, 6};
        case 22: return Point{130, 48};
        case 23: return Point{130, 90};
        case 24: return Point{130, 132};
        case 25: return Point{130, 174};
        
        // Kolumna 6
        case 26: return Point{161, 6};
        case 27: return Point{161, 48};
        case 28: return Point{161, 90};
        case 29: return Point{161, 132};
        case 30: return Point{161, 174};
        
        // Kolumna 7
        case 31: return Point{192, 6};
        case 32: return Point{192, 48};
        case 33: return Point{192, 90};
        case 34: return Point{192, 132};
        case 35: return Point{192, 174};
        
        // Kolumna 8
        case 36: return Point{223, 6};
        case 37: return Point{223, 48};
        case 38: return Point{223, 90};
        case 39: return Point{223, 132};
        case 40: return Point{223, 174};
        
        // Kolumna 9
        case 41: return Point{254, 6};
        case 42: return Point{254, 48};
        case 43: return Point{254, 90};
        case 44: return Point{254, 132};
        case 45: return Point{254, 174};
        
        // Kolumna 10
        case 46: return Point{285, 6};
        case 47: return Point{285, 48};
        case 48: return Point{285, 90};
        case 49: return Point{285, 132};
        case 50: return Point{285, 174};
        
        default:
            return Point{0, 0}; 
        }
    }
} // Koniec namespace read
#endif