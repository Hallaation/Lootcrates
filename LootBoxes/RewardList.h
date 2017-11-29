#pragma once

#include "BaseLootCrateReward.h"
#include "Rarity.h"
#include <vector>

#ifndef RewardVector
#define RewardVector std::vector<BaseLootCrateReward>
#endif // !RewardVector


class RewardList
{
public:
	RewardList();
	~RewardList();

	RewardVector mCommons;
	RewardVector mRares;
	RewardVector mEpics;
	RewardVector mLegendaries;
	RewardVector mMythicals;

	void LoadRewardsFromFile() {}
	void SaveRewardsToFile() {}


	BaseLootCrateReward GetReward(Rarity rarityType)
	{
		switch (rarityType)
		{
		case COMMON:
			//return mCommons.at(rand() % mCommons.size() - 1);
			return BaseLootCrateReward(COMMON, "Common");
			break;
		case RARE:
			return BaseLootCrateReward(RARE, "Rare");
			//return mRares.at(rand() % mCommons.size() - 1);
			break;
		case EPIC:
			return BaseLootCrateReward(EPIC, "Epic");
			//return mEpics.at(rand() % mCommons.size() - 1);
			break;
		case LEGENDARY:
			return BaseLootCrateReward(LEGENDARY, "Legendary");
			//return mLegendaries.at(rand() % mCommons.size() - 1);
			break;
		case MYTHICAL:
			return BaseLootCrateReward(MYTHICAL, "Mythical");
			//return mMythicals.at(rand() % mCommons.size() - 1);
			break;
		default:
			break;
		}
	}

	void AddReward(BaseLootCrateReward aReward)
	{
		switch (aReward.GetRarity())
		{
		case COMMON:
			mCommons.push_back(aReward);
			break;
		case RARE:
			mRares.push_back(aReward);
			break;
		case EPIC:
			mRares.push_back(aReward);
			break;
		case LEGENDARY:
			mRares.push_back(aReward);
			break;
		case MYTHICAL:
			mRares.push_back(aReward);
			break;
		default:
			break;
		}
	}
};

