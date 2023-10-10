#pragma once
#include <iostream>
#include <vector>
#include "ClassCard.h"

using namespace std;
using namespace ClassCard;

namespace ClassDeck
{ 
	class Deck
	{
	public:
	#pragma region METHODS
		// This method fills the pack with the 52 cards
		void FillDeck();

		// This method copies the pack in blend and shuffle it
		void BlendDeck();

		// This method returns the top card of the shuffled deck and delete it
		Card GiveCard();
	#pragma endregion

	private:
	#pragma region PROPERTIES
		// Private property for orderly poker card deck
		vector<ClassCard::Card> Pack;

		// Private property for shuffled poker card deck
		vector<ClassCard::Card> Blend;
	#pragma endregion
	};
}

