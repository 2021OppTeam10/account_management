/*
* TODO
* 1. & 추가
* 3. 파일입출력 try-catch
* 비밀번호 치면 바로 * 변환

*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <ctime>

#include "Word.h"
#include "person.h"

using namespace std;

vector<Person> mainLoad() {
	cout << "-----------------------------< DOWNLOAD FILE >----------------------------" << endl;
	string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ .";
	string cmd = "start /wait /min " + download;
	std::locale::global(std::locale("Korean"));
	if (system(download.c_str()) == 0)
		cout << " " << "file" << "\t\t\t\t\t\t     -다운로드 완료-" << endl;
	else
		cout << " " << "file" << "\t\t\t\t\t\t     -다운로드 실패-" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
	vector<Person> result;
	string name;
	string num;
	int count = 0;
	ifstream is(".\\customer\\" + to_string(count) + "\\" + to_string(count));
	if (!is.is_open())
		return result;
	do
	{
		getline(is, num);
		getline(is, name);
		Person tmp(name, num);
		tmp.loadPer(count, num);
		is.close();
		result.push_back(tmp);
		count++;
		ifstream is(".\\customer\\" + to_string(count) + "\\" + to_string(count));
	} while (is.is_open());
	return result;
}

int main() {
	vector<Person> cusList = mainLoad(); // customer list
	//Person tmp("배재익");
	//Person tmp2("홍석원");
	//Person tmp3("나선혁");
	//DepositAccount ttmp("배재익", "우리은행", 1234);
	//DepositAccount ttmp2("홍석원", "우리은행", 2345);
	//DepositAccount ttmp3("나선혁", "우리은행", 3456);
	//tmp.addDepAcc(ttmp);
	//tmp2.addDepAcc(ttmp2);
	//tmp3.addDepAcc(ttmp3);
	//cusList.push_back(tmp);
	//cusList.push_back(tmp2);
	//cusList.push_back(tmp3);
	
	for (int i = 0; i < cusList.size(); i++)
	{
		cusList[i].savePer(i);
	}
	for (auto i : cusList)
		i.dailyInterest();
	Word myWord;
	myWord.start(cusList);
	return 0;
}