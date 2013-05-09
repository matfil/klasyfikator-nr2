#include "1R.h"
#include "atrib.h"
#include "data.h"

#include <string>
#include <iostream>

void klas1R::learn()
{
	
	char klasa, value;
	double CurrentAccuracy;
	double accuracy;
	int GoodAtribute;
	char GoodValue;

	insider tmp;


	CurrentAccuracy = 0;
	GoodAtribute = 0;
	GoodValue = ' ';

	for(int c = 0; c < zestaw[0].getNoDiffValues(); c++)
	{//dla każdej klasy z osobna
	
		for(unsigned int a = 1; a < zestaw.NoAtr(); a++)
		{//for each atribute

			for(int v = 0; v < zestaw[a].getNoDiffValues(); v++)
				{//dla każdej możliwej wartości
					value = zestaw[a].getNthValue(v);
					klasa = zestaw.HFrqCls(a,value);

					if (klasa == zestaw[0].getNthValue(c))
					{
						accuracy = (double)zestaw[a].getNoAsses(klasa,value) / (double)zestaw.NoEnt();
						if (CurrentAccuracy < accuracy)
						{
							GoodAtribute = a;
							GoodValue = value;
						}
						
					}
					
				}
		}
		tmp.cls = zestaw[0].getNthValue(c);
		tmp.atr = GoodAtribute;
		tmp.val = GoodValue;
	
		effect.push_back(tmp);

		CurrentAccuracy = 0;
		GoodAtribute = 0;
		GoodValue = ' ';
	}
}

void klas1R::setTarget(std::string& filename)
{
 data tmp(filename);
 target = tmp;
}

void klas1R::useknowledge()
{
}

klas1R::klas1R(std::string& filename): klas(filename)
{	
}

void klas1R::show()
{
	zestaw.show();
	
	std::cout << "klasyfikator 1R" << std::endl;

	for (unsigned int i = 0 ; i < effect.size(); i++)
	{
		std::cout<< "cls " << effect[i].cls << " atr " <<effect[i].atr << " val " <<effect[i].val << std::endl;
	}

}
