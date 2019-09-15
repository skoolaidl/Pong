#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace std;

Paddle::Paddle (float xPos, float yPos) {
    position.x = xPos;
    position.y = yPos;

    speed = .8f;
    
    paddle.setSize(sf::Vector2f(15,70));
    paddle.setPosition(position);
    paddle.setFillColor(sf::Color::White);
}

void Paddle::moveUp() {
    position.y -= speed;
    paddle.setPosition(position);
}

void Paddle::moveDown() {
    position.y += speed;
    paddle.setPosition(position);
}

sf::Vector2f Paddle::getSize() {
    return paddle.getSize();
}

sf::RectangleShape Paddle::getPaddle() {
    return paddle;
}





