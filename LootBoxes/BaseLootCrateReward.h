#pragma once
#include "Rarity.h"

class BaseLootCrateReward
{


public:
	BaseLootCrateReward();
	~BaseLootCrateReward();

	Rarity GetRarity();
protected:
	Rarity mRarity;
};

