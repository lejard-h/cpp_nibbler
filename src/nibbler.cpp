//
// nibbler.cpp for  in /home/lejard_h/projects/nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 23:28:13 2014 hadrien lejard
// Last update Sun Apr  6 21:50:05 2014 hadrien lejard
//

#include <unistd.h>
#include <iostream>
#include <string>
#include "nibbler.hh"
#include "DynamicLib.hh"
#include "event.hh"

Game::Nibbler::Nibbler(std::string const &libName)
{
  Graphic::IGraphicalEngine	*(*entry)(void);

  this->_map = 0;
  this->_snake = 0;
  this->_engine = 0;
  this->_dynamicLoad = 0;
  this->_score = 0;
  this->_timer = TIMER;
  try
    {
      this->_dynamicLoad = new DynamicLib(libName, RTLD_LAZY);

      entry = (Graphic::IGraphicalEngine *(*)(void)) this->_dynamicLoad->symbole("createInstance");
      this->_engine = entry();
    }
  catch (std::exception &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
}

Game::Nibbler::~Nibbler(void)
{
  if (this->_map)
    delete this->_map;
  if (this->_snake)
    delete this->_snake;
  if (this->_engine)
    delete this->_engine;
  if (this->_dynamicLoad)
    delete this->_dynamicLoad;
}

void	Game::Nibbler::launch(void)
{
  if (!this->_engine)
    return ;
  this->_score = 4;
  while (!snakeIsDead())
    {
      usleep(this->_timer);
      this->_engine->refresh();
      if (this->_engine->getEventQueue().isEvent())
	{
	  Event::Event lastevent = this->_engine->getEventQueue().popEvent();
	  if (lastevent.getKeyPressed() == Event::keyEscape)
	    {
	      this->_engine->quit();
	      return ;
	    }
	  else
	    getSnake()->setWay((enum SnakeState) lastevent.getKeyPressed());
	}
      getSnake()->run();
      if (snakeIsEating())
	generateFood();
    }
  this->_engine->quit();
}

void	Game::Nibbler::init(int height, int width)
{
  if (!this->_engine)
    return ;
  if (height <= 5 || width <= 5 || height > 50 || width > 50)
    throw NibblerException("size area impossible.\n\t[5 < width < 50] [5 < height < 50].");
  this->_map = new Map(height, width);
  this->_snake = new Snake((height / 2), (width / 2));
  this->_engine->init(height, width, this);
}

Game::Snake		*Game::Nibbler::getSnake(void) const
{
  return (this->_snake);
}

Game::Map		*Game::Nibbler::getMap(void) const
{
  return (this->_map);
}

Game::Nibbler::NibblerException::NibblerException(std::string const &msg) : _msg(msg)
{
}

Game::Nibbler::NibblerException::~NibblerException() throw()
{
}

const char	*Game::Nibbler::NibblerException::what() const throw()
{
  return _msg.c_str();
}

bool	Game::Nibbler::snakeIsDead(void) const
{
  const unsigned int	*snakePos = this->getSnake()->getHeadPos();

  if (this->getMap()->getCell(snakePos[0], snakePos[1]) == tWall)
    return true;

  std::list<SnakeElement *> snakeList = this->getSnake()->getList();
  std::list<SnakeElement*>::const_iterator it = snakeList.begin();
  it++;
  for (; it != snakeList.end(); ++it)
    {
      const unsigned int	*tmp = (*it)->getPos();
      if (tmp[0] == snakePos[0] && tmp[1] == snakePos[1])
	return true;
    }
  return false;
}

bool	Game::Nibbler::snakeIsEating(void)
{
  const unsigned int	*snakePos = this->getSnake()->getHeadPos();

  if (this->getMap()->getCell(snakePos[0], snakePos[1]) == tFood)
    {
      this->getMap()->setCell(snakePos[0], snakePos[1], tEmpty);
      this->getSnake()->eat();
      this->_score++;
      this->_timer -= 1000;
      return true;
    }
  return false;
}

void	Game::Nibbler::generateFood(void) const
{
  this->_map->generateFood(this->_snake);
}

int	Game::Nibbler::getScore(void) const
{
  return _score;
}
