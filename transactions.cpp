#include <iostream> 
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "C:/Users/Ciprian/OneDrive - unibuc.ro/Desktop/facultate/Anul I sem II/POO/proiect/account.h"
#include "C:/Users/Ciprian/OneDrive - unibuc.ro/Desktop/facultate/Anul I sem II/POO/proiect/bank.h"
#include "C:/Users/Ciprian/OneDrive - unibuc.ro/Desktop/facultate/Anul I sem II/POO/proiect/transactions.h"

class Account;

Transactions::Transactions(Account* src, Account* dest, double amount, double fee)
    : m_sourceAcc(src), m_destAcc(dest), m_amount(amount), m_fee(fee), m_transaction_id(0) {
} // m_transaction_id should be used to identify the transaction, but it's not implemented in this code.


Transactions::~Transactions() {} // Sa stiu ca e acolo 


bool Transactions::execute() {
    if (!m_sourceAcc || !m_destAcc) return false; // != nullptr

    if (m_sourceAcc->Account::getBalance() >= (m_amount + (m_amount * m_fee / 100.0))) {
        double amount_deducted = m_amount + (m_amount * m_fee / 100.0);
        m_sourceAcc->withdraw(amount_deducted);
        m_destAcc->deposit(m_amount);

        auto end = std::chrono::system_clock::now();
        m_timestamp = end;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        char buffer[26]; // Buffer to hold the formatted time string
        ctime_s(buffer, sizeof(buffer), &end_time);
        std::cout << "Transfer completed at: " << buffer;

        return true;
    }

    return false;
}

// Getters 
double Transactions::getFee() const {
    return m_fee;
}

double Transactions::getAmount() const {
    return m_amount;
}

// from timestamp to string 
std::string Transactions::getTimestamp() const {
    std::time_t time = std::chrono::system_clock::to_time_t(m_timestamp);
    std::tm tm;
    localtime_s(&tm, &time); // Use localtime_s for safety
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
