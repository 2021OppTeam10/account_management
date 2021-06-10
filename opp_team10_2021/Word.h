#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
/*
* ����� ����̸�? ����?
* ������ ������ �ٽ� ���´�
*/
class Word {
private:
	std::string inputString;
	std::vector<std::string> tokenedString;
	std::vector<std::string> usedWord;
	std::vector<std::string> usedSen;
	std::vector<std::string> StringToken(std::string inputString);
	int mAmount = 0;
	void LoadUsed();

public:
	Word();
	const void getInput();
	const int getAmount();
	const std::string getinputString();
	const std::vector<std::string> getTokenedString();
	const std::string getName();
	void setTokenedString(std::string tmp);
	void saveWord();
	void addUsedWord(std::string word);
	void addUsedSen(std::string sentence);
	std::string findWord(std::string firstWord);
	int findFunc();
	void swit(std::string name, int funcChoiced, int amount);
};