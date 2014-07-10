//
// graphicalEngine.hh for  in /home/lejard_h/projects/nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 23:18:59 2014 hadrien lejard
// Last update Sat Mar 29 13:49:48 2014 hadrien lejard
//

#ifndef __GRAPHICALENGINE_H__
# define __GRAPHICALENGINE_H__

#include "event.hh"
#include "game.hh"

namespace Graphic
{
  class IGraphicalEngine
  {
  public:
    virtual void		init(unsigned int, unsigned int, Game::IGame *) = 0;
    virtual void		refresh(void) = 0;
    virtual Event::IEventManager &getEventQueue() = 0;
    virtual void		quit(void) = 0;
    virtual ~IGraphicalEngine() {};
  };
}

#endif /* !__GRAPHICALENGINE_H__ */
