#pragma once
#include<iostream>
#include<vector>
#include "ClassDeck.h"

using namespace std;

namespace ClassPlayer
{
	class Player
	{
	public:
		// This method make the player draw a card on the deck and return the number of cards on hand
		int DrawCard(ClassDeck::Deck& deck);

		// This method clear the player hand
		void ClearHand();

		// This method allow the player to bet some tokens. 
		// The number of tokens can't be more than the pot and less than 1
		int BetToken();

		// This method make the player fill his pot with a number of tokens
		void GetToken(int nbToken);

		// This method show the number of tokens in the player's pot
		int ShowPot();

		// This method show the cards in the player's hand
		void ShowHand();

	private:
		// Private property for the hand of the player
		vector<ClassCard::Card> hand;

		// Private property for the number of player's tokens
		int pot;
	};
}

