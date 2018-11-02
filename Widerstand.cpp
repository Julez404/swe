#include "stdafx.h"
#include "Widerstand.h"


CWiderstand::CWiderstand()
{
	r = 0.0;
}

CWiderstand::CWiderstand(std::string _name, double _preis, CPunkt _position, double _r)
:CBauelement(_name,_preis,_position),r(_r)
{}

CWiderstand::~CWiderstand()
{}


double CWiderstand::getR()
{
	return r;
}


void CWiderstand::setR(double _r)
{
	r = _r;
}


std::ostream& operator<<(std::ostream& stream, CWiderstand toPrint)
{
	stream << toPrint.getName() << "," << toPrint.getR() << "Ohm" << toPrint.getPreis() , toPrint.getPosition();
	return stream;
}



CComplex CWiderstand::getImpedanz(double _f)
{
	return CComplex(r,0);
}