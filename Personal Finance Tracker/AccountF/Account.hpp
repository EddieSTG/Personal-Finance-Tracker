#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <vector>
#include <string>

class Transaction;

class Account
{
public:
    void AddTransaction(double amount,
                        const std::string& category,
                        const std::string& description,
                        const std::string& type);

    void DeleteTransaction(size_t index);  // <-- New method to delete a transaction
    const std::vector<Transaction>& getTransactions() const;

private:
    std::vector<Transaction> m_transactions;

    void SaveTransactionToFile(const Transaction& transaction);
    void RewriteTransactionsToFile(); // <-- Helper to rewrite the whole file
};

#endif
