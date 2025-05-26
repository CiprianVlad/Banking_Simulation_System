#ifndef INVESTING_ACC_H
#define INVESTING_ACC_H

#include "account.h"
#include "stock.h"
#include "bank.h"

class Invest_acc : public Account {
private:
	std::vector<Stock> stocks;
	std::vector<int> heldStocks;
public:
	// Constructor 
	Invest_acc(const std::string& holder, double initialBalance, std::vector<Stock>& initialStocks);

	// Destructor
	~Invest_acc();

	// override deposit to track the timestamp
	void deposit(double amount) override;

	void updateStocks(Bank& bank);

	// Getters 
	std::vector<Stock>& getSelectedStocks();
	std::vector<int>& getHeldStocks();

	// allow the user to invest a specific amount
	bool investInStocks(std::vector<int> stockVecIndex, double& amount);

};
#endif 
