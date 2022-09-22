//
// Created by mharc on 16.09.2022.
//

#ifndef SMALLDATABASE_MENU_H
#define SMALLDATABASE_MENU_H

#include "Add.h"
#include "Search.h"
#include "Remove.h"
#include "Show.h"
#include "Person.h"

using namespace std;

enum action {
    add = 1, show, searchA, erase, esc = -21
};  //27 - 48(cast from char to int)

char menu(vector <Person> &);
void require_enter();

#endif //SMALLDATABASE_MENU_H
