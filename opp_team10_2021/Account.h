#pragma once
#include <string>
#include <vector>
#include <random>
#define LOAN_RATE 1.5
#define SAVE_RATE 1.0
#define DEPOSIT_RATE 0.1

class Account {
protected:
    std::string mAccNum;
    std::string mPerName;
    std::string mBnkName;
    unsigned int mBalance;
    unsigned int mPwd;
    int savingmonth;
public:
    virtual const std::string getAccountType() = 0;
    virtual void deposit(int amount);
    virtual void withdrawal(int amount);
    virtual void dailymonth();
    void printAccount();
    const std::string getAccNum();
    const std::string getPerName();
    const std::string getBnkName();
    const unsigned int getBalance();
    const unsigned int getPwd();
    const int getsavingmonth();
    void genAccNum();
    bool isCorrect(unsigned int inPwd);
    void operator=(const Account& rhs);
};