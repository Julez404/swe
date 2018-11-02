#pragma once
#include "Bauelement.h"
#include "Complex.h"

class CWiderstand :
	public CBauelement
{
public:

protected:
	double r;
public:
	CWiderstand();
	CWiderstand(std::string _name, double _preis, CPunkt _position, double _r);
	~CWiderstand();

	double getR() const;
	void setR(double _r);

	CComplex CWiderstand::getImpedanz(double _f) const;

};

std::ostream& operator<<(std::ostream& stream, CWiderstand _CWiderstand);