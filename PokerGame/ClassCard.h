#pragma once
#include <iostream>

using namespace std;

namespace ClassCard
{
	class Card
	{
	public:
		// Default constructor
		Card() = default;

		// Property:
		//	Value -> Poker card value (Two to Ace)
		//	color -> Poker card color (Spade, Club, Diamond, Heart)
		Card(string value, string color);

		// Return a string value of all property of the object
		string ToString();

	private:
		// Private property for the value of the card
		string value;

		// Private property for the color of the card
		string color;
	};
}

