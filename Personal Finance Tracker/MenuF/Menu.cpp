//
//  Menu.cpp
//  Personal Finance Tracker
//
//  Created by Eduard on 31/01/2026.
//

#include "Menu.hpp"
#include <iostream>

void DisplayMenu()
{
    std::cout << "====Personal Finance Tracker====\n" << std::endl;
    std::cout << "1. Add Transaction\n" << std::endl;
    std::cout << "2. View Transaction\n" << std::endl;
    std::cout << "3. Delete Transaction\n" << std::endl;
    std::cout << "4. Exit\n" << std::endl;
    std::cout << "================================\n" << std::endl;
    std::cout << "Enter your choice: " << std::endl;
}
