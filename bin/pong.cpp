/* 
 * Seth Layton
 * CSCI 437 - Pong
 * Due 9/16/19, 12:00 P.M.
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "paddle.h"
#include "ball.h"

using namespace std;

int main(int argc, char** argv)
{
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Seth Layton - Pong");

  sf::Font bitFont;
  if (!bitFont.loadFromFile("/Users/Seth/Desktop/pong/resources/bit5x3.ttf")) {
    cout << "Error loading file.";
  }

  bool isPlaying = false;
  float randY, startAngle;
  float pi = 3.14159f;

  //Initalize Player1 and Computer Paddles
  Paddle p1(10, App.getSize().y/2 - 35);
  Paddle computer(App.getSize().x - p1.getSize().x - 10, App.getSize().y/2 - 35);

  //Initialize Ball (in random location)
  srand(time(NULL));
  randY = float(rand() % 600);
  Ball ball(App.getSize().x/2 - 3, randY);

  //Initialize Half-Court Lines


  //Initalize Text Objects
  sf::Text beginMsg;
  beginMsg.setFont(bitFont);
  beginMsg.setCharacterSize(24);
  beginMsg.setFillColor(sf::Color::White);
  beginMsg.setPosition(App.getSize().x/2, App.getSize().y - 50);
  beginMsg.setString("Press space bar to begin.");
  
  while(App.isOpen()) {

    sf::Event Event;

    while(App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed) App.close();
    }

    if (!isPlaying) {
      if (Event.key.code == sf::Keyboard::Space) {
        isPlaying = true;
        beginMsg.setFillColor(sf::Color::Black);

        //fix this
        startAngle = float((rand() % 180) * 2 * pi / 360);
        ball.updateAngle(startAngle);
      }
    }

    else {
      if (Event.type == sf::Event::KeyPressed) {
        if ((Event.key.code == sf::Keyboard::Up) && (p1.position.y >= 0)) p1.moveUp();
        if ((Event.key.code == sf::Keyboard::Down) && (p1.position.y <= App.getSize().y - p1.getSize().y)) p1.moveDown();
        if ((Event.key.code == sf::Keyboard::Up) && (computer.position.y >= 0)) computer.moveUp();
        if ((Event.key.code == sf::Keyboard::Down) && (computer.position.y <= App.getSize().y - computer.getSize().y)) computer.moveDown();
      }

      

      ball.move();

      //Need to implement if there is a loss

      //If ball hits top wall
      if (ball.getBall().getPosition().y < 0) {
        ball.updateAngle(-ball.getAngle());
        ball.getBall().setPosition(ball.getBall().getPosition().x, 7);
      }
      
      //If ball hits bottom wall
      if (ball.getBall().getPosition().y > App.getSize().y) {
        ball.updateAngle(-ball.getAngle());
        ball.getBall().setPosition(ball.getBall().getPosition().x, App.getSize().y - 7);
      }

      //If ball hits p1 paddle
      if (ball.getBall().getPosition().y >= p1.position.y - p1.getPaddle().getSize().y/2 && 
          ball.getBall().getPosition().y <= p1.position.y + p1.getPaddle().getSize().y/2 &&
          ball.getBall().getPosition().x <= p1.position.x + p1.getPaddle().getSize().x) {
            
            ball.updateAngle(ball.getAngle() + (rand() % 10) * 180);
            //Random perturbation
            // if (ball.getBall().getPosition().y > p1.position.y) {
              
            // }

            // else {
            //   ball.updateAngle(ball.getAngle() - (rand() % 10) * 180);
            // }
        ball.getBall().setPosition(ball.getBall().getPosition().x + 1, ball.getBall().getPosition().y);
      }

      if (ball.getBall().getPosition().y <= computer.position.y + p1.getPaddle().getSize().y/2 && 
          ball.getBall().getPosition().y >= computer.position.y - p1.getPaddle().getSize().y/2 &&
          ball.getBall().getPosition().x >= computer.position.x) {
            ball.updateAngle(ball.getAngle() + (rand() % 10) * 180);
            //Random perturbation
            // if (ball.getBall().getPosition().y > computer.position.y) {
              
            // }

            // else {
            //   ball.updateAngle(ball.getAngle() - (rand() % 10) * 180);
            // }
        ball.getBall().setPosition(ball.getBall().getPosition().x - 1, ball.getBall().getPosition().y);
      }
    }

    App.clear(sf::Color::Black);

    if (isPlaying) {
      App.draw(p1.getPaddle());
      App.draw(computer.getPaddle());
      App.draw(ball.getBall());
      App.display();
    }
    else {
      App.draw(p1.getPaddle());
      App.draw(computer.getPaddle());
      App.draw(ball.getBall());
      App.draw(beginMsg);
      App.display();
    }
  }
    
  return 0;
}