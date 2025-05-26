#ifndef BANK_H
#define BANK_H

#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

class Account; // not good practice 

class Bank {

private:

    std::string m_name;
    std::string m_address;
    std::vector<Account*> m_accounts;

public:
    static int m_months_passed;

    Bank(const std::string& bankName, const std::string& bankAddress);
    ~Bank();

    void displayBankInfo() const;
    void addAccount(Account* account);
    void removeAccount(Account* account);
    void listAllAccounts() const;
    double applyInterest(Account& account, double rate, int months = m_months_passed); // months_passed updates in main 

    // Getters
    std::string getName() const;
    std::string getAddress() const;
};

#endif