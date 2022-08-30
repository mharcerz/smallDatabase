//
// Created by mharc on 03.08.2022.
//

#ifndef SMALLDATABASE_OSOBA_H
#define SMALLDATABASE_OSOBA_H
using namespace std;
#include <string>
class Osoba {
private:
    int ID;
    static int counter;
    string imie;
    string nazwisko;
    int wiek;
    string telefon;
public:
    Osoba();
    ~Osoba();
    int getID();
    static int getCounter();
    string getImie();
    void setImie(string);
    string getNazwisko();
    void setNazwisko(string);
    short int getWiek();
    void setWiek(int);
    string getTelefon();
    void setTelefon(string);
};


#endif SMALLDATABASE_OSOBA_H
