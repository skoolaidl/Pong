#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace std;

Paddle::Paddle (float xPos, float yPos)
{
    position.x = xPos;
    position.y = yPos;
    
    paddle.setSize(sf::Vector2f(5,45));
    paddle.setPosition(position);
    paddle.setFillColor(sf::Color::White);
}

sf::RectangleShape Paddle::getPaddle(){
    return paddle;
}





