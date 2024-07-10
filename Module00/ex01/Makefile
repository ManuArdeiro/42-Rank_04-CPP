NAME		=	phonebook

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -I./include -fsanitize=address

SRC			=	src/main.cpp \
				src/PhoneBook.cpp \
				src/Contact.cpp
OBJ			=	$(SRC:.cpp=.o)
RM			=	rm -rf

# Define color variables
YELLOW		=	\033[1;33m
WHITE		=	\033[1;37m
LIGHT_GRAY	=	\033[0;37m

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(YELLOW)Creating program...$(WHITE)"
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
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

.PHONY: all clean fclean re run
