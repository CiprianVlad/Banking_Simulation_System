#include "account.h"
#include "bank.h"
#include <random>
#include <chrono>

Account::Account(const std::string& holder, double initialBalance) 
    : account_holder(holder), balance(initialBalance) {
    account_number = generateAccountNumber();
}

Account::~Account() {}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << " Deposited $ " << amount << " to account " << account_number << "\n";
    }
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << " Withdrawn $ " << amount << " from account " << account_number << "\n";
        return true;
    }
    else {
        std::cout << " Not enough money in " << account_number;
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

// generate number for acc 
std::string Account::generateAccountNumber() {
    static std::default_random_engine generator(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())); // Didn't find a simpler way 
    std::uniform_int_distribution<int> distribution(100000, 999999); // 6-digit number
    int randomNumber = distribution(generator);
    return "RO" + std::to_string(4147) + std::to_string(randomNumber);
}