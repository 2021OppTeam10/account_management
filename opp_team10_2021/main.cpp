#include <string>
#include <vector>
#include <ctime>
#include "person.h"
#include "Word.h"
// �����׽�Ʈ
// ��ȣȭ��ġ��
// ������
// ó�� �ȳ�â, ��ɾ� ���� �ۼ�
using namespace std;

vector<Person> mainLoad() {
	string download = "scp -C -o ServerAliveInterval=2 -o ServerAliveCountMax=3 -r -o StrictHostKeyChecking=no -i ./id_rsa -P 8080 cppproj@1.225.217.57:/home/cppproj/customer/ .";
	string cmd = "start /wait /min " + download;
	std::locale::global(std::locale("Korean"));
	if (system(cmd.c_str()) == 0)
		cout << "-�ٿ�ε� �Ϸ�-" << endl;
	else
		cout << "-�ٿ�ε� ����-" << endl;
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
	//Person tmp("������");
	//Person tmp2("ȫ����");
	//Person tmp3("������");
	//DepositAccount ttmp("������", "�츮����", 1234);
	//DepositAccount ttmp2("ȫ����", "�츮����", 2345);
	//DepositAccount ttmp3("������", "�츮����", 3456);
	//tmp.addDepAcc(ttmp);
	//tmp2.addDepAcc(ttmp2);
	//tmp3.addDepAcc(ttmp3);
	//cusList.push_back(tmp);
	//cusList.push_back(tmp2);
	//cusList.push_back(tmp3);
	for (auto i : cusList)
		i.dailyInterest();
	Word myWord;
	myWord.start(cusList);
	return 0;
}