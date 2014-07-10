//
// Drawing.cpp for nibbler in /home/roche_d/rendu/cpp_nibbler/SFML
// 
// Made by roche_d
// Login   <roche_d@epitech.net>
// 
// Started on  Thu Apr  3 10:28:45 2014 roche_d
// Last update Thu Apr  3 13:05:29 2014 roche_d
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Drawing.h"

void	DrawingSFML::drawSquare(sf::RenderWindow *w, int x, int y, sf::Color col)
{
  sf::RectangleShape	sq(sf::Vector2f(10, 10));

  sq.setFillColor(col);
  sq.setPosition(x, y);
  if (w)
    w->draw(sq);
}
