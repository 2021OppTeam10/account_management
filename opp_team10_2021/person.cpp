#include "person.h"
#include <iostream>
using namespace std;

string Person::getname() {
	return mName;
}

Person::Person(string name) {
	mName = name;
	mOwnedDepAcc;
	mOwnedSavAcc;
}

void Person::addSavAcc(SavingAccount newACC) {
	mOwnedSavAcc.push_back(newACC);
}

void Person::addDepAcc(DepositAccount newACC) {
	mOwnedDepAcc.push_back(newACC);
}

void Person::rmAcc(string accNum) {
	
	for (int i = 0; i < mOwnedSavAcc.size(); i++) {
		if (mOwnedSavAcc[i].SavingAccount::getAccNum().compare(accNum) == 0) {
			cout << "%s ���°� ���� �Ǿ����ϴ�." << accNum << endl;
			mOwnedSavAcc.erase(mOwnedSavAcc.begin() +i);
			return;
		}
	}
	for (int i = 0; i < mOwnedDepAcc.size(); i++) {
		if (mOwnedDepAcc[i].DepositAccount::getAccNum().compare(accNum) == 0) {
			cout << "%s ���°� ���� �Ǿ����ϴ�." << accNum << endl;
			mOwnedDepAcc.erase(mOwnedDepAcc.begin() + i);
			return;
		}
	}
	cout << "%s�� �������� �ʽ��ϴ�." << accNum << endl;;
	return;
}

SavingAccount& Person::getSavAcc(string accNum) {

	for (int i = 0; i < mOwnedSavAcc.size(); i++) {
		if (mOwnedSavAcc[i].SavingAccount::getAccNum().compare(accNum) == 0) {
			return mOwnedSavAcc[i];
		}
	}
	
}
DepositAccount& Person::getDepAcc(string accNum) {

	for (int i = 0; i < mOwnedDepAcc.size(); i++) {
		if (mOwnedDepAcc[i].DepositAccount::getAccNum().compare(accNum) == 0) {
			return mOwnedDepAcc[i];
		}
	}
}

void Person::save() {
	system("upload.bat");
}
void Person::load() {
	system("download.bat");
}
