#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::zarejestrujUzytkownika()
{
    uzytkownikMenedzer.zarejestrujUzytkownika();
}


void KsiazkaAdresowa::zalogujUzytkownika()
{
    uzytkownikMenedzer.zalogujUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
       adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}


void KsiazkaAdresowa::zamknijProgram()
{
    system("cls");
    cout << "Trwa zamykanie programu" << endl;
    Sleep(2000);
    exit(0);
}


void KsiazkaAdresowa::zarzadzajAdresatami()
{
    char wybranaOpcja;

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        while(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        {
            wybranaOpcja = uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
            switch(wybranaOpcja)
            {
            case '1':
                adresatMenedzer ->dodajAdresata(); break;
            case '2':
                adresatMenedzer ->wyszukajAdresatowPoImieniu(); break;
            case '3':
                adresatMenedzer ->wyszukajAdresatowPoNazwisku(); break;
            case '4':
                adresatMenedzer ->wyswietlWszystkichAdresatow(); break;
            case '5':
                adresatMenedzer ->usunAdresata(); break;
            case '6':
                adresatMenedzer ->edytujAdresata(); break;
            case '7':
                uzytkownikMenedzer.zmienHasloZalogowanegoUzytkownika(); break;
            case '8':
                uzytkownikMenedzer.wylogujUzytkownika();
                delete adresatMenedzer; adresatMenedzer = NULL; break;
            default:
                cout << "Nie ma takiej opcji. Wybierz ponownie." << endl;
                Sleep(2000); break;
            }
        }
    }
}
