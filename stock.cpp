#include "stock.h"

int Stock::nextId = 0; 

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

double Stock::getCurrentIndex() const{
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
// Operatorul << 
std::ostream& operator<<(std::ostream& os, const Stock& stock) {
    os << " Stock: " << stock.getName() << ", Category: " << stock.getCategory()
        << ", Index: " << stock.getCurrentIndex() << ", For Sale: " << stock.getStocksForSale();
    return os;
}
// Operatorul + 
Stock Stock::operator+(const Stock& other) const {
    if (name == other.name && category == other.category) {
        return Stock(name, category, currentIndex, stocksForSale);
    } 
    // return copy 
    return *this; 
}

// Display stock details
void Stock::displayDetails() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Category: " << category << "\n";
    std::cout << "Current Index: " << currentIndex << "\n";
    std::cout << "Stocks for Sale: " << stocksForSale << "\n";
    std::cout << "Index History: ";
    for (const auto& index : indexHistory) {
        std::cout << index << " ";
    }
    std::cout << "\n";
}