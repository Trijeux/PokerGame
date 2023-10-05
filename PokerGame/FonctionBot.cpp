#include "FonctionBot.h"
#include "ClassPlayer.h"


void MainFonctionBot(std::string choiceplayer1, int misePlayer1, ClassPlayer::Player& player)
{
	if(choiceplayer1 == "1")
	{
		player.BetToken(misePlayer1);
		player.ShowPot();
	}
	if(choiceplayer1 == "2")
	{
		cout << "Je t'check" << endl;
	}
}
