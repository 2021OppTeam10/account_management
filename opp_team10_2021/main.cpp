/*
* TODO
* 1. const, static, & 추가
* 2. 예금이랑 적금 계좌 생성자 넣기. 단 생성자 내에서 account 생성자 넣기. main에서 account 직접생성 금지.
* 3. 파일입출력 try-catch
* 4. 업로드 다운로드 때 오류나면?
* 5. 클래스 상속 가상함수 프렌즈함수 제네릭함수 파일입력
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

	if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // 똑바로 입력한경우
	{
		myWord.saveWord();
		myWord.swit(name, funcChoiced, amount);
	}
	else {
		int tmp = 1;
		string tmpS = myWord.findWord(myWord.getTokenedString()[0]);
		while (1)
		{
			cout << tmpS << "를 실행할까요?" << endl;
			myWord.getInput();
			string tmpSS = myWord.getinputString();
			if (tmpSS == "네")
			{
				myWord.setTokenedString(tmpS);
				funcChoiced = myWord.findFunc();
				amount = myWord.getAmount();
				name = myWord.getName();
				myWord.swit(name, funcChoiced, amount);
				break;
			}
			else if (tmpSS == "아니오")
			{
				break;
			}
			else
			{
				cout << "입력오류" << endl;
			}
		}
	}

	DepositAccount newDeposit("배재익", "우리은행", 1234);
	DepositAccount newDeposit2("나선혁", "신한은행", 2345);
	SavingAccount newSaving("홍석원", "농협은행", 3456);

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