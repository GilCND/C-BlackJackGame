/*
Author: Felipe SG 
Date: 15/11/2020
Program: Player.h
Program Details: 
Blackjack Game

Create a command-line blackjack game using OOP principles and the following criteria:

Player is prompted for first name
Use an array to represent the 52 cards (values 1-52). Store as attribute within card class
When the game starts, randomize entries in card array, calculate the user's current score (cards 0,1 in array) and the house score (cards 2,3 in array) and display. Prompt the user to hit or stay
Each time the player indicates "hit", a new card value is added to their score (the next value from the array) and displayed.
If the player score exceeds 21, the player loses (remember the ace can be a 1 OR 11 => value is 11 while the score <= 21 and downward adjusted when a value of 11 would exceed 21).
When the "stay" option is indicated, the "house" starts drawing cards from the array from where the player left off. After each card is drawn, the house score is adjusted and checked. Card are continually drawn until the house score is equal or greater to the player score.
If the house score is > 21, the house busts and the player is awarded 50pts.
If the player busts or the house score is >= player score (without busting), 50pts is deducted from the player score.
At the end of the hand, the player may continue or quit
Class member functions are used to calculate the score.

-------------------------------------------------------------------------------------
Change log
-------------------------------------------------------------------------------------
|       Date        |   Programmer   |                   Changelog                   | 
    Nov-13-2020         Felipe SG                   First Version  1.0         
    Nov-14-2020         Felipe SG                   First Version  1.1         
    Nov-15-2020         Felipe SG                   First Version  1.2         
*/

#include <iostream>
using namespace std;

class Player
{
    private:
        string playerName;
        int playerPoints;

    public:
        //Constructor
        Player();
        Player (string g);
        Player(string s, int z);

        //Destructor
        ~Player();

        //Setters
        void setPlayerName(string n);
        void setPlayerPoints(int y);
        
        //Getters
        string getPlayerName();
        int getPlayerPoints();
};
