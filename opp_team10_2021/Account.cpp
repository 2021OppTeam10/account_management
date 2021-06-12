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

void Account::printAccount() {
	cout << "-----------------------------< ACCOUNT INFO >-----------------------------" << endl;
	cout << "���� ���� : " << this->getAccountType() << endl;
	cout << "�̸� : " << mPerName << endl;
	cout << "����� : " << mBnkName << endl;
	cout << "���¹�ȣ : " << mAccNum << endl;
	cout << "�ܾ� : " << mBalance << endl;
	cout << "�������� : " << DEPOSIT_RATE << "%" << endl << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

const string Account::getAccNum() {//���¹�ȣ

	return mAccNum;
}

const unsigned int Account::getBalance() {//�ܾ�

	return mBalance;
}

const string Account::getPerName() {//����̸�

	return mPerName;
}

const string Account::getBnkName() {//�����

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