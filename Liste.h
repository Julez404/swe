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
	bool setStart(CBauelement* _newStartPtr);
	bool addToStart(CBauelement* _newStartPtr);
	bool addToEnd(CBauelement* _newStartPtr);
	bool delAtStart(void);
	bool delAtEnd(void);

	int  getEntryCount(void)const;
	void printAllElements(void) const;

	CBauelement* searchName(const std::string& _nameToFind) const;
	template<class T, class K>
	CListe* search(T _searchObj, T (*fktPtr)(K&)) const;

	friend std::ostream& operator<<(std::ostream& stream, const CListe& _list);
};


//Will move to .cpp with polymorphie
template<class T, class K>
CListe* CListe::search(T _searchObj, T(*fktPtr)(K&)) const
{
	static CListe* listOfItemsToReturn = new CListe;
	CBauelement* searchPtr = start;
	while (searchPtr != NULL)
	{
		if ((*fktPtr)(*searchPtr) == _searchObj)
		{
			CBauelement* newEntry = new CBauelement(*searchPtr);
			listOfItemsToReturn->addToStart(newEntry);
		}
		searchPtr = searchPtr->getNext();
	}
	return listOfItemsToReturn;
}


