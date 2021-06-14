#include "Word.h"

using namespace std;

vector<Person> wordLoad() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t�ٿ�ε� ó����..." << endl;
	string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ .";
	string cmd = "start /wait /min " + download;
	std::locale::global(std::locale("Korean"));
	if (system(cmd.c_str()) == 0) {
		cout << "\x1b[A";
		cout << "\33[2K";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-�ٿ�ε� �Ϸ�-" << endl;
	}
	else {
		cout << "\x1b[A";
		cout << "\33[2K";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-�ٿ�ε� ����-" << endl;
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

bool Word::getInput()
{
	system("timeout 1 > nul");
	cout << "��ɾ� �Է� > ";
	getline(cin, inputString);
	if (inputString == "����")
	{
		return false;
	}
	tokenedString = StringToken(inputString);
	return true;
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
		size_t nPos = i.find("�� ");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			mAmount = stoi(i.substr(0, nPos));
		}
		 nPos = i.find("��ȣ");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			result = '0';
			result += i.substr(0, nPos);
		}
		if (result == "")
		{
			nPos = i.find("����");
			if (nPos != string::npos && nPos != 0 && nPos != -1)
			{
				result = '1';
				result += i.substr(0, nPos);
			}
			nPos = i.find("��");
			if (nPos != string::npos && nPos != 0 && nPos != -1)
			{
				result = '1';
				result += i.substr(0, nPos);
			}
			nPos = i.find("��");
			if (nPos != string::npos && nPos != 0 && nPos != -1)
			{
				result = '1';
				result += i.substr(0, nPos);
			}
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
		result.push_back(inputString.substr(0, spacePos+1));
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
	for (auto i : usedSen)
	{
		if (i.find(sentence) != string::npos) {
			return i;
		}
	}
	return "";
}

void Word::switFunc(std::string accNum, int funcChoiced, int amount, std::vector<Person>& cusList)
{
	unsigned tp;
	for (int i = 0; i < cusList.size(); i++)
	{
		for (int j = 0; j < cusList[i].getDepAcc().size(); j++)
		{
			if (cusList[i].getDepAcc()[j].getAccNum() == accNum)
			{
				cout << "���� ��й�ȣ�� �Է����ּ���" << endl;
				cin >> tp;
				cin.ignore();
				if (cusList[i].getDepAcc()[j].isCorrect(tp))
				{
					switch (funcChoiced)
					{
					case 0:
						cusList[i].getDepAcc()[j].deposit(amount);
						cout << accNum << "���� " << amount << "�� �Ա�ó��" << endl;
						break;
					case 1:
						if (cusList[i].getDepAcc()[j].withdrawal(amount))
						{
							cout << accNum << "���� " << amount << "�� ���ó��" << endl;
							break;
						}
						else
						{
							break;
						}
					case 2:
						DepositAccount tD("NULL", "NULL", 0);
						string source;
						cout << "���� ����ؼ� ������ ���¸� �Է��ϼ���" << endl;
						cin >> source;
						cin.ignore();
						bool isFind = false;
						for (auto k : cusList)
						{
							for (auto s : k.getDepAcc())
							{
								if (s.getAccNum() == source)
								{
									tD = s;
									isFind++;
									break;
								}
							}
							if (isFind)
							{
								break;
							}
						}
						if (tD.getPerName() != "NULL")
						{
							if (tD.withdrawal(amount))
							{
								cout << accNum << "���� " << amount << "�� ���ó��" << endl;
								cusList[i].getDepAcc()[j].deposit(amount);
								cout << accNum << "���� " << amount << "�� �۱�ó��" << endl;
								break;
							}
							else
							{
								break;
							}
						}
						else {
							cout << "��� ���°� �ùٸ��� �ʽ��ϴ�." << endl;
							break;
						}
					}
				}
				else
				{
					cout << "��й�ȣ �Է� ����" << endl;
					break;
				}
				break;
			}
			for (auto j : cusList[i].getSavAcc())
			{
				if (j.getAccNum() == accNum)
				{
					cout << "���� ���´� ���� �Ա�, ���, �۱��� �Ұ����մϴ�." << endl;
					break;
				}
			}
		}
	}
}

