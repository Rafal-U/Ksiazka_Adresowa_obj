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
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '2':
            ksiazkaAdresowa.logowanieUzytkownika();
            ksiazkaAdresowa.zarzadzajAdresatami();
            break;
        case '3':
            ksiazkaAdresowa.zamknijProgram();
        //case '0': ksiazkaAdresowa.wypiszWszystkichUzytkownikow(); system("pause"); break; //Opcja tymaczasowa do usuniecia
        default:
            system("cls");
            cout << "Nie ma takiej opcji, wybierz ponownie" << endl;
            Sleep(2000);
        }
    }

    return 0;
}
