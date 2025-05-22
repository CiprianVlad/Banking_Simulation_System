#include "stock.h"

int Stock::nextId = 1;

// Constructor 
Stock::Stock(const std::string& name, const std::string& category, double initialIndex, int stocksForSale)
	: id(nextId++), name(name), category(category), currentIndex(initialIndex), stocksForSale(stocksForSale) {
    indexHistory.push_back(initialIndex);
};

// Getters
int Stock::getId() const {
    return id;
}

std::string Stock::getName() const {
    return name;
}

std::string Stock::getCategory() const {
    return category;
}
/*
std::string Stock::getDescription() const {
    return description;
}
*/
double Stock::getCurrentIndex() const {
    return currentIndex;
}

int Stock::getStocksForSale() const {
    return stocksForSale;
}

const std::vector<double>& Stock::getIndexHistory() const {
    return indexHistory;
}

// Setters
void Stock::updateIndex(double newIndex) {
    currentIndex = newIndex;
    indexHistory.push_back(newIndex); // Add the new index to the history
}

void Stock::setStocksForSale(int newStocksForSale) {
    stocksForSale = newStocksForSale;
}

// Display stock details
void Stock::displayDetails() const {
    std::cout << "Stock ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Category: " << category << "\n";
    // std::cout << "Description: " << description << "\n";
    std::cout << "Current Index: " << currentIndex << "\n";
    std::cout << "Stocks for Sale: " << stocksForSale << "\n";
    std::cout << "Index History: ";
    for (const auto& index : indexHistory) {
        std::cout << index << " ";
    }
    std::cout << "\n";
}