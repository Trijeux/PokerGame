#include "ClassPlayer.h"
#include "ClassDeck.h"

namespace ClassPlayer
{ 
	#pragma region CONSTRUCTORS
	// Parameter:
	//	string name -> The player's name
	Player::Player(string name) :name(name) {}
	#pragma endregion

	#pragma region METHODS
	// This method allows the player to draw a card on the deck
	// Parameter:
	//	Deck deck -> The deck where to draw a card
	void Player::DrawCard(Deck& deck)
	{
		// Add a card to the player's hand
		Hand.push_back(deck.GiveCard());
	}

	// This method makes the player fill his pot with a number of tokens
	// Parameter:
	//	int nbToken -> The number of tokens to add to the player's pot
	void Player::TakeToken(int nbToken)
	{
		// Add the number of tokens to the player's pot
		pot += nbToken;
	}

	// This method allows the player to bet some tokens
	// The number of tokens can't be more than the pot and less than 1
	// Parameter:
	//	int nbToken -> The number of tokens to bet. It can't be more than the player pot or less than 1
	void Player::BetToken(int nbToken)
	{
		// if the number of tokens is bigger that the pot
		if (nbToken > pot)
		{
			// Bet all tokens in the player's pot
			cout <<"\n" << name << " parie : " << pot << "Token\n" << endl;
			pot -= pot;
			return;
		}
		// Bet the number of tokens
		cout << name << " parie : " << nbToken << "Token\n" << endl;
		pot -= nbToken;
	}

	// This method returns the number of tokens in the player's pot
	int Player::GetPot()
	{
		return pot;
	}

	// This method returns a vector with all cards in the player's hand
	vector<Card> Player::GetHand()
	{
		return Hand;
	}

	// This method displays the player's hand
	// Parameter:
	//	bool hide -> true : Hide the cards
	//		       false : Show the cards
	void Player::DisplayHand(bool hide)
	{
		// Create vector to keep the cards
		vector<string> temp;
		vector<string> actualHand = {
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		};

		// For all cards in the player's hand
		for(Card card : Hand)
		{
			// Clear the vector "temps"
			temp.clear();
			// for the size of the card
			for (char i = 0; i < card.Display().size(); i++)
			{
				// Add the card to temp line by line
				temp.push_back(actualHand[i] + " " + card.Display(hide)[i]);
			}
			// Copy temp in actual hand
			actualHand = temp;
		}
		
		// for each line in the actual hand
		for (string line : actualHand)
		{
			// Display the line
			cout << line << endl;
		}
	}

	// This method clears the player's hand
	void Player::ClearHand()
	{
		Hand.clear();
	}
	#pragma endregion
}