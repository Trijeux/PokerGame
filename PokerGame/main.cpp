﻿#include <iostream>
#include <Windows.h>
#include "ClassDeck.h"
#include "ClassPlayer.h"
#include "ClassPokerGame.h"

#pragma region using
using namespace ClassDeck;
using namespace ClassPlayer;
using namespace ClassPokerGame;

using namespace std;
#pragma endregion

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	#pragma region Variables
	Player player("Player1");
	Player bot("Bot");
	Deck gameDeck;
	PokerGame gameTable;
	#pragma endregion

	// Fill de deck with the 52 poker cards
	gameDeck.FillDeck();

	do
	{
		// Shuffle the deck
		gameDeck.BlendDeck();

		// clear the player and bot's hands
		player.ClearHand();
		bot.ClearHand();

		// Distribute the cards to the player and bot
		gameTable.CardsDistribution(player, bot, gameDeck, 2);

		do
		{
			// Ask the player to do an action
			int playerChoice = gameTable.AskForPlayerChoice(player);

			if (playerChoice == 1) // If the action is bet
			{
				int betSum;
				do
				{
					// Show the table with all information
					gameTable.ShowTable(player, bot);

					// Ask the player how much he want to bet
					cout << "\nVeuillez choisir une mise entre 1 et " << player.GetPot() << " : " << endl;
					cin >> betSum;

					// If the bet is valable, break the loop
					if (betSum < player.GetPot() && betSum>0) break;
					// If the bet is not valable, show a message
					cout << "\nCette mise n'est pas permise, veuillez choisir une mise possible." << endl;
					system("PAUSE");
				} while (true);

				// The player bet the sum of token
				player.BetToken(betSum);
				gameTable.FillCommonPot(betSum);

				// Show the new table's value
				system("PAUSE");
				gameTable.ShowTable(player, bot);

				cout << endl;
				
				// The bot follow the player
				bot.BetToken(betSum);
				gameTable.FillCommonPot(betSum);

				// Show the new table's value
				system("PAUSE");
				gameTable.ShowTable(player, bot);
			}
			else if (playerChoice == 2)
			{
				// The player check
				cout << player.name << " : Je check!" << endl;

				// restart the table's displayed informations
				system("PAUSE");
				gameTable.ShowTable(player, bot);

				cout << endl;

				// The bot follow the player
				cout << bot.name << " : Je check!" << endl;

				// restart the table's displayed informations
				system("PAUSE");
				gameTable.ShowTable(player, bot);
			}
			else // else the action is to quit
			{
				cout << player.name << " : Je me couche." << endl;
				cout << bot.name << " gagne la partie et touche : " << gameTable.GetCommonPot() << "Token" << endl;
				bot.TakeToken(gameTable.ClearCommonPot());
				gameTable.ClearCommonHand();
				system("PAUSE");
				break;
			}

			if (gameTable.GetCurrentTurn() < 4)
			{
				// if it's the first turn, add 3 cards to te commun hand, else only 1 card
				int nbCard = gameTable.GetCurrentTurn() == 1 ? 3 : 1;
				gameTable.AddCardCommonHand(gameDeck, nbCard);
				gameTable.ShowTable(player, bot);
				continue;
			}
			
			cout << "Fin de la manche. \nVerification du vainqueur." << endl;
			system("PAUSE");

			gameTable.GetWinner(player, bot);

			gameTable.ClearCommonHand();
			break;
		} while (true);
	} while (player.GetPot() >= 0 || bot.GetPot() >= 0);
	
	return 0;
}