#include "FileOperations.h" //ToDo dowiedz sie czym jest auto!!!
#include "Menu.h"
using namespace std;
vector <Person> people;

int main() {

    ios_base::sync_with_stdio(0);

    read_from_file(people);
    while (menu(people) != action::esc);
    save_to_file(people);

    return EXIT_SUCCESS;
}



