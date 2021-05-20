#pragma once
#include <string>
#include "Account.h"

class DepositAccount :public Account{
public:
	void withdrawal(int amount);
	void getPattern();
	void transfer();
	virtual std::string getAccountType() final;
};