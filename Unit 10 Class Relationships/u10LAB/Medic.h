//
// Created by snoutibur on 11/17/24.
//

#ifndef MEDIC_H
#define MEDIC_H

#include <string>
#include "Character.h"

class Medic : public Character {
public:
    Medic(string name, int health, int atk, int def, int medkits, int healamount) : Character(name, health, atk, def), medkits(medkits), healAmount(healamount) {};
    virtual string str();
protected:
    int medkits;
    int healAmount;
};

#endif //MEDIC_H
