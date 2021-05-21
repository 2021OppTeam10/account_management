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
	cout << "대출총액 : " << mLoanInfo.first << endl;
	cout << "대출잔액 : " << mLoanInfo.second << endl;
	cout << "대출이율 : " << LOAN_RATE << "%" << endl;
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

pair<int, int> Account::getLoanInfo() {//대출정보
	return mLoanInfo;
}