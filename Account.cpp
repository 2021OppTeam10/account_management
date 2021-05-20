#include <string>
#include <utility>
#include <"Account.h">

std::string Account::getAccountType() {

}

void Account::deposit() {

}

void Account::printAccount() {

}

unsigned int Account::getAccNum() {//계좌번호

    return mAccNum;
}

unsigned int Account::getBalance() {//잔액

    return mBalance;
}

std::string Account::getPerName() {//사람이름

    return mPerName;
}

std::string Account::getBnkName() {//은행명

    return mBnkName;
}

std::pair<int, int> Account::getLoanInfo() {//대출정보

    return mLoanInfo;
}