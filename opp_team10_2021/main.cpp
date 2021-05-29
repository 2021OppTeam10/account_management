/*
* TODO
* 1. const, static, & 추가
* 3. 파일입출력 try-catch
* 6. main에 cusList load하는 함수 person에 friend
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
	Person p1("배재익");

	DepositAccount newDeposit("배재익", "우리은행", 1234);
	DepositAccount newDeposit2("배재익", "우리은행", 1234);
	//DepositAccount newDeposit2("나선혁", "신한은행", 2345);
	//SavingAccount newSaving("홍석원", "농협은행", 3456);


	p1.loadPer(0);
	p1.addDepAcc(newDeposit);
	p1.addDepAcc(newDeposit2);
	//p1.savePer(0);

	//string name = myWord.getName();
	//int funcChoiced = myWord.findFunc();
	//int amount = myWord.getAmount();

	//if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // 똑바로 입력한경우
	//{
	//	myWord.saveWord();
	//	myWord.swit(name, funcChoiced, amount);
	//}
	//else {
	//	int tmp = 1;
	//	string tmpS = myWord.findWord(myWord.getTokenedString()[0]);
	//	while (1)
	//	{
	//		cout << tmpS << "를 실행할까요?" << endl;
	//		myWord.getInput();
	//		string tmpSS = myWord.getinputString();
	//		if (tmpSS == "네")
	//		{
	//			myWord.setTokenedString(tmpS);
	//			funcChoiced = myWord.findFunc();
	//			amount = myWord.getAmount();
	//			name = myWord.getName();
	//			myWord.swit(name, funcChoiced, amount);
	//			break;
	//		}
	//		else if (tmpSS == "아니오")
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			cout << "입력오류" << endl;
	//		}
	//	}
	//}

	return 0;
}