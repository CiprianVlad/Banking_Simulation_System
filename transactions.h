#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H 

#include <iostream> 
#include <chrono>
#include <ctime>

class Account;

class Transactions {

private:

    Account* m_sourceAcc;
    Account* m_destAcc;
    double m_amount;
    double m_fee;
    std::chrono::system_clock::time_point m_timestamp;
    static int m_transaction_id;

public:

    Transactions(Account* src, Account* dest, double amount, double fee);
    ~Transactions();

    bool execute();

    // Getters 
    double getFee() const;
    double getAmount() const;
    std::string getTimestamp() const;
};

#endif