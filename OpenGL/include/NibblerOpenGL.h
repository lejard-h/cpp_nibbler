/*
** NibblerOpenGL.h for nibbler in /home/millon_c/Projets/NIBBLER/cpp_nibbler/OpenGL/src
** 
** Made by millon_c
** Login   <millon_c@epitech.net>
** 
** Started on  Tue Apr  1 15:58:13 2014 millon_c
// Last update Wed Apr  2 14:04:02 2014 millon_c
*/

#ifndef NIBBLEROPENGL_H_
# define NIBBLEROPENGL_H_

#include <map>
#include "game.hh"
#include "map.hh"
#include "graphicalEngine.hh"
#include "OpenGL.h"
#include "snake.hh"

class NibblerOpenGL : public Graphic::IGraphicalEngine
{
public:
  NibblerOpenGL();
  virtual ~NibblerOpenGL();
  void init(unsigned int, unsigned int, Game::IGame*);
  void refresh();
  Event::IEventManager &getEventQueue();
  void quit();

private: // Attribs
  std::map<SDLKey, Event::KeyPressed> _eventsHandler; 
  unsigned int _height;
  unsigned int _width;
  Game::IGame *_game; // COntient la map et le snake
  Event::EventQueue _event;
  OpenGL *_openGL;
  // _snakeWay translate my event to -> Event::Event

private:
  void catchEvent(SDL_Event*);
  void affSnake(Game::SnakeElement*);
  void displayMap() const;
  void displaySnake() const;
  
};


#endif
