#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
     : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
     {
         adresatMenedzer = NULL;
     };

     ~KsiazkaAdresowa()
     {
         delete adresatMenedzer;
         adresatMenedzer = NULL;
     };

    void zarejestrujUzytkownika();
    void zalogujUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    void zamknijProgram();
    void zarzadzajAdresatami();
};


#endif
