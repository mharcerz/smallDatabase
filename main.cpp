#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Osoba.h"
#include <cstring>
#include <cstdio>

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
enum exit {esc = 27};
void wymagajEnter();

char menu();

void dodajOsobe();

void pokazOsoby();

void zapiszDoPliku();

int odczytajZPliku();

void przeszukajBaze();

char menuSzukaj();

void szukaj(int, string);

void szukaj2(int, int);

//template<typename T>
void Szukaj(int val, string arg) {
    cout << " ID  |  IMIE  |  NAZWISKO  |  TELEFON  |  WIEK" << endl;
//    enum dzialanie {ID = 1, imie, nazwisko, telefon, wiek};

    for(int i = 0; i <ludzie.size(); i++)
    {
        if(ludzie[i].get(val) == arg) {
            cout << ludzie[i].getID() << " | " << ludzie[i].getImie() << " | " << ludzie[i].getNazwisko()
                 << " | " << ludzie[i].getTelefon() << " | " << ludzie[i].getWiek() << endl;
        }
    }
}

int main() {

    odczytajZPliku();
    while (menu() != esc); //27 to w ASCII znak enter


    return EXIT_SUCCESS;
}

char menu() {

    char tescior;
    cout << GREEN;
    cout << "Osob w bazie: " << ludzie.size() << endl;
    cout << CYAN << "Kliknij Esc zeby wyjsc!" << endl;
    cout << WHITE;
    cout << "MENU:" << endl;
    cout << "1. Dodaj osobe." << endl;
    cout << "2. Pokaz osoby." << endl;
    cout << "3. Zapisz do pliku." << endl;
    cout << "4. Przeszukaj baze. " << endl;

    tescior = getch(); // pobiera wartosc bez potwierdzenie enterem
    switch (tescior) {
        enum czynnosc {dodaj = 49, pokaz, zapisz, przeszukaj};
        case dodaj:
            dodajOsobe();
            break;
        case pokaz:
            pokazOsoby();
            break;
        case zapisz:
            zapiszDoPliku();
            break;
        case przeszukaj:
            przeszukajBaze();
            break;
        case esc:
            return esc;
        default:
            break;

    }
    wymagajEnter();
    return tescior;
}

void wymagajEnter() {
    cout << RED;
    cout << "Wcisnij Enter aby kontynuowac" << endl;
    while (getch() != '\n'); //enter to 13 w ASCII
    system("clear");

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

    delete osoba;
    delete dane;
    delete wiek;
}

void pokazOsoby() {
    cout << PURPLE;

    cout << YELLOW;
    if (ludzie.size()) {
        cout << " ID  |  IMIE  |  NAZWISKO  |  TELEFON  |  WIEK" << endl;
        for (int i = 0; i < ludzie.size(); i++) {
            cout << ludzie[i].getID() << " | " << ludzie[i].getImie() << " | " << ludzie[i].getNazwisko()
                 << " | " << ludzie[i].getTelefon() << " | " << ludzie[i].getWiek() << endl;
        }
    } else
        cout << "BRAK OSOB W BAZIE!!!" << endl;
    cout << WHITE;

}

void zapiszDoPliku() // czy jak plik nie istnieje to czy nie stworzy sie przy zapisie?
{
    ofstream file("./baza.txt");

    if (file.is_open()) {
        for (int i = 0; i < ludzie.size() - 1; i++) {
            file << ludzie[i].getImie() << "," << ludzie[i].getNazwisko() << "," << ludzie[i].getTelefon()
                 << "," << ludzie[i].getWiek() << endl;
        }
        file << ludzie[ludzie.size() - 1].getImie() << "," << ludzie[ludzie.size() - 1].getNazwisko() << ","
             << ludzie[ludzie.size() - 1].getTelefon()
             << "," << ludzie[ludzie.size() - 1].getWiek();
        file.close();
    } else
        cout << "Plik nie zostal otwarty poprawnie" << endl;

}

