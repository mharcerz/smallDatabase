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

void requireEnter();

char menu();

void addPerson();

void showPersons();

void saveToFile();

int readFromFile();

int searchingMenu();

void searchingBase();

void removePerson();

template<option, typename T2>
bool compare(Person, T2);

template<typename T2, option>
void search(T2);


int main() {

    readFromFile();
    while (menu() != action::esc); //27 to w ASCII znak enter
    saveToFile();
    return EXIT_SUCCESS;
}

char menu() {

    int * option = new int;
    cout << GREEN;
    cout << "People in the base: " << people.size() << endl;
    cout << CYAN << "Press Esc to exit!" << endl;
    cout << WHITE;
    cout << "MENU:" << endl;
    cout << "1. Add a Person." << endl;
    cout << "2. Show Persons." << endl;
    cout << "3. Search the base. " << endl;
    cout << "4. Remove the person from the base." << endl;

    *option = static_cast<int> (getch()) - 48; // pobiera wartosc bez potwierdzenie enterem
    switch (*option) {

        case action::add:
            addPerson();
            break;
        case action::show:
            showPersons();
            break;
        case action::searchA:
            searchingBase();
            break;
        case action::erase:
            removePerson();
            break;
        case action::esc:
            return esc;
        default:
            break;

    }
    requireEnter();
    return *option;
    delete option;
}

void requireEnter() {

    cout << RED;
    cout << "Press Enter to continue" << endl;
    while (getch() != '\n'); //enter to 13 w ASCII
    system("clear");

}

void addPerson() {
    Person *person = new Person();
    char *data = new char;

    cout << "Name: ";
    cin >> data;
    person->setName(data);

    cout << "Surname: ";
    cin >> data;
    person->setSurname(data);

    cout << "Phone Number: ";
    cin >> data;
    person->setPhoneNumber(data);
    delete data;

    int *age = new int;
    cout << "Age: ";
    cin >> *age;
    person->setAge(*age);

    people.push_back(*person);

    delete person;
    delete age;
}

void showPersons() {

    if (people.size()) {
        cout << PURPLE;
        cout << " ID | NAME | SURNAME | PHONE | AGE" << endl;
        cout << YELLOW;
        for (int i = 0; i < people.size(); i++) {
            cout << people[i].getID() << " | " << people[i].getName() << " | " << people[i].getSurname()
                 << " | " << people[i].getPhoneNumber() << " | " << people[i].getAge() << endl;
        }
    } else
        cout << "THE BASE IS EMPTY!!!" << endl;
}

void saveToFile() {
    ofstream file("./base.txt");

    if (file.is_open()) {
        for (int i = 0; i < people.size() - 1; i++) {
            file << people[i].getName() << "," << people[i].getSurname() << "," << people[i].getPhoneNumber()
                 << "," << people[i].getAge() << endl;
        }
        file << people[people.size() - 1].getName() << "," << people[people.size() - 1].getSurname() << ","
             << people[people.size() - 1].getPhoneNumber()
             << "," << people[people.size() - 1].getAge();
        file.close();
    } else
        cout << "The file did not open properly." << endl;
}

int readFromFile() {

    ifstream file("./base.txt");
    file.seekg(0, ios::end);
    int *file_size = new int;
    *file_size = file.tellg();
    file.seekg(0, ios::beg);
    if (file_size > 0) {
        if (file.is_open()) {
            int *i = new int;
            while (!file.eof()) {
                Person *person = new Person();
                char *dane = new char;
                file >> dane;
                char *tmp = strtok(dane, ",");
                *i = 1;
                while (tmp != NULL) {
                    switch ((*i) + 1) {
                        case option::name:
                            person->setName(tmp);
                            break;
                        case option::surname:
                            person->setSurname(tmp);
                            break;
                        case option::phoneNumber:
                            person->setPhoneNumber(tmp);
                            break;
                        case option::age:
                            person->setAge(atoi(tmp)); //konwersja char* do int
                            break;
                        default:
                            break;
                    }
                    tmp = strtok(NULL, ",");
                    (*i)++;
                }

                people.push_back(*person);

                delete dane;
                delete tmp;
                delete person;

            }
            delete i;
            file.close();
        } else
            cout << CYAN << "The file did not open properly." << endl;
    } else
        cout << BLUE << "THE BASE IS EMPTY!" << endl;
    delete file_size;
    showPersons();
    requireEnter();
}

int searchingMenu() {
    cout << "Search with:" << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "3. Surname" << endl;
    cout << "4. Phone Number" << endl;
    cout << "5. Age" << endl;

    char c = getch();
    return static_cast<int>(c) - 48;
}

void searchingBase() {
    if (people.size()) {
        switch (searchingMenu()) {
            case option::ID: {
                cout << "Enter the ID you want to search by:";
                int *id = new int;
                cin >> *id;
                cin.ignore();
                if (*id > Person::getCounter())
                    cout << "There is no such ID!" << endl;
                else search<int, option::ID>(*id);
                delete id;
                break;
            }
            case option::name: {
                cout << "Enter the NAME you want to search by:";
                string name;
                cin >> name;
                cin.ignore();
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                search<string, option::name>(name);
                break;
            }
            case option::surname: {
                cout << "Enter the SURNAME you want to search by:";
                string surname;
                cin >> surname;
                cin.ignore();
                transform(surname.begin(), surname.end(), surname.begin(), ::tolower);
                search<string, option::surname>(surname);
                break;
            }
            case option::phoneNumber: {
                cout << "Enter the PHONE NUMBER you want to search by:";
                char *phoneNumber = new char;
                cin >> phoneNumber;
                cin.ignore();
                search<string, option::phoneNumber>(phoneNumber);
                delete phoneNumber;
                break;
            }
            case option::age: {
                cout << "Enter the AGE you want to search by:";
                short int age;
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
            cout << people[i].getID() << " | " << people[i].getName() << " | " << people[i].getSurname()
                 << " | " << people[i].getPhoneNumber() << " | " << people[i].getAge() << endl;
        }
    }
}

void removePerson() //ToDo trzeba jeszcze nadac na nowo id
{
    if(people.size() > 0) {
        cout << "Enter the ID of the person you want to remove:" << endl;
        int * id = new int;
        cin >> *id;
        cin.ignore();
        Person person;
        for ( int i=(*id)-1; i<people.size()-1; i++) {
            people[i] = people[i+1];
        }
        people.pop_back();
        delete id;
        system("clear");
        cout << "New table:" << endl;
        showPersons();

    }
    else cout << "The Base is empty. You cannot remove." << endl;
}