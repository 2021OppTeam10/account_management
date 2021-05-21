#pragma once
#include <string>
#include <random>
#include "Account.h"

class SavingAccount final : public Account {
public:
	SavingAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	SavingAccount(std::string perName, std::string bnkName, unsigned int pwd);
	virtual void deposit(int amount) override;
	virtual std::string getAccountType() override;
};