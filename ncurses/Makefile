NAME		= lib_nibbler_Ncurses.so

SRCDIR		= ./src

SRC		=   $(SRCDIR)/NibblerNcurses.cpp \
		    $(SRCDIR)/Ncurses.cpp \
		    $(SRCDIR)/event.cpp

OBJS		= $(SRC:.cpp=.o)

INC		= -I./include/ -I../include/

LIB		= -lncurses

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
