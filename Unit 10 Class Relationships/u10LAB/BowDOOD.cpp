#include "BowDOOD.h"

string BowDOOD::str() {
    stringstream ss;
    ss << Character::str();
    ss << "ARCHER!!\n";
    ss << "BOW: " << bow << endl;
    ss << arrows << " arrows remaining.\n";
    ss << "Level: " << skillLevel << endl;

    return ss.str();
}