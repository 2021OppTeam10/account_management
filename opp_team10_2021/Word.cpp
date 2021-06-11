#include "Word.h"
#include "person.h"

using namespace std;

int Word::findFunc() {
	vector<string> funcList = { "입금", "출금", "송금", "계좌", "새로", "대출" };
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

void Word::showManual()
{
	cout << "1. 신규 고객 등록" << endl;
	cout << "2. 기존 고객 계좌 추가" << endl;
	cout << "3. 기존 고객 계좌 삭제" << endl;
	cout << "4. 계좌 번호로 계좌조회" << endl;
	cout << "5. 대출 받기" << endl;
	cout << "6. 대출 상환" << endl;
	cout << "7. 입금 출금 송금" << endl;
}

void Word::printAllAccount(string PerName, vector<Person> cusList)
{
	vector<DepositAccount> tDep;
	vector<SavingAccount> tSav;
	cout << "이름 : " << PerName;
	for (auto i : cusList) {
		if (PerName == i.getname()) {
			tDep = i.getDepAcc();
			tSav = i.getSavAcc();
			for (int j = 0; j < tDep.size(); j++) {
				cout << "예금계좌 : " << tDep[j].getAccNum() << endl;
			}
			for (int j = 0; j < tSav.size(); j++) {
				cout << "적금계좌 : " << tSav[j].getAccNum() << endl;
			}
		}
		else
			cout << "이름이 존재하지 않습니다." << endl;
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
			throw invalid_argument("존재하지 않는 계좌입니다.");
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
		if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // 입금 송금 출금
		{
			if (name[0] == '1') // 계좌가 대상
			{
				printAllAccount(name, cusList);
				cout << "원하는 계좌번호로 입력하세요.";
			}
			else
			{
				saveWord();
				name.erase(name.begin());
				switFunc(name, funcChoiced, amount);
			}
		}
		else if (funcChoiced == 3) //계좌 -> 삭제 추가
		{
			vector<string> funcList = { "삭제", "추가" };
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
			if (funcChoiced == 0 && name[0] == '0') // 삭제
			{
				name.erase(name.begin());
				try { whois(name, cusList).rmAcc(name); }
				catch (const invalid_argument& e) { cout << e.what() << endl; break; }
			}
			else if (funcChoiced == 1 && name[0] == '1') // 추가 + 이름 입력했으면
			{
				for (auto i : cusList)
				{
					if (i.getname() == name) {
						name.erase(name.begin());
						string tin;
						string tin2;
						unsigned tp;
						bool isEnd = false;
						cout << "정기 적금과 보통 예금 중에서 어떤 것을 추가할까요?" << endl;
						cin >> tin;
						cout << "은행이름을 입력하세요" << endl;
						cin >> tin2;
						cout << "비밀번호를 입력하세요" << endl;
						cin >> tp;
						while (!isEnd)
						{
							cout << "정기 적금과 보통 예금 중에서 어떤 것을 추가할까요?" << endl;
							cin >> tin;
							if (tin.find("예금"))
							{
								DepositAccount tmp(name, tin2, tp);
								i.addDepAcc(tmp);
								isEnd = true;
							}
							else if (tin.find("적금"))
							{
								cout << "출금 대상계좌는 무엇으로 할까요?" << endl;
								cin >> tin;
								SavingAccount tmp(tin, name, tin2, tp);
								i.addSavAcc(tmp);
								isEnd = true;
							}
							else
							{
								cout << "적금과 예금 중에서 입력하세요" << endl;
							}
						}
						break;
					}
				}
			}
			else
			{
				cout << "계좌 삭제를 원하시면 \"(계좌번호)으로된 계좌를 삭제해줘\"를 입력하세요" << endl;
				cout << "계좌 추가를 원하시면 \"(이름)에게 계좌를 추가해줘\"를 입력하세요" << endl;
			}
		}
		else if (funcChoiced == 4) //새로
		{
			name.erase(name.begin());
			cout << "새로운 고객으로 " << name << "님을 추가할까요?" << endl;
			getInput();
			string tmpSS = inputString;
			if (tmpSS == "네")
			{
				Person tmp(name);
				cusList.push_back(tmp);
				cout << "추가 완료." << endl;
			}
			else if (tmpSS == "아니오")
			{
				cout << "작업을 취소합니다." << endl;
			}
			else
			{
				cout << "작업을 취소합니다." << endl;
			}
		}
		else if (funcChoiced == 5) //대출
		{
			vector<string> funcList = { "상환", "추가" };
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
			if (funcChoiced == 0) // 상환
			{
				for (auto i : cusList)
				{
					if (i.getname() == name) {
						string dest;
						int amt;
						cout << "얼마를 갚으실 건가요?" << endl;
						cin >> amt;
						cout << "출금하실 예금 계좌번호를 입력해주세요" << endl;
						cin >> dest;
						i.getLoan().Repayment(i.getDepAcc(dest), amount);
						break;
					}
				}
				
			}
			else if (funcChoiced == 1) // 추가
			{
				cout << "대출추가" << endl;
			}
		}
		else {
			int tmp = 1;
			string tmpS = findUsedSen(inputString);
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
					switFunc(name, funcChoiced, amount);
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
	
}
