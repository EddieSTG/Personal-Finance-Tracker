//
//  Transaction.cpp
//  Personal Finance Tracker
//
//  Created by Eduard on 31/01/2026.
//

#include "Transaction.hpp"

Transaction::Transaction(double amount,
                         const std::string& category,
                         const std::string& description,
                         const std::string& type)
    : m_amount(amount),
      m_category(category),
      m_description(description),
      m_type(type),
      m_timestamp(std::chrono::system_clock::now())

{
    m_timestamp = std::chrono::system_clock::now();  // Set current timestamp
}

double Transaction::amount() const { return m_amount; }
const std::string& Transaction::category() const { return m_category; }
const std::string& Transaction::description() const { return m_description; }
const std::string& Transaction::type() const { return m_type; }
std::chrono::system_clock::time_point Transaction::timestamp() const { return m_timestamp;
    
}
