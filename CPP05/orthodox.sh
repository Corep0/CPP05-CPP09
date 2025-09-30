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
		/* Constructor | Destructor */
		$NAME();
		virtual ~$NAME();
		$NAME($NAME const& copy);

		/* Operator */
		$NAME&	operator=(const $NAME& other);

		/* Member Function	*/
		
		/* Getter | Setter	*/

		/* Exception class	*/
	private:

};

std::ostream&	operator<<(std::ostream& out, ${NAME}& f);

#endif // ${NAME}_HPP
EOF

# Create .cpp file
cat > "${NAME}.cpp" <<EOF
#include "${NAME}.hpp"

/* Constructor | Destructor	*/
$NAME::$NAME(void)
{
	std::cout << "${NAME} Constructor is called" << std::endl;
}

$NAME::$NAME()
{
	std::cout << "${NAME} Constructor is called" << std::endl;
}

$NAME::~$NAME()
{
	std::cout << "${NAME} Destructor is called" << std::endl;
}

$NAME::$NAME($NAME const& copy);
{
	std::cout << "${NAME} Copy Constructor is called" << std::endl;
	*this = copy;
}

/* Operator		*/
$NAME&	operator=(const $NAME& other)
{
	std::cout << "${NAME} Assignement operator is called" << std::endl;
	if (this != &other)
	{
	}
	return (*this);
}

/* Member Function	*/

/* Getter | Setter	*/

/* Exception class	*/

/* Function		*/
std::ostream&	operator<<(std::ostream& out, ${NAME}& f)
{
	std::cout << "Something" << std::endl;
	return (out);
}
EOF

echo "Files ${NAME}.hpp and ${NAME}.cpp created!"


