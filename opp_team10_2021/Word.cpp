#include "Word.h"
#include "person.h"

using namespace std;

Word::Word()
{
	std::getline(std::cin, inputString);
	tokenedString = StringToken(inputString);
	for (auto i : tokenedString)
	{
		size_t wonPos = i.find("원을");
		if (wonPos != string::npos && wonPos != 0 && wonPos != -1)
		{
			mAmount = stoi(i.substr(0, wonPos));
			break;
		}
	}
	LoadUsed();
}

int Word::findFunc() {
	vector<string> funcList = { "입금", "출금", "송금", "계좌개설", "대출", "계좌삭제" };
	int funcChoiced = 3;
	for (int i = 0; funcChoiced == 3 && i < tokenedString.size(); i++) {
		for (int j = 0; j < 3; j++)
		{
			if (tokenedString[i].find(funcList[j]) != string::npos)
			{
				funcChoiced = j;
				break;
			}
		}
	}
	return funcChoiced;
}

const void Word::getInput()
{
	getline(cin, inputString);
}

void Word::setTokenedString(std::string tmp)
{
	tokenedString = StringToken(tmp);
}

void Word::saveWord()
{
	addUsedSen(inputString);
	sort(usedSen.begin(), usedSen.end());
	unique(usedSen.begin(), usedSen.end());
	ofstream os2("UsedSen.txt");
	for (auto sen : usedSen)
	{
		if (sen != "")
		{
			os2.write(sen.c_str(), sen.size());
			os2.write("\n", 1);
		}
	}
	os2.close();
}

const std::string Word::getName() {
	string result;
	for (auto i : tokenedString)
	{
		size_t nPos = i.find("으로");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			result = '0';
			result += i.substr(0, nPos);
			break;
		}
		nPos = i.find("에게");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			result = '0';
			result += i.substr(0, nPos);
			break;
		}
	}
	return result;
}

vector<string> Word::StringToken(string inputString) {
	vector<string> result;
	size_t spacePos = 0;
	while (!inputString.empty())
	{
		spacePos = inputString.find(' ');
		if (spacePos == -1)	spacePos = inputString.size();
		result.push_back(inputString.substr(0, spacePos));
		inputString.erase(0, spacePos + 1);
	}
	return result;
}

void Word::LoadUsed() {
	ifstream is2("UsedSen.txt");
	string tmp;
	if (!is2.is_open())
	{
		return;
	}
	for (int i = 0; !is2.eof(); i++)
	{
		getline(is2, tmp);
		if (tmp != "")
		{
			usedSen.push_back(tmp);
		}
	}
	is2.close();
}
void Word::addUsedSen(string sentence) {
	usedSen.push_back(sentence);
}

string Word::findWord(string firstWord) {
	int tmp = 0;
	for (size_t i = 0; i < usedSen.size(); i++)
	{
		if (usedSen[i].find(firstWord) != string::npos && usedSen[i].find(firstWord) != -1) {
			tmp = i;
			break;
		}
	}
	return usedSen[tmp];
}

void Word::swit(string name, int funcChoiced, int amount) {
	switch (funcChoiced)
	{
	case 0:
		cout << name << "에게 " << amount << "원 입금처리" << endl;
		break;
	case 1:
		cout << name << "에게 " << amount << "원 출금처리" << endl;
		break;
	case 2:
		cout << name << "에게 " << amount << "원 송금처리" << endl;
		break;
	default:
		cout << "오류" << endl;
		break;
	}
}

void Word::start()
{
	string name = getName();
	int funcChoiced = findFunc();
	int amount = mAmount;

	if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // 똑바로 입력한경우
	{
		saveWord();
		swit(name, funcChoiced, amount);
	}
	else {
		int tmp = 1;
		string tmpS = findWord(tokenedString[0]);
		while (1)
		{
			cout << tmpS << "를 실행할까요?" << endl;
			getInput();
			string tmpSS = inputString;
			if (tmpSS == "네")
			{
				setTokenedString(tmpS);
				funcChoiced = findFunc();
				amount = mAmount;
				name = getName();
				swit(name, funcChoiced, amount);
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
}
