#include <iostream>
#include <algorithm>
#include<random>
#include <vector>
#include "ClassDeck.h"
#include "ClassCard.h"

using namespace std;

namespace ClassDeck
{
	// This method will fill the "Deck" object with the 52 poker cards and add it to the "Pack" private property
	void Deck::FillDeck()
	{
		// Make a list "cardValue" with all poker cards values from Two to Ace
		string cardValue[13]
		{
			"Deux",
			"Trois",
			"Quatre",
			"Cinq",
			"Six",
			"Sept",
			"Huit",
			"Neuf",
			"Dix",
			"Valet",
			"Reine",
			"Roi",
			"As"
		};

		// Make a list "cardColor" with all poker cards colors (Spade, Club, Diamond, Heart)  
		string cardColor[4]
		{
			"Pique",
			"Trefle",
			"Carreau",
			"Coeur"
		};

		// Instantiate a variable i for iteration 
		int i = 0;

		// For all color in cardColor
		for (const string& color : cardColor)
		{
			// For all value in cardValue
			for (const string& value : cardValue)
			{
				// Make a ClassCard with the parameters "value" and "color" from "cardValue" and "cardColor" and add it to the deck's property list "Pack"
				Pack.push_back(ClassCard::Card(value, color));
				// Increment the variable i
				i++;
			}
		}
	}

	// This method will copy the private property "Pack" in the private property "Blend" and shuffle it
	void Deck::BlendDeck()
	{
		// Make a copy of the vector "Pack" inside of Blend
		Blend = Pack;

		// Shuffle the vector "Blend"
		shuffle(Blend.begin(), Blend.end(), default_random_engine(0));
		/*C++17 removed
		random_shuffle(Blend.begin(), Blend.end());*/
	}

	// This method return the top card of the shuffled deck and delete it
	ClassCard::Card Deck::GiveCard()
	{
		ClassCard::Card card = Blend[Blend.size()-1];
		Blend.pop_back();
		return card;
	}
}