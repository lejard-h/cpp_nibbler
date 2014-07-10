//
// map.cpp for  in /home/lejard_h/projects/nibbler/include
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 21:48:28 2014 hadrien lejard
// Last update Sun Apr  6 21:52:39 2014 hadrien lejard
//

#include <cstdlib>
#include <ctime>
#include "map.hh"
#include "snake.hh"

Game::Map::Map(unsigned int h, unsigned int w) : _height(h), _width(w)
{
  this->_map = new char*[h];
  for (unsigned int i = 0; i < h; ++i)
    this->_map[i] = new char[w];
  for (unsigned int i = 0; i < h; ++i)
    {
      for (unsigned int a = 0; a < w; a++)
	{
	  if (i == 0 || i == h - 1 ||
	      a == 0 || a == w - 1)
	    this->_map[i][a] = tWall;
	  else
	    this->_map[i][a] = tEmpty;
	}
    }
  generateFood(0);
}

Game::Map::~Map(void)
{
  for (unsigned int i = 0; i < this->_height; ++i)
    delete []this->_map[i];
  delete []this->_map;
}

char	Game::Map::getCell(unsigned int x, unsigned int y) const
{
  if (x >= this->_height || y >= this->_width)
    throw MapException("Bad coord.");
  return (this->_map[x][y]);
}

void	Game::Map::setCell(unsigned int x, unsigned int y, enum MapType type)
{
  if (x >= this->_height || y >= this->_width)
    throw MapException("Bad coord.");
  this->_map[x][y] = type;
}

Game::Map::MapException::MapException(std::string const &msg) : _msg(msg)
{
}

Game::Map::MapException::~MapException() throw()
{
}

const char	*Game::Map::MapException::what() const throw()
{
  return _msg.c_str();
}

void	Game::Map::generateFood(Snake const *snake)
{
  int	ntry = 0;
  bool	state;
  unsigned int x;
  unsigned int y;

  srand(time(0));
  state = false;
  while (state == false && ntry < 1000)
    {
      x = rand() % (this->_height - 1) + 1;
      y = rand() % (this->_width - 1) + 1;
      state = true;
      if (getCell(x, y) != tEmpty)
	state = false;
      if (snake)
	{
	  for (std::list<SnakeElement*>::const_iterator it = snake->getList().begin(); it != snake->getList().end(); ++it)
	    {
	      if (x == (*it)->getPos()[0] && y == (*it)->getPos()[1])
		state = false;
	    }
	}
      ntry++;
    }
  if (ntry == 1000)
    throw MapException("Impossible to generate food.");
  setCell(x, y, tFood);
}
