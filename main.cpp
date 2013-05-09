#include "atrib.h"
#include "data.h"
#include "1R.h"
#include <iostream>
#include <string>

int main ()
{
	std::string filename;
	std::cout<< "plik z danymi"<<std::endl;
	std::cin >> filename;

	/*
	data wejscie(filename);

	wejscie.show();
	*/

	klas1R test(filename);

	test.learn();
	
	std::cout<< "plik analizowany"<<std::endl;
	std::cin >> filename;

	test.setTarget(filename);

	test.useknowledge();

	test.show();

	return 0;
}
