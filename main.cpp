// Program execution begins and ends here.

#include <iostream>
#include "account.h"
#include "bank.h"
#include "transactions.h"
#include "investing_acc.h"

int main() {
    // Initialize stocks
    std::vector<Stock> initialStocks = {
        {"TechCorp", 150.0},
        {"HealthInc", 200.0},
        {"AutoMakers", 120.0}
    };

    // Create an investment account
    Invest_acc investAccount("John Doe", 1000.0, initialStocks);

    // Display initial details
    investAccount.displayDetails();

    // Apply stock changes over iterations (1 iteration could be considered 1 month) 
    for (int i = 0; i < 5; ++i) {
        investAccount.applyStockDifference();
        investAccount.displayDetails();
    }

    return 0;
}
