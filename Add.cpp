//
// Created by mharc on 16.09.2022.
//

#include "Add.h"
void add_person(vector<Person> &people) {
    Person person;
    string data;
    int age;

    cout << "Name: ";
    cin >> data;
    person.set_name(data);

    cout << "Surname: ";
    cin >> data;
    person.set_surname(data);

    cout << "Phone Number: ";
    cin >> data;
    person.set_phone_number(data);

    cout << "Age: ";
    cin >> age;
    person.set_age(age);

    people.push_back(person);
}
