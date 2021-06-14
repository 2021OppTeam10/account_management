#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "SavingAccount.h"
#include "DepositAccount.h"
#include "LoanAccount.h"
#include "Account.h"

class Person {
	std::vector<SavingAccount> mOwnedSavAcc;
	std::vector<DepositAccount> mOwnedDepAcc;
	std::string mName;
	std::string mPerNum;
	LoanAccount loan;
	void genPerNum();
public:
	Person(std::string name);
	Person(std::string name, std::string num);
	const std::string getname();
	virtual void addSavAcc(SavingAccount newACC);
	virtual void addDepAcc(DepositAccount newACC);
	virtual void rmAcc(std::string accNum);
	SavingAccount& getSavAcc(std::string accNum);
	DepositAccount& getDepAcc(std::string accNum);
	void setDate();
	const bool getDate();
	std::vector<SavingAccount>& getSavAcc();
	std::vector<DepositAccount>& getDepAcc();
	LoanAccount& getLoan();
	void dailyInterest();
	void savePer(int perOrder);
	void loadPer(int perOrder, std::string perNum);
	void saveAcc(DepositAccount& account, int perOrder, int accOrder);
	void saveAcc(SavingAccount& account, int perOrder, int accOrder);
	bool loadAcc(int perOrder, int accOrder);
	std::string Encry(unsigned int Pwd);
	unsigned int Decry(std::string encrypt);
};
