// Library includes
#include <iostream>
#include <vector>
// File includes
#include <cmath>

#include "Character.h"
#include "BowDOOD.h"
#include "LittleBigMonster.h"
#include "Medic.h"

using namespace std;

// Storage
int pNum;
int targetPNum;
vector<Character *> players;


void setupPlayer() {
    system("clear");

    int choice = 0;
    string name;

    int randHealth = 50 + rand() % 100;
    int randAtk = 1 + rand() % 10;
    int randDef = 0 + rand() % 100;

    // Naming the new player
    cout << "\n[RANDOMLY GENERATED] Player setup!\nYour name, please: ";
    cin >> name;
    system("clear");

    // Choosing the new player's class
    cout << "Very good, " << name << "\nNow, please choose a role.\n"
            "1: BowDOOD\n"
            "2: Medic\n"
            "3: LittleBigMonsterTM\n";
    cout << "Your choice, please: ";
    cin >> choice;
    system("clear");

    // Character setup
    if (choice == 1) {
        // Archer setup //
        string weapon;
        float bowDam = 1.05 + rand() % 3;

        cout << "You shall be a BowDOOD.\nName your weapon: ";
        cin >> weapon;
        system("clear");

        // Add to roster + prints the player out
        BowDOOD *newPlayer = new BowDOOD(name, randHealth, randHealth, randAtk, randDef, weapon, bowDam, 100, 0);
        players.push_back(newPlayer);

        cout << "Very well then, here is your character:\n";
        cout << *newPlayer;
    } else if (choice == 2) {
        // Medic setup
        int randMedkitCount = 2 + rand() % 16;
        Medic *newPlayer = new Medic(name, randHealth, randHealth, randAtk, randDef, randMedkitCount, 20);
        players.push_back(newPlayer);

        system("clear");
        cout << "You shall be a Medic.\nHere's your character:\n";
        cout << *newPlayer;
        cout << "(NOTE: Entry level medkits heal 20HP each.)\n";
    } else if (choice == 3) {
        cout << "YOU ARE THE LITTLE BIG MONSTER! :OOO\n";
        LittleBigMonster *newMonster = new LittleBigMonster(name, randHealth + 1000, randHealth + 1000, randAtk * 2,
                                                            randDef * 5, 1, 100);
        players.push_back(newMonster);
        cout << *newMonster;
    } else {
        // Invalid choice
        cout << "bad choice...\n";
    }
}

void enterToProceed() {
    cin.clear();
    cout << "\nEnter to proceed\n";
    cin.ignore();
    system("clear");
}

void simplePlayerDisplay() {
    // List players - simplified
    cout << endl << players.size() << " player(s) remain. They are:\n";
    pNum = 0;
    for (auto c: players) {
        pNum++;
        cout << "[ #" << pNum << " ] ";
        cout << c->getName() << endl;
    }
    cout << endl;
}

void bigPlayerDisplay() {
pNum = 0;
    for (auto c: players) {
        pNum++;
        cout << "Player #" << pNum << endl;
        cout << c->str() << endl;
    }
}

Character* searchPlayer(string input) {
    do {
        for (auto c: players) {
            if (c->getName() == input) {
                return c;
            }
        }

        cout << "PLAYER CAN'T BE FOUND D: Try again. Player name please:\n";
        cin >> input;
    } while(true);
}

int main() {
    string sInput;
    int iInput;

    system("clear");
    cout << "        A very generic turn based fighting game!\n";
    cout << R"(
 ▄██████▄     ▄█    █▄     ▄█     █▄   ▄█     ▄████████
███    ███   ███    ███   ███     ███ ███    ███    ███
███    ███   ███    ███   ███     ███ ███▌   ███    █▀
███    ███  ▄███▄▄▄▄███▄▄ ███     ███ ███▌  ▄███▄▄▄
███    ███ ▀▀███▀▀▀▀███▀  ███     ███ ███▌ ▀▀███▀▀▀
███    ███   ███    ███   ███     ███ ███    ███    █▄
███    ███   ███    ███   ███ ▄█▄ ███ ███    ███    ███
 ▀██████▀    ███    █▀     ▀███▀███▀  █▀     ██████████
)" << endl;
    cout << "                  please don't blow up" << endl;
    enterToProceed();


    // == TEST SECTION == //

    // return 0;

    // == GAME SECTION == //
    cout << "NOTE: Players will play in the order that they're registered.";
    // Player Setup : initial
    setupPlayer();
    // Add additional players
    while (true) {
        cout << "(f)inish or (a)dd another player: ";
        cin.clear();
        cin >> sInput;

        if (sInput == "f") {
            break;
        } else if (sInput == "a") {
            setupPlayer();
        } else {
            cout << "Invalid choice, pls try harder\n";
        }
    }

    // Lists roster
    system("clear");
    cout << "Here are your players:\n";
    bigPlayerDisplay();
    enterToProceed();


    // GAMEPLAY //
    while (players.size() > 1) {
        simplePlayerDisplay();

        // Player actions
        for (auto c: players) {
            int turns = 3;
            do {
                turns -= 1;
                cout << "==== " << c->getName() << " is up! =====\n"
                        "What would you like to do?\n"
                        "(b)asic character actions\n"
                        "(s)pecial actions\n"
                        "(d)isplay a character's stats (Doesn't cost a turn!)\n"
                        "(f)inish run prematurely. \nYou have " << turns << " turns remaining!" << endl;

                cin >> sInput;
                if (sInput == "b") {
                    // BASIC CHAR FUNCTIONS
                    cout << "BASIC CHARACTER ACTIONS!\n"
                            "Who will you perform your action on?\n";
                    simplePlayerDisplay();
                    cin >> sInput;
                    c->performBasicAction(searchPlayer(sInput));
                } else if (sInput == "s") {
                    // SPECIAL CHARACTER ACTIONS
                    cout << "SPECIAL CHARACTER ACTIONS!\n"
                            "Who will you perform your action on?\n";
                    simplePlayerDisplay();
                    cin >> sInput;
                    c -> performSpecial(searchPlayer(sInput));

                } else if (sInput == "f") {
                    // FINISH TURN
                    break;
                } else if (sInput == "d") {
                    // CHECK CHARACTER
                    turns += 1;
                    cout << "YOUR STATS!\n" << c->str() << "\nAny key to continue, or fetch a (s)pecific player's stats"
                            << endl;
                    cin >> sInput;
                    if (sInput == "s") {
                        simplePlayerDisplay();
                        cout << "Fetching stats for: ";
                        cin >> sInput;
                        cout << searchPlayer(sInput)->str() << endl;
                    }
                } else {
                    // no.
                    cout << "bad choice" << endl;
                    turns += 1;
                }
            } while (sInput != "f" || turns <= 0);
            system("clear");
            cout << c->getName() << "'s turn concluded" << endl << endl;
        }

        // End of round actions
        enterToProceed();
    }

    cout << "YAY!" << players[0]->getName() << "was the last player standing!\nSo they win.\nThe end!!\n";
    return 0;
}