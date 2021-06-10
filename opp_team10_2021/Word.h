#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
/*
* 대상이 사람이름? 계좌?
* 부족한 정보를 다시 묻는다
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
	const void getInput();
	const std::string getName();
	void setTokenedString(std::string tmp);
	void saveWord();
	void addUsedSen(std::string sentence);
	std::string findWord(std::string firstWord);
	int findFunc();
	void swit(std::string name, int funcChoiced, int amount);

public:
	Word();
	void start();
};