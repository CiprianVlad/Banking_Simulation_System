#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Account {

protected:
    std::string account_number;
    std::string account_holder;

    double balance;
    static int accountCount; // numarul de conturi create 
    std::string generateAccountNumber();

public:

    Account(const std::string& holder, double initialBalance);
    virtual ~Account();

    // Setters
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void displayDetails() const;

    //Getters 
    std::string getAccNumber() const;
    std::string getAccHolder() const;

    double getBalance() const;
    static int getAccountCount();

};

#endif
