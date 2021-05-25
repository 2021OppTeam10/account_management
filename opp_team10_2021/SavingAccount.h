#pragma once
#include <string>
#define LOAN_RATE 1.5
#define SAVE_RATE 1.0
#define DEPOSIT_RATE 0.1
#include "Account.h"

class SavingAccount final : public Account {
private:
	std::string mSourceAcc;
public:
	SavingAccount(std::string accNum, std::string sourceAcc, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	SavingAccount(string perName, string bnkName, unsigned int pwd);
	virtual std::string getAccountType() override;
	std::string getSourceAcc();
};