//
// Created by Andrei on 3/19/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "cookbook.h"
#include "../explode.h"
#include "../ingredient/ingredient.h"
#define EXC_INGREDIENT_EXISTS 1

// TODO: add ingredient removal & saving on exit
void cookbook::initialise() {
    ifstream ingFile("../ingredient/ingredients.txt");
    string line;
    while(getline(ingFile, line)) {
        vector<string> res = strparse(line, '|');
        try {
            ingredient ing = ingredient(res[0], stoi(res[1]));
            cout << ing.getName() << ' ';
            this->addIngredient(ingredient(res[0], stoi(res[1])));
        } catch(int exception) {
            continue;
        }
    }
}

void cookbook::addIngredient(const ingredient &a) {
    for(auto& i: ingredients)
        if(i == a) throw EXC_INGREDIENT_EXISTS;
    this->ingredients.push_back(a);
}

void cookbook::listIngredients() {
    for(auto& i: ingredients)
         cout << "Name: " << i.getName() << " | Price: " << i.getPrice() << '\n';
}

