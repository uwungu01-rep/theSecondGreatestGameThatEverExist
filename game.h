#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::map;

class game {
    public:
        static vector<string> wordlistParser(string pathToWordList);
        static map<char, vector<int>> parseWord(char guess, string target);
        static void clear();
};

#endif