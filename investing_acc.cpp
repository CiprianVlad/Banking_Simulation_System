#include "investing_acc.h"
#include "stock.h"

// Constructor
Invest_acc::Invest_acc(const std::string& holder, double initialBalance, const std::vector<Stock>& initialStocks)
	: Account(holder, initialBalance), stocks(initialStocks), distribution(-0.2, 0.2) {
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

//Destructor 
Invest_acc::~Invest_acc() {
	// No cleanup needed 
}

// Override deposit 
void Invest_acc::deposit(double amount) {
	if (amount > 0) {
		balance += amount;
		std::cout << "Deposited $" << amount << " into the investment acccount.\n";
	} else {
		std::cout << "Invalid deposit amount.\n";
	}
}

// Randomize stock indices and update balance 
void Invest_acc::applyStockDifference() {
	double totalChange = 0.0; 

	for (auto& stock : stocks) {
		// Randomly change the stock index 
		double change = stock.getCurrentIndex() * distribution(generator);
		stock.updateIndex(stock.getCurrentIndex() + change);
		totalChange += change; 
	}
	// Update the account balance 
	balance += totalChange; 

	std::cout << "Stock indices updated. Total change in balance: $" << totalChange << "\n";
}

// Display account + stock details 
void Invest_acc::displayDetails() const {
	Account::displayDetails(); // the base fuctions 
	std::cout << "Investment Account Stocks:\n";
	for (const auto& stock : stocks) {
		stock.displayDetails(); 
		std::cout << "\n";
	}
}