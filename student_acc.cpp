#include "student_acc.h"

// Constructor
Student_Acc::Student_Acc(const std::string& holder, double initialBalance, double rate)
    : Account(holder, initialBalance), m_interest_rate(rate) {
    last_deposit_time = std::chrono::system_clock::now(); // Initialize the deposit timestamp
}

// Destructor
Student_Acc::~Student_Acc() {
    // Destructor
    // No cleanup needed for now
}

// Override deposit to update the timestamp
void Student_Acc::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        last_deposit_time = std::chrono::system_clock::now(); // Update the deposit timestamp
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
}

void Student_Acc::afterInterest(Bank& bank) {
    if (Bank::m_months_passed >= 6 && Bank::m_months_passed % 6 == 0) {
        double interest = bank.applyInterest(*this, Student_Acc::m_interest_rate);
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest
            << " applied to the account with the name: " << getAccHolder() << "\n";
    }
    else {
        std::cout << (6 - (Bank::m_months_passed % 6)) << " month(s) must pass to apply the interest";
    }
}

// Override displayDetails for interest rate
void Student_Acc::displayDetails() const {
    Account::displayDetails(); // Call base class method
    std::cout << "Interest Rate for an adult account: " << m_interest_rate << "%\n";
}