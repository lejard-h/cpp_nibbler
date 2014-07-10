##
## Makefile for nibbler in /home/millon_c/Projets/NIBBLER/cpp_nibbler/OpenGL
## 
## Made by millon_c
## Login   <millon_c@epitech.net>
## 
## Started on  Tue Apr  1 16:16:47 2014 millon_c
##

NAME		= lib_nibbler_OpenGL.so

SRCDIR		= ./src/

SRC		= $(SRCDIR)NibblerOpenGL.cpp \
		$(SRCDIR)OpenGL.cpp

OBJS		= $(SRC:.cpp=.o)

INC		= -I./include/ -I../include/

LIB		= -lGL -lGLU -lSDL

CC		= g++
CFLAGS		= -Wall -Wextra -fPIC

RM		= rm -f

all        : $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(LIB) -shared $(INC) $(OBJS) -o $(NAME)

clean        :
		$(RM) $(SRCDIR)*.o
		$(RM) $(SRCDIR)*~
		$(RM) #*#


fclean        : clean
		$(RM) $(NAME)
		$(RM) $(LINK)

re        : fclean all

.cpp.o:
		 $(CC) $(LIB) -c $(INC) $(CFLAGS) $< -o $@
