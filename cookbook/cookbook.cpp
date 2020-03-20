//
// Created by Andrei on 3/19/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "cookbook.h"
#include "../parser.h"
#include "../ingredient/ingredient.h"

#define EXC_INGREDIENT_EXISTS 1
#define EXC_INGREDIENT_NFOUND 2

// functions to get object attributes
bool cookbook::wasModified() {
    return modified;
}

void cookbook::listIngredients() {
    for(auto& i: ingredients)
        cout << "Name: " << i.getName() << " | Price: " << i.getPrice() << '\n';
}
// TODO: add ingredient removal & saving on exit
void cookbook::initialise() {
    ifstream ingFile("../ingredient/ingredients.txt");
    string line;
    while(getline(ingFile, line)) {
        vector<string> res = strparse(line, '|');
        try {
            ingredient ing = ingredient(res[0], stoi(res[1]));
            cout << ing.getName() << ' ';
            addIngredient(ingredient(res[0], stoi(res[1])));
        } catch(int exception) {
            continue;
        }
    }
}

void cookbook::deleteIngredient(const string& s) {
    bool deleted = 0;
    for(auto i = ingredients.begin(); i < ingredients.end(); i++)
        if((*i).getName() == s) {
            ingredients.erase(i);
            modified = 1;
            deleted = 1;
        }

    if(!deleted) throw EXC_INGREDIENT_NFOUND;
}

void cookbook::addIngredient(const ingredient &a, bool duringRun) {
    for(auto& i: ingredients)
        if(i == a) throw EXC_INGREDIENT_EXISTS;
    ingredients.push_back(a);
    if(duringRun) modified = 1;
}

void cookbook::save() {
    ofstream ingFile("../ingredient/ingredients.txt");
    string wrt;
    cout << "Saving...";
    for(auto& i: ingredients)
        wrt += i.getName() + "|" + to_string(i.getPrice()) + "\n";
    
    ingFile << wrt;
}