#pragma once
#include <string>
#include <random>
#include "Account.h"

class DepositAccount final :public Account{
public:
	DepositAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	DepositAccount(std::string perName, std::string bnkName, unsigned int pwd);
	void getPattern();
	virtual std::string getAccountType() override;
};