//
// main.cpp for  in /home/lejard_h/projects/nibbler
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Tue Mar 25 22:52:33 2014 hadrien lejard
// Last update Sun Apr  6 21:49:33 2014 hadrien lejard
//

#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "game.hh"
#include "nibbler.hh"

int	main(int ac, char **av)
{
  if (ac == 4)
    {
      Game::Nibbler	game(av[3]);
      std::istringstream buffer1(av[1]);
      std::istringstream buffer2(av[2]);
      int height;
      int width;

      buffer1 >> width;
      buffer2 >> height;
      try
	{
	  game.init(height, width);
	  game.launch();
	}
      catch (std::exception &e)
	{
	  std::cerr << "Error : " << e.what() << std::endl;
	  return (1);
	}
      std::cout << "Score :" << std::endl << game.getScore() << std::endl;
      return (0);
    }
  std::cerr << "Usage: ./nibbler [5 < width < 50] [5 < height < 50] libgraphic.so" << std::endl;
  return (1);
}
