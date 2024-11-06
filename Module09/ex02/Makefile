NAME		=	PmergeMe

vpath			%.hpp include
vpath			%.cpp src
vpath			%.o obj

INCLUDE		=   -Iinclude/
SRC			=	PmergeMe.cpp main.cpp
OBJ_DIR		=   obj

CC			=	c++
SANITIZER	=   -g3 -fsanitize=address -g
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 $(INCLUDE) $(SANITIZER)

OBJ			=   $(SRC:%.cpp=$(OBJ_DIR)/%.o)

RM			=	rm -rf

# Pattern rule for creating .o files in the obj directory
$(OBJ_DIR)/%.o : %.cpp
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(YELLOW)Creating program...$(WHITE)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
			@echo "\n$(LIGHT_GRAY)----- Ready -----\033[0m"

clean:
			@echo "\n\033[1;31mCleaning files...$(WHITE)\n"
			$(RM) $(OBJ)
			@echo "\n$(LIGHT_GRAY)----- Done -----\033[0m\n"

fclean: 	clean
			@echo "\n\033[1;31mCleaning program...$(WHITE)\n"
			$(RM) $(NAME)
			@echo "\n$(LIGHT_GRAY)----- Done -----\033[0m\n"

re: 		fclean all

run: 		all clean
			./$(NAME)

.PHONY: all clean fclean re run bonus

# COLORS
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
MAGENTA         = \033[0;35m
CYAN            = \033[0;36m
LIGHT_GRAY      = \033[0;37m
DARK_GRAY       = \033[0;90m
LIGHT_RED       = \033[0;91m
WHITE           = \033[0;97m

#SETS
BOLD            = \e[0;1m
UNDERLINED      = \e[0;4m
BLINK           = \e[0;5m
