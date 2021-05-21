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
			cout << "%s 계좌가 해지 되었습니다." << accNum << endl;
			mOwnedSavAcc.erase(mOwnedSavAcc.begin() +i);
			return;
		}
	}
	for (int i = 0; i < mOwnedDepAcc.size(); i++) {
		if (mOwnedDepAcc[i].DepositAccount::getAccNum().compare(accNum) == 0) {
			cout << "%s 계좌가 해지 되었습니다." << accNum << endl;
			mOwnedDepAcc.erase(mOwnedDepAcc.begin() + i);
			return;
		}
	}
	cout << "%s는 존재하지 않습니다." << accNum << endl;;
	return;
}

Account Person::getAcc(string accNum) {
		for (int i = 0; i < mOwnedSavAcc.size(); i++) {
		if (mOwnedSavAcc[i].SavingAccount::getAccNum().compare(accNum) == 0) {
			return mOwnedSavAcc[i];
		}
	}
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
