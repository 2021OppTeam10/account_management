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
	cout << "�����Ѿ� : " << mLoanInfo.first << endl;
	cout << "�����ܾ� : " << mLoanInfo.second << endl;
	cout << "�������� : " << LOAN_RATE << "%" << endl;
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

pair<int, int> Account::getLoanInfo() {//��������
	return mLoanInfo;
}