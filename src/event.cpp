//
// event.cpp for  in /home/lejard_h/rendu/cpp_nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Thu Mar 27 21:37:33 2014 hadrien lejard
// Last update Fri Mar 28 16:33:41 2014 hadrien lejard
//

#include "event.hh"

Event::Event::Event(enum KeyPressed newKey) : _key(newKey)
{
}

Event::Event::~Event()
{
}

Event::EventQueue::EventQueue()
{
}

Event::EventQueue::~EventQueue()
{
}

bool	Event::EventQueue::isEvent(void) const
{
  if (this->_queue.empty())
    return false;
  return true;
}

Event::Event const	&Event::EventQueue::popEvent(void)
{
  Event	*event;

  event = this->_queue.front();
  this->_queue.pop();
  return (*event);
}

void			Event::EventQueue::pushEvent(Event *event)
{
  this->_queue.push(event);
}

enum Event::KeyPressed	Event::Event::getKeyPressed(void) const
{
  return this->_key;
}
