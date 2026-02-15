#include <list>
#include "mergeSort.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    std::cout << "Unsorted array:" << std::endl;
    std::list<int> toSort = {11, 21, 3, 54, 76, 43, 67, 64, 54, 100 };

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Algo visualisation");

    sf::RectangleShape line({150.f, 5.f});
    line.rotate(sf::degrees(90));
    sf::Vector2f vectorTranslate {100.f, 100.f};
    line.setPosition(vectorTranslate);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(line);

        window.display();
    }


    std::cout << std::endl << "Sorted array" << std::endl;
    std::list<int> sorted {mergeSort(toSort)};
    for (int i : sorted) {
        std::cout << "[" << i << "]-";
    }
}