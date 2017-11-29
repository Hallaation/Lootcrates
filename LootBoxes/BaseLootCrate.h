#pragma once
#include "Rarity.h"
#include "BaseLootCrateReward.h"


#include <stdio.h>
#include <vector>
#include <random>

#define RewardVector std::vector<BaseLootCrateReward>
class BaseLootCrate
{
public:
	/*
	Rarity Distribution:
	Nothing   : 10%
	Common    : 60%
	Rare      : 20%
	Epic      : 5%
	Legendary : 3%
	Mythical  : 1%
	*/
	BaseLootCrate();
	BaseLootCrate(Rarity aRarity, float aPrice, int aRewardOutput);
	~BaseLootCrate();

	//Adds a reward to the vector 
	void AddReward(BaseLootCrateReward aReward);

	RewardVector RollRewards();
protected:
	Rarity mCrateRarity;
	float mPrice;
	int rewardOutputCount;
	RewardVector mRewards; 

};