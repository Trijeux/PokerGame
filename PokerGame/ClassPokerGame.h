#pragma once
#include <vector>
#include "ClassCard.h"
#include "ClassDeck.h"
#include "ClassPlayer.h"

using namespace std;
using namespace ClassCard;
using namespace ClassDeck;
using namespace ClassPlayer;

namespace ClassPokerGame
{
	class PokerGame
	{
	public:	

	#pragma region METHODS
		// This method gives one card to each player at the time
		// Parameter:
		//	Player player1	-> Main player
		//	Player player2	-> Second player
		//	Deck deck	-> The deck where to take the card to distribute
		//	char nbOfCards	-> The number of cards to distribute
		void CardsDistribution(Player& player1, Player& player2, Deck& deck, int nbOfCards);

		// This method adds cards from the deck to the common hand
		// Parameter:
		//	Deck deck	-> The deck where to take the card 
		//	char nbCard	-> The number of cards to add
		void AddCardCommonHand(Deck& deck, char nbCard);

		// This method adds tokens to the common pot
		// Parameter:
		//	int nbToken	-> the number of tokens to add to the common pot
		void FillCommonPot(int nbToken);

		// This method asks the player which action he wants to do and return it
		// Parameter:
		//	Player player	-> The player who need to do an action
		int AskForPlayerChoice(Player& player);

		// This method displays all game information
		// Format :
		//	Turn number (turn name)
		//	player1's pot | player2's pot | commun pot
		//	common hand :
		//	player1's hand :
		//	player2's hand :
		// Parameter:
		//	Player player1	-> Main player
		//	Player player2	-> Second player
		void ShowTable(Player& player1, Player& player2);

		// This method returns the current turn value
		int GetCurrentTurn();

		// This method returns the common pot
		int GetCommonPot();

		// This method displays the common hand
		void DisplayCommonHand();

		// This method returns the common pot and clear it 
		int ClearCommonPot();

		// This method clears the common hand
		void ClearCommonHand();

		// This method compares all hands and show the winner
		void GetWinner(Player& player1, Player& player2);

		// This method is a temporary method to make the software work in time
		int TempMethodToMakeTheSoftWork(vector<Card> handToCheck);
	#pragma endregion

	private:
	#pragma region PROPERTIES
		// Private property for the common pot
		int CommonPot=0;

		// Private property for the common hand
		vector<Card> CommonHand;

		// Public property for the current turn
		int currentTurn = 0;
	#pragma endregion

	#pragma region METHODS
		//int CheckHand(vector<Card> handToCheck);
	#pragma endregion 
	};
}

