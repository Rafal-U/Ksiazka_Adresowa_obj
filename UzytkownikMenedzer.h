#ifndef UZYTKOWNIKMENEGER_H
#define UZYTKOWNIKMENEGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika();

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    int logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy);
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
