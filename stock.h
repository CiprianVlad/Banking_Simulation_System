#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>

class Stock {
private:
	static int nextId; 
	int id;
	std::string name;
	std::string category; // stock category (eg. tech, health)
	double currentIndex; 
	int stocksForSale;
	std::string description; // Not sure if I should have a written description and have a getter
	// or set one in main.cpp for each stock
	std::vector<double> indexHistory; // how the index performed in time
	// could become a graph (child class) for future implementations

public:
	// Constructor
	Stock(const std::string& name, const std::string& category, double initialIndex, int stocksForSale);

	//Getters 
	int getId() const;
	std::string getName() const;
	std::string getCategory() const;
	// std::string getDescription() const; // a possibility
	double getCurrentIndex() const;
	int getStocksForSale() const;
	const std::vector<double>& getIndexHistory() const;

	// Setters 
	void updateIndex(double newIndex);
	void setStocksForSale(int newStock);

	// Display stock details
	void displayDetails() const;
};

#endif
