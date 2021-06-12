#include "LoanAccount.h"
using namespace std;

LoanAccount::LoanAccount()
{
    mAccNum = "NULL";
    mBalance = 0;
    mPerName = "NULL";
    mBnkName = "NULL";
    mPwd = 0;
}

LoanAccount::LoanAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd) {
    mAccNum = accNum;
    mBalance = balance;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
}
LoanAccount::LoanAccount(std::string perName, std::string bnkName, unsigned int pwd) {
    mBalance = 0;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    genAccNum();
}
void LoanAccount::Repayment(DepositAccount& destAcc, int amount)
{
    destAcc.withdrawal(amount);
    this->withdrawal(amount);
}

void LoanAccount::addLoan(int amount) {
    this->mBalance += amount;
}

const string LoanAccount::getAccountType()
{
	return "¥Î√‚";
}