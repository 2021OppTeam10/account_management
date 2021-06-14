#include <string>
#include <vector>
#include <ctime>
#include "person.h"
#include "Word.h"

using namespace std;

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

	vector<Person> cusList = mainLoad(); // customer list
	for (auto i : cusList)
		i.dailyInterest();
	Word myWord;
	myWord.start(cusList);
	return 0;
}

