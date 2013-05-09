#include "data.h"
#include "atrib.h"
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
	ok = input >> line; //pobranie pierwszej linijki
	NoAtributes = (line.size()-1)/2; //obliczenie ilości atrubutów

	for(unsigned int i = 0; i <= NoAtributes; i++) //przygotowanie vectora atrybutów
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

void data::changeAtr(int i,  atribute n)
{
	dataset[i] = n;
}

void data::show()
{
	std::cout << "NoEntries = " << NoEntries << " NoAtributes = " <<NoAtributes << std::endl;
	for(unsigned int i = 0; i < NoEntries; i++)
	{
		dataset[i].show();
	}
}

char data::HFrqCls(int c,char v)
{
	char cls = ' ';
	int high = 0;
	for(int i = 0; i < dataset[0].getNoDiffValues(); i++)
	{
		if (high < dataset[c].getNoAsses(dataset[0].getNthValue(i),v))
		{ 
			cls = dataset[0].getNthValue(i);
			high = dataset[c].getNoAsses(dataset[0].getNthValue(i),v);
		}
		
	}
	return cls;
}

unsigned int data::NoEnt()const
{
	return NoEntries;
}

unsigned int data::NoAtr()const
{
	return NoAtributes;
}

char data::getAtrVal (int c, int r)const
{
	return dataset[c].getAtribValue(r);
}

int data::getNoAtrib(int c, char v)const
{
	return dataset[c].getNoAtrib(v);
}

int data::getNoAsses(int col, char c, char a)const
{
	return dataset[col].getNoAsses(c,a);
}

atribute data::operator[] (int i)const
{
	return dataset[i];
}
