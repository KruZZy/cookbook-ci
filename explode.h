//
// Created by Andrei on 3/20/2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> strparse(const string& source, char delim) {
    vector<string> result;
    stringstream ss(source);
    string temp;

    while(getline(ss, temp, delim)) {
        result.push_back(temp);
    }

    return result;
}