#ifndef GNI
#define GNI
#include <windows.h>
#include <string>
#include <cstring>
#include <conio.h>
#include <sstream>

std::string Pozycja_apk(const char* link) {
    HANDLE plik;
    DWORD przeczytano;
    char tekst[16] = {0};
    std::string napis = "";
    bool wczytanoPoprawnie = false;

    plik = CreateFileA(link, GENERIC_READ, FILE_SHARE_READ, NULL, 
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (plik != INVALID_HANDLE_VALUE) {
        if (ReadFile(plik, tekst, sizeof(tekst) - 1, &przeczytano, NULL)) {
            if (przeczytano > 0) {
                tekst[przeczytano] = '\0';
                for (DWORD i = 0; i < przeczytano; i++) {
                    if (tekst[i] == '\r' || tekst[i] == '\n') {
                        tekst[i] = '\0';
                        break;
                    }
                    else {
                        napis += tekst[i];
                    }
                }
                long odczytanaPozycja = 0;
                std::stringstream ss(tekst);
                // Sprawdzamy, czy udało się wczytać liczbę i czy nie ma po niej śmieci
                if ((ss >> odczytanaPozycja) && ss.eof() && odczytanaPozycja >= 1 && odczytanaPozycja <= 52) {
                    wczytanoPoprawnie = true;
                }
            }
        }
        CloseHandle(plik);
    }

    if (std::strcmp(link, "data/trashbin/trashpos.dat") == 0) return "51";
    else if (std::strcmp(link, "data/my_files/myfilespos.dat") == 0) return "52";

    if (!wczytanoPoprawnie) {
        return ""; 
    }
    return napis;
}

void ikonka(std::string klawisz){
    std::string konsola    = Pozycja_apk("data/console/consolepos.dat");
    std::string draw       = Pozycja_apk("data/draw/drawpos.dat");
    std::string informacje = Pozycja_apk("data/info/infopos.dat");
    std::string notatnik   = Pozycja_apk("data/notes/notepos.dat");
    std::string ustawienia = Pozycja_apk("data/settings/settingspos.dat");
    std::string kosz       = Pozycja_apk("data/trashbin/trashpos.dat");
    std::string moje_pliki = Pozycja_apk("data/my_files/myfilespos.dat");
    std::string internet   = Pozycja_apk("data/web/webpos.dat");
    
    if (klawisz == konsola) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                if (WinExec("cmd.exe", SW_SHOWNORMAL) <= 31) {
                    WinExec("command.com", SW_SHOWNORMAL);
                }
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (draw == klawisz) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                if (WinExec("mspaint.exe", SW_SHOWNORMAL) <= 31) {
                    WinExec("pbrush.exe", SW_SHOWNORMAL);
                }
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (informacje == klawisz) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                MessageBoxA(NULL, "Ta aplikacja jest jeszcze w budowie (Still in work)!", "Informacja", MB_OK | MB_ICONINFORMATION);
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (klawisz == notatnik) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                WinExec("notepad.exe", SW_SHOWNORMAL);
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (klawisz == ustawienia) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                WinExec("control.exe", SW_SHOWNORMAL);
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (klawisz == kosz) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                if (WinExec("explorer.exe shell:RecycleBinFolder", SW_SHOWNORMAL) <= 31) {
                    WinExec("explorer.exe ::645FF040-5081-101B-9F88-00AA2F954E", SW_SHOWNORMAL);
                }
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (klawisz == moje_pliki) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                WinExec("explorer.exe", SW_SHOWNORMAL);
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
    else if (klawisz == internet) {
        while (true) {
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                if (_kbhit()) _getch();
                if (WinExec("msedge.exe https://www.google.com", SW_SHOWNORMAL) <= 31) {
                    if (WinExec("msedge.exe", SW_SHOWNORMAL) <= 31) {
                        ShellExecuteA(NULL, "open", "iexplore.exe", NULL, NULL, SW_SHOWNORMAL);
                    }
                }
                return;
            }
            else if (_kbhit()) {
                _getch();
                return;
            }
            Sleep(10);
        }
    }
}

#endif
