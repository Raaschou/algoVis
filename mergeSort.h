#ifndef MERGESORT_H
#define MERGESORT_H

#include <functional>
#include <list>

#include "SFML/Graphics.hpp"


void onUpdate(sf::RenderWindow& window, std::vector<sf::RectangleShape>& lines, std::list<float>& state) {
    int i {0};
    for (float value : state) {
        lines[i].setSize({value, 5.f});
        // window.draw(lines[i]);
        i++;
    }

    window.clear(sf::Color::Black);

    for (auto &line : lines) {
        window.draw(line);
    }


    window.display();

    sf::sleep(sf::milliseconds(10));
}


template <class Data>
std::list<Data> merge(std::list<Data> left, std::list<Data> right, sf::RenderWindow& window,  std::vector<sf::RectangleShape>& lines) {
    std::list<Data> result{};
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();

        } else {
            result.push_back(right.front());
            right.pop_front();
        }

        onUpdate(window, lines, result);
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
        onUpdate(window, lines, result);

    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
        onUpdate(window, lines, result);

    }

    return result;
}

template <class Data>
std::list<Data> mergeSort(std::list<Data>& arr, sf::RenderWindow& window,  std::vector<sf::RectangleShape>& lines) {
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

    left = mergeSort(left, window, lines);
    right = mergeSort(right, window, lines);


    return merge(left, right, window, lines);
}

#endif
