#include "Word.h"

using namespace std;

vector<Person> wordLoad() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t다운로드 처리중..." << endl;
	string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ .";
	string cmd = "start /wait /min " + download;
	std::locale::global(std::locale("Korean"));
	if (system(cmd.c_str()) == 0) {
		cout << "\x1b[A";
		cout << "\33[2K";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-다운로드 완료-" << endl;
	}
	else {
		cout << "\x1b[A";
		cout << "\33[2K";
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

bool Word::getInput()
{
	system("timeout 1 > nul");
	cout << "명령어 입력 > ";
	getline(cin, inputString);
	if (inputString == "종료")
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
		size_t nPos = i.find("원 ");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			mAmount = stoi(i.substr(0, nPos));
		}
		 nPos = i.find("번호");
		if (nPos != string::npos && nPos != 0 && nPos != -1)
		{
			result = '0';
			result += i.substr(0, nPos);
		}
		if (result == "")
		{
			nPos = i.find("에게");
			if (nPos != string::npos && nPos != 0 && nPos != -1)
			{
				result = '1';
				result += i.substr(0, nPos);
			}
			nPos = i.find("을");
			if (nPos != string::npos && nPos != 0 && nPos != -1)
			{
				result = '1';
				result += i.substr(0, nPos);
			}
			nPos = i.find("를");
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
				cout << "계좌 비밀번호를 입력해주세요" << endl;
				cin >> tp;
				cin.ignore();
				if (cusList[i].getDepAcc()[j].isCorrect(tp))
				{
					switch (funcChoiced)
					{
					case 0:
						cusList[i].getDepAcc()[j].deposit(amount);
						cout << accNum << "에게 " << amount << "원 입금처리" << endl;
						break;
					case 1:
						if (cusList[i].getDepAcc()[j].withdrawal(amount))
						{
							cout << accNum << "에게 " << amount << "원 출금처리" << endl;
							break;
						}
						else
						{
							break;
						}
					case 2:
						DepositAccount tD("NULL", "NULL", 0);
						string source;
						cout << "돈을 출금해서 보내실 계좌를 입력하세요" << endl;
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
								cout << accNum << "에게 " << amount << "원 출금처리" << endl;
								cusList[i].getDepAcc()[j].deposit(amount);
								cout << accNum << "에게 " << amount << "원 송금처리" << endl;
								break;
							}
							else
							{
								break;
							}
						}
						else {
							cout << "대상 계좌가 올바르지 않습니다." << endl;
							break;
						}
					}
				}
				else
				{
					cout << "비밀번호 입력 오류" << endl;
					break;
				}
				break;
			}
			for (auto j : cusList[i].getSavAcc())
			{
				if (j.getAccNum() == accNum)
				{
					cout << "적금 계좌는 직접 입급, 출금, 송금이 불가능합니다." << endl;
					break;
				}
			}
		}
	}
}

void Word::showManual()
{
	cout << "가능한 명령어의 기본 형태는 다음과 같습니다." << endl;
	cout << "\t1. 입출금" << endl;
	cout << "\t\t1. 입금 : (계좌번호)번호로 (금액)원 입금해줘" << endl;
	cout << "\t\t2. 출금 : (계좌번호)번호로 (금액)원 출금해줘" << endl;
	cout << "\t\t3. 송금 : (계좌번호)번호로 (금액)원 송금해줘" << endl;
	cout << "\t2. 계좌관련" << endl;
	cout << "\t\t1. 추가 : (이름)에게 계좌를 추가해줘" << endl;
	cout << "\t\t2. 삭제 : (이름)에게 계좌를 삭제해줘" << endl;
	cout << "\t\t3. 조회 : (이름)을/를 계좌 조회해줘" << endl;
	cout << "\t3. 고객관련" << endl;
	cout << "\t\t1. 신규 고객 등록 : (이름)을/를 새로 등록해줘" << endl;
	cout << "\t4. 대출관련" << endl;
	cout << "\t\t1. 상환 : (이름)에게 대출 상환" << endl;
	cout << "\t\t2. 추가 대출 : (이름)에게 추가 대출" << endl;
}

