#pragma once
#include "Bauelement.h"
#include "Complex.h"

class CSpule :
	public CBauelement
{
protected:
	double l;
public:
	CSpule();
	CSpule(std::string _name, double _preis, CPunkt _position, double _l);
	~CSpule();

	double getL();
	void setL(double _l);

	CComplex CSpule::getImpedanz(double _f);
};

std::ostream& operator<<(std::ostream& stream, CSpule toPrint);