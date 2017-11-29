#include "BaseLootCrateReward.h"


BaseLootCrateReward::BaseLootCrateReward()
{
	mRarity = COMMON;
	mReward = "Nothing";
}

BaseLootCrateReward::BaseLootCrateReward(Rarity aRarity, std::string aReward)
{
	mRarity = aRarity;
	mReward = aReward;
}

BaseLootCrateReward::~BaseLootCrateReward()
{

}

Rarity BaseLootCrateReward::GetRarity()
{
	return mRarity;
}
