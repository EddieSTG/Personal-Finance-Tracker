//
//  Transaction.hpp
//  Personal Finance Tracker
//
//  Created by Eduard on 31/01/2026.
//

#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <chrono>

class Transaction
{
public:
    // Constructor to initialize the transaction details
    Transaction(double amount,
                const std::string& category,
                const std::string& description,
                const std::string& type);

    // Getter methods
    double amount() const;
    const std::string& category() const;
    const std::string& description() const;
    const std::string& type() const;
    std::chrono::system_clock::time_point timestamp() const;

private:
    double m_amount;
    std::string m_category;
    std::string m_description;
    std::string m_type;
    std::chrono::system_clock::time_point m_timestamp;
};

#endif // TRANSACTION_HPP


