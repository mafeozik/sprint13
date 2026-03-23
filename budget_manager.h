#pragma once

#include "date.h"
#include <vector>

class BudgetManager {
public:
    static const Date START_DATE;
    static const Date END_DATE;

    BudgetManager();

    void Earn(const Date& from, const Date& to, double amount);
    void Spend(const Date& from, const Date& to, double amount);
    void PayTax(const Date& from, const Date& to, int percentage);
    double ComputeIncome(const Date& from, const Date& to) const;

private:
    std::vector<double> income_;
    std::vector<double> spend_;
    std::vector<double> taxed_;
};
