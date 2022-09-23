//
// Created by mharc on 16.09.2022.
//

#include "Remove.h"

void remove_person(vector<Person> &people) {

    show_persons(people);
    cout << WHITE;

    if(people.size() > 0) {
        int i;

        cout << "Enter the ID of the person you want to remove:" << endl;
        cin >> i;
        cin.ignore();
        if (i > Person::get_counter())
            cout << "There is no such ID!" << endl;
        else {
            for (i--; i < people.size() - 1; i++) {
                people[i] = people[i + 1]; // overload = in Person's class
            }
            people.pop_back();
            system("clear");
            cout << "New table:" << endl;
            show_persons(people);
        }
    }
    else cout << "The Base is empty. You cannot remove." << endl;
}