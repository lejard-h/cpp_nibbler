//
// text.cpp for plop in /home/roche_d/rendu/cpp_nibbler/SFML
// 
// Made by roche_d
// Login   <roche_d@epitech.net>
// 
// Started on  Wed Apr  2 12:39:53 2014 roche_d
// Last update Thu Apr  3 13:29:50 2014 roche_d
//

#include <SFML/Graphics.hpp>

int	main(void)
{
  sf::RenderWindow	window(sf::VideoMode(200, 200), "SFML");
  sf::CircleShape	shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
    {
      sf::Event	event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
      window.clear();
      window.draw(shape);
      window.display();
    }
  
  return (0);
}
