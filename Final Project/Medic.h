#ifndef MEDIC_H
#define MEDIC_H

#include <string>
#include "Character.h"

class Medic : public Character {
public:
    // Constructor
    Medic(string name, int health, int maxHealth, int atk, int def, int medkits, int healamount) : Character(name, health, maxHealth, atk, def), medkits(medkits), healAmount(healamount) {};

    // Special actions
    void healCharacter(Character* patient);
    virtual void performSpecial(Character *target);

    // Display
    virtual string str();

protected:
    int medkits;
    int healAmount;
};

#endif //MEDIC_H
