/*
* TODO
* 1. & 추가
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
	int count = 1;
	ifstream is(".\\customer\\" + to_string(count) + "\\" + to_string(count));
	if (!is.is_open())
		return result;
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
	for (auto i : cusList)
		i.dailyInterest();
	Word myWord;
	myWord.start(cusList);
	return 0;
}