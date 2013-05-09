#ifndef _1R_H
#define _1R_H

#include "klas.h"
#include <vector>
#include <string>


using namespace std; // jestem zbyt leniwy... 

class klas1R:public klas
{
	private:
	
	class insider
	{
		public:
		char cls;
		int  atr;
		char val;
	};
	
	vector<insider> effect;
	
	data target;
	atribute used;

	protected:
	public:
	klas1R(std::string& filename);
	void show();

	void setTarget (std::string& filename);

	void learn();
	void useknowledge();
};

#endif
