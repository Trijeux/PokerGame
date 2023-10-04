
#include "ClassPlayer.h"
#include "ClassDeck.h"
#include <list>

using namespace std;

namespace ClassPlayer
{
	// This method make the player draw a card on the deck and return the number of cards on hand
	int Player::DrawCard(ClassDeck::Deck& deck)
	{
		hand.push_back(deck.GiveCard());
		return hand.size();
	}

	// This method clear the player hand
	void Player::ClearHand()
	{
		hand.clear();
	}

	// This method allow the player to bet a sum. 
	// The sum can't be more than the pot allowed and less than 1
	void Player::BetToken(int nbToken)
	{
		if (nbToken > pot) pot -= pot;
		else pot -= nbToken;
	}

	// This method make the player fill his pot with a number of tokens
	void Player::GetToken(int nbToken)
	{
		pot += nbToken;
	}

	// This method show the number of tokens in the player's pot
	int Player::ShowPot()
	{
		return pot;
	}

	// This method show the cards in the player's hand
	void Player::ShowHand()
	{
		list<string>playerHand{};

		for (ClassCard::Card card : hand)
		{
			cout << card.Display() << endl;
		}
	}


}