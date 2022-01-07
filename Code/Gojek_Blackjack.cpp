#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <limits>

using namespace std;

//Choose_a_card_function chooses a random integer 
int Choose_a_card_function() 
{ 
    return rand() % 10 + 1; 
}

int main()
{
		srand((int)time(0));
		string Option_Chosen="HIT";
		int dealer = Choose_a_card_function();
		int first = Choose_a_card_function(), second = Choose_a_card_function();
		int total = first + second;

		if (Option_Chosen == "HIT")
		{
			//Initial cards of Dealer, one card is shown as X because it is hidden from the player
			cout << "Dealer's hand: X " << dealer << endl;
			//Initial cards of PLayer chosen randomly using Choose_a_card_function function.
			cout << "Player's hand: " << first << " " << second << endl;
			do
			{   
					//The PLayer gets the first turn to choose.
				    cout << "Player's Turn: ";
				    cin >> Option_Chosen;
					//IF he player chooses to HIT, then the chosen card number is added to the players total score.
				    if (Option_Chosen == "HIT")
    				{
					    int newCard = Choose_a_card_function();
					    total += newCard;

					    cout << "Card: " << newCard << endl;
					    cout << "Total: " << total << endl;
						//if the players score gets over 21, then the player looses and the Dealer wins.
					    if (total > 21)
				    	{
						cout << "The player is busted, Dealer wins." << endl;
						//once the player looses and dealer wins, the variable option_chosen is changed to STAND and the game stops
						Option_Chosen = "STAND";
						break;
					    }
					    //if the total score of player reaches 21, then the player wins.
					    else if(total == 21)
					    {
					    cout << "Player wins." << endl;
					    }
					   
				    }
				    //If the player chooses to STAND, then the player is no longer asked to choose to pick and the dealer starts picking.
				    else if (Option_Chosen == "STAND" )
			        {
			            
					//If the total score of dealer is leass than 17, the dealer has to pick a card.
					while (dealer < 17)
					{
						cout << "Dealer's hand: X " << dealer << "..." << endl;
						string c;
						do {
							cout << "(Press NEXT to proceed) ";
							cin>>c;
						} while (c != "NEXT");

						int newDealerCard = Choose_a_card_function();
						cout << "Dealer's hand " << newDealerCard << endl;
						//Once the dealer picks a card, the cards score is added to the total dealer's score.
						dealer += newDealerCard;
						cout << "Total: " << dealer << endl;
					}

					//While determining the winner, if dealer reaches 21 and the player's score is not 21, then the player looses the game.
					if (dealer == 21 && dealer != total)
						cout << "Player Looses" << endl;
					else if (dealer == total)
						cout << "Blackjack, Dealer wins" << endl;
					else if (dealer > 21 && total > dealer && total < 21)
					//If the score of player is greater than that of dealers and  the players score is less than 21, then the player wins.
						cout << "Player wins" << endl;
						//if the toatl score of dealer is greater than that of the player and is less than 21, then the player looses.
					else if (dealer > total && dealer <= 21)
						cout << "Player looses" << endl;
					break;
				}
			} while (Option_Chosen == "HIT");
		}

	return 0;
}
