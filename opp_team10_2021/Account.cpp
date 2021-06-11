#include <iostream>
#include "Account.h"
#include "person.h"

using namespace std;

void Account::deposit(int amount) {
	this->mBalance += amount;
}

void Account::withdrawal(int amount) {
	this->mBalance -= amount;
}

void Account::dailymonth() {
	this->savingmonth--;
}

void Account::printAllAccount() {
	vector<Person> cusList;
	vector<SavingAccount> mOwnedSavAcc;
	vector<DepositAccount> mOwnedDepAcc;
	string PerName;
	cin >> PerName;
	cout << "이름 : " << PerName;
	for (int i = 0; i < cusList.size(); i++) {
		if (PerName == cusList[i].mName) {
			for (int j = 0; j < mOwnedSavAcc.size(); j++) {
				if (PerName == mOwnedSavAcc[j].mName) {
					cout << "예금계좌 : " << mOwnedSavAcc[j].mAccNum << endl;
				}

				for (int k = 0; k < mOwnedDepAcc.size(); k++) {
					if (PerName == mOwnedDepAcc[k].mName) {
						cout << "적금계좌 : " << mOwnedDepAcc[k].mAccNum << endl;
					}
				}
			}
		}
		else
			cout << "이름이 존재하지 않습니다." << endl;
	}
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

const string Account::getAccNum() {//계좌번호

	return mAccNum;
}

const unsigned int Account::getBalance() {//잔액

	return mBalance;
}

const string Account::getPerName() {//사람이름

	return mPerName;
}

const string Account::getBnkName() {//은행명

	return mBnkName;
}

const unsigned int Account::getPwd()
{
	return mPwd;
}
const int Account::getsavingmonth() {
	return savingmonth;
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

void Account::operator=(const Account& rhs)
{
	this->mAccNum = rhs.mAccNum;
	this->mBalance = rhs.mBalance;
	this->mPerName = rhs.mPerName;
	this->mBnkName = rhs.mBnkName;
	this->mPwd = rhs.mPwd;
}
