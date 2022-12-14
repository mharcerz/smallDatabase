//
// Created by mharc on 16.09.2022.
//

#ifndef SMALLDATABASE_SHOW_H
#define SMALLDATABASE_SHOW_H

#include <iostream>
#include <vector>

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

void show_persons(vector <Person> &);

#endif //SMALLDATABASE_SHOW_H
