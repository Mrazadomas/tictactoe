#ifndef PALADIN_H
#define PALADIN_H
#include <iostream>
#include <vector>
#include "Game.cpp"

using namespace std;

class Paladin {
    private:
        int cell1; //tile of the mark
        int cell2; //empty tile to push cell1 to
        int t1 = 1;
        int t2 = 4;
        int t3 = 7;
        int t4 = 11;
        int t5 = 14;
        int t6 = 17;
        int t7 = 21;
        int t8 = 24;
        int t9 = 27;
        // string push1 = "Your options are 2, 4, and 5.";
        // string push2 = "Your options are 1, 3, 4, 5, and 6.";
        // string push3 = "Your options are 2, 5, and 6.";
        // string push4 = "Your options are 1, 2, 5, 7, and 8.";
        // string push5 = "You can push anywhere.";
        // string push6 = "Your options are 2, 3, 5, 8, and 9.";
        // string push7 = "Your options are 4, 5, and 8.";
        // string push8 = "Your options are 4, 5, 6, 7, and 9";
        // string push9 = "Your options are 5, 6, and 8.";

    private: void getPushTiles() {
        bool check = true;
        do {
            cout << "\n\nPlease enter the number of the tile of the mark you would like to push: " << endl;
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
            cout << "\n\nPlease enter the number of the tile you would like to push your mark to: " << endl;
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

    private: bool checkSurroundings(vector<string> gameboard) {
        if (cell1 == 1) {
            if ((cell2 == 2) || (cell2 == 4) || (cell2 == 5)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 2) {
            if ((cell2 == 1) || (cell2 == 3) || (cell2 == 4) || (cell2 == 5) || (cell2 == 6)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 3) {
            if ((cell2 == 2) || (cell2 == 5) || (cell2 == 6)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 4) {
            if ((cell2 == 1) || (cell2 == 7) || (cell2 == 5) || (cell2 == 8) || (cell2 == 2)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 5) {
            if ((cell2 >= 1) && (cell2 <= 9)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 6) {
            if ((cell2 == 3) || (cell2 == 9) || (cell2 == 5) || (cell2 == 2) || (cell2 == 8)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 7) {
            if ((cell2 == 4) || (cell2 == 5) || (cell2 == 8)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 8) {
            if ((cell2 == 4) || (cell2 == 5) || (cell2 == 6) || (cell2 == 7) || (cell2 == 9)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } else if (cell1 == 9) {
            if ((cell2 == 5) || (cell2 == 6) || (cell2 == 8)) {
                if (!(check(cell2, gameboard))) {
                    return true; //true for all clear and ready to swap
                } else {
                    return false; //false for not clear
                }
            }
        } 
        return false;
    }

    public: vector<string> ability(vector<string> gameboard) {
        do {
            getPushTiles();
            if (cell1 == cell2) {
                cout << "\nPlease input two different cells." << endl;
            }
        } while (cell1 == cell2);
        if (check(cell1, gameboard) && checkSurroundings(gameboard)) {
            string temp;
            temp = gameboard[tileConversion(cell1)];
            gameboard[tileConversion(cell1)] = gameboard[tileConversion(cell2)];
            gameboard[tileConversion(cell2)] = temp;
            cout << "\n" << endl;
        } else {
            cout << "Cannot complete push. Try a different combination of nummbers." << endl;
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
