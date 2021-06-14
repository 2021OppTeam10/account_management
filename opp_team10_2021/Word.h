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
};