/*
* TODO
* 1. const, static, & 추가
* 3. 파일입출력 try-catch
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

vector<Person> mainLoad() {
	vector<Person> result;
	string name;
	string num;
	int count = 0;
	ifstream is(".\\customer\\" + to_string(count) + "\\" + to_string(count));
	do
	{
		getline(is, num);
		getline(is, name);
		Person tmp(name, num);
		tmp.loadPer(count, num);
		is.close();
		result.push_back(tmp);
		count++;
		ifstream is(".\\customer\\" + to_string(count) + "\\" + to_string(count));
	} while (is.is_open());
	return result;
}

 int main() {

	vector<Person> cusList = mainLoad(); // customer list
	Word myWord;


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