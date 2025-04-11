#ifndef CHARACTER_H
#define CHARACTER_H

#include <chrono>

using std::stringstream;
using std::ostream;
using std::string;
using std::endl;


class Character {
public:
    // Constructor
    Character(string name, int health, int maxHealth, int atk, int def) : name(name), health(health), maxHealth(maxHealth), atk(atk), def(def) {};

    // Character events
    void takeDamage(int);
    void heal(int);

    // Character actions
    void basicAttack(Character *enemy);
    void performBasicAction(Character *target);

    virtual void performSpecial(Character *target);

    // Getters and operators
    string getName() const;
    string displayHP();

    // Display functions
    string healthBar();

    virtual string str();
    friend ostream& operator << (ostream& out, Character& me);

protected:
    string name;
    int health;
    int maxHealth;
    int atk;
    int def;
};

#endif //CHARACTER_H
