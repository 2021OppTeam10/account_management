#include <iostream>
#include "Account.h"

using namespace std;

void Account::deposit() {
    cout << "이름 : " << mPerName << endl;
    cout << "현재 잔액 : " << mBalance << endl;
    cout << "입금하실 금액을 입력해 주세요 : ";
    int mdeposit = 0;
    cin >> mdeposit;
    mBalance += mdeposit;
    cout << mdeposit << "원이 입력되었습니다." << endl;
}

void Account::transfer()
{
}

void Account::withdrawal(int amount)
{
}

void Account::printAccount() {
    cout << "이름 : " << mPerName << endl;
    cout << "은행명 : " << mBnkName << endl;
    cout << "계좌번호 : " << mAccNum << endl;
    cout << "잔액 : " << mBalance << endl;
    cout << "예금이율 : " << DEPOSIT_RATE << "%" << endl << endl;
    cout << "대출총액 : " << mLoanInfo.first << endl;
    cout << "대출잔액 : " << mLoanInfo.second << endl;
    cout << "대출이율 : " << LOAN_RATE << "%" << endl;
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

pair<int, int> Account::getLoanInfo() {//대출정보
    return mLoanInfo;
}