#include <string>
#include <vector>
#include "SavingAccount.h"
#include "DepositAccount.h"
#include "LoanAccount.h"

class Person {
	std::vector<SavingAccount> mOwnedSavAcc;
	std::vector<DepositAccount> mOwnedDepAcc;
	std::string mName;
	LoanAccount loan;
public:
	Person(std::string name);
	std:: string getname();
	virtual void addSavAcc(SavingAccount newACC);
	virtual void addDepAcc(DepositAccount newACC);
	virtual void rmAcc(std::string accNum);
	SavingAccount& getSavAcc(std::string accNum);
	DepositAccount& getDepAcc(std::string accNum);
	void setDate();
	bool getDate();
	void dailyInterest();
	template<typename T>
	void save(T account);
	template<typename T>
	void load(T account);
};