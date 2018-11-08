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

	bool addToStart(CBauelement* _newStartPtr);

	void printAllElements(void) const;
	void print(void);
};