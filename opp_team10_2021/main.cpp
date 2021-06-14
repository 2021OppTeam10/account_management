#include <string>
#include <vector>
#include <ctime>
#include "person.h"
#include "Word.h"

using namespace std;

void initProgram() {
	vector<Person> cusList;
	Person tmp("배재익");
	Person tmp2("홍석원");
	Person tmp3("나선혁");
	DepositAccount ttmp("배재익", "우리은행", 1234);
	DepositAccount ttmp2("홍석원", "우리은행", 2345);
	DepositAccount ttmp3("나선혁", "우리은행", 3456);
	tmp.addDepAcc(ttmp);
	tmp2.addDepAcc(ttmp2);
	tmp3.addDepAcc(ttmp3);
	cusList.push_back(tmp);
	cusList.push_back(tmp2);
	cusList.push_back(tmp3);
	int s = 0;
	for (auto i : cusList)
		i.savePer(s++);
	string upload = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i .\\id_rsa -P 8080 .\\customer\\ cppproj@1.225.217.57:/home/cppproj/";
	string cmd = "start /min /wait " + upload;
	std::locale::global(std::locale("Korean"));
	if (system(cmd.c_str()) == 0)
		cout << "-업로드 완료-" << endl;
	else {
		cout << "-다운로드 실패-" << endl;
		exit(0);
	}
	exit(0);
}

vector<Person> mainLoad() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t다운로드 처리중..." << endl;
	system("rmdir /S /Q customer 2>nul");
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

int main() {

	//initProgram();
	vector<Person> cusList = mainLoad(); // customer list
	for (auto i : cusList)
		i.dailyInterest();
	Word myWord;
	myWord.start(cusList);
	return 0;
}

