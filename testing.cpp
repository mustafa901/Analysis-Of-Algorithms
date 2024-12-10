#include <iostream>
#include "divide_and_conquer.h"
#include "dynamic_programming.h"

void test_divide_and_conquer() {
    std::cout << "Testing count_ones:" << std::endl;
    std::vector<std::vector<int>> testCases1 = {{0, 0, 1, 1, 1}, {0, 1, 1}, {1, 1, 1}, {0, 0, 0}, {1}};
    std::vector<int> expected1 = {3, 2, 3, 0, 1};
    for (size_t i = 0; i < testCases1.size(); ++i) {
        std::cout << "Input: ";
        for (int num : testCases1[i]) std::cout << num << " ";
        std::cout << " | Expected: " << expected1[i];
        std::cout << " | Output: " << count_ones(testCases1[i]) << std::endl;
    }

    std::cout << "\nTesting count_target:" << std::endl;
    std::vector<std::vector<int>> testCases2 = {{1, 2, 2, 3, 4}, {1, 1, 1, 2}, {2, 2, 2, 2}, {1, 3, 5}, {1}};
    std::vector<int> targets = {2, 1, 2, 4, 0};
    std::vector<int> expected2 = {2, 3, 4, 0, 0};
    for (size_t i = 0; i < testCases2.size(); ++i) {
        std::cout << "Input: ";
        for (int num : testCases2[i]) std::cout << num << " ";
        std::cout << " | Target: " << targets[i] << " | Expected: " << expected2[i];
        std::cout << " | Output: " << count_target(testCases2[i], targets[i]) << std::endl;
    }
}

void test_dynamic_programming() {
    std::cout << "\nTesting knapsack:" << std::endl;
    std::vector<std::vector<std::pair<int, int>>> testCases = {
        {{2, 3}, {1, 2}, {3, 6}, {2, 1}},
        {{1, 1}, {2, 2}, {3, 3}},
        {{1, 10}, {4, 40}, {3, 50}, {2, 60}},
        {{5, 10}, {4, 40}, {6, 30}, {3, 50}},
        {{1, 15}, {3, 20}, {4, 25}, {2, 30}}
    };
    std::vector<int> limits = {5, 4, 5, 10, 7};
    std::vector<int> expected = {8, 4, 60, 90, 70};
    for (size_t i = 0; i < testCases.size(); ++i) {
        std::cout << "Items (weight, value): ";
        for (auto item : testCases[i]) std::cout << "(" << item.first << ", " << item.second << ") ";
        std::cout << " | Weight Limit: " << limits[i];
        std::cout << " | Expected Value: " << expected[i];
        std::cout << " | Output Value: " << knapsack(testCases[i], testCases[i].size(), limits[i]) << std::endl;
    }
}

int main() {
    test_divide_and_conquer();
    test_dynamic_programming();
    return 0;
}
