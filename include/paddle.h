#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class  Paddle {
    public:
        Paddle() {};
        Paddle(float xPos, float yPos);

        void moveUp();
        void moveDown(); 

        sf::Vector2f position;  
        sf::RectangleShape getPaddle(); 
        sf::Vector2f getSize(); 
        
    private:
        float xPos, yPos;
        float speed;
        sf::RectangleShape paddle;   
};

#endif