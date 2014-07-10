//
// snake.cpp for  in /home/lejard_h/projects/nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 22:35:42 2014 hadrien lejard
// Last update Sat Apr  5 16:27:35 2014 hadrien lejard
//

#include <iostream>
#include "game.hh"
#include "snake.hh"

Game::Snake::Snake(unsigned int x, unsigned int y)
{
  this->_way = Right;
  this->_snake.push_back(new SnakeElement(x, y));
  this->_snake.push_back(new SnakeElement(x, y - 1));
  this->_snake.push_back(new SnakeElement(x, y - 2));
  this->_snake.push_back(new SnakeElement(x, y - 3));
}

Game::Snake::~Snake(void)
{
  for (std::list<SnakeElement*>::const_iterator it = this->_snake.begin(); it != this->_snake.end(); ++it)
    delete *it;
}

std::list<Game::SnakeElement *> const &Game::Snake::getList(void) const
{
  return (this->_snake);
}

void	Game::Snake::setWay(enum SnakeState way)
{
  if (way == Right)
    {
      if (this->_way == Right)
	this->_way = Down;
      else if (this->_way == Up)
	this->_way = Right;
      else if (this->_way == Down)
	this->_way = Left;
      else
	this->_way = Up;
    }
  else if (way == Left)
    {
      if (this->_way == Right)
	this->_way = Up;
      else if (this->_way == Up)
	this->_way = Left;
      else if (this->_way == Down)
	this->_way = Right;
      else
	this->_way = Down;
    }
}

enum Game::SnakeState	Game::Snake::getWay(void) const
{
  return (this->_way);
}

void	Game::Snake::eat(void)
{
  SnakeElement	*end = this->_snake.back();
  unsigned int const *tab = end->getLastPos();

  this->_snake.push_back(new SnakeElement(tab[0], tab[1]));
}

unsigned int const	*Game::Snake::getHeadPos(void)
{
  SnakeElement	*head = *(this->_snake.begin());
  return (head->getPos());
}

void	Game::Snake::run(void)
{
  SnakeElement	*head = *(this->_snake.begin());
  unsigned int	x = head->getPos()[0];
  unsigned int	y = head->getPos()[1];

  if (getWay() == Right)
    y++;
  else if (getWay() == Left)
    y--;
  else if (getWay() == Up)
    x--;
  else if (getWay() == Down)
    x++;
  updateList(x, y);
}

void	Game::Snake::updateList(unsigned int x, unsigned int y)
{
  for (std::list<SnakeElement*>::const_iterator it = this->_snake.begin(); it != this->_snake.end(); ++it)
    {
      (*it)->setPos(x, y);
      x = (*it)->getLastPos()[0];
      y = (*it)->getLastPos()[1];
    }
}

void	Game::SnakeElement::setLastPos(unsigned int x, unsigned int y)
{
  this->_lastpos[0] = x;
  this->_lastpos[1] = y;
}

Game::SnakeElement::SnakeElement(unsigned int x, unsigned int y)
{
  setPos(x, y);
}

Game::SnakeElement::~SnakeElement(void)
{
}

void	Game::SnakeElement::setPos(unsigned int x, unsigned int y)
{
  setLastPos(this->_pos[0], this->_pos[1]);
  this->_pos[0] = x;
  this->_pos[1] = y;
}

unsigned int const *Game::SnakeElement::getLastPos(void) const
{
  return (this->_lastpos);
}

unsigned int const *Game::SnakeElement::getPos(void) const
{
  return (this->_pos);
}
