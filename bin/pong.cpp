/* 
 * Seth Layton
 * CSCI 437 - Pong
 * Due 9/16/19, 12:00 P.M.
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "paddle.h"

int main(int argc, char** argv)
{
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Seth Layton - Pong");

  //Create Player 1, Computer, Ball, and Half-Court
  Paddle p1(20,300);
  
  while(App.isOpen()) {
    sf::Event Event;
    while(App.pollEvent(Event))
    
    if (Event.type == sf::Event::Closed) App.close();

    if (Event.type == sf::Event::KeyPressed) {
      if (Event.key.code == sf::Keyboard::Up) p1.moveUp();
      if (Event.key.code == sf::Keyboard::Down) p1.moveDown();
    }

    App.clear(sf::Color::Black);
    App.draw(p1.getPaddle());
    App.display();

    }
  return 0;
}