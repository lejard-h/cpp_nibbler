/*
** NibblerSFML.h for nibbler in /home/roche_d/rendu/cpp_nibbler/SFML
**
** Made by roche_d
** Login   <roche_d@epitech.net>
**
** Started on  Wed Apr  2 12:57:55 2014 roche_d
** Last update Sun Apr  6 18:47:55 2014 hadrien lejard
*/

#ifndef NIBBLERSFML_H_
# define NIBBLERSFML_H_

#include <exception>
#include <map>
#include <SFML/Graphics.hpp>
#include "event.hh"
#include "game.hh"
#include "graphicalEngine.hh"

class NibblerSFMLException : public std::exception
{
 public:
  NibblerSFMLException(std::string const &);
  virtual ~NibblerSFMLException() throw ();
  virtual const char	*what() const throw();
 private:
  std::string	_msg;
};

class NibblerSFML : public Graphic::IGraphicalEngine
{
 public:
  NibblerSFML(void);
  virtual ~NibblerSFML(void);

  void			init(unsigned int, unsigned int, Game::IGame *);
  void			refresh(void);
  Event::IEventManager	&getEventQueue(void);
  void			quit(void);

 protected:
  void			drawMap(void) const;
  void			drawSnake(void) const;
  void			drawSnakeElem(void) const;
  void			eventLoop(void);

 private:
  unsigned int						_height;
  unsigned int						_width;
  Game::IGame						*_game;
  Event::EventQueue					_eventQueue;
  sf::RenderWindow					*_window;
  std::map<sf::Keyboard::Key, Event::KeyPressed>	_snakeEvent;
};

#endif
