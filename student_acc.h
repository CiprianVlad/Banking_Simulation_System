#ifndef STUDENT_ACCOUNT_H
#define STUDENT_ACCOUNT_H

#include "account.h" // include the base class header
#include <iomanip>
#include <chrono>

class Student_Acc : public Account {

private:
	double m_interest_rate; // interest rate for savings account
	std::chrono::system_clock::time_point last_deposit_time; // the last time of deposit 
public:
	// Constructor 
	Student_Acc(const std::string& holder, double initialBalance, double rate = 1.0);

	// Destructor
	~Student_Acc();

	// override deposit to track the timestamp
	void deposit(double amount) override;

	// apply interest to the balance
	void applyInterest();

	// display account details
	void displayDetails() const override;

	// Getter for Interest Rate
	double getInterestRate() const{
		return m_interest_rate;
	}
};


#endif