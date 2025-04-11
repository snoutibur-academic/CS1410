#ifndef LITTLEBIGMONSTER_H
#define LITTLEBIGMONSTER_H

#include "Character.h"

class LittleBigMonster : public Character {
public:
    // Constructor
    LittleBigMonster(string name, int health, int maxHealth, int atk, int def, int beastiness, int energy) : Character(name, health, maxHealth, atk, def), beastiness(beastiness), energy(energy) {};

    // Special Actions
    void chonkyAttack(Character &enemy);
    void beastinessBoost(int amount);

    virtual void performSpecial(Character *target);

    // Gameplay
    void gainEnergy(int amount);

    // Display
    virtual string str();

protected:
    int beastiness;
    int energy;
    int chonkyAtkDmg = atk * beastiness;
};

#endif //LITTLEBIGMONSTER_H