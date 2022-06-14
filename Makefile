GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=	\e[0;31m
RESET		=	\e[0m

NAME	:= philosophers

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

CC		:=	gcc
CFLAGS	:= -Wall -Wextra -Werror -pthread

PATH_SRC		:=	./src
PATH_INCLUDES	:=	./incs
INCS			:=	-I$(PATH_INCLUDES) -I$(LIBFT_DIR)
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

$(BIN):$(LIBFT) $(OBJ)
		@$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(@) $^ -I$(PATH_INCLUDES)
		@printf "\033[44m[Philo built!]\033[0m\n"

$(LIBFT):
		@$(MAKE) -C ./libft --silent


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
		@ $(MAKE) fclean -C $(LIBFT_DIR) --silent
		@rm -rf $(PATH_BUILD) $(NAME)
		@rm -rf $(BIN)
		@printf "\033[38;5;1m[Cleaning Bin!]\033[0m\n"

re: fclean all