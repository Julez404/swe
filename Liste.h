#pragma once
#include "Bauelement.h"


class CListe
{
protected:
	CBauelement* start;

public:
	CListe();
	CListe(CBauelement* _bauelement);
	~CListe();
	CBauelement* CListe::getStart(void) const;

	///<summary>
	//Returns 0 on success
	///</summary>
	bool setStart(CBauelement* _newStartPtr);

	///<summary>
	//Returns 0 on success
	///</summary>
	bool addToStart(CBauelement* _newStartPtr);

	///<summary>
	//Prints all entrys beginning with "start" ptr
	///</summary>
	void printAllElements(void) const;

	///<summary>
	//Lookup string in name attributes of list members
	///</summary>
	CBauelement* searchName(std::string _nameToFind) const;

	///<summary>
	//Search for specific type of attribute by fktPtr, returns pointer if Element is found.
	///</summary>
	template<class T, class K>
	CBauelement* search(T _searchObj, T (*fktPtr)(K&)) const;
};


//Will move to .cpp with polymorphie
template<class T, class K>
CBauelement* CListe::search(T _searchObj, T(*fktPtr)(K&)) const
{
	CBauelement* searchPtr = start;
	while (searchPtr != NULL)
	{
		if ((*fktPtr)(*searchPtr) == _searchObj)
		{
			return searchPtr;
		}
		searchPtr = searchPtr->getNext();
	}
	return NULL;
}

