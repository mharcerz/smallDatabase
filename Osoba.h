//
// Created by mharc on 03.08.2022.
//

#ifndef SMALLDATABASE_OSOBA_H
#define SMALLDATABASE_OSOBA_H
enum pole {ID = 1, imie, nazwisko, wiek, telefon};
using namespace std;
#include <string>
class Osoba {
private:
    int ID;
    static int counter;
    string imie;
    string nazwisko;
    short int wiek;
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

    template <pole p, typename T>
    T get();


};






//template <>
//auto Osoba::get<pole::wiek>() {
//    return getWiek();
//}

//template <>
//auto Osoba::get<pole::ID>() {
//    return getID();
//}

//template <pole T, typename T2>
//T2 Osoba::get() {
//
////    pole pol;
//    switch (T) {
////        case ID:
////            return static_cast<string> (getID());
////            break;
//        case pole::imie:
//            return getImie();
//            break;
//        case pole::nazwisko:
//            return getNazwisko();
//            break;
//        case pole::wiek:
//            return getWiek();
//            break;
//        case pole::telefon:
//            return getTelefon();
//            break;
//        default:
//            break;
//    }
//}

#endif SMALLDATABASE_OSOBA_H

