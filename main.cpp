#include "FileOperations.h" //ToDo dowiedz sie czym jest auto!!!
//#include "Menu.h"
#include <conio.h>
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
void require_enter() {

    cout << RED;
    cout << "Press Enter to continue" << endl;
    while ( getch() != '\n');
    system("clear");
}
char menu(vector <Person> &people) {
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

    option = static_cast<int> (getch()) - 48; // taking ascii value without enter permission and cast to int
    switch (option) {

        case action::add:
            add_person(people);
            break;
        case action::show:
            show_persons(people);
            break;
        case action::searchA:
            searching_base(people);
            break;
        case action::erase:
            remove_person(people);
            break;
        case action::esc:
            return esc;
        default:
            break;

    }
    require_enter();
    return option;
}

int main() {

    ios_base::sync_with_stdio(0);

    read_from_file(people);

    while (menu(people) != action::esc);
    save_to_file(people);

    return EXIT_SUCCESS;
}



