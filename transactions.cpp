#include <iostream> 
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "account.h"
#include "transactions.h"

int Transactions::m_transaction_id = 0;

Transactions::Transactions(Account* src, Account* dest, double amount, double fee)
    : m_sourceAcc(src), m_destAcc(dest), m_amount(amount), m_fee(3){
    m_transaction_id++; 
} 


Transactions::~Transactions() {} // Scris sa nu fie lasat implicit 


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
