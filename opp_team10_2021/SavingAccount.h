#pragma once
#include <string>
#include "Account.h"

class SavingAccount :public Account {
public:
	virtual void deposit() final;
	virtual std::string getAccountType() final;
};