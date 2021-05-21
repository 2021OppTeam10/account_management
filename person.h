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
	virtual void rmAcc(string accNum);
	Account getAcc(string accNum);
	virtual void save();
	virtual void load();
};