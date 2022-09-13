//
// Created by mharc on 03.08.2022.
//

#ifndef SMALLDATABASE_PERSON_H
#define SMALLDATABASE_PERSON_H
enum option {ID = 1, name, surname, phoneNumber, age};
using namespace std;
#include <string>
class Person {
private:
    int ID;
    static int counter;
    string name;
    string surname;
    short int age;
    string phoneNumber;
    int setID(int);
public:
    Person();
    ~Person();
    int getID();
    static int getCounter();
    string getName();
    void setName(string);
    string getSurname();
    void setSurname(string);
    short int getAge();
    void setAge(int);
    string getPhoneNumber();
    void setPhoneNumber(string);
    Person operator=(Person);

    template <option p, typename T>
    T get();


};

#endif SMALLDATABASE_PERSON_H

