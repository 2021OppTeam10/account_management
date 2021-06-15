#include "person.h"
#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)
using namespace std;

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

const string Person::getname() {
	return mName;
}

Person::Person(string name) {
	mName = name;
	mOwnedDepAcc;
	mOwnedSavAcc;
	genPerNum();
}

Person::Person(string name, string num) {
	mName = name;
	mOwnedDepAcc;
	mOwnedSavAcc;
	mPerNum = num;
}


void Person::addSavAcc(SavingAccount newACC) {
	mOwnedSavAcc.push_back(newACC);
}

void Person::addDepAcc(DepositAccount newACC) {
	mOwnedDepAcc.push_back(newACC);
}

void Person::rmAcc(string accNum) { // GUI 다듬기~
	for (int i = 0; i < mOwnedSavAcc.size(); i++) {
		if (mOwnedSavAcc[i].getAccNum().compare(accNum) == 0) {
			cout << accNum << "정기적금계좌가 해지 되었습니다." << endl;
			mOwnedSavAcc.erase(mOwnedSavAcc.begin() + i);
			return;
		}
	}
	for (int i = 0; i < mOwnedDepAcc.size(); i++) {
		if (mOwnedDepAcc[i].DepositAccount::getAccNum().compare(accNum) == 0) {
			cout << accNum << "보통예금계좌가 해지 되었습니다." << endl;
			mOwnedDepAcc.erase(mOwnedDepAcc.begin() + i);
			return;
		}
	}
}

SavingAccount& Person::getSavAcc(string accNum) {
	static SavingAccount tmpssss("", "", "", 0);
	for (int i = 0; i < mOwnedSavAcc.size(); i++) {
		if (mOwnedSavAcc[i].SavingAccount::getAccNum().compare(accNum) == 0) {
			return mOwnedSavAcc[i];
		}
	}
	return tmpssss;
}
DepositAccount& Person::getDepAcc(string accNum) {
	static DepositAccount tmpssss("", "", 0);
	for (int i = 0; i < mOwnedDepAcc.size(); i++) {
		if (mOwnedDepAcc[i].DepositAccount::getAccNum().compare(accNum) == 0) {
			return mOwnedDepAcc[i];
		}
	}
	return tmpssss;
}

void Person::setDate()
{
	string date = "date /T > date.txt";
	system(date.c_str());
}

