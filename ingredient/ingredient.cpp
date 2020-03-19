//
// Created by Andrei on 3/19/2020.
//
#include <string>
#include "ingredient.h"
using namespace std;
void ingredient::changeName(const string &s) {
    this->name = s;
}

string ingredient::getName() {
    return this->name;
}

int ingredient::getPrice() {
    return this->price;
}