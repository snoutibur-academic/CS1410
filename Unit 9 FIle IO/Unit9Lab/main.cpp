#include "Element.h"
#include <iostream>

using namespace std;

int main() {
    int choiceI;
    string choiceS;
    cout << "THE PERIODIC TABLE OF ELEMENTS: FOR NERDS!" << endl;

    do {
        cout << "1: Lookup by atomic number.\n2: Lookup by symbol\n3: Exit" << endl;
        cin >> choiceI;

        if(choiceI == 1) {
            Element l;
            cout << "Enter atomic number: " << endl;
            cin >> choiceS;
            l.searchByNum(choiceS);
            cout << l;
        } else if (choiceI == 2) {
            Element l;
            cout << "Enter symbol: " << endl;
            cin >> choiceS;
            l.searchBySymbol(choiceS);
            cout << l;
        }
    } while (choiceI != 3);
    cout << "KTHXBAI";
    return 0;
}
