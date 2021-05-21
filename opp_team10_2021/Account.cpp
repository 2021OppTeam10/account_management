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

void Account::withdrawal() {
    cout << "이름 : " << mPerName << endl;
    cout << "현재 잔액 : " << mBalance << endl;
    cout << "출금하실 금액을 입력해 주세요 : ";
    int mwithdrawal = 0;
    cin >> mwithdrawal;
    mBalance -= mwithdrawal;
    cout << mwithdrawal << "원이 입력되었습니다." << endl;
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