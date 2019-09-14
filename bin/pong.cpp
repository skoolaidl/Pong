/* 
 * Seth Layton
 * CSCI 437 - Pong
 * Due 9/16/19
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "paddle.h"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Seth Layton - Pong");

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    Paddle p1(20,300);

    // clear screen and fill with blue
    App.clear(sf::Color::Black);

    App.draw(p1.getPaddle());

    // display
    App.display();
  }

  // Done.
  return 0;
}