#pragma once

#include "Bauelement.h"
#include "Complex.h"

class CKap :
	public CBauelement
{
protected:
	double c;

public:
	CKap();
	CKap(std::string _name, double _preis, CPunkt _position, double _c);
	~CKap();

	double getC();
	void setC(double _c);
	CComplex CKap::getImpedanz(double _f);
};

std::ostream& operator<<(std::ostream& stream, CKap toPrint);
