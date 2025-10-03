#!/bin/bash

# Check if an argument is given
if [ -z "$1" ]; then
    echo "Usage: $0 <Name>"
    exit 1
fi

NAME=$1

# Create .hpp file
cat > "${NAME}.hpp" <<EOF
#ifndef ${NAME^^}_HPP
# define ${NAME^^}_HPP

# include <iostream>

class	$NAME
{
	public:
		// Constructor | Destructor
		$NAME();
		virtual ~$NAME();
		$NAME($NAME const& copy);

		// Operator
		$NAME&	operator=(const $NAME& other);

		// Member Function
		
		// Getter | Setter

		// Exception class
	private:

};

#endif // ${NAME}_HPP
EOF

# Create .cpp file
cat > "${NAME}.cpp" <<EOF
#include "${NAME}.hpp"

/* Constructor | Destructor */
$NAME::$NAME()
{
	std::cout << "$NAME Construtor is called" << std::endl;
}

$NAME::~$NAME()
{
	std::cout << "$NAME Destrutor is called" << std::endl;
}

$NAME::$NAME($NAME const& copy);
{
	std::cout << "$NAME Copy Construtor is called" << std::endl;
}

/* Operator */
$NAME&	$NAME::operator=(const $NAME& other)
{
	std::cout << "$NAME Assignement is called" << std::endl;
}

/* Member Function */

/* Getter | Setter */

/* Exception class */

EOF

# Create Makefile file
cat > "Makefile" << EOF
# Compilator
CC = c++
CF = -Wall -Werror -Wextra -std=c++98

# Program
NAME = $NAME 

# Header
INC = -I include/.

# Sources
SRCD = src/
SRC =	\$(SRCD)main.cpp

OBJ = \$(SRC:.cpp=.o)

# Color
GC = \033[0;32m
RC = \033[0;31m
BC = \033[0;34m
ENDC = \033[0m

all: 		\$(NAME)

\$(NAME):	\$(OBJ)
		@echo "\$(GC) Compiling \$(NAME) program..\$(ENDC)"
		\$(CC) \$(CF) \$(INC) -o \$(NAME) \$(OBJ)
		@echo "\$(GC) \$(NAME) ready to be used \$(ENDC)"

%.o: %.cpp
		\$(CC) \$(CF) \$(INC) -c $< -o \$@

clean:	
		@rm -f \$(OBJ)

fclean:		clean
		@rm -f \$(NAME)

re:		fclean all

.PHONY:		re fclean clean all

EOF

echo "Files ${NAME}.hpp and ${NAME}.cpp and Makefile created!"


