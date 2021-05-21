#pragma once
#define LOAN_RATE 1.5
#define DEPOSIT_RATE 0.1
#include <string>
#include <utility>

class Account {
    std::string mAccNum;
    unsigned int mBalance;
    std::string mPerName;
    std::string mBnkName;
    std::pair<int, int> mLoanInfo;
    unsigned int mPwd;
public:
    Account(std::string accNum, unsigned balance, std::string perName, std::string bnkName, unsigned int pwd);
    Account(std::string perName, std::string mBnkName, unsigned int pwd);
    virtual std::string getAccountType();
    virtual void deposit();
    void printAccount();
    std::string getAccNum();
    unsigned int getBalance();
    std::string getPerName();
    std::string getBnkName();
    std::pair<int, int> getLoanInfo();
};
