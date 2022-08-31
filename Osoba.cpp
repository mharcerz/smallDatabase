//
// Created by mharc on 03.08.2022.
//

#include "Osoba.h"
Osoba::Osoba() {
    counter++;
    ID = counter;
}

int Osoba::getID() {
    return this->ID;
}
int Osoba::counter = 0;
int Osoba::getCounter() {
    return counter;
}
Osoba::~Osoba() {}
string Osoba::getImie() {
    return this->imie;
}
void Osoba::setImie(string imie) {
    this->imie = imie;
}
void Osoba::setNazwisko(string nazwisko) {
    this->nazwisko = nazwisko;
}
string Osoba::getNazwisko() {
    return this->nazwisko;
}
void Osoba::setWiek(int wiek) {
    this->wiek = wiek;
}
short int Osoba::getWiek() {
    return this->wiek;
}
string Osoba::getTelefon() {
    return this->telefon;
}
void Osoba::setTelefon(string telefon) {
    this->telefon = telefon;
}