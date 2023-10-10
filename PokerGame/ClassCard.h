#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace ClassCard
{
	class Card
	{
	public:
	#pragma region CONSTRUCTORS
		// Parameter:
		//	string value -> Poker card value (Two to Ace)
		//	string color -> Poker card color (Spade, Club, Diamond, Heart)
		Card(char value, char color);
	#pragma endregion

	#pragma region METHODS
		// This method returns a vector with the card skin 
		// Propertie:
		//	bool hide -> true : Hide the card
		//		       false : Show the card
		vector<string> Display(bool hide = false);

		// This method returns a vector with all properties of the card
		vector<char> GetCardProperties();
	#pragma endregion

	private:
	#pragma region PROPERTIES
		// Private property for the value of the card
		char Value;

		// Private property for the color of the card
		char Color;

		// Private property for the default card's skin
		vector<string> DefaultCardSkin = {
			"#########",
			"# %   % #",
			"#       #",
			"#   &   #",
			"#       #",
			"# %   % #",
			"#########"
		};

		vector < string> CardSkin;
	#pragma endregion

	};
}

