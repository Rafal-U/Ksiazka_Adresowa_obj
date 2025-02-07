#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class MetodyPomocnicze
{
public:
    static string konwertujIntNaString(int liczba);
    static string wczytajLinie();
    static char wczytajZnak();
    static int wczytajLiczbeCalkowita();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int konwertujStringNaInt(string liczba);
};



#endif
