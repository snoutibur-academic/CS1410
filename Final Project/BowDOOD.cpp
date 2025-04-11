#include "BowDOOD.h"
#include <cmath>
#include <iostream>

string BowDOOD::str() {
    // Display
    stringstream ss;
    ss << Character::str();

    ss << "ARCHER!!\n";
    ss << "BOW: " << bow << endl;
    ss << "BOW DEALS " << getBowDamage() << " HP OF DAMAGE!\n";
    ss << arrows << " arrows remaining.\n";
    ss << "Level: " << skillLevel << endl;

    return ss.str();
}

int BowDOOD::getBowDamage() {
    int damage = ceil((atk*1.5) * bowDamageMultiplier);
    return damage;
}

// Special actions
void BowDOOD::bowAttack(Character &enemy) {
    if (arrows >=1) {
        arrows -=1;

    } else {
        std::cout << name << " is out of arrows. :c\n";
    }
}

void BowDOOD::performSpecial(Character *target) {
    string action;
    std::cout << name << "'s special actions:\n"
                         "(b)owattack\n"
                         "THESE ACTIONS WILL PE PERFORMED ON: " << target->getName() << endl;
    do {
        std::cin >> action;
        if(action == "b") {
            bowAttack(*target);
            break;
        } else {
            std::cout << "Invalid action! Try again:\n";
        }
    } while (true);
}
