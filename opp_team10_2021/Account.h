#pragma once
#define LOAN_RATE 1.5
#define DEPOSIT_RATE 0.1
#include <string>
#include <vector>
#include <utility>

class Account {
protected:
    std::string mAccNum;
    unsigned int mBalance;
    std::string mPerName;
    std::string mBnkName;
    std::pair<int, int> mLoanInfo;
    unsigned int mPwd;
public:
    virtual std::string getAccountType() = 0;
    virtual void deposit(int amount);
    virtual void withdrawal(int amount);
    void printAccount();
    std::string getAccNum();
    unsigned int getBalance();
    std::string getPerName();
    std::string getBnkName();
    unsigned int getPwd();
    std::pair<int, int> getLoanInfo();
};
