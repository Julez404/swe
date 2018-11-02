#include "stdafx.h"
#include "Kap.h"


CKap::CKap()
	:CBauelement(), c(0)
{}

CKap::CKap(std::string _name, double _preis, CPunkt _position, double _c)
	:CBauelement(_name, _preis, _position),c(_c)
{}


CKap::~CKap()
{
}


double CKap::getC()
{
	return c;
}


void CKap::setC(double _c)
{
	c = _c;
}

std::ostream& operator<<(std::ostream& stream, CKap toPrint)
{
	stream << toPrint.getName() << "," << toPrint.getC() << "Ohm" << toPrint.getPreis(), toPrint.getPosition();
	return stream;
}

CComplex CKap::getImpedanz(double _f)
{
	return CComplex(0,-( 1 / (2 * M_PI*_f*c)));
}
