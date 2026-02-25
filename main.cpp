#include <list>
#include "mergeSort.h"
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

void updateLines(const std::vector<sf::RectangleShape> &lines, const sf::RenderWindow &window) {
    float lineOffset = 20.f;

    for (sf::RectangleShape line : lines) {
        // Draw lines in correct orientation and position
        line.rotate(sf::degrees(270));
        line.setPosition({lineOffset, 1020.f});
        window.draw(line);
        lineOffset += 6.f;
    }
}

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

    for (float i : toSort) {
        std::cout << "[" << i << "]-";
    }

    std::vector<sf::RectangleShape> lines {};
    for (float i : toSort) {
        lines.push_back(sf::RectangleShape({i, 5.f}));
    }

    sf::VertexArray infoBox {sf::PrimitiveType::TriangleStrip, 5};
    infoBox[0].position = sf::Vector2f(1250.f, 300.f);
    infoBox[1].position = sf::Vector2f(1600.f, 300.f);
    infoBox[2].position = sf::Vector2f(1600.f, 600.f);
    infoBox[3].position = sf::Vector2f(1250.f, 600.f);
    infoBox[4].position = sf::Vector2f(1250.f, 300.f);
    infoBox[0].color = sf::Color::White;
    infoBox[1].color = sf::Color::White;
    infoBox[2].color = sf::Color::White;
    infoBox[3].color = sf::Color::White;
    infoBox[4].color = sf::Color::White;

    const sf::Font font("0xProtoNerdFontMono-Regular.ttf");
    sf::Text currentLine {font};
    currentLine.setCharacterSize(20);
    currentLine.setFillColor(sf::Color::Black);
    currentLine.setPosition(sf::Vector2f(1250.f, 350.f));
    currentLine.setString("Test string for testing purposes");

    sf::RenderWindow window(sf::VideoMode({1620, 1024}), "Algo visualisation");
    window.setFramerateLimit(60);

    updateLines(lines, window);

    // Render loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>() ) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {
                    mergeSort(toSort);
                }
            }
        }



        window.clear(sf::Color::Black);

        for (sf::RectangleShape& line : lines) {
            window.draw(line);
        }
        window.draw(infoBox);
        window.draw(currentLine);

        window.display();
    }


    std::cout << std::endl << "Sorted array" << std::endl;
    std::list<float> sorted {mergeSort<float>(toSort)};
    for (float i : sorted) {
        std::cout << "[" << i << "]-";
    }
}