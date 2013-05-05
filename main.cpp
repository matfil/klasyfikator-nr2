#include "atrib.h"
#include "data.h"
#include <iostream>
#include <string>

int main ()
{
	std::string filename;
	std::cin >> filename;

	data wejscie(filename);

	wejscie.show();

	return 0;
}
