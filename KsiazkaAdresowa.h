#include <iostream>
#include <vector>
#include "Uzytkownicy.h"
#include <windows.h>
using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    vector <Uzytkownik> uzytkownicy;

   Uzytkownik podajDaneNowegoUzytkownika();
   int pobierzIdNowegoUzytkownika();
   bool czyIstniejeLogin(string login);

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
