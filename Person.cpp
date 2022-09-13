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

int Person::setID(int ID) {
    this->ID = ID;
}

int Person::getID() {
    return this->ID;
}

int Person::counter = 0;

int Person::getCounter() {
    return counter;
}

Person::~Person() {}

string Person::getName() {
    return this->name;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getSurname() {
    return this->surname;
}

void Person::setSurname(string surname) {
    this->surname = surname;
}

short int Person::getAge() {
    return this->age;
}

void Person::setAge(int age) {
    this->age = age;
}

string Person::getPhoneNumber() {
    return this->phoneNumber;
}

void Person::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

Person Person::operator=(Person obj) {

    this->setName(obj.getName());
    this->setSurname(obj.getSurname());
    this->setPhoneNumber(obj.getPhoneNumber());
    this->setAge(obj.getAge());
    return obj;
}

template <> //ToDo template specialization
string Person::get<option::name>() {
    string s = getName();
    transform(s.begin(), s.end(), s.begin(), ::tolower); //zamiana na male znaki
    return s;
}

template <>
string Person::get<option::surname>() {
    string s = getSurname();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

template <>
string Person::get<option::phoneNumber>() {
    return getPhoneNumber();
}

template <>
short int Person::get<option::age>() {
    return getAge();
}

template <>
int Person::get<option::ID>() {
    return getID();
}