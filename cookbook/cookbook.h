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
    public:
        void initialise();
        void addIngredient(const ingredient& a);
        void listIngredients();
};


#endif //COOKBOOK_CI_COOKBOOK_H
