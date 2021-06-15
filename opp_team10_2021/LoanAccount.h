#pragma once
#include <string>
#include <random>
#include <ctime>
#include "Account.h"
#include "DepositAccount.h"

class LoanAccount final : public Account {
public:
	LoanAccount();
	LoanAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	LoanAccount(std::string perName, std::string bnkName, unsigned int pwd);
	virtual void Repayment(DepositAccount& destAcc, int amount);
	void addLoan(std::string perName, std::string bnkName, int amount);
	virtual const std::string getAccountType() override;
};