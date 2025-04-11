#include "Character.h"
#include <iostream>
#include <cmath>

// Getters and Operators //
string Character::getName() const {
    return name;
}
string Character::displayHP() {
    return health + " / " + maxHealth;
}

ostream& operator << (ostream& out, Character& me) {
    out << me.str();
    return out;
}

// Display character //
string Character::healthBar() {
    return "[HEALTHBAR - To be implemented]";
}

string Character::str() {
    stringstream ss;
    ss << "---=-=-=-== [ " << name << " ] ==-=-=-=---" << endl;
    ss << "HP: " << health <<  " / " << maxHealth << endl;
    ss << "ATK: " << atk << endl;
    ss << "DEF: " << def << endl;

    return ss.str();
}

// Gameplay functions - to be utilized with other classes, or throughout the story. //
// Character events
void Character::takeDamage(int amount) {
    int damage = floor(amount - (amount * (def/100)));
    std::cout << name << " took " << damage << " HP of damage!!" << endl;
    health -= damage;

    if(health <= 0) {
        std::cout << name << " has just died. " << endl;
        // Sets HP to 0 just in case the character is in negative health.
        health = 0;
    }
}

void Character::heal(int amount) {
    if(health <= 0) {
        std::cout << name << " was revived! " << endl;
    } else {
        std::cout << name << " gained " << amount << " HP!\n";
    }

    health += amount;
    std::cout << name << " now has " << health << " HP" << endl;
}

// Character actions
void Character::basicAttack(Character *enemy) {
    // Characters won't have a successful attack 100% of the time. This should result in a roughly 70% success rate.
    int hitChance = 0 + rand() % 100;

    if(hitChance >= 30) {
        std::cout << name << " attacks " << enemy -> getName() << " successfully dealing " << atk << " HP of damage!" << endl;
        enemy -> takeDamage(atk);
    } else {
        std::cout << name << " misses their attack D:" << endl;
    }
}

void Character::performBasicAction(Character *target) {
    string action;
    std::cout << name << "'s basic actions:\n"
                         "(a)ttack - basic\n"
                         "THESE ACTIONS WILL PE PERFORMED ON: " << target->getName() << endl;
    std::cin >> action;
    if(action == "a") {
        basicAttack(target);
    }
}

void Character::performSpecial(Character *target) {
    std::cout << "Standard characters don't have a special!\n" << endl;
}
