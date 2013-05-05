#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include "atrib.h"

class data
{
	private:
	//pola
		unsigned int NoEntries;
		unsigned int NoAtributes;
		std::vector<atribute> dataset; 
	//metody
		void AddEntry(std::string& line);
	protected:
	public:
	data();
	data(const std::string& filename);
	void show();
};

#endif
