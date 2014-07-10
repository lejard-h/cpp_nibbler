/*
 * File:   Ncurses.cpp
 * Author: lejard_h
 *
 * Created on March 29, 2014, 7:47 PM
 */

#include <csignal>
#include <ncurses.h>
#include "Ncurses.h"

Ncurses::Ncurses()
{
  this->_height = 0;
  this->_width = 0;
  this->_window = 0;
}

Ncurses::~Ncurses()
{
  if (this->_window && endwin() == ERR)
    throw NcursesException("endwin failed.");
}

void	  Ncurses::keypading(bool state) const
{
  if (keypad(this->_window, (char) state) == ERR)
    throw NcursesException("keypad failed.");
}

void    Ncurses::checkSize(void) const
{

}

void    Ncurses::init(unsigned int height, unsigned int width)
{
  if (!(this->_window = initscr()))
    throw NcursesException("initscr failed.");
  this->_height = height;
  this->_width = width;
}

NcursesException::NcursesException(std::string const &msg) : _msg(msg)
{
}

NcursesException::~NcursesException() throw()
{
}

const char	*NcursesException::what() const throw()
{
  return _msg.c_str();
}

void     Ncurses::refreshWindow() const
{
    if (wrefresh(this->_window) == ERR)
        throw NcursesException("refresh failed.");
}

int     Ncurses::getchar() const
{
    return wgetch(this->_window);
}

void     Ncurses::clearWindow(void) const
{
    if (wclear(this->_window) == ERR)
        throw NcursesException("clear failed.");
}

void    Ncurses::printChar(int x, int y, const chtype ch) const
{
    if (mvwaddch(this->_window, x, y, ch) == ERR)
        throw NcursesException("print failed.");
}

void    Ncurses::cbreakMode() const
{
    if (cbreak() == ERR)
        throw NcursesException("cbreak failed.");
}

void    Ncurses::ntimeout(int t) const
{
    wtimeout(this->_window, t);
}

void    Ncurses::cursor(int set) const
{
  if (curs_set(set) == ERR)
    throw NcursesException("curs_set failed.");
}

void    Ncurses::getSizeWindow(int *x, int *y) const
{
  getmaxyx(this->_window, *y, *x);
}

void    Ncurses::colorStart(void) const
{
  if (start_color() == ERR)
    throw NcursesException("start_color failed.");
}

void    Ncurses::initColor(short a, short b, short c) const
{
  if (init_pair(a, b, c) == ERR)
    throw NcursesException("init_pari failed.");
}

void    Ncurses::setColor(int color) const
{
  if (wattrset(this->_window, color) == ERR)
    throw NcursesException("wattrset failed.");
}
