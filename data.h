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
	char HFrqCls(int,char);
	void show();
	unsigned int NoEnt()const;
	unsigned int NoAtr()const;
	void changeAtr(int, atribute);
	char getAtrVal(int,int)const;//column, row
	int getNoAtrib(int,char)const;//column, value
	int getNoAsses(int,char,char)const;
	atribute operator[](int)const;
};

#endif
