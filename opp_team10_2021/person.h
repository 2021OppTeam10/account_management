#include <string>
#include <vector>
#include "SavingAccount.h"
#include "DepositAccount.h"
#include "LoanAccount.h"

class Person {
	std::vector<SavingAccount> mOwnedSavAcc;
	std::vector<DepositAccount> mOwnedDepAcc;
	std::string mName;
	std::string mPerNum;
	LoanAccount loan;
	template<typename T>
	void saveAcc(T account);
	template<typename T>
	void loadAcc(T account);
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
	void savePer();
	void loadPer();
};