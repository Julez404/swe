#pragma once

#include "Punkt.h"

class CBauelement
{
protected:
	std::string name;
	double preis;
	CPunkt position;
	CBauelement* next;

public:
	CBauelement();
	CBauelement(std::string _name, double _preis, CPunkt _position);
	~CBauelement();



	std::string getName(void) const;
	///<summary>
	//Returns price of element
	///</summary>
	double getPreis(void) const;
	CPunkt getPosition(void) const;
	CBauelement* getNext(void) const;

	void setName(std::string _name);
	void setPreis(double _preis);
	void setPosition(CPunkt _position);
	void setNext(CBauelement* _next);

	friend std::ostream& operator<<(std::ostream& stream, const CBauelement& _bauelement);
};
