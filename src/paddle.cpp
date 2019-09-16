#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace std;

Paddle::Paddle (float xPos, float yPos) {
    //Set initial paddle position
    position.x = xPos;
    position.y = yPos;

    //Set paddle speed
    speed = 1.5f;
    
    //Set paddle parameters
    paddle.setSize(sf::Vector2f(10,70));
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





