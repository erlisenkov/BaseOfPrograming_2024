#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int n = prices.size();

//     Массивы для отслеживания максимальной прибыли после первой и второй транзакции
    vector<int> profit_after_first(n, 0);
    vector<int> profit_after_second(n, 0);

    // Находим максимальную прибыль после первой транзакции
    int min_price = prices[0];
    for (int i = 1; i < n; ++i) {
        min_price = min(min_price, prices[i]);
        profit_after_first[i] = max(profit_after_first[i - 1], prices[i] - min_price);
    }

    // Находим максимальную прибыль после второй транзакции
    int max_price = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_price = max(max_price, prices[i]);
        profit_after_second[i] = max(profit_after_second[i + 1], max_price - prices[i]);
    }

    // Находим максимальную общую прибыль, объединяя прибыль после первой и второй транзакции
    int max_profit = 0;
    for (int i = 0; i < n; ++i) {
        max_profit = max(max_profit, profit_after_first[i] + profit_after_second[i]);
    }

    return max_profit;
}

int main() {
    vector<int> prices = {1, 5, 3, 2, 1, 8};
    int result = maxProfit(prices);
    cout << result << endl;

    return 0;
}
