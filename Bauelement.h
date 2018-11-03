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
	double getPreis(void) const;
	CPunkt getPosition(void) const;

	void setName(std::string _name);
	void setPreis(double _preis);
	void setPosition(CPunkt _position);
	void setNext(CBauelement* _next);
};

std::ostream& operator<<(std::ostream& stream, CBauelement _bauelement);
