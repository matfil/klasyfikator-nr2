#include <iostream>
#include "atrib.h"

int main ()
{
	atribute tr;
	tr.add('a','b');
	tr.add('a','f');
	tr.add('b','b');
	tr.add('a','b');
	tr.add('b','f');
	tr.add('b','b');
	tr.show();
	return 0;
}
