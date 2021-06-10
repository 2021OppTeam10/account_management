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
	Person(std::string name, std::string num);
	const std::string getname();
	virtual void addSavAcc(SavingAccount newACC);
	virtual void addDepAcc(DepositAccount newACC);
	virtual void rmAcc(std::string accNum);
	SavingAccount& getSavAcc(std::string accNum);
	DepositAccount& getDepAcc(std::string accNum);
	void setDate();
	const bool getDate();
	void dailyInterest() {
		if (getDate()) {
			for (auto i : mOwnedSavAcc) {
				if (i.getsavingmonth() <= 0) {
					rmAcc(i.getAccNum());
					break;
				}
				int tAmount = (SAVE_RATE / 100) * i.getBalance();
				getDepAcc(i.getSourceAcc()).withdrawal(tAmount);
				i.deposit(tAmount);									//적금
			}
			for (auto i : mOwnedDepAcc) {
				i.deposit((DEPOSIT_RATE / 100) * i.getBalance());	//예금
			}
			loan.deposit((LOAN_RATE / 100) * loan.getBalance());//대출
		}
	}
	void savePer(int perOrder);
	void loadPer(int perOrder, std::string perNum);
	void saveAcc(DepositAccount account, int perOrder, int accOrder);
	void saveAcc(SavingAccount account, int perOrder, int accOrder);
	bool loadAcc(int perOrder, int accOrder);
};