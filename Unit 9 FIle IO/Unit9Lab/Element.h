#ifndef PERIODICTABLE_H
#define PERIODICTABLE_H

#include <string>
using namespace std;

class Element {
public:
    Element();
    Element(string&, string&, string&, string&);

    void searchByNum(const string&);
    void searchBySymbol(const string&);

    friend ostream &operator << (ostream &, const Element&);
private:
    string name;
    string symbol;
    string number;
    string mass;
};

#endif //PERIODICTABLE_H
