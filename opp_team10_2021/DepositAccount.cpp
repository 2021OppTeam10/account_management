#include "DepositAccount.h"
#define LOAN_RATE 1.5
#define SAVE_RATE 1.0
#define DEPOSIT_RATE 0.1

using namespace std;

DepositAccount::DepositAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd) {
	mAccNum = accNum;
	mBalance = balance;
	mPerName = perName;
	mBnkName = bnkName;
	mPwd = pwd;
}

DepositAccount::DepositAccount(string perName, string bnkName, unsigned int pwd)
{
	mBalance = 0;
	mPerName = perName;
	mBnkName = bnkName;
	mPwd = pwd;
	genAccNum();
}

template <typename T>
void DepositAccount::transfer(T& destAcc, int amount) {
	this->withdrawal(amount);
	destAcc.deposit(amount);
}

const string DepositAccount::getAccountType()
{
	return "¿¹±Ý";
}
