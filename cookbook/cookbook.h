//
// Created by Andrei on 3/19/2020.
//

#ifndef COOKBOOK_CI_COOKBOOK_H
#define COOKBOOK_CI_COOKBOOK_H

#include <vector>
#include "../ingredient/ingredient.h"

using namespace std;
class cookbook {
    private:
        vector<ingredient> ingredients;
        bool modified;
    public:
        void initialise();
        void addIngredient(const ingredient &a, bool duringRun = 0);
        void deleteIngredient(const string& s);
        void listIngredients();
        bool wasModified();
        void save();

};


#endif //COOKBOOK_CI_COOKBOOK_H
