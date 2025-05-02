// Program execution begins and ends here.

#include <iostream>
#include "account.h"
#include "bank.h"
#include "transactions.h"

// Main function
int main() {
    // Create accounts
    Account acc1("Ana", 1000.0);  // Account holder "Ana" with $1000
    Account acc2("Vasile", 500.0);     // Account holder "Vasile" with $500

    // Display initial balances
    std::cout << "Initial balances:\n";
    std::cout << "Ana: $" << acc1.getBalance() << "\n";
    std::cout << "Vasile: $" << acc2.getBalance() << "\n\n";

    // Create a transaction (3% fee is standard)
    Transactions transfer(&acc1, &acc2, 200.0);  // fee is set based the type of acc 

    // Execute and check result
    std::cout << "Executing transfer...\n";
    if (transfer.execute()) {
        std::cout << "Transfer succeeded!\n";
    }
    else {
        std::cout << "Transfer failed (insufficient funds or invalid accounts).\n";
    }

    // Display final balances
    std::cout << "\nFinal balances:\n";
    acc1.displayDetails();
    // std::cout << "Vasile: $" << acc2.getBalance() << "\n";

    return 0;
}