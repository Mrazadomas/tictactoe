#ifndef CAMPAIGN_H
#define CAMPAIGN_H
#include <iostream>
#include <vector>
#include "Game.h"
#include "Bot.h"
#include "Alchemist.h"
#include "Paladin.h"
#include <fstream>
#include <string>

//g++ -std=c++17 main.cpp -o c

using namespace std;

class Campaign {

    Game game;

    private: vector<int> cells = {1, 4, 7, 11, 14, 17, 21, 24, 27};

    int turn = 1;
    int act = 0; // marking game progress

    Alchemist alchemist;
    Paladin paladin;

    private: int health = 100;
    private: int attack = 60;
    private: int defense = 40;

    private: string Pname;
    private: string Parch;

    private: int money = 0;

    Bot* Kaido = new Bot("Kaido", 300, 150, 90);
    Bot* Hawkins = new Bot("Hawkins", 100, 80, 20);
    Bot* Jack = new Bot("Jack", 200, 40, 20);
    Bot* Katakuri = new Bot("Katakuri", 150, 60, 40);
    Bot* Doffy = new Bot("Doffy", 100, 60, 30);

    public: bool battle(Bot bot) {
        int h = bot.getHealth();
        int a = bot.getAttack();
        int d = bot.getDefense();

        do {
                cout << "\n" << endl;
            for (int i = 0; i < game.gameboard.size(); i++) {
                    if ((i == 9) || (i == 19)) {
                        cout << "\n" << game.gameboard[i] << endl;
                    } else {
                        cout << game.gameboard[i];
                    }
            }
            int move = 0;
            do {
                if ((turn == 1) || ((turn % 2) == 1)) {
                    cout << "\n\n" << Pname << "'s turn." << endl;
                    move = game.getMove();
                } else {
                    cout << "\n\n" << bot.getName() << "'s turn." << endl;
                    game.gameboard = bot.botMove(game.gameboard, "x");
                }
                if ((turn == 1) || ((turn % 2) == 1)) {
                        if (move == 1) {
                        game.fillTile(turn);
                    } else if (move == 2) {
                        if (Parch == "Alchemist") {
                            game.gameboard = alchemist.ability(game.gameboard);
                        } else {
                            game.gameboard = paladin.ability(game.gameboard);
                        }
                    }
                }
                if ((turn > 4)) {
                    if ((turn % 2) == 0) {
                        if (game.checkWinx() == 1) {
                            cout << "\n\n" << bot.getName() << " has won the game.\n" << endl;
                            int damage = bot.getAttack() - defense;
                            health = health - damage;
                            cout << "Your opponent did " << damage << " damage to you!" << endl;
                            if (h < 0) {
                                cout << bot.getName() << " has defeated you." << endl;
                            } else {
                                cout << "Your health is now: " << health << endl;
                                cout << "Get your opponent's health to zero to win!" << endl;
                            }
                            break;
                        }
                    } else {
                        if (game.checkWino() == 1) {
                            cout << "\n\n" << Pname << " has won the game.\n" << endl;
                            int damage = attack - bot.getDefense();
                            h = h - damage;
                            cout << "You did " << damage << " damage to " << bot.getName() << "!" << endl;
                            if (h < 0) {
                                cout << "You have defeated " << bot.getName() << "!" << endl;
                            } else {
                                cout << "Opponent's health is now: " << h << endl;
                                cout << "Get your opponent's health to zero to win!" << endl;
                            }
                            break;
                        }
                    }
                }
                turn++;
            } while (!(game.boardFull()));
            if (game.boardFull()) {
                cout << "\n\nThe game ends in a tie." << endl;
            }
            game.clear();
            turn = 1;
        } while ((health > 0) && (h > 0));
        if (health <= 0) {
            return false;
        }
        return true;
    }

