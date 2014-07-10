//
// DynamicLib.hh for  in /home/lejard_h/cpp/DynamicLib
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Wed Mar 19 15:16:53 2014 hadrien lejard
// Last update Wed Apr  2 12:23:17 2014 hadrien lejard
//

#ifndef __DYNAMICLIB_HH__
# define __DYNAMICLIB_HH__

#include <string>
#include <exception>
#include <dlfcn.h>

class DynamicLib
{
private:
  class DynamicLibException : public std::exception
  {
  public:
    DynamicLibException(std::string const &);
    virtual ~DynamicLibException() throw ();
    virtual const char	*what() const throw();
  private:
    std::string	_msg;
  };
  void	*_handle;
public:
  DynamicLib(std::string const &, int);
  ~DynamicLib();
  void	*symbole(std::string const &) const;
};

#endif /* !__DYNAMICLIB_HH__ */
