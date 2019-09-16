#include <SFML/Graphics.hpp>
#include <cmath>
#include "ball.h"

using namespace std;

Ball::Ball (float xStart, float yStart) {
    position.x = xStart;
    position.y = yStart;

    xSpeed = 2.0f;
    ySpeed = 2.0f;

    ball.setRadius(6);
    ball.setPosition(position);
    ball.setFillColor(sf::Color::White);
}

float Ball::getAngle(){
    return curAngle;
}

void Ball::updateAngle(float angle) {
    curAngle = angle;
}

void Ball::move() {
    ball.move(cos(curAngle) * xSpeed, sin(curAngle) * ySpeed);
}

sf::CircleShape Ball::getBall() {
    return ball;
}