void Word::showManual()
{
	cout << "������ ��ɾ��� �⺻ ���´� ������ �����ϴ�." << endl;
	cout << "\t1. �����" << endl;
	cout << "\t\t1. �Ա� : (���¹�ȣ)��ȣ�� (�ݾ�)�� �Ա�����" << endl;
	cout << "\t\t2. ��� : (���¹�ȣ)��ȣ�� (�ݾ�)�� �������" << endl;
	cout << "\t\t3. �۱� : (���¹�ȣ)��ȣ�� (�ݾ�)�� �۱�����" << endl;
	cout << "\t2. ���°���" << endl;
	cout << "\t\t1. �߰� : (�̸�)���� ���¸� �߰�����" << endl;
	cout << "\t\t2. ���� : (�̸�)���� ���¸� ��������" << endl;
	cout << "\t\t3. ��ȸ : (�̸�)��/�� ���� ��ȸ����" << endl;
	cout << "\t3. ������" << endl;
	cout << "\t\t1. �ű� �� ��� : (�̸�)��/�� ���� �������" << endl;
	cout << "\t4. �������" << endl;
	cout << "\t\t1. ��ȯ : (�̸�)���� ���� ��ȯ" << endl;
	cout << "\t\t2. �߰� ���� : (�̸�)���� �߰� ����" << endl;
}

void Word::printAllAccount(string PerName, vector<Person>& cusList)
{
	vector<DepositAccount> tDep;
	vector<SavingAccount> tSav;
	int result1 = 0;
	int result2 = 0;
	cout << "-------------���� ��ȸ-------------" << endl;
	cout << "��ȸ�Ͻ� ���� �̸� : " << PerName << endl;
	for (auto i : cusList) {
		if (PerName == i.getname()) {
			tDep = i.getDepAcc();
			tSav = i.getSavAcc();
			for (int j = 0; j < tDep.size(); j++) {
				tDep[j].printAccount();
				result1++;
			}
			cout << "�� ���� ���� ���¼��� " << result1 << "�� �Դϴ�." << endl;
			for (int j = 0; j < tSav.size(); j++) {
				tDep[j].printAccount();
				result2++;
			}
			cout << "�� ���� ���� ���¼��� " << result2 << "�� �Դϴ�." << endl;
		}
	}
}

