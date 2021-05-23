/*
* TODO
* 1. const, static, & 추가
* 2. 예금이랑 적금 계좌 생성자 넣기. 단 생성자 내에서 account 생성자 넣기. main에서 account 직접생성 금지.
* 3. 파일입출력 try-catch
* 4. 업로드 다운로드 때 오류나면?
* 5. 대출?
*/
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <ctime>
#include "person.h"
#include "DepositAccount.h"
#include "SavingAccount.h"

using namespace std;

template <typename T>
void save(T account) {
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
void load(T account) {
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

void setDate() {
	string date = "date /T > date.txt";
	system(date.c_str());
}

bool getDate() {

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

int main() {
	getDate();
	DepositAccount newDeposit("배재익", "우리은행", 1234);
	DepositAccount newDeposit2("나선혁", "신한은행", 2345);
	SavingAccount newSaving("홍석원", "농협은행", 3456);
	save(newDeposit);

	newDeposit.deposit(10000);
	newDeposit.printAccount();
	newDeposit2.printAccount();
	newSaving.printAccount();

	newDeposit.transfer(newDeposit2, 1000);

	newDeposit.printAccount();
	newDeposit2.printAccount();
	newSaving.printAccount();

	return 0;
}