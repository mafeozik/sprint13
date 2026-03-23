#include "budget_manager.h"

using namespace std::literals;

const Date BudgetManager::START_DATE = Date("2000-01-01"s);
const Date BudgetManager::END_DATE = Date("2100-01-01"s);

BudgetManager::BudgetManager() {
    int total_days = Date::ComputeDistance(START_DATE, END_DATE);
    income_.assign(total_days, 0.0);
    spend_.assign(total_days, 0.0);
}

void BudgetManager::Earn(const Date& from, const Date& to, double amount) {
    int start_idx = Date::ComputeDistance(START_DATE, from);
    int end_idx = Date::ComputeDistance(START_DATE, to);
    int days = end_idx - start_idx + 1;
    double per_day = amount / days;
    for (int i = start_idx; i <= end_idx; ++i) {
        income_[i] += per_day;
    }
}

void BudgetManager::Spend(const Date& from, const Date& to, double amount) {
    int start_idx = Date::ComputeDistance(START_DATE, from);
    int end_idx = Date::ComputeDistance(START_DATE, to);
    int days = end_idx - start_idx + 1;

    double per_day = amount / days;

    for (int i = start_idx; i <= end_idx; ++i) {
        spend_[i] += per_day;
    }
}

void BudgetManager::PayTax(const Date& from, const Date& to, int percentage) {
    int start_idx = Date::ComputeDistance(START_DATE, from);
    int end_idx = Date::ComputeDistance(START_DATE, to);

    double factor = (100.0 - percentage) / 100.0;
    for (int i = start_idx; i <= end_idx; ++i) {
        income_[i] *= factor;
    }
}

double BudgetManager::ComputeIncome(const Date& from, const Date& to) const {
    int start_idx = Date::ComputeDistance(START_DATE, from);
    int end_idx = Date::ComputeDistance(START_DATE, to);
    double total = 0.0;
    for (int i = start_idx; i <= end_idx; ++i) {
            total += income_[i] - spend_[i];
    }
    return total;
}
