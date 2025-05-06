#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

using std::vector;
using std::string;

class game {
    public:
        static vector<string> wordlistParser(string pathToWordList);
        static map<char, vector<int>> parseWord(char guess, string target);
};

#endif