##
## Makefile for nibbler in /home/millon_c/Projets/NIBBLER/cpp_nibbler
## 
## Made by millon_c
## Login   <millon_c@epitech.net>
## 
## Started on  Thu Mar 27 14:34:08 2014 millon_c
##

NAME    =       nibbler

REP_SRC =       ./src/

SRCS    =	$(REP_SRC)main.cpp		\
		$(REP_SRC)map.cpp		\
		$(REP_SRC)nibbler.cpp 		\
		$(REP_SRC)snake.cpp		\
		$(REP_SRC)DynamicLib.cpp	\
		$(REP_SRC)event.cpp	\


OBJS    =	$(SRCS:.cpp=.o)

CXXFLAGS  +=    -I ./include/ -Wall -Wextra -ldl -rdynamic

CC      =       g++

RM      =       rm -f

$(NAME) :	$(OBJS)
		$(CC) $(SRCS) -o $(NAME) $(CXXFLAGS)
		make -C./ncurses/
		make -C./OpenGL/
		make -C./SFML/
		cp ./ncurses/*.so ./
		cp ./OpenGL/*.so ./
		cp ./SFML/*.so ./

all     :	$(NAME)

clean   :
		$(RM) $(OBJS)
		make clean -C./ncurses/   
		make clean -C./OpenGL/   
		make clean -C./SFML/

fclean  :       clean
		$(RM) $(NAME)
		make fclean -C./ncurses/
		make fclean -C./OpenGL/   
		make fclean -C./SFML/
		$(RM) *.so

re      :       fclean all
