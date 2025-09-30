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

class $NAME
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

// Constructor | Destructor
$NAME::$NAME()
{
}

$NAME::~$NAME()
{
}

$NAME::$NAME($NAME const& copy);
{
}

// Operator
$NAME&	operator=(const $NAME& other)
{
}

// Member Function

// Getter | Setter

// Exception class
EOF

echo "Files ${NAME}.hpp and ${NAME}.cpp created!"


