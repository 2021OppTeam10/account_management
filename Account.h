#pragma once
#include <string>
#include <utility>

class account {
    unsigned int mAccNum;
    unsigned int mBalance;
    std::string mPerName;
    std::string mBnkName;
    std::pair<int, int> mLoanInfo;
    int mPwd;
public:
    virtual int getAccountType();
    virtual void deposit();
    void transfer();
    void printAccount();
    unsigned int getAccNUM();
    unsigned int getBalance();
    std::string getPerNAme();
    std::string getBnkName();
    std::pair<int, int> getLoanInfo();
};