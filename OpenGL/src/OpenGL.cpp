//
// OpenGL.cpp for nibbler in /home/millon_c/Projets/NIBBLER/cpp_nibbler/OpenGL/src
//
// Made by millon_c
// Login   <millon_c@epitech.net>
//
// Started on  Tue Apr  1 15:54:38 2014 millon_c
// Last update Sun Apr  6 18:52:08 2014 hadrien lejard
//

#include "OpenGL.h"

OpenGL::OpenGL()
{
}

OpenGL::~OpenGL()
{
}

OpenGLException::OpenGLException(std::string const &msg) : _msg(msg)
{
}

OpenGLException::~OpenGLException() throw ()
{
}

const char *OpenGLException::what() const throw()
{
  return _msg.c_str();
}

void OpenGL::init_OpenGL(unsigned int height, unsigned int width)
{
  glLoadIdentity();
  glOrtho(0, height, width, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL::createWin(unsigned int height, unsigned int width)
{
  SDL_Surface* win = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw OpenGLException("Failed to open window.");
  if ((win = SDL_SetVideoMode(width, height, 32, SDL_OPENGL)) == NULL)
    throw OpenGLException("Failed to open window.");
  SDL_Flip(win);
  init_OpenGL(width, height);
  SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
  SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
  SDL_EventState(SDL_KEYUP, SDL_IGNORE);
  SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
}

void OpenGL::printWin()
{
  SDL_GL_SwapBuffers();
  glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL::printSquare(unsigned int x, unsigned int y, unsigned int size, unsigned char *color)
{
  glBegin(GL_QUADS);
  glColor3ub(color[0], color[1], color[2]);
  glVertex2f(x, y);
  glVertex2f(x + size, y);
  glVertex2f(x + size, y + size);
  glVertex2f(x, y + size);
  glEnd();
  glFlush();
}

void OpenGL::closeWin()
{
  SDL_Quit();
}

SDL_Event *OpenGL::getEvent()
{
  static SDL_Event event;

  if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	{
	  closeWin();
	}
      else if (event.type != SDL_KEYDOWN)
	{
	  return (NULL);
	}
    }
  else
    return (NULL);
  return (&event);
}
