#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "account.h" // base class header
#include "bank.h"
#include <chrono>

class Savings_Acc : public Account {

private:
	double m_interest_rate; // interest rate for savings account
	std::chrono::system_clock::time_point m_last_deposit_time; // the last time of deposit 
public:
	// Constructor 
	Savings_Acc(const std::string& holder, double initialBalance, double rate = 3.0);

	// Destructor
	~Savings_Acc();

	// override deposit to track the timestamp
	void deposit(double amount) override;

	// apply interest to the balance
	void afterInterest(Bank& bank);

	// display account details
	void displayDetails() const override;
};


#endif