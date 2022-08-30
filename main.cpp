#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include "Osoba.h"

#define BLACK "\033[0;30m"
#define RED  "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
using namespace std;
vector <Osoba> ludzie;

void wymagajEnter();

char menu();

void dodajOsobe();

void pokazOsoby();

int main() {

    system("clear");
    while (menu() != 27); //27 to w ASCII znak enter


    return EXIT_SUCCESS;
}

char menu() {

    char tescior;
    cout << GREEN;
    cout << "Osob w bazie: " << ludzie.size() << endl;
    cout << WHITE;
    cout << "MENU:" << endl;
    cout << "1. Dodaj osobe." << endl;
    cout << "2. Pokaz osoby." << endl;
    cout << "3. Zapisz do pliku." << endl;

    tescior = getch(); // pobiera wartosc bez potwierdzenie enterem
    switch (tescior) {
        case '1':
            dodajOsobe();
            break;
        case '2':
            pokazOsoby();
            break;
        case 27:
            return 27;
        default:
            break;

    }
    wymagajEnter();
    system("clear");

    return tescior;
}

void wymagajEnter() {
    cout << RED;
    cout << "Wcisnij Enter aby kontynuowac" << endl;
    while (getch() != '\n'); //enter to 13 w ASCII
}

void dodajOsobe() {
    Osoba *osoba = new Osoba();
    char *dane = new char;
    cout << "Podaj imie: ";
    cin >> dane;
    osoba->setImie(dane);
    cout << "Podaj nazwisko: ";
    cin >> dane;
    osoba->setNazwisko(dane);
    cout << "Podaj nr. telefonu: ";
    cin >> dane;
    osoba->setTelefon(dane);
    int *wiek = new int;

    cout << "Podaj wiek: ";
    cin >> *wiek;
    osoba->setWiek(*wiek);

    ludzie.push_back(*osoba);

    delete dane;
    delete wiek;


}

void pokazOsoby() {
    cout << PURPLE;

    cout << YELLOW;
    if (ludzie.size()) {
        cout << " ID  |  IMIE  |  NAZWISKO  |  WIEK  |  TELEFON  " << endl;
        for (int i = 0; i < ludzie.size(); i++) {
            cout << ludzie[i].getID() << " | " << ludzie[i].getImie() << " | " << ludzie[i].getNazwisko() << " | "
                 << ludzie[i].getWiek() << " | " << ludzie[i].getTelefon() << endl;
        }
    }
    else
        cout << "BRAK OSOB W BAZIE!!!" << endl;
    cout << WHITE;
}