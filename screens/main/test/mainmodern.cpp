#include <iostream>
#include "font2x2modern.hpp"

// Szerokość i wysokość Twojego ekranu graficznego
const int EKRAN_SZEROKOSC = 80;
const int EKRAN_WYSOKOSC = 60;

void printScreen(){
    // Pętla rysująca 80 wierszy w pionie
    for (int y = 0; y < EKRAN_WYSOKOSC; ++y) {
        // Pętla rysująca 60 liter 'A' w poziomie (jeden wiersz)
        for (int x = 0; x < EKRAN_SZEROKOSC; ++x) {
            std::wcout << L"A";
        }
        std::wcout << L"\n"; // Po narysowaniu 60 znaków przechodzimy do nowej linii
    }
}

int main(){
    if (!font2::font2x2()) {
        return 1; // Przerywamy, jeśli font się nie załadował
    }
    
    printScreen();   // Wyświetlenie całego ekranu 60x80
    
    std::cin.get();  // Czekaj na Enter
    font2::zamknijFont2x2();
    return 0;
}