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

// Calculate and apply interest
void Child_Acc::applyInterest() {
    auto now = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - m_last_deposit_time);
    // Need to test this 

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

// Override displayDetails for interest rate
void Child_Acc::displayDetails() const {
    Account::displayDetails(); // Call base class method
    std::cout << "Interest Rate for an adult account: " << m_interest_rate << "%\n";
}