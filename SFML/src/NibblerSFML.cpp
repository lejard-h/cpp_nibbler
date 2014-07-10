//
// NibblerSFML.cpp for nibbler in /home/roche_d/rendu/cpp_nibbler/SFML
//
// Made by roche_d
// Login   <roche_d@epitech.net>
//
// Started on  Wed Apr  2 13:03:23 2014 roche_d
// Last update Sun Apr  6 18:55:58 2014 hadrien lejard
//

#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <SFML/Window.hpp>
#include <cstring>
#include <cstdlib>
#include "map.hh"
#include "event.hh"
#include "Drawing.h"
#include "NibblerSFML.h"

extern char **environ;

NibblerSFML::NibblerSFML(void)
{
  _game = 0;
  _snakeEvent[sf::Keyboard::Escape] = Event::keyEscape;
  _snakeEvent[sf::Keyboard::Left] = Event::keyLeft;
  _snakeEvent[sf::Keyboard::Up] = Event::keyUp;
  _snakeEvent[sf::Keyboard::Down] = Event::keyDown;
  _snakeEvent[sf::Keyboard::Right] = Event::keyRight;
}

NibblerSFML::~NibblerSFML(void)
{
}

void	NibblerSFML::init(unsigned int h, unsigned int w, Game::IGame *gamePtr)
{
  if (!environ || !*environ || !getenv("DISPLAY") || strcmp(getenv("DISPLAY"), ":0"))
    throw NibblerSFMLException("Failed to open window.");
  _window = new sf::RenderWindow(sf::VideoMode(10 * w, 10 * h), "Nibbler SFML");
  _window->setVerticalSyncEnabled(true);
  _window->setKeyRepeatEnabled(false);
  _height = h;
  _width = w;
  _game = gamePtr;
}

void	NibblerSFML::refresh(void)
{
  _window->clear();
  eventLoop();
  drawMap();
  drawSnake();
  _window->display();
}

Event::IEventManager	&NibblerSFML::getEventQueue(void)
{
  return (_eventQueue);
}

void	NibblerSFML::quit(void)
{
  delete _window;
}

void	NibblerSFML::drawMap(void) const
{
  Game::Map	*map = _game->getMap();
  unsigned int	x = 0;
  unsigned int	y = 0;
  char		cur;

  while (y < _height * 10)
    {
      while (x < _width * 10)
	{
	  cur = map->getCell(y / 10, x / 10);
	  if (cur == Game::tWall)
	    DrawingSFML::drawSquare(_window, x, y, sf::Color(255, 255, 255));
	  else if (cur == Game::tFood)
	    DrawingSFML::drawSquare(_window, x, y, sf::Color(255, 0, 0));
	  x += 10;
	}
      x = 0;
      y += 10;
    }
}

void	NibblerSFML::drawSnake(void) const
{
  Game::Snake	*snake = _game->getSnake();

  for (std::list<Game::SnakeElement *>::const_iterator it = snake->getList().begin(); it != snake->getList().end(); ++it)
    {
      const unsigned int	*pos = (*it)->getPos();
      DrawingSFML::drawSquare(_window, pos[1] * 10, pos[0] * 10, sf::Color(0, 255, 0));
    }
}

void		NibblerSFML::eventLoop(void)
{
  sf::Event	event;
  std::map<sf::Keyboard::Key, Event::KeyPressed>::const_iterator it = _snakeEvent.begin();

  while (_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	_eventQueue.pushEvent(new Event::Event(Event::keyEscape));
      while (it != _snakeEvent.end())
	{
	  if (event.type == sf::Event::KeyPressed && event.key.code == it->first)
	    {
	      _eventQueue.pushEvent(new Event::Event(it->second));
	      return ;
	    }
	  ++it;
	}
      it = _snakeEvent.begin();
    }
}

NibblerSFMLException::NibblerSFMLException(std::string const &msg) : _msg(msg)
{
}

NibblerSFMLException::~NibblerSFMLException() throw()
{
}

const char	*NibblerSFMLException::what() const throw()
{
  return _msg.c_str();
}

extern "C"
{
  Graphic::IGraphicalEngine	*createInstance(void)
  {
    return (new NibblerSFML);
  }
}
