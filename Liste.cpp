#include "stdafx.h"
#include "liste.h"

CListe::CListe()
	:start(NULL)
{}

CListe::CListe(CBauelement* _bauelement)
{
	start = _bauelement;
}

CListe::~CListe()
{
	if (start != NULL)
	{
		delete start;
	}
}


CBauelement* CListe::getStart(void) const
{
	return start;
}

///<summary>
//Returns 0 on success
///</summary>
bool CListe::setStart(CBauelement* _newStartPtr)
{
	return 0;
}


bool CListe::addToStart(CBauelement* _newStartPtr)
{
	if (_newStartPtr == NULL)
	{
		return 1;
	}
	else
	{
		(*_newStartPtr).setNext(start);
		start = _newStartPtr;
		return 0;
	}
}

void CListe::print(void)
{
	CBauelement* ptr = start;

	std::cout << *ptr << std::endl; //Löscht next
	ptr = start->getNext();
	std::cout << *ptr << std::endl;


	/*
		for (ptr = start; ptr != NULL ; ptr = ptr->getNext()->getNext())
		{
			std::cout << *ptr << std::endl;
		}
		*/
}


void CListe::printAllElements(void) const
{
	CBauelement* ptr = NULL;

	for (ptr = start; ptr != NULL; ptr = ptr->getNext())
	{
		std::cout << *ptr << std::endl;
	}
}
