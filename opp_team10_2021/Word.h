#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "person.h"

vector<Person> wordLoad() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t다운로드 처리중..." << endl;
	string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ . > nul";
	std::locale::global(std::locale("Korean"));
	if (system(download.c_str()) == 0) {
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-다운로드 완료-" << endl;
	}
	else {
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-다운로드 실패-" << endl;
		exit(0);
	}
	vector<Person> result;
	string name;
	string num;
	int count = 0;
	while (true)
	{
		ifstream is(".\\customer\\" + to_string(count) + "\\" + to_string(count));
		if (!is.is_open()) {
			break;
		}
		getline(is, num);
		getline(is, name);
		Person tmp(name, num);
		tmp.loadPer(count, num);
		result.push_back(tmp);
		count++;
		is.close();
	}
	return result;
}

class Word {
private:
	std::string inputString;
	std::vector<std::string> tokenedString;
	std::vector<std::string> usedSen;
	int mAmount = 0;
	std::vector<std::string> StringToken(std::string inputString);
	void LoadUsed();
	bool getInput();
	const std::string getName();
	void setTokenedString(std::string tmp);
	void saveWord();
	void addUsedSen(std::string sentence);
	std::string findUsedSen(std::string sentence);
	void switFunc(std::string accNum, int funcChoiced, int amount, std::vector<Person>& cusList);
	int findFunc();
	void showManual();
	void printAllAccount(std::string PerName, std::vector<Person>& cusList);
	Person& whois(std::string accnum, std::vector<Person>& cusList);
	void mainWork(std::vector<Person>& cusList);
public:
	void start(std::vector<Person>& cusList);
	friend vector<Person> wordLoad();
};
