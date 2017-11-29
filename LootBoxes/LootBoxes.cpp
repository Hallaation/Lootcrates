// LootBoxes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rarity.h"

#include <random>
#include <time.h>
#include <iostream>

#include "BaseLootCrate.h"
#include "RewardList.h"

struct MyLootCrates
{
	BaseLootCrate mCrate;
	int miAmountOfCrates;
};

using namespace std;
int main()
{
	std::vector<BaseLootCrateReward> mObtainedRewards;

	srand(time(NULL));
	//Setup a reward list
	RewardList *mRewardList = new RewardList();
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));
	mRewardList->AddReward(BaseLootCrateReward(COMMON, "Common"));


	mRewardList->AddReward(BaseLootCrateReward(RARE, "Rare"));
	mRewardList->AddReward(BaseLootCrateReward(RARE, "Rare"));
	mRewardList->AddReward(BaseLootCrateReward(RARE, "Rare"));
	mRewardList->AddReward(BaseLootCrateReward(RARE, "Rare"));


	mRewardList->AddReward(BaseLootCrateReward(EPIC, "Epic"));
	mRewardList->AddReward(BaseLootCrateReward(EPIC, "Epic"));

	mRewardList->AddReward(BaseLootCrateReward(LEGENDARY, "Legendary"));
	mRewardList->AddReward(BaseLootCrateReward(MYTHICAL, "Mythical"));


	//Make some lootcrates
	MyLootCrates mLootCrates[4]
	{
		{ BaseLootCrate(COMMON, 1.99, 5), 5 },
		{ BaseLootCrate(RARE, 2.99, 4), 5 },
		{ BaseLootCrate(EPIC, 3.99, 3), 5 },
		{ BaseLootCrate(LEGENDARY, 5.99, 2), 5 },
	};

	for (size_t i = 0; i < 4; i++)
	{
		mLootCrates[i].mCrate.SetRewardList(mRewardList);
	}

	bool running = true;
	float creditBalance = 2000;
	int currentSkew = 10;
	int OpenedBoxes, AmountForGuaranteeLegendary = 20;
	char selection;

	while (running)
	{
		std::cout << "Current balance: $" << creditBalance << std::endl;
		for (auto it : mObtainedRewards)
		{
			std::cout << it.GetReward() << " ";
		}
		std::cin >> selection;
		switch (toupper(selection))
		{
		case 'C':
		{
			if (mLootCrates[0].miAmountOfCrates > 0)
			{
				for (auto it : mLootCrates[0].mCrate.RollRewards(currentSkew, (OpenedBoxes >= AmountForGuaranteeLegendary)))
				{
					std::cout << it.GetReward() << std::endl;
					mObtainedRewards.push_back(it);
				}

				mLootCrates[0].miAmountOfCrates--;
				currentSkew--;
				OpenedBoxes++;
				creditBalance -= mLootCrates[0].mCrate.GetPrice();
			}
			else
			{
				std::cout << "Not enough money" << std::endl;
			}
			break;
		}
		case 'R':
		{
			if (mLootCrates[1].mCrate.GetPrice() <= creditBalance)
			{
				for (auto it : mLootCrates[1].mCrate.RollRewards(currentSkew, (OpenedBoxes >= AmountForGuaranteeLegendary)))
				{
					std::cout << it.GetReward() << std::endl;
					mObtainedRewards.push_back(it);
				}
				mLootCrates[1].miAmountOfCrates--;
				currentSkew--;
				OpenedBoxes++;
				creditBalance -= mLootCrates[1].mCrate.GetPrice();
			}
			else
			{
				std::wcout << "Not enough money" << std::endl;
			}
			break;
		}
		case 'E':
		{
			if (mLootCrates[2].mCrate.GetPrice() <= creditBalance)
			{
				for (auto it : mLootCrates[2].mCrate.RollRewards(currentSkew, (OpenedBoxes >= AmountForGuaranteeLegendary)))
				{
					std::cout << it.GetReward() << std::endl;
					mObtainedRewards.push_back(it);
				}
				mLootCrates[2].miAmountOfCrates--;
				currentSkew--;
				OpenedBoxes++;
				creditBalance -= mLootCrates[2].mCrate.GetPrice();
			}
			else
			{
				std::cout << "Not enough money" << std::endl;
			}
			break;
		}
		case 'L':
		{
			if (mLootCrates[3].mCrate.GetPrice() <= creditBalance)
			{
				for (auto it : mLootCrates[3].mCrate.RollRewards(currentSkew, (OpenedBoxes >= AmountForGuaranteeLegendary)))
				{
					std::cout << it.GetReward() << std::endl;
					mObtainedRewards.push_back(it);
				}
				mLootCrates[3].miAmountOfCrates--;
				currentSkew--;
				OpenedBoxes++;
				creditBalance -= mLootCrates[3].mCrate.GetPrice();
			}
			else
			{
				std::cout << "Not enough money" << std::endl;
			}
			break;
		}
		default:
			break;
		}

		if (currentSkew <= 0)
		{
			currentSkew = 10;
		}
		std::cout << std::endl;
		system("cls");
		//cout << &lootCrate1;

	}
	delete mRewardList;
	mRewardList = nullptr;
	return 0;

}

