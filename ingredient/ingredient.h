//
// Created by Andrei on 3/19/2020.
//
#include <string>

#ifndef COOKBOOK_CI_INGREDIENT_H
#define COOKBOOK_CI_INGREDIENT_H

using namespace std;

class ingredient {
    private:
        string name;
        int price;
    public:
        /**
        compares two ingredients a and b by price. returns the difference between the price of a and the price of b
        */
        int cmp(const ingredient& a, const ingredient& b) {
            return a.price - b.price;
        }
        /**
        we consider that two ingredients are equal if they have the same name
         */
        inline bool operator ==(const ingredient& b) {
            return this->name == b.name;
        }
        ingredient(const string& n, int p) {
            this->name = n;
            this->price = p;
        }

        void changeName(const string& s);
        string getName();
        int getPrice();
};


#endif //COOKBOOK_CI_INGREDIENT_H
