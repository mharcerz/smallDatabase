//
// Created by mharc on 16.09.2022.
//

#ifndef SMALLDATABASE_FILEOPERATIONS_H
#define SMALLDATABASE_FILEOPERATIONS_H
#include <fstream>
#include <cstring>
#include "Person.h"
#include "Show.h"
#include "Menu.h"



void save_to_file(vector<Person> &);
void read_from_file(vector<Person> &);

#endif //SMALLDATABASE_FILEOPERATIONS_H
