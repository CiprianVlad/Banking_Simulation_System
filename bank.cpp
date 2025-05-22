#include <algorithm>
#include "bank.h"
#include "account.h"

Bank::Bank(const std::string& bankName, const std::string& bankAddress)
    : m_name(bankName), m_address(bankAddress) {
}

Bank::~Bank() {
    for (Account* account : m_accounts) { // Looping through m_accounts 
        delete account;
    }
}

void Bank::addAccount(Account* account) {
    if (account == nullptr) {
        std::cout << "Cannot create a NULL account pointer" << "\n";
    }
    else {
        for (Account* acc : m_accounts) { // Verific daca exista contul 
            if (acc->getAccNumber() == account->getAccNumber()) {
                std::cout << "Account " << account->getAccNumber() << " already exists\n";
                return;
            }
        }
        m_accounts.push_back(account);
    }
}

void Bank::removeAccount(Account* account) {
    auto it = Bank::m_accounts.begin();
    while (it != m_accounts.end()) {
        if ((*it)->getAccNumber() == account->getAccNumber()) {
            it = m_accounts.erase(it);
            delete* it; 
            return;
        }
        else {
            ++it;
        }
    }
}

void Bank::displayBankInfo() const {
    std::cout << "Name:" << m_name << "\n"
        << "Address:" << m_address << "\n";
}

void Bank::listAllAccounts() const {
    for (Account* account : m_accounts) {
        std::cout << "Holder:" << account->getAccHolder() << "\n"
            << "Account Number:" << account->getAccNumber() << "\n"
            << "Balance $:" << account->getBalance() << "\n";
    }
}

// Getters 
std::string Bank::getName() const {
    return m_name;
}

std::string Bank::getAddress() const {
    return m_address;
}