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

// Calculate and apply interest
void Savings_Acc::applyInterest() {
    auto now = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - m_last_deposit_time);
    // Need to test this 

    if (duration.count() >= 6) { // Check if 6 months have passed
        double interest = balance * (m_interest_rate / 100.0); // Calculate interest
        balance += interest; // Apply interest
        m_last_deposit_time = now; // Reset the deposit timestamp
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest // setprecision(2) = nr de cifre dupa virgula
            << " applied to the account.\n";
    }
    else {
        std::cout << "Interest can only be applied after 6 months.\n";
    }
}

// Override displayDetails for interest rate
void Savings_Acc::displayDetails() const {
    Account::displayDetails(); // Call base class method
    std::cout << "Interest Rate: " << m_interest_rate << "%\n";
}
