#include "child_acc.h"

// Constructor
Child_Acc::Child_Acc(const std::string& holder, double initialBalance, double rate)
    : Account(holder, initialBalance), m_interest_rate(rate) {
    m_last_deposit_time = std::chrono::system_clock::now(); // Initialize timestamp
}

// Destructor
Child_Acc::~Child_Acc() {
    // Destructor
}

// Override deposit to update the timestamp
void Child_Acc::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        m_last_deposit_time = std::chrono::system_clock::now(); // Update timestamp
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
}

// Apply interest & 
void Child_Acc::afterInterest(Bank& bank) {
    if (Bank::m_months_passed >= 6 && Bank::m_months_passed % 6 == 0) {
        double interest = bank.applyInterest(*this, Child_Acc::m_interest_rate);
        Account::balance += interest; // Apply interest
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest
            << " applied to the account with the name: " << getAccHolder() << "\n";
    }
    else {
        std::cout << (6 - (Bank::m_months_passed % 6)) << " month(s) must pass to apply the interest";
    }
}

// Override displayDetails for interest rate
void Child_Acc::displayDetails() const {
    Account::displayDetails(); // Call base class method
    std::cout << "Interest Rate for an adult account: " << m_interest_rate << "%\n";
}