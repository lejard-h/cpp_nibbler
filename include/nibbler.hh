//
// nibbler.hh for  in /home/lejard_h/projects/nibbler/include
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 21:43:21 2014 hadrien lejard
// Last update Wed Apr  2 15:56:27 2014 hadrien lejard
//

#ifndef __NIBBLER_HH__
# define __NIBBLER_HH__

#include <string>
#include <exception>
#include "game.hh"
#include "snake.hh"
#include "map.hh"
#include "graphicalEngine.hh"
#include "DynamicLib.hh"


namespace Game
{
  class Nibbler : public IGame
  {
  private:
      class NibblerException : public std::exception
      {
      public:
	NibblerException(std::string const &);
	virtual ~NibblerException() throw ();
	virtual const char	*what() const throw();
      private:
	std::string	_msg;
      };

    Snake	*_snake;
    Map		*_map;
    Graphic::IGraphicalEngine	*_engine;
    DynamicLib  *_dynamicLoad;
    int		_score;
    int		_timer;
  public:
    Nibbler(std::string const &);
    virtual ~Nibbler(void);
    void	launch(void);
    void	init(int, int);

    int		getScore(void) const;
    Snake	*getSnake(void) const;
    Map		*getMap(void) const;
    bool	snakeIsDead(void) const;
    bool	snakeIsEating(void);
    void	generateFood(void) const;
  };
}

#endif /* !__NIBBLER_HH__ */
