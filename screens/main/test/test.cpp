#include <iostream>
#include <windows.h>
#include "../functions/font/font2x2.hpp"

int main() {
    // Wymuszamy włączenie kolorów w Windows 11
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    char esc = 27;

    font2::font2x2();

    // Test 1: Zwykły napis z kolorem tła i tekstu
    std::cout << esc << "[33;44m TO JEST TEST KOLORU " << esc << "[0m" << std::endl;

    // Test 2: Próba wyświetlenia Twojej litery A
    std::cout << "A A A A A" << std::endl;

    font2::zamknijFont2x2();

    system("pause");
    return 0;
}