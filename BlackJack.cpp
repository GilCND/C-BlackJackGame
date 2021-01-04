/*
Author: Felipe SG 
Date: 15/11/2020
Program: BlackJack.cpp
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
#include <vector>
#include <random>
#include  <numeric>
#include "Card.h"
#include "Player.h"


using namespace std;


vector <int> player{};
vector <int> dealer{};
bool running = false, status = true, winner;
int playerHand;
int dealerHand;
int counter =3; 
int score = 0;
vector<Card> cards;
vector<Player>playerInfo;

//Function part of Shuffle/Random 
void show(vector<int> const &input) {
   for (auto const& i: input) {
      std::cout << i << " ";
   }
}
void drawCard(vector<Card>& cards)
{
    int valueCP = cards[counter].getCardValue();
    player.insert(player.end(),valueCP);
}

void drawDaelersCard(vector<Card>& cards)
{
    int valueD = cards[counter].getCardValue();
    dealer.insert(dealer.end(),valueD);
}
// Create All 52 objects
void addCard(vector<Card>& cards)
{
    //Initialize a new card object
    string cardSuit;
    int cardValue;

    //Add cards to deck of cards using loop
    for (int i=1; i<=52; i ++)
    {
        if (i <= 13)
        {
            cardSuit = "Hearts";
            if (i > 10)
            {
                cardValue = 10;
            }
            else
            {
                 cardValue = i;
            }          
        }
        else if (i > 13 && i <=26)
        {
            cardSuit = "Clubs";
            if ((i -13) > 10)
            {
                cardValue = 10;
            }
            else
            {
                 cardValue = (i-13);
            }
        }
        else if (i > 26 && i <=39)
        {
            cardSuit = "Diamonds";
            if ((i -26) > 10)
            {
                cardValue = 10;
            }
            else
            {
                 cardValue = (i-26);
            }
        }
        else if ( i >39)
        {
            cardSuit = "Spades";
            if ((i -39) > 10)
            {
                cardValue = 10;
            }
            else
            {
                 cardValue = (i-39);
            }
        }
         //Create new object
        Card newCard(cardSuit, cardValue);
        //Grab the object and push back on vector
        cards.push_back(newCard);
    }
}

// Display Vector 
void displayVector(const vector<int> inVec)
{
    for(auto element = inVec.cbegin(); element != inVec.cend(); ++element)
    {
        cout << *element << " ";
    }
    cout << endl;
}

void shuffleCards()
{
    for (int a =0; a < rand(); a++)
    {
        int size = cards.size();
        for (int i = 0; i < size - 1; i++) 
        {
            int j = i + rand() % (size - i);
            swap(cards[i], cards[j]);
        }
    }
}

void initialHand(vector<Card>& cards)
{
    //Draw 2 card to Player and Dealer
    for (int c =0; c<=1; c++)
    {       
        //Player card Validation
        int valueCP = cards[c].getCardValue();
        if (valueCP == 1)
        {
            valueCP = 11;
            player.insert(player.end(),valueCP);
        }
        else
        {
           player.insert(player.end(),valueCP);
        }
        
       //Daeler card Validation   
        int valueD = cards[c+2].getCardValue();
        if (valueD ==1)
        {
            valueD = 11;
            dealer.insert(dealer.end(),valueD);
        }
        else
        {
            dealer.insert(dealer.end(),valueD);
        }
    }
}

void validateCardScore(vector<int>& player)
{
    int e = player.size();
    int z = dealer.size();
    int valueOfpVector;
    int valueOfdVector;

    if (playerHand <=10)
    {
        //if the sum of players hand is less or equal to 10
        //do
        //search for number 1 in the vector of players hand
        for (int i=0; i<e; i++)
        {
            valueOfpVector = player[i];
            if (valueOfpVector == 1)
            {
                player[i] = 11;
            }
        }
    }
    else if (playerHand > 10)
    {
        for (int i=0; i<e; i++)
        {
            valueOfpVector = player[i];
            if (valueOfpVector == 11)
            {
                player[i] = 1;
            }
        }
    }
    else if (dealerHand <=10)
    {
        //if the sum of daelers hand is less or equal to 10
        //do
        //search for number 1 in the vector of daelers hand
        for (int i=0; i<z; i++)
        {
            if (valueOfdVector == 1)
            {
                dealer[i] = 11;
            }
        }
    }
    else if (dealerHand > 10)
    {
        for (int i=0; i<z; i++)
        {
            if (valueOfdVector == 11)
            {
                dealer[i] = 1;
            }
        }
    }
}



void calculateScore()
{
    playerHand = accumulate(player.rbegin(), player.rend(), 0);
    dealerHand = accumulate(dealer.rbegin(), dealer.rend(), 0);
}

void result ()
{
    cout << "Your hand: ";
    displayVector(player);
    cout << "The sum is: "; 
    cout << playerHand << endl;

    cout << "Daeler hand ";
    displayVector(dealer);
    cout << "The sum is: "; 
    cout << dealerHand << endl; 
}

void checkWinner()
{
    
    //calculateScore(player);  
    if (playerHand > 21 && dealerHand <= 21)
    {
        //House Wins 
        cout << "  " << endl;
        cout << "House Wins!"<< endl;   
        status = false;
        score = score - 50;
        playerInfo[0].setPlayerPoints(score);

    }
    else if (playerHand <=21 && dealerHand >21)
    {
        //Player Wins 
        cout << "  " << endl;
        cout << "Player Wins!"<< endl;
        status = false;
        score = score + 50;
        playerInfo[0].setPlayerPoints(score);

    }
    else if ( playerHand <= 21 && dealerHand <= 21)
    {

            if (dealerHand < playerHand)
        {
            //Player Wins 
            cout << "  " << endl;
            cout << "Player Wins!"<< endl;
            status = false;
            score = score + 50;
            playerInfo[0].setPlayerPoints(score);
        }
        if (dealerHand > playerHand)
        {
            //House Wins
            cout << "  " << endl;
            cout << "House Wins!"<< endl;
            status = false;
            score = score - 50;
            playerInfo[0].setPlayerPoints(score);
        }    
        if (playerHand == dealerHand)
        {
            //Tie
            cout << "  " << endl;
            cout << "TIE!"<< endl;
            status = false;
        }
    
    }
    else if (playerHand > 21 && dealerHand > 21)
    {
        //Tie
        cout << "TIE!"<< endl;
        status = false;  
    }
}

void printScore()
{
    string pName = playerInfo[0].getPlayerName();
    int pPoints = playerInfo[0].getPlayerPoints();
    cout << "Thank you for playing "; 
    cout << pName;
    cout << " you have ";
    cout << pPoints;
    cout << " points";
}



int main ()
{
    string option = "h", option2 = "", name;
    int p, h;
   
    //Start the game with both, player and dealer hands
    addCard(cards);
    
    //Shuffle vector at the start
    shuffleCards();

    //Give the inital Hand to both players
    initialHand(cards);
   
    //Save players name 
    if (running == false)
    {
        //Running here is used to only create a player when the game first start.
        cout << "Welcome to BackJack" << endl;
        cout << "-------------------" << endl;
        cout << "PLease Type your Name: ";
        cin >> name;
        Player newPlayer(name);
        playerInfo.push_back(newPlayer); 
        running = true;       
        //As soon as the player enters its name, this section will no longer appear.
    }
    //Start the game, Draw 2 hand with 2 cards each
    validateCardScore(player);
    calculateScore();
    result();
    
    //The game will be contained in this loop unitll Player decide to end the game pressing "h"
    while (option =="h" || option == "h")
    {
        //Status true is used to never execute its contents if the game is over
        if (status == true)
        {
            cout << "Stand or Hit (S/H)" << endl;
            cin >> option;

            //if player choose h draw new card  
            if (option == "H" || option == "h")
            {
                counter ++;
                drawCard(cards);
                validateCardScore(player);
                calculateScore();
                result();

                if (playerHand > 21)
                {
                    break;
                }
                else if ( dealerHand > 21)
                {
                    break;
                }
            }

            else if (option == "s" && option =="s")
            {
                while (playerHand > dealerHand)
                {
                    counter ++;
                    drawDaelersCard(cards);
                    calculateScore();
                    result();
                }

            }
        }
        else if (status == false)
        {
            break;
        }  
    }
        //Pressed Hit or game over
        //Print player score from object
        system("CLS");
        result();
        checkWinner();
        calculateScore();
        printScore();

        cout << "\n\n Another match? (Y/N)"<< endl;
        cin >> option2;
        if (option2 == "y" || option2 == "Y")
        {
            player.clear();
            dealer.clear();
            counter = 3;
            status = true;
            playerHand = accumulate(player.rbegin(), player.rend(), 0);
            dealerHand = accumulate(dealer.rbegin(), dealer.rend(), 0);
            main();
        }
    return 0;
}



