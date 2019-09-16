#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Ball {
    public:
        Ball() {};
        Ball(float xStart, float yStart);

        sf::CircleShape ball;

        float curAngle;

        sf::Vector2f position;
        sf::CircleShape getBall();
        float getAngle();

        void move();
        void updateAngle(float angle);

    private:
        float xSpeed, ySpeed;      
};

#endif