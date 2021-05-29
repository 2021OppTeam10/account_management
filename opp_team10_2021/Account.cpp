#include <iostream>
#include "Account.h"

using namespace std;

void Account::deposit(int amount) {
	this->mBalance += amount;
}

void Account::withdrawal(int amount) {
	this->mBalance -= amount;
}

void Account::printAccount() {
	cout << "-----------------------------< ACCOUNT INFO >-----------------------------" << endl;
	cout << "계좌 종류 : " << this->getAccountType() << endl;
	cout << "이름 : " << mPerName << endl;
	cout << "은행명 : " << mBnkName << endl;
	cout << "계좌번호 : " << mAccNum << endl;
	cout << "잔액 : " << mBalance << endl;
	cout << "예금이율 : " << DEPOSIT_RATE << "%" << endl << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

string Account::getAccNum() {//계좌번호

	return mAccNum;
}

unsigned int Account::getBalance() {//잔액

	return mBalance;
}

string Account::getPerName() {//사람이름

	return mPerName;
}

string Account::getBnkName() {//은행명

	return mBnkName;
}

unsigned int Account::getPwd()
{
	return mPwd;
}

void Account::genAccNum()
{
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

bool Account::isCorrect(unsigned int inPwd)
{
	return inPwd == mPwd ? true : false;
}
