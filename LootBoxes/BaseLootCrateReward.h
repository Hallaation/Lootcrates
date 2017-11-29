#pragma once
#include "Rarity.h"

#include <string>

class BaseLootCrateReward
{
public:
	BaseLootCrateReward();
	BaseLootCrateReward(Rarity aRarity, std::string aReward);
	~BaseLootCrateReward();

	Rarity GetRarity();
	std::string GetReward();
protected:
	Rarity mRarity;
	std::string mReward;
};

