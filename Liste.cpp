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
	CBauelement* ptr = start;
	int Entrys = this->getEntryCount();
	CBauelement** delList = new CBauelement*[Entrys];

	for (int i = 0; i < Entrys; i++)
	{
		delList[i] = ptr;
		ptr = ptr->getNext();
	}
	for (int i = 0; i < Entrys; i++)
	{
		delete	delList[i];
	}
	delete[] delList;
}

CBauelement* CListe::getStart(void) const
{
	return start;
}

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

bool CListe::addToEnd(CBauelement * _newStartPtr)
{
	if (_newStartPtr == NULL)
		return 1;
	else
	{
		if (start == NULL)
		{
			start = _newStartPtr;
		}
		else
		{
			CBauelement* lookupPtr = start;
			CBauelement* lookupPtrOld = lookupPtr;
			while (lookupPtr != NULL)
			{
				lookupPtrOld = lookupPtr;
				lookupPtr = lookupPtr->getNext();
			}
			lookupPtrOld->setNext(_newStartPtr);
			return 0;
		}
	}
}

bool CListe::delAtStart()
{
	return 0;
}

bool CListe::delAtEnd()
{
	//Check if Entry exist
	if (start == NULL)
	{
		return 1;
	}
	CBauelement* nullCopyPtr = NULL;
	CBauelement* delPtr = NULL;
	CBauelement* ptr = start;

	/* Need Implementation of Delete Funcionaliti
	while (ptr != NULL)
	{
		ptr = ptr->getNext();
		)
		delPtr = ptr;
		
	}
	if (nullCopyPtr != NULL)
	{
		nullCopyPtr->setNext(NULL);
	}
	if (delPtr != NULL)
		delete	delPtr;
	delete delPtr;
	return 0;
	*/
		return 0;
}

int CListe::getEntryCount(void)const
{
	CBauelement* ptr = start;
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->getNext();
	}
	return count;
}

void CListe::printAllElements(void) const
{
	CBauelement* ptr = NULL;

	for (ptr = start; ptr != NULL; ptr = ptr->getNext())
	{
		std::cout << *ptr << std::endl;
	}
}

CBauelement* CListe::searchName(const std::string& _nameToFind) const
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

std::ostream& operator<<(std::ostream& stream, const CListe& _list)
{
	CBauelement* ptr = _list.start;
	while (ptr != NULL)
	{
		stream << (*ptr);
		stream << std::endl;
		ptr = ptr->getNext();
	}
	return stream;
}
