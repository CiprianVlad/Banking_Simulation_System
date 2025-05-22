#ifndef BANK_H
#define BANK_H

#include <iostream> 
#include <string>
#include <vector>

class Account; // not good practice 

class Bank {

private:

    std::string m_name;
    std::string m_address;
    std::vector<Account*> m_accounts;

public:

    Bank(const std::string& bankName, const std::string& bankAddress);
    ~Bank();

    void displayBankInfo() const;
    void addAccount(Account* account);
    void removeAccount(Account* account);
    void listAllAccounts() const;

    // Getters
    std::string getName() const;
    std::string getAddress() const;
};

#endif