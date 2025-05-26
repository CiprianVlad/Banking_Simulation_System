#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>
#include <random>

class Stock {
private:
	static int nextId;
	int id; 
	std::string name;
	std::string category; // company category (eg. tech, health)
	double currentIndex; 
	int stocksForSale;
	std::vector<double> indexHistory;

public:
	// Overload pe <<  
	friend std::ostream& operator<<(std::ostream& os, const Stock& stock); 

	// Overload pe operatorul + 
	Stock operator+(const Stock& other) const; 

	// Constructor
	Stock(const std::string& name, const std::string& category, double initialIndex, int stocksForSale);

	//Getters 
	int getId() const;
	std::string getName() const;
	std::string getCategory() const;
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
