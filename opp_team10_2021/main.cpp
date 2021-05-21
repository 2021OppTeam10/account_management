/*
* TODO
* 1. const, static, & 추가
* 2. 예금이랑 적금 계좌 생성자 넣기. 단 생성자 내에서 account 생성자 넣기. main에서 account 직접생성 금지.
* 3. 파일입출력 try-catch
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "person.h"
#include "DepositAccount.h"
#include "SavingAccount.h"

using namespace std;

#include <locale>
template <typename T>
void save(T account) {
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

	cout << "-------------------------------------------------< UPLOAD FILE >-------------------------------------------------" << endl;
	string uploadBase1 = "scp -o \"StrictHostKeyChecking no\" -i ./id_rsa -P 8080 ./customer/";
	string uploadBase2 = " cppproj@1.225.217.57:/home/cppproj/customer/";

	filename = account.getPerName() + ".txt";
	string upload = uploadBase1 + filename + uploadBase2;
	cout << ".................................................................................................................";
	system(upload.c_str());

	filename = account.getPerName() + "pw";
	upload = uploadBase1 + filename + uploadBase2;
	cout << ".................................................................................................................";
	system(upload.c_str());
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl << endl;
	_wsetlocale(LC_ALL, L"korean");
}

template <typename T>
void load(T account) {
	string filename = account.getPerName();
	ifstream is("./customer/" + filename + ".txt");
	ifstream is2("./customer/" + filename + "pw");
	is.close();
	is2.close();

	cout << "------------------------------------------------< DONWLOAD FILE >------------------------------------------------" << endl;
	string downloadBase1 = "scp -o \"StrictHostKeyChecking no\" -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/";
	string downloadBase2 = " ./customer/";

	filename = account.getPerName() + ".txt";
	string download = downloadBase1 + filename + downloadBase2;
	cout << ".................................................................................................................";
	system(download.c_str());

	filename = account.getPerName() + "pw";
	download = downloadBase1 + filename + downloadBase2;
	cout << ".................................................................................................................";
	system(download.c_str());
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl << endl;
	_wsetlocale(LC_ALL, L"korean");
}

int main() {
	DepositAccount newDeposit("배재익", "우리은행", 1234);
	DepositAccount newDeposit2("나선혁", "신한은행", 2345);
	SavingAccount newSaving("홍석원", "농협은행", 3456);
	save(newDeposit);
	save(newDeposit2);
	save(newSaving);
	load(newDeposit);
	load(newDeposit2);
	load(newSaving);

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