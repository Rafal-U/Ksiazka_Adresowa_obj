#include "UzytkownikMenedzer.h"

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweID)
{
    idZalogowanegoUzytkownika = noweID;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << "Istnieje uzytkownik o takim loginie" << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::zarejestrujUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    Sleep(2000);
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login, haslo;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        cout << "Podaj login: " << endl;
        cin >> login; cin.sync();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: " << endl;
    cin >> haslo; cin.sync();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}


void UzytkownikMenedzer::zalogujUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}


bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0) return true;
    else return false;
}


void UzytkownikMenedzer::zmienHasloZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    int aktualneID = pobierzIdZalogowanegoUzytkownika();
    if (aktualneID > 0)
    {
        cout << "Podaj nowe haslo: ";
        noweHaslo = MetodyPomocnicze::wczytajLinie();

        for (int i = 0; i < uzytkownicy.size(); i++)
        {
            if (uzytkownicy[i].pobierzId() == aktualneID)
            {
                uzytkownicy[i].ustawHaslo(noweHaslo);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
}

void UzytkownikMenedzer::wylogujUzytkownika()
{
    ustawIdZalogowanegoUzytkownika(0);
}


char UzytkownikMenedzer::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}
