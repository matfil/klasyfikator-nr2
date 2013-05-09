#ifndef KLAS_H
#define KLAS_H

#include "data.h"
#include <string>

class klas
{
	private:
	protected:
	data zestaw;
	public:
	klas(std::string&);
	virtual void learn() = 0; //uczenie klasyfikatora
	virtual void useknowledge() = 0; //wykorzystywanie klasyfikatora
};

#endif
