//
// Created by mharc on 16.09.2022.
//

#include "Show.h"

void show_persons(vector <Person> &people) {


    if (people.size()) {
        cout << PURPLE << " ID | NAME | SURNAME | PHONE | AGE" << endl << YELLOW;

        for (int i = 0; i < people.size(); i++) {
            cout << people[i].get_ID() << " | " << people[i].get_name()
                 << " | " << people[i].get_surname()
                 << " | " << people[i].get_phone_number()
                 << " | " << people[i].get_age() << endl;
        }
    } else
        cout << "THE BASE IS EMPTY!!!" << endl;

}