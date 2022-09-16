//
// Created by mharc on 16.09.2022.
//

#ifndef SMALLDATABASE_MENU_H
#define SMALLDATABASE_MENU_H

#include <conio.h>

#include "Add.h"
#include "Search.h"
#include "Remove.h"
#include "Show.h"
#include "Person.h"


#define BLACK "\033[0;30m"
#define RED  "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"


using namespace std;

enum action {
    add = 1, show, searchA, erase, esc = -21
};  //27 - 48(cast from char to int)

char menu(vector <Person> &);
void require_enter();

#endif //SMALLDATABASE_MENU_H
