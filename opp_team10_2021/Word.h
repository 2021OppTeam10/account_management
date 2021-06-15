#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "person.h"

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
	friend inline std::vector<Person> wordLoad();
};

inline std::vector<Person> wordLoad() {
	std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t다운로드 처리중..." << std::endl;
	std::string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ . > nul";
	std::locale::global(std::locale("Korean"));
	if (system(download.c_str()) == 0) {
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-다운로드 완료-" << std::endl;
	}
	else {
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-다운로드 실패-" << std::endl;
		exit(0);
	}
	std::vector<Person> result;
	std::string name;
	std::string num;
	int count = 0;
	while (true)
	{
		std::ifstream is(".\\customer\\" + std::to_string(count) + "\\" + std::to_string(count));
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