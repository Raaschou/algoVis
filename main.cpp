#include <list>
#include "mergeSort.h"
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>


int main() {
    std::cout << "Unsorted array:" << std::endl;
    std::list<float> toSort = {};

    for (int i = 1; i <= 200; i++) {
        toSort.push_back(static_cast<float>(i));
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    // Hack for shuffling list
    std::vector<int> temp( toSort.begin(), toSort.end());
    std::shuffle(temp.begin(), temp.end(), rng);
    std::copy(temp.begin(), temp.end(), toSort.begin());


    std::vector<sf::RectangleShape> lines {};
    for (float i : toSort) {
        lines.push_back(sf::RectangleShape({i, 5.f}));
    }


    sf::RenderWindow window(sf::VideoMode({1620, 1024}), "Algo visualisation");
    window.setFramerateLimit(60);

    float lineOffset = 20.f;
    for (sf::RectangleShape& line : lines) {
        // Draw lines in correct orientation and position
        line.rotate(sf::degrees(270));
        line.setPosition({lineOffset, 1020.f});
        window.draw(line);
        lineOffset += 6.f;
    }

    // Render loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        for (sf::RectangleShape& line : lines) {
            window.draw(line);
        }

        window.display();
    }


    std::cout << std::endl << "Sorted array" << std::endl;
    std::list<float> sorted {mergeSort<float>(toSort)};
    for (float i : sorted) {
        std::cout << "[" << i << "]-";
    }
}