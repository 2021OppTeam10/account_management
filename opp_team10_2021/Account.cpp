#include <iostream>
#include "Account.h"
#include "person.h"

using namespace std;
const INT C1 = 52845;
const INT C2 = 22719;
const INT KEY = 78695;
#pragma warning(disable : 4996)

void Account::deposit(int amount) {
	this->mBalance += amount;
}

bool Account::withdrawal(int amount) {
	if (mBalance >= amount) {
		mBalance -= amount;
		return true;
	}
	else
	{
		cout << "�ܾ��� �����մϴ�" << endl;
		return false;
	}
}

void Account::dailymonth() {
	this->savingmonth--;
}

void Account::printAccount() {
	cout << "-----------------------------< ACCOUNT INFO >-----------------------------" << endl;
	cout << "���� ���� : " << getAccountType() << endl;
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

BOOL Account::Encrypt(char* source, char* dest, DWORD length) {
	DWORD i;
	INT key = KEY;
	if (!source || !dest || length <= 0) {
		return FALSE;
	}
	for (i = 0; i < length; i++)
	{
		dest[i] = source[i] ^ key >> 16;
		key = (dest[i] + key) * C1 + C2;
	}
	return TRUE;
}

BOOL Account::Decrypt(char* source, char* dest, DWORD length) {
	DWORD i;
	char previousBlock;
	INT key = KEY;
	if (!source || !dest || length <= 0) {
		return FALSE;
	}
	for (i = 0; i < length; i++)
	{
		previousBlock = source[i];
		dest[i] = source[i] ^ key >> 16;
		key = (previousBlock + key) * C1 + C2;
	}
	return TRUE;
}
