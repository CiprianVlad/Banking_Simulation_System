// Program execution begins and ends here.

#include "investing_acc.h"
#include "stock.h"

int main() {
    // al 3-lea parametru e index-ul
    // al 4-lea e numarul de stocuri
    Stock stock1("TechCorp", "Technology", 150.0, 1000); 
    Stock stock2("HealthInc", "Healthcare", 200.0, 500);
    Stock stock3("AutoMakers", "Automotive", 120.0, 800);

    // Initialize stocks vector
    std::vector<Stock> SelectedStocks = { stock1, stock3 };

    // Create an investment account
    Invest_acc investAccount("John Doe", 1000.0, SelectedStocks);

    // Display initial details
    investAccount.displayDetails();

    // Apply stock changes over iterations
    for (int i = 0; i < 3; ++i) {
        investAccount.applyStockDifference();
        investAccount.displayDetails();
        std::cout << "\n";
    }
    return 0;
}
