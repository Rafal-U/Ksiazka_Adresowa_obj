#include <iostream>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while(true)
    {
        char wyborGlowny;
        wyborGlowny = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

        switch(wyborGlowny)
        {
        case '1':
            ksiazkaAdresowa.zarejestrujUzytkownika();
            break;
        case '2':
            ksiazkaAdresowa.zalogujUzytkownika();
            ksiazkaAdresowa.zarzadzajAdresatami();
            break;
        case '3':
            ksiazkaAdresowa.zamknijProgram();
        default:
            system("cls");
            cout << "Nie ma takiej opcji, wybierz ponownie" << endl;
            Sleep(2000);
        }
    }

    return 0;
}
