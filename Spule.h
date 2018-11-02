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

	double getL() const;
	CComplex CSpule::getImpedanz(double _f) const;

	void setL(double _l);


};

std::ostream& operator<<(std::ostream& stream, CSpule toPrint);