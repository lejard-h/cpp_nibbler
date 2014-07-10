/*
 * File:   NibblerNcurses.h
 * Author: lejard_h
 *
 * Created on March 29, 2014, 11:44 PM
 */

#ifndef NIBBLERNCURSES_H
#define	NIBBLERNCURSES_H

#include <map>
#include <string>
#include "game.hh"
#include "Ncurses.h"
#include "event.hh"
#include "graphicalEngine.hh"
#include "snake.hh"

#define MAP_WALL    '#'
#define MAP_FOOD    '*'
#define SNAKE       'o'

class NibblerNcurses : public Graphic::IGraphicalEngine
{
public:
    NibblerNcurses();
    virtual ~NibblerNcurses();
    void                init(unsigned int, unsigned int, Game::IGame *);
    void                refresh(void);
    Event::IEventManager &getEventQueue(void);
    void                quit(void);
    bool                checkSize(void) const;
private:
    unsigned int        _height;
    unsigned int        _width;
    void                displayMap() const;
    void                displaySnake() const;
    Event::EventQueue   _events;
    Ncurses             *_ncurses;
    Game::IGame         *_game;
    std::map<int, Event::KeyPressed> _snakeWay;
};


#endif	/* NIBBLERNCURSES_H */
