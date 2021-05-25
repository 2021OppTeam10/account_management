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

SavingAccount::SavingAccount(string perName, string bnkName, unsigned int pwd)
{
    mBalance = 0;
    mPerName = perName;
    mBnkName = bnkName;
    mPwd = pwd;
    genAccNum();
}

string SavingAccount::getAccountType()
{
	return "����";
}

std::string SavingAccount::getSourceAcc()
{
    return mSourceAcc;
}
