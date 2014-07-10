//
// snake.hh for  in /home/lejard_h/projects/nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 22:06:59 2014 hadrien lejard
// Last update Sun Mar 30 19:44:18 2014 hadrien lejard
//

#ifndef __SNAKE_HH__
# define __SNAKE_HH__

#include <exception>
#include <list>
#include "game.hh"

namespace Game
{
  class SnakeElement
  {
  private:
    unsigned int	_pos[2];
    unsigned int	_lastpos[2];
  public:
    SnakeElement(unsigned int, unsigned int);
    ~SnakeElement(void);
    void	setLastPos(unsigned int, unsigned int);
    void	setPos(unsigned int, unsigned int);
    unsigned int const	*getPos(void) const;
    unsigned int const	*getLastPos(void) const;
  };

  class Snake
  {
  private:
    std::list<SnakeElement *>	_snake;
    enum SnakeState		_way;
    void	updateList(unsigned int, unsigned int);
  public:
    Snake(unsigned int, unsigned int);
    ~Snake(void);
    std::list<SnakeElement *> const &getList(void) const;
    void		setWay(enum SnakeState);
    enum SnakeState	getWay(void) const;
    void		eat(void);
    void		run(void);
    unsigned int const	*getHeadPos(void);
  };
}


#endif /* !__SNAKE_HH__ */
