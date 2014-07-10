/*
 * File:   NibblerNcurses.cpp
 * Author: lejard_h
 *
 * Created on March 29, 2014, 11:44 PM
 */

#include <iostream>
#include <unistd.h>
#include <list>
#include "map.hh"
#include "snake.hh"
#include "Ncurses.h"
#include "NibblerNcurses.h"
#include "event.hh"
#include "graphicalEngine.hh"


NibblerNcurses::NibblerNcurses()
{
  this->_snakeWay[KEY_UP] = Event::keyUp;
  this->_snakeWay[KEY_DOWN] = Event::keyDown;
  this->_snakeWay[KEY_RIGHT] = Event::keyRight;
  this->_snakeWay[KEY_LEFT] = Event::keyLeft;
  this->_snakeWay[27] = Event::keyEscape;

  this->_ncurses = new Ncurses;
}

NibblerNcurses::~NibblerNcurses()
{
  if (this->_ncurses)
    delete this->_ncurses;
}

bool                NibblerNcurses::checkSize(void) const
{
  int   size[2];

  this->_ncurses->getSizeWindow(&size[0], &size[1]);
  if (size[0] < (int) this->_height || size[1] < (int) this->_width)
    return false;
  return true;
}

void                NibblerNcurses::init(unsigned int height, unsigned int width, Game::IGame *game)
{
  this->_ncurses->init(height, width);
  this->_game = game;
  this->_height = height;
  this->_width = width;

  this->_ncurses->keypading(true);
  this->_ncurses->ntimeout(0);
  this->_ncurses->cbreakMode();
  this->_ncurses->cursor(0);

  this->_ncurses->colorStart();
  this->_ncurses->initColor(1, COLOR_RED, COLOR_BLACK);
  this->_ncurses->initColor(2, COLOR_CYAN, COLOR_BLACK);
  this->_ncurses->initColor(3, COLOR_GREEN, COLOR_BLACK);
}

void                NibblerNcurses::refresh(void)
{
  int ch = this->_ncurses->getchar();

  std::map<int,Event::KeyPressed>::const_iterator search = this->_snakeWay.find(ch);
  if(search != this->_snakeWay.end())
    this->getEventQueue().pushEvent(new Event::Event(this->_snakeWay[ch]));
  this->_ncurses->clearWindow();
  this->displayMap();
  this->displaySnake();
  this->_ncurses->refreshWindow();
}

Event::IEventManager  &NibblerNcurses::getEventQueue()
{
    return this->_events;
}

void                NibblerNcurses::quit()
{
  this->_ncurses->clearWindow();
  this->_ncurses->refreshWindow();
  delete this->_ncurses;
  this->_ncurses = 0;
}

void                NibblerNcurses::displayMap() const
{
  this->_ncurses->setColor(COLOR_PAIR(1));
  for (unsigned int i = 0; i < this->_height; ++i)
    {
      for (unsigned int a = 0; a < this->_width; ++a)
        {
	  char ch;
	  if (this->_game->getMap()->getCell(i, a) == Game::tWall)
	    ch = MAP_WALL;
	  else if (this->_game->getMap()->getCell(i, a) == Game::tFood)
	    {
	      this->_ncurses->setColor(COLOR_PAIR(2));
	      ch = MAP_FOOD;
	    }
	  else
	    ch = ' ';
	  if (!checkSize())
	    return ;
	  this->_ncurses->printChar(i, a, ch);
	  this->_ncurses->setColor(COLOR_PAIR(1));
        }
    }
}

void                NibblerNcurses::displaySnake() const
{
  this->_ncurses->setColor(COLOR_PAIR(3));
  for (std::list<Game::SnakeElement *>::const_iterator it = this->_game->getSnake()->getList().begin(); it != this->_game->getSnake()->getList().end(); ++it)
    {
      const unsigned int	*tmp = (*it)->getPos();
      if (!checkSize())
	return ;
      this->_ncurses->printChar(tmp[0], tmp[1], SNAKE);
    }
}

extern "C"
{
  Graphic::IGraphicalEngine	*createInstance(void)
  {
    return new NibblerNcurses();
  }
}
