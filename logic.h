#pragma once
#include <iostream>
#include <exception>
#include <windows.h>

using namespace std;

//ЗАВДАННЯ 1
#include <list>
void even(list<int>& lst) {
    for (auto& x : lst) {
        if(x<0)
        throw domain_error("Від'ємне значення");
}
    for (auto it = lst.begin(); it != lst.end(); ) {
        if (*it % 2 == 0) {
            it = lst.erase(it); 
        }
        else {
            ++it;
        }
    }
}


//ЗАВДАННЯ 2
#include <map>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;
map<int, vector<int>> readTSV(const string& );
void mergeData(map<int, vector<int>>& , const map<int, vector<int>>& );
map<int, double> calculateAverage(const map<int, vector<int>>& );
void saveToJson(const map<int, double>& , const string& );

