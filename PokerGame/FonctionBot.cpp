#include "FonctionBot.h"
#include "ClassPlayer.h"

int MainFonctionBot(std::string choiceplayer1, int misePlayer1)
{
	ClassPlayer::Player bot;
	int potBot;

	if(choiceplayer1 == "1")
	{
		bot.BetToken(misePlayer1);
		potBot = bot.ShowPot();
	}
	if(choiceplayer1 == "2")
	{
		cout << "Je t'check" << endl;
	}
	return potBot;
}
