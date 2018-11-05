#include "stdafx.h"
#include "bauelement.h"

CBauelement::CBauelement()
	:preis(0), position(CPunkt())
{
	next = NULL;
}

CBauelement::CBauelement(std::string _name, double _preis, CPunkt _position, CBauelement* _next)
	: name(_name), preis(_preis), position(_position),next(_next)
{}

CBauelement::~CBauelement()
{}

std::string CBauelement::getName(void) const
{
	return name;
}


double CBauelement::getPreis() const
{
	return preis;
}

CPunkt CBauelement::getPosition() const
{
	return position;
}

CBauelement* CBauelement::getNext(void) const
{
	return next;
}

void CBauelement::setName(std::string _name)
{
	name = _name;
}

void CBauelement::setPreis(double _preis)
{
	preis = _preis;
}
void CBauelement::setPosition(CPunkt _position)
{
	position = _position;
}

void CBauelement::setNext(CBauelement* _next)
{
	next = _next;
}

std::ostream& operator<<(std::ostream& stream, CBauelement _bauelement)
{
	stream << "Preis: " << _bauelement.getPreis() << " EUR  Position: " << _bauelement.getPosition();
	return stream;
}