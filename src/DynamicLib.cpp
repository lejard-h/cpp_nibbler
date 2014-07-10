//
// DynamicLib.cpp for  in /home/lejard_h/cpp/DynamicLib
//
// Made by hadrien lejard
// Login   <lejard_h@epitech.net>
//
// Started on  Wed Mar 19 15:16:38 2014 hadrien lejard
// Last update Wed Apr  2 11:53:05 2014 hadrien lejard
//

#include <string>
#include <dlfcn.h>
#include "DynamicLib.hh"

DynamicLib::DynamicLib(std::string const &fileName, int flags)
{
  this->_handle = dlopen(("./" + fileName).c_str(), flags);
  if (!this->_handle)
    throw DynamicLibException(dlerror());
}

DynamicLib::~DynamicLib()
{
  if (dlclose(this->_handle))
    throw DynamicLibException(dlerror());
}

void	*DynamicLib::symbole(std::string const &symName) const
{
  void	*sym;
  char	*error;

  sym = dlsym(this->_handle, symName.c_str());
  if ((error = dlerror()))
    throw DynamicLibException(error);
  return (sym);
}


DynamicLib::DynamicLibException::DynamicLibException(std::string const &msg) : _msg(msg)
{
}

DynamicLib::DynamicLibException::~DynamicLibException() throw()
{
}

const char	*DynamicLib::DynamicLibException::what() const throw()
{
  return _msg.c_str();
}
