#include "Medic.h"
#include <iostream>

// Special actions
void Medic::healCharacter(Character *patient) {
    std::cout << name << " healed "<< patient -> getName() << "!\n";
    medkits-=1;
    patient -> heal(healAmount);
}

void Medic::performSpecial(Character *target) {
    string action;
    std::cout << name << "'s special actions:\n"
                         "(h)eal player\n"
                         "THESE ACTIONS WILL PE PERFORMED ON: " << target->getName() << endl;
    do {
        std::cin >> action;
        if(action == "h") {
            std::cout << "Healing " << target->getName() << endl;
            target->heal(healAmount);
            break;
        } else {
            std::cout << "Invalid action. Try again\n";
        }
    } while (true);
}

// Display
string Medic::str() {
    stringstream ss;
    ss << Character::str();

    ss << "MEDIC!!\n";
    ss << "Medkits remaining: " << medkits << endl;
    ss << "Each medkit heals " << healAmount << " HP.\n";

    return ss.str();
}