#include <iostream>
#include "ClassCard.h"

using namespace std;

namespace ClassCard
{
	// Property:
	//	Value -> Poker card value (Two to Ace)
	//	color -> Poker card color (Spade, Club, Diamond, Heart)
	Card::Card(string value, string color) :value(value), color(color) {}

	// Return a string value of all property of the object
	string Card::ToString()
	{
		// value of color
		return value + " de " + color;
	}
}