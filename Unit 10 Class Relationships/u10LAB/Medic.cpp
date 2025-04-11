#include "Medic.h"

string Medic::str() {
    stringstream ss;
    ss << Character::str();

    ss << "MEDIC!!\n";
    ss << "Medkits remaining:" << medkits << endl;
    ss << "Each medkit heals" << healAmount << "HP.\n";

    return ss.str();
}