# Compilator
CC = c++
CF = -Wall -Werror -Wextra -std=c++98

# Program
NAME = Bureaucrat 

# Header
INC = -I include/.

# Sources
SRCD = src/
SRC =	$(SRCD)main.cpp			\
	$(SRCD)Bureaucrat.cpp 		\
	$(SRCD)AForm.cpp		\
	$(SRCD)PresidentialPardonForm.cpp	\
	$(SRCD)RobotomyRequestForm.cpp 	\
	$(SRCD)ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

# Color
GC = \033[0;32m
RC = \033[0;31m
BC = \033[0;34m
ENDC = \033[0m

all: 		$(NAME)

$(NAME):	$(OBJ)
		@echo "$(GC) Compiling $(NAME) program..$(ENDC)"
		$(CC) $(CF) $(INC) -o $(NAME) $(OBJ)
		@echo "$(GC) $(NAME) ready to be used $(ENDC)"

%.o: %.cpp
		$(CC) $(CF) $(INC) -c $< -o $@

clean:	
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		re fclean clean all

