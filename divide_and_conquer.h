#ifndef DIVIDE_AND_CONQUER_H
#define DIVIDE_AND_CONQUER_H

#include <vector>
#include <algorithm>

int count_ones(const std::vector<int>& binaryArray) {
    int left = 0, right = binaryArray.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (binaryArray[mid] == 0) {
            left = mid + 1;
        } else {
            if (mid == 0 || binaryArray[mid - 1] == 0) {
                return binaryArray.size() - mid;
            }
            right = mid - 1;
        }
    }
    return 0;
}

int count_target(const std::vector<int>& sortedArray, int target) {
    auto lower = std::lower_bound(sortedArray.begin(), sortedArray.end(), target);
    auto upper = std::upper_bound(sortedArray.begin(), sortedArray.end(), target);
    return upper - lower;
}

#endif 
