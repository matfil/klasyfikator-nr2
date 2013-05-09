#include "atrib.h"
#include "data.h"
#include "1R.h"
#include <iostream>
#include <string>

int main ()
{
	std::string filename;
	std::cin >> filename;

	/*
	data wejscie(filename);

	wejscie.show();
	*/

	klas1R test(filename);

	test.learn();
	
	test.show();

	return 0;
}
