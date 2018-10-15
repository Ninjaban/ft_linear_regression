# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 13:07:37 by jcarra            #+#    #+#              #
#    Updated: 2018/10/07 23:13:13 by nathan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_linear_regression
NAME2		=	ft_trainer

LIB		=	libft.a
SRC		=	ft_linear_regression.c \
			ft_get_theta.c \
			ft_learn.c \
			ft_tools.c \
			ft_map.c

SRC1		=	ft_linear_regression.c \
			ft_get_theta.c
SRC2		=	ft_learn.c \
			ft_get_theta.c \
			ft_map.c \
			ft_tools.c

DIRSRC		=	sources/
DIRINC		=	include/
DIRLIB		=	library/
DIROBJ		=	objects/

LIBS		=	$(LIB:%=$(DIRLIB)%)
SRCS		=	$(SRC:%=$(DIRSRC)%)

OBJS		=	$(addprefix $(DIROBJ), $(SRC:.c=.o))
OBJS1		=	$(addprefix $(DIROBJ), $(SRC1:.c=.o))
OBJS2		=	$(addprefix $(DIROBJ), $(SRC2:.c=.o))

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC) -I./$(DIRLIB)$(DIRINC)

CC		=	gcc
RM		=	rm -rf
ECHO		=	printf
MAKE		=	make -sC

CLEAN		=	"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         "
LEN		=	$$(/bin/echo -n $(NAME) | wc -c)
DELTA		=	$$(echo "$$(tput cols)-32-$(LEN)"|bc)
NB		=	$(words $(SRC))
INDEX		=	0
SHELL		=	/bin/bash

all		:	$(NAME)

$(NAME)		:	$(DIROBJ) $(OBJS)
	@$(eval OBJ_LEN=$(shell echo "$$(echo "$(NAME1)" | sed 's/^.*\///')" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-6-$(OBJ_LEN)"|bc))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS1) $(LIBS) $(LFLAGS)
	@$(ECHO) "\r\033[38;5;040m✓ MAKE $(NAME)%.*s\033[0m\033[0m" $(CLEAN_LEN) $(CLEAN)
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2) $(LIBS) $(LFLAGS)
	@$(ECHO) "\r\033[38;5;040m✓ MAKE $(NAME2)%.*s\033[0m\033[0m" $(CLEAN_LEN) $(CLEAN)
	@$$(/bin/echo -n "0,0,0" > $(DIRSRC)/value.csv)
	@$(ECHO) "\r\033[38;5;040m✓ Init THETA%.*s\033[0m\033[0m\n" $(CLEAN_LEN) $(CLEAN)

$(DIROBJ)%.o	:	$(DIRSRC)%.c | $(DIROBJ)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(20 21 26 27 32 33 38 39 44 45 50 51); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@$(ECHO) "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[0m" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@$(eval OBJ_LEN=$(shell echo "$$(echo "$@" | sed 's/^.*\///')" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-1-$(OBJ_LEN)"|bc))
	@$(ECHO) "\r\033[38;5;%dm✓ %s\033[0m\033[0m%.*s\n\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[0m"  $(COLOR) "$(shell echo "$@" | sed 's/^.*\///')"  $(CLEAN_LEN) $(CLEAN) $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(DIROBJ)	:
	@$(MAKE) $(DIRLIB)
	@mkdir -p $(DIROBJ)

clean		:
	@$(MAKE) $(DIRLIB) clean
	@if [ -e $(DIROBJ) ];						\
	then								\
		$(RM) $(DIROBJ);					\
		$(ECHO) "\033[38;5;202m✗ $(NAME)\033[0m\033[0m\n";	\
		$(ECHO) "\033[38;5;202m✗ $(NAME2)\033[0m\033[0m\n";	\
	fi;

fclean		:	clean
	@$(MAKE) $(DIRLIB) fclean
	@if [ -e $(NAME) ];						\
	then								\
		$(RM) $(NAME);						\
		$(ECHO) "\033[38;5;196m✗ $(NAME)\033[0m\033[0m\n";	\
	fi;
	@if [ -e $(NAME2) ];						\
	then								\
		$(RM) $(NAME2);						\
		$(ECHO) "\033[38;5;196m✗ $(NAME2)\033[0m\033[0m\n";	\
	fi;

re		:	fclean all

.PHONY		:	all fclean clean re
