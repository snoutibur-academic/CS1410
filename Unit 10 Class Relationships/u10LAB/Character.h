#ifndef CHARACTER_H
#define CHARACTER_H

#include <chrono>

using std::stringstream;
using std::ostream;
using std::string;
using std::endl;


class Character {
public:
    Character(string name, int health, int atk, int def) : name(name), health(health), atk(atk) {};

    virtual string str();
    friend ostream& operator << (ostream& out, Character& me);

protected:
    string name;
    int health;
    int atk;
    int def;
};
#endif //CHARACTER_H
