#pragma once
#include <string>
#include <vector>
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
	std::string getname();
	virtual void addSavAcc(SavingAccount newACC);
	virtual void addDepAcc(DepositAccount newACC);
	virtual void rmAcc(std::string accNum);
	SavingAccount& getSavAcc(std::string accNum);
	DepositAccount& getDepAcc(std::string accNum);
	void setDate();
	bool getDate();
	void dailyInterest();
	void savePer(int perOrder);
	void loadPer(int perOrder);
	void saveAcc(DepositAccount account, int perOrder, int accOrder);
	void saveAcc(SavingAccount account, int perOrder, int accOrder);
	void loadAcc(int perOrder, int accOrder);
};