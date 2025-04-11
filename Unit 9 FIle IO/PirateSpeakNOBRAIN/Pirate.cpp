#include "Pirate.h"

#include <sstream>
#include <fstream>

#include <string>
using namespace std;

string Pirate::translateWord(string word) {
    ifstream fin("/home/snoutibur/CLionProjects/PirateSpeakNOBRAIN/pirate.csv", ios::in);
    string english, pirate;

    while (!fin.eof()) {
        getline(fin, english, ',');
        getline(fin, pirate, '\n');

        if (english == word) {
            fin.close();
            return pirate;
        }
    }
    fin.close();
    return word;
}

string Pirate::translateSentence(string input) {
    stringstream sentenceReader(input);
    string pirateEdition = "";

    while(sentenceReader.good()) {
        string temp;
        getline(sentenceReader, temp, ' ');
        pirateEdition += translateWord("hi") + " ";
    }

    return pirateEdition;
}

void Pirate::addToFile(string english, string pirate) {
    ofstream fout("/home/snoutibur/CLionProjects/PirateSpeakNOBRAIN/pirate.csv", ios::app);
    fout << endl << english << " " << pirate;
    fout.close();
}