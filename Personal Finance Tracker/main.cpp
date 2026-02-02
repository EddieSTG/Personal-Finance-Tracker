//
//  main.cpp
//  Personal Finance Tracker
//
//  Created by Eduard on 29/01/2026.
//

#include <iostream>
#include <limits>
#include "Account.hpp"
#include "MenuF/Menu.hpp"
#include "AccountF/Account.hpp"
#include "TransactionF/Transaction.hpp"

void addTransaction(Account& account)
{
    double amount;
    std::string category, description, type;

    std::cout << "\nEnter transaction details:\n";
    std::cout << "Amount: $";
    std::cin >> amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Flush input buffer

    std::cout << "Category: ";
    std::getline(std::cin, category);

    std::cout << "Description: ";
    std::getline(std::cin, description);

    std::cout << "Type (Income/Expense): ";
    std::getline(std::cin, type);

    // Call Account's AddTransaction method
    account.AddTransaction(amount, category, description, type);
    std::cout << "Transaction added successfully!\n";
}

void viewTransactions(const Account& account)
{
    std::cout << "\n--- View Transactions ---\n";

    // Call Account's getTransactions method
    const auto& transactions = account.getTransactions();

    if (transactions.empty())
    {
        std::cout << "No transactions available.\n";
    }
    else
    {
        // Loop through the transactions and print them
        for (size_t i = 0; i < transactions.size(); ++i)
        {
            const auto& t = transactions[i];
            std::cout << "Transaction #" << i + 1 << ": \n";
            std::cout << "  Amount: $" << t.amount() << "\n";
            std::cout << "  Category: " << t.category() << "\n";
            std::cout << "  Description: " << t.description() << "\n";
            std::cout << "  Type: " << t.type() << "\n";
            std::cout << "----------------------------\n";
        }
    }
}

void deleteTransaction(Account& account)
{
    size_t index;

    std::cout << "\nEnter the transaction number to delete: ";
    std::cin >> index;
    index -= 1;  // Adjust for 0-based indexing

    // Call Account's DeleteTransaction method
    account.DeleteTransaction(index);
    std::cout << "Transaction #" << index + 1 << " deleted.\n";
}

int main()
{
    Account myAccount;  // Account object to manage transactions
    int choice;
    bool running = true;

    while (running)
    {
        // Call Menu's DisplayMenu function to show options
        DisplayMenu();

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Flush input buffer

        switch (choice)
        {
            case 1:
                addTransaction(myAccount);
                break;
            case 2:
                viewTransactions(myAccount);
                break;
            case 3:
                deleteTransaction(myAccount);
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
