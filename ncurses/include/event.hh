//
// event.hh for  in /home/lejard_h/projects/nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 23:19:30 2014 hadrien lejard
// Last update Fri Mar 28 16:33:35 2014 hadrien lejard
//

#ifndef __EVENT_HH__
# define __EVENT_HH__

#include <queue>

namespace Event
{
  enum KeyPressed { keyUp, keyDown, keyRight, keyLeft, keyEscape };
  class Event
  {
  public:
    Event(enum KeyPressed);
    ~Event();
    enum KeyPressed	getKeyPressed() const;
  private:
    const enum KeyPressed	_key;
  };

  class IEventManager
  {
  public:
    virtual Event const &popEvent(void) = 0;
    virtual void	pushEvent(Event *) = 0;
    virtual bool	isEvent(void) const = 0;
    virtual ~IEventManager() {};
  };

  class EventQueue : public IEventManager
  {
  private:
    std::queue<Event *>	_queue;
  public:
    EventQueue();
    ~EventQueue();
    bool	isEvent(void) const;
    Event const &popEvent(void);
    void	pushEvent(Event *);
  };
}

#endif /* !__EVENT_HH__ */
