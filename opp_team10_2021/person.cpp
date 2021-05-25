#include "person.h"
#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)
using namespace std;

void upload() {
	cout << "------------------------------< UPLOAD FILE >-----------------------------" << endl;
	string upload = "scp -r -o StrictHostKeyChecking=no -i .\\id_rsa -P 8080 .\\customer\\ cppproj@1.225.217.57:/home/cppproj/";
	string cmd = "start /min /wait " + upload;
	std::locale::global(std::locale("Korean"));
	if (system(upload.c_str()) == 0)
		cout << " " << "file" << "\t\t\t\t\t\t     -업로드 완료-" << endl;
	else
		cout << " " << "file" << "\t\t\t\t\t\t     -업로드 실패-" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

void download() {
	cout << "-----------------------------< DOWNLOAD FILE >----------------------------" << endl;
	string download = "scp -r -o \"StrictHostKeyChecking no\" -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ .\\";
	string cmd = "start /wait /min " + download;
	if (system(cmd.c_str()) == 0)
		cout << " " << "file" << "\t\t\t\t\t\t     -다운로드 완료-" << endl;
	else
		cout << " " << "file" << "\t\t\t\t\t\t     -다운로드 실패-" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

void Person::genPerNum()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 9);
	for (int i = 0; i < 15; i++)
	{
		mPerNum.push_back(dis(gen) + '0');
	}
}

string Person::getname() {
	return mName;
}

Person::Person(string name) {
	mName = name;
	mOwnedDepAcc;
	mOwnedSavAcc;
	genPerNum();
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

void Person::dailyInterest() {
	if (getDate()) {
		for (auto i : mOwnedSavAcc) {
			int tAmount = (SAVE_RATE / 100) * i.getBalance();
			getSavAcc(i.getSourceAcc()).withdrawal(tAmount);
			i.deposit(tAmount);									//적금
		}
		for (auto i : mOwnedDepAcc) {
			i.deposit((DEPOSIT_RATE / 100) * i.getBalance());	//예금
		}
		//대출
	}
}

void Person::savePer()
{
	string tmp = "md customer";
	if (system(tmp.c_str()))
		system("cls");

	tmp = "md .\\customer\\";
	tmp += mPerNum;
	if (system(tmp.c_str()))
		system("cls");

	for (auto i : mOwnedSavAcc) {
		saveAcc(i);
	}

	for (auto i : mOwnedDepAcc) {
		saveAcc(i);
	}
	tmp = "start /wait /min ssh -o \"StrictHostKeyChecking no\" -i id_rsa -p 8080 cppproj@1.225.217.57 rm -r ./customer/*";
	system(tmp.c_str());
	upload();
}

void Person::loadPer()
{
	download();
}

template<typename T>
void Person::saveAcc(T account) {
	string accNum = account.getAccNum();

	ofstream os(".\\customer\\" + mName + "\\" + accNum + ".txt");
	ofstream os2(".\\customer\\" + mName + "\\" + accNum + "pw");
	os << account.getAccNum() << "\n";
	os << account.getBalance() << "\n";
	os << account.getPerName() << "\n";
	os << account.getBnkName() << "\n";
	os2 << account.getPwd() << "\n";
	os.close();
	os2.close();
}

template <typename T>
void Person::loadAcc(T account) {
	string accNum = account.getAccNum();
	ifstream is("./customer/" + accNum + ".txt");
	ifstream is2("./customer/" + accNum + "pw");
	is.close();
	is2.close();
}