/*
* TODO
* 1. const, static, & �߰�
* 2. �����̶� ���� ���� ������ �ֱ�. �� ������ ������ account ������ �ֱ�. main���� account �������� ����.
* 3. ��������� try-catch
* 4. ���ε� �ٿ�ε� �� ��������?
* 5. Ŭ���� ��� �����Լ� �������Լ� ���׸��Լ� �����Է�
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
#include "Word.h"

using namespace std;

int main() {

	vector<Person> cusList; // customer list
	Word myWord;

	string name = myWord.getName();
	int funcChoiced = myWord.findFunc();
	int amount = myWord.getAmount();

	if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // �ȹٷ� �Է��Ѱ��
	{
		myWord.saveWord();
		myWord.swit(name, funcChoiced, amount);
	}
	else {
		int tmp = 1;
		string tmpS = myWord.findWord(myWord.getTokenedString()[0]);
		while (1)
		{
			cout << tmpS << "�� �����ұ��?" << endl;
			myWord.getInput();
			string tmpSS = myWord.getinputString();
			if (tmpSS == "��")
			{
				myWord.setTokenedString(tmpS);
				funcChoiced = myWord.findFunc();
				amount = myWord.getAmount();
				name = myWord.getName();
				myWord.swit(name, funcChoiced, amount);
				break;
			}
			else if (tmpSS == "�ƴϿ�")
			{
				break;
			}
			else
			{
				cout << "�Է¿���" << endl;
			}
		}
	}

	DepositAccount newDeposit("������", "�츮����", 1234);
	DepositAccount newDeposit2("������", "��������", 2345);
	SavingAccount newSaving("ȫ����", "��������", 3456);

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