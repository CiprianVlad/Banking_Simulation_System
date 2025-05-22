#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H 

#include <iostream> 
#include <chrono>
#include <ctime>

class Account; // not good practice 

class Transactions {

private:

    Account* m_sourceAcc;
    Account* m_destAcc;
    double m_amount;
    double m_fee;
    std::chrono::system_clock::time_point m_timestamp;
    static int m_transaction_id; 
    // inline static int m_transaction_id = 0; 
    // C++17 and above, C++14 does not allow this 

public:

    Transactions(Account* src, Account* dest, double amount, double fee = 3);
    ~Transactions();

    bool execute();

    // Getters 
    double getFee() const;
    double getAmount() const;
    std::string getTimestamp() const;
};

#endif