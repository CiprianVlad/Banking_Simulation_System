#include "bank.h"
#include "account.h"
#include "stock.h"

Bank::Bank(const std::string& bankName, const std::string& bankAddress)
    : m_name(bankName), m_address(bankAddress), distribution(-0.2, 0.2){
}

Bank::~Bank() {
    for (Account* account : m_accounts) { 
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

int Bank::m_months_passed = 0; 

double Bank::applyInterest(Account& account, double rate, int months) {

    if (months % 6 == 0 && months > 5) {
        double interest = account.getBalance() * (rate / 100.0);
        account.deposit(interest);
        std::cout << "Interest applied\n";
        return interest;
    } else {
        std::cout << "Interest denied. Wait for the 6th or 12th month of the year.\n";
        return 0; 
    }
}

// Randomize stock indices and update balance 
double Bank::applyStockDifference(Stock& stock){
    // Randomly change the stock index 
    double change = stock.getCurrentIndex() * distribution(generator);
    stock.updateIndex(stock.getCurrentIndex() + change);

    std::cout << "Stock " << stock.getName() << " index updated by " << change
        << ". New index: " << stock.getCurrentIndex() << "\n";
    return change;
}

// Getters 
std::string Bank::getName() const {
    return m_name;
}

std::string Bank::getAddress() const {
    return m_address;
}