void Word::printAllAccount(string PerName, vector<Person>& cusList)
{
	vector<DepositAccount> tDep;
	vector<SavingAccount> tSav;
	int result1 = 0;
	int result2 = 0;
	cout << "-------------계좌 조회-------------" << endl;
	cout << "조회하신 고객의 이름 : " << PerName << endl;
	for (auto i : cusList) {
		if (PerName == i.getname()) {
			tDep = i.getDepAcc();
			tSav = i.getSavAcc();
			for (int j = 0; j < tDep.size(); j++) {
				tDep[j].printAccount();
				result1++;
			}
			cout << "총 보유 예금 계좌수는 " << result1 << "개 입니다." << endl;
			for (int j = 0; j < tSav.size(); j++) {
				tDep[j].printAccount();
				result2++;
			}
			cout << "총 보유 적금 계좌수는 " << result2 << "개 입니다." << endl;
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

void Word::mainWork(std::vector<Person>& cusList) {
	string name = getName();
	int amount = mAmount;
	int funcChoiced = findFunc();
	if (amount != 1 && (0 <= funcChoiced && funcChoiced <= 2)) // 입금 송금 출금
	{
		if (name[0] == '1') // 이름이 대상
		{
			printAllAccount(name, cusList);
			cout << "원하는 계좌번호로 입력하세요." << endl;
		}
		else
		{
			name.erase(name.begin());
			saveWord();
			switFunc(name, funcChoiced, amount, cusList);
		}
	}
	else if (funcChoiced == 3) //계좌 -> 삭제 추가
	{
		vector<string> funcList = { "삭제", "추가", "조회" };
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
		if (funcChoiced == 0 && name[0] == '0') // 삭제
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
		else if (funcChoiced == 1 && name[0] == '1') // 추가 + 이름 입력했으면
		{
			name.erase(name.begin());
			for (int i = 0; i < cusList.size(); i++)
			{
				if (cusList[i].getname() == name) {
					string tin;
					string tin2;
					unsigned tp;
					bool isEnd = false;
					cout << "정기 적금과 보통 예금 중에서 어떤 것을 추가할까요?" << endl << "적금 / 예금 > ";
					cin >> tin;
					cin.ignore();
					cout << "은행이름을 입력하세요" << endl << "입력 > ";
					cin >> tin2;
					cin.ignore();
					cout << "비밀번호를 입력하세요" << endl << "입력 > ";
					cin >> tp;
					cin.ignore();
					while (!isEnd)
					{
						if (tin.find("예금") != string::npos)
						{
							DepositAccount tmp(name, tin2, tp);
							cusList[i].addDepAcc(tmp);
							isEnd = true;
							cout << "예금 계좌가 추가되었습니다!" << endl;
							printAllAccount(name, cusList);
							saveWord();
						}
						else if (tin.find("적금") != string::npos)
						{
							cout << "출금 대상계좌는 무엇으로 할까요?" << endl;
							printAllAccount(name, cusList);
							cin >> tin;
							cin.ignore();
							SavingAccount tmp(tin, name, tin2, tp);
							cusList[i].addSavAcc(tmp);
							isEnd = true;
							cout << "적금 계좌가 추가되었습니다!" << endl;
							printAllAccount(name, cusList);
							saveWord();
						}
						else
						{
							cout << "적금과 예금 중에서 입력하세요" << endl;
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
					cout << "입력오류" << endl;
					cout << "수행할 수 있는 주요 기능은 다음과 같습니다" << endl;
					showManual();
					return;
				}
				cout << tmpS << "를 실행할까요?" << endl;
				string tmpSS;
				cout << "네 / 아니오 > ";
				getline(cin, tmpSS);
				if (tmpSS == "네")
				{
					setTokenedString(tmpS);
					mainWork(cusList);
					return;
				}
				else if (tmpSS == "아니오")
				{
					cout << "작업을 취소합니다." << endl;
					return;
				}
				else
				{
					cout << "입력오류" << endl;
					showManual();
					return;
				}
			}
		}
	}
	else if (funcChoiced == 4) //새로
	{
		name.erase(name.begin());
		for (auto i : cusList)
		{
			if (i.getname() == name) {
				cout << "이미 존재하는 고객입니다." << endl;
				return;
			}
		}
		cout << "새로운 고객으로 " << name << "님을 추가할까요?" << endl;
		getInput();
		string tmpSS = inputString;
		if (tmpSS == "네")
		{
			saveWord();
			Person tmp(name);
			cusList.push_back(tmp);
			cout << "추가 완료." << endl;
		}
		else
		{
			cout << "작업을 취소합니다." << endl;
			return;
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
			name.erase(name.begin());
			for (auto i : cusList)
			{
				if (i.getname() == name) {
					string dest;
					int amt;
					unsigned tp;
					cout << "얼마를 갚으실 건가요?" << endl;
					cin >> amt;
					cin.ignore();
					cout << "출금하실 예금 계좌번호를 입력해주세요" << endl;
					cin >> dest;
					cin.ignore();
					cout << "출금하실 예금 비밀번호를 입력해주세요" << endl;
					cin >> tp;
					cin.ignore();
					if (i.getLoan().isCorrect(tp)) {
						i.getLoan().Repayment(i.getDepAcc(dest), amount);
						saveWord();
					}
					else
					{
						cout << "비밀번호 입력 오류" << endl;
						return;
					}
					return;
				}
			}
		}
		else if (funcChoiced == 1) // 추가
		{
			name.erase(name.begin());
			for (auto i : cusList)
			{
				if (i.getname() == name) {
					int amt;
					cout << "얼마를 빌리실 건가요?" << endl;
					cin >> amt;
					cin.ignore();

					string tin2;
					unsigned tp;
					cout << "은행이름을 입력하세요" << endl;
					cin >> tin2;
					cin.ignore();
					cout << "비밀번호를 입력하세요" << endl;
					cin >> tp;
					if (i.getLoan().isCorrect(tp)) {
						saveWord();
						i.getLoan().addLoan(name, tin2, amt);
						cout << amt << "원 대출 처리 완료" << endl;
						i.getLoan().printAccount();
						return;
					}
					else
					{
						cout << "비밀번호 입력 오류" << endl;
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
					cout << "입력오류" << endl;
					cout << "수행할 수 있는 주요 기능은 다음과 같습니다" << endl;
					showManual();
					return;
				}
				cout << tmpS << "를 실행할까요?" << endl;
				string tmpSS;
				cout << "네 / 아니오 > ";
				getline(cin, tmpSS);
				if (tmpSS == "네")
				{
					setTokenedString(tmpS);
					mainWork(cusList);
					return;
				}
				else if (tmpSS == "아니오")
				{
					cout << "작업을 취소합니다." << endl;
					return;
				}
				else
				{
					cout << "입력오류" << endl;
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
				cout << "입력오류" << endl;
				cout << "수행할 수 있는 주요 기능은 다음과 같습니다" << endl;
				showManual();
				return;
			}
			cout << tmpS << "를 실행할까요?" << endl;
			string tmpSS;
			cout << "네 / 아니오 > ";
			getline(cin, tmpSS);
			if (tmpSS == "네")
			{
				setTokenedString(tmpS);
				mainWork(cusList);
				return;
			}
			else if (tmpSS == "아니오")
			{
				cout << "작업을 취소합니다." << endl;
				return;
			}
			else
			{
				cout << "입력오류" << endl;
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
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t업로드 처리중..." << endl;
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
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-업로드 완료-" << endl;
		}
		else {
			cout << "\x1b[A";
			cout << "\33[2K";
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-업로드 실패-" << endl;
			exit(0);
		}
	}
}