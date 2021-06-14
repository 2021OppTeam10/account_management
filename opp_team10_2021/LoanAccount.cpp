#include "LoanAccount.h"
using namespace std;

LoanAccount::LoanAccount()
{
    mBalance = 0;
    mPerName;
    mBnkName;
    mPwd = 0;
    genAccNum();
}

LoanAccount::LoanAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd) {
    if (accNum == "NULL")
    {
        genAccNum();
    }
    else
    {
        mAccNum = accNum;
    }
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

void LoanAccount::addLoan(std::string perName, std::string bnkName, int amount) {
    mPerName = perName;
    mBnkName = bnkName;
    this->mBalance += amount;
}

const string LoanAccount::getAccountType()
{
	return "¥Î√‚";
}