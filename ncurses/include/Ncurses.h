/*
 * File:   Ncurses.h
 * Author: lejard_h
 *
 * Created on March 29, 2014, 7:47 PM
 */

#ifndef NCURSES_H
#define	NCURSES_H

#include <ncurses.h>
#include <string>
#include <exception>

class NcursesException : public std::exception
{
 public:
  NcursesException(std::string const &);
  virtual ~NcursesException() throw ();
  virtual const char	*what() const throw();
 private:
  std::string	_msg;
};

class Ncurses
{
public:
  Ncurses();
  virtual ~Ncurses();
  void    init(unsigned int, unsigned int);
  void    refreshWindow(void) const;
  int     getchar(void) const;
  void    clearWindow(void) const;
  void    printChar(int, int, const chtype)const;
  void    cbreakMode() const;
  void    ntimeout(int) const;
  void    checkSize(void) const;
  void	  keypading(bool) const;
  void    cursor(int) const;
  void    getSizeWindow(int *, int *) const;
  void    colorStart(void) const;
  void    initColor(short, short, short) const;
  void    setColor(int) const;
private:
  WINDOW  *_window;
  unsigned int _height;
  unsigned int _width;
};

#endif	/* NCURSES_H */
