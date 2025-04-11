#include "Element.h"

#include <sstream>
#include <fstream>
#include <iostream>

#include <string>
using namespace std;

Element::Element() {
    name = "";
    symbol = "";
    number = "0";
    mass = "0.0";
}

Element::Element(string &nameIn, string &symbolIn, string &numberIn, string &massIn) {
    name = nameIn;
    symbol = symbolIn;
    number = numberIn;
    mass = massIn;
}

void Element::searchByNum(const string& input) {
    ifstream fin ("/home/snoutibur/CLionProjects/Unit9Lab/elements.csv", ios::in);

    while(!fin.eof()) {
        getline(fin, number, ',');
        getline(fin, name, ',');
        getline(fin, symbol, ',');
        getline(fin, mass, '\n');
        if(mass.find('\r') != string::npos) {
            mass = mass.substr(0,mass.find('\r')-1);
        }

        if(input == number) {
            fin.close();
            return;
        }
    }

    cout << "ELEMENT NO EXIST D:\n";
}

void Element::searchBySymbol(const string& input) {
    ifstream fin ("/home/snoutibur/CLionProjects/Unit9Lab/elements.csv", ios::in);

    while(!fin.eof()) {
        getline(fin, number, ',');
        getline(fin, name, ',');
        getline(fin, symbol, ',');
        getline(fin, mass, '\n');
        if(mass.find('\r') != string::npos) {
            mass = mass.substr(0,mass.find('\r')-1);
        }
        
        if(input == symbol) {
            fin.close();
            return;
        }
    }

    cout << "ELEMENT NO EXIST D:\n";
}

ostream &operator << (ostream &out, const Element &e) {
    out << "Symbol: " << e.symbol << endl;
    out << "Element: " << e.name << endl;
    out << "Atomic #:" << e.number << endl;
    out << "Mass: " << e.mass << endl;

    return out;
}