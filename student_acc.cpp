#include "student_acc.h"
#include <iostream>
#include <chrono>
#include <iomanip>

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

// Calculate and apply interest
void Student_Acc::applyInterest() {
    auto now = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - last_deposit_time);

    if (duration.count() >= 6) { // Check if 6 months have passed
        double interest = balance * (m_interest_rate / 100.0); // Calculate interest
        balance += interest; // Apply interest
        last_deposit_time = now; // Reset the deposit timestamp
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest
            << " applied to the account.\n";
    }
    else {
        std::cout << "Interest can only be applied after x months.\n";
    }
}

// Override displayDetails for interest rate
void Student_Acc::displayDetails() const {
    Account::displayDetails(); // Call base class method
    std::cout << "Interest Rate for an adult account: " << m_interest_rate << "%\n";
}
