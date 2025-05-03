#include "adult_acc.h"
#include <iostream>
#include <chrono>
#include <iomanip>

// Constructor
Adult_Acc::Adult_Acc(const std::string& holder, double initialBalance, double rate)
    : Account(holder, initialBalance), m_interest_rate(rate) {
    m_last_deposit_time = std::chrono::system_clock::now(); // Initialize the deposit timestamp
}

// Destructor
Adult_Acc::~Adult_Acc() {
    // Destructor
    // No cleanup needed for now
}

// Override deposit to update the timestamp
void Adult_Acc::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        m_last_deposit_time = std::chrono::system_clock::now(); // Update the deposit timestamp
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
}

// Calculate and apply interest
void Adult_Acc::applyInterest() {
    auto now = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - m_last_deposit_time);

    if (duration.count() >= 6) { // Check if 6 months have passed
        double interest = balance * (m_interest_rate / 100.0); // Calculate interest
        balance += interest; // Apply interest
        m_last_deposit_time = now; // Reset the deposit timestamp
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest
            << " applied to the account.\n";
    }
    else {
        std::cout << "Interest can only be applied after x months.\n";
    }
}

// Override displayDetails
void Adult_Acc::displayDetails() const {
    Account::displayDetails(); // Base class method
    std::cout << "Interest Rate for an adult account: " << m_interest_rate << "%\n";
}
