//
// game.hh for  in /home/lejard_h/projects/nibbler/include
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 21:38:32 2014 hadrien lejard
// Last update Wed Apr  2 15:56:00 2014 hadrien lejard
//

#ifndef __GAME_HH__
# define __GAME_HH__

#include <string>

#define TIMER	50000

namespace Game
{
  class Map;
  class Snake;
  class IGame
  {
  public:
    virtual void	launch(void) = 0;
    virtual void	init(int, int) = 0;
    virtual Map         *getMap() const = 0;
    virtual Snake       *getSnake() const = 0;
    virtual int         getScore() const = 0;
    virtual ~IGame(void) {};
  };

  enum MapType { tEmpty, tWall, tFood, };
  enum SnakeState { Up, Down, Right, Left };
}

#endif /* !__GAME_HH__ */
