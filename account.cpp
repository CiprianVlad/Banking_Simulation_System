#include <iostream> 
#include <ctime>
#include <random>
#include "account.h"

int Account::accountCount = 0;

Account::Account(const std::string& holder, double initialBalance) // Ai grija sa fie acceeasi parametrii 
    : account_holder(holder), balance(initialBalance) {
    account_number = generateAccountNumber();
    accountCount++;
}

Account::~Account() {
    /*
    * Not sure if this is right yet, needs some testing
    accountCount--;
    std::cout << "Account " << account_number << " closed.\n";
    */
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << " Deposited $" << amount << " to account " << account_number << "\n";
    }
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << " Withdrawn $" << amount << " from account " << account_number << "\n";
        return true;
    }
    else {
        std::cout << "Not enough money in" << account_number;
        return false;
    }
}

void Account::displayDetails() const {
    std::cout << "Account Holder: " << account_holder << "\n"
        << "Account number: " << account_number << "\n"
        << "Balance: " << balance << "\n";

}

// Getters 
std::string Account::getAccNumber() const {
    return account_number;
}

std::string Account::getAccHolder() const {
    return account_holder;
}

double Account::getBalance() const {
    return balance;
}

int Account::getAccountCount() {
    return accountCount;
}


// generate number for acc 
std::string Account::generateAccountNumber() {
    std::mt19937 rng(static_cast<unsigned int>(time(0))); // Seed the random number generator  
    std::uniform_int_distribution<int> dist(100000, 999999); // range for the random number 
    return "RO" + std::to_string(4147) + std::to_string(dist(rng)); // generate acc_number  
}