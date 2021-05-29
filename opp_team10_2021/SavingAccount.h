#pragma once
#include <string>
#include "Account.h"

class SavingAccount final : public Account {
private:
	std::string mSourceAcc;
public:
	SavingAccount(std::string accNum, std::string sourceAcc, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
	SavingAccount(std::string perName, std::string bnkName, unsigned int pwd);
	virtual std::string getAccountType() override;
	std::string getSourceAcc();
};