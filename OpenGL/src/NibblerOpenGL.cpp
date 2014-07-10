//
// NibblerOpenGL.cpp for nibbler in /home/millon_c/Projets/NIBBLER/cpp_nibbler/OpenGL/src
//
// Made by millon_c
// Login   <millon_c@epitech.net>
//
// Started on  Tue Apr  1 15:54:56 2014 millon_c
// Last update Sun Apr  6 14:03:25 2014 hadrien lejard
//

#include <algorithm>
#include <functional>
#include "NibblerOpenGL.h"

NibblerOpenGL::NibblerOpenGL()
{
  _eventsHandler[SDLK_UP] = Event::keyUp;
  _eventsHandler[SDLK_DOWN] = Event::keyDown;
  _eventsHandler[SDLK_RIGHT] = Event::keyRight;
  _eventsHandler[SDLK_LEFT] = Event::keyLeft;
  _eventsHandler[SDLK_ESCAPE] = Event::keyEscape;
}

NibblerOpenGL::~NibblerOpenGL()
{
}

void NibblerOpenGL::init(unsigned int height, unsigned int width, Game::IGame* game)
{
  this->_height = height * 10;
  this->_width = width * 10;
  this->_game = game;
  this->_openGL = new OpenGL();

  _openGL->createWin(this->_height, this->_width);
}

void NibblerOpenGL::catchEvent(SDL_Event *event)
{
  SDLKey key;

  if (event == NULL)
    return;
  if (event->type == SDL_QUIT)
    {
      this->getEventQueue().pushEvent(new Event::Event(Event::keyEscape));
      return;
    }
  key = event->key.keysym.sym;
  if (_eventsHandler.find(key) != _eventsHandler.end())
    this->getEventQueue().pushEvent(new Event::Event(this->_eventsHandler[key]));

}

void NibblerOpenGL::refresh()
{
  displayMap();
  displaySnake();
  this->_openGL->printWin();

  catchEvent(this->_openGL->getEvent());
}

Event::IEventManager &NibblerOpenGL::getEventQueue()
{
  return this->_event;
}

void NibblerOpenGL::quit()
{
  this->_openGL->closeWin();
  delete this->_openGL;
}

void NibblerOpenGL::displayMap() const
{
  Game::Map *map = _game->getMap();
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned char color_wall[3] = {255, 255, 255};
  unsigned char color_food[3] = {255, 0, 0};

  while (x < this->_height)
    {
      while (y < this->_width)
	{
	  if (map->getCell(x / 10, y / 10) == Game::tWall)
	    this->_openGL->printSquare(y, x, 10, color_wall);
	  else if (map->getCell(x / 10, y / 10) == Game::tFood)
	    this->_openGL->printSquare(y, x, 10, color_food);
	  y += 10;
	}
      y = 0;
      x += 10;
    }
}

void NibblerOpenGL::affSnake(Game::SnakeElement *elem)
{
  unsigned char color_snake[3] = {0, 255, 0};
  const unsigned int *snake_pos = elem->getPos();

  this->_openGL->printSquare(snake_pos[1] * 10, snake_pos[0] * 10, 10, color_snake);
}

void NibblerOpenGL::displaySnake() const
{
  Game::Snake *snake = _game->getSnake();

  std::for_each(snake->getList().begin(), snake->getList().end(),
		std::bind1st(std::mem_fun(&NibblerOpenGL::affSnake), this));
}

extern "C"
{
  Graphic::IGraphicalEngine *createInstance()
  {
    return new NibblerOpenGL();
  }
}
