//
// Created by mharc on 03.08.2022.
//
#include <algorithm>
#include "Person.h"
using namespace std;
#include <iostream>

Person::Person() {
    counter++;
    ID = counter;
}

int Person::set_ID(int ID) {
    this->ID = ID;
}

int Person::get_ID() {
    return this->ID;
}

int Person::counter = 0;

int Person::get_counter() {
    return counter;
}

Person::~Person() {}

string Person::get_name() {
    return this->name;
}

void Person::set_name(string name) {
    this->name = name;
}

string Person::get_surname() {
    return this->surname;
}

void Person::set_surname(string surname) {
    this->surname = surname;
}

short int Person::get_age() {
    return this->age;
}

void Person::set_age(int age) {
    this->age = age;
}

string Person::get_phone_number() {
    return this->phone_number;
}

void Person::set_phone_number(string phone_number) {
    this->phone_number = phone_number;
}

Person Person::operator=(Person obj) {
    if(obj.get_ID() == counter)
        counter--;
    this->set_name(obj.get_name());
    this->set_surname(obj.get_surname());
    this->set_phone_number(obj.get_phone_number());
    this->set_age(obj.get_age());
    return obj;
}


template <> //ToDo template specialization
string Person::get<option::name>() {
    string s = get_name();

    transform(s.begin(), s.end(), s.begin(), ::tolower); //zamiana na male znaki
    return s;
}

template <>
string Person::get<option::surname>() {
    string s = get_surname();

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

template <>
string Person::get<option::phone_number>() {
    return get_phone_number();
}

template <>
short int Person::get<option::age>() {
    return get_age();
}

template <>
int Person::get<option::ID>() {
    return get_ID();
}