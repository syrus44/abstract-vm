##
## Makefile for Makefile in /home/bettin_j//Documents/Abstract-Vm
## 
## Made by jordan bettin
## Login   <bettin_j@epitech.net>
## 
## Started on  Sat Feb  9 10:25:49 2013 jordan bettin
## Last update Thu Feb 14 18:51:01 2013 jordan bettin
##

NAME	=	avm

SRC_DIR	=	.

SRCS	=	$(SRC_DIR)/main.cpp		\
		$(SRC_DIR)/Parser.cpp		\
		$(SRC_DIR)/Exception.cpp	\
		$(SRC_DIR)/Epur.cpp		\
		$(SRC_DIR)/AbstractVM.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

DUST	=	*~ \#*\#

DUSTI	=	$(INC_DIR)/*~ $(INC_DIR)/\#*\#

DUSTS	=	$(SRC_DIR)/*~ $(SRC_DIR)/\#*\#

CC	=	g++

FLAGS	=	-W -Wall -Werror -Wunused

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(SRCS) $(FLAGS) -o $(NAME)

dust	:
		$(RM) $(DUST)
		$(RM) $(DUSTI)
		$(RM) $(DUSTS)

clean	:	dust
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

doc	:
		rm -rf doc
		mkdir doc
		doxygen .
		mv html latex doc

re	:	fclean all
