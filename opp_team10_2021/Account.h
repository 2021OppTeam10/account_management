#pragma once
#include <string>
#include <utility>

class Account {
    unsigned int mAccNum;
    unsigned int mBalance;
    std::string mPerName;
    std::string mBnkName;
    std::pair<int, int> mLoanInfo;
    int mPwd;
public:
    virtual std::string getAccountType();
    virtual void deposit();
    void printAccount();
    unsigned int getAccNUM();
    unsigned int getBalance();
    std::string getPerNAme();
    std::string getBnkName();
    std::pair<int, int> getLoanInfo();
};