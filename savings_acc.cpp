#include "savings_acc.h"
#include <iomanip>

// Constructor
Savings_Acc::Savings_Acc(const std::string& holder, double initialBalance, double rate)
    : Account(holder, initialBalance), m_interest_rate(rate) {
    m_last_deposit_time = std::chrono::system_clock::now(); // Initialize the deposit timestamp
}

// Destructor
Savings_Acc::~Savings_Acc() {
}

// Override deposit to update the timestamp
void Savings_Acc::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        m_last_deposit_time = std::chrono::system_clock::now(); // Update the deposit timestamp
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
}

void Savings_Acc::afterInterest(Bank& bank) {
    if (Bank::m_months_passed >= 6 && Bank::m_months_passed % 6 == 0) {
        double interest = bank.applyInterest(*this, Savings_Acc::m_interest_rate);
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest
            << " applied to the account with the name: " << getAccHolder() << "\n";
    }
    else {
        std::cout << (6 - (Bank::m_months_passed % 6)) << " month(s) must pass to apply the interest";
    }
}

// Override displayDetails for interest rate
void Savings_Acc::displayDetails() const {
    Account::displayDetails(); // Call base class method
    std::cout << "Interest Rate: " << m_interest_rate << "%\n";
}
