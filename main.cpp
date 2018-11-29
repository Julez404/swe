// vererbung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "ImpedanzRechner.h"
#include "ImpedanzRechner_Serie.h"
#include "ImpedanzRechner_Parallel.h"
#include "Liste.h"

int main()
{
	/*
	DEFINITIONEN
	*/
	ImpedanzRechner* reihe = new ImpedanzRechner_Serie;
	ImpedanzRechner* parallel = new ImpedanzRechner_Parallel;

	CListe* BauelementListe = new CListe;
	BauelementListe->setImpPtr(reihe);

	/*
	Liste füllen
	*/
	BauelementListe->addToEnd(new CWiderstand("R1", 0.35, CPunkt(3, 8), 1.5));
	BauelementListe->addToEnd(new CSpule("L1", 0.81, CPunkt(12, 2), 0.03));
	BauelementListe->addToEnd(new CKap("C1", 0.15, CPunkt(3, 18), 0.000270));


	/*
	Auswertung
	*/
	BauelementListe->printAllElements();

	delete BauelementListe;

	//----------------	
	std::cout << std::endl;
	system("pause");
	return 0;
}