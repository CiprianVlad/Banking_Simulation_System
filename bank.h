#ifndef BANK_H
#define BANK_H

#include "stock.h"
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <random>

class Account; // not good practice 

class Bank {

private:
    std::string m_name;
    std::string m_address;
    std::vector<Account*> m_accounts;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution; // the distribution of the random changes 
public:
    static int m_months_passed;

    Bank(const std::string& bankName, const std::string& bankAddress);
    ~Bank();

    void displayBankInfo() const;
    void addAccount(Account* account);
    void removeAccount(Account* account);
    void listAllAccounts() const;

    double applyInterest(Account& account, double rate, int months = m_months_passed); // months_passed updates in main 
    double applyStockDifference(Stock& stock);

    // Getters
    std::string getName() const;
    std::string getAddress() const;
};

#endif