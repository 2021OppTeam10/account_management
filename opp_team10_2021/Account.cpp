#include <iostream>
#include "Account.h"

using namespace std;

void Account::deposit() {
    cout << "�̸� : " << mPerName << endl;
    cout << "���� �ܾ� : " << mBalance << endl;
    cout << "�Ա��Ͻ� �ݾ��� �Է��� �ּ��� : ";
    int mdeposit = 0;
    cin >> mdeposit;
    mBalance += mdeposit;
    cout << mdeposit << "���� �ԷµǾ����ϴ�." << endl;
}

void Account::transfer()
{
}

void Account::withdrawal(int amount)
{
}

void Account::printAccount() {
    cout << "�̸� : " << mPerName << endl;
    cout << "����� : " << mBnkName << endl;
    cout << "���¹�ȣ : " << mAccNum << endl;
    cout << "�ܾ� : " << mBalance << endl;
    cout << "�������� : " << DEPOSIT_RATE << "%" << endl << endl;
    cout << "�����Ѿ� : " << mLoanInfo.first << endl;
    cout << "�����ܾ� : " << mLoanInfo.second << endl;
    cout << "�������� : " << LOAN_RATE << "%" << endl;
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

pair<int, int> Account::getLoanInfo() {//��������
    return mLoanInfo;
}