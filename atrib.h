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
		int NoAtrib (char)const; //Number of Atributes of this type
		int NoAsses (char,char)const; //Number of Accociations
};

#endif
