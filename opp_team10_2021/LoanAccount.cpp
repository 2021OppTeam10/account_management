#include "LoanAccount.h"
using namespace std;

LoanAccount::LoanAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd) {
    mAccNum = accNum;
    mBalance = balance;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    mLoanInfo = make_pair(0, 0);
}
LoanAccount::LoanAccount(std::string perName, std::string bnkName, unsigned int pwd) {
    mBalance = 0;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    mLoanInfo = make_pair(0, 0);
    genAccNum();
}
void LoanAccount::Repayment(DepositAccount& destAcc, int amount)
{
    destAcc.withdrawal(amount);
    this->withdrawal(amount);
}

string LoanAccount::getAccountType()
{
	return "¥Î√‚";
}