#pragma once
#include <string>
#include <iostream>
#include <random>
#include "Account.h"
#include "SavingAccount.h"

class DepositAccount final :public Account{
public:
	DepositAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	DepositAccount(std::string perName, std::string bnkName, unsigned int pwd);
	void transfer(SavingAccount& destAcc, int amount);
	void transfer(DepositAccount& destAcc, int amount);
	virtual std::string getAccountType() override;
};