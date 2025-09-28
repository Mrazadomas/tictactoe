#include <iostream>
#include <vector>

using namespace std;

vector<string> gameboard = {" ", " ", " |", " ", " ", " |", " ", " ", " ", 
        "-----------", 
        " ", " ", " |", " ", " ", " |", " ", " ", " ", 
        "-----------", 
        " ", " ", " |", " ", " ", " |", " ", " ", " "};
string p1;
string p2;
int turn = 1; //for turns, default is 1, which is o, 2 is x and so on alternating
int t1 = 1;
int t2 = 4;
int t3 = 7;
int t4 = 11;
int t5 = 14;
int t6 = 17;
int t7 = 21;
int t8 = 24;
int t9 = 27;
int tile;
// x win is 1, o win is 0;

//win conditions
/*
1 4 7
11 14 17
21 24 27
1 11 21
4 14 24
7 17 27
1 14 27
7 14 21
*/

// vector<int> win1 = {1, 4, 7};
// vector<int> win2 = {11, 14, 17};
// vector<int> win3 = {21, 24, 27};
// vector<int> win4 = {1, 11, 21};
// vector<int> win5 = {4, 14, 24};
// vector<int> win6 = {7, 17, 27};
// vector<int> win7 = {1, 14, 27};
// vector<int> win8 = {7, 14, 21};

int checkWinx() {
    vector<int> xTiles;
    for (int i = 0; i < gameboard.size(); i++) {
        if (gameboard[i] == "x") {
            xTiles.push_back(i);
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 1) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 4) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 7) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 11) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 17) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 21) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 24) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 27) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 1) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 11) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 21) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 4) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 24) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 7) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 17) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 27) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 1) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 27) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 7) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 21) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int checkWino() {
    vector<int> xTiles;
    for (int i = 0; i < gameboard.size(); i++) {
        if (gameboard[i] == "o") {
            xTiles.push_back(i);
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 1) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 4) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 7) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 11) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 17) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 21) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 24) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 27) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 1) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 11) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 21) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 4) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 24) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 7) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 17) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 27) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 1) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 27) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < xTiles.size(); i++) {
        if (xTiles[i] == 7) {
            for (int x = 0; x < xTiles.size(); x++) {
                if (xTiles[x] == 14) {
                    for (int y = 0; y < xTiles.size(); y++) {
                        if (xTiles[y] == 21) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int getTile() {
    bool check = true;
    do {
        cout << "\n\nPlease enter the number of the tile you would like to place your mark." << endl;
        cin >> tile;
        if (cin.fail()) {
            cout << "ERROR ----- Please enter a valid integer 1 through 9. ----- ERROR" << endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if ((tile >= 1) && (tile <=9)) {
            check = false;
        } else {
            cout << "ERROR ----- Please enter a valid integer 1 through 9. ----- ERROR" << endl;
        }


    } while (check);
    return tile;
}

int tileConversion(int tile) {
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

bool tileCheck(int tile) {
    if (gameboard[tile] != " ") {
        cout << "Tile is already marked." << endl;
        return false;
        
    } 
    return true;
}

void fillTile() { //t for tile
    if ((turn % 2) == 0) {
        int rt = getTile(); //requested tile
        int rtc = tileConversion(rt); //requested tile converted
        if (tileCheck(rtc)) {
            gameboard[rtc] = "x";
        } else {
            fillTile();
        }
    } else {
        int rt = getTile(); //requested tile
        int rtc = tileConversion(rt); //requested tile converted
        if (tileCheck(rtc)) {
            gameboard[rtc] = "o";
        } else {
            fillTile();
        }
    }
    cout << "\n" << endl;
    for (int i = 0; i < gameboard.size(); i++) {
            if ((i == 9) || (i == 19)) {
                cout << "\n" << gameboard[i] << endl;
            } else {
                cout << gameboard[i];
            }
        }
    
}

void instructions() {
    cout << "Welcome to the Tic-Tac-Toe game!" << "\n" << endl;
    cout << "Please enter the name of player 1: ";
    cin >> p1;
    cout << "\n" << "Please enter the name of player 2: ";
    cin >> p2;
    cout << endl;
    cout << "Player 1 will mark the boxes with o. Player 2 will mark the boxes with x. Press enter to continue------>";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    string temp;
    getline(cin, temp);
    cout << endl;
    cout << endl;
    cout << "To mark the boxes you will type in the number of the box you wish to fill according to the diagram below." << "\n" << endl;
    vector<string> board = {" ", "1", " |", " ", "2", " |", " ", "3", " ", 
        "----------", 
        " ", "4", " |", " ", "5", " |", " ", "6", " ", 
        "----------", 
        " ", "7", " |", " ", "8", " |", " ", "9", " ",};
    for (int i = 0; i < board.size(); i++) {
        if ((i == 9) || (i == 19)) {
            cout << "\n" << board[i] << endl;
        } else {
            cout << board[i];
        }
    }
    cout << endl;
    cout << "\nPress enter to start the game.";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    string temp1;
    getline(cin, temp1);
};

void game() {
    instructions();
    cout << "\n" << endl;
    for (int i = 0; i < gameboard.size(); i++) {
            if ((i == 9) || (i == 19)) {
                cout << "\n" << gameboard[i] << endl;
            } else {
                cout << gameboard[i];
            }
    }
    for (int i = 1; i < 10; i++) {
        if ((turn == 1) || ((turn % 2) == 1)) {
            cout << "\n\n" << p1 << "'s turn." << endl;
        } else {
            cout << "\n\n" << p2 << "'s turn." << endl;
        }
        fillTile();
        if ((turn > 4)) {
            if ((turn % 2) == 0) {
                if (checkWinx() == 1) {
                    cout << "\n\n" << p2 << " has won the game.\n" << endl;
                    break;
                }
            } else {
                if (checkWino() == 1) {
                    cout << "\n\n" << p1 << " has won the game.\n" << endl;
                    break;
                }
            }
        }
        turn++;
        if (i == 9) {
            cout << "\n\nThe game ends in a tie" << endl;
        }
    }


}

int main() {
    game();
}
