#include "investing_acc.h"
#include "stock.h"

// Constructor
Invest_acc::Invest_acc(const std::string& holder, double initialBalance, std::vector<Stock>& initialStocks)
	: Account(holder, initialBalance), stocks(initialStocks) {}

//Destructor 
Invest_acc::~Invest_acc() {}

// Override deposit 
void Invest_acc::deposit(double amount) {
	if (amount > 0) {
		balance += amount;
		std::cout << "Deposited $" << amount << " into the investment acccount.\n";
	} else {
		std::cout << "Invalid deposit amount.\n";
	}
}

// Getters 
std::vector<Stock>& Invest_acc::getSelectedStocks(){
	return stocks;
}

std::vector<int>& Invest_acc::getHeldStocks() {
    return heldStocks;
}

// allow the user to invest a specific amount
bool Invest_acc::investInStocks(std::vector<int> stockVecIndex, double& amount) {
    auto& stocks = getSelectedStocks(); 
    auto& heldStocks = getHeldStocks();

    // Ensure heldStocks is the same size as stocks
    if (heldStocks.size() != stocks.size()) {
        heldStocks.resize(stocks.size(), 0);
    }

    if (stockVecIndex.empty()) {
        std::cout << "No stocks selected.\n";
        return false;
    }

	double amountPerStock = amount / stockVecIndex.size();
	bool ok = false;

    for (int stock_id : stockVecIndex) {
        if (stock_id < 0 || stock_id >= static_cast<int>(stocks.size())) {
            std::cout << "Invalid stock selection: " << stock_id << "\n";
            continue;
        }
        Stock& stock = stocks[stock_id];
        double price = stock.getCurrentIndex();
        int maxBuyable = static_cast<int>(amountPerStock / price);
        if (maxBuyable == 0) {
            std::cout << "Amount too low to buy any stock of " << stock.getName() << ".\n";
            continue;
        }
        if (maxBuyable > stock.getStocksForSale()) {
            std::cout << "Not enough stocks available for " << stock.getName()
                << ". You can buy up to " << stock.getStocksForSale() << ".\n";
            maxBuyable = stock.getStocksForSale();
        }
        double totalCost = maxBuyable * price;
        if (totalCost > getBalance()) {
            std::cout << "Insufficient funds for purchase of " << stock.getName() << ".\n";
            continue;
        }

        Account::balance -= totalCost;
        stock.setStocksForSale(stock.getStocksForSale() - maxBuyable);
        heldStocks[stock_id] += maxBuyable;
        amount -= maxBuyable;
        std::cout << "Purchased " << maxBuyable << " stocks of " << stock.getName()
            << " for $" << totalCost << ".\n";
        ok = true;
    }
    return ok;
}

void Invest_acc::updateStocks(Bank& bank) {
    double totalChange = 0.0;
    for (auto& stock : stocks) {
        double change = bank.applyStockDifference(stock);
        totalChange += change;
    }
    balance += totalChange;
    std::cout << "Total change in balance after updating all stocks: $" << totalChange << "\n";
}