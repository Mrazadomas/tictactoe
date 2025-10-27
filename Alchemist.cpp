#ifndef ALCHEMIST_H
#define ALCHEMIST_H
#include <iostream>
#include <vector>
#include "Game.cpp" 


using namespace std;

class Alchemist {

    private:
        int cell1;
        int cell2;
        int t1 = 1;
        int t2 = 4;
        int t3 = 7;
        int t4 = 11;
        int t5 = 14;
        int t6 = 17;
        int t7 = 21;
        int t8 = 24;
        int t9 = 27;

    private: void getSwapTiles() {
        bool check = true;
        do {
            cout << "\n\nPlease enter the number of the first tile you would like to swap: " << endl;
            cin >> cell1;
            if (cin.fail()) {
                cout << "ERROR ----- Please enter a valid integer 1 through 9. ----- ERROR" << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((cell1 >= 1) && (cell1 <=9)) {
                check = false;
            } else {
                cout << "ERROR ----- Please enter a valid integer 1 through 9. ----- ERROR" << endl;
            }


        } while (check);
        
        bool check2 = true;
        do {
            cout << "\n\nPlease enter the number of the second tile you would like to swap: " << endl;
            cin >> cell2;
            if (cin.fail()) {
                cout << "ERROR ----- Please enter a valid integer 1 through 9. ----- ERROR" << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((cell2 >= 1) && (cell2 <=9)) {
                check2 = false;
            } else {
                cout << "ERROR ----- Please enter a valid integer 1 through 9. ----- ERROR" << endl;
            }


        } while (check2);
    }
    
    public: int tileConversion(int tile) {
        if (tile == 1) {
            return t1;
        } else if (tile == 2) {
            return t2;
        } else if (tile == 3) {
            return t3;
        } else if (tile == 4) {
            return t4;
        } else if (tile == 5) {
            return t5;
        } else if (tile == 6) {
            return t6;
        } else if (tile == 7) {
            return t7;
        } else if (tile == 8) {
            return t8;
        } else {
            return t9;
        }
    }

    private: bool check(int tile, vector<string> gameboard) {
        int rtc = tileConversion(tile);
        if (gameboard[rtc] != " ") {
            return true;
        } else {
            return false;
        }
    }

    public: vector<string> ability(vector<string> gameboard) {
        do {
            getSwapTiles();
            if (cell1 == cell2) {
                cout << "\nPlease input two different cells." << endl;
            }
        } while (cell1 == cell2);
        if (check(cell1, gameboard) && check(cell2, gameboard)) {
            string temp;
            temp = gameboard[tileConversion(cell1)];
            gameboard[tileConversion(cell1)] = gameboard[tileConversion(cell2)];
            gameboard[tileConversion(cell2)] = temp;
            cout << "\n" << endl;
        } else {
            cout << "Both tiles must be already marked to be able to swap." << endl;
            return ability(gameboard);
        }
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
#endif
