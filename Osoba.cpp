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

template <> //ToDo template specialization
string Osoba::get<pole::imie>() {
    return getImie();
}

template <>
string Osoba::get<pole::nazwisko>() {
    return getNazwisko();
}

template <>
string Osoba::get<pole::telefon>() {
    return getTelefon();
}
template <>
short int Osoba::get<pole::wiek>() {
    return getWiek();
}

template <>
int Osoba::get<pole::ID>() {
    return getID();
}


//string Osoba::get(int t) {
//    enum dzialanie {ID = 1, imie, nazwisko, wiek, telefon};
//    switch (t) {
////        case ID:
////            return static_cast<string> (getID());
////            break;
//        case imie:
//            return getImie();
//            break;
//        case nazwisko:
//            return getNazwisko();
//            break;
////        case wiek:
////            return static_cast<string> (getWiek()); //ToDo do ogarniecia na template
//        case telefon:
//            return getTelefon();
//            break;
////        default:
////            return static_cast<string> (EXIT_FAILURE);
////            break;
//    }
//    }