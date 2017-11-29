#include "BaseLootCrate.h"

#include <random>

BaseLootCrate::BaseLootCrate()
{
}

BaseLootCrate::BaseLootCrate(Rarity aRarity, float aPrice, int aRewardOutput)
{
	mCrateRarity = aRarity;
	mPrice = aPrice;
	miRewardOutputCount = aRewardOutput;
}


BaseLootCrate::~BaseLootCrate()
{
}

RewardVector BaseLootCrate::RollRewards()
{
	RewardVector temp;
	//seed with a random value
	for (int i = 0; i < miRewardOutputCount; i++)
	{
		//check for 60%
		  //obtain common
		//check for 10%
		  //obtain nothing
		//check for 5%
		  //obtain rare
		//check for 3%
		  //obtain legendary
		//check for 1%
		  //obtain mythical
	}
	/*
	Rarity Distribution:
	Nothing   : 10%
	Common    : 60%
	Rare      : 20%
	Epic      : 5%
	Legendary : 3%
	Mythical  : 1%
	*/

	return RewardVector();
}