const bool Person::getDate() {

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

std::vector<SavingAccount>& Person::getSavAcc()
{
	return mOwnedSavAcc;
}

std::vector<DepositAccount>& Person::getDepAcc()
{
	return mOwnedDepAcc;
}

LoanAccount& Person::getLoan()
{
	return loan;
}

void Person::dailyInterest()
{
	if (getDate()) {
		for (auto i : mOwnedSavAcc) {
			if (i.getsavingmonth() <= 0) {
				rmAcc(i.getAccNum());
				break;
			}
			int tAmount = (SAVE_RATE / 100) * i.getBalance();
			getDepAcc(i.getSourceAcc()).withdrawal(tAmount);
			i.deposit(tAmount);									//적금
		}
		for (auto i : mOwnedDepAcc) {
			i.deposit((DEPOSIT_RATE / 100) * i.getBalance());	//예금
		}
		loan.deposit((LOAN_RATE / 100) * loan.getBalance());//대출
	}
}

void Person::savePer(int perOrder)
{
	int accOrder = 0;
	string tmp = "md customer 2>nul";
	system(tmp.c_str());

	tmp = "md .\\customer\\";
	tmp += to_string(perOrder);
	tmp += " 2> nul ";
	system(tmp.c_str());

	ofstream os(".\\customer\\" + to_string(perOrder) + "\\" + to_string(perOrder));
	ofstream os2(".\\customer\\" + to_string(perOrder) + "\\" + to_string(perOrder) + "p");
	os << mPerNum << '\n';
	os << mName << '\n';
	os << loan.getAccNum() << "\n";
	os << loan.getBalance() << "\n";
	os << loan.getPerName() << "\n";
	os << loan.getBnkName() << "\n";
	os2 << Encry(loan.getPwd()) << "\n";
	os.close();
	os2.close();

	for (auto i : mOwnedSavAcc) {
		saveAcc(i, perOrder, accOrder);
		accOrder++;
	}
	for (auto i : mOwnedDepAcc) {
		saveAcc(i, perOrder, accOrder);
		accOrder++;
	}
	tmp = "start /wait /min ssh -o StrictHostKeyChecking=no -i id_rsa -p 8080 cppproj@1.225.217.57 rm -r ./customer/*";
	system(tmp.c_str());
}

void Person::loadPer(int perOrder, string perNum) {
	string filename = "./\\customer\\" + to_string(perOrder) + "\\" + to_string(perOrder);
	string accNum;
	string balance = "0";
	string perName;
	string bnkName;
	unsigned int pwd;
	string crypt;
	try
	{
		ifstream is1(filename);
		getline(is1, accNum);
		getline(is1, accNum);
		getline(is1, accNum);
		getline(is1, balance);
		getline(is1, perName);
		getline(is1, bnkName);
		is1.close();

		filename = "./\\customer\\" + to_string(perOrder) + "\\" + to_string(perOrder) + "p";
		ifstream is(filename);
		getline(is, crypt);
		pwd = Decry(crypt);
		is.close();
	}
	catch (...)
	{
		cout << "******************파일입출력 오류!******************" << endl;
		return;
	}
	LoanAccount tLoan(accNum, stoi(balance), perName, bnkName, pwd);
	loan = tLoan;
	for (int i = 0; loadAcc(perOrder, i); i++) {}
}

void Person::saveAcc(DepositAccount& account, int perOrder, int accOrder) {

	ofstream os(".\\customer\\" + to_string(perOrder) + "\\A" + to_string(accOrder));
	ofstream os2(".\\customer\\" + to_string(perOrder) + "\\AP" + to_string(accOrder));
	os << account.getAccNum() << "\n";
	os << account.getBalance() << "\n";
	os << account.getPerName() << "\n";
	os << account.getBnkName() << "\n";
	os2 << Encry(account.getPwd()) << "\n";
	os.close();
	os2.close();
}

void Person::saveAcc(SavingAccount& account, int perOrder, int accOrder) {

	try
	{
		ofstream os(".\\customer\\" + to_string(perOrder) + "\\A" + to_string(accOrder));
		ofstream os2(".\\customer\\" + to_string(perOrder) + "\\AP" + to_string(accOrder));
		os << account.getAccNum() << "\n";
		os << account.getBalance() << "\n";
		os << account.getPerName() << "\n";
		os << account.getBnkName() << "\n";
		os2 << Encry(account.getPwd()) << "\n";
		os << account.getSourceAcc() << "\n";
		os.close();
		os2.close();
	}
	catch (...)
	{
		cout << "******************파일입출력 오류!******************" << endl;
		return;
	}
}

bool Person::loadAcc(int perOrder, int accOrder) {

	string accNum;
	string perName;
	string bnkName;
	string sourceAcc = "";
	string crypt;
	unsigned int balance;
	unsigned int pwd;
	try
	{
		ifstream is(".\\customer\\" + to_string(perOrder) + "\\A" + to_string(accOrder));
		if (!is.is_open())
			return false;
		is >> accNum;
		is >> balance;
		is >> perName;
		is >> bnkName;
		is >> sourceAcc;
		is.close();

		ifstream is2(".\\customer\\" + to_string(perOrder) + "\\AP" + to_string(accOrder));
		is2 >> crypt;
		pwd = Decry(crypt);
		is2.close();

		if (sourceAcc == "") {
			DepositAccount tmp(accNum, balance, perName, bnkName, pwd);
			mOwnedDepAcc.push_back(tmp);
			tmp.~tmp();
		}
		else {
			SavingAccount tmp(accNum, sourceAcc, balance, perName, bnkName, pwd);
			mOwnedSavAcc.push_back(tmp);
			tmp.~tmp();
		}
		return true;
	}
	catch (...)
	{
		cout << "******************파일입출력 오류!******************" << endl;
		return false;
	}

}

string Person::Encry(unsigned int Pwd) {
	char tmp[10];
	for (int i = 0; i < 10; i++)
	{
		tmp[i] = Pwd % 10;
		Pwd /= 10;
		if (Pwd == 0)
		{
			break;
		}
	}
	char encrypt[10];

	ZeroMemory(encrypt, sizeof(encrypt));

	Account::Encrypt(tmp, encrypt, sizeof(tmp));
	string str(encrypt);

	return str;
}

unsigned int Person::Decry(string encrypt) {
	char tmp[100];
	char* ptr;
	strcpy(tmp, encrypt.c_str());

	char decrypt[100];
	ZeroMemory(decrypt, sizeof(decrypt));
	Account::Decrypt(tmp, decrypt, sizeof(decrypt));
	auto decryint = strtol(decrypt, &ptr, 10);

	return decryint;
}
