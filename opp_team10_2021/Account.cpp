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
	cout << "���� ���� : " << this->getAccountType() << endl;
	cout << "�̸� : " << mPerName << endl;
	cout << "����� : " << mBnkName << endl;
	cout << "���¹�ȣ : " << mAccNum << endl;
	cout << "�ܾ� : " << mBalance << endl;
	cout << "�������� : " << DEPOSIT_RATE << "%" << endl << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

string Account::getAccNum() {//���¹�ȣ

	return mAccNum;
}

unsigned int Account::getBalance() {//�ܾ�

	return mBalance;
}

string Account::getPerName() {//����̸�

	return mPerName;
}

string Account::getBnkName() {//�����

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
