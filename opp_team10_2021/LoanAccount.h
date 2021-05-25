#pragma once
#include <string>
#include <random>
#include <ctime>
#include "Account.h"
#include "DepositAccount.h"

class LoanAccount final : public Account {
public:
	LoanAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	LoanAccount(std::string perName, std::string bnkName, unsigned int pwd);
	virtual void Repayment(DepositAccount& destAcc,int amount);
	virtual std::string getAccountType();
};