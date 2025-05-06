#ifndef INVESTING_ACC_H
#define INVESTING_ACC_H

#include "account.h"
#include "stock.h"
#include <vector>
#include <chrono>
#include <random>

class Invest_acc : public Account {
private:
	std::vector<Stock> stocks; // list of stocks 
	std::chrono::system_clock::time_point m_last_deposit_time; // the last time of deposit 
	std::default_random_engine generator; // with how much is modified the stock 
	std::uniform_real_distribution<double> distribution; // the distribution of the random changes 

public:
	// Constructor 
	Invest_acc(const std::string& holder, double initialBalance, const std::vector<Stock>& initialStocks);

	// Destructor
	~Invest_acc();

	// override deposit to track the timestamp
	void deposit(double amount) override;

	// apply interest to the balance
	void applyStockDifference();

	// display account details
	void displayDetails() const override; 
};
#endif 
