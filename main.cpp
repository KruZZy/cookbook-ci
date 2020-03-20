#include <iostream>
#include <string>
#include <vector>
#include "cookbook/cookbook.h"

using namespace std;


#define MODE_SELECT 1
#define MODE_EXIT 2
#define MODE_INGREDIENT_ADD 3
#define MODE_INGREDIENT_SEE 4
#define MODE_INGREDIENT_DEL 5

vector<string> modes = {"select mode", "exit", "add an ingredient", "list ingredients", "delete an ingredient"};
cookbook C;
int main() {
    int mode = MODE_SELECT;
    C.initialise();
    while(mode != MODE_EXIT) { /// main loop
        if(mode == MODE_SELECT) {
            cout << "What do you want to do? Press:\n";
            for(int i = 1; i < modes.size(); i++)
                cout << i << ") " << modes[i] << '\n';
            int inp;
            cin >> inp;
            mode = inp+1;
        } else if(mode == MODE_INGREDIENT_ADD) {
            string name;
            int price;

            cout << "Give ingredient name: "; cin >> name;
            cout << "Give ingredient price: "; cin >> price;
            try {
                C.addIngredient(ingredient(name, price), true);
                mode = MODE_SELECT;
            } catch(int exception) {
                cout << "This ingredient already exists!\n";
            }

        } else if(mode == MODE_INGREDIENT_SEE) {
            C.listIngredients();
            mode = MODE_SELECT;
        } else if(mode == MODE_INGREDIENT_DEL) {
            string name;
            cout << "Give ingredient name:"; cin >> name;

            try {
                C.deleteIngredient(name);
                mode = MODE_SELECT;
            } catch(int exception) {
                cout << "Ingredient doesn't exist!";
            }
        }
    }

    if(C.wasModified())
        C.save();
    return 0;
}