#include <string>
#include <vector>
#include <ctime>
#include "person.h"
#include "Word.h"

using namespace std;
void initProgram() { //프로그램 및 데이터 초기화
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
	if (system(upload.c_str()) == 0)
		cout << "-업로드 완료-" << endl;
	else {
		cout << "-다운로드 실패-" << endl;
		exit(0);
	}
	exit(0);
}
vector<Person> mainLoad() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t다운로드 처리중..." << endl;
	string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ . > nul";
	std::locale::global(std::locale("Korean"));
	if (system(download.c_str()) == 0) {
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-다운로드 완료-" << endl;
	}
	else {
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
	//initProgram(); // ***주의*** 이 기능을 실행하면 DB의 파일이 초기화. 실행금지.
	vector<Person> cusList = mainLoad(); // customer list
	for (auto i : cusList)
		i.dailyInterest();
	Word myWord;
	myWord.start(cusList);
	return 0;
}

