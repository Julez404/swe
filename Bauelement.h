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
	CBauelement(std::string _name, double _preis, CPunkt _position, CBauelement* _next = NULL);
	~CBauelement();



	std::string getName(void) const;
	///<summary>
	//Gibt den Preis des Bauelements zurück
	///</summary>
	double getPreis(void) const;
	CPunkt getPosition(void) const;
	CBauelement* getNext(void) const;

	void setName(std::string _name);
	void setPreis(double _preis);
	void setPosition(CPunkt _position);
	void setNext(CBauelement* _next);
	///<summary>
	// Adds a new Bauelement at end of Container
	///</summary>
	void addEntryAtEnd(CBauelement& _Bauelement);
};

std::ostream& operator<<(std::ostream& stream, CBauelement _bauelement);
