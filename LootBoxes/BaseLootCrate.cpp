#include "BaseLootCrate.h"
#include "RewardList.h"
#include <random>
#include <iostream>
BaseLootCrate::BaseLootCrate()
{
}

BaseLootCrate::BaseLootCrate(Rarity aRarity, float aPrice, int aRewardOutput)
{
	mCrateRarity = aRarity;
	mPrice = aPrice;
	rewardOutputCount = aRewardOutput;
}


BaseLootCrate::~BaseLootCrate()
{
}

void BaseLootCrate::SetRewardList(RewardList* aRewardList)
{
	mRewardList = aRewardList;
}

float BaseLootCrate::GetPrice()
{
	return mPrice;
}


RewardVector BaseLootCrate::RollRewards(float afskewAmount, bool abGuaranteeLegendary)
{
	RewardVector temp;
	//seed with a random value
	for (int i = 0; i < rewardOutputCount; i++)
	{
		int randomNumber = rand() % 100 + afskewAmount;
		//check for 60%
		if (abGuaranteeLegendary)
		{
			temp.push_back(mRewardList->GetReward(LEGENDARY));
		}
		else if (randomNumber <= 1)
		{
			temp.push_back(mRewardList->GetReward(MYTHICAL));
		}
		else if (randomNumber <= 3 )
		{
			temp.push_back(mRewardList->GetReward(LEGENDARY));
		}
		else if (randomNumber <= 5)
		{
			temp.push_back(mRewardList->GetReward(EPIC));
		}
		else if (randomNumber <= 10)
		{
			
		}
		else if (randomNumber <= 20)
		{
			temp.push_back(mRewardList->GetReward(RARE));
		}
		else if (randomNumber <= 60 )
		{
			temp.push_back(mRewardList->GetReward(COMMON));
		}
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

	return temp;
}
