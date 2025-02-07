#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"
using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void uaktualnijPlikiZAdresatami();

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata = 0;
    };

    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    int pobierzIdOstatniegoAdresata();
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void uporzadkujPlikiPodczasEdytowaniaAdresata(Adresat edytowanyAdresat);
    void uporzadkujPlikiPodczasUsuwaniaAdresata(int idAdresataUsunietego);
    int pobierzZPlikuIdOstatniegoAdresata();
};

#endif
