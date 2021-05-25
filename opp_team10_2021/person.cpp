#include "person.h"
#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)
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
			mOwnedSavAcc.erase(mOwnedSavAcc.begin() + i);
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

template <typename T>
void Person::save(T account) {
	string tmp = "md customer";
	if (system(tmp.c_str()))
		system("cls");
	string filename = account.getPerName();
	ofstream os("./customer/" + filename + ".txt");
	ofstream os2("./customer/" + filename + "pw");
	os << account.getAccNum() << "\n";
	os << account.getBalance() << "\n";
	os << account.getPerName() << "\n";
	os << account.getBnkName() << "\n";
	os << account.getLoanInfo().first << "\n";
	os << account.getLoanInfo().second << "\n";
	os2 << account.getPwd() << "\n";
	os.close();
	os2.close();

	string uploadBase1 = "scp -o \"StrictHostKeyChecking no\" -i ./id_rsa -P 8080 ./customer";
	string uploadBase2 = " cppproj@1.225.217.57:/home/cppproj/customer/";

	cout << "------------------------------< UPLOAD FILE >-----------------------------" << endl;
	filename = account.getPerName() + ".txt";
	string upload = uploadBase1 + filename + uploadBase2;
	string cmd = "start /min /wait " + upload;
	if (system(cmd.c_str()) == 0)
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 완료-" << endl;
	else
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 실패-" << endl;
	filename = account.getPerName() + "pw";
	upload = uploadBase1 + filename + uploadBase2;
	cmd = "start /wait /min " + upload;
	if (system(cmd.c_str()) == 0)
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 완료-" << endl;
	else
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 실패-" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
	system("echo on");
}
template <typename T>
void Person::load(T account) {
	string filename = account.getPerName();
	ifstream is("./customer/" + filename + ".txt");
	ifstream is2("./customer/" + filename + "pw");
	is.close();
	is2.close();

	string downloadBase1 = "scp -o \"StrictHostKeyChecking no\" -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/";
	string downloadBase2 = " ./customer/";

	cout << "-----------------------------< DOWNLOAD FILE >----------------------------" << endl;
	filename = account.getPerName() + ".txt";
	string download = downloadBase1 + filename + downloadBase2;
	string cmd = "start /wait /min " + download;
	if (system(cmd.c_str()) == 0)
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 완료-" << endl;
	else
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 실패-" << endl;
	filename = account.getPerName() + "pw";
	download = downloadBase1 + filename + downloadBase2;
	cmd = "start /wait /min " + download;
	if (system(cmd.c_str()) == 0)
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 완료-" << endl;
	else
		cout << " " << filename << "\t\t\t\t\t\t     -업로드 실패-" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

void Person::setDate()
{
	string date = "date /T > date.txt";
	system(date.c_str());
}

bool Person::getDate() {

	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);
	string month = to_string(local_time->tm_mon + 1);
	if (month.size() == 1) {
		month.push_back(month[0]);
		month[0] = '0';
	}
	string date = to_string(local_time->tm_year + 1900) + "-" + month + "-" + std::to_string(local_time->tm_mday);

	string savedDate = "";
	ifstream is("date.txt");
	getline(is, savedDate);
	savedDate.pop_back();
	if (savedDate == date)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Person::dailyInterest() {//적금이자 적금계좌에 더하기
	if (getDate()) {
		for (auto i : mOwnedSavAcc) {
			i.getSourceAcc();
			i.deposit((SAVE_RATE / 100) * i.getBalance());	//적금
		}
		for (auto i : mOwnedDepAcc) {
			i.deposit((DEPOSIT_RATE / 100) * i.getBalance());	//예금
		}
						//대출
	}
}
