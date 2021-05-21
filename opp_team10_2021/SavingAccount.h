#pragma once
#include <string>
#include "Account.h"

class SavingAccount final : public Account {
public:
	virtual void deposit() override;
	virtual void transfer() override;
	virtual std::string getAccountType() override;
};