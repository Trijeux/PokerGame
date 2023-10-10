#include <iostream>
#include <vector>
#include <algorithm>
#include "ClassCard.h"

using namespace std;

namespace ClassCard
{
	#pragma region CONSTRUCTORS
	// Parameter:
	//	string value -> Poker card value (Two to Ace)
	//	string color -> Poker card color (Spade, Club, Diamond, Heart)
	Card::Card(char value, char color) :Value(value), Color(color) 
	{
		for (string line : DefaultCardSkin)
		{
			replace(line.begin(), line.end(), '%', Color);
			replace(line.begin(), line.end(), '&', Value);

			CardSkin.push_back(line);
		}
	}
	#pragma endregion

	#pragma region METHODS
	// This method returns a vector with the card skin 
	// Propertie:
	//	bool hide -> true : Hide the card
	//		       false : Show the card
	vector<string> Card::Display(bool hide)
	{
		if (hide)
		{
			return DefaultCardSkin;
		}
		return CardSkin;
	}

	// This method returns a vector with all properties of the card
	vector<char> Card::GetCardProperties() 
	{
		return { Value, Color };
	}
	#pragma endregion
}