#include <iostream>
#include <algorithm>
#include <random>
#include "ClassDeck.h"
#include "ClassCard.h"

namespace ClassDeck
{
	#pragma region METHODS
	// This method fills the pack with the 52 cards
	void Deck::FillDeck()
	{
		// Make a list "cardValue" with all poker card values from Two to Ace
		char cardValue[13]
		{
			'2',
			'3',
			'4',
			'5',
			'6',
			'7',
			'8',
			'9',
			'T',
			'J',
			'Q',
			'K',
			'A'
		};


		// Make a list "cardColor" with all poker card colors (Spade, Club, Diamond, Heart)  
		char cardColor[4]
		{
			'C',
			'D', 
			'H',
			'S'
		};

		// For all colors in cardColor
		for (char& color : cardColor)
		{
			// For all values in cardValue
			for (char& value : cardValue)
			{
				// Make a card with the parameters "value" and "color" from "cardValue" and "cardColor" and add it to the Pack
				Pack.push_back(Card(value, color));
			}
		}
	}

	// This method copies the pack in blend and shuffle it
	void Deck::BlendDeck()
	{
		// Make a copy of the vector "Pack" inside of Blend
		Blend = Pack;

		// Shuffle the vector "Blend"
		shuffle(Blend.begin(), Blend.end(), default_random_engine(0));
	}

	// This method returns the top card of the shuffled deck and delete it
	Card Deck::GiveCard()
	{
		// Get the last card on the vector "Blend"
		Card card = Blend[Blend.size() - 1];

		// Delete the last card of the vector "Blend"
		Blend.pop_back();

		return card;
	}
	#pragma endregion
}