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
	template <typename T>
	void transfer(T& destAcc, int amount);
	virtual std::string getAccountType() override;
};