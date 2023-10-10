#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <map>
#include "ClassPokerGame.h"

using namespace std;

namespace ClassPokerGame
{
	#pragma region METHODS

	// This method gives one card to each player at the time
	// Parameter:
	//	Player player1	-> Main player
	//	Player player2	-> Second player
	//	Deck deck	-> The deck where to take the card to distribute
	//	char nbOfCards	-> The number of cards to distribute
	void PokerGame::CardsDistribution(Player& player1, Player& player2, Deck& deck, int nbOfCards)
	{
		currentTurn = 1;
		for (char i = 0; i < nbOfCards; i++)
		{
			player1.DrawCard(deck);
			ShowTable(player1, player2);
			Sleep(1000);
			player2.DrawCard(deck);
			ShowTable(player1, player2);
			Sleep(1000);
		}
	}

	// This method adds cards from the deck to the common hand
	// Parameter:
	//	Deck deck	-> The deck where to take the card 
	//	char nbCard	-> The number of cards to add
	void PokerGame::AddCardCommonHand(Deck& deck, char nbCard)
	{
		currentTurn++;
		for (char i = 0; i < nbCard; i++)
		{
			CommonHand.push_back(deck.GiveCard());
		}
		
	}

	// This method adds tokens to the common pot
	// Parameter:
	//	int nbToken	-> the number of tokens to add to the common pot
	void PokerGame::FillCommonPot(int nbToken) 
	{
		CommonPot += nbToken;
	}

	// This method asks the player which action he wants to do and return it
	// Parameter:
	//	Player player	-> The player who need to do an action
	int PokerGame::AskForPlayerChoice(Player& player)
	{
		string choice;
		if (player.GetPot()!=0)
		{
			do
			{
				cout << "\nVeuillez choisir une action\nMiser(1) Parler(2) Ce coucher(3) : " << endl;
				cin >> choice;
				if (choice == "1" || choice == "2" || choice == "3") break;
				cout << "Ce choix n'est pas valide." << endl;
				system("PAUSE");

			} while (true);
		}		
		return std::stoi(choice);
	}

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
	void PokerGame::ShowTable(Player& player1, Player& player2)
	{
		vector<Card> player1Hand = player1.GetHand();
		vector<Card> player2Hand = player2.GetHand();
		string turnName;

		switch (currentTurn)
		{
		case 1:
			turnName = "Donne";
			break;
			
		case 2:
			turnName = "Flop";
			break;
			
		case 3:
			turnName = "River";
			break;
			
		case 4:
			turnName = "Turn";
			break;
		default:
			turnName = "?";
			break;
		}

		// Clear the console
		system("cls");

		// Display the turn number and the turn name
		cout << "Tour numero " << currentTurn << " (" << turnName << ")\n" << endl;

		// Show the pot of player1, player2 and the commun pot
		cout << "pot de " << player1.name << " : " << player1.GetPot();
		cout << " | pot de " << player2.name << " : " << player2.GetPot();
		cout << " | pot commun : " << CommonPot << endl << endl;

		// Show the commun hand
		cout << "Main commune : " << endl;
		DisplayCommonHand();
		
		// Show the hand of player1
		cout << "\nMain de " << player1.name<<" : " << endl;
		player1.DisplayHand();
		
		// Show the hand of player2
		cout << "\nMain de " << player2.name << " : " << endl;
		player2.DisplayHand(true);
	}

	// This method returns the current turn value
	int PokerGame::GetCurrentTurn() 
	{
		return currentTurn;
	}

	// This method returns the common pot
	int PokerGame::GetCommonPot() 
	{
		return CommonPot;
	}

	// This method displays the common hand
	void PokerGame::DisplayCommonHand()
	{
		// Create vector to keep the cards
		vector<string> temp;
		vector<string> actualHand = {
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		};
		// For all cards in the common hand
		for (Card card : CommonHand)
		{
			// Clear the vector "temps"
			temp.clear();
			// for the size of the card
			for (char i = 0; i < card.Display().size(); i++)
			{
				// Add the card to temp line by line
				temp.push_back(actualHand[i] + " " + card.Display()[i]);
			}
			// Copy temp in actual hand
			actualHand = temp;
		}
		// for each line in the actual hand
		for (string line : actualHand)
		{
			// Display the line
			cout << line << endl;
		}
	}

	// This method returns the common pot and clear it 
	int PokerGame::ClearCommonPot() 
	{
		int temp = CommonPot;
		CommonPot = 0;
		return temp;
	}

	// This method clears the common hand
	void PokerGame::ClearCommonHand()
	{
		CommonHand.clear();
	}

	// This method compares all hands and show the winner
	void PokerGame::GetWinner(Player& player1, Player& player2)
	{
		#pragma region InitVariables
		vector<Card> player1Hand = player1.GetHand();
		vector<Card> player2Hand = player2.GetHand();
		for (Card card : CommonHand)
		{
			player1Hand.push_back(card);
			player2Hand.push_back(card);
		}
		int player1Rank = TempMethodToMakeTheSoftWork(player1Hand);
		int player2Rank = TempMethodToMakeTheSoftWork(player2Hand);

		if (player1Rank > player2Rank)
		{
			cout << "\nLe gagnant est " << player1.name << " avec " << player1Rank << "points, contre "<< player2Rank<<"points." << endl;
			cout<<"Il remporte : " << GetCommonPot() << "Token" << endl;
			player1.TakeToken(GetCommonPot());
			ClearCommonPot();
			system("PAUSE");
		}
		else if (player1Rank < player2Rank)
		{
			cout << "\nLe gagnant est " << player2.name << " avec " << player2Rank << "points, contre " << player1Rank << "points." << endl;
			cout << "Il remporte : " << GetCommonPot() << "Token" << endl;
			player2.TakeToken(GetCommonPot());
			ClearCommonPot();
			system("PAUSE");
		}
		else
		{
			cout << "\nC'est une egalité, tout le monde recupere sa mise." << endl;
			player1.TakeToken(GetCommonPot()/2);
			player2.TakeToken(GetCommonPot()/2);
			ClearCommonPot();
			system("PAUSE");
		}
		#pragma endregion
	}

