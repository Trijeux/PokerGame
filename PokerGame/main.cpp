#include <iostream>
#include "ClassCard.h"
#include "ClassDeck.h"
#include "ClassPlayer.h"
#include "FonctionBot.h"

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
	int mise;


	for (int i = 0; i < nbPlayers; i++)
	{
		player1.DrawCard(gameDeck);
	}

	while (true)
	{
		cout << "Veuillez choisir une action <1>Miser <2>Parler <3>Ce coucher : \n";
		string choice;
		cin >> choice;

		if (choice == "1")
		{
			
			do
			{
				cout << "Choisi ta mise :";
				cin >> mise;
				if (mise < 1 || mise > player1.ShowPot())
				{
					cout << "La mise n'est pas valide" << endl;
				}
			} while (mise < 1 || mise > player1.ShowPot());
			player1.BetToken(mise);
		}
		else if (choice == "2")
		{
			break;
		}
		else if (choice == "3")
		{
			//player2.GetToken(communPot);
		}

		int potplayer2 = MainFonctionBot(choice, mise);

		cout << player1.ShowPot() << endl;
		cout << potplayer2 << endl;

	}

	return 0;
}
