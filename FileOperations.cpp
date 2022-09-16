//
// Created by mharc on 16.09.2022.
//

#include "FileOperations.h"
void save_to_file(vector<Person> &people) {
    ofstream file("./base.txt");

    if (file.is_open()) {
        for (int i = 0; i < people.size() - 1; i++) {
            file << people[i].get_name() << "," << people[i].get_surname()
                 << "," << people[i].get_phone_number()
                 << "," << people[i].get_age() << endl;
        }
        file << people[people.size()-1].get_name() << ","
             << people[people.size()-1].get_surname() << ","
             << people[people.size()-1].get_phone_number()
             << "," << people[people.size()-1].get_age();

        file.close();
    } else
        cout << "The file did not open properly." << endl;
}

void read_from_file(vector<Person> &people) {
    ifstream file("./base.txt");
    int file_size;

    file.seekg(0, ios::end);
    file_size = file.tellg();
    file.seekg(0, ios::beg);

    if (file_size > 0) {
        if (file.is_open()) {


            while (!file.eof()) {
                Person person;
                char * data = new char; // pointer is essential (both)
                char * tmp = new char;
                int i;

                file >> data;
                tmp = strtok(data, ",");
                i = 1;
                while (tmp != NULL) {
                    switch (i + 1) {
                        case option::name:
                            person.set_name(tmp);
                            break;
                        case option::surname:
                            person.set_surname(tmp);
                            break;
                        case option::phone_number:
                            person.set_phone_number(tmp);
                            break;
                        case option::age:
                            person.set_age(atoi(tmp)); //cast char* to int
                            break;
                        default:
                            break;
                    }
                    tmp = strtok(NULL, ","); //split
                    i++;
                }

                people.push_back(person);

                delete data;
                delete tmp;
            }

            file.close();
        } else
            cout << CYAN << "The file did not open properly." << endl;
    } else
        cout << BLUE << "THE BASE IS EMPTY!" << endl;

    show_persons(people);
    require_enter();
}
