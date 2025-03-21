#include "PlikZAdresatami.h"

void PlikZAdresatami::ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata)
{
    if (idOstatniegoAdresata >= 0)
        idOstatniegoAdresata = noweIdOstatniegoAdresata;
}
int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector <Adresat> adresaci;
    Adresat adresat;
    fstream plikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}


bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwertujIntNaString(adresat.pobierzIDAdresata()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwertujIntNaString(adresat.pobierzIDUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwertujStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwertujStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}


Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIDAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIDUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


void PlikZAdresatami::uporzadkujPlikiPodczasEdytowaniaAdresata(Adresat edytowanyAdresat)
{
    fstream plik, plikTymczasowy;
    int numerLinii = 1, dlugoscLinii = 0, idAdresataZmienionego = 0;
    string linia = "", liniaEdytowanegoAdresata = "";

    idAdresataZmienionego = edytowanyAdresat.pobierzIDAdresata();
    plikTymczasowy.open("Adresaci_Tymczasowi.txt", ios::out);
    plik.open("Adresaci.txt", ios::in);
    if (plik.good() && plikTymczasowy.good())
    {
        while(getline(plik, linia))
        {
            dlugoscLinii = linia.length();
            if (idAdresataZmienionego != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(linia) && dlugoscLinii != 0)
            {
                if (numerLinii == 1)
                {
                    plikTymczasowy << linia;
                }
                else
                {
                    plikTymczasowy << endl << linia;
                }
                numerLinii++;
            }
            else
            {
                liniaEdytowanegoAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(edytowanyAdresat);
                if (numerLinii == 1)
                {
                    plikTymczasowy << liniaEdytowanegoAdresata;
                }
                else
                {
                    plikTymczasowy << endl << liniaEdytowanegoAdresata;
                }
                numerLinii++;
            }
        }
    }
    plikTymczasowy.close();
    plik.close();
    uaktualnijPlikiZAdresatami();
}


void PlikZAdresatami::uaktualnijPlikiZAdresatami()
{
    remove("Adresaci.txt");
    rename("Adresaci_Tymczasowi.txt", "Adresaci.txt");
}

void PlikZAdresatami::uporzadkujPlikiPodczasUsuwaniaAdresata(int idAdresataUsunietego)
{
    fstream plik, plikTymczasowy;
    int numerLinii = 1, dlugoscLinii = 0;
    string linia = "";
    plikTymczasowy.open("Adresaci_Tymczasowi.txt", ios::out);
    plik.open("Adresaci.txt", ios::in);
    if (plik.good() && plikTymczasowy.good())
    {
        while(getline(plik, linia))
        {
            dlugoscLinii = linia.length();
            if (idAdresataUsunietego != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(linia) && dlugoscLinii != 0)
            {
                if (numerLinii == 1)
                {
                    plikTymczasowy << linia;
                }
                else
                {
                    plikTymczasowy << endl << linia;
                }
                numerLinii++;
            }
        }
    }
    plikTymczasowy.close();
    plik.close();
    uaktualnijPlikiZAdresatami();
    if (idAdresataUsunietego == idOstatniegoAdresata)
    {
        idOstatniegoAdresata = pobierzZPlikuIdOstatniegoAdresata();
    }
}


int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
    int ostatnieID = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open("Adresaci.txt", ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        ostatnieID = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return ostatnieID;
}
