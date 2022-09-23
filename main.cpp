#include "FileOperations.h"

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


int main() {

    ios_base::sync_with_stdio(0);

    read_from_file(people);

    while (menu(people) != action::esc);
    save_to_file(people);

    return EXIT_SUCCESS;
}



