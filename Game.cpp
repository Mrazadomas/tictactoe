#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Alchemist.cpp"
#include "Paladin.cpp"

using namespace std;

class Game {

    Alchemist alchemist;
    Paladin paladin;

    vector<int> cells = {1, 4, 7, 11, 14, 17, 21, 24, 27};

    public: vector<string> gameboard = {" ", " ", " |", " ", " ", " |", " ", " ", " ", 
            "-----------", 
            " ", " ", " |", " ", " ", " |", " ", " ", " ", 
            "-----------", 
            " ", " ", " |", " ", " ", " |", " ", " ", " "};

    private: vector<string> clearboard = {" ", " ", " |", " ", " ", " |", " ", " ", " ", 
            "-----------", 
            " ", " ", " |", " ", " ", " |", " ", " ", " ", 
            "-----------", 
            " ", " ", " |", " ", " ", " |", " ", " ", " "};

    private:
    string p1;
    string p2;
    string p1mark;
    string p2mark;
    string p1Arch;
    string p2Arch;
    int mode;
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

    private: int checkWinx() {
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

    private: int checkWin(string mark) { // for custom marks
        vector<int> xTiles;
        for (int i = 0; i < gameboard.size(); i++) {
            if (gameboard[i] == mark) {
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

    private: int checkWino() {
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

    public: int getTile() {
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

    public: bool tileCheck(int tile) {
        if (gameboard[tile] != " ") {
            cout << "Tile is already marked." << endl;
            return false;
            
        } 
        return true;
    }

    private: bool boardFull() {
        int count = 0;
        for (int i = 1; i < 10; i++) {
        if (gameboard[tileConversion(i)] != " ") {
                count++;
        }
        }
        if (count == 9) {
            return true;
        }
        return false;
    }

    private: void fillTile() { //t for tile
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

    private: void fillTile(string p1, string p2) { // overloaded fill tile for custom marks
        if ((turn % 2) == 0) {
            int rt = getTile(); //requested tile
            int rtc = tileConversion(rt); //requested tile converted
            if (tileCheck(rtc)) {
                gameboard[rtc] = p2;
            } else {
                fillTile();
            }
        } else {
            int rt = getTile(); //requested tile
            int rtc = tileConversion(rt); //requested tile converted
            if (tileCheck(rtc)) {
                gameboard[rtc] = p1;
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

    private: int getFilledTiles() {
        int count = 0;
        for (int i = 0; i < cells.size(); i++) {
            int cell = cells[i];
            if (gameboard[cell] != " ") {
                count++;
            }
        }
        return count;
    }

    private: int getMode() {
        bool check = true;
        cout << "Would you like to play regular or battle?" << endl;
        do {
            cout << "Type 1 for regular or 2 for battle. ";
            cin >> mode;
            if (cin.fail()) {
                cout << "Please enter one of the designated numbers. \n" << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((mode == 1) || (mode == 2)) {
                check = false;
            } else {
                cout << "Please enter one of the designated numbers. \n" << endl;
            }


        } while (check);

        return mode;
    }

    private: void menu() {
        cout << "\nWelcome to the Tic-Tac-Toe game!" << "\n" << endl;
        getMode();
    }

    private: void instructionsRegular() {
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

    private: string getArchetype() {
        bool check = true;
        int temp;
        cout << "\nYou will now choose an Archetype." << endl;
        do {
            cout << "Type 1 for Alchemist or 2 for Paladin. ";
            cin >> temp;
            if (cin.fail()) {
                cout << "Please enter one of the designated numbers. \n" << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((temp == 1) || (temp == 2)) {
                check = false;
            } else {
                cout << "Please enter one of the designated numbers. \n" << endl;
            }


        } while (check);

        if (temp == 1) {
            return "Alchemist";
        } 
        return "Paladin";
    }

    private: int getMove() {
        bool check = true;
        int move;
        do {
            cout << "Type 1 to place your mark, or type 2 to use your archetype's ability. ";
            cin >> move;
            if (cin.fail()) {
                cout << "Please enter one of the designated numbers. \n" << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((move == 1) || (move == 2)) {
                check = false;
            } else {
                cout << "Please enter one of the designated numbers. \n" << endl;
            }


        } while (check);

        if ((turn == 1) && ((p1Arch == "Paladin") || (p2Arch == "Paladin")) && (move == 2) && (getFilledTiles() == 0)) {
            move = 1;
            cout << "\nThere must be a tile marked before using Paladin ability." << endl;
        } else if (((p1Arch == "Alchemist") || (p2Arch == "Alchemist")) && (move == 2) && (getFilledTiles() < 2)) {
            move = 1; 
            cout << "\nThere must be at least two tiles marked before using Alchemist ability." << endl;
        }

        return move;
    }

    private: void instructionsBattle() {
        cout << "Please enter the name of player 1: ";
        cin >> p1;
        cout << "Please enter your preferred mark. Mark must be one character. ";
        cin >> p1mark;
        p1Arch = getArchetype();
        cout << "\n" << "Please enter the name of player 2: ";
        cin >> p2;
        cout << "Please enter your preferred mark. Mark must be one character. ";
        cin >> p2mark;
        p2Arch = getArchetype();
        cout << endl;
        cout << "Player 1 will mark the boxes with " << p1mark << ". Player 2 will mark the boxes with " << p2mark << ". Press enter to continue------>";
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
    }

    private: void Regulargame() {
        cout << "\n" << endl;
        for (int i = 0; i < gameboard.size(); i++) {
                if ((i == 9) || (i == 19)) {
                    cout << "\n" << gameboard[i] << endl;
                } else {
                    cout << gameboard[i];
                }
        }
        do {
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
            if (turn == 9) {
                cout << "\n\nThe game ends in a tie" << endl;
            } else {
                turn++;
            }
        } while (!(boardFull()));


    }

    private: void Battlegame() {
        cout << p1Arch << ", " << p2Arch << endl;
        cout << "\n" << endl;
        for (int i = 0; i < gameboard.size(); i++) {
                if ((i == 9) || (i == 19)) {
                    cout << "\n" << gameboard[i] << endl;
                } else {
                    cout << gameboard[i];
                }
        }
        int move = 0;
        do {
            if ((turn == 1) || ((turn % 2) == 1)) {
                cout << "\n\n" << p1 << "'s turn." << endl;
                move = getMove();
            } else {
                cout << "\n\n" << p2 << "'s turn." << endl;
                move = getMove();
            }
            if (move == 1) {
                fillTile(p1mark, p2mark);
            } else if (move == 2) {
                if ((turn == 1) || ((turn % 2) == 1)) {
                    if (p1Arch == "Alchemist") {
                        gameboard = alchemist.ability(gameboard);
                    } else {
                        gameboard = paladin.ability(gameboard);
                    }
                } else {
                    if (p2Arch == "Alchemist") {
                        gameboard = alchemist.ability(gameboard);
                    } else {
                        gameboard = paladin.ability(gameboard);
                    }
                }
            }
            if ((turn > 4)) {
                if ((turn % 2) == 0) {
                    if (checkWin(p2mark) == 1) {
                        cout << "\n\n" << p2 << " has won the game.\n" << endl;
                        break;
                    }
                } else {
                    if (checkWin(p1mark) == 1) {
                        cout << "\n\n" << p1 << " has won the game.\n" << endl;
                        break;
                    }
                }
            }
            turn++;
        } while (!(boardFull()));
        cout << "\n\nThe game ends in a tie." << endl;
    }

    private: bool playAgain() {
        bool check = true;
        string input;
        do {
            cout << "\n\nWould you like to play again? Enter Yes(Y) or No(N). " << endl;
            cin >> input;
            if (cin.fail()) {
                cout << "Please enter Yes(Y) or No(N)." << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((input == "y") || (input == "Y") || (input == "n") || (input == "N")
                        || (input == "Yes") || (input == "No") || (input == "YES") || (input == "NO")) {
                check = false;
            } else {
                cout << "Please enter Yes(Y) or No(N)." << endl;
            }

        } while (check);

        if ((input == "y") || (input == "Y") || (input == "Yes") || (input == "YES")) {
            return true;
        } 
        return false;
    }

    private: void clear() {
        gameboard = clearboard;
        p1 = "";
        p2 = "";
        p1mark = "";
        p2mark = "";
        p1Arch = "";
        p2Arch = "";
    }

    public: void startGame() {
        do {
            clear();
            menu();
            if (mode == 1) {
                instructionsRegular();
                Regulargame();
            } else {
                instructionsBattle();
                Battlegame();
            }
        } while (playAgain());
        
    }
};
#endif
