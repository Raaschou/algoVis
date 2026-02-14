//
// Created by marcu on 14-02-2026.
//

#include "mergeSort.h"

#include <list>

std::list<int> merge(std::list<int> left, std::list<int> right) {
    std::list<int> result {};
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    // If sides are not of equal length
    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

std::list<int> mergeSort(std::list<int> arr) {
    // Base case
    if (arr.size() <= 1) return arr;

    std::list<int> left {};
    std::list<int> right {};
    int arrayLength {static_cast<int>(arr.size())};

    int index = 0;
    for (auto i : arr) {
        if( index++ < arr.size()/2) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}
