#ifndef SWORDBRO_H
#define SWORDBRO_H
#include "Character.h"


class BowDOOD : public Character {
public:
    BowDOOD(string name, int health, int atk, int def, string weaponName, int arrows, double skilz) : Character(name, health, atk, def), bow(weaponName), arrows(arrows), skillLevel(skilz) {};

    virtual string str();
protected:
    string bow;
    int arrows;
    double skillLevel;
};

#endif //SWORDBRO_H
