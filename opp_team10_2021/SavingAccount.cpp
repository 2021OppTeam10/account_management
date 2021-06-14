#include "SavingAccount.h"

using namespace std;
SavingAccount::SavingAccount(string accNum, string sourceAcc, unsigned balance, string perName, string bnkName, unsigned int pwd) {
    mAccNum = accNum;
    mSourceAcc = sourceAcc;
    mBalance = balance;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
}

SavingAccount::SavingAccount(string sourceAcc, string perName, string bnkName, unsigned int pwd)
{
    mBalance = 0;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    mSourceAcc = sourceAcc;
    genAccNum();
}

const string SavingAccount::getAccountType()
{
	return "Àû±Ý";
}

const std::string SavingAccount::getSourceAcc()
{
    return mSourceAcc;
}
