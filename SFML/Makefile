##
## Makefile for nibble in /home/roche_d/rendu/cpp_nibbler/SFML
## 
## Made by roche_d
## Login   <roche_d@epitech.net>
## 
## Started on  Wed Apr  2 12:54:52 2014 roche_d
##

NAME		= lib_nibbler_SFML.so

SRCDIR		= ./src/

SRCS		= $(SRCDIR)NibblerSFML.cpp \
		$(SRCDIR)Drawing.cpp \

OBJS		= $(SRCS:.cpp=.o)

INC		= -I./inc/ -I../include/

LIB		= -lsfml-graphics -lsfml-window -lsfml-system

CC		= g++

CXXFLAGS	= -Wall -Wextra -fPIC

RM		= rm -f

all        : $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CXXFLAGS) $(LIB) -shared $(INC) $(OBJS) -o $(NAME)

clean        :
		$(RM) $(SRCDIR)*.o
		$(RM) $(SRCDIR)*~
		$(RM) #*#


fclean        : clean
		$(RM) $(NAME)
		$(RM) $(LINK)

re        : fclean all

.cpp.o:
		 $(CC) $(LIB) -c $(INC) $(CXXFLAGS) $< -o $@
