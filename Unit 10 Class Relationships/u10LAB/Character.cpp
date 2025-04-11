#include "Character.h"

string Character::str() {
    stringstream ss;
    ss << name << endl;
    ss << "HP: " << health << endl;
    ss << "ATK: " << atk << endl;

    return ss.str();
}

ostream& operator << (ostream& out, Character& me) {
    out << me.str();
    return out;
}