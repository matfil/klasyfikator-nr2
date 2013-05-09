#include "atrib.h"
#include <map>
#include <iostream>

atribute::Assctns::Assctns(char c = ' ', char a = ' ')
{
	cls = c;
	atr = a;
}

void atribute::add(char c = ' ', char a = ' ') // dodawanie kolejnych par klasa / atrybut do bazy danych
{
	unsigned int i;
	atr[a]++; // zwiększenie ilości wystąpień atrybutu a o 1
	for(i = 0; i < associations.size(); i++) //czy taka para klasa/atrybut już gdzieś wystąpiła
	{
		if (c != associations[i].cls) 
		{
			continue; // jak różnią się klasą to na pewno nie są równe, więc idziemy do przodu
		}
		else
		{
			if (a != associations[i].atr)
			{
				continue; // jak różnią się klasą i atrybutem to jeszcze nic nie znaczy. Trzeba sprawdzić wszystkie, idziemy dalej.
			}
			else
			{
				break; // taka para już wystąpiła
			}
		}
	}	
	atrib.push_back(a);
	if(i < associations.size()) // czyli jak już był na liście
	{
		AssCounter[i]++; // zwiększam ilość wystąpień o 1
	}
	else
	{
		Assctns ins(c,a);
		associations.push_back(ins);
		AssCounter.push_back(1);			
	}


} // void atribute::add(char c, char a)

void atribute::show()
{ 

	for(unsigned int i = 0; i < atrib.size(); i++)
	{
		std::cout << atrib[i] << std::endl;
	}
	
	std::cout << std::endl; // linia odstępu

	for(std::map<char,int>::iterator it = atr.begin(); it != atr.end(); ++it)
	{
		std::cout << it -> first << " " << it -> second << std::endl;
	}

	std::cout << std::endl; // linia odstępu

	for(unsigned int i = 0; i < associations.size(); i++)
	{
		std::cout << associations[i].cls << " " << associations[i].atr << " = " << AssCounter[i] << std::endl;
	}
}

int atribute::getNoDiffValues ()const
{
	return atr.size();
}

char atribute::getNthValue(int nth)
{
	std::map<char,int>::iterator it = atr.begin();
	for(;nth>0;nth--)
		++it;
	return it->first;
}

char atribute::getAtribValue(int x)const
{
	return atrib[x];
}

int atribute::getNoAtrib(char a)const
{
	return atr.find(a)->second;
}
int atribute::getNoAsses(char c,char a)const
{
	for(unsigned int i = 0; i < associations.size(); i++)
	{
		if (c == associations[i].cls && a == associations[i].atr)
			return AssCounter[i];
	}
	return 0;
}
