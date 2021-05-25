#include "SavingAccount.h"

using namespace std;
SavingAccount::SavingAccount(string accNum, string sourceAcc, unsigned balance, string perName, string bnkName, unsigned int pwd) {
    mAccNum = accNum;
    mSourceAcc = sourceAcc;
    mBalance = balance;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    mLoanInfo = make_pair(0, 0);
}

SavingAccount::SavingAccount(string perName, string bnkName, unsigned int pwd)
{
    mBalance = 0;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    mLoanInfo = make_pair(0, 0);
    genAccNum();
}

string SavingAccount::getAccountType()
{
	return "Àû±Ý";
}

std::string SavingAccount::getSourceAcc()
{
    return mSourceAcc;
}
