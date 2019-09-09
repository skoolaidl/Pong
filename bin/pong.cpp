/* 
 * Seth Layton
 * CSCI 423 - Pong
 * Due 9/16/19
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

    // clear screen and fill with blue
    App.clear(sf::Color::Black);

    sf::RectangleShape p1(sf::Vector2f(10.f, 50.f));
    p1.setFillColor(sf::Color::White);
    App.draw(p1);

    // display
    App.display();
  }

  // Done.
  return 0;
}