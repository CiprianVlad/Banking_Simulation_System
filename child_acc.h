#ifndef CHILD_ACOOUNT_H
#define CHILD_ACOOUNT_H

#include "account.h" // base header 
#include <chrono>
#include <iomanip>
#include "bank.h"

class Child_Acc : public Account {

private:
	double m_interest_rate; // interest rate for savings account
	std::chrono::system_clock::time_point m_last_deposit_time; // the last time of deposit 
public:
	// Constructor 
	Child_Acc(const std::string& holder, double initialBalance, double rate = 1.0); 

	// Destructor
	~Child_Acc();

	// override deposit to track the timestamp
	void deposit(double amount) override;

	// apply interest to the balance
	void afterInterest(Bank& bank);

	// display account details
	void displayDetails() const override;
};
#endif