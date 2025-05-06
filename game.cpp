#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "game.h"

using std::vector;
using std::string;
using std::map;

vector<int> seek(char guess, string target) {
    /*
        Find the indices of guess in target. Return an empty vector if not found.
    */
    vector<int> output;

    string temp(1, guess);
    for(int i; i < target.length(); i++) {
        if(target[i] == temp) {
            output.push_back(i);
        } 
    }
    return output;
}

vector<string> game::wordlistParser(string pathToWordList) {
    vector<string> output;
    std::ifstream input(pathToWordList);
    
    std::string line;
    std::getline(input, line);
    input.close();

    vector<char> temp = {'[', ']', '\"'};
    for(char i : temp) {
        line.erase(std::remove(line.begin(), line.end(), i), line.end());
    }

    string temp2;
    for(char& i : line) {
        string j(1, i);
        if(j == ",") {
            output.push_back(temp2);
            temp2 = "";
            continue;
        }
        temp2.append(j);
    }
    return output;
}

map<char, vector<int>> game::parseWord(char guess, string target) {
    map<char, vector<int>> output;
    output[guess] = seek(guess, target);
    return output;
}