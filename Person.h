//
// Created by mharc on 03.08.2022.
//

#ifndef SMALLDATABASE_PERSON_H
#define SMALLDATABASE_PERSON_H
enum option {ID = 1, name, surname, phone_number, age};
using namespace std;
#include <string>
class Person {
private:
    int ID;
    static int counter;
    string name;
    string surname;
    short int age;
    string phone_number;
    int set_ID(int);
public:
    Person();
    ~Person();
    int get_ID();
    static int get_counter();
    string get_name();
    void set_name(string);
    string get_surname();
    void set_surname(string);
    short int get_age();
    void set_age(int);
    string get_phone_number();
    void set_phone_number(string);
    Person operator=(Person);

    template <option p, typename T>
    T get();


};

#endif SMALLDATABASE_PERSON_H

