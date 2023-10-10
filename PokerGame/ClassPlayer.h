#pragma once
#include <iostream>
#include <vector>
#include "ClassDeck.h"

using namespace std;
using namespace ClassDeck;
using namespace ClassCard;

namespace ClassPlayer
{
	class Player
	{
	public:
	#pragma region CONSTRUCTORS
		// Parameter:
		//	string name -> The player's name
		Player(string name);
	#pragma endregion

	#pragma region PROPERTIES
		// Public property for the name of the player
		string name;
	#pragma endregion

	#pragma region METHODS
		// This method allows the player to draw a card on the deck
		// Parameter:
		//	Deck deck -> The deck where to draw a card
		void DrawCard(Deck& deck);

		// This method makes the player fill his pot with a number of tokens
		// Parameter:
		//	int nbToken -> The number of tokens to add to the player's pot
		void TakeToken(int nbToken);

		// This method allows the player to bet some tokens
		// The number of tokens can't be more than the pot and less than 1
		// Parameter:
		//	int nbToken -> The number of tokens to bet. It can't be more than the player pot or less than 1
		void BetToken(int nbToken);

		// This method returns the number of tokens in the player's pot
		int GetPot();

		// This method returns a vector with all cards in the player's hand
		vector<Card> GetHand();

		// This method displays the player's hand
		// Parameter:
		//	bool hide -> true : Hide the cards
		//		       false : Show the cards
		void DisplayHand(bool hide = false);

		// This method clears the player's hand
		void ClearHand();
	#pragma endregion

	private:
	#pragma region PROPERTIES
		// Private property for the number of player's tokens
		int pot = 1000;

		// Private property for the hand of the player
		vector<ClassCard::Card> Hand;
	#pragma endregion
	};
}

