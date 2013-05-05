#include "data.h"
#include <fstream>
#include <iostream>

data::data()
{
	NoEntries = 0;
	NoAtributes = 0;
}

data::data(const std::string& filename)
{
	bool ok; //poprawne wczytanie linijki z pliku zaznaczane jest tutaj
	std::string line; //linijka tekstu
	std::ifstream input; //strumień wejściowy
	atribute tmp;

	NoEntries = 0;
	NoAtributes = 0;

	input.open(filename.c_str(),std::ifstream::in); //otworzenie strumienia do czytania
	ok = input >> line;//pobranie pierwszej linijki
	NoAtributes = (line.size()-1)/2; //obliczenie ilości atrubutów

	for(unsigned int i = 0; i <= NoAtributes; i++)//przygotowanie vectora atrybutów
	{
		dataset.push_back(tmp);
	}

	while(ok)
	{
		this->AddEntry(line);
		NoEntries++;
		ok = input >> line;
	}	
	 
	input.close();
}

void data::AddEntry(std::string& line)
{
	dataset[0].add('*',line[0]);
	
	for(unsigned int i = 2;i < line.size(); i += 2)
	{
		dataset[ i/2 ].add(line[0],line[i]);
	}
}

void data::show()
{
	std::cout << "NoEntries = " << NoEntries << " NoAtributes = " <<NoAtributes << std::endl;
	for(unsigned int i = 0; i < NoEntries; i++)
	{
		dataset[i].show();
	}
}
