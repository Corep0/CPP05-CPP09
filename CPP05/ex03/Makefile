# Compilator
CC = c++
CF = -Wall -Werror -Wextra -std=c++98 -g

# Program
NAME = Form 

# Header
INC = -I include/.

# Sources
SRCD = src/
SRC =	$(SRCD)Bureaucrat.cpp	\
	$(SRCD)Form.cpp	\
      	$(SRCD)main.cpp
#Color
GC = \033[0;32m
RC = \033[0;31m
ENDC = \033[0m

all:	$(NAME)

$(NAME):	$(SRC)
		@echo "$(GC)Compiling program $(NAME)..$(ENDC)"
		$(CC) $(CF) $(INC) -o $(NAME) $(SRC)
		@echo "$(RC) $(NAME) ready to be used $(ENDC)"

clean:
		@rm -f $(NAME)
		@echo "$(GC) $(NAME) removed$(ENDC)"

fclean:		clean
		@rm -f $(NAME)
		@echo "$(GC) $(NAME) removed$(ENDC)"

re :		fclean all

.PHONY:		re clean fclean all
	
