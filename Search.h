//
// Created by mharc on 16.09.2022.
//

#ifndef SMALLDATABASE_SEARCH_H
#define SMALLDATABASE_SEARCH_H
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <vector>
#include "Person.h"

using namespace std;

void searching_base(vector<Person> &);

template<option, typename T2>
bool compare(Person, T2);

template<typename T2, option>
void search(T2, vector<Person> &);

int searching_menu();

#endif //SMALLDATABASE_SEARCH_H
