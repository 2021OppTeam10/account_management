/*
* TODO
* 1. const, static, & �߰�
* 3. ��������� try-catch
* 6. main�� cusList load�ϴ� �Լ� person�� friend
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <ctime>

#include "Word.h"
#include "person.h"

using namespace std;

void mainLoad(){}

int main() {

	vector<Person> cusList; // customer list
	//Word myWord;
	Person p1("������");

	DepositAccount newDeposit("������", "�츮����", 1234);
	DepositAccount newDeposit2("������", "�츮����", 1234);
	//DepositAccount newDeposit2("������", "��������", 2345);
	//SavingAccount newSaving("ȫ����", "��������", 3456);


	p1.loadPer(0);
	p1.addDepAcc(newDeposit);
	p1.addDepAcc(newDeposit2);
	//p1.savePer(0);

	//string name = myWord.getName();
	//int funcChoiced = myWord.findFunc();
	//int amount = myWord.getAmount();

	//if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // �ȹٷ� �Է��Ѱ��
	//{
	//	myWord.saveWord();
	//	myWord.swit(name, funcChoiced, amount);
	//}
	//else {
	//	int tmp = 1;
	//	string tmpS = myWord.findWord(myWord.getTokenedString()[0]);
	//	while (1)
	//	{
	//		cout << tmpS << "�� �����ұ��?" << endl;
	//		myWord.getInput();
	//		string tmpSS = myWord.getinputString();
	//		if (tmpSS == "��")
	//		{
	//			myWord.setTokenedString(tmpS);
	//			funcChoiced = myWord.findFunc();
	//			amount = myWord.getAmount();
	//			name = myWord.getName();
	//			myWord.swit(name, funcChoiced, amount);
	//			break;
	//		}
	//		else if (tmpSS == "�ƴϿ�")
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			cout << "�Է¿���" << endl;
	//		}
	//	}
	//}

	return 0;
}