// vererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "ImpedanzRechner.h"
#include "ImpedanzRechner_Serie.h"
#include "Liste.h"


std::string getName(const CBauelement& _bauelement);
std::string getName(const CBauelement& _bauelement)
{
	return _bauelement.getName();
}

int main()
{

	CListe* BauelementListe = new CListe;
	BauelementListe->setImpPtr(new ImpedanzRechner_Serie);

	BauelementListe->addToEnd(new CWiderstand("R1", 0.35, CPunkt(3, 8), 1.5));
	BauelementListe->addToEnd(new CSpule("L1", 0.81, CPunkt(12, 2), 0.03));
	BauelementListe->addToEnd(new CKap("C1", 0.15, CPunkt(3, 18), 0.000270));

	std::cout << BauelementListe->getImpedanzOfList(50) << std::endl;



	//----------------
	std::cout << std::endl;
	system("pause");
	return 0;
}