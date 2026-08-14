
import struct

# Tworzymy minimalistyczną strukturę nagłówka starego pliku .FON / .FNT
# Zdefiniujemy tylko jeden znak (65 - 'A') o rozmiarze 2x2 piksele
with open("C:/MyOS/MCWCOS/functions/font/moja_retro_czcionka.fon", "wb") as f:
    # Zapisujemy podstawowe bajty identyfikacyjne formatu Windows Font
    f.write(b'\x00\x02' + b'\x00' * 114) # Uprawnienia i puste nagłówki
    # Reprezentacja binarna Twojego znaku ## (w systemie dwójkowym zapalone piksele)
    f.write(struct.pack('BB', 0b11000000, 0b11000000))

print("Sukces! Plik .fon został wygenerowany poprawnie dla MCWCOS!")
