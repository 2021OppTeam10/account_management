#pragma once
#define LOAN_RATE 1.5
#define DEPOSIT_RATE 0.1
#include <string>
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
    virtual std::string getAccountType();
    virtual void deposit(); // 입금
    virtual void transfer(); // 이체
    virtual void withdrawal(int amount); // 출금
    void printAccount();
    std::string getAccNum();
    unsigned int getBalance();
    std::string getPerName();
    std::string getBnkName();
    std::pair<int, int> getLoanInfo();
};
