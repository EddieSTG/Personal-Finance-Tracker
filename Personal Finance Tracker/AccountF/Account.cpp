//
//  Account.cpp
//  Personal Finance Tracker
//
//  Created by Eduard on 31/01/2026.
//


#include "Account.hpp"
#include "Transaction.hpp"
#include <fstream>
#include <iostream>

void Account::AddTransaction(double amount,
                             const std::string& category,
                             const std::string& description,
                             const std::string& type)
{
    // 1. Create and store transaction in memory
    m_transactions.emplace_back(amount, category, description, type);

    // 2. Save the newly added transaction to file
    SaveTransactionToFile(m_transactions.back());
}

void Account::DeleteTransaction(size_t index)
{
    if (index < m_transactions.size())
    {
        // 1. Remove transaction from vector (memory)
        m_transactions.erase(m_transactions.begin() + index);

        // 2. Rewrite the transactions to file (with the removed one excluded)
        RewriteTransactionsToFile();
    }
    else
    {
        std::cerr << "Error: Invalid transaction index.\n";
    }
}

const std::vector<Transaction>& Account::getTransactions() const
{
    return m_transactions;
}

void Account::SaveTransactionToFile(const Transaction& transaction)
{
    std::ofstream file("transactions.csv", std::ios::app);

    if (!file)
    {
        std::cerr << "Failed to open transactions file\n";
        return;
    }

    file << transaction.amount() << ","
         << transaction.category() << ","
         << transaction.description() << ","
         << transaction.type() << "\n";
}

void Account::RewriteTransactionsToFile()
{
    std::ofstream file("transactions.csv", std::ios::trunc);  // Truncate to clear the file

    if (!file)
    {
        std::cerr << "Failed to open transactions file for rewriting\n";
        return;
    }

    // Write all transactions back to the file
    for (const auto& transaction : m_transactions)
    {
        file << transaction.amount() << ","
             << transaction.category() << ","
             << transaction.description() << ","
             << transaction.type() << "\n";
    }
}
