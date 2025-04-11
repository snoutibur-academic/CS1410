#include <iostream>
#include <vector>

#include "BowDOOD.h"
#include "Character.h"
#include "Medic.h"

using namespace std;

int main() {
    cout << "Just some beings, I guess!" << endl;

    Character useless("Useless", 1, 0, 0);

    vector<Character*> roster;
    roster.push_back(new BowDOOD("Dingus", 100, 3, 10, "PewPew", 100, 0.42));
    roster.push_back(new BowDOOD("Audizee", 100, 10, 3, "HYPRpew", 50, 0.83));
    roster.push_back(new Medic("ERbill", 100, 1, 7, 10, 50));
    roster.push_back(new Medic("Meditella", 100, 0, 10, 5, 100));

    cout << useless << endl;

    for(Character *c: roster) {
        cout << *c << endl;
    }

    return 0;
}
