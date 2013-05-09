#ifndef ATRIB_H
#define ATRIB_H

#include <map>
#include <vector>

class atribute
{
	private:
		std::map<char,int> atr;
		
		class Assctns
		{
			public:
				char cls;
				char atr;
				Assctns(char,char);
		};
		
		std::vector<char> atrib;
		std::vector<Assctns> associations;
		std::vector<int> AssCounter; //association counter

	protected:
	public:
		void add (char,char);
		void show();
		int getNoDiffValues ()const; //get Number of different Values
		char getNthValue(int); //no duplications
		char getAtribValue (int)const; //get #th Atribute Value (possible duplications)
		int getNoAtrib (char)const; //get Number of Atributes
		int getNoAsses (char,char)const; //get Number of Accociations
};


#endif
