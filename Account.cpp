#include <string>
#include <utility>
#include <"Account.h">

std::string Account::getAccountType() {

}

void Account::deposit() {

}

void Account::printAccount() {

}

unsigned int Account::getAccNum() {//���¹�ȣ

    return mAccNum;
}

unsigned int Account::getBalance() {//�ܾ�

    return mBalance;
}

std::string Account::getPerName() {//����̸�

    return mPerName;
}

std::string Account::getBnkName() {//�����

    return mBnkName;
}

std::pair<int, int> Account::getLoanInfo() {//��������

    return mLoanInfo;
}