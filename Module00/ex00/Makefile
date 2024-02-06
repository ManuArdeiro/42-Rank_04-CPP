NAME	=	megaphone

SRC 	=	megaphone.cpp
OBJS 	=	$(SRC:.cpp=.o)
%.o: 		%.cpp
			${CC} ${CFLAGS} -c $< -o $@

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

all: $(NAME)

$(NAME):	$(OBJ)
			@echo "$(YELLOW) Creating program... $(WHITE)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "\n$(LIGHT_GRAY)----- Ready -----

clean:
			@echo "\n"
			@echo "$(LIGHT_RED) Cleaning files... $(WHITE)\n"
			$(RM) $(OBJS)
			@echo "\n"
			@echo "\n$(LIGHT_GRAY)----- Done -----

fclean: 	clean
			@echo "\n"
			@echo "$(LIGHT_RED) Cleaning program... $(WHITE)\n"
			$(RM) $(NAME)
			@echo "\n"
			@echo "\n$(LIGHT_GRAY)----- Done -----

re: 		fclean all

run: 		all clean
			./$(NAME)

.PHONY: 	all clean fclean re run

# COLORS
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
LIGHT_GRAY		= \033[0;37m
DARK_GRAY		= \033[0;90m
LIGHT_RED		= \033[0;91m
WHITE			= \033[0;97m

#SETS
BOLD			= \e[0;1m
UNDERLINED		= \e[0;4m
BLINK			= \e[0;5m