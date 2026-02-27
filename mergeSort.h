#ifndef MERGESORT_H
#define MERGESORT_H

#include <functional>
#include <list>

#include "SFML/Graphics.hpp"



template <class Data>
std::list<Data> merge(std::list<Data> left, std::list<Data> right,  std::function<void(const std::list<Data>&)> onUpdate) {
    std::list<Data> result{};
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();

        } else {
            result.push_back(right.front());
            right.pop_front();
        }

        onUpdate(result);
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
        onUpdate(result);

    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
        onUpdate(result);

    }

    return result;
}

template <class Data>
std::list<Data> mergeSort(std::list<Data>& arr,  std::function<void(const std::list<Data>&)> onUpdate) {
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

    left = mergeSort(left, onUpdate);
    right = mergeSort(right, onUpdate);


    return merge(left, right, onUpdate);
}

#endif
