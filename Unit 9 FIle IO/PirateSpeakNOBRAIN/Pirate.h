#ifndef PIRATE_H
#define PIRATE_H

#include <sstream>
#include <fstream>

#include <string>
using namespace std;

class Pirate {
    public:
    string translateWord(string);
    string translateSentence(string);

    void addToFile(string, string);
};

#endif //PIRATE_H