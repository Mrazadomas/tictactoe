#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bot {
        // int t1 = 1;
        // int t2 = 4;
        // int t3 = 7;
        // int t4 = 11;
        // int t5 = 14;
        // int t6 = 17;
        // int t7 = 21;
        // int t8 = 24;
        // int t9 = 27;
    private: vector<int> cells = {1, 4, 7, 11, 14, 17, 21, 24, 27};

    private: string name;
            
    private: int health;
    private: int attack;
    private: int defense;

    public: 
        Bot(string name, int health, int attack, int defense) {
            this->name = name;
            this->health = health;
            this->attack = attack;
            this->defense = defense;
        }

    public: 
        string getName() {
            return name;
        }

    public: 
        int getHealth() {
            return health;
        }

    public: 
        int getAttack() {
            return attack;
        }

    public: 
        int getDefense() {
            return defense;
        }


    public: 
        vector<string> botMove(vector<string> gameboard, string mark) {
            vector<int> openTiles;
            for (int i = 0; i < cells.size(); i++) { // find empty cells on the board
                if (gameboard[cells[i]] == " ") {
                    openTiles.push_back(cells[i]);
                }
            }
        
            srand(time(0));
            int index = (rand() % (openTiles.size()));
            gameboard[openTiles[index]] = mark;

            cout << "\n" << endl;
            for (int i = 0; i < gameboard.size(); i++) {
                if ((i == 9) || (i == 19)) {
                    cout << "\n" << gameboard[i] << endl;
                } else {
                    cout << gameboard[i];
                }
            }
            
            return gameboard;
        }
};
