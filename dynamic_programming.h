#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <vector>
#include <iostream>

void find_items(const std::vector<std::vector<int>>& dp, const std::vector<std::pair<int, int>>& items, int n, int weightLimit);

int knapsack(const std::vector<std::pair<int, int>>& items, int n, int weightLimit) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(weightLimit + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int weight = items[i - 1].first;
        int value = items[i - 1].second;

        for (int w = 0; w <= weightLimit; ++w) {
            if (weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weight] + value);
            }
        }
    }

    find_items(dp, items, n, weightLimit);

    return dp[n][weightLimit];
}

void find_items(const std::vector<std::vector<int>>& dp, const std::vector<std::pair<int, int>>& items, int n, int weightLimit) {
    std::vector<int> chosenItems;
    int w = weightLimit;

    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosenItems.push_back(i - 1); 
            w -= items[i - 1].first;
        }
    }

    std::cout << "Chosen items (0-based index): ";
    for (int idx : chosenItems) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;
}

#endif 
