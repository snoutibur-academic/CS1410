#include "LittleBigMonster.h"
#include <iostream>

// Special actions
void LittleBigMonster::chonkyAttack(Character &enemy) {
    if (energy <= 0) {
        std::cout << name << " IS COMMITTING THE CHONKYATTACK!!\n";
        energy -= 10;
        enemy.takeDamage(chonkyAtkDmg);
    } else {
        std::cout << name << " is too tired to perform this action.\n";
    }
}

void LittleBigMonster::beastinessBoost(int amount) {
    if(energy <= amount) {
        std::cout << name << " converted " << amount << " energy to " << amount << " beastiness!\n";
        energy -= amount;
        beastiness += amount;
    } else {
        std::cout << name << " doesn't have enough energy to convert to the desired amount of beastiness. \n";
    }
}

void LittleBigMonster::performSpecial(Character *target) {
    string action;
    std::cout << name << "'s special actions:\n"
                         "(b)eastiness boost\n"
                         "(c)honky attack\n"
                         "THESE ACTIONS WILL PE PERFORMED ON: " << target->getName() << endl;

    std::cout << "You've automatically gained 10 energy!\n";
    gainEnergy(10);

    do {
        std::cin >> action;
        if(action == "b") {
            int amount;
            std::cout << "HOWMUCH BEEEST?"<<endl;
            std::cin >> amount;
            beastinessBoost(amount);
            break;
        } else if(action == "c") {
            std::cout << "CHONK ATTACK ON " << target->getName() << endl;
            chonkyAttack(*target);
            break;
        } else {
            std::cout << "invalid action. try again!\n";
        }
    } while (true);
}


// Gameplay
void LittleBigMonster::gainEnergy(int amount) {
    energy += amount;
}

// Display
string LittleBigMonster::str() {
    stringstream ss;
    ss << Character::str();

    ss << "-= BIG SCARY MONSTER =-\n";
    ss << "NRG: " << energy << endl;
    ss << "BEASTINESS: " << beastiness << endl;
    chonkyAtkDmg = atk * beastiness; // Updates chonky attack damage
    ss << "CHONKY ATTACK DAMAGE: " << chonkyAtkDmg << endl;

    return ss.str();
}