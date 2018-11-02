#include "stdafx.h"
#include "Spule.h"


CSpule::CSpule()
	:CBauelement(), l(0)	
{}

CSpule::CSpule(std::string _name, double _preis, CPunkt _position, double _l)
	: CBauelement(_name, _preis, _position), l(_l)
{}

CSpule::~CSpule()
{}


double CSpule::getL()
{
	return l;
}


void CSpule::setL(double _l)
{
	l = _l;
}


std::ostream& operator<<(std::ostream& stream, CSpule toPrint)
{
	stream << toPrint.getName() << "," << toPrint.getL() << "Ohm" << toPrint.getPreis(), toPrint.getPosition();
	return stream;
}

CComplex CSpule::getImpedanz(double _f)
{
	return CComplex(0, 2 * M_PI*_f*l);
}