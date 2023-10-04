#include <iostream>
#include "ClassCard.h"
#include "ClassDeck.h"
#include "ClassPlayer.h"

#pragma region using
using Card = ClassCard::Card;
using Deck = ClassDeck::Deck;
using Player = ClassPlayer::Player;

using namespace std;
#pragma endregion

int main()
{
	Player player1;
	Player player2;
	Deck gameDeck;
	gameDeck.FillDeck();
	gameDeck.BlendDeck();
	//int communPot;
	int nbPlayers = 2;
	bool gameContinue = true;


	for (int i = 0; i < nbPlayers; i++)
	{
		player1.DrawCard(gameDeck);
		player2.DrawCard(gameDeck);
	}
		
	while (true)
	{
		cout << "Veuillez choisir une action <1>Miser <2>Parler <3>Ce coucher : \n";
		string choice;
		cin >> choice;

		if (choice == "1")
		{
			player1.BetToken();
		}
		else if (choice == "2")
		{
			break;
		}
		else if (choice == "3")
		{
			//player2.GetToken(communPot);
		}
	}

	return 0;
}
