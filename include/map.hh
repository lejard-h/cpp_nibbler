//
// map.hh for  in /home/lejard_h/projects/nibbler/include
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 21:44:32 2014 hadrien lejard
// Last update Sun Apr  6 19:08:53 2014 hadrien lejard
//

#ifndef __MAP_HH__
# define __MAP_HH__

#include <exception>
#include "game.hh"
#include "snake.hh"

namespace Game
{
  class Map
  {
  private:
    class MapException : public std::exception
    {
    public:
      MapException(std::string const &);
      virtual ~MapException() throw ();
      virtual const char	*what() const throw();
    private:
      std::string	_msg;
    };

    char		**_map;
    const unsigned int	_height;
    const unsigned int	_width;
  public:
    Map(unsigned int, unsigned int);
    ~Map(void);
    char	getCell(unsigned int, unsigned int) const;
    void	setCell(unsigned int, unsigned int, enum MapType);
    void	generateFood(Snake const *);
  };
}

#endif /* !__MAP_HH__ */
