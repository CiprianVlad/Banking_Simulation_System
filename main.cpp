// Program execution begins and ends here.

#include "investing_acc.h"
#include "stock.h"
#include "bank.h"
#include "child_acc.h"

int main() {

    Child_Acc child_acc1("Vlad", 1000);
    Bank bank("ING", "Str. Victoriei nr. 22");

    // al 3-lea parametru e index-ul
    // al 4-lea e numarul de stocuri
    Stock stock1("TechCorp", "Technology", 150.0, 1000); 
    Stock stock2("HealthInc", "Healthcare", 200.0, 500);
    Stock stock3("AutoMakers", "Automotive", 120.0, 800);

    // Initialize stocks vector
    std::vector<Stock> SelectedStocks = { stock2, stock3 };

    // Create an investment account
    Invest_acc investAccount("John Doe", 1000.0, SelectedStocks);

    // Display initial details
    investAccount.displayDetails();

    // Apply stock changes over iterations
    for (int i = 1; i <= 6; ++i) {
        Bank::m_months_passed++;
        investAccount.applyStockDifference();
        investAccount.displayDetails();
        if (i % 6 == 0) { // apply interest every 6 months 
            child_acc1.afterInterest(bank);
        }
        std::cout << "\n";
    }
    return 0;
}
