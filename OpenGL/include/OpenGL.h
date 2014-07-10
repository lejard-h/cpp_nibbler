/*
** OpenGL.h for nibbler in /home/millon_c/Projets/NIBBLER/cpp_nibbler/OpenGL
** 
** Made by millon_c
** Login   <millon_c@epitech.net>
** 
** Started on  Tue Apr  1 17:29:48 2014 millon_c
// Last update Wed Apr  2 14:42:00 2014 millon_c
*/

#ifndef OPENGL_H_
# define OPENGL_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <exception>
#include <string>

class OpenGLException : public std::exception
{
 public:
  OpenGLException(std::string const &);
  virtual ~OpenGLException() throw ();
  virtual const char *what() const throw();
private:
  std::string _msg;
};

class OpenGL
{
public:
  OpenGL();
  ~OpenGL();
  void createWin(unsigned int, unsigned int); // throw exception on fail
  void printSquare(unsigned int, unsigned int, unsigned int, unsigned char*); // height, width, size, color
  void closeWin(); // close win
  SDL_Event *getEvent(); // getevent un poll event koa
  void printWin();

 private:
  void init_OpenGL(unsigned int, unsigned int);
};


#endif
