/*
* TODO
* 1. const, static, & �߰�
* 2. �����̶� ���� ���� ������ �ֱ�. �� ������ ������ account ������ �ֱ�. main���� account �������� ����.
* 3. ��������� try-catch
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

	string uploadBase1 = "scp -o \"StrictHostKeyChecking no\" -i ./id_rsa -P 8080 ./customer/";
	string uploadBase2 = " cppproj@1.225.217.57:/home/cppproj/customer/";

	cout << "------------------------------< UPLOAD FILE >-----------------------------" << endl;
	filename = account.getPerName() + ".txt";
	string upload = uploadBase1 + filename + uploadBase2;
	string cmd = "start /MIN " + upload;
	if (system(cmd.c_str()) == 0) {
		cout << filename << endl;
	}

	filename = account.getPerName() + "pw";
	upload = uploadBase1 + filename + uploadBase2;
	cmd = "start /MIN " + upload;
	if (system(cmd.c_str()) == 0) {
		cout << filename << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl << endl;
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
	string cmd = "start /MIN " + download;
	if (system(cmd.c_str()) == 0) {
		cout << filename << endl;
	}

	filename = account.getPerName() + "pw";
	download = downloadBase1 + filename + downloadBase2;
	cmd = "start /MIN " + download;
	if (system(cmd.c_str()) == 0) {
		cout << filename << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl << endl;
}

int main() {
	DepositAccount newDeposit("������", "�츮����", 1234);
	DepositAccount newDeposit2("������", "��������", 2345);
	SavingAccount newSaving("ȫ����", "��������", 3456);
	save(newDeposit);
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