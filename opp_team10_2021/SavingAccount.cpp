#include "SavingAccount.h"

using namespace std;
SavingAccount::SavingAccount(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd) {
    mAccNum = accNum;
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 9);
    for (int i = 0; i < 15; i++)
    {
        if (i == 4 || i == 8)
        {
            mAccNum.push_back('-');
        }
        else
        {
            mAccNum.push_back(dis(gen) + '0');
        }
    }
}
void SavingAccount::deposit() // 입금인데 월별 정기입금 처리 -> 하루단위
{

}

void SavingAccount::transfer()
{
}

string SavingAccount::getAccountType()
{
	return "적금";
}