    public: vector<string> thunderBagua(vector<string> gameboard) {
        cout << "\nKaido holds his massive club up to the sky directing lightning toward it, and swings it at you." << endl;
        for (int i = 0; i < cells.size(); i++) {
            if (gameboard[cells[i]] == "o") {
                gameboard[cells[i]] = " ";
            }
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

    public: bool Bossbattle(Bot bot) {
        int h = bot.getHealth();
        int a = bot.getAttack();
        int d = bot.getDefense();

        int abcount = 0; //for kaido's ability count

        do {
                cout << "\n" << endl;
            for (int i = 0; i < game.gameboard.size(); i++) {
                    if ((i == 9) || (i == 19)) {
                        cout << "\n" << game.gameboard[i] << endl;
                    } else {
                        cout << game.gameboard[i];
                    }
            }
            int move = 0;
            do {
                if ((turn == 1) || ((turn % 2) == 1)) {
                    cout << "\n\n" << Pname << "'s turn." << endl;
                    move = game.getMove();
                } else {
                    cout << "\n\n" << bot.getName() << "'s turn." << endl;
                    if (((h <= 150) && (abcount == 0)) || ((h <= 50) && (abcount == 1))) {
                        cout << "\nIn a fit of rage, Kaido uses Thunder Bagua." << endl;
                        game.gameboard = thunderBagua(game.gameboard);
                    } else {
                        game.gameboard = bot.botMove(game.gameboard, "x");
                    }
                }
                if ((turn == 1) || ((turn % 2) == 1)) {
                        if (move == 1) {
                        game.fillTile(turn);
                    } else if (move == 2) {
                        if (Parch == "Alchemist") {
                            game.gameboard = alchemist.ability(game.gameboard);
                        } else {
                            game.gameboard = paladin.ability(game.gameboard);
                        }
                    }
                }
                if ((turn > 4)) {
                    if ((turn % 2) == 0) {
                        if (game.checkWinx() == 1) {
                            cout << "\n\n" << bot.getName() << " has won the game.\n" << endl;
                            int damage = bot.getAttack() - defense;
                            health = health - damage;
                            cout << "Your opponent did " << damage << " damage to you!" << endl;
                            if (h < 0) {
                                cout << bot.getName() << " has defeated you." << endl;
                            } else {
                                cout << "Your health is now: " << health << endl;
                                cout << "Get your opponent's health to zero to win!" << endl;
                            }
                            break;
                        }
                    } else {
                        if (game.checkWino() == 1) {
                            cout << "\n\n" << Pname << " has won the game.\n" << endl;
                            int damage = attack - bot.getDefense();
                            h = h - damage;
                            cout << "You did " << damage << " damage to " << bot.getName() << "!" << endl;
                            if (h < 0) {
                                cout << "You have defeated " << bot.getName() << "!" << endl;
                            } else {
                                cout << "Opponent's health is now: " << h << endl;
                                cout << "Get your opponent's health to zero to win!" << endl;
                            }
                            break;
                        }
                    }
                }
                turn++;
            } while (!(game.boardFull()));
            if (game.boardFull()) {
                cout << "\n\nThe game ends in a tie." << endl;
            }
            game.clear();
            turn = 1;
        } while ((health > 0) && (h > 0));
        if (health <= 0) {
            return false;
        }
        return true;
    }

    void Continue() {
        string temp;
        cout << "Press enter to continue.";
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, temp);
    }

    private: int shop() { 
        bool check = true;
        int temp;
        cout << "\nWhat will you choose to buy?" << endl;
        do {
            cout << "Type 1 for the first option, 2 for the second option, or 3 for both.";
            cin >> temp;
            if (cin.fail()) {
                cout << "Please enter one of the designated numbers. \n" << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((temp == 1) || (temp == 2) || (temp == 3)) {
                check = false;
            } else {
                cout << "Please enter one of the designated numbers. \n" << endl;
            }


        } while (check);

        return temp;
    }

    public: void writeSaveFile() {
        ofstream MyFile("save.txt");

        MyFile << act << endl;
        MyFile << health << endl;
        MyFile << attack << endl;
        MyFile << defense << endl;
        MyFile << money << endl;

        MyFile.close();
    }

    public: void readSaveFile() {
        vector<int> details;
        string element;

        ifstream MyReadFile("save.txt");

        while (getline(MyReadFile, element)) {
            details.push_back(stoi(element));
       }

        MyReadFile.close();

        act = details[0];
        health = details[1];
        attack = details[2];
        defense = details[3];
        money = details[4];
    }

    public: bool actOne() {
        cout << "You will now embark your journey, your first stop, is the floral island of Dressrosa." << endl;

        Continue();

        cout << "\nUpon your arrival, you notice several humanoid marionettes walking beside the people of the town." << endl; 

        Continue();

        cout << "Something is off. A child bumps into you as you walk by." << endl;

        Continue();

        cout << "You look back at her. You can barely see her face, but she wears this sinister smile that makes you shiver. You keep walking." << endl;

        Continue();

        cout << "You decide to follow her." << endl;

        Continue();

        cout << "You find yourself in an underground lab surrounded by enemies." << endl;

        Continue();

        cout << "Doffy appears from the shadows..." << endl;

        Continue();

        cout << "Doffy reveals that he is producing fake devil fruits that make people go insane and selling them to the public." << endl;

        Continue();

        cout << "Doffy also reveals that he is the one turning human beings into marionettes to be his puppet slaves." << endl;

        Continue();

        cout << "You ask Doffy to stop, but he then attempts to make you a puppet. You fight back." << endl;

        Continue();

        if (battle(*Doffy) == true) {
            act = 1;
            money += 100000;
        } else {
            return false;
        }
        writeSaveFile();
        return true;

    }

    public: bool actTwo() {
        cout << "You have now defeated Doffy and stole his treasure worth one hundred thousand berries." << endl;

        Continue();

        cout << "You walk out of the underground lab and the people of Dressrosa cheer for you as you just set them free of Doffy's tyrannical rule." << endl;

        Continue();

        cout << "You board your ship and head for the next island, Whole Cake Island." << endl;

        Continue();

        cout << "This island is inhabited by one of the most feared emperors of the sea, Big Mom, so tread carefully." << endl;

        Continue();

        cout << "You finally reach Whole Cake Island, and the island appears to be made entirely of sweets." << endl;

        Continue();

        cout << "You get sidetracked a little as you indulge on the chocolate tasting dirt, but you remember why you came here." << endl;

        Continue();

        cout << "It was to find an ancient text that is said to hold the directions to the ancient island of Wano Kuni." << endl;

        Continue();

        cout << "You start snooping around the island and run into the island guards, but you let them take you." << endl;

        Continue();

        cout << "You finally get into Big Mom's fortress with the help of the guards that you knocked out just a few seconds ago, and are now looking for the text" << endl;

        Continue();

        cout << "You finally find the ancient text in a secret room that you discovered by accidentally walking into a mirror." << endl;

        Continue();

        cout << "But you are not alone in the room. One of Big Mom's sons, Katakuri, catches you in the act and nearly pierces you in the chest with his mochi-mochi devil fruit." << endl;

        Continue();

        cout << "You fight back." << endl;

        if (battle(*Katakuri) == true) {
            act = 2;
            money += 400000;
        } else {
            return false;
        }
        writeSaveFile();
        return true;
    }

    public: bool actThree() {
        cout << "You have beaten Katakuri and his elite defense, and now pillage Big Mom's fortress for a total of four hundred thousand berries." << endl;

        Continue();

        cout << "You take the ancient text, and flee the island before Big Mom sees you." << endl;

        Continue();

        cout << "Before leaving the island you decide to run over to a shop right by the water." << endl;

        cout << "Tillman's Seaside Shop." << endl;
        cout << "Ancient Scroll of Observation: 500000 berries." << endl;
        cout << "Food (heal to max health): 100000." << endl;
        cout << "\nYour balance is: " << money << " berries" << endl;

        bool check = true;
        do {

            int choice = shop();

            if (choice == 1) {
                money = 0;
                cout << "You buy the scroll." << endl;

                Continue();

                cout << "You open the scroll and read the poem inside." << endl;

                Continue();

                defense *= 2.5;

                cout << "\nYour defense has increased to " << defense << endl;
                check = false;
            } else if (choice == 2) {
                health = 100;

                money -= 100000;

                cout << "You are now max health." << endl;
                check = false;
            } else if (choice == 3) {
                cout << "You do not have enough berries to buy both." << endl;
            } 
        } while (check == true);

        cout << "You set sail again until you see a thick fog starting to form around you." << endl;

        Continue();

        cout << "All of a sudden you run into a large gray pillar in the middle of the sea." << endl;

        Continue();

        cout << "You and your crew decide to climb it." << endl;

        Continue();

        cout << "Once you reach the top you see civilization, trees, ponds." << endl;

        Continue();

        cout << "But you also see buildings on fire and pirates attacking the villagers." << endl;

        Continue();

        cout << "You and your crew engage the pirates and fight them. You take on their captain, Jack." << endl;

        if (battle(*Jack) == true) {
            act = 3;
            money += 10000;
        } else {
            return false;
        }
        writeSaveFile();
        return true;
    }

    public: bool actFour() {
        cout << "Jack's crew didn't have much berries on them, so you climb down and set sail to Wano Kuni." << endl;

        Continue();

        cout << "The voyage to Wano Kuni was extremely rough, but you make it nonetheless." << endl;

        Continue();

        cout << "You are walking through the bamboo forest of Wano Kuni when all of a sudden a samurai prophet approaches you." << endl;

        Continue();

        cout << "His name is Danzo, and says he has been expecting you for a long time." << endl;

        Continue();

        cout << "His prophecy is that you will liberate the land of Wano from the reign of the Animal Beast Pirates and restore the land." << endl;

        Continue();

        cout << "He explains that Kaido, the captain of the Animal Beast Pirates, has turned people into slaves, imprisoned innocent people, and killed the last emperor of Wano." << endl;

        Continue();

        cout << "With that prophecy he also hands you a sword named Enma. A legendary sword of the last great emperor that was slain by Kaido." << endl;

        Continue();

        attack += 20;

        cout << "Your attack has increased to " << attack << endl;

        Continue();

        cout << "You start your journey to the floating island of Onigashima right above Wano, where Kaido lives and watches over Wano." << endl;

        Continue();

        cout << "During your journey you run into one of Kaido's lackeys, Hawkins." << endl;

        Continue();

        cout << "You have become a very wanted pirate worth over 1 billion berries, and Hawkins says he is going to claim that bounty." << endl;

        Continue();

        cout << "You and Hawkins clash." << endl;

        if (battle(*Hawkins) == true) {
            act = 4;
            money += 1000000;
        } else {
            return false;
        }
        writeSaveFile();
        return true;
    }

    public: bool finalAct() {
        cout << "When you defeat Hawkins, he reveals that Kaido is the strongest pirate in the world, and there is no way anyone can beat him." << endl;

        cout << "Turns out Hawkins also had a decently high bounty, and you turn him in for 1 million berries." << endl;

        Continue();

        cout << "Next to police precinct, you spot a shop. You enter it." << endl;

        Continue();

        cout << "Wano Shop." << endl;
        cout << "Ancient Scroll of Ryou: 500000 berries." << endl;
        cout << "Food (heal to max health): 100000." << endl;
        cout << "\nYour balance is: " << money << " berries" << endl;

        bool check2 = true;
        do {

            int choice = shop();

            if (choice == 1) {
                money = 0;
                cout << "You buy the scroll." << endl;

                Continue();

                cout << "You open the scroll and read the poem inside." << endl;

                Continue();

                attack *= 1.5;

                cout << "\nYour attack has increased to " << attack << endl;
                check2 = false;
            } else if (choice == 2) {
                health = 100;

                money -= 100000;

                cout << "You are now max health." << endl;
                check2 = false;
            } else if (choice == 3) {
                money -= 500000;
                cout << "You buy the scroll." << endl;

                Continue();

                cout << "You open the scroll and read the poem inside." << endl;

                Continue();

                attack *= 1.5;

                cout << "\nYour attack has increased to " << attack << endl;

                health = 100;

                money -= 100000;

                cout << "You are now max health." << endl;
                check2 = false;
            } 
        } while (check2 == true);

        Continue();

        cout << "As you climb a mountain to get closer to Onigashima, a crazy person runs down the mountain steps, and drops a suspicious looking scroll." << endl;

        Continue();

        cout << "The scroll read: The Scroll of the Fifth" << endl;

        Continue();

        cout << "You read the scroll, but all of a sudden you faint." << endl;

        Continue();

        cout << "All you see is a rainbow of colors, and feel a thumping sensation throughout you body." << endl;

        Continue();

        cout << "When you awake you are glowing, radiating light and energy." << endl;

        Continue();

        cout << "Your clothes have turned white, your hair has turned white, and you have a white halo circling you." << endl;

        cout << "\nYou have become the warrior of liberation, wielding the power of the Fifth." << endl;

        defense *= 2;
        attack *= 2;

        cout << "\nYour attack has increased to " << attack << endl;
        cout << "\nYour defense has increased to " << defense << endl;

        Continue();

        cout << "Suddenly Kaido appears in front of you and swings his massive club at you." << endl;

        Continue();

        cout << "You deflect it like nothing." << endl;

        Continue();

        cout << "Kaido scoffs as he was just testing you, he says that there is not one pirate as strong as him." << endl;

        if (Bossbattle(*Kaido) == true) {
            money += 100000000;
        } else {
            return false;
        }

        cout << "You have defeated Kaido, and now are the strongest and wealthies pirate on earth as you pillage over 100 million berries." << endl;

        cout << "Thanks for playing the Tales of Nika!" << endl;

        return true;
    }

    public: void campaignGame() {

        cout << "\n\nWelcome to the Tales of Nika game!\n" << endl;
        cout << "You are a pirate in the New World and will commandeer your crew through islands and defeat powerful foes." << endl;
        cout << "Enter your pirate name: ";
        cin >> Pname;
        Parch = game.getArchetype();
        cout << "reading saved file..." << endl;
        try {
            readSaveFile();
        } catch (int e) {
            cout << "error" << endl;
        }

        if (act == 0) {
            if (actOne()) {
                if (actTwo()) {
                    if (actThree()) {
                        if (actFour()) {
                            finalAct();
                        }
                    }
                }
            }

        } else if (act == 1) {
            if (actTwo()) {
                    if (actThree()) {
                        if (actFour()) {
                            finalAct();
                        }
                    }
                }
        } else if (act == 2) {
            if (actThree()) {
                    if (actFour()) {
                        finalAct();
                    }
        } else if (act == 3) {
            if (actFour()) {
                        finalAct();
                    }
        } else if (act == 4) {
            finalAct();
        }
        

        
    }

    //g++ -std=c++17 main.cpp -o c






    }
};
#endif
