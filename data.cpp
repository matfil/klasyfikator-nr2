#include "data.h"
#include <fstream>

data::data()
{
	NoEntries = 0;
	NoAtributes = 0;
}

data::data(std::string filename)
{
	bool ok;
	std::string line;
	std::ifstream input;
	atribute tmp;

	input.open(filename.c_str(),std::ifstream::in); //otworzenie pliku do czytania
	ok = input >> line;//pobranie pierwszej linijki
	NoAtributes = (line.size()-1)/2;
	for(unsigned int i = 0; i < NoAtributes; i++)
	{
		dataset.push_back(tmp);
	}

	while(ok)
	{
		this->AddEntry(line);
		ok = input >> line;
	}	
	 
	input.close();
}

void data::AddEntry(std::string& line)
{
	
}
