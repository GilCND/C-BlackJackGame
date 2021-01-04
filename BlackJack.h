/*
Author: Felipe SG 
Date: 
Program: 
Program Details: 

-------------------------------------------------------------------------------------
Change log
-------------------------------------------------------------------------------------
|       Date        |   Programmer   |                   Changelog                   | 
    Nov-12-2020         Felipe SG                   First Version  1.0         

*/

#include <iostream>
using namespace std;


class BlackJack
{
    private:
        string playerName;
        string cardName;
        int value;
        int points;

    public:
     //Constructor
        BlackJack();
        BlackJack(string n);

        //Destructor
        ~BlackJack();
    
        //Setters
        void setPlayerName(string n);
        void setCardName(string n);
        void setValue(int y);
        void Display();
        
        //Getters
        string getPlayerName();
        string getCardName();
        int getValue();

};
