# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:16:03 by dmarceli          #+#    #+#              #
#    Updated: 2022/10/10 20:04:14 by dmarceli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=	\e[0;31m
RESET		=	\e[0m

NAME	:= philo

CC		:=	gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pthread #-fsanitize=thread   

PATH_SRC		:=	./src
PATH_INCLUDES	:=	./incs
INCS			:=	-I$(PATH_INCLUDES) 
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

BIN				:=	./$(NAME)
SRCS			:= $(PATH_SRC)/main.c \
					$(PATH_SRC)/argparser.c\
					$(PATH_SRC)/init.c\
					$(PATH_SRC)/prints.c\
					$(PATH_SRC)/actions.c\
					$(PATH_SRC)/time.c\

OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))

all:$(BIN)

$(BIN): $(OBJ)
		@$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(@) $^ -I$(PATH_INCLUDES)
		@printf "\033[44m[Philo built!]\033[0m\n"



$(PATH_OBJS)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@$(CC) $(INCS) $(CFLAGS) -c $(^) -o $@
		@printf "\033[36m[Building ${@F}]\033[0m\n"


$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS) 

clean:
		@printf "\033[38;5;1m[Cleaning objects!]\033[0m\n"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@rm -rf $(PATH_BUILD) $(NAME)
		@rm -rf $(BIN)
		@printf "\033[38;5;1m[Cleaning Bin!]\033[0m\n"

re: fclean all