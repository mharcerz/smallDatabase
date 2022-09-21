//
// Created by mharc on 16.09.2022.
//

#include "Search.h"

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
} //https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed

template<option p, typename T2>
bool compare(Person person, T2 arg) {
    return person.get<p, T2>() == arg; //calling overloaded get() functions
}

template<typename T2, option p> //ToDo auto
void search(T2 arg, vector<Person> &people) {
    cout << " ID | NAME | SURNAME | PHONE | AGE" << endl;
    for (int i = 0; i < people.size(); i++) {
        if (compare<p, T2>(people[i], arg)) { //calling T2 function inside compare() function
            cout << people[i].get_ID() << " | " << people[i].get_name() << " | "
                 << people[i].get_surname() << " | " << people[i].get_phone_number()
                 << " | " << people[i].get_age() << endl;
        }
    }
}

int searching_menu() {
    char  option;

    cout << "Search with:" << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "3. Surname" << endl;
    cout << "4. Phone Number" << endl;
    cout << "5. Age" << endl;

    option = getch();
//    option = '1'; //ToDo remove!!!
    return static_cast<int>(option) - 48;
}

void searching_base(vector<Person> &people) {
    if (people.size()) {
        switch (searching_menu()) {
            case option::ID: {
                int id;

                cout << "Enter the ID you want to search by:";
                cin >> id;
                cin.ignore();
                if (id > Person::get_counter())
                    cout << "There is no such ID!" << endl;
                else search<int, option::ID>(id, people);
                break;
            }
            case option::name: {
                string name;

                cout << "Enter the NAME you want to search by:";
                cin >> name;
                cin.ignore();
                transform(name.begin(), name.end(), name.begin(), ::tolower); //transform string to lowercase
                search<string, option::name>(name, people);
                break;
            }
            case option::surname: {
                string surname;

                cout << "Enter the SURNAME you want to search by:";
                cin >> surname;
                cin.ignore();
                transform(surname.begin(), surname.end(), surname.begin(), ::tolower); //transform string to lowercase
                search<string, option::surname>(surname, people);
                break;
            }
            case option::phone_number: {
                string phone_number;

                cout << "Enter the PHONE NUMBER you want to search by:";
                cin >> phone_number;
                cin.ignore();
                search<string, option::phone_number>(phone_number, people);
                break;
            }
            case option::age: {
                short int age;

                cout << "Enter the AGE you want to search by:";
                cin >> age;
                cin.ignore();
                search<short int, option::age>(age, people);
                break;
            }
            default:
                cout << "You entered a wrong value." << endl;
                break;
        }
    } else
        cout << "The base is empty, there is nothing to look for there." << endl;
}

