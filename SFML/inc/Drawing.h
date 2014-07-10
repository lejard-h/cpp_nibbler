/*
** Drawing.h for nibbler in /home/roche_d/rendu/cpp_nibbler/SFML
** 
** Made by roche_d
** Login   <roche_d@epitech.net>
** 
** Started on  Thu Apr  3 10:30:31 2014 roche_d
** Last update Thu Apr  3 10:56:25 2014 roche_d
*/

#ifndef DRAWING_H_
# define DRAWING_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class DrawingSFML
{
 public:
  static void	drawSquare(sf::RenderWindow *, int x, int y, sf::Color);
};

#endif
