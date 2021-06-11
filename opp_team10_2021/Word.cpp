#include "Word.h"
#include "person.h"

using namespace std;

int Word::findFunc() {
	vector<string> funcList = { "�Ա�", "���", "�۱�", "����", "����", "����" };
	int funcChoiced = 99;
	for (int i = 0; funcChoiced == 99 && i < tokenedString.size(); i++) {
		for (int j = 0; j < 6; j++)
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

void Word::showManual()
{
	cout << "1. �ű� �� ���" << endl;
	cout << "2. ���� �� ���� �߰�" << endl;
	cout << "3. ���� �� ���� ����" << endl;
	cout << "4. ���� ��ȣ�� ������ȸ" << endl;
	cout << "5. ���� �ޱ�" << endl;
	cout << "6. ���� ��ȯ" << endl;
	cout << "7. �Ա� ��� �۱�" << endl;
}

void Word::printAllAccount(string PerName, vector<Person> cusList)
{
	vector<DepositAccount> tDep;
	vector<SavingAccount> tSav;
	cout << "�̸� : " << PerName;
	for (auto i : cusList) {
		if (PerName == i.getname()) {
			tDep = i.getDepAcc();
			tSav = i.getSavAcc();
			for (int j = 0; j < tDep.size(); j++) {
				cout << "���ݰ��� : " << tDep[j].getAccNum() << endl;
			}
			for (int j = 0; j < tSav.size(); j++) {
				cout << "���ݰ��� : " << tSav[j].getAccNum() << endl;
			}
		}
		else
			cout << "�̸��� �������� �ʽ��ϴ�." << endl;
	}
}

Person Word::whois(std::string accnum, std::vector<Person> cusList)
{
	int k = 0;
	string name;
	for (auto i : cusList)
	{
		try
		{
			name = cusList[k++].getDepAcc(accnum).getPerName();
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
			throw invalid_argument("�������� �ʴ� �����Դϴ�.");
		}
	}
	for (auto i : cusList) {
		if (i.getname() == name)
		{
			return i;
		}
	}
}

void Word::start(vector<Person> cusList)
{
	LoadUsed();
	getInput();
	string name = getName();
	int funcChoiced = findFunc();
	int amount = mAmount;

	while (true)
	{
		if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // �Ա� �۱� ���
		{
			if (name[0] == '1') // ���°� ���
			{
				printAllAccount(name, cusList);
				cout << "���ϴ� ���¹�ȣ�� �Է��ϼ���.";
			}
			else
			{
				saveWord();
				name.erase(name.begin());
				switFunc(name, funcChoiced, amount);
			}
		}
		else if (funcChoiced == 3) //���� -> ���� �߰�
		{
			vector<string> funcList = { "����", "�߰�" };
			int funcChoiced = 99;
			for (int i = 0; funcChoiced == 99 && i < tokenedString.size(); i++) {
				for (int j = 0; j < 2; j++)
				{
					if (tokenedString[i].find(funcList[j]) != string::npos)
					{
						funcChoiced = j;
						break;
					}
				}
			}
			if (funcChoiced == 0 && name[0] == '0') // ����
			{
				name.erase(name.begin());
				try { whois(name, cusList).rmAcc(name); }
				catch (const invalid_argument& e) { cout << e.what() << endl; break; }
			}
			else if (funcChoiced == 1 && name[0] == '1') // �߰� + �̸� �Է�������
			{
				for (auto i : cusList)
				{
					if (i.getname() == name) {
						name.erase(name.begin());
						string tin;
						string tin2;
						unsigned tp;
						bool isEnd = false;
						cout << "���� ���ݰ� ���� ���� �߿��� � ���� �߰��ұ��?" << endl;
						cin >> tin;
						cout << "�����̸��� �Է��ϼ���" << endl;
						cin >> tin2;
						cout << "��й�ȣ�� �Է��ϼ���" << endl;
						cin >> tp;
						while (!isEnd)
						{
							cout << "���� ���ݰ� ���� ���� �߿��� � ���� �߰��ұ��?" << endl;
							cin >> tin;
							if (tin.find("����"))
							{
								DepositAccount tmp(name, tin2, tp);
								i.addDepAcc(tmp);
								isEnd = true;
							}
							else if (tin.find("����"))
							{
								cout << "��� �����´� �������� �ұ��?" << endl;
								cin >> tin;
								SavingAccount tmp(tin, name, tin2, tp);
								i.addSavAcc(tmp);
								isEnd = true;
							}
							else
							{
								cout << "���ݰ� ���� �߿��� �Է��ϼ���" << endl;
							}
						}
						break;
					}
				}
			}
			else
			{
				cout << "���� ������ ���Ͻø� \"(���¹�ȣ)���ε� ���¸� ��������\"�� �Է��ϼ���" << endl;
				cout << "���� �߰��� ���Ͻø� \"(�̸�)���� ���¸� �߰�����\"�� �Է��ϼ���" << endl;
			}
		}
		else if (funcChoiced == 4) //����
		{
			name.erase(name.begin());
			cout << "���ο� ������ " << name << "���� �߰��ұ��?" << endl;
			getInput();
			string tmpSS = inputString;
			if (tmpSS == "��")
			{
				Person tmp(name);
				cusList.push_back(tmp);
				cout << "�߰� �Ϸ�." << endl;
			}
			else if (tmpSS == "�ƴϿ�")
			{
				cout << "�۾��� ����մϴ�." << endl;
			}
			else
			{
				cout << "�۾��� ����մϴ�." << endl;
			}
		}
		else if (funcChoiced == 5) //����
		{
			vector<string> funcList = { "��ȯ", "�߰�" };
			int funcChoiced = 99;
			for (int i = 0; funcChoiced == 99 && i < tokenedString.size(); i++) {
				for (int j = 0; j < 2; j++)
				{
					if (tokenedString[i].find(funcList[j]) != string::npos)
					{
						funcChoiced = j;
						break;
					}
				}
			}
			if (funcChoiced == 0) // ��ȯ
			{
				for (auto i : cusList)
				{
					if (i.getname() == name) {
						string dest;
						int amt;
						cout << "�󸶸� ������ �ǰ���?" << endl;
						cin >> amt;
						cout << "����Ͻ� ���� ���¹�ȣ�� �Է����ּ���" << endl;
						cin >> dest;
						i.getLoan().Repayment(i.getDepAcc(dest), amount);
						break;
					}
				}
				
			}
			else if (funcChoiced == 1) // �߰�
			{
				cout << "�����߰�" << endl;
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
	
}