int odczytajZPliku() {

    ifstream file("./baza.txt");
    file.seekg(0, ios::end);
    int file_size = file.tellg();
    file.seekg(0, ios::beg);
    if (file_size > 0) {
        if (file.is_open()) {
            while (!file.eof()) {
                Osoba *osoba = new Osoba();
                char *dane = new char;
                file >> dane;
                char *tmp = strtok(dane, ",");
                int i = 1;
                while (tmp != NULL) {
                    enum odczyt { imie = 1, nazwisko, nr, wiek};
                    switch (i) {
                        case imie:
                            osoba->setImie(tmp);
                            break;
                        case nazwisko:
                            osoba->setNazwisko(tmp);
                            break;
                        case nr:
                            osoba->setTelefon(tmp);
                            break;
                        case wiek:
                            osoba->setWiek(atoi(tmp)); //konwersja char* do int
                            break;
                        default:
                            break;
                    }
                    tmp = strtok(NULL, ",");
                    i++;
                }

                ludzie.push_back(*osoba);

                delete dane;
                delete tmp;
                delete osoba;

            }
            file.close();
        } else
            cout << CYAN << "Plik nie zostal otwarty poprawnie" << endl;
    } else
        cout << BLUE << "Plik jest pusty!" << endl;

    pokazOsoby();
    wymagajEnter();
}

void przeszukajBaze() {
    if (ludzie.size()) {
        enum search { ID = 49, imie, nazwisko, wiek, nr};
        switch (menuSzukaj()) {
            case ID:
                break;
            case imie: {
                cout << "Podaj imie po ktorym chcesz szukac:";
                char * imie = new char;
                cin >> imie;
                cin.ignore();
//                szukaj(2, imie);
                Szukaj(2, imie);
                delete imie;
                break;
            }
            case nazwisko: {
                cout << "Podaj nazwisko po ktorym chcesz szukac:";
                char * nazwisko = new char;
                cin >> nazwisko;
                cin.ignore();
                Szukaj(3, nazwisko);
                delete nazwisko;
                break;
            }
            case wiek: {
                cout << "Podaj wiek po ktorym chcesz szukac:";
                int wiek;
                cin >> wiek;
                szukaj2(4, wiek);
                break;
            }
            case nr:
                break;
            default:
                cout << "Podales niewlasciwa wartosc" << endl;
                break;
        }
    } else
        cout << "Baza jest pusta, nie ma tam czego szukac" << endl;

}

void szukaj(int val, string imie) {

    cout << " ID  |  IMIE  |  NAZWISKO  |  TELEFON  |  WIEK" << endl;
    for (int i = 0; i < ludzie.size(); i++) {
        if (!strcasecmp( ludzie[i].getImie().c_str(), imie.c_str())) { //porownuje nie zwracajac uwagi na wielkosc znaku
            cout << ludzie[i].getID() << " | " << ludzie[i].getImie() << " | " << ludzie[i].getNazwisko()
                 << " | " << ludzie[i].getTelefon() << " | " << ludzie[i].getWiek() << endl;
        }
    }

}

void szukaj2(int val, int wiek) {

    cout << " ID  |  IMIE  |  NAZWISKO  |  TELEFON  |  WIEK" << endl;
    for (int i = 0; i < ludzie.size(); i++) {
        if (ludzie[i].getWiek() == wiek) {
            cout << ludzie[i].getID() << " | " << ludzie[i].getImie() << " | " << ludzie[i].getNazwisko()
                 << " | " << ludzie[i].getTelefon() << " | " << ludzie[i].getWiek() << endl;
        }
    }

}

char menuSzukaj() {
    cout << "Wzgledem czego chcesz przeszukac baze:" << endl;
    cout << "1. ID" << endl;
    cout << "2. Imie" << endl;
    cout << "3. Nazwisko" << endl;
    cout << "4. Wiek" << endl;
    cout << "5. Nr. telefonu" << endl;
    char c = getch();;
    return c;
}