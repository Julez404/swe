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

void CListe::printAllElements(void) const
{
	CBauelement* ptr = NULL;

	for (ptr = start; ptr != NULL; ptr = ptr->getNext())
	{
		std::cout << *ptr << std::endl;
	}
}

CBauelement* CListe::searchName(std::string _nameToFind) const
{
	CBauelement* nameSearchPtr = start;
	while (nameSearchPtr != NULL)
	{
		if (nameSearchPtr->getName() == _nameToFind)
		{
			return nameSearchPtr;
		}
		nameSearchPtr = nameSearchPtr->getNext();
	}
	return NULL;
}


