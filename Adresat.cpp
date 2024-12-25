#include "Adresat.h"

    void Adresat::ustawIDAdreesata(int noweID)
    {
        if (noweID >= 0)
        idAdresata = noweID;
    }

    void Adresat::ustawImie(string noweImie)
    {
        imie = noweImie;
    }

    void Adresat::ustawNazwisko(string noweNazwisko)
    {
        nazwisko = noweNazwisko;
    }

    void Adresat::ustawNumerTelefonu(string nowyNumerTel)
    {
        numerTelefonu = nowyNumerTel;
    }

    void Adresat::ustawEmail(string nowyEmail)
    {
        email = nowyEmail;
    }

    void Adresat::ustawAdres(string nowyAdres)
    {
        adres = nowyAdres;
    }

    int Adresat::pobierzIDAdresata()
    {
        return idAdresata;
    }

    string Adresat::pobierzImie()
    {
        return imie;
    }

    string Adresat::pobierzNazwisko()
    {
        return nazwisko;
    }

    string Adresat::pobierzNumerTelefonu()
    {
        return numerTelefonu;
    }

    string Adresat::pobierzEmail()
    {
        return email;
    }

    string Adresat::pobierzAdres()
    {
        return adres;
    }
