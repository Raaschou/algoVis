#ifndef MERGESORT_H
#define MERGESORT_H

#include <list>

template <class Data>
std::list<Data> merge(std::list<Data> left, std::list<Data> right) {
    std::list<Data> result{};
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }

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

template <class Data>
std::list<Data> mergeSort(std::list<Data> arr) {
    if (arr.size() <= 1) return arr;

    std::list<Data> left{};
    std::list<Data> right{};

    int half = arr.size() / 2;
    int index = 0;

    for (auto i : arr) {
        if (index++ < half)
            left.push_back(i);
        else
            right.push_back(i);
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

#endif
