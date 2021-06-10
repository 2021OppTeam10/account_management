#include "Word.h"
#include "person.h"

using namespace std;

int Word::findFunc() {
	vector<string> funcList = { "�Ա�", "���", "�۱�", "���°���", "����", "���»���" };
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
	tokenedString = StringToken(inputString);
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
		size_t nPos = i.find("����");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			result = '0';
			result += i.substr(0, nPos);
			break;
		}
		nPos = i.find("����");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			result = '1';
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

string Word::findUsedSen(string sentence) {
	int tmp = 0;
	for (size_t i = 0; i < usedSen.size(); i++)
	{
		
	}
	return usedSen[tmp];
}

void Word::switFunc(string name, int funcChoiced, int amount) {
	switch (funcChoiced)
	{
	case 0:
		cout << name << "���� " << amount << "�� �Ա�ó��" << endl;
		break;
	case 1:
		cout << name << "���� " << amount << "�� ���ó��" << endl;
		break;
	case 2:
		cout << name << "���� " << amount << "�� �۱�ó��" << endl;
		break;
	default:
		cout << "����" << endl;
		break;
	}
}

void Word::start(vector<Person> cusList)
{
	LoadUsed();
	getInput();
	string name = getName();
	int funcChoiced = findFunc();
	int amount = mAmount;

	if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // �ȹٷ� �Է��Ѱ��
	{
		saveWord();
		if (name[0] == '0') // ���°� ���
		{
			name.erase(name.begin());
			switFunc(name, funcChoiced, amount);
		}
		else if(name[0] == '1') // �̸��� ���
		{
			name.erase(name.begin());
			//�̸� �� �����ְ�
			//
			cout << "���ϴ� ���¹�ȣ�� �Է��ϼ��� >> ";
			getInput();
		}
		else
		{
			cout << "�Է¿���!" << endl;
			return;
		}
	}
	else {
		int tmp = 1;
		string tmpS = findUsedSen(inputString);
		while (1)
		{
			cout << tmpS << "�� �����ұ��?" << endl;
			getInput();
			string tmpSS = inputString;
			if (tmpSS == "��")
			{
				setTokenedString(tmpS);
				funcChoiced = findFunc();
				amount = mAmount;
				name = getName();
				switFunc(name, funcChoiced, amount);
				break;
			}
			else if (tmpSS == "�ƴϿ�")
			{
				break;
			}
			else
			{
				cout << "�Է¿���" << endl;
			}
		}
	}
}