	// This method is a temporary method to make the software work in time
	int PokerGame::TempMethodToMakeTheSoftWork(vector<Card> handToCheck)
	{
		int weightHand=0;
		map<char, int> valueStraight;
		valueStraight['2'] = 2;
		valueStraight['3'] = 3;
		valueStraight['4'] = 4;
		valueStraight['5'] = 5;
		valueStraight['6'] = 6;
		valueStraight['7'] = 7;
		valueStraight['8'] = 8;
		valueStraight['9'] = 9;
		valueStraight['T'] = 10;
		valueStraight['J'] = 11;
		valueStraight['Q'] = 12;
		valueStraight['K'] = 13;
		valueStraight['A'] = 14;

		for (Card card : handToCheck)
		{
			weightHand += valueStraight[card.GetCardProperties()[0]];
		}
		return weightHand;
	}
	/*
	int PokerGame::CheckHand(vector<Card> handToCheck) 
	{
		
		map<char, int> valueStraight;
		valueStraight['2'] = 12;
		valueStraight['3'] = 11;
		valueStraight['4'] = 10;
		valueStraight['5'] = 9;
		valueStraight['6'] = 8;
		valueStraight['7'] = 7;
		valueStraight['8'] = 6;
		valueStraight['9'] = 5;
		valueStraight['T'] = 4;
		valueStraight['J'] = 3;
		valueStraight['Q'] = 2;
		valueStraight['K'] = 1;
		valueStraight['A'] = 0;

		string RankingName = "RoyalFlush";
		int Rankinglvl = 0;
		char arrayCardValue[8];
		char arrayCardColor[8];

		for (char i=0;i<handToCheck.size();i++)
		{
			arrayCardValue[i] = handToCheck[i].GetCardProperties()[0];
			arrayCardColor[i] = handToCheck[i].GetCardProperties()[1];
		}

		if (RankingName=="RoyalFlush")
		{
			for (char i = 0; i < handToCheck.size(); i++)
			{

			}
		}

		if (RankingName == "StraightFlush")
		{

		}
		
		if (RankingName == "fourOfKind")
		{
			int countOfCard;
			for (char value : arrayCardValue)
			{
				countOfCard = count(arrayCardValue, arrayCardValue + 8, value);
				if (countOfCard >= 4)
				{
					return Rankinglvl;
				}
			}
			RankingName = "FullHouse";
		}

		if (RankingName == "FullHouse")
		{

		}
		
		if (RankingName == "Flush")
		{

		}

		if (RankingName == "Straight")
		{

		}
		
		if (RankingName == "ThreeOfKind")
		{

		}
		
		if (RankingName == "TwoPair")
		{

		}
		
		if (RankingName == "Pair")
		{

		}
		
		if (RankingName == "HighCard")
		{

		}

		do
		{
			for (size_t i = 0; i < handToCheck.size(); i++)
			{
				char cardValue = handToCheck[i].GetCardProperties()[0];
				char cardColor = handToCheck[i].GetCardProperties()[1];

				#pragma region ROYAL FLUSH
				// Check for Royal flush
				if (RankingName == "RoyalFlush")
				{
					static int nbCardFind = 0;
					static char saveLastCardColor;
					static char arrayCardValue[8];


					switch (cardValue)
					{
					case 'T':
						Rankinglvl = 1;
						if (nbCardFind ==0)
						{
							nbCardFind++;
							saveLastCardColor = cardColor;
						}
						else if (i == handToCheck.size() - 1)
						{
							RankingName = "StraightFlush";
							nbCardFind = 0;
						}
						break;
					case 'J':
						if (nbCardFind == 1)
						{
							if (saveLastCardColor==cardColor)
							{
								nbCardFind++;
							}
						}
						else if (i == handToCheck.size() - 1)
						{
							RankingName = "StraightFlush";
							nbCardFind = 0;
						}
						break;
					case 'Q':
						if (nbCardFind == 2)
						{
							if (saveLastCardColor == cardColor)
							{
								nbCardFind++;
							}
						}
						else if (i == handToCheck.size() - 1)
						{
							RankingName = "StraightFlush";
							nbCardFind = 0;
						}
						break;
					case 'K':
						if (nbCardFind == 3)
						{
							if (saveLastCardColor == cardColor)
							{
								nbCardFind++;
							}
						}
						else if (i == handToCheck.size() - 1)
						{
							RankingName = "StraightFlush";
							nbCardFind = 0;
						}
						break;
					case 'A':
						if (nbCardFind == 4)
						{
							if (saveLastCardColor == cardColor)
							{
								return Rankinglvl;
							}
						}
						else if (i == handToCheck.size()-1)
						{
							RankingName = "StraightFlush";
							nbCardFind = 0;
						}
						break;
					}
				}
				#pragma endregion

				#pragma region STRAIGHT FLUSH
				// Check for Straight flush
				else if (RankingName == "StraightFlush")
				{
					static int nbCardFind = 0;
					static bool watchHigher = true;
					static char saveLastCardValue;
					static char saveLastCardColor;
					switch (nbCardFind)
					{
					case 0:
						Rankinglvl = 2;
						saveLastCardValue = cardValue;
						saveLastCardColor = cardColor;
						nbCardFind++;
						break;
					case 1:
						if (valueStraight[saveLastCardValue] < valueStraight[cardValue] && watchHigher)
						{
							saveLastCardValue = cardValue;
							nbCardFind++;
							if (i == handToCheck.size()-1)
							{
								nbCardFind=0;
								watchHigher = false;
							}
						}
						else if (valueStraight[saveLastCardValue] > valueStraight[cardValue] && !watchHigher)
						{
							saveLastCardValue = cardValue;
							if (i == handToCheck.size() - 1)
							{
								RankingName = "fourOfKind";
							}
						}
						break;
					case 2:
						if (valueStraight[saveLastCardValue] > valueStraight[cardValue] && watchHigher)
						{
							saveLastCardValue = cardValue;
							nbCardFind++;
							if (i == handToCheck.size() - 1)
							{
								nbCardFind = 0;
								watchHigher = false;
							}
						}
						else if (valueStraight[saveLastCardValue] < valueStraight[cardValue] && !watchHigher)
						{
							saveLastCardValue = cardValue;
							if (i == handToCheck.size() - 1)
							{
								RankingName = "fourOfKind";
							}
						}
						break;
					case 3:
						if (valueStraight[saveLastCardValue] > valueStraight[cardValue] && watchHigher)
						{
							saveLastCardValue = cardValue;
							nbCardFind++;
							if (i == handToCheck.size() - 1)
							{
								nbCardFind = 0;
								watchHigher = false;
							}
						}
						else if (valueStraight[saveLastCardValue] < valueStraight[cardValue] && !watchHigher)
						{
							saveLastCardValue = cardValue;
							if (i == handToCheck.size() - 1)
							{
								RankingName = "fourOfKind";
							}
						}
						break;
					case 4:
						if (valueStraight[saveLastCardValue] > valueStraight[cardValue] && watchHigher)
						{
							return Rankinglvl;
						}
						else if (valueStraight[saveLastCardValue] < valueStraight[cardValue] && !watchHigher)
						{
							saveLastCardValue = cardValue;
							if (i == handToCheck.size() - 1)
							{
								RankingName = "fourOfKind";
							}
						}
						break;
					}
				}
				#pragma endregion

				#pragma region FOUR OF A KIND
				// Check for four of kind
				else if (RankingName == "fourOfKind")
				{
					Rankinglvl = 3;
					static char arrayCardValue[8];
					static bool arrayCardFull = false;
					static int countOfCard;


					if (arrayCardFull)
					{
						for (char value : arrayCardValue)
						{
							for (char value : arrayCardValue)
							{
								countOfCard = count(arrayCardValue, arrayCardValue + 8, value);
								if (countOfCard >= 4)
								{
									return Rankinglvl;
								}
								else if (i == handToCheck.size() - 1 && countOfCard < 4)
								{
									RankingName = "TwoPair";
								}
							}
						}
					}
					else
					{
						arrayCardValue[i] = cardValue;
						if (i = handToCheck.size() - 1)
						{
							arrayCardFull = true;
						}
					}
				}
				#pragma endregion

				#pragma region FULL HOUSE
				// Check for Full house
				else if (RankingName == "FullHouse")
				{
					RankingName = "Flush";
				}
				#pragma endregion

				#pragma region FLUSH
				// Check for Flush
				else if (RankingName == "Flush")
				{
					RankingName = "Straight";
				}
				#pragma endregion

				#pragma region STRAIGHT
				// Check for Straight
				else if (RankingName == "Straight")
				{
					RankingName = "ThreeOfKind";
				}
				#pragma endregion

				#pragma region THREE OF A KIND
				// Check for Three of kind
				else if (RankingName == "ThreeOfKind")
				{
					Rankinglvl = 7;
					static char arrayCardValue[8];
					static bool arrayCardFull = false;
					static int countOfCard;


					if (arrayCardFull)
					{
						for (char value : arrayCardValue)
						{
							for (char value : arrayCardValue)
							{
								countOfCard = count(arrayCardValue, arrayCardValue + 8, value);
								if (countOfCard >= 4)
								{
									return Rankinglvl;
								}
								else if (i == handToCheck.size() - 1&& countOfCard<4)
								{
									RankingName = "TwoPair";
								}
							}
						}
					}
					else
					{
						arrayCardValue[i] = cardValue;
						if (i = handToCheck.size() - 1)
						{
							arrayCardFull = true;
						}
					}
				}
				#pragma endregion

				#pragma region TWO PAIR
				// Check for Two pair
				else if (RankingName == "TwoPair")
				{
					RankingName = "Pair";
				}
				#pragma endregion

				#pragma region PAIR
				// Check for Pair
				else if (RankingName == "Pair")
				{
					RankingName = "HighCard";
				}
				#pragma endregion

				#pragma region HIGH CARD
				// Check for High card
				else if (RankingName == "HighCard")
				{
					// Change the ranking lvl of the combination
					Rankinglvl = 10;

					// Instentate the save variable with the first card
					static char saveLastCardValue = cardValue;

					// Check if the new value is biggest as the old one
					if (valueStraight[saveLastCardValue] > valueStraight[cardValue])
					{
						saveLastCardValue = cardValue;
					}// If all card was cheked 
					else if (i== handToCheck.size()-1)
					{
						return Rankinglvl + valueStraight[saveLastCardValue];
					}
				}
				#pragma endregion
			}
		} while (true);
		return 0;
	}*/
	#pragma endregion
}