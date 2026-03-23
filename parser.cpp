#include "budget_manager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

void ParseAndProcessQuery(BudgetManager& manager, std::string_view line) {
    std::istringstream in{std::string(line)};
    std::string command;
    in >> command;

    if (command == "Earn") {
        std::string from_str, to_str;
        double amount;
        in >> from_str >> to_str >> amount;
        manager.Earn(Date(from_str), Date(to_str), amount);
    } else if (command == "PayTax") {
        std::string from_str, to_str;
        int percentage;
        in >> from_str >> to_str >> percentage;
        manager.PayTax(Date(from_str), Date(to_str), percentage);
    } else if (command == "Spend") {
        std::string from_str, to_str;
        double amount;
        in >> from_str >> to_str >> amount;
        manager.Spend(Date(from_str), Date(to_str), amount);
    } else if (command == "ComputeIncome") {
        std::string from_str, to_str;
        in >> from_str >> to_str;
        double result = manager.ComputeIncome(Date(from_str), Date(to_str));
        std::cout.precision(10);
        std::cout << result << std::endl;
    }
}
