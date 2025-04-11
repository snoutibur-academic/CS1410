#ifndef SWORDBRO_H
#define SWORDBRO_H
#include "Character.h"


class BowDOOD : public Character {
public:
    // Constructor
    BowDOOD(string name, int health, int maxHealth, int atk, int def, string weaponName, float bowDmgMultiplier, int arrows, int skilz) : Character(name, health, maxHealth, atk, def), bow(weaponName), bowDamageMultiplier(bowDmgMultiplier) , arrows(arrows), skillLevel(skilz) {};

    // Display & getters
    int getBowDamage();
    virtual string str();

    // Special actions
    void bowAttack(Character &enemy);
    virtual void performSpecial (Character *target);

protected:
    string bow;
    float bowDamageMultiplier;
    int arrows;
    int skillLevel;
};

#endif //SWORDBRO_H
