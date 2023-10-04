#pragma once
#include <iostream>
#include <vector>
#include "ClassCard.h"

using namespace std;

namespace ClassDeck
{ 
	class Deck
	{
	public:
		// This method will fill the "Deck" object with the 52 poker cards and add it to the "Pack" private property
		void FillDeck(); 

		// This method will copy the private property "Pack" in the private property "Blend" and shuffle it
		void BlendDeck();

		// This method return the top card of the shuffled deck and delete it
		ClassCard::Card GiveCard();

		
	private:
		// Private property for orderly poker card deck
		vector<ClassCard::Card> Pack;

		// Private property for shuffled poker card deck
		vector<ClassCard::Card> Blend;
		
	};
}

