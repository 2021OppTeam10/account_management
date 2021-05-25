#include <string>
#include <vector>
#include "SavingAccount.h"
#include "DepositAccount.h"

class Person {
	std::vector<SavingAccount> mOwnedSavAcc;
	std::vector<DepositAccount> mOwnedDepAcc;
	std::string mName;
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
	void dailySaveInterest(int mBalance);
	void dailyDepositInterest(int mBalance);
	void dailyLoanInterest(int mBalance);
	template<typename T>
	void save(T account);
	template<typename T>
	void load(T account);
};