Person Word::whois(std::string accnum, std::vector<Person>& cusList)
{
	int k = 0;
	string name;
	for (auto i : cusList)
	{
		try
		{
			name = cusList[k++].getDepAcc(accnum).getPerName();
			if (name != "")
			{
				break;
			}
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

void Word::mainWork(std::vector<Person>& cusList) {
	string name = getName();
	int amount = mAmount;
	int funcChoiced = findFunc();
	if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // �Ա� �۱� ���
	{
		if (name[0] == '1') // �̸��� ���
		{
			printAllAccount(name, cusList);
			cout << "���ϴ� ���¹�ȣ�� �Է��ϼ���." << endl;
		}
		else
		{
			name.erase(name.begin());
			saveWord();
			switFunc(name, funcChoiced, amount, cusList);
		}
	}
	else if (funcChoiced == 3) //���� -> ���� �߰�
	{
		vector<string> funcList = { "����", "�߰�", "��ȸ" };
		int funcChoiced = 99;
		for (int i = 0; funcChoiced == 99 && i < tokenedString.size(); i++) {
			for (int j = 0; j < 3; j++)
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
			try { 
				whois(name, cusList).rmAcc(name);
				saveWord();
			}
			catch (const invalid_argument& e) {
				cout << e.what() << endl;
				return;
			}
		}
		else if (funcChoiced == 1 && name[0] == '1') // �߰� + �̸� �Է�������
		{
			name.erase(name.begin());
			for (int i = 0; i < cusList.size(); i++)
			{
				if (cusList[i].getname() == name) {
					string tin;
					string tin2;
					unsigned tp;
					bool isEnd = false;
					cout << "���� ���ݰ� ���� ���� �߿��� � ���� �߰��ұ��?" << endl << "���� / ���� > ";
					cin >> tin;
					cin.ignore();
					cout << "�����̸��� �Է��ϼ���" << endl << "�Է� > ";
					cin >> tin2;
					cin.ignore();
					cout << "��й�ȣ�� �Է��ϼ���" << endl << "�Է� > ";
					cin >> tp;
					cin.ignore();
					while (!isEnd)
					{
						if (tin.find("����") != string::npos)
						{
							DepositAccount tmp(name, tin2, tp);
							cusList[i].addDepAcc(tmp);
							isEnd = true;
							cout << "���� ���°� �߰��Ǿ����ϴ�!" << endl;
							printAllAccount(name, cusList);
							saveWord();
						}
						else if (tin.find("����") != string::npos)
						{
							cout << "��� �����´� �������� �ұ��?" << endl;
							printAllAccount(name, cusList);
							cin >> tin;
							cin.ignore();
							SavingAccount tmp(tin, name, tin2, tp);
							cusList[i].addSavAcc(tmp);
							isEnd = true;
							cout << "���� ���°� �߰��Ǿ����ϴ�!" << endl;
							printAllAccount(name, cusList);
							saveWord();
						}
						else
						{
							cout << "���ݰ� ���� �߿��� �Է��ϼ���" << endl;
							return;
						}
					}
					return;
				}
			}
		}
		else if (funcChoiced == 2 && name[0] == '1')
		{
			name.erase(name.begin());
			printAllAccount(name, cusList);
		}
		else
		{
			string tmpS = findUsedSen(inputString);
			while (1)
			{
				if (tmpS == "")
				{
					cout << "�Է¿���" << endl;
					cout << "������ �� �ִ� �ֿ� ����� ������ �����ϴ�" << endl;
					showManual();
					return;
				}
				cout << tmpS << "�� �����ұ��?" << endl;
				string tmpSS;
				cout << "�� / �ƴϿ� > ";
				getline(cin, tmpSS);
				if (tmpSS == "��")
				{
					setTokenedString(tmpS);
					mainWork(cusList);
					return;
				}
				else if (tmpSS == "�ƴϿ�")
				{
					cout << "�۾��� ����մϴ�." << endl;
					return;
				}
				else
				{
					cout << "�Է¿���" << endl;
					showManual();
					return;
				}
			}
		}
	}
	else if (funcChoiced == 4) //����
	{
		name.erase(name.begin());
		for (auto i : cusList)
		{
			if (i.getname() == name) {
				cout << "�̹� �����ϴ� ���Դϴ�." << endl;
				return;
			}
		}
		cout << "���ο� ������ " << name << "���� �߰��ұ��?" << endl;
		getInput();
		string tmpSS = inputString;
		if (tmpSS == "��")
		{
			saveWord();
			Person tmp(name);
			cusList.push_back(tmp);
			cout << "�߰� �Ϸ�." << endl;
		}
		else
		{
			cout << "�۾��� ����մϴ�." << endl;
			return;
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
			name.erase(name.begin());
			for (auto i : cusList)
			{
				if (i.getname() == name) {
					string dest;
					int amt;
					unsigned tp;
					cout << "�󸶸� ������ �ǰ���?" << endl;
					cin >> amt;
					cin.ignore();
					cout << "����Ͻ� ���� ���¹�ȣ�� �Է����ּ���" << endl;
					cin >> dest;
					cin.ignore();
					cout << "����Ͻ� ���� ��й�ȣ�� �Է����ּ���" << endl;
					cin >> tp;
					cin.ignore();
					if (i.getLoan().isCorrect(tp)) {
						i.getLoan().Repayment(i.getDepAcc(dest), amount);
						saveWord();
					}
					else
					{
						cout << "��й�ȣ �Է� ����" << endl;
						return;
					}
					return;
				}
			}
		}
		else if (funcChoiced == 1) // �߰�
		{
			name.erase(name.begin());
			for (auto i : cusList)
			{
				if (i.getname() == name) {
					int amt;
					cout << "�󸶸� ������ �ǰ���?" << endl;
					cin >> amt;
					cin.ignore();

					string tin2;
					unsigned tp;
					cout << "�����̸��� �Է��ϼ���" << endl;
					cin >> tin2;
					cin.ignore();
					cout << "��й�ȣ�� �Է��ϼ���" << endl;
					cin >> tp;
					if (i.getLoan().isCorrect(tp)) {
						saveWord();
						i.getLoan().addLoan(name, tin2, amt);
						cout << amt << "�� ���� ó�� �Ϸ�" << endl;
						i.getLoan().printAccount();
						return;
					}
					else
					{
						cout << "��й�ȣ �Է� ����" << endl;
						return;
					}
				}
			}
		}
		else
		{
			string tmpS = findUsedSen(inputString);
			while (1)
			{
				if (tmpS == "")
				{
					cout << "�Է¿���" << endl;
					cout << "������ �� �ִ� �ֿ� ����� ������ �����ϴ�" << endl;
					showManual();
					return;
				}
				cout << tmpS << "�� �����ұ��?" << endl;
				string tmpSS;
				cout << "�� / �ƴϿ� > ";
				getline(cin, tmpSS);
				if (tmpSS == "��")
				{
					setTokenedString(tmpS);
					mainWork(cusList);
					return;
				}
				else if (tmpSS == "�ƴϿ�")
				{
					cout << "�۾��� ����մϴ�." << endl;
					return;
				}
				else
				{
					cout << "�Է¿���" << endl;
					showManual();
					return;
				}
			}
		}
	}
	else {
		string tmpS = findUsedSen(inputString);
		while (1)
		{
			if (tmpS == "")
			{
				cout << "�Է¿���" << endl;
				cout << "������ �� �ִ� �ֿ� ����� ������ �����ϴ�" << endl;
				showManual();
				return;
			}
			cout << tmpS << "�� �����ұ��?" << endl;
			string tmpSS;
			cout << "�� / �ƴϿ� > ";
			getline(cin, tmpSS);
			if (tmpSS == "��")
			{
				setTokenedString(tmpS);
				mainWork(cusList);
				return;
			}
			else if (tmpSS == "�ƴϿ�")
			{
				cout << "�۾��� ����մϴ�." << endl;
				return;
			}
			else
			{
				cout << "�Է¿���" << endl;
				showManual();
				return;
			}
		}
	}
}

void Word::start(std::vector<Person>& cusList)
{
	LoadUsed();
	int c;
	showManual();
	while (getInput())
	{
		cusList = wordLoad();
		mainWork(cusList);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t���ε� ó����..." << endl;
		c = 0;
		for (int i = 0; i < cusList.size(); i++)
		{
			cusList[i].savePer(c++);
		}
		string upload = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i .\\id_rsa -P 8080 .\\customer\\ cppproj@1.225.217.57:/home/cppproj/";
		string cmd = "start /min /wait " + upload;
		std::locale::global(std::locale("Korean"));
		if (system(cmd.c_str()) == 0) {
			cout << "\x1b[A";
			cout << "\33[2K";
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-���ε� �Ϸ�-" << endl;
		}
		else {
			cout << "\x1b[A";
			cout << "\33[2K";
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-���ε� ����-" << endl;
			exit(0);
		}
	}
}