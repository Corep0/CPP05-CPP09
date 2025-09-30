# Compilator
CC = c++
CF = -Wall -Werror -Wextra -std=c++98 -g

# Program
PROG = Form 

# Sources
SRC =	Bureaucrat.cpp			\
	AForm.cpp			\
	ShrubberyCreationForm.cpp	\
	RobotomyRequestForm.cpp		\
	PresidentialPardonForm.cpp	\
      	main.cpp
#Color
GC = \033[0;32m
RC = \033[0;31m
ENDC = \033[0m

all:	$(PROG)

$(PROG):	$(SRC)
		@echo "$(GC)Compiling program $(PROG)..$(ENDC)"
		$(CC) $(CF) $(SRC) -o $(PROG)
		@echo "$(RC) $(PROG) ready to be used $(ENDC)"

clean:
		@rm -f $(PROG)
		@rm -f *_shrubbery 
		@echo "$(GC) $(PROG) removed$(ENDC)"

re :		clean all

.PHONY:		re clean all
	
