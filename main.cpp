#include <list>
#include "mergeSort.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    std::cout << "Unsorted array:" << std::endl;
    std::list<float> toSort = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f };
    for (float i : toSort) {
        std::cout << "[" << i << "]-";
    }
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Algo visualisation");
    std::vector<sf::RectangleShape> lines {};
    float lineHeight {150.f};
    for (float i : toSort) {
        lines.push_back(sf::RectangleShape({lineHeight, 10.f}));
        lineHeight += 50.f;
    }

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        float lineOffset = 20.f;

        for (sf::RectangleShape& line : lines) {
            line.setPosition({10.f, lineOffset});
            window.draw(line);
            lineOffset += 11.f;
        }

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