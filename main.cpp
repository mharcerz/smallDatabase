#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include "Person.h" //ToDo dowiedz sie czym jest auto!!!
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

#define BLACK "\033[0;30m"
#define RED  "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

using namespace std;
vector <Person> people;

enum action {
    add = 1, show, searchA, erase, esc = -21
};  //27 - 48(cast z char do int)

void require_enter();

char menu();

void add_person();

void show_persons();

void save_to_file();

int read_from_file();

int searching_menu();

void searching_base();

void remove_person();

template<option, typename T2>
bool compare(Person, T2);

template<typename T2, option>
void search(T2);


int main() {

    read_from_file();
    while (menu() != action::esc); //27 to w ASCII znak enter
    save_to_file();
    return EXIT_SUCCESS;
}

char menu() {
    int option;

    cout << GREEN;
    cout << "People in the base: " << people.size() << endl;
    cout << CYAN << "Press Esc to exit!" << endl;
    cout << WHITE;
    cout << "MENU:" << endl;
    cout << "1. Add a Person." << endl;
    cout << "2. Show Persons." << endl;
    cout << "3. Search the base. " << endl;
    cout << "4. Remove the person from the base." << endl;

    option = static_cast<int> (getch()) - 48; // pobiera wartosc bez potwierdzenie enterem
    switch (option) {

        case action::add:
            add_person();
            break;
        case action::show:
            show_persons();
            break;
        case action::searchA:
            searching_base();
            break;
        case action::erase:
            remove_person();
            break;
        case action::esc:
            return esc;
        default:
            break;

    }
    require_enter();
    return option;
}

void require_enter() {

    cout << RED;
    cout << "Press Enter to continue" << endl;
    while (getch() != '\n'); //enter to 13 w ASCII
    system("clear");
}

void add_person() {
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

void show_persons() {

    if (people.size()) {
        cout << PURPLE << " ID | NAME | SURNAME | PHONE | AGE" << endl << YELLOW;

        for (int i = 0; i < people.size(); i++) {
            cout << people[i].get_ID() << " | " << people[i].get_name() << " | " << people[i].get_surname()
                 << " | " << people[i].get_phone_number() << " | " << people[i].get_age() << endl;
        }
    } else
        cout << "THE BASE IS EMPTY!!!" << endl;
}

void save_to_file() {
    ofstream file("./base.txt");

    if (file.is_open()) {
        for (int i = 0; i < people.size() - 1; i++) {
            file << people[i].get_name() << "," << people[i].get_surname()
                << "," << people[i].get_phone_number() << "," << people[i].get_age() << endl;
        }
        file << people[people.size()-1].get_name() << "," << people[people.size()-1].get_surname()
            << "," << people[people.size()-1].get_phone_number() << "," << people[people.size()-1].get_age();

        file.close();
    } else
        cout << "The file did not open properly." << endl;
}

int read_from_file() {
    ifstream file("./base.txt");
    int file_size;

    file.seekg(0, ios::end);
    file_size = file.tellg();
    file.seekg(0, ios::beg);

    if (file_size > 0) {
        if (file.is_open()) {


            while (!file.eof()) {
                Person person;
                char * data = new char; // tu tak musi byc
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
                            person.set_age(atoi(tmp)); //konwersja char* do int
                            break;
                        default:
                            break;
                    }
                    tmp = strtok(NULL, ",");
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

    show_persons();
    require_enter();
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
    return static_cast<int>(option) - 48;
}

void searching_base() {
    if (people.size()) {
        switch (searching_menu()) {
            case option::ID: {
                int id;

                cout << "Enter the ID you want to search by:";
                cin >> id;
                cin.ignore();
                if (id > Person::get_counter())
                    cout << "There is no such ID!" << endl;
                else search<int, option::ID>(id);
                break;
            }
            case option::name: {
                string name;

                cout << "Enter the NAME you want to search by:";
                cin >> name;
                cin.ignore();
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                search<string, option::name>(name);
                break;
            }
            case option::surname: {
                string surname;

                cout << "Enter the SURNAME you want to search by:";
                cin >> surname;
                cin.ignore();
                transform(surname.begin(), surname.end(), surname.begin(), ::tolower);
                search<string, option::surname>(surname);
                break;
            }
            case option::phone_number: {
                string phone_number;

                cout << "Enter the PHONE NUMBER you want to search by:";
                cin >> phone_number;
                cin.ignore();
                search<string, option::phone_number>(phone_number);
                break;
            }
            case option::age: {
                short int age;

                cout << "Enter the AGE you want to search by:";
                cin >> age;
                cin.ignore();
                search<short int, option::age>(age);
                break;
            }
            default:
                cout << "You entered a wrong value." << endl;
                break;
        }
    } else
        cout << "The base is empty, there is nothing to look for there." << endl;
}

template<option p, typename T2>
bool compare(Person person, T2 arg) {
    return person.get<p, T2>() == arg;
}

template<typename T2, option p> //ToDo auto
void search(T2 arg) {

    cout << " ID | NAME | SURNAME | PHONE | AGE" << endl;
    for (int i = 0; i < people.size(); i++) {
        if (compare<p, T2>(people[i], arg)) {
            cout << people[i].get_ID() << " | " << people[i].get_name() << " | " << people[i].get_surname()
                 << " | " << people[i].get_phone_number() << " | " << people[i].get_age() << endl;
        }
    }
}

void remove_person() {

    if(people.size() > 0) {
        int i;

        cout << "Enter the ID of the person you want to remove:" << endl;
        cin >> i;
        cin.ignore();
        if (i > Person::get_counter())
            cout << "There is no such ID!" << endl;
        else {
            for (i--; i < people.size() - 1; i++)
                people[i] = people[i + 1];

            people.pop_back();
            system("clear");
            cout << "New table:" << endl;
            show_persons();
        }
    }
    else cout << "The Base is empty. You cannot remove." << endl